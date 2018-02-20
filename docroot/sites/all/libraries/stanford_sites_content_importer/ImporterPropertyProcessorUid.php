<?php
/**
 * @file
 * A class to process the UID property.
 */

 /**
  * Importer Property Processor for the UID property.
  */
class ImporterPropertyProcessorUid extends ImporterFieldProcessor {

  /**
   * Process a property.
   *
   * Make any neccessary changes to a peroperty before saving it.
   *
   * @param object $entity
   *   The entity to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   * @param string $property
   *   The property on $entity that is being processed.
   */
  public function process(&$entity, $entity_type, $property) {

    // For this iteration we simply want to map the content to user 1
    // if a UUID is passed in the UID field of the node entity.

    if ($entity_type == "node") {
      if (!is_numeric($entity->{$property})) {
        $entity->{$property} = 1;
      }
    }

  }

}
