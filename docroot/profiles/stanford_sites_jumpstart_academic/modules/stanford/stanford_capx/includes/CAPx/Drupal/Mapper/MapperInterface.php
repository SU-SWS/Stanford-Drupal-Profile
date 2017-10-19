<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Mapper;

interface MapperInterface {

  /**
   * The one method to rule them all.
   * @param  Entity $entity the entity to map with
   * @param  array $data   the data to map to.
   */
  public function execute($entity, $data);

}
