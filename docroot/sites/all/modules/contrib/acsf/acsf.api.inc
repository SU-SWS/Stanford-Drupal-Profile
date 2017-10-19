<?php

/**
 * @file
 * Documents hooks provided by the ACSF module.
 */

/**
 * Modifies the preserved list of user roles for staged sites.
 *
 * Use this hook to protect user accounts with specific role assignments from
 * being scrubbed when you copy production websites to the staging environment.
 * Scrubbed user accounts are assigned anonymous email addresses and have their
 * passwords reset to randomized strings.
 *
 * @param array $admin_roles
 *   An indexed array of integer role IDs - Users with these roles will be
 *   preserved.
 */
function hook_acsf_staging_scrub_admin_roles_alter(array &$admin_roles) {
  if ($role = variable_get('my_module_admin_role')) {
    $admin_roles[] = $role;
  }
}

/**
 * Modifies the preserved list of user IDs for staged sites.
 *
 * Use this hook to protect specific user accounts from being scrubbed when you
 * copy production websites to the staging environment. Scrubbed user accounts
 * are assigned anonymous email addresses and have their passwords reset to
 * randomized strings.
 *
 * @param array $preserved_uids
 *   An indexed array of integer user IDs to preserve.
 */
function hook_acsf_staging_scrub_preserved_users_alter(array &$preserved_uids) {
  if ($uids = variable_get('my_module_preserved_uids', array())) {
    $preserved_uids = array_merge($preserved_uids, $uids);
  }
}
