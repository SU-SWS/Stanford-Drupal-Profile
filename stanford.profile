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
  // Pull in config file
  include_once('config.inc');
  
  // Define our fields
  $fields = get_stanford_installer();

  if ($form_id == 'install_configure') {
    // General form settings.
    $form['intro']['#value'] = st('Please fill out the following values:');
    $form['site_information']['#collapsible'] = TRUE;
    $form['admin_account']['#value'] = '';
    $form['admin_account']['markup']['#value'] = '';
    $form['admin_account']['#title'] = 'Administrator Account';

    // Site settings.
    $form['site_information']['site_name']['#default_value'] = $fields['site_name'];
    $form['site_information']['site_mail']['#default_value'] = $fields['site_mail'];
    $form['site_information']['site_mail']['#type'] = 'hidden';

    // Admin account settings.
    $form['admin_account']['account']['mail']['#default_value'] = $fields['site_mail'];
    $form['admin_account']['account']['name']['#default_value'] = 'admin';
    $form['admin_account']['account']['mail']['#type'] = 'hidden';
    $form['admin_account']['account']['name']['#type'] = 'hidden';

    // Hide the fieldset since it'll be empty anyway
    $form['server_settings']['#type'] = 'markup';

    // Server settings.
    $form['server_settings']['clean_url']['#type'] = 'hidden';
    $form['server_settings']['clean_url']['#default_value'] = 1;
    $form['server_settings']['date_default_timezone']['#type'] = 'hidden';
    $form['server_settings']['date_default_timezone']['#default_value'] = -25200;

    // Hide the automatic updates block.
    unset($form['server_settings']['update_status_module']);
  }
}
