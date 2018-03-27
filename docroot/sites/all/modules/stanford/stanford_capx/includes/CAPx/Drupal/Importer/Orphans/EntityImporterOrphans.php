<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans;
use CAPx\Drupal\Organizations\Orgs;
use CAPx\Drupal\Importer\EntityImporter;
use CAPx\Drupal\Util\CAPx;
use CAPx\Drupal\Util\CAPxImporter;

/**
 * Profiles that have been downloaded will need to be compared against each
 * of the type conditions.
 *
 * Removed from CAP orphan (sunet id check)
 *
 * 1. Gather up all the ids that are attached to this importer
 * 2. Break them up into the same number of groups as batch does
 * 3. Fetch the profiles by their profile ids
 * 4. Compare results to list of local.
 *
 * Removed from an organization orphan (org check)
 *
 * 1. Gather up all the ids that are attached to this importer
 * 2. Break them up into the same number of groups as batch does
 * 3. Fetch the profiles by their profile ids
 * 4. Look through the results for the organizations and grab the orgCodes
 * 5. Compare org codes with org code settings through vocabulary tree.
 *
 * Removed from a workgroup orphan (workgroup check)
 *
 * 1. Gather up all the ids that are attached to this importer
 * 2. Break them up into the same number of groups as batch does
 * 3. Fetch all results from a workgroup by fetching a large number limit
 * 4. Compare results to set.
 *
 * If profile id is missing from all three of these checks then it is deemed
 * a true orphan and should be actioned on as such.
 *
 */

class EntityImporterOrphans implements ImporterOrphansInterface {

  protected $importer;
  protected $profiles = array();
  protected $limit = 100;
  protected $orphans = array();
  protected $lookups = array();
  protected $comparisons = array();
  protected $results = array();

  /**
   * Create the thing.
   *
   * @param EntityImporter $importer
   *   The entity importer
   * @param array $profiles
   *   An array of profile ids.
   * @param array $lookups
   *   An array of lookup object
   * @param array $comparisons
   *   An array of comparison objects
   */
  public function __construct(EntityImporter $importer, Array $profiles, Array $lookups, Array $comparisons) {

    $this->setImporter($importer);
    $this->setProfiles($profiles);
    $this->setLimit(count($profiles));

    // Store all of the lookups.
    if (is_array($lookups)) {
      $this->lookups = $lookups;
    }

    // Store all of the comparisons.
    if (is_array($comparisons)) {
      $this->comparisons = $comparisons;
    }

  }

  /**
   * Process handling for queue items.
   */
  public function execute() {

    // If the action is set to do nothing to orphaned profiles, do nothing.
    $options = $this->getImporterOptions();
    $action = $options['orphan_action'];
    $profiles = $this->getProfiles();
    $client = $this->getClient();
    $limit = $this->getLimit();
    $orphans = $this->getOrphans();

    // We need to adjust the search to grab all the results.
    $client->setLimit($limit);

    // Make one request to the server for the profile information to check for
    // profiles that no longer exist on the API.
    $response = $client->api('profile')->search("ids", $profiles);

    // Fail if the response from the server was not successful.
    if (!$response || !is_array($response) || !isset($response['values'])) {
      watchdog("EntityImporterOrphans", "Client response was false. Possible connectivity issue. Stopped orphan processing.", array(), WATCHDOG_WARNING);
      return;
    }

    $results = $response['values'];

    // Allow those to alter this set.
    drupal_alter('capx_orphan_profile_results', $results);

    // Store for later.
    $this->setResults($results);

    // Run the lookups in order to identify the orphans for each way we can
    // import a profile.
    $lookups = $this->getLookups();
    foreach ($lookups as $k => $looker) {
      $orphans = $looker->execute($this);
      $this->setOrphans($orphans);
    }

    // Now that we have identified all of the orphans lets compare them to each
    // way we can import a profile to identify if an orphan in one is not an
    // orphan in another. Only an orphan across all ways is a true orphan.
    $comparisons = $this->getComparisons();
    foreach ($comparisons as $k => $comparison) {
      $orphans = $comparison->execute($this);
      $this->setOrphans($orphans);
    }

    // Special processor for multiple items.
    if (isset($orphans['multiple'])) {
      $this->processMultipleImporterOrphans($orphans['multiple']);
      unset($orphans['multiple']);
    }

    // We have looked at everything and now it is time to process the orphans.
    // In order to be an orphan the orphan id has to appear in all importer
    // Options. So we can just take one and run the process on that.
    $orphaned = end($orphans);

    // Always want to do this in case the action has changed.
    $this->processAdopted($profiles, $orphaned);
    $this->processAdoptedMultiple($profiles);

    // If we have no orphans after all of that just end.
    if (empty($orphaned)) {
      return;
    }

    // Small patch up fix.
    if (isset($orphans["missing"])) {
      $orphaned = $orphaned + $orphans["missing"];
    }

    // If no action is required then just skip over this and go to the adopted.
    if ($action !== "nothing" && is_array($orphaned)) {
      $this->processOrphans($orphaned);
    }

  }

