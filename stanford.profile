<?php

/*
 * Implementation of hook_install_tasks().
 */

function stanford_profile_install_tasks($install_state) {
  $tasks = array();
  return $tasks;
}

/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function stanford_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
    unset($form['server_settings']['update_status_module']);
  }
}
