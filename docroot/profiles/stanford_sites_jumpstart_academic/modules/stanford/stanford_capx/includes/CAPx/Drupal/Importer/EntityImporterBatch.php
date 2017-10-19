<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer;
use CAPx\Drupal\Organizations\Orgs;
use CAPx\Drupal\Processors\EntityProcessor;
use CAPx\Drupal\Util\CAPxImporter;
/**
 * A static class for handling Batch/Queue API callbacks.
 */
class EntityImporterBatch {


  /**
   * Callback for batch import functionality.
   * @param string $type
   *   The type of import bing executed (orgcodes, workgroup, sunets)
   * @param string $importerMachineName
   *   The machine name of the importer configuration entity.
   * @param int $page
   *   The page of results to process
   * @param int $limit
   *   The limit of results per page to process
   * @param array $context
   *   Batch context information passed by reference.
   */
  public static function batch($type, $importerMachineName, $page, $limit, &$context) {

    // Define a lot of things...
    $importer = CAPxImporter::loadEntityImporter($importerMachineName);
    if ($importer) {
      $options = $importer->getOptions();
      $children = $options['child_orgs'];
      $client = $importer->getClient();
      $types = $options['types'];

      // We need to adjust the search to grab results from the correct page.
      $client->setLimit($limit);
      $client->setPage($page);

      // In order to get the values to search for we need to find out what index
      // the type is as the values are in the corresponding index.
      $index = array_search($type, $types);
      $search = $options['values'][$index];

      $response = $client->api('profile')->search($type, $search, FALSE, $children);

      if (empty($response)) {
        drupal_set_message(t("ERROR: Could not fetch profile information. No response from the server."),  "error");
        return;
      }

      $results = $response['values'];
      $success = EntityImporterBatch::processResults($results, $importer);

      if ($success) {
        $now = time();
        $importer->setLastCronRun($now);
      }
    }
    else {
      $vars = array(
        '%name' => $importerMachineName,
        '!log' => l(t('log messages'), 'admin/reports/dblog'),
      );
      drupal_set_message(t('There was an issue loading the importer with %name machine name. Check !log.', $vars), 'error');
      drupal_goto('admin/config/capx/importer');
    }

  }

  /**
   * Callback function for cron queue processing.
   *
   * Fetches and parses results from the CAP API server based on settings from
   * the item array that is being passed in. This function loads up fresh
   * configuration from the importer and mapper so it is possible that things
   * have changed since the queue item was established.
   *
   * @param array $item
   *   An array of information to use during the queue call.
   */
  public static function queue($item) {

    // Define a lot of things...
    $type = $item['type'];
    $importerMachineName = $item['importer'];
    $page = $item['page'];
    $limit = $item['limit'];
    $importer = CAPxImporter::loadEntityImporter($importerMachineName);
    if (!$importer || !$importer->valid()) {
      return FALSE;
    }
    $options = $importer->getOptions();
    $children = $options['child_orgs'];
    $client = $importer->getClient();
    $types = $options['types'];

    // We need to adjust the search to grab results from the correct page.
    $client->setLimit($limit);
    $client->setPage($page);

    // In order to get the values to search for we need to find out what index
    // the type is as the values are in the corresponding index.
    $index = array_search($type, $types);
    $search = $options['values'][$index];

    $response = $client->api('profile')->search($type, $search, FALSE, $children);
    $results = $response['values'];

    $success = EntityImporterBatch::processResults($results, $importer);

    if ($success) {
      $now = time();
      $importer->setLastCronRun($now);
    }

  }

  /**
   * Process the results from the response from the API.
   *
   * This function handles the values that the CAP API server has returned from
   * either the batch or queue processes.
   *
   * @param array $results
   *   An array of profile information to process
   * @param EntityImporter $importer
   *   The EntityImporter object that is currently importing the profiles.
   *
   * @return bool
   *   success status.
   */
  public static function processResults($results, $importer) {

    // No results.
    if (empty($results)) {
      return FALSE;
    }

    $mapper = $importer->getMapper();
    // Allow altering of the results.
    drupal_alter('capx_preprocess_results', $results, $importer);

    // Loop through each result (profile info) and send it to the processor for
    // mapping and saving.
    foreach ($results as $index => $info) {

      $entityType = $mapper->getEntityType();
      $entityType = ucfirst(strtolower($entityType));
      $className = "\CAPx\Drupal\Processors\\" . $entityType . 'Processor';

      if (class_exists($className)) {
        $processor = new $className($mapper, $info);
      }
      else {
        $processor = new EntityProcessor($mapper, $info);
      }

      $processor->setEntityImporter($importer);
      $processor->execute();

      $message = $processor->getStatusMessage();

      // Nada.
      if (empty($message)) {
        continue;
      }

      // Log some information.
      // @todo This needs to be better.
      watchdog('stanford_capx', $message . " | " . $info['displayName'], array(), WATCHDOG_DEBUG);
      if (function_exists('drush_log')) {
        drush_log($message . ' | ' . $info['displayName'], 'ok');
      }

    }

    return TRUE;
  }

}
