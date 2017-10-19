<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;

use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\Drupal\Util\CAPx;

class EntityProcessor extends ProcessorAbstract {

  // Wrapped Drupal entity to be processed.
  protected $entity;

  // Skip etag check.
  protected $force;

  /**
   * Process entity.
   *
   * The starting point for processing any entity. This function executes and
   * handles the saving and/or updating of an entity with the data that is
   * set to it.
   *
   * @param bool $force
   *   Synchronize even if synchronization is disable('sync' = 0).
   *
   * @return object
   *   The new or updated wrapped entity.
   */
  public function execute($force = FALSE) {

    // Set this force.
    $this->force == $force;

    try {
      $multi = $this->getMapper()->getConfigSetting('multiple');
    }
    catch (\Exception $e) {
      $multi = FALSE;
    }

    // Sometimes we need to create one, other times we need moar.
    if (!empty($multi) && $multi == 1) {
      $entity = $this->executeMultiple($force);
    }
    else {
      $entity = $this->executeSingle($force);
    }

    return $entity;
  }

  /**
   * Process the execution and creation of multiple entities per profile.
   * @param  [type] $force [description]
   * @return [type]        [description]
   */
  protected function executeMultiple($force = FALSE) {

    $mapper = $this->getMapper();
    $data = $this->getData();
    $numEntities = $mapper->getMultipleEntityCountBySubquery($data);

    // Let the Orphan cron runs take care of the clean up. We just need to stop.
    if ($numEntities <= 0) {
      return;
    }

    // Time to loop through our results and either update or create entities.
    $entityImporter = $this->getEntityImporter();
    $importerMachineName = $entityImporter->getMachineName();
    $entityType = $mapper->getEntityType();
    $bundleType = $mapper->getBundleType();

    // Check to see what entities we have for this profile.
    $entities = CAPx::getProfiles($entityType, array(
      'profile_id' => $data['profileId'],
      'importer' => $importerMachineName
    ));

    // Looks like we have a whole new batch to create.
    if (empty($entities)) {
      $this->multipleCreateNewEntity($numEntities, $entityType, $bundleType, $data, $mapper);
      return;
    }

    // Check if we even need to update. A matching etag will allow us to
    // avoid a costly update routine.
    if (!$this->isETagDifferent() && !$this->skipEtagCheck()) {
      // Nothing to do, same etag and no forceful update.
      return;
    }

    // At this point we have saved entities and the etag changed or we are
    // forcing an update.

    // Strategy: If the user can provide a GUID (fingerprint) then we can try to
    // update in place. If the user cannot provide a GUID then we go with the
    // delete everything and replace strategy.

    try {
      $guuidPath = $mapper->getConfigSetting("guuidquery");
    }
    catch (\Exception $e) {
      // An older mapper that has not yet been updated.
      // @todo: Think of a way to update the older mappers with an update hook.
    }

    // NO GUUID available. Delete all of the existing entities and replace with
    // new ones.
    if (empty($guuidPath)) {
      $this->multipleDeleteEntities($entities);
      $this->multipleCreateNewEntity($numEntities, $entityType, $bundleType, $data, $mapper);
      return;
    }

    // GUUID available lets check to see if it matches the numEntities count.
    $numGUUIDs = count($mapper->getRemoteDataByJsonPath($data, $guuidPath));

    // Ok, we are in good shape at this point. We have results, we have ids, and
    // now we can update them in place!
    $this->multipleUpdateEntities($numEntities, $entityType, $bundleType, $data, $mapper);

  }

  /**
   * Create a bunch of new entities!
   * @param  [type] $numEntities [description]
   * @param  [type] $entityType  [description]
   * @param  [type] $data        [description]
   * @param  [type] $mapper      [description]
   * @return [type]              [description]
   */
  protected function multipleCreateNewEntity($numEntities, $entityType, $bundleType, $data, $mapper) {
    $i = 0;
    while ($i < $numEntities) {
      // Setting the index tells the mapper which values to save.
      $mapper->setIndex($i);
      $guuid = $mapper->getGUUID($data, $i);
      $entity = $this->newEntity($entityType, $bundleType, $data, $mapper, $guuid);
      $i++;
    }
    return TRUE;
  }

  /**
   * Deletes all entities passed to this function.
   * @param  [type] $entities [description]
   * @return [type]           [description]
   */
  protected function multipleDeleteEntities($entityType, $entities) {
    entity_delete_multiple($entityType, $entities);
  }

