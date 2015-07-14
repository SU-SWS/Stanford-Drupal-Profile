<?php
/**
 * @file
 * Abstract Task Class
 */

abstract class AbstractTask implements TaskInterface {

  // Variables
  // ---------------------------------------------------------------------------

  var $complete;

  // Constructor
  // ---------------------------------------------------------------------------

  public function __construct() {

  }

  // Methods
  // ---------------------------------------------------------------------------

  /**
   * Throw an exception as the child class must define this.
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

}
