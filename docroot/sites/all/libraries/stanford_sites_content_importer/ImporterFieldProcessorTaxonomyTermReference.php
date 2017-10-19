<?php
/**
 * @file
 */

/**
 *
 */
class ImporterFieldProcessorTaxonomyTermReference extends ImporterFieldProcessor {

  /**
   * [process description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field_name  [description]
   * @return [type]              [description]
   */
  public function process(&$entity, $entity_type, $field_name) {

    foreach ($entity->{$field_name} as $lang => $values) {
      foreach ($values as $key => $value) {
        if (!is_numeric($value['tid'])) {
          $uuid = $value['tid'];
          $term = entity_uuid_load('taxonomy_term', array($uuid));

          if (!$term) {
            try {
              $term = $this->taxonomy_term_reference_field_create_item($uuid);
            }
            catch(Exception $e) {
              unset($entity->{$field_name}[$lang][$key]);
              continue;
            }
          }
          else {
            $term = array_pop($term);
          }


          // If still no term just unset it and continue.
          if (!$term) {
            unset($entity->{$field_name}[$lang][$key]);
            continue;
          }

          // Set tid.
          $entity->{$field_name}[$lang][$key]['tid'] = $term->tid;

        } // if!numeric
      }
    }
  }

  /**
   * [taxonomy_term_reference_field_create_item description]
   * @param  [type] $uuid [description]
   * @return [type]       [description]
   */
  private function taxonomy_term_reference_field_create_item($uuid) {
    $endpoint = $this->get_endpoint();
    try {
      $term_response = drupal_http_request($endpoint . '/taxonomy_term/' . $uuid . '.json');
    }
    catch(Exception $e) {
      return false;
    }

    if ($term_response->code !== "200") {
      return false;
    }

    $term_obj = drupal_json_decode($term_response->data);
    $term_obj = (object) $term_obj;
    unset($term_obj->tid);

    $vocab = taxonomy_vocabulary_machine_name_load($term_obj->vocabulary_machine_name);
    $term_obj->vid = $vocab->vid;

    taxonomy_term_save($term_obj);

    return $term_obj;
  }


}
