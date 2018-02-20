<?php
/**
 * @file
 * A class to process File fields.
 */

 /**
  * Importer Field Processor for file fields.
  */
class ImporterFieldProcessorFile extends ImporterFieldProcessor {

  /**
   * Process a file field.
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
    $this->processFieldFile($entity, $entity_type, $field_name);
  }

  /**
   * Proccess a file field.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $field_name
   *   The field on $entity that is being processed.
   */
  protected function processFieldFile(&$entity, $entity_type, $field_name) {
    $files = $this->getStorage('processed_files');
    $field = $entity->{$field_name};

    // Load into the array of tracked ids the new ones.
    foreach ($field as $lang => $values) {
      foreach ($values as $value) {
        if (isset($files['uuid'])) {
          continue;
        }
        $files[$value['uuid']] = array($value['fid']);
      }
    }

    // Keep a running track of the ones we have processed.
    foreach ($files as $uuid => $value) {
      if (!is_array($value)) {
        continue;
      }
      // Try to load the file.
      $ids = entity_get_id_by_uuid('file', array($uuid));
      if ($ids) {
        $fid = array_pop($ids);
        $files[$uuid] = file_load($fid);
      }
      else {
        try {
          $file = $this->processFieldFileCreateItem($uuid, $entity, $entity_type);
        }
        catch (Exception $e) {
          watchdog('ImporterFieldProcessorFile', $e->getMessage(), array(), WATCHDOG_NOTICE);
          if (function_exists('drush_log')) {
            drush_log($e->getMessage(), 'error');
          }
          $files[$uuid] = FALSE;
          continue;
        }
        $files[$uuid] = $file;
      }
    }

    $this->setStorage('processed_files', $files);

    // All of the items we have already have been keyed at this point. Now we
    // need to loop through the field and update the values.

    foreach ($entity->{$field_name} as $lang => $values) {
      foreach ($values as $k => $value) {
        $search_uuid = $value['uuid'];
        $file = $files[$search_uuid];

        // If the item_id is false then unset that id.
        if (!$file) {
          unset($entity->{$field_name}[$lang][$k]);
        }
        else {
          $file->display = 0;
          $entity->{$field_name}[$lang][$k] = (array) $file;
          $alt = !empty($field[$lang][$k]['alt']) ? $field[$lang][$k]['alt'] : "";
          $title = !empty($field[$lang][$k]['title']) ? $field[$lang][$k]['title'] : $alt;
          $entity->{$field_name}[$lang][$k]['alt'] = $alt;
          $entity->{$field_name}[$lang][$k]['title'] = $title;
        }

      }
    }

  }

  /**
   * Fetch and save the file from the content server.
   *
   * @param string $uuid
   *   The UUID of the file.
   *
   * @return object
   *   The fully saved file object.
   */
  public function processFieldFileCreateItem($uuid) {

    // Endpoint will almost always be the hardcoded one.
    $endpoint = $this->getEndpoint();

    // Ask nicely for content.
    $result = drupal_http_request($endpoint . "/file/" . $uuid, array('headers' => array('Accept' => 'application/json')));
    // Die if no content.
    $data = ($result->code == "200") ? drupal_json_decode($result->data) : FALSE;

    if (!$data) {
      throw new Exception("Could not fetch file: " . $uuid);
    }

    $file = (object) $data;
    unset($file->fid);

    // Try to save the remote file.
    $pend = parse_url($endpoint);
    $puri = parse_url($file->uri);

    // We shouldnt need this but for some reason filename is getting extra bits.
    $puri = str_replace("/", "", $puri);

    $expl = explode("/", $pend['path']);
    array_pop($expl);
    $base_path = implode("/", $expl);

    unset($puri['scheme']);
    $file_path = implode('/', $puri);

    $basename = drupal_basename($file->uri);
    $directory = str_replace($basename, "", $file->uri);
    if (!is_dir($directory)) {
      file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
    }

    $urlparts = explode("/", $file_path);
    foreach ($urlparts as $index => $part) {
      $urlparts[$index] = rawurlencode($part);
    }

    $clean_path = implode("/", $urlparts);

    $url = $pend['scheme'] . "://" . $pend['host'] . $base_path . "/sites/default/files/" . $clean_path;

    system_retrieve_file($url, $file->uri, 0, FILE_EXISTS_REPLACE);

    $file->alt = empty($file->alt) ? "" : $file->alt;
    $file->title = empty($file->title) ? "" : $file->title;

    file_save($file);

    return $file;
  }

}
