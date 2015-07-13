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
   * Verify task is at execute state.
   *
   * @return bool
   *   True if criteria has passed. False if not.
   */
  public function verify();

  /**
   * Provide additional requirements.
   *
   * @return array
   *   An array of requirements.
   */
  public function requirements();

  /**
   * Allow for tasks to alter other tasks prior to execution.
   */
  public function installTaskAlter(&$tasks);



}
