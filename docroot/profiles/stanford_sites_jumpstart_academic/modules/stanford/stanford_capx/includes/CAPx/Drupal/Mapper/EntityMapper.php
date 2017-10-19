<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Mapper;

use CAPx\Drupal\Processors\FieldProcessors\FieldProcessor;
use CAPx\Drupal\Processors\FieldProcessors\EntityReferenceFieldProcessor;
use CAPx\Drupal\Processors\PropertyProcessors\PropertyProcessor;
use CAPx\Drupal\Processors\FieldCollectionProcessor;
use CAPx\Drupal\Processors\EntityReferenceProcessor;
use CAPx\Drupal\Util\CAPx;
use CAPx\Drupal\Util\CAPxMapper;
use CAPx\Drupal\Util\CAPxImporter;

class EntityMapper extends MapperAbstract {

  protected $index;

  /**
   * Execute starts the mapping process.
   *
   * @param \EntityDrupalWrapper $entity
   *   Expects the entity to be wrapped in entity_metadata_wrapper.
   * @param array $data
   *   An array of json data. The response from the API.
   *
   * @return Entity
   *   A fully saved or updated entity.
   */
  public function execute($entity, $data) {

    // Always attach the profileId to the entity
    $raw = $entity->value();
    $raw->capx['profileId'] = $data['profileId'];
    $raw->capxMapper = $this;
    $entity->set($raw);

    // Store this for later.
    $this->setEntity($entity);

    // Mappy map.
    // Each of the mapping functions will go through all of their values and
    // throw one error if there was a problem somewhere in the loop. The error
    // is logged to watchdog so handle any errors in each of these by throwing
    // only one error up a level.

    // FIELDS.
    try {
      $this->mapFields($data);
    }
    catch (\Exception $e) {
      $this->setError($e);
    }

    // PROPERTIES.
    try {
      $this->mapProperties($data);
    }
    catch (\Exception $e) {
      $this->setError($e);
    }

    // FIELD COLLECTIONS.
    try {
      // Field Collections are special. Special means more code. They get their
      // own mapProcess even though they are sort of a field.
      $this->mapFieldCollections($data);
    }
    catch (\Exception $e) {
      $this->setError($e);
    }

    // REFERENCES.
    try {
      $this->mapReferences();
    }
    catch (\Exception $e) {
      $this->setError($e);
    }

    // Even if there were errors we should have an entity by this point.
    return $entity;
  }

  /**
   * Map all of the fields.
   *
   * Map all of the fields that have settings in the mapper to their field on
   * the entity. Loop through each setting and get the data out of the response
   * array.
   *
   * @param array $data
   *   An array of data from the API.
   */
  public function mapFields($data) {

    $config = $this->getConfig();
    /** @var \EntityDrupalWrapper $entity */
    $entity = $this->getEntity();
    $error = FALSE;
    $d = $data;

    // Loop through each field and run a field processor on it.
    foreach ($config['fields'] as $fieldName => $remoteDataPaths) {
      // Get some information about the field we are going to process.
      $fieldInfoField = field_info_field($fieldName);
      if ($fieldInfoField) {
        $fieldInfoInstance = field_info_instance($entity->type(), $fieldName, $entity->getBundle());

        if ($fieldInfoInstance) {
          $info = array();

          drupal_alter('capx_pre_map_field', $entity, $fieldName, $remoteDataPaths, $data);

          // Allow just one path as a string.
          // @todo For data structures like files we shouldn't convert data path to array.
          if (!is_array($remoteDataPaths)) {
            $remoteDataPaths = array($remoteDataPaths);
          }

          // Loop through each of the data paths.
          foreach ($remoteDataPaths as $key => $dataPath) {

            // No setting was provided.
            if (empty($dataPath)) {
              continue;
            }

            // Attempt to get the data based on the path that was provided.
            // No guarantee that the user will enter valid jsonpath notation
            // that does have a valid result.
            try {
              $info[$key] = $this->getRemoteDataByJsonPath($data, $dataPath);
            }
            catch (\Exception $e) {
              $error = TRUE;
              $message = 'There was an exception when trying to get data by @path. Exception message is: @message.';
              $message_vars = array(
                '@path' => $dataPath,
                '@message' => $e->getMessage(),
              );
              watchdog('stanford_capx_jsonpath', $message, $message_vars);
              continue;
            }
          }

          // If there is no data to map just carry on.
          if (empty($info)) {
            continue;
          }

          // If we are running a multiple entity mapping we only want part of
          // the result.
          if ($this->isMultiple()) {
            $info = $this->getMultipleIndexInfoResultField($info);
          }

          // Widgets can change the way the data needs to be parsed. Provide
          // that to the FieldProcessor.
          $widget = $fieldInfoInstance['widget']['type'];
          $field = $fieldInfoField['type'];

          // Create a new field processor and let it do its magic.
          try {
            $fieldProcessor = new FieldProcessor($entity, $fieldName);
            $fieldProcessor->field($field)->widget($widget)->put($info);
          }
          catch (\Exception $e) {
            // IF there was an exception we want to carry on processing but
            // let the entity mapper know. Throw an error after everything.
            $error = TRUE;
          }
          // Allow altering of an entity after this process.
          drupal_alter('capx_post_map_field', $entity, $fieldName);
        }
      }
      $data = $d;
    }

    // Set the entity again for changes.
    $this->setEntity($entity);

    // If there was an error we should let the previous function know.
    if ($error) {
      throw new \Exception("Error Processing Fields.");
    }

  }

