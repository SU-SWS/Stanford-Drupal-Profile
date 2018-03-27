<?php
/**
 * @file
 * stanford_jumpstart_vpsa_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function stanford_jumpstart_vpsa_roles_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 6,
  );

  // Exported role: site owner.
  $roles['site owner'] = array(
    'name' => 'site owner',
    'weight' => 7,
  );

  // Exported role: student assistant.
  $roles['student assistant'] = array(
    'name' => 'student assistant',
    'weight' => 8,
  );

  return $roles;
}
