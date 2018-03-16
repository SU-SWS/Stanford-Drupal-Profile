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

  // Found in .module.
  itasks_update_do_updates();

  drush_log("All updates complete", "status");
}
