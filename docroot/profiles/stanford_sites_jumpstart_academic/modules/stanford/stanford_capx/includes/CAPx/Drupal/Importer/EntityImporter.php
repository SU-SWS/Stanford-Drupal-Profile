<?php
/**
 * @file
 * Entity importer class handles the execution process which fires off the
 * API request, parses the data, and sends it to an entity processor.
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer;
use CAPx\Drupal\Util\CAPx;
use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\Drupal\Processors\EntityProcessor as EntityProcessor;
use CAPx\Drupal\Processors\UserProcessor as UserProcessor;
use CAPx\APILib\HTTPClient;
use CAPx\Drupal\Entities\CFEntity;


class EntityImporter implements ImporterInterface {

  // Options and configuration array.
  protected $options = array();

  // The configuration entity called importer.
  protected $importer;

  // The mapping scheme object.
  protected $mapper;

  // Metadata about this importer.
  protected $meta;

  // The machine name of the CFE Importer entity.
  protected $machineName = '';

  /**
   * Constructor class. Sets a number of items.
   *
   * @param CFEntity $importer
   *   The configuration entity importer
   * @param EntityMapper $mapper
   *   The entity mapper object
   * @param HTTPClient $client
   *   The HTTPClient to use. Usually GuzzleClient.
   */
  public function __construct(CFEntity $importer, EntityMapper $mapper, HTTPClient $client) {
    $mapper->setImporter($importer->getMachineName());
    $this->setImporter($importer);
    $this->setMapper($mapper);
    $this->setClient($client);
    $this->setMeta($importer->meta);

    $config = $this->getEntityImporterConfig();
    $this->addOptions($config);
    $this->setMachineName($config['machine_name']);

  }

  /**
   * The open method for executing cron callback functionality.
   *
   * 1. Check settings to see if this should run.
   * 2. Create queue items to run next cron run.
   */
  public function cron() {

    // Don't do anything if cron settings say don't do it.
    if (!$this->shouldIRunCron()) {
      return;
    }

    // Create the import/sync queue items.
    $this->createQueue();
    // Create the orphan queue items.
    $this->createOrphansQueue();

  }

  /**
   * Check to see if this importer's setting should run cron or not.
   *
   * @return bool
   *   True if cron action should run, false otherwise.
   */
  protected function shouldIRunCron() {
    $options = $this->getOptions();
    $now = time();
    $lastRun = $this->getLastCronRun();
    $nextRun = 0;

    switch ($options['cron_option']) {
      case 'none':
        return FALSE;

      case 'all':
        return TRUE;

      case 'daily':
        $hour = $options['cron_option_hour'];
        $nextRun = strtotime("Tomorrow " . $hour, $lastRun);
        break;

      case 'weekly':
        $hour = $options['cron_option_hour'];
        $day = $options['cron_option_day_week'];
        $nextRun = strtotime($hour . " next " . $day, $lastRun);
        break;

      case 'monthly':
        $hour = $options['cron_option_hour'];
        $day = $options['cron_option_day_number'];
        $nextMonth = strtotime("next month", $lastRun);
        $year = (date("m", $nextMonth) == "01") ? date("Y", strtotime("next year")) : date("Y");
        $nextRun = strtotime($hour . " " . $day . " " . date("F", $nextMonth) . " " . $year);
        break;

      case 'yearly':
        $hour = $options['cron_option_hour'];
        $day = $options['cron_option_day_number'];
        $month = $options['cron_option_month'];
        $month++;
        $dateObj = \DateTime::createFromFormat('!m', $month);
        $monthName = $dateObj->format('F');
        $year = strtotime("next year", $lastRun);
        $nextRun = strtotime($hour . " " . $day . " " . $monthName . " " . date("Y" , $year));
        break;
    }

    // Check to see if now is after next.
    if ($now > $nextRun) {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Execute the whole importprocess as one huge request.
   *
   * This is generally a bad idea for large imports but may be useful for small.
   */
  public function justDoIt() {

    $options = $this->getOptions();
    $mapper = $this->getMapper();
    $client = $this->getClient();
    $data = array();

    foreach ($options['types'] as $k => $type) {
      $children = FALSE;

      switch ($type) {
        case "orgCodes":
          $children = $options['child_orgs'];
        case "privGroups":
        case "uids":

          // Set the results to a huge number so we get all results in one
          // request.
          $client->setLimit(99999);
          $new = $client->api('profile')->search($type, $options['values'][$k], FALSE, $children);

          if (!empty($new['values'])) {
            $data[$type] = $new['values'];
          }
          break;
      }
    }

    if (!empty($data)) {
      foreach ($data as $type => $results) {
        foreach ($results as $index => $info) {
          // Allow altering of the results.
          drupal_alter('stanford_capx_preprocess_results', $info, $this);
          $processor = new EntityProcessor($mapper, $info);
          $processor->setEntityImporter($this);
          $processor->execute();
        }
      }
    }

    // Update some meta information.
    $meta = $this->getImporter()->getMeta();
    $meta['count'] = $new['totalCount'];
    $this->getImporter()->setMeta($meta);
    $this->getImporter()->save();

  }

  /**
   * Executes the import process as a series of batch processors.
   *
   * First pings the server for each type and finds out how many results there
   * are. It then breaks up the results into sensible batch sizes.
   */
  public function createBatch() {

    $options = $this->getOptions();
    $client = $this->getClient();
    $responses = array();
    $numberOfProfiles = 0;

    // Loop through each of the import type options and ping the server for just
    // one item of each to get an idea of how many items there actually is.
    foreach ($options['types'] as $k => $type) {

      $children = FALSE;
      switch ($type) {
        case "orgCodes":
          $children = $options['child_orgs'];
        case "privGroups":
          // Set the results to one per page.
          $httpOptions = $client->setLimit(1);

          // Fire off request.
          $results = $client->api('profile')->search($type, $options['values'][$k], FALSE, $children);
          break;
        case "uids":
          $index = array_search("uids", $options["types"]);
          $results = array();
          $results['totalCount'] = count($options["values"][$index]);
          break;
      }

      // No results no need to continue.
      if (empty($results)) {
        continue;
      }

      // Keep a track of the number of items.
      // Because we have set the page results to 1 the number of pages will be
      // the number of results we get back.
      $responses[$type] = array();
      $responses[$type]['totalCount'] = $results['totalCount'];
      $numberOfProfiles += $results['totalCount'];

    }

    // How many to run per batch.
    $processLimit = variable_get('stanford_capx_batch_limit', 100);

    // Batch definition.
    $batch = array(
      'operations' => array(),
      'title' => t('Downloading and processing profile information...'),
      'init_message' => t('Profile information sync is starting.'),
      'progress_message' => t('Profile sync in progress. @current of @total completed.'),
      'error_message' => t('Profile information could not be imported. Please try again.'),
      'finished' => "stanford_capx_importer_batch_finished",
    );

    // Loop through each type and chunk up into patch operations.
    foreach ($responses as $type => $info) {
      $count = $info['totalCount'];
      $i = 0;
      while ($count > 0) {
        $i++;
        $batch['operations'][] = array('\CAPx\Drupal\Importer\EntityImporterBatch::batch', array($type, $this->getMachineName(), $i, $processLimit));
        $count -= $processLimit;
      }
    }

    // There was nothing to work on. Don't do anything.
    if ($numberOfProfiles) {

      // Update some meta information.
      $meta = $this->getImporter()->getMeta();
      $meta['count'] = $numberOfProfiles;
      $this->getImporter()->setMeta($meta);
      $this->getImporter()->save();

      // Set the big batch after all...
      batch_set($batch);

    }
    else {
      drupal_set_message(t("No profiles found. Please check importer settings and connection then try again."), "warning");
      drupal_goto("admin/config/capx/importer/edit/" . $this->getMachineName());
    }

  }

  /**
   * Create a list of queued items that need to be ran on cron.
   *
   * @see QueuesAPI.
   */
  public function createQueue() {

    $queue = \DrupalQueue::get('stanford_capx_profiles', TRUE);
    $options = $this->getOptions();
    $client = $this->getClient();
    $limit = variable_get('stanford_capx_batch_limit', 100);
    $numberOfProfiles = 0;

    // If the importer is empty.
    if (empty($options['types'])) {
      return;
    }

    // Loop through each of the import type options and ping the server for just
    // one item of each to get an idea of how many items there actually is.
    // Break up the number of items into sensible chunks.

    foreach ($options['types'] as $k => $type) {

      $children = FALSE;
      switch ($type) {
        case "orgCodes":
          $children = $options['child_orgs'];
        case "privGroups":
          // Set the results to one per page.
          $httpOptions = $client->setLimit(1);
          // Fire off request.
          $results = $client->api('profile')->search($type, $options['values'][$k], FALSE, $children);
          break;
        case "uids":
          $index = array_search("uids", $options["types"]);
          $results = array();
          $results['totalCount'] = count($options["values"][$index]);
          break;
      }

      // Total number of profiles.
      $total = $results['totalCount'];
      $numberOfProfiles += $total;
      $page = 1;

      // Create queues for each page.
      while ($total > 0) {
        $item = $this->getQueueItem();
        $item['type'] = $type;
        $item['page'] = $page;
        $queue->createItem($item);
        $page++;
        $total -= $limit;
      }

    }

    // Only update the meta count if we got a response from the server.
    if (!empty($results)) {
      // Update some meta information.
      $meta = $this->getImporter()->getMeta();
      $meta['count'] = $numberOfProfiles;
      $this->getImporter()->setMeta($meta);
      $this->getImporter()->save();
    }
    else {
      watchdog("stanford_capx", "There was no response from the server when trying to fetch profile information.", array(), WATCHDOG_ERROR);
    }

  }

  /**
   * Search through the values we have and find orphans in the api.
   *
   * Create queue api queues that run on cron to check for orphans.
   */
  public function createOrphansQueue() {

    // If the action is set to do nothing to orphaned profiles, do nothing.
    $options = $this->getOptions();
    if ($options['orphan_action'] == 'nothing') {
      return;
    }

    $limit = variable_get('stanford_capx_batch_limit', 100);

    // Get a list of all the profiles that are associated with this importer.
    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_type', 'entity_id', 'profile_id'))
      ->condition('importer', $this->getMachineName())
      ->condition('sync', TRUE)
      ->orderBy('profile_id', 'ASC');

    $result = $query->execute();
    $assoc = $result->fetchAllAssoc('profile_id');
    $profiles = array_keys($assoc);

    // Don't process empty sets.
    if (empty($profiles)) {
      return;
    }

    $chunk = array_chunk($profiles, $limit);
    foreach ($chunk as $slice) {
      $queue = \DrupalQueue::get('stanford_capx_profile_orphans', TRUE);
      $item = array();
      $item['importer'] = $this->getMachineName();
      $item['profiles'] = $slice;
      $queue->createItem($item);
    }

  }

  // ===========================================================================
  // GETTERS & SETTERS
  // ===========================================================================

  /**
   * Returns the timestamp of the last time this importer was called.
   * @return int
   *   epoc time integer
   */
  public function getLastCronRun() {
    $meta = $this->getMeta();
    return isset($meta['lastUpdate']) ? $meta['lastUpdate'] : 0;
  }

  /**
   * Sets the meta information about the last time the importer was executed.
   *
   * @param int $time
   *   set the epoc time of the last cron run
   */
  public function setLastCronRun($time = REQUEST_TIME) {
    $importer = $this->getImporter();
    $importer->meta['lastUpdate'] = $time;
    $importer->meta['lastUpdateHuman'] = format_date($time, 'custom', 'F j - g:ia');
    $importer->save();
  }

    /**
   * This function takes the saved settings and retuns an array that
   * matches the API importer library settings.
   * @return [type] [description]
   */
  protected function getEntityImporterConfig() {
    $importer = $this->getImporter();

    $settings = $importer->settings;
    $settings['machine_name'] = $importer->machine_name;

    if (!empty($settings['organization'])) {
      $settings['types'][] = 'orgCodes';
      $settings['values'][] = explode(",", $settings['organization']);
    }

    if (!empty($settings['workgroup'])) {
      $settings['types'][] = 'privGroups';
      $settings['values'][] = explode(",", $settings['workgroup']);
    }

    if (!empty($settings['sunet_id'])) {
      $settings['types'][] = 'uids';
      $settings['values'][] = explode(",", $settings['sunet_id']);
    }

    return $settings;
  }

  /**
   * Returns the meta information about this importer.
   *
   * @return array
   *   An array of mixed values
   */
  public function getMeta() {
    return $this->meta;
  }

  /**
   * Set the metadata information.
   *
   * This is for storage only and does not update the configuration entity.
   * To set the meta information use CFEntity::setMeta()
   *
   * @param array $meta
   *   An array of meta information
   */
  public function setMeta($meta) {
    $this->meta = $meta;
  }

  /**
   * A template item function.
   *
   * Returns the default options for an item that is going to go into the Queues
   * API.
   *
   * @return array
   *   A keyed array with values that need to be passed to the queue
   */
  protected function getQueueItem() {
    $limit = variable_get('stanford_capx_batch_limit', 100);

    // Each queue needs some items. Here is a template for that.
    $item = array(
      'type' => '', // The import type (sunet, orgCodes, workgroup)
      'page' => 1, // The page on the API to import
      'limit' => $limit, // The limit per page
      'importer' => $this->getMachineName(), // This name so we can load er up.
    );

    return $item;
  }

  /**
   * Getter function.
   *
   * @return array
   *   An array of options
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Adder function.
   *
   * @param array $newOpts
   *   Adds an array of options into the already defined options.
   */
  public function addOptions($newOpts) {
    $opts = $this->getOptions();
    $opts = array_merge($opts, $newOpts);
    $this->setOptions($opts);
  }

  /**
   * Setter function.
   *
   * @param array $opts
   *   An array of options.
   */
  protected function setOptions($opts) {
    $this->options = $opts;
  }

  /**
   * Getter function.
   *
   * @return EntityMapper
   *   An EntityMapper instance.
   */
  public function getMapper() {
    return $this->mapper;
  }

  /**
   * Setter function.
   * @param EntityMapper
   *   An EntityMapper instance
   */
  public function setMapper($map) {
    $this->mapper = $map;
  }

  /**
   * Getter function.
   *
   * @return HTTPClient
   *   The HTTPClient instance.
   */
  public function getClient() {
    return $this->client;
  }

  /**
   * Setter function.
   *
   * @param HTTPClient
   *   The HTTPClient instance.
   */
  public function setClient($client) {
    $this->client = $client;
  }

  /**
   * Getter function.
   *
   * @return string
   *   The machine name of the importer configuration entity.
   */
  public function getMachineName() {
    return $this->machineName;
  }

  /**
   * Setter function.
   *
   * @param string $name
   *   The machine name of the importer configuration entity.
   */
  public function setMachineName($name) {
    $this->machineName = $name;
  }

  /**
   * The importer configuration entity.
   *
   * @param CFEntity $importer
   *   A configuration entity importer object
   */
  public function setImporter($importer) {
    $this->importer = $importer;
  }

  /**
   * The importer configuration entity.
   *
   * @return CFEntity
   *   The configuration entity importer object
   */
  public function getImporter() {
    return $this->importer;
  }

  /**
   * [getEntityType description]
   * @return [type] [description]
   */
  public function getEntityType() {
    $mapper = $this->getMapper();
    return $mapper->getEntityType();
  }

  /**
   * [getEntityType description]
   * @return [type] [description]
   */
  public function getBundleType() {
    $mapper = $this->getMapper();
    return $mapper->getBundleType();
  }

  /**
   * Checks importer status.
   *
   * * @return bool
   *  Importer status.
   */
  public function valid() {
    return $this->getMapper()->valid($this->getMachineName());
  }
}
