<?php
/**
 * @file
 * @author Shea McKinney <sheamck@stanford.edu>
 *
 */

require_once "includes/autoloader.php";

// Looks like we are missing some things before boot. Include them here.
//include_once DRUPAL_ROOT . "/includes/stream_wrappers.inc";

/**
 * Implements hook_install_tasks().
 */
function stanford_sites_jumpstart_plus_install_tasks(&$install_state) {
  $tasks = array();
  $profile = new JumpstartSitesPlus();
  $tasks = $profile->get_install_tasks($install_state);
  return $tasks;
}

/**
 * Implements hook_install_tasks_alter().
 * @param array $tasks an array of installation tasks
 * @param array $install_state the current installation state
 */
function stanford_sites_jumpstart_plus_install_tasks_alter(&$tasks, &$install_state) {
  $profile = new JumpstartSitesPlus();
  $profile->prepare_task_handlers($install_state);
  $profile->install_tasks_alter($tasks, $install_state);
}

/**
 * Implements form_install_configure_form_alter.
 * Allows all dependants to alter the configuration form.
 * @param  [array] $form       [the form array]
 * @param  [array] $form_state [the form state array]
 */
function stanford_sites_jumpstart_plus_form_install_configure_form_alter(&$form, &$form_state) {
  $profile_name = JumpstartProfileAbstract::get_active_profile();
  $profile = new $profile_name();
  $form = $profile->get_config_form($form, $form_state);
  return $form;
}

/**
 * Implements form_install_configure_form_alter_validate.
 * Calls all dependant validate functions on the installation config form.
 * @param  [array] $form       [the form array]
 * @param  [array] $form_state [the form state array]
 */
function stanford_sites_jumpstart_plus_form_install_configure_form_alter_validate($form, &$form_state) {
  $profile_name = JumpstartSites::get_active_profile();
  $profile = new $profile_name();
  $profile->get_config_form_validate($form, $form_state);
}

/**
 * Implements form_install_configure_form_alter_validate
 * Calls all dependant submit functions on the installation form.
 * @param  [array] $form       [the form array]
 * @param  [array] $form_state [the form state array]
 */
function stanford_sites_jumpstart_plus_form_install_configure_form_alter_submit($form, &$form_state) {
  $profile_name = JumpstartSites::get_active_profile();
  $profile = new $profile_name();
  $profile->get_config_form_submit($form, $form_state);
}


