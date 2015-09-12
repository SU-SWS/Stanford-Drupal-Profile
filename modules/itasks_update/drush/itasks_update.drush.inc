<?php
/**
 * @file
 *
 */

/**
 * Implements hook_drush_command().
 */
function itasks_update_drush_command() {
  $items = array();
  $items['itasks-updb'] = array(
    'aliases' => array('ipdb'),
    'callback' => 'itasks_update_update_database',
    'description' => 'Run the update tasks as defined by the itasks profile.',
    'examples' => array(
      'drush ipdb' => 'Check and run all itasks update tasks.',
    ),
  );
  return $items;
}
/**
 * Implementation of hook_drush_help().
 */
function itasks_update_drush_help($section) {
  switch ($section) {
    case 'meta:itasks_update:title':
      return dt('iTasks commands');
    case 'meta:itasks_update:summary':
      return dt('iTasks Drush commands.');
  }
}
/**
 * A custom 'drush up' like command.
 * @return [type] [description]
 */
function itasks_update_update_database() {
  $version = drush_core_version();
  if ($version < 6) {
    drush_log("Your drush version is too old. Please update to version 6.", "error");
    drush_user_abort();
    return;
  }

  // Need this for later:
  require_once DRUPAL_ROOT . "/includes/install.inc";

  // Get the install profile name.
  $profile = variable_get("install_profile", "itasks");

  // Parse the info file for updates.
  $info = drupal_parse_info_file(drupal_get_path("profile", $profile) . "/" . $profile . ".info");
  $update_tasks = isset($info['task']['update']) ? $info['task']['update'] : FALSE;
  $taskdir = $info["taskdir"];

  // If the task directory is not available or is not a directory at all then
  // we must stop our adventure here as we won't be able to continue.
  if(empty($taskdir) || !is_dir(DRUPAL_ROOT . "/" . $taskdir)) {
    drush_log("Update task directory not defined. Please add taskdir to " . $profile . ".info", "error");
    return;
  }

  // Get the autoloader file.
  require_once DRUPAL_ROOT . "/" . $taskdir . "/autoloader.php";

  // If no update tasks defined then present a message and go home for the day.
  if (!$update_tasks) {
    drush_log("No update tasks defined in " . $profile, 'warning');
    return;
  }

  // Trim out the fat. Ie: the schema tasks that have already been run.
  $current_version = drupal_get_installed_schema_version($profile);

  // The versions available
  $not_yet_run = array_slice($update_tasks, $current_version);

  if (is_empty($not_yet_run)) {
    drush_log("No updates available for " . $profile . ". Schema version: " . $current_version);
  }




  echo "Please complete this function";
}