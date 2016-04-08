<?php
/**
 * @file
 * Enables modules and site configuration for a minimal site installation.
 */

// Need this because of the early part of the install process.
require_once dirname(__FILE__) . "/includes/loader.php";

/**
 * Call through to itasks_install module.
 * @param  [type] &$install_state [description]
 * @return [type]                 [description]
 */
function jumpstart_install_tasks(&$install_state) {
  return itasks_install_tasks($install_state);
}

/**
 * Implements hook_install_tasks_alter().
 *
 * Allow each installation task a chance to alter the task array. Also, take
 * over the original verify_requirements function so that we can add additional
 * dependencies to the veryify check before executing it.
 */
function jumpstart_install_tasks_alter(&$tasks, &$install_state) {
  itasks_install_tasks_alter($tasks, $install_state);
}

/**
 * Override original verify function to add in task dependencies.
 *
 * Override the install_verify_requirements function to allow us to add in
 * dependencies from the the installation tasks before executing the check.
 *
 * @param $install_state
 */
function jumpstart_install_verify_requirements(&$install_state) {
  itasks_install_verify_requirements($install_state);
}


/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function jumpstart_form_install_configure_form_alter(&$form, $form_state) {
  itasks_form_install_configure_form_alter($form, $form_state);
}
