<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;
use CAPx\Drupal\Processors\EntityProcessor;
use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\Drupal\Util\CAPx;

class FieldCollectionProcessor extends EntityProcessor {

  // The field collection entity
  protected $fieldCollectionEntities = array();
  // The parent entity
  protected $parentEntity = null;

  /**
   * Override method execute.
   *
   * The field collection processor will assume all updates will create a new
   * field collection and toss the old one. No need to check for existing item.
   * @see  parent::execute();
   * @return FieldCollection the saved field collection.
   */
  public function execute() {
    $data = $this->getData();
    $mapper = $this->getMapper();
    $entityType = $mapper->getEntityType();
    $bundleType = $mapper->getBundleType();
    $parent = $this->getParentEntity();

    // Loop through an create new field collections based on the number of
    // results for each field. Keep looping through the index of data until
    // there is no more data to add to the entity. We can accomplish this by
    // checking to see if the last FC that was created is exactly the same as
    // the one just created. If they are identical then no new data is available
    // and the loop should be stopped.

    $mapper->setIsMultiple(true);
    $lastEntity = NULL;

    $i = 0;
    $hasValues = TRUE;
    while($hasValues) {
      $mapper->setIndex($i);
      $entity = $this->newEntity($entityType, $bundleType, $data, $mapper);
      if (!$entity) {
        $i++;
        continue;
      }
      drupal_alter('capx_new_fc', $entity);
      $entity = $mapper->execute($entity, $data);

      // Here we check to see if anything came out the other end.
      $hash = md5(serialize($entity));
      if ($hash == $lastEntity) {
        $hasValues = FALSE;
        break;
      }

      // Not the same. Store the current entity as the last entity before saving
      // or we will pollute the object with ids.
      $lastEntity = $hash;

      // Save.
      $entity->save();

      // Storage for something that may need it.
      $this->addFieldCollectionEntity($entity);

      // Add to index for next one.
      $i++;
    }

    // Remove the last two items from the entities array and from the parent
    // entity as they are full of duplicate or not complete data.
    $fieldName = $mapper->getBundleType();
    array_pop($this->fieldCollectionEntities);
    array_pop($this->fieldCollectionEntities);
    $rawParent = $parent->raw();
    array_pop($rawParent->{$fieldName}[LANGUAGE_NONE]);
    array_pop($rawParent->{$fieldName}[LANGUAGE_NONE]);
    $parent->set($rawParent);

    // Return all the things we just created.
    return $this->getFieldCollectionEntities();
  }

  /**
   * New entity override as FieldCollections have some different defualts.
   * @see parent:newEntity();
   */
  public function newEntity($entityType, $bundleType, $data, $mapper) {

    $properties = array(
      'type' => $bundleType,
      'uid' => 1, // @TODO - set this to something else.
      'status' => 1, // @TODO - allow this to change.
      'comment' => 0, // Any reason to set otherwise?.
      'promote' => 0, // Fogetaboutit.
      'field_name' => $bundleType,
    );

    // Create an empty entity.
    $entity = entity_create($entityType, $properties);

    $hostEntity = $this->getParentEntity();
    $hostType = $hostEntity->type();
    $entity->setHostEntity($hostType, $hostEntity->raw());

    // Wrap it up baby!
    $entity = entity_metadata_wrapper($entityType, $entity);
    return $entity;
  }

  /**
   * Setter function
   * @param Array $entities an array of field collection items
   */
  protected function addFieldCollectionEntity($entity) {
    $this->fieldCollectionEntities[] = $entity;
  }


  /**
   * Setter function
   * @param Array $entities an array of field collection items
   */
  public function setFieldCollectionEntities($entities) {
    $this->fieldCollectionEntities = $entities;
  }

  /**
   * Getter function
   * @return FieldCollectionItem the field collection item.
   */
  public function getFieldCollectionEntities() {
    return $this->fieldCollectionEntities;
  }

  /**
   * Setter function
   * @param Entity $entity The parent entity that the field collection
   * belongs to
   */
  public function setParentEntity($entity) {
    $this->parentEntity = $entity;
  }

  /**
   * Getter function
   * @return Entity The parent entity that the field collection belongs to.
   */
  public function getParentEntity() {
    return $this->parentEntity;
  }

}
