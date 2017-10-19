<?php

/**
 * @file
 * Page callbacks for the workbench_access module.
 */

/**
 * Autocomplete callback for adding users to a section.
 *
 * We don't use user_autocomplete so we can filter out users already
 * assigned to the section.
 *
 * @param $access_type
 *  The access type to check.
 * @param $access_id
 *  The access id to check.
 * @param $string
 *  The search string, which is a partial match of a user name.
 * @param $test_mode
 *  Indicates we are running a SimpleTest and should not return JSON.
 *
 * @return
 *  A JSON object of matching requests. If in test mode, returns an array.
 */
function workbench_access_autocomplete($access_type, $access_id, $string, $test_mode = FALSE) {
  $cache = &drupal_static(__FUNCTION__, array());

  // Build static caches for the roles that can be assigned access.
  if (!isset($cache['rids'])) {
    $cache['rids'] = workbench_access_get_roles('access workbench access by role');
  }

  $string = trim($string);
  $matches = array();

  if (!empty($string) && !empty($cache['rids'])) {
    // Build the query to remove users already assigend to this section and ID.
    $sub_query = db_select('workbench_access_user', 'wau');
    $sub_query->addField('wau', 'uid');
    $sub_query->condition('access_scheme', $access_type);
    $sub_query->condition('access_id', $access_id);

    $query = db_select('users', 'u');
    $query->addField('u', 'uid');
    $query->condition('u.name', db_like($string) . '%', 'LIKE');
    $query->condition('u.uid', $sub_query, 'NOT IN');
    $query->range(0, 20);
    $query->addTag('user_autocomplete');

    // If all authorized users are not allowed, JOIN to user_roles.
    if (!isset($cache['rids'][DRUPAL_AUTHENTICATED_RID])) {
      $query->join('users_roles', 'ur', 'u.uid = ur.uid');
      $query->condition('ur.rid', array_keys($cache['rids']), 'IN');
    }

    $uids = $query->execute()->fetchCol();
    $accounts = user_load_multiple($uids);
    foreach ($accounts as $account) {
      $matches[$account->name] = check_plain(format_username($account));
    }
  }

  // Yes, this will make Crell cry, but tests are tests.
  if ($test_mode) {
    return $matches;
  }

  drupal_json_output($matches);
}
