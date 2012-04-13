<?php

/*
 * Implementation of hook_install_tasks().
 */

function stanford_profile_install_tasks($install_state) {
  $tasks['disable_update'] = array(
    'display_name' => st('Disable the Update Manager module'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_REACHED,
    'function' => 'stanford_sites_disable_update',
  );

  return $tasks;
}

function stanford_sites_disable_update() {
  // Disable the Update manager module because we'll be pushing updates centrally
  module_disable(array('update'));
}