  /**
   * Update function for when there are multiple entities being created per
   * person.
   * @param  [type] $numEntities [description]
   * @param  [type] $entityType  [description]
   * @param  [type] $bundleType  [description]
   * @param  [type] $data        [description]
   * @param  [type] $mapper      [description]
   * @return [type]              [description]
   */
  protected function multipleUpdateEntities($numEntities, $entityType, $bundleType, $data, $mapper) {
    $i = 0;
    while ($i < $numEntities) {
      // Setting the index tells the mapper which values to save.
      $mapper->setIndex($i);
      $guuid = $mapper->getGUUID($data, $i);
      $importerMachineName = $this->getEntityImporter()->getMachineName();
      $profileId = $data['profileId'];

      $entity = CAPx::getEntityIdByGUUID($importerMachineName, $profileId, $guuid);
      if ($entity) {
        $entity = entity_metadata_wrapper($entityType, $entity);
        $entity = $this->updateEntity($entity, $data, $mapper);
      }
      else {
        $entity = $this->newEntity($entityType, $bundleType, $data, $mapper, $guuid);
      }

      $i++;
    }
    return TRUE;
  }

  /**
   * Process the execution and creation of a single entity per profile response.
   * @param  [type] $force [description]
   * @return [type]        [description]
   */
  protected function executeSingle($force = FALSE) {
    $mapper = $this->getMapper();
    $data = $this->getData();
    $entityImporter = $this->getEntityImporter();
    $importerMachineName = $entityImporter->getMachineName();

    $entityType = $mapper->getEntityType();
    $bundleType = $mapper->getBundleType();

    $entity = NULL;
    $entities = CAPx::getProfiles($entityType, array(
      'profile_id' => $data['profileId'],
      'importer' => $importerMachineName
    ));
    if (is_array($entities)) {
      $entity = array_pop($entities);
    }

    // If we have an entity we need to update it.
    if (!empty($entity)) {

      // Profile synchronization has been disabled.
      if (empty($entity->capx['sync']) && !$force) {
        return NULL;
      }

      $this->setEntity($entity);

      // Check to see if the etag has changed. We can avoid processing a profile
      // if the etag is unchanged.

      if ($this->isETagDifferent() || $this->skipEtagCheck()) {
        $entity = entity_metadata_wrapper($entityType, $entity);
        $entity = $this->updateEntity($entity, $data, $mapper);
        $this->setStatus(3, 'Etag expired. Profile was updated.');
      }
      else {
        $this->setStatus(2, 'Etag matched. No processing happened.');
        // Call this function so that the timestamp of sync is updated.
        $entity = entity_metadata_wrapper($entityType, $entity);
        CAPx::updateProfileRecord($entity, $data['profileId'], $data['meta']['etag'], $importerMachineName);
      }

    }
    else {
      $entity = $this->newEntity($entityType, $bundleType, $data, $mapper);
      if ($entity) {
        $this->setStatus(1, 'Created new entity.');
      }
      else {
        $this->setStatus(0, 'Skipped entity.');
      }
    }

    return $entity;
  }

  /**
   * Update the entity.
   *
   * Slightly different from the new entity. If we have an entity we will
   * execute the mapper on it and re-save it.
   *
   * @param \EntityDrupalWrapper $entity
   *   The entity to be updated
   * @param array $data
   *   The data to map into it.
   * @param object $mapper
   *   The entity mapper instance
   *
   * @return object|bool
   *   The updated entity.
   */
  public function updateEntity($entity, $data, $mapper) {
    $entity_info = entity_get_info($entity->type());
    drupal_alter('capx_pre_update_entity', $entity, $data, $mapper);
    if ($entity->getIdentifier()) {
      $entity = $mapper->execute($entity, $data);

      // There is a possiblility that a field or property had an error while being
      // processed. These errors are stored for us to get later so that no one
      // field stops the processing of an entity. If there was an error somewhere
      // the eTag should be invalidated so that this entity gets updates on the
      // next import run.
      $errors = $mapper->getErrors();

      if (!empty($errors)) {
        // If there was an error on the field mapping set the etag to errors.
        $data['meta']['etag'] = "errors";
      }

      // Nodes have special sauces.
      if ($entity->type() == "node") {
        // Set up default values, if required.
        $node_options = variable_get('node_options_' . $entity->getBundle(), array(
          'status',
          'promote'
        ));
        // Always use the default revision setting.
        $entity->revision->set(in_array('revision', $node_options));
      }

      // Save the entity.
      drupal_alter('capx_entity_presave', $entity, $mapper);
      $entity->save();

      $entityImporter = $this->getEntityImporter();
      $importerMachineName = $entityImporter->getMachineName();

      if ($entity->getIdentifier()) {
        $guuid = $mapper->getGUUID($data, $mapper->getIndex());
        CAPx::updateProfileRecord($entity, $data['profileId'], $data['meta']['etag'], $importerMachineName, $guuid);
      }

      drupal_alter('capx_post_update_entity', $entity);

      return $entity;
    }
    return FALSE;
  }

