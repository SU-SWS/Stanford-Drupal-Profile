<?php
/**
 * @file
 *
 * A shared, namespaced, and other stuff things and stuff.
 */

class TaskEngine {

  // Stores tasks.
  protected $tasks = array();

  // Constructor
  // ---------------------------------------------------------------------------

  /**
   * Profile information.
   * @param [type] $info [description]
   */
  public function __construct($info) {
    $whats = "this";
  }

  // Methods
  // ---------------------------------------------------------------------------

  /**
   * Adds a task to the task array.
   * @param [type] $type [description]
   * @param [type] $task [description]
   */
  public function addTask($type, $task) {
    $this->tasks[$type][] = $task;
  }

  /**
   * Returns an array of tasks.
   *
   * @return mixed
   *   An array of tasks or FALSE if none.
   */
  public function getTasks($type = NULL) {

    // If nothing passed pass all back.
    if (is_null($type)) {
      return $this->tasks;
    }

    // If the task type is not set or there are no tasks return false.
    if (!isset($this->tasks[$type]) || empty($this->tasks)) {
      return FALSE;
    }

    // Return the slice.
    return $this->tasks[$type];
  }

}
