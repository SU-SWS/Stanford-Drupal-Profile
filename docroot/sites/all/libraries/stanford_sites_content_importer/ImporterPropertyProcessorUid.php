<?php
/**
 * @file
 */

/**
 *
 */
class ImporterPropertyProcessorUid extends ImporterFieldProcessor {

  /**
   * [process description]
   * @param  [type] $entity      [description]
   * @param  [type] $entity_type [description]
   * @param  [type] $field_name  [description]
   * @return [type]              [description]
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
