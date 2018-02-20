<?php
/**
 * @file
 * A class to process Entity Reference fields.
 */

/**
 * Importer Field Processor for Entity Reference fields.
 */
class ImporterFieldProcessorEntityreference extends ImporterFieldProcessor {

  /**
   * Process a date time field.
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

    // Only if the values are present.
    $values = isset($entity->{$field_name}[LANGUAGE_NONE]) ? $entity->{$field_name}[LANGUAGE_NONE] : NULL;

    // Nothing to do...
    if (empty($values)) {
      return;
    }

    // Lopp through each of the values and attempt to find the reference by
    // UUID.
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
