<?php
/**
 * @file
 * stanford_minimal_filter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_minimal_filter_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format minimal_html'.
  $permissions['use text format minimal_html'] = array(
    'name' => 'use text format minimal_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
