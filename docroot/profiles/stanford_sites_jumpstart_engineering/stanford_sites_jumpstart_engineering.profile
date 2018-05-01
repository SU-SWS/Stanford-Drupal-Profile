<?php
/**
 * @file
 */

// Need this because of the early part of the install process.
if (!function_exists('itasks_install_finished')) {
  require_once dirname(__FILE__) . "/includes/iTasks.php";
}

/**
 * Implements hook_install_tasks().
 *
 * Call through to itasks_install module.
 */
function stanford_sites_jumpstart_engineering_install_tasks(&$install_state) {
  return itasks_install_tasks($install_state);
}

/**
 * Implements hook_install_tasks_alter().
 * @param array $tasks an array of installation tasks
 * @param array $install_state the current installation state
 *
 * Allow each installation task a chance to alter the task array. Also, take
 * over the original verify_requirements function so that we can add additional
 * dependencies to the veryify check before executing it.
 */
function stanford_sites_jumpstart_engineering_install_tasks_alter(&$tasks, &$install_state) {
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
function stanford_sites_jumpstart_engineering_install_verify_requirements(&$install_state) {
  itasks_install_verify_requirements($install_state);
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 * Allows all dependents to alter the configuration form.
 * @param  [array] $form       [the form array]
 * @param  [array] $form_state [the form state array]
 *
 * Allows the profile to alter the site configuration form.
 */
function stanford_sites_jumpstart_engineering_form_install_configure_form_alter(&$form, &$form_state) {
  itasks_form_install_configure_form_alter($form, $form_state);
  $form["#validate"][] = "stanford_sites_jumpstart_engineering_form_install_configure_form_alter_validate";
  $form["#submit"][] = "stanford_sites_jumpstart_engineering_form_install_configure_form_alter_submit";
}

/**
 * @param $form
 * @param $form_state
 */
function stanford_sites_jumpstart_engineering_form_install_configure_form_alter_validate(&$form, &$form_state) {
  itasks_form_install_configure_form_alter_validate($form, $form_state);
}

/**
 * @param $form
 * @param $form_state
 */
function stanford_sites_jumpstart_engineering_form_install_configure_form_alter_submit(&$form, &$form_state) {
  itasks_form_install_configure_form_alter_submit($form, $form_state);
}