  /**
   * Map properties to the entity.
   *
   * Take the data out of the JSON array and put it into a property on the
   * entity. Properties are much simplier than fields as they do not have a
   * number of columns and/or other special properties to worry about.
   *
   * @param array $data
   *   The response data from the API
   */
  public function mapProperties($data) {

    $config = $this->getConfig();
    $entity = $this->getEntity();
    $error = FALSE;

    // Loop through each property and run a property processor on it.
    foreach ($config['properties'] as $propertyName => $remoteDataPath) {
      drupal_alter('capx_pre_property_set', $entity, $data, $propertyName);
      try {
        $info = $this->getRemoteDataByJsonPath($data, $remoteDataPath);
      }
      catch (\Exception $e) {
        $error = TRUE;
        $message = 'There was an exception when trying to get data by @path. Exception message is: @message.';
        $message_vars = array(
          '@path' => $remoteDataPath,
          '@message' => $e->getMessage(),
        );
        watchdog('stanford_capx_jsonpath', $message, $message_vars);
        continue;
      }

      // If we are running a multiple entity mapping we only want part of
      // the result.
      if ($this->isMultiple()) {
        $info = $this->getMultipleIndexInfoResultProperty($info);
      }

      // Let the property processor do its magic.
      try {
        $propertyProcessor = new PropertyProcessor($entity, $propertyName);
        $propertyProcessor->put($info);
      }
      catch (\Exception $e) {
        // We want to continue even if there is an error so set this flag and
        // throw again later.
        $error = TRUE;
      }
    }

    // Set the entity again for changes.
    $this->setEntity($entity);

    // If there was an error we should let the previous function know.
    if ($error) {
      throw new \Exception("Error Processing Fields.");
    }
  }

  /**
   * Process field collection fields uniquely.
   *
   * Field Collection fields are a special field and need to be handled
   * differently. The field collection data needs to be saved as its own enitty
   * and then attached to the parent entity. Allow for this.
   *
   * @param array $data
   *   An array of field collection data information
   */
  public function mapFieldCollections($data) {

    try {
      $collections = $this->getConfigSetting('fieldCollections');
    }
    catch (\Exception $e) {
      // No collections. Just return.
      return;
    }

    // The parent entity.
    $entity = $this->getEntity();

    // Each field collection field.
    foreach ($collections as $fieldName => $collectionMapper) {

      // Validate that the field exists.
      if (!isset($entity->{$fieldName})) {
        watchdog('stanford_capx', 'No field collection field on this entity with name: ' . $fieldName, WATCHDOG_NOTICE);
        continue;
      }

      // If field exists we will need to clear out the old values. Create a new
      // field collection each time.
      // @todo: rethink the new field collection each time as there may be
      // additional data on the FC.
      $entity->{$fieldName}->set(null);

      // Allow the field collection processor to do its magic.
      $collectionProcessor = new FieldCollectionProcessor($collectionMapper, $data);
      $collectionProcessor->setParentEntity($entity);
      $collectionProcessor->execute();

    }

    // Set the entity again for changes.
    $this->setEntity($entity);
  }

  /**
   * Process entity reference fields uniquely.
   *
   * Reference fields are a special field and need to be handled differently.
   * Allow for the ability to look for an item to attach to from the API
   * that has already been imported.
   *
   */
  public function mapReferences() {

    try {
      $references = $this->getConfigSetting('references');
    }
    catch (\Exception $e) {
      // No references. Just return.
      return;
    }

    // Nothing to do here.
    if (empty($references)) {
      return;
    }

    $entity = $this->getEntity();

    // Loop through each reference field and try to match up with another
    // entity from another importer.
    foreach ($references as $fieldName => $values) {
      $target = array_pop($values);
      $processor = new EntityReferenceProcessor($entity, $this->getImporter(), $target);
      $referenceEntity = $processor->execute();

      // No possible references available. End here.
      if (empty($referenceEntity)) {
        continue;
      }

      // wrap it up.
      $referenceEntity = entity_metadata_wrapper($this->getEntityType(), $referenceEntity);

      // Map the reference.
      $entityReferenceFieldProcessor = new EntityReferenceFieldProcessor($entity, $fieldName);
      $entityReferenceFieldProcessor->put($referenceEntity);

    }

    // Set the entity to apply any changes this function may have had.
    $this->setEntity($entity);
  }

