<?php
/**
 * @file
 * A class to process long text fields.
 */

 /**
  * Importer Field Processor for long text field.
  */
class ImporterFieldProcessorTextLong extends ImporterFieldProcessor {

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

  }

}
