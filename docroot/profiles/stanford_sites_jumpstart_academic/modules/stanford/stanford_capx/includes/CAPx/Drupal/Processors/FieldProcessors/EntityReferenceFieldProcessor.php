<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class EntityReferenceFieldProcessor {

  protected $entity;
  protected $fieldName;

  public function __construct($entity, $fieldName) {
    $this->entity = $entity;
    $this->fieldName = $fieldName;
  }

  /**
   * Default implementation of put.
   */
  public function put($relatedEntity) {
    $id = $relatedEntity->getIdentifier();
    $entity = $this->entity;
    $field = $entity->{$this->fieldName};

    // Metadata wrapper is smarter than plain field info.
    switch (get_class($field)) {
      // Structure wrapper assumes we providing multiple columns.
      case 'EntityStructureWrapper':
      case 'EntityListWrapper':
        $field->set(array($id));
        break;

      // Value wrapper assumes we providing single value.
      case 'EntityDrupalWrapper':
      case 'EntityValueWrapper':
        $field->set($id);
        break;
    }
  }


}