  /**
   * Create a multiple step batch processes.
   *
   * Creates a multistep batch process that looks for orphans in every way in
   * the set importer.
   */
  public function batch() {
    $limit = variable_get('stanford_capx_batch_limit', 100);
    $importer = $this->getImporter();

    // Get a list of all the profiles that are associated with this importer.
    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_type', 'entity_id', 'profile_id'))
      ->condition('importer', $importer->getMachineName())
      ->condition('sync', TRUE)
      ->orderBy('profile_id', 'ASC');

    $result = $query->execute();
    $assoc = $result->fetchAllAssoc('profile_id');
    $profiles = array_keys($assoc);

    // Batch definition.
    $batch = array(
      'operations' => array(),
      'title' => t('Downloading and processing profile information...'),
      'init_message' => t('Profile information orphan lookup is starting.'),
      'progress_message' => t('Profile orphans in progress. @current of @total completed.'),
      'error_message' => t('Profile information could not be processed. Please try again.'),
      'finished' => 'stanford_capx_orphan_check_batch_finished',
    );

    $chunk = array_chunk($profiles, $limit);
    foreach ($chunk as $slice) {
      $batch['operations'][] = array(
        '\CAPx\Drupal\Importer\Orphans\EntityImporterOrphansBatch::batch',
        array($importer->getMachineName(), $slice),
      );
    }

    batch_set($batch);

  }

  // ///////////////////////////////////////////////////////////////////////////
  // GETTERS AND SETTERS
  // ///////////////////////////////////////////////////////////////////////////

  /**
   * [addLookup description]
   * @param [type] $lookup [description]
   */
  public function addLookup($lookup) {
    $this->lookups[] = $lookup;
  }

  /**
   * [getScenarios description]
   * @return [type] [description]
   */
  protected function getLookups() {
    return $this->lookups;
  }

  /**
   * [addComparison description]
   * @param [type] $comparison [description]
   */
  public function addComparison($comparison) {
    $this->comparisons[] = $comparison;
  }

  /**
   * [getComparison description]
   * @return [type] [description]
   */
  protected function getComparisons() {
    return $this->comparisons;
  }

  /**
   * [setImporter description]
   * @param [type] $importer [description]
   */
  protected function setImporter($importer) {
    $this->importer = $importer;
  }

  /**
   * [getImporter description]
   * @return [type] [description]
   */
  public function getImporter() {
    return $this->importer;
  }

  /**
   * [setProfiles description]
   * @param [type] $profiles [description]
   */
  protected function setProfiles($profiles) {
    $this->profiles = $profiles;
  }

  /**
   * [getProfiles description]
   * @return [type] [description]
   */
  public function getProfiles() {
    return $this->profiles;
  }

  /**
   * [getImporterOptions description]
   * @return [type] [description]
   */
  public function getImporterOptions() {
    return $this->getImporter()->getOptions();
  }

  /**
   * [getClient description]
   * @return [type] [description]
   */
  public function getClient() {
    return $this->getImporter()->getClient();
  }

  /**
   * [getLimit description]
   * @return [type] [description]
   */
  protected function getLimit() {
    return $this->limit;
  }

  /**
   * Sets the limit
   * @param [type] $int [description]
   */
  public function setLimit($int) {
    $this->limit = $int;
  }

