<?php

/**
 * @file
 * Drush commands for Workbench Access.
 */

/**
 * Implements hook_drush_command().
 */
function workbench_access_drush_command() {
  $items = array();

  $items['workbench-access-test'] = array(
    'description' => 'Install test configuration of Workbench Access.',
    'aliases' => array('wa-test'),
  );

  return $items;
}

/**
 * Implement hook_drush_help().
 */
function workbench_access_drush_help($section) {
  $items = workbench_access_drush_command();
  $name = str_replace('workbench access:', '', $section);
  if (isset($items[$name])) {
    return dt($items[$name]['description']);
  }
}

/**
 * Installs the test configuration.
 */
function drush_workbench_access_test() {
  module_load_include('inc', 'workbench_access', 'workbench_access.admin');
  module_enable(array('taxonomy'));
  workbench_access_example_taxonomy();
}