  /**
   * New entity.
   *
   * An existing entity was not found and a new one should be created. Provide
   * some default values, create the entity, map the fields to it, and store
   * some additional data about where it came from.
   *
   * @param string $entityType
   *   The type of entity being created
   * @param string $bundleType
   *   The bundle type of the entity being created
   * @param array $data
   *   The data to be mapped to the new entity
   * @param EntityMapper $mapper
   *   The EntityMapper instance
   * @param mixed $guuid
   *   The genuine unique id for this entity of other than profileId.
   *
   * @return object|bool
   *   The new entity after it has been saved.
   */
  public function newEntity($entityType, $bundleType, $data, $mapper, $guuid = NULL) {

    $properties = array(
      'type' => $bundleType,
      'uid' => 1, // @TODO - set this to something else
      'status' => 1, // @TODO - allow this to change
      'comment' => 0, // Any reason to set otherwise?
      'promote' => 0, // Fogetaboutit.
    );

    $values = array(
      'properties' => $properties,
      'entityType' => $entityType,
      'bundleType' => $bundleType,
      'mapper' => $mapper,
      'data' => $data,
      'guid' => $guuid,
    );
    drupal_alter('capx_pre_entity_create', $values);
    extract($values);

    if (!isset($properties['no_create']) || !$properties['no_create']) {
      // Create an empty entity.
      /** @var \EntityDrupalWrapper $entity */
      $entity = entity_create($entityType, $properties);

      // Wrap it up baby!
      $entity = entity_metadata_wrapper($entityType, $entity);
      $entity = $mapper->execute($entity, $data);
      // @todo Need to catch exceptions here as well.
      drupal_alter('capx_entity_presave', $entity, $mapper);
      $entity->save();

      // There is a possiblility that a field or property had an error while being
      // processed. These errors are stored for us to get later so that no one
      // field stops the processing of an entity. If there was an error somewhere
      // the eTag should be invalidated so that this entity gets updates on the
      // next import run.
      $errors = $mapper->getErrors();

      if (!empty($errors)) {
        // If there was an error on the field mapping set the etag to errors.
        $data['meta']['etag'] = "errors";
      }

      // Allow altering.
      drupal_alter('capx_post_entity_create', $entity);

      // Write a new record.
      $entityImporter = $this->getEntityImporter();
      $importerMachineName = $entityImporter->getMachineName();
      CAPx::insertNewProfileRecord($entity, $data['profileId'], $data['meta']['etag'], $importerMachineName, $guuid);

      return $entity;
    }

    return FALSE;
  }

  /**
   * Check to see if the etag changed since last update.
   *
   * Validates the etag difference in the saved version to the api version. If
   * they are the same then the profile has not changed and we can carry on. If
   * the etag is different we need to run the update.
   * @return boolean [description]
   */
  protected function isETagDifferent() {
    $importer = $this->getEntityImporter()->getMachineName();
    $data = $this->getData();
    $etag = CAPx::getEntityETag($importer, $data['profileId']);

    return !($etag == $data['meta']['etag']);
  }

  /**
   * [setEntity description]
   * @param [type] $entity [description]
   */
  protected function setEntity($entity) {
    $this->entity = $entity;
  }

  /**
   * [getEntity description]
   * @return [type] [description]
   */
  protected function getEntity() {
    return $this->entity;
  }

  /**
   * [skipEtagCheck description]
   * @param  boolean $bool [description]
   * @return [type]        [description]
   */
  public function skipEtagCheck($bool = NULL) {
    if (is_bool($bool)) {
      $this->force = $bool;
    }

    // Allow a debug force var.
    $debug = variable_get("stanford_capx_debug_always_force_etag", -1);
    if ($debug !== -1) {
      return $debug;
    }

    return $this->force;
  }

}
