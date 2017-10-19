<?php
/**
 * @file
 */

/**
 *
 */
class ImporterFieldProcessorEntityreference extends ImporterFieldProcessor {

  /**
   * [process description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field_name  [description]
   * @return [type]              [description]
   */
  public function process(&$entity, $entity_type, $field_name) {
    $values = $entity->{$field_name}[LANGUAGE_NONE];

    // Nothing to do...
    if (empty($values)) {
      return;
    }

    foreach ($values as $index => $info) {

      // UUID module on the server overtakes this and serves up UUIDs. This is
      // great except when a site does not have the UUID module available.
      if (!is_int($info['target_id']) && !function_exists('entity_get_id_by_uuid')) {
        unset($entity->{$field_name}[LANGUAGE_NONE][$index]);
      }

      // If UUID is available...
      if (function_exists('entity_get_id_by_uuid')) {
        $ref_entity = reset(entity_get_id_by_uuid('node', array($info['target_id'])));
        if (is_numeric($ref_entity)) {
          $entity->{$field_name}[LANGUAGE_NONE][$index]['target_id'] = $ref_entity;
        }
        else {
          unset($entity->{$field_name}[LANGUAGE_NONE][$index]);
        }
      }

    }

    sort($entity->{$field_name}[LANGUAGE_NONE]);

  }

}
