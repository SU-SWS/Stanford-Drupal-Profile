<?php
/**
 * @file
 * Enables modules and site configuration for a minimal site installation.
 */

/**
 * Include the files necessary to do the install tasks.
 */
function itasks_include_includes() {
  include_once dirname(__FILE__) . "/includes/TaskInterface.php";
  include_once dirname(__FILE__) . "/includes/AbstractTask.php";
  include_once dirname(__FILE__) . "/includes/AbstractInstallTask.php";
  include_once dirname(__FILE__) . "/includes/TaskEngine.php";
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function itasks_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}


/**
 * Implements hook_install_tasks().
 *
 * Load up all the installation tasks defined in the .info file of this profile
 * and add them to the task array.
 */
function itasks_install_tasks(&$install_state) {
  itasks_include_includes();
  $profile_name = $install_state['parameters']['profile'];
  $info_file = drupal_get_path('profile', $profile_name) . "/" . $profile_name . ".info";
  $install_state['profile_info'] = drupal_parse_info_file($info_file);
  $engine = new TaskEngine($install_state['profile_info'], $install_state);
  return $engine->getInstallTaskArray();
}

/**
 * Implements hook_install_tasks_alter().
 *
 * Allow each installation task a chance to alter the task array. Also, take
 * over the original verify_requirements function so that we can add additional
 * dependencies to the veryify check before executing it.
 */
function itasks_install_tasks_alter(&$tasks, &$install_state) {
  itasks_include_includes();
  $engine = new TaskEngine($install_state['profile_info'], $install_state);
  $iTasks = $engine->getTasks("install");

  // Allow each tasks to alter the tasks array.
  if (is_array($iTasks)) {
    foreach ($iTasks as $task) {
      $task->installTaskAlter($tasks);
    }
  }

  // Take over the verify function so that we can add the tasks dependencies
  // before executing it.
  $tasks["install_verify_requirements"]["function"] = "itasks_install_verify_requirements";
}

/**
 * Override original verify function to add in task dependencies.
 *
 * Override the install_verify_requirements function to allow us to add in
 * dependencies from the the installation tasks before executing the check.
 *
 * @param $install_state
 */
function itasks_install_verify_requirements(&$install_state) {
  itasks_include_includes();
  $engine = new TaskEngine($install_state['profile_info'], $install_state);
  $iTasks = $engine->getTasks("install");
  foreach ($iTasks as $task) {
    $dependencies = $task->requirements();
    $install_state['profile_info']['dependencies'] = array_merge($install_state['profile_info']['dependencies'], $dependencies);
  }

  // Remove the duplicates and run the original install_verify_requirements.
  $install_state['profile_info']['dependencies'] = array_unique($install_state['profile_info']['dependencies']);
  install_verify_requirements($install_state);
}


/**
 * Implements hook_install_profile_modules().
 */
function itasks_install_profile_modules(&$install_state) {

}

/**
 * The task execution function.
 *
 * Drupal needs a function name that it can call for each task and this is it.
 * The name of the task is provided in the install_state array so load it up
 * and execute it.
 *
 * @param $install_state
 */
function itask_run_install_task(&$install_state) {
  itasks_include_includes();
  $engine = new TaskEngine($install_state['profile_info'], $install_state);
  $tasks = $engine->getTasks("install");

  if (function_exists('drush_log')) {
    $time = microtime(TRUE);
    drush_log("Executing: " . $install_state['active_task'], 'ok');
  }

  // Call the bloody thing.
  $tasks[$install_state['active_task']]->execute();

  if (function_exists("drush_log")) {
    $now = microtime(TRUE);
    $diff = round($now - $time, 3);
    drush_log("Finished executing in: " . $diff . " seconds", "ok");
  }

}
