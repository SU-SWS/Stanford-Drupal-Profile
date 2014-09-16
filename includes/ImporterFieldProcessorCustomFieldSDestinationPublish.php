<?php
/**
 * @file
 */

/**
 *
 */
class ImporterFieldProcessorCustomFieldSDestinationPublish extends ImporterFieldProcessor {

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
        $entity->status = $entity->{$field_name}[LANGUAGE_NONE][0]['value'];
      }
    }
  }

}
