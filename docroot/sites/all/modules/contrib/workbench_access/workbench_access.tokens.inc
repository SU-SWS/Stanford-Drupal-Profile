<?php

/**
 * @file
 * Token integration for the workbench_access module.
 */

/**
 * Implements hook_token_info().
 */
function workbench_access_token_info() {
  // Node tokens.
  $info['tokens']['node']['workbench-access-sections'] = array(
    'name' => t('Workbench access sections'),
    'description' => t('Section assignments for the node.'),
    'type' => 'array',
  );

  // User tokens.
  $info['tokens']['user']['workbench-access-sections'] = array(
    'name' => t('Workbench access sections'),
    'description' => t('Section assignments for the user account.'),
    'type' => 'array',
  );

  // Site global tokens.
  $info['tokens']['site']['workbench-access-scheme'] = array(
    'name' => t('Workbench access scheme'),
    'description' => t('The active access scheme used on the site.'),
    'type' => 'workbench-access-scheme',
  );

  // Workbench access scheme tokens.
  $info['types']['workbench-access-scheme'] = array(
    'name' => t('Workbench access scheme'),
    'description' => t('Tokens related to workbench access schemes.'),
    'needs-data' => 'workbench-access-scheme',
  );
  $info['tokens']['workbench-access-scheme']['name'] = array(
    'name' => t('Name'),
    'description' => t('The name of the access scheme.'),
  );
  $info['tokens']['workbench-access-scheme']['machine-name'] = array(
    'name' => t('Machine name'),
    'description' => t('The unique machine-readable name of the access scheme.'),
  );
  $info['tokens']['workbench-access-scheme']['description'] = array(
    'name' => t('Description'),
    'description' => t('A human-readable description of the access control scheme.'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function workbench_access_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  // Node tokens.
  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'workbench-access-sections':
          if ($sections = _workbench_access_get_node_section_names($node)) {
            if ($sanitize) {
              // Run sections through check_plain() if they should be sanitized.
              $sections = array_map('check_plain', $sections);
            }
            $join = isset($options['join']) ? $options['join'] : ', ';
            $replacements[$original] = implode($join, $sections);
          }
          elseif (variable_get('workbench_access_node_type_' . $node->type, 1)) {
            // Output the default unassigned token if the content type is access
            // controlled.
            $replacements[$original] = t('Unassigned');
          }
          break;
      }
    }

    // Chained token relationships.
    if ($section_tokens = token_find_with_prefix($tokens, 'workbench-access-sections')) {
      if ($sections = _workbench_access_get_node_section_names($node)) {
        $replacements += token_generate('array', $section_tokens, array('array' => $sections), $options);
      }
    }
  }

  // User tokens.
  if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'workbench-access-sections':
          if ($sections = _workbench_access_get_user_section_names($account)) {
            if ($sanitize) {
              // Run sections through check_plain() if they should be sanitized.
              $sections = array_map('check_plain', $sections);
            }
            $join = isset($options['join']) ? $options['join'] : ', ';
            $replacements[$original] = implode($join, $sections);
          }
          break;
      }
    }

    // Chained token relationships.
    if ($section_tokens = token_find_with_prefix($tokens, 'workbench-access-sections')) {
      if ($sections = _workbench_access_get_user_section_names($account)) {
        $replacements += token_generate('array', $section_tokens, array('array' => $sections), $options);
      }
    }
  }

  // Site global tokens.
  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'workbench-access-scheme':
          if ($scheme = workbench_access_access_scheme_load(variable_get('workbench_access'))) {
            $replacements[$original] = $sanitize ? check_plain($scheme['name']) : $scheme['name'];
          }
          break;
      }
    }

    // Chained token relationships.
    if ($scheme_tokens = token_find_with_prefix($tokens, 'workbench-access-scheme')) {
      if ($scheme = workbench_access_access_scheme_load(variable_get('workbench_access'))) {
        $replacements += token_generate('workbench-access-scheme', $scheme_tokens, array('workbench-access-scheme' => $scheme), $options);
      }
    }
  }

  // Workbench access scheme tokens.
  if ($type == 'workbench-access-scheme' && !empty($data['workbench-access-scheme'])) {
    $scheme = $data['workbench-access-scheme'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'name':
          $replacements[$original] = $sanitize ? check_plain($scheme['name']) : $scheme['name'];
          break;

        case 'machine-name':
          // Machine names are assumed to not contain unsafe characters.
          $replacements[$original] = $scheme['access_scheme'];
          break;

        case 'description':
          $replacements[$original] = $sanitize ? check_plain($scheme['description']) : $scheme['description'];
          break;
      }
    }
  }

  return $replacements;
}


/**
 * Fetch an array of a node's access sections for use with tokens.
 *
 * @return array
 *   An array of access section names keyed by access ID.
 */
function _workbench_access_get_node_section_names($node) {
  $sections = &drupal_static(__FUNCTION__, array());

  if (!isset($sections[$node->nid])) {
    $sections[$node->nid] = array();

    if (!empty($node->workbench_access)) {
      $access_type = variable_get('workbench_access');
      foreach ($node->workbench_access as $access_id) {
        $info = workbench_access_load($access_type, $access_id);
        $sections[$node->nid][$access_id] = $info['name'];
      }
    }

  }

  return $sections[$node->nid];
}

/**
 * Fetch an array of a user's access sections for use with tokens.
 *
 * @return array
 *   An array of access section names keyed by access ID.
 */
function _workbench_access_get_user_section_names($account) {
  $sections = &drupal_static(__FUNCTION__, array());

  if (!isset($sections[$account->uid])) {
    $sections[$account->uid] = array();

    if (!empty($account->workbench_access)) {
      $access_type = variable_get('workbench_access');
      foreach (array_keys($account->workbench_access) as $access_id) {
        $info = workbench_access_load($access_type, $access_id);
        $sections[$account->uid][$access_id] = $info['name'];
      }
    }
  }

  return $sections[$account->uid];
}