  /**
   * [setOrphans description]
   * @param [type] $orphans [description]
   */
  public function setOrphans($orphans) {
    $this->orphans = $orphans;
  }

  /**
   * [getOrphans description]
   * @return [type] [description]
   */
  public function getOrphans() {
    return $this->orphans;
  }

  /**
   * [setResults description]
   * @param [type] $results [description]
   */
  protected function setResults($results) {
    $this->results = $results;
  }

  /**
   * [getResults description]
   * @return [type] [description]
   */
  public function getResults() {
    return $this->results;
  }

  // ///////////////////////////////////////////////////////////////////////////
  // END GETTERS AND SETTERS
  // ///////////////////////////////////////////////////////////////////////////


  /**
   * @param $entityIds
   */
  protected function processMultipleImporterOrphans($entityIds) {
    $importer = $this->getImporter();
    $entityType = $importer->getEntityType();
    $options = $this->getImporterOptions();
    $action = $options['orphan_action'];

    // Do nothing John Snow.
    if ($action == "nothing") {
      return;
    }

    foreach ($entityIds as $entityId) {
      $entity = entity_load($entityType, array($entityId));
      $profile = entity_metadata_wrapper($entityType, $entity[$entityId]);

      switch ($action) {
        // Any entity can be deleted.
        case 'delete':
          $profile->delete();
          break;

        // Users and nodes can have their status set to 0.
        case 'block':
        case 'unpublish':
          $profile->status->set(0);
          $profile->save();
          $this->logOrphan($profile);
          break;

        default:
          // Do nothing.
      }
    }

  }


  /**
   * Handles what to do when a profile has been orphaned.
   *
   * @param array $profileIds
   *   An array of profileIds to process as orphans.
   */
  public function processOrphans($profileIds) {

    $importer = $this->getImporter();
    $entityType = $importer->getEntityType();
    $bundleType = $importer->getBundleType();
    $options = $this->getImporterOptions();
    $action = $options['orphan_action'];

    foreach ($profileIds as $id) {
      $profile = CAPx::getEntityByProfileId($entityType, $bundleType, $id);

      // Could not load the profile for some strange reason.
      if (!$profile) {
        continue;
      }

      // If already an orphan we don't want to flood with messages.
      if (CAPx::profileIsOrphan($profile)) {
        continue;
      }

      $profile = entity_metadata_wrapper($entityType, $profile);

      switch ($action) {
        case 'delete':
          $profile->delete();
          break;

        case 'block':
        case 'unpublish':
          $profile->status->set(0);
          $profile->save();

          // Log that this profile was orphaned.
          $this->logOrphan($profile);
          break;

        default:
          // Do nothing.
      }
    }

  }

  /**
   * Logs that a profile was orphaned.
   *
   * @param object $profile
   *   The loaded and wrapped entity metadata.
   */
  public function logOrphan($entity) {

    // Set the flag to 1 in the capx_profiles table.

    // BEAN is returning its delta when using this.
    // $id = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($id, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);

    $guuid = $entityRaw->capx['guuid'];

    $importer = $this->getImporter();
    $importerName = $importer->getMachineName();
    $entityType = $importer->getEntityType();
    $bundleType = $importer->getBundleType();

    $record = array(
      'entity_type' => $entityType,
      'bundle_type' => $bundleType,
      'entity_id' => $id,
      'importer' => $importerName,
      'orphaned' => 1,
    );

    // For the multiple entity.
    if (!empty($guuid)) {
      $record['guuid'] = $guuid;
    }

    $keys = array(
      'entity_type',
      'entity_id',
      'importer',
      'bundle_type',
    );

    // For multiple entities.
    if (!empty($guuid)) {
      $keys[] = 'guuid';
    }

    $yes = drupal_write_record('capx_profiles', $record, $keys);

    if ($yes) {
      watchdog('EntityImporterOrphans', "%title was orphaned from the importer %importername.", array("%title" => $entity->label(), "%importername" => $importerName), WATCHDOG_NOTICE, '');
    }
  }

