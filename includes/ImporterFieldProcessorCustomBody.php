<?php
/**
 * @file
 */

/**
 *
 */
class ImporterFieldProcessorCustomBody extends ImporterFieldProcessor {

  /**
   * [process description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field_name  [description]
   * @return [type]              [description]
   */
  public function process(&$entity, $entity_type, $field_name) {
    if ($entity_type == "node") {
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['value'])) {
        $entity->{$field_name}[LANGUAGE_NONE][0]['value'] = str_replace('/jsa-content', 'https://sites.stanford.edu/jsa-content', $entity->{$field_name}[LANGUAGE_NONE][0]['value']);
      }
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['summary'])) {
        $entity->{$field_name}[LANGUAGE_NONE][0]['summary'] = str_replace('/jsa-content', 'https://sites.stanford.edu/jsa-content', $entity->{$field_name}[LANGUAGE_NONE][0]['summary']);
      }
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['safe_value'])) {
        $entity->{$field_name}[LANGUAGE_NONE][0]['safe_value'] = str_replace('/jsa-content', 'https://sites.stanford.edu/jsa-content', $entity->{$field_name}[LANGUAGE_NONE][0]['safe_value']);
      }
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['safe_summary'])) {
        $entity->{$field_name}[LANGUAGE_NONE][0]['safe_summary'] = str_replace('/jsa-content', 'https://sites.stanford.edu/jsa-content', $entity->{$field_name}[LANGUAGE_NONE][0]['safe_summary']);
      }
    }
  }

}
