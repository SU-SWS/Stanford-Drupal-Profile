<?php
/**
 * @file
 * @author
 */

namespace CAPx\Drupal\Entities;

class CFEntityType extends \Entity {
  public $type;
  public $label;
  public $weight = 0;

  /**
   * Constructor method.
   *
   * @param array $values
   *   Values to pass into the type constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'capx_cfe_type');
  }

  /**
   * Implements isLocked().
   *
   * @return bool
   *   TRUE if the entity is locked.
   */
  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}
