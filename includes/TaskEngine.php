<?php
/**
 * @file
 *
 * A shared, namespaced, and other stuff things and stuff.
 */

class TaskEngine {

  // Install state
  protected $installState;

  // Stores tasks.
  protected $tasks = array();

  // Tasks path.
  protected $taskDir = "sites/all/tasks";


  // Constructor
  // ---------------------------------------------------------------------------

  /**
   * Profile information.
   * @param [type] $info [description]
   */
  public function __construct($info, &$install_state) {

    $this->installState = &$install_state;
    $install_state['test'] = "test";

    // Set the path to the include folder if provided.
    if (isset($info['taskdir'])) {
      $this->setTaskDir($info['taskdir']);
    }

    // Define where to look for the task classes.
    $include = $this->getTaskDirAbsolute();

    // Loop through each of the tasks and load it up.
    if (isset($info['task']['install'])) {
      foreach ($info['task']['install'] as $key => $task) {
        include_once $this->normalizePath($include . $task);
        $className = "\\" . explode(".", $task)[0];
        $taskObject = new $className();
        $this->addTask("install", $taskObject);
      }
    }

  }

  // Methods
  // ---------------------------------------------------------------------------

  /**
   * Adds a task to the task array.
   * @param [type] $type [description]
   * @param [type] $task [description]
   */
  public function addTask($type, $task) {
    $this->tasks[$type][$task->getMachineName()] = $task;
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

  /**
   * @return array
   *   An array of installation tasks.
   */
  public function getInstallTaskArray() {
    $taskArray = array();

    $tasks = $this->getTasks('install');

    foreach ($tasks as $task) {
      $taskArray[$task->getMachineName()] = array(
        'display_name' => $task->getDisplayName(),
        'display' => $task->getInstallDisplay(),
        'run' => $task->getRunType(),
        'type' => $task->getInstallType(),
        'function' => $task->getInstallFunction(),
      );

      $this->installState['itasks']['install'][$task->getMachineName()] = $task;
    }

    return $taskArray;
  }


  // DIRECTORY AND PATHS
  // ---------------------------------------------------------------------------

  /**
   * @param string $path
   */
  public function setTaskDir($path = "sites/all/tasks") {
    $this->taskDir = $path;
  }

  /**
   * @return string
   *   Returns the absolute path to the tasks directory.
   */
  public function getTaskDirAbsolute() {
    return DRUPAL_ROOT . "/" . $this->taskDir . "/";
  }

  /**
   * @param $path
   *
   * @return string
   */
  protected function normalizePath($path) {
    $parts = array();// Array to build a new path from the good parts
    $path = str_replace('\\', '/', $path);// Replace backslashes with forwardslashes
    $path = preg_replace('/\/+/', '/', $path);// Combine multiple slashes into a single slash
    $segments = explode('/', $path);// Collect path segments
    $test = '';// Initialize testing variable
    foreach($segments as $segment) {
      if($segment != '.') {
         $test = array_pop($parts);
         if(is_null($test)) {
           $parts[] = $segment;
         } else if($segment == '..') {

           if($test == '..') {
             $parts[] = $test;
           }

           if($test == '..' || $test == '') {
             $parts[] = $segment;
           }
         }
      else {
        $parts[] = $test;
        $parts[] = $segment;
        }
      }
    }

    return implode('/', $parts);
  }

}
