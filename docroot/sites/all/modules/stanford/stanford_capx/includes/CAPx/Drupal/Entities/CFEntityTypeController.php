<?php
/**
 * @file
 * @author [author] <[email]>
 */
namespace CAPx\Drupal\Entities;

class CFEntityTypeController extends \EntityAPIControllerExportable {

  /**
   * Create method for the TypeController.
   *
   * @param array $values
   *   A set of values to pass into the default set.
   *
   * @return CFEntityTypeController
   *   This thing with populated values.
   */
  public function create(array $values = array()) {
    $values += array(
      'label' => '',
      'description' => '',
    );
    return parent::create($values);
  }

  /**
   * Save Task Type.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
  }

}
