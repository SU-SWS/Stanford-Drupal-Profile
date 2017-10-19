<?php
/**
 *@file
 */

/**
 * ImporterFieldProcessorFieldCollection
 * Processess field collections.
 */
class ImporterFieldProcessorFieldCollection extends ImporterFieldProcessor {


  /**
   * [process description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field_name  [description]
   * @return [type]              [description]
   */
  public function process(&$entity, $entity_type, $field_name) {
    $this->process_field_field_collection($entity, $entity_type, $field_name);
  }

  /**
   * [set_storage description]
   * @param [type] $key   [description]
   * @param [type] $value [description]
   */
  public function set_storage($key, $value) {
    parent::set_storage($key, $value);

    if ($key == "field_collections") {
      $static_values = &drupal_static('ImporterFieldProcessorFieldCollection', array());
      $static_values = $this->get_storage($key);
    }

    if ($key == "field_collections_patch_later") {
      $static_values = &drupal_static('ImporterFieldProcessorFieldCollectionPatchLater', array());
      $static_values = $this->get_storage($key);
    }


  }

  /**
   * [process_field_field_collection_item description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field       [description]
   * @return [type]              [description]
   */
  protected function process_field_field_collection(&$entity, $entity_type, $field_name) {
    $field = $entity->{$field_name};
    $uuids = $this->get_storage('field_collections');

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
          $field_collection = $this->process_field_field_collection_item_create_item($uuid, $entity, $entity_type);
          $uuids[$uuid] = $field_collection;
        }
        catch(Exception $e) {
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
    $this->set_storage('field_collections', $uuids);

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
   * [process_field_field_collection_item_create_item description]
   * @param  [type] $uuid [description]
   * @return [type]       [description]
   */
  protected function process_field_field_collection_item_create_item($uuid, &$host, $host_type) {
    $create_field_collections = $this->get_storage('create_field_collections');

    $endpoint = $this->get_endpoint();

    // Ask nicely for content.
    $result = drupal_http_request($endpoint . "/field_collection_item/" . $uuid, array('headers' => array('Accept' => 'application/json')));
    $data = ($result->code == "200") ? drupal_json_decode($result->data) : FALSE;

    // Die if no content.
    if (!$data) {
      throw new Exception("Could Not Fetch Field Colelction Item: " . $uuid);
    }

    // Remove previous id.
    unset($data['item_id']);

    // Create a new field collection with the data the server provided.
    $fc = entity_create('field_collection_item', $data);
    $fc->setHostEntity($host_type, $host);

    // Because FCs can have fields we need to process this as well.
    $importer = new SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->process_fields($fc, 'field_collection_item');

    // Cant do this yet.
    // $fc->save();

    // Store for later.
    $create_field_collections[] = $fc;
    $this->set_storage('create_field_collections', $create_field_collections);

    return $fc;
  }


}
