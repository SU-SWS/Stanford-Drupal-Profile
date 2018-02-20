<?php
/**
 * @file
 * A class to process taxonomy term fields.
 */

 /**
  * Importer Field Processor for taxonomy term field.
  */
class ImporterFieldProcessorTaxonomyTermReference extends ImporterFieldProcessor {

  /**
   * Process a field.
   *
   * Make any neccessary changes to a field before saving it.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $field_name
   *   The field on $entity that is being processed.
   */
  public function process(&$entity, $entity_type, $field_name) {

    foreach ($entity->{$field_name} as $lang => $values) {
      foreach ($values as $key => $value) {
        if (!is_numeric($value['tid'])) {
          $uuid = $value['tid'];
          $term = entity_uuid_load('taxonomy_term', array($uuid));

          if (!$term) {
            try {
              $term = $this->taxonomyTermReferenceFieldCreateItem($uuid);
            }
            catch (Exception $e) {
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
   * Fetch and save the taxonomy term item from the content server.
   *
   * @param string $uuid
   *   The UUID of the taxonomy term item that is to be saved.
   *
   * @return object
   *   The fully saved taxonomy term object.
   */
  private function taxonomyTermReferenceFieldCreateItem($uuid) {
    $endpoint = $this->getEndpoint();
    try {
      $term_response = drupal_http_request($endpoint . '/taxonomy_term/' . $uuid . '.json');
    }
    catch (Exception $e) {
      return FALSE;
    }

    if ($term_response->code !== "200") {
      return FALSE;
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
