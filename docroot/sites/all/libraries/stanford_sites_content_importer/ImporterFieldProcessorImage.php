<?php
/**
 * @file
 * A class to process Image fields.
 */

 /**
  * Importer Field Processor for image fields.
  */
class ImporterFieldProcessorImage extends ImporterFieldProcessorFile {

  /**
   * Process an image field.
   *
   * Pass through to parent file processor.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $field_name
   *   The field on $entity that is being processed.
   */
  public function process(&$entity, $entity_type, $field_name) {
    parent::process($entity, $entity_type, $field_name);
  }

}
