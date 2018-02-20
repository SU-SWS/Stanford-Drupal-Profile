<?php
/**
 * @file
 * Abstract Task Class
 */

namespace ITasks;

/**
 * Abstract class.
 */
abstract class AbstractTask {

  // Variables
  // ---------------------------------------------------------------------------
  protected $machineName;


  // Constructor
  // ---------------------------------------------------------------------------

  public function __construct() {}

  // Methods
  // ---------------------------------------------------------------------------

  /**
   * Throw an exception as the child class must define this.
   *
   * @param array &$args
   *   An array of arguments.
   *
   * @throws Exception
   *   Throws an exception if called as child class must define this method.
   */
  public function execute(&$args = array()) {
    throw new \Exception("No execute method defined!");
  }

  /**
   * Return an array of requirements for install time.
   *
   * @return array
   *   An array of requirements.
   */
  public function requirements() {
    return array();
  }

  /**
   * Verify function on wether this task can be run.
   *
   * @return bool
   *   TRUE for a pass.
   */
  public function verify() {
    return TRUE;
  }

  /**
   * Returns the machine name of the task.
   *
   * @return string
   *   The machine name.
   */
  public function getMachineName() {
    if (!empty($this->machineName)) {
      return $this->machineName;
    }
    return drupal_clean_css_identifier(get_class($this));
  }

  /**
   * Set the machine name to something other than the defualt.
   *
   * @param string $name
   *   A new machine name.
   */
  public function setMachineName($name) {
    $this->machineName == $name;
  }


}
