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
 */
function itasks_install_tasks(&$install_state) {
  itasks_include_includes();
  $profile_name = $install_state['parameters']['profile'];
  $info_file = drupal_get_path('profile', $profile_name) . "/" . $profile_name . ".info";
  $install_state['profile_info'] = drupal_parse_info_file($info_file);
  $engine = new TaskEngine($install_state['profile_info']);

}

/**
 * Implements hook_install_tasks_alter().
 */
function itasks_install_tasks_alter(&$tasks, &$install_state) {

}

/**
 * Implements hook_install_profile_modules().
 */
function itasks_install_profile_modules(&$install_state) {

}

/**
 * Implements hook_verify_requirements().
 */
function itasks_verify_requirements(&$install_state) {

}
