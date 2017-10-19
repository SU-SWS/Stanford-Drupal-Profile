<?php
/**
 * @file
 * stanford_jumpstart_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function stanford_jumpstart_roles_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '6',
  );

  // Exported role: site owner.
  $roles['site owner'] = array(
    'name' => 'site owner',
    'weight' => '7',
  );

  return $roles;
}