  /**
   * Checks that fields used in this mapper still in place.
   *
   * If it happens that field used in mapper will be removed from bundle
   * or from the system entirely this will put a watchdog message and put a
   * persistent message for admin users on admin pages.
   *
   * @return bool
   *   Boolean indicating status of mapper fields.
   */
  public function checkFields() {
    $fields_status = TRUE;
    $config = $this->getConfig();
    $entity_type = $config['entity_type'];
    $bundle = $config['bundle_type'];
    $fields = $config['fields'];
    $collections = $config['fieldCollections'];
    $items = array();

    foreach ($fields as $fieldName => $values) {
      $items[] = array("name" => $fieldName, "bundle" => $bundle, "entity" => $entity_type);
    }

    foreach ($collections as $fcMapper) {
      $fcConfig = $fcMapper->getConfig();
      foreach ($fcConfig['fields'] as $fieldName => $values) {
        $items[] = array("name" => $fieldName, "bundle" => $fcMapper->bundle, "entity" => "field_collection_item");
      }
    }

    foreach ($items as $fieldInfo) {

      $fieldName = $fieldInfo['name'];
      $bundle = $fieldInfo['bundle'];
      $entity_type = $fieldInfo['entity'];

      $fieldInfoField = field_info_field($fieldName);
      if ($fieldInfoField) {
        $fieldInfoInstance = field_info_instance($entity_type, $fieldName, $bundle);
        if (!$fieldInfoInstance) {
          // Field was removed from this bundle.
          $fields_status = FALSE;
          $messages = variable_get('stanford_capx_admin_messages', array());
          $mapper = $this->getMapper();
          $message_key = $mapper->getMachineName() . ':' . $entity_type . ':' . $bundle . ':' . $fieldName;

          if (empty($messages[$message_key])) {
            $message_vars = array(
              '%field' => $fieldName,
              '%entity_type' => $entity_type,
              '%bundle' => $bundle,
              '!mapper' => l(check_plain($mapper->label()), 'admin/config/capx/mapper/edit/' . $mapper->getMachineName()),
            );
            $message = t('Field %field was removed from the %entity_type bundle %bundle, but is still used in !mapper. You should check configuration of the specified mapping!');
            watchdog('stanford_capx_admin_messages', $message, $message_vars, WATCHDOG_ERROR);
            $messages[$message_key] = array(
              'text' => $message,
              'message_vars' => $message_vars,
            );
            variable_set('stanford_capx_admin_messages', $messages);
          }
        }
      }
      else {
        // Field was removed from system.
        $fields_status = FALSE;
        $messages = variable_get('stanford_capx_admin_messages', array());
        $message_key = $fieldName;

        if (empty($messages[$message_key])) {
          $mappers = CAPxMapper::loadAllMappers();
          // Filtering mappers that uses this field.
          $mapper_links = array();
          foreach ($mappers as $mapper) {
            if (array_key_exists($fieldName, $mapper->fields)) {
              $mapper_links[$mapper->getMachineName()] = l(check_plain($mapper->label()), 'admin/config/capx/mapper/edit/' . $mapper->getMachineName());
            }
          }
          $message_vars = array('%field' => $fieldName, '!mappers' => implode(', ', $mapper_links));
          $message = t('Field %field was removed from the system, but is still used in !mappers. You should check configuration of the specified mappers!');
          watchdog('stanford_capx_admin_messages', $message, $message_vars, WATCHDOG_ERROR);
          $messages[$message_key] = array(
            'text' => $message,
            'message_vars' => $message_vars,
            'mappers' => $mapper_links,
          );
          variable_set('stanford_capx_admin_messages', $messages);
        }
      }
    }

    return $fields_status;
  }

  /**
   * Checks mapper status.
   *
   * @param string $importer
   *   Importer machine name.
   *
   * @return bool
   *  Mapper status.
   */
  public function valid($importer) {
    $this->setImporter($importer);

    $entity_status = $this->checkEntity();
    $fields_status = $this->checkFields();

    return ($entity_status && $fields_status);
  }

