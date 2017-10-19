<?php
/**
 * @file
 * @author
 */

namespace CAPx\Drupal\Entities;

class CFEControllerExportable extends \EntityAPIControllerExportable {

  /**
   * Create a new entity and provide some default values.
   *
   * @param array $values
   *   Values to be merged in with the default values.
   *
   * @return EntityAPIControllerExportable
   *   An entity class populated with default values.
   */
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'title' => '',
      'description' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
      'module' => 'stanford_capx',
      'settings' => array(),
      'meta' => array(),
    );
    return parent::create($values);
  }

  /**
   * Save function.
   *
   * @param EntityAPIControllerExportable $entity
   *   A fully populated entity ready for saving.
   * @param DatabaseTransaction $transaction
   *   A DB Object
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
  }

}
