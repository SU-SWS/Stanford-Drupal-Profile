<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Util;
use CAPx\APILib\HTTPClient;
use Guzzle\Http\Exception\ClientErrorResponseException;

class CAPx {

  /**
   * Returns an array of loaded profile entities.
   *
   * @param string $type
   *   The entity type to load
   * @param array $conditions
   *   An array of conditions to use in the DB query when looking for profiles.
   *
   * @return array
   *   An array of loaded profile entities.
   */
  public static function getProfiles($type, $conditions = array()) {

    if (!$type) {
      throw new \Exception("Type required for getProfiles", 1);
    }

    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_type', 'entity_id'))
      ->condition('entity_type', $type)
      ->orderBy('id', 'DESC');

    foreach ($conditions as $key => $value) {
      $query->condition($key, $value);
    }

    $result = $query->execute();
    $assoc = $result->fetchAllAssoc('entity_id');
    $ids = array_keys($assoc);

    return entity_load($type, $ids);
  }

  /**
   * Returns an array of loaded enties by the importer machine name.
   *
   * @param string $machine_name
   *   The importer machine name
   *
   * @return array
   *   An arry of entity objects
   */
  public static function getProfilesByImporter($machine_name) {
    $profiles = NULL;

    $importer = CAPxImporter::loadEntityImporter($machine_name);
    if ($importer) {
      $type = $importer->getEntityType();
      $bundle = $importer->getBundleType();

      $conditions = array(
        'importer' => $machine_name,
      );

      $profiles = CAPx::getProfiles($type, $conditions);
    }
    else {
      $vars = array(
        '%name' => $machine_name,
        '!log' => l(t('log messages'), 'admin/reports/dblog'),
      );
      drupal_set_message(t('There was an issue loading the importer with %name machine name. Check !log.', $vars), 'error');
    }

    return $profiles;
  }

  /**
   * Returns an array of profileIds that match the argument conditions.
   *
   * @param string $type
   *   The type of entity.
   *
   * @param array $conditions
   *   An array of key => value arguments to use in a select query.
   *
   * @param string $operator
   *   A comparison operator to use with all the $conditions that are passed in.
   *
   * @return array
   *   An array of entity id integers.
   */
  public static function getProfileIds($type, $conditions = array(), $operator = "=") {

    if (!$type) {
      throw new \Exception("Type required for getProfiles", 1);
    }

    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_id'))
      ->condition('entity_type', $type, $operator)
      ->orderBy('id', 'DESC');

    foreach ($conditions as $key => $value) {
      $query->condition($key, $value);
    }

    $result = $query->execute();
    $ids = $result->fetchCol();

    return $ids;
  }

  /**
   * Returns a fully loaded entity from the DB.
   *
   * @param string $entityType
   *   The entity type (eg: node, block, user)
   * @param string $bundleType
   *   The name of the bundle we a loading (eg: page, article)
   * @param int $profileId
   *   The profile id from the CAP API.
   *
   * @return object
   *   A fully loaded entity from the DB.
   */
  public static function getEntityByProfileId($entityType, $bundleType, $profileId) {
    // @todo: CACHE THIS!

    $entityId = CAPx::getEntityIdByProfileId($entityType, $bundleType, $profileId);

    if (!$entityId) {
      return FALSE;
    }

    $entity = entity_load_single($entityType, $entityId);
    return $entity;

  }

  /**
   * Returns an entity id by its profile id, type, and bundle.
   *
   * @param string $entityType
   *   The entity type (eg: node, block, user)
   * @param string $bundleType
   *   The name of the bundle we a loading (eg: page, article)
   * @param int $profileId
   *   The profile id from the CAP API.
   *
   * @return int
   *   The entity id (not CAP API id)
   */
  public static function getEntityIdByProfileId($entityType, $bundleType, $profileId) {

    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_id'))
      ->condition('entity_type', $entityType)
      ->condition('bundle_type', $bundleType)
      ->condition('profile_id', $profileId)
      ->orderBy('id', 'DESC')
      ->execute()
      ->fetchAssoc();

    return isset($query['entity_id']) ? $query['entity_id'] : FALSE;

  }

