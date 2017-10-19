<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Mapper;

class FieldCollectionMapper extends EntityMapper {

  protected $bundle = null;

  /**
   * Additionaly to the parent set the bundle "field_name".
   * @see parent::__construct()
   *
   * @param array $mapper
   *   Additional configuration.
   */
  public function __construct($mapper) {
    $this->setBundle($mapper->settings['bundle_type']);
  }

  /**
   * Parent override...
   * @return string
   *   This type is always field_collection_item
   */
  public function getEntityType() {
    return 'field_collection_item';
  }

  /**
   * Parent override.
   * @return string
   *   The machine name of the bundle.
   */
  public function getBundleType() {
    return $this->bundle;
  }

  /**
   * Set the bundle type of this FieldCollectionMapper.
   *
   * @param string $name
   *   The name of the bundle
   */
  public function setBundle($name) {
    $this->bundle = $name;
  }

}
