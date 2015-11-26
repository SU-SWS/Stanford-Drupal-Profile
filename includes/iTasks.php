<?php
/**
 * @file
 * Enables modules and site configuration for a minimal site installation.
 */

/**
 * Include the files necessary to do the install tasks.
 */
function itasks_includes() {
  require_once dirname(__FILE__) . "/InstallTaskInterface.php";
  require_once dirname(__FILE__) . "/AbstractTask.php";
  require_once dirname(__FILE__) . "/AbstractInstallTask.php";
  require_once dirname(__FILE__) . "/TaskEngine.php";
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function itasks_form_install_configure_form_alter(&$form, $form_state) {

  itasks_includes();

  $engine = new TaskEngine($form_state['build_info']['args'][0]['profile_info'], $form_state['build_info']['args'][0]);

  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form = $engine->getTaskOptionsForm($form, $form_state);

  $form["#validate"][] = "itasks_install_form_install_configure_form_alter_validate";
  $form["#submit"][] = "itasks_install_form_install_configure_form_alter_submit";

}

/**
 * [itasks_install_form_install_configure_form_alter_validate description]
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function itasks_form_install_configure_form_alter_validate($form, &$form_state) {
  if (empty($form_state['values']['itasks']['tasks'])) {
    return;
  }
  // Do something here.....
}

/**
 * [itasks_install_form_install_configure_form_alter_submit description]
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function itasks_form_install_configure_form_alter_submit($form, &$form_state) {
  if (empty($form_state['values']['itasks']['tasks'])) {
    return;
  }
  $form_state['build_info']['args'][0]['install_task_list'] = $form_state['values']['itasks']['tasks'];
}

/**
 * Implements hook_install_tasks().
 *
 * Load up all the installation tasks defined in the .info file of this profile
 * and add them to the task array.
 */
function itasks_install_tasks(&$install_state) {
  itasks_includes();
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
  itasks_includes();
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
  itasks_includes();
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
 * The task execution function.
 *
 * Drupal needs a function name that it can call for each task and this is it.
 * The name of the task is provided in the install_state array so load it up
 * and execute it.
 *
 * @param $install_state
 */
function itask_run_install_task(&$install_state) {
  itasks_includes();
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

/**
 * Implements hook_install_finished.
 */
function itasks_install_finished() {
  // Kill all static vars.
  drupal_static_reset();

  // If features are around lets rebuild them to be sure they
  // are as they should be.
  if (module_exists("features")) {
    features_rebuild();
    features_revert();
  }

  // Flush all caches.
  drupal_flush_all_caches();
}