  /**
   * Returns the profile Id of a loaded entity.
   *
   * @param object $entity
   *   A loaded entity object
   *
   * @return int
   *   The cap API profile id.
   */
  public static function getProfileIdByEntity($entity) {
    // BEAN is returning its delta when using this.
    // $id = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($id, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);

    $entityType = $entity->type();
    $bundleType = $entity->getBundle();

    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('profile_id'))
      ->condition('entity_type', $entityType)
      ->condition('bundle_type', $bundleType)
      ->condition('entity_id', $id)
      ->orderBy('id', 'DESC')
      ->execute()
      ->fetchAssoc();

    return isset($query['profile_id']) ? $query['profile_id'] : FALSE;
  }

  /**
   * Returns a loaded entity or false.
   *
   */
  public static function getEntityIdByGUUID($importerMachineName, $profileId, $guuid) {

    $query = db_select("capx_profiles", 'capx')
      ->fields('capx', array('entity_type', 'entity_id'))
      ->condition('importer', $importerMachineName)
      ->condition('profile_id', $profileId)
      ->condition('guuid', $guuid)
      ->orderBy('id', 'DESC')
      ->execute()
      ->fetchAssoc();

    // If we gots one send it back.
    if (isset($query['entity_id'])) {
      $entities = entity_load($query['entity_type'], array($query['entity_id']));
      return array_pop($entities);
    }

    return FALSE;
  }

  /**
   * Create new profile record.
   *
   * Inserts a record into the capx_profiles table with information that helps
   * the rest of the module keep track of what it is and where it came from.
   *
   * @param Entity $entity
   *   The entity that was just saved.
   */
  public static function insertNewProfileRecord($entity, $profileId, $etag, $importer, $guuid = '') {
    // BEAN is returning its delta when using this.
    // $entityId = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($id, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);
    $bundleType = $entity->getBundle();
    $time = time();

    $record = array(
      'entity_type' => $entityType,
      'entity_id' => $id,
      'importer' => $importer,
      'profile_id' => $profileId,
      'etag' => $etag,
      'bundle_type' => $bundleType,
      'sync' => 1,
      'last_sync' => $time,
      'orphaned' => 0,
      'guuid' => $guuid,
    );

    $yes = drupal_write_record('capx_profiles', $record);

    if (!$yes) {
      watchdog('CAPx', 'Could not insert record for capx_profiles on profile id: ' . $profileId, array(), WATCHDOG_ERROR);
    }
  }

  /**
   * Updates a profile recored data.
   *
   * @param  [type] $entity    [description]
   * @param  [type] $profileId [description]
   * @param  [type] $etag      [description]
   * @param  [type] $importer  [description]
   * @return [type]            [description]
   */
  public static function updateProfileRecord($entity, $profileId, $etag, $importer, $guuid = '') {

    $time = time();
    // BEAN is returning its delta when using this.
    // $id = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($id, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);
    $bundleType = $entity->getBundle();

    $record = array(
      'entity_type' => $entityType,
      'entity_id' => $id,
      'importer' => $importer,
      'profile_id' => $profileId,
      'etag' => $etag,
      'last_sync' => $time,
      'guuid' => $guuid,
    );

    $keys = array(
      'entity_type',
      'entity_id',
      'importer',
      'profile_id',
      'guuid',
    );

    $yes = drupal_write_record('capx_profiles', $record, $keys);

  }

  /**
   * Get the etag for an entity.
   *
   * @param string $importer
   *   Importer machine name.
   * @param string $profileId
   *   Profile ID.
   *
   * @return string
   *   Profile Etag.
   */
  public static function getEntityETag($importer, $profileId) {

    $result = db_select('capx_profiles', 'capxp')
      ->fields('capxp', array('etag'))
      ->condition('importer', $importer)
      ->condition("profile_id", $profileId)
      ->execute();

    return $result->fetchField();
  }

  /**
   * Invalidates profile etags by mapper or by importer.
   *
   * When a mapper or an importer changes we need to invalidate the etag on the
   * profiles associated with it.
   *
   * @param string $type
   *   Either mapper or importer
   * @param object $object
   *   Either a mapper or importer CFEntity
   */
  public static function invalidateEtags($type, $object) {
    $or = db_or();

    if ($type == "importer") {
      $or->condition("importer", $object->getMachineName(), "=");
    }
    else if ($type == "mapper") {
      $importers = CAPxImporter::loadImportersByMapper($object);

      if(empty($importers)) {
        return;
      }

      foreach ($importers as $k => $v) {
        $or->condition("importer", $v->getMachineName(), "=");
      }
    }

    $result = db_update("capx_profiles")
    ->fields(array(
      "etag" => 'invalidated',
      ))
    ->condition($or)
    ->execute();

  }

  /**
   * Clears the stanford_capx_profiles queue.
   *
   * If you need to clear the queue because of config changes, this is your method.
   */
  public static function clearTheQueue() {
    $queue = \DrupalQueue::get('stanford_capx_profiles', TRUE);
    $queue->deleteQueue();
  }

  /**
   * Invalidates profile photo timestamp by importer.
   *
   * When a mapper changes we need to invalidate the timestamp on the
   * profile photos associated with it.
   *
   * @param object $importers
   *   Importers acquired using CAPxImporter::loadImportersByMapper($mapper);
   */
  public static function invalidateTimestamp($importers) {
    $importer_machine_names = array();
    foreach ($importers as $importer) {
      $importer_machine_names[] = $importer->machine_name;
    }
    $q = db_select('capx_profiles', 'cp');
    $q->addfield('cp', 'entity_id');
    $q->condition('cp.importer', $importer_machine_names, 'IN');
    $r = $q->execute()->fetchAll();
    $profile_ids = array();
    if (!empty($r)) {
      foreach ($r as $id) {
        $profile_ids[] = $id->entity_id;
      }
      $q = db_select('field_data_field_s_person_profile_picture', 'pp');
      $q->addfield('pp', 'field_s_person_profile_picture_fid');
      $q->condition('pp.entity_id', $profile_ids, 'IN');
      $r = $q->execute()->fetchAll();
      $fids = array();
      if (!empty($r)) {
        foreach ($r as $fid) {
          $fids[] = (int) $fid->field_s_person_profile_picture_fid;
        }
        $q = db_update('file_managed');
        $q->fields(array('timestamp' => 0));
        $q->condition('fid', $fids, 'IN');
        $q->execute();
        cache_clear_all('*', 'cache_image', TRUE);
      }
    }
  }

  /**
   * Remove a profile record.
   *
   * Removes a profile record from the capx_profiles table when an entity is
   * deleted. No longer need to keep track of it.
   *
   * @param Entity $entity
   *   The entity that is being deleted.
   */
  public static function deleteProfileRecord($entity) {

    // BEAN is returning its delta when using this.
    // $id = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($id, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);

    db_delete('capx_profiles')
      ->condition('entity_type', $entityType)
      ->condition('entity_id', $id)
      ->execute();
  }

  /**
   * Check to see if profile is an orphan.
   *
   * @param Entity $profile
   *   A loaded entity.
   *
   * @return bool
   *   TRUE if orphaned FALSE if not.
   */
  public static function profileIsOrphan($profile) {
    if (isset($profile->capx)) {
      return (bool) $profile->capx['orphaned'];
    }
    return FALSE;
  }

  /**
   * Returns the API endpoint.
   * @todo Move this to CAPxConnection
   *
   * @return string
   *  Full URL to the API endpoint
   */
  public static function getAPIEndpoint() {
    return variable_get('stanford_capx_api_base_url', 'https://api.stanford.edu');
  }

  /**
   * Returns the authentication endpoint.
   *
   * @todo Move this to CAPxConnection
   * @return string
   *   Full url to the auth endpoint
   */
  public static function getAuthEndpoint() {
    return variable_get('stanford_capx_api_auth_uri', 'https://authz.stanford.edu/oauth/token');
  }

  /**
   * Returns a decrypted username that authenticates with the cap api.
   *
   * @todo Mmove this to CAPxConnection
   *
   * @return string
   *   The username
   */
  public static function getAuthUsername() {
    return decrypt(variable_get('stanford_capx_username', ''));
  }

  /**
   * Returns a decrypted password that authenticates with the cap api.
   * @todo Move this to CAPxConnection
   * @return string
   *   The password
   */
  public static function getAuthPassword() {
    return decrypt(variable_get('stanford_capx_password', ''));
  }


}
