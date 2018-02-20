<?php
/**
 * @file
 * A class to process date and time fields.
 */

/**
 * Importer Field Processor for Date Time fields.
 */
class ImporterFieldProcessorDatetime extends ImporterFieldProcessor {

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
    // Nothing to see here.
  }

}
