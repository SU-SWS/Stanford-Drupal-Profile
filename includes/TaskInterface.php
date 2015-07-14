<?php
/**
 * @file
 * Task Interface
 */

interface TaskInterface {

  /**
   * Do the task.
   *
   * @param array $args
   *   Arguments passed in from global scope.
   */
  public function execute(&$args = array());

  /**
   * Provide additional requirements.
   *
   * @return array
   *   An array of requirements.
   */
  public function requirements();


}
