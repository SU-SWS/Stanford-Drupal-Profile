<?php
/**
 * @file
 * @author
 */

namespace CAPx\Drupal\Entities;

use CAPx\Drupal\Util\CAPxImporter;

class CFEntity extends \Entity {

  /**
   * Constructor of the class.
   *
   * This constructor takes the top level items in the settings property array
   * and exposes them as properties of the instance. This is just a syntax
   * reducing bit of fun.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);

    // Expose settings for easier get access.
    if (isset($this->settings)) {
      $ar = $this->settings;
      if (!is_array($this->settings)) {
        $ar = unserialize($this->settings);
      }
      foreach ($ar as $key => $value) {
        if (!isset($this->{$key})) {
          $this->{$key} = $value;
        }
      }
    }

  }

  /**
   * Implements defaultLabel().
   * @return string
   *   What to call this thing.
   */
  protected function defaultLabel() {
    return $this->title;
  }

  /**
   * Implements defaultUIR.
   * @return array
   *   Path settings
   */
  protected function defaultUri() {
    return array('path' => 'cfe/' . $this->identifier());
  }

  /**
   * Returns the metadata information that is stored in the DB.
   * @return array
   *   An array of arbitrary information
   */
  public function getMeta() {
    return $this->meta;
  }

  /**
   * Sets the metadata array.
   *
   * @param array $meta
   *   Set or create the default metadata.
   */
  public function setMeta($meta = null) {

    // Populate some defaults if empty.
    if (empty($meta)) {
      $meta = array(
        'lastUpdate' => 0,
        'lastUpdateHuman' => t('Never'),
        'count' => 0,
      );
    }

    // Set the stuff.
    $this->meta = $meta;
  }

  /**
   * Returns the machine name of this entity.
   *
   * @todo Should be removed - duplicating parent::identifier().
   * Impossible to do it right now because many our classes have such method
   * and we have poor documentation on method calls and returned values.
   *
   * @return string
   *   The machine name
   */
  public function getMachineName() {
    return $this->machine_name;
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
