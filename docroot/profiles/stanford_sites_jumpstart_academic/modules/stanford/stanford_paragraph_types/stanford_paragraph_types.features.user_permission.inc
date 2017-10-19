<?php
/**
 * @file
 * stanford_paragraph_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_paragraph_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'show format selection for paragraphs_item'.
  $permissions['show format selection for paragraphs_item'] = array(
    'name' => 'show format selection for paragraphs_item',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  return $permissions;
}
