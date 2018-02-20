<?php
/**
 * @file
 * A class to process Entity Reference fields.
 */

 /**
  * Importer Field Processor for Entity Reference fields.
  */
class ImporterFieldProcessorFieldCollection extends ImporterFieldProcessor {


  /**
   * Process a field collection field.
   *
   * Make any neccessary chagnes to this field before saving it.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $field_name
   *   The field on $entity that is being processed.
   */
  public function process(&$entity, $entity_type, $field_name) {
    $this->processFieldFieldCollection($entity, $entity_type, $field_name);
  }

  /**
   * Override of setStorage method.
   *
   * @param mixed $key
   *   The associative array key for the stored value.
   * @param mixed $value
   *   The value for the $key.
   */
  public function setStorage($key, $value) {
    parent::setStorage($key, $value);

    if ($key == "field_collections") {
      $static_values = &drupal_static('ImporterFieldProcessorFieldCollection', array());
      $static_values = $this->getStorage($key);
    }

    if ($key == "field_collections_patch_later") {
      $static_values = &drupal_static('ImporterFieldProcessorFieldCollectionPatchLater', array());
      $static_values = $this->getStorage($key);
    }
  }

  /**
   * Process a field collection field.
   *
   * Field collections are entities themselves and the field has references to
   * those ids. They can change upon save and extra care is needed to preserve
   * them.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $field_name
   *   The field on $entity that is being processed.
   */
  protected function processFieldFieldCollection(&$entity, $entity_type, $field_name) {
    $field = $entity->{$field_name};
    $uuids = $this->getStorage('field_collections');

    // Load into the array of tracked ids the new ones.
    foreach ($field as $lang => $values) {
      foreach ($values as $key => $value) {
        if (isset($uuids['value'])) {
          continue;
        }
        $uuids[$value['value']] = array($value['value']);
      }
    }

    // Keep a running track of the ones we have processed.
    foreach ($uuids as $uuid => $value) {
      if (!is_array($value)) {
        continue;
      }
      // Try to load field collection.
      $ids = entity_get_id_by_uuid('field_collection_item', array($uuid));
      if ($ids) {
        $uuids[$uuid] = array_pop($ids);
      }
      else {
        try {
          $field_collection = $this->processFieldFieldCollectionItemCreateItem($uuid, $entity, $entity_type);
          $uuids[$uuid] = $field_collection;
        }
        catch (Exception $e) {
          watchdog('ImporterFieldProcessorFieldCollection', $e->getMessage(), array(), WATCHDOG_NOTICE);
          if (function_exists('drush_log')) {
            drush_log($e->getMessage(), 'error');
          }
          $uuids[$uuid] = FALSE;
          continue;
        }
      }

    }

    // Store processed fcs.
    $this->setStorage('field_collections', $uuids);

    // Prepare fields on the entity so it can be saved with the field collections.
    foreach ($entity->{$field_name} as $lang => $values) {
      foreach ($values as $key => $value) {
        if (isset($value['value']) && !is_numeric($value['value'])) {
          unset($entity->{$field_name}[$lang][$key]);
        }
      }
    }

  }

  /**
   * Process the field collection item entity.
   *
   * The field data will contain a reference to a field collection item so we
   * will need to fetch it from the server before being able to save it and
   * apply the new value to the field.
   *
   * @param string $uuid
   *   The UUID of the field collection entity to be imported and saved.
   * @param object $host
   *   The host entity which contains the field collection field.
   * @param string $host_type
   *   The host type entity name.
   */
  protected function processFieldFieldCollectionItemCreateItem($uuid, &$host, $host_type) {

    // Get any field collections out of storage.
    $create_field_collections = $this->getStorage('create_field_collections');
    $endpoint = $this->getEndpoint();

    // Ask nicely for content.
    $result = drupal_http_request($endpoint . "/field_collection_item/" . $uuid, array('headers' => array('Accept' => 'application/json')));
    $data = ($result->code == "200") ? drupal_json_decode($result->data) : FALSE;

    // Die if no content.
    if (!$data) {
      throw new Exception("Could Not Fetch Field Collection Item: " . $uuid);
    }

    // Remove previous id.
    unset($data['item_id']);

    // Create a new field collection with the data the server provided.
    $fc = entity_create('field_collection_item', $data);
    $fc->setHostEntity($host_type, $host);

    // Because FCs can have fields we need to process this as well.
    $importer = new SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->processFields($fc, 'field_collection_item');

    // Cant do this yet.
    // $fc->save();

    // Store for later.
    $create_field_collections[] = $fc;
    $this->setStorage('create_field_collections', $create_field_collections);

    return $fc;
  }

}