  /**
   * Checks if the entity type and bundle configured for mapper is still in place.
   *
   * @return bool
   *   Boolean indicating status of mapper entity.
   */
  public function checkEntity() {
    $entity_status = FALSE;
    $entity_type = $this->getConfigSetting('entity_type');
    $bundle = $this->getConfigSetting('bundle_type');

    $entity_info = entity_get_info($entity_type);
    if ($entity_info) {
      if (!isset($entity_info['bundles']) || empty($entity_info['bundles'][$bundle])) {
        $mapper = $this->getMapper();
        $message_key = $this->getImporter();
        $message_vars = array(
          '%mapper' => $mapper->label(),
          '%entity_type' => $entity_info['label'],
          '%bundle' => $bundle,
        );
        $message_text = t('Invalid bundle setting on %mapper. The bundle %bundle is no longer available and should either be restored, or the mapping %mapper should be deleted.');
        watchdog('stanford_capx_mapper_issue', $message_text, $message_vars, WATCHDOG_ERROR);
      }
      else {
        // Entity end bundle info is in place - status OK.
        $entity_status = TRUE;
      }
    }
    else {
      $mapper = $this->getMapper();
      $message_key = $this->getImporter();
      $message_vars = array(
        '%mapper' => $mapper->label(),
        '%entity_type' => $entity_type,
        '%bundle' => $bundle,
      );
      $message_text = t('Invalid entity setting on %mapper. The entity %entity_type is no longer available. Please restore the entity type or remove the mapping.');
      watchdog('stanford_capx_mapper_issue', $message_text, $message_vars, WATCHDOG_ERROR);
    }

    // Something is wrong - removing mapper config.
    if (!$entity_status) {

      $importers = $this->getAffectedImporters();
      $importer_links = array();
      foreach ($importers as $importer) {
        $importer_links[$importer->getMachineName()] = l(check_plain($importer->label()), 'admin/config/capx/importer/edit/' . $importer->getMachineName());
      }

      $message_vars['!importers'] = implode(', ', $importer_links);
      $message_text .= ' ';
      $message_text .= t('The following importers are using an invalid mapping. Please update or delete the mapping settings: !importers.');

      $messages = variable_get('stanford_capx_admin_messages', array());
      $messages[$message_key] = array(
        'text' => $message_text,
        'message_vars' => $message_vars,
        'importers' => $importer_links,
      );

      variable_set('stanford_capx_admin_messages', $messages);
    }

    return $entity_status;
  }

  /**
   * Returns array of importers that are using current mapper.
   *
   * @return array
   *   Array is keyed by importer machine name.
   */
  public function getAffectedImporters() {
    $mapper = $this->getMapper();
    $importers = CAPxImporter::loadAllImporters();
    $affected = array();
    foreach ($importers as $importer) {
      if ($importer->mapper == $mapper->getMachineName()) {
        $affected[$importer->getMachineName()] = $importer;
      }
    }

    return $affected;
  }

  /**
   * Boolean to whether or not this is a multiple import or not.
   * @return boolean [description]
   */
  public function isMultiple() {
    try {
      return $this->getConfigSetting("multiple");
    }
    catch (\Exception $e) {
      return FALSE;
    }
  }

  /**
   * Sets the multiple config value to passed in.
   * @param $val bool
   *   Boolean for multiple or not
   */
  public function setIsMultiple($val = TRUE) {
    $this->config['multiple'] = $val;
  }

  /**
   * get Subquery wrapper
   */
  public function getSubquery() {
    try {
      return $this->getConfigSetting("subquery");
    }
    catch (\Exception $e) {
      return FALSE;
    }
  }

  /**
   * get guuid wrapper
   */
  public function getGUUIDQuery() {
    try {
      return $this->getConfigSetting("guuidquery");
    }
    catch (\Exception $e) {
      return FALSE;
    }
  }

  /**
   * [getIndex description]
   * @return [type] [description]
   */
  public function getIndex() {
    return $this->index;
  }

  /**
   * [setIndex description]
   * @param [type] $i [description]
   */
  public function setIndex($i) {
    if (is_int($i) && $i >= 0) {
      $this->index = $i;
    }
    else {
      throw new \Exception("Could not set index. Invalid option.");

    }
  }

  /**
   * [getMultipleIndexInfoResult description]
   * @param  [type] $info [description]
   * @return [type]       [description]
   */
  protected function getMultipleIndexInfoResultField($info) {
    $index = $this->getIndex();
    $keys = array_keys($info);
    $ret = array();

    foreach ($keys as $key) {
      if (isset($info[$key][$index])) {
        $ret[$key] = array($info[$key][$index]);
      }
    }

    return !empty($ret) ? $ret : $info;
  }

  /**
   * @param $info
   * @return array
   */
  protected function getMultipleIndexInfoResultProperty($info) {
    $index = $this->getIndex();

    // If an index value exists:
    if (isset($info[$index])) {
      return array($info[$index]);
    }

    return $info;
  }

}
