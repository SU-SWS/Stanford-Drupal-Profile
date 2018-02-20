<?php
/**
 * @file
 * A class to process email fields.
 */

/**
 * Importer Field Processor for Email fields.
 */
class ImporterFieldProcessorEmail extends ImporterFieldProcessor {

  /**
   * Process any email field.
   *
   * Make an neccessary chagnes to this field before saving it.
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
