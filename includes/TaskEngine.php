<?php
/**
 * @file
 * A shared, namespaced, and other stuff things and stuff.
 */
/**
 *
 */
class TaskEngine {

  // Install state.
  protected $installState;

  // Stores tasks.
  protected $tasks = array();

  // Tasks path.
  protected $taskDir = "sites/all/tasks";

  // Conditional tasks.
  protected $extraTasks = "none";

  // Constructor
  // ---------------------------------------------------------------------------

  /**
   * Profile information.
   *
   * @param [type] $info
   *   [description]
   */
  public function __construct($info, &$install_state) {

    $this->installState = &$install_state;

    // Set the path to the include folder if provided.
    if (isset($info['taskdir'])) {
      $this->setTaskDir($info['taskdir']);
    }

    // Define where to look for the task classes.
    $include = $this->getTaskDirAbsolute();
    $autoloader = $include . "autoloader.php";

    // Include the PHP autoloader.
    if (is_file($autoloader)) {
      require_once $autoloader;
    }

    // Loop through each of the tasks and load it up.
    if (isset($info['task'])) {
      foreach ($info['task'] as $key => $tasks) {
        foreach ($tasks as $index => $task) {

          // For the straight up install/upgrade tasks.
          if (!is_array($task)) {
            $className = "\\" . $task;
            $taskObject = new $className();
            $this->addTask($key, $taskObject);
          }

          // For the task groups. e.g: sites, anchorage, local...
          // Check for the classname in this one because we might not have all
          // of the tasks available.
          if (is_array($task)) {
            foreach ($task as $subIndex => $subTask) {
              $className = "\\" . $subTask;
              if (class_exists($className)) {
                $taskObject = new $className();
                $this->addTask($key, $taskObject);
              }
              // @todo: How to log if something is missing?
            }
          }

        }
      }
    }

    // Allow for an extra group of installation tasks.
    $extras = "none";
    if (isset($install_state["forms"]["install_configure_form"]["itasks_extra_tasks"])) {
      $extras = $install_state["forms"]["install_configure_form"]["itasks_extra_tasks"];
      $this->setExtraTasksName($extras);
    }

  }

  // Methods
  // ---------------------------------------------------------------------------

  /**
   * Adds a task to the task array.
   *
   * @param [type] $type
   *   [description]
   * @param [type] $task
   *   [description]
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
    $extras = $this->getTasks($this->getExtraTasksName());

    // Patch in the extra group.
    if (is_array($extras)) {
      $tasks = $tasks + $extras;
    }

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

  /**
   * [setExtraTasksName description]
   * @param [type] $val [description]
   */
  protected function setExtraTasksName($val) {
    $this->extraTasks = $val;
  }

  /**
   * [getExtraTasksName description]
   * @return [type] [description]
   */
  public function getExtraTasksName() {
    return $this->extraTasks;
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
    $parts = array();
    // Array to build a new path from the good parts.
    $path = str_replace('\\', '/', $path);
    // Replace backslashes with forwardslashes.
    $path = preg_replace('/\/+/', '/', $path);
    // Combine multiple slashes into a single slash.
    $segments = explode('/', $path);
    // Collect path segments.
    $test = '';
    // Initialize testing variable.
    foreach ($segments as $segment) {
      if ($segment != '.') {
        $test = array_pop($parts);
        if (is_null($test)) {
          $parts[] = $segment;
        }
        elseif ($segment == '..') {

          if ($test == '..') {
            $parts[] = $test;
          }

          if ($test == '..' || $test == '') {
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

  // FORMS AND UI
  // ---------------------------------------------------------------------------

  /**
   * [getTaskOptionsForm description].
   *
   * @return [type] [description]
   */
  public function getTaskOptionsForm($form = array(), &$form_state) {
    $tasks = $this->getTasks('install');

    $form['itasks'] = array(
      "#type" => "fieldset",
      "#title" => t("Task Options"),
      "#description" => t("Choose which tasks you would like enabled."),
      "#collapsible" => TRUE,
      "#collapsed" => FALSE,
      "#tree" => TRUE,
    );

    $options = array();
    foreach ($tasks as $machine => $task) {
      $options[$machine] = $task->getDescription();
    }

    $form['itasks']['tasks'] = array(
      "#type" => "checkboxes",
      "#options" => $options,
      "#title" => t("Installation tasks"),
      "#description" => t("Check off all the installation tasks you would like to perform"),
      "#default_value" => isset($form_state['values']['itasks']['tasks']) ? $form_state['values']['itasks']['tasks'] : array(),
    );

    return $form;
  }

}
