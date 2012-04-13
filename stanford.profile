<?php

/*
 * Implementation of hook_install_tasks().
 */

function stanford_install_tasks($install_state) {
  $tasks['stanford_sites_tasks'] = array(
    'display_name' => st('Do configuration tasks for the Stanford Sites hosting environment'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  return $tasks;
}

function stanford_sites_tasks() {
    // Do stuff that's only needed on the Stanford Sites platform
//  if (stanford_sites_hosted()) {
    
    
    /**
     * Tasks for all sites on the service
     */
    module_disable(array('update'));
    module_enable(array('stanford_sites_systemtools'));
    stanford_adjust_authuser_rid();
    
    /**
     * Tasks that require more fine-grained logic.
     */
    $enable_webauth = variable_get('stanford_sites_enable_webauth');
    if ($enable_webauth == 1) {
      $modules = array('webauth');
      module_enable($modules);
    }
    
    /**
     * Set temp file directory.
     */
    $tmpdir = variable_get('stanford_sites_tmpdir');
    variable_set('file_temporary_path', $tmpdir);

   
    /**
     *  Departments' preferred theme is Stanford Modern.
     *  Groups and individuals' preferred theme is Stanford Basic.
     * Official groups can have the Stanford Modern theme enabled by ITS
     */
    $org_type = variable_get('stanford_sites_org_type');
    if ($org_type == 'dept') {
      $preferred_themes = array(
        'theme_default' => 'stanfordmodern',
        'admin_theme' => 'seven',
        'node_admin_theme' => 'seven',
        'bartik'
      );
      theme_enable($preferred_themes);
      foreach ($preferred_themes as $var => $theme) {
        if (!is_numeric($var)) {
          variable_set($var, $theme);
        }
      }
    } else {
      $preferred_themes = array(
        'theme_default' => 'stanford_basic',
        'admin_theme' => 'seven',
        'node_admin_theme' => 'seven',
        'bartik'
      );
      theme_enable($preferred_themes);
      foreach ($preferred_themes as $var => $theme) {
        if (!is_numeric($var)) {
          variable_set($var, $theme);
        }
      }
    }
  //}

}

/*
 * Change the default rid for the authenticated user role. Drupal expects it
 * to be 2, and while you can change the setting in a file, bad modules
 * apparently don't respect that setting.
 */
function stanford_adjust_authuser_rid() {
  $result = db_query("UPDATE role SET rid='1' WHERE name='anonymous user'");
  $result = db_query("UPDATE role SET rid='2' WHERE name='authenticated user'");
}

/**
 * Checks to see if the current Drupal install is on one of the Stanford Sites 
 * hosting servers.
 * 
 * @return
 *   TRUE if it is; FALSE if it isn't.
 */
function stanford_sites_hosted() {
  $server = $_SERVER["SERVER_NAME"];
  if ($server == "") {
    $server = $SERVER["HOST"];
  } 
  if (preg_match('/^(sites|publish).*\.stanford\.edu/', $server, $matches) > 0) {
    return TRUE;
  }
  else{
    return FALSE;
  }
}