  /**
   * Orphaned profiles that have returned to the importer.
   *
   * Find and process profiles that have been added back into an import by
   * removing their orphan status.
   *
   * @param array $profiles
   *   An array of profile ids
   * @param array $orphans
   *   An array of orphaned profile ides
   */
  public function processAdopted($profiles, $orphans) {
    $importer = $this->getImporter();
    $importerName = $importer->getMachineName();
    $entityType = $importer->getEntityType();
    $bundleType = $importer->getBundleType();

    foreach ($profiles as $id) {
      $profile = CAPx::getEntityByProfileId($entityType, $bundleType, $id);

      if (!$profile) {
        continue;
      }

      $profileWrapped = entity_metadata_wrapper($entityType, $profile);

      if (CAPx::profileIsOrphan($profile) && !in_array($id, $orphans)) {
        // Profile is not an orphan. Lets enable it again.
        $record = array(
          'entity_type' => $entityType,
          'bundle_type' => $bundleType,
          'profile_id' => $id,
          'importer' => $importerName,
          'orphaned' => 0,
        );

        $keys = array(
          'entity_type',
          'profile_id',
          'importer',
          'bundle_type',
        );

        drupal_write_record('capx_profiles', $record, $keys);

        $options = $importer->getOptions();

        // If the action was to unpublish let's re-publish the node.
        if ($options['orphan_action'] == "unpublish") {
          $profileWrapped->status->set(1);
          $profileWrapped->save();
        }

        // Log the adoption.
        watchdog('EntityImporterOrphans', "%title was adopted and is no longer an orphan in the importer %importername.", array("%title" => $profileWrapped->label(), "%importername" => $importerName), WATCHDOG_NOTICE, '');
      }

    }

    return $orphans;
  }

  /**
   * Orphaned profiles that have returned to the importer.
   *
   * Find and process profiles that have been added back into an import by
   * removing their orphan status.
   *
   * @param array $profiles
   *   An array of profile ids
   * @param array $orphans
   *   An array of orphaned profile ides
   */
  public function processAdoptedMultiple($profiles) {
    $importer = $this->getImporter();
    $importerMachineName = $importer->getMachineName();
    $entityType = $importer->getEntityType();
    $bundleType = $importer->getBundleType();
    $options = $importer->getOptions();
    $orphanAction = $options['orphan_action'];
    $mapper = $this->getImporter()->getMapper();

    if ($orphanAction !== "unpublish") {
      // Nothing actionable to perform.
      return;
    }

    // No need to do anything if it is not a multiple query...
    if (!$mapper->getConfigSetting('multiple')) {
      return;
    }

    $results = $this->getResults();
    $guuidquery = $mapper->getGUUIDQuery();
    $parts = explode(".", $guuidquery);
    $subquery = "$.." . array_pop($parts);
    $remoteGUUIDs = $mapper->getRemoteDataByJsonPath($results, $subquery);

    $or = db_or()->condition('profile_id', $profiles);
    $localResults = db_select("capx_profiles", "cxp")
      ->fields('cxp', array('entity_id', 'guuid'))
      ->condition($or)
      ->condition("importer", $importerMachineName)
      ->condition("orphaned", 1)
      ->execute()
      ->fetchAllAssoc('guuid');

    $localGUUIDs = array_keys($localResults);
    $diff = array_intersect($localGUUIDs, $remoteGUUIDs);

    // Nothing to adopt. Yay.
    if (empty($diff)) {
      return array();
    }

    foreach ($diff as $guuid) {
      $entityID = $localResults[$guuid]->entity_id;
      $ids = array($entityID);
      $entity = array_pop(entity_load($entityType, $ids));
      $profile = entity_metadata_wrapper($entityType, $entity);
      $profile->status->set(1);
      $profile->save();

      // Profile is not an orphan. Lets enable it again.
      $record = array(
        'entity_type' => $entityType,
        'bundle_type' => $bundleType,
        'entity_id' => $entityID,
        'importer' => $importerMachineName,
        'orphaned' => 0,
        'guuid' => $guuid,
      );

      $keys = array(
        'entity_type',
        'entity_id',
        'importer',
        'bundle_type',
        'guuid',
      );

      drupal_write_record('capx_profiles', $record, $keys);
    }


  }



}
