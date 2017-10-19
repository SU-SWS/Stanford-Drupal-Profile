<?php

/**
 * @file
 * Workbench Access admin file.
 */

/**
 * Settings form for Workbench Access configuration.
 */
function workbench_access_settings_form($form, &$form_state) {
  // Make sure all hook_invocations exist.
  workbench_access_load_include();
  $info = module_invoke_all('workbench_access_info');
  $options = array();
  foreach ($info as $key => $value) {
    $options[$key] = $value['name'] . '<div class="description">' . $value['description'] . '</div>';
  }
  $active = variable_get('workbench_access');
  $form = array();
  $form['help'] = array(
    '#markup' => '<h2>' . t('Workbench Access settings') . '</h2>',
  );
  // Check for proper installation.
  if (module_exists('taxonomy')) {
    $vocabulary = workbench_access_sample_vocabulary();
    $exists = workbench_access_vocabulary_exists($vocabulary);
    if (!$exists && (empty($active) || $active == 'taxonomy')) {
      $form['help']['#markup'] .= '<p>' . t('Install the <a href="!url">test configuration for Workbench</a>.', array('!url' => url('admin/config/workbench/access/install'))) .'</p>';
    }
  }
  $form['workbench_access'] = array(
    '#type' => 'radios',
    '#title' => t('Active access scheme'),
    '#options' => $options,
    '#description' => t('Select the access scheme to use for the site.'),
    '#required' => TRUE,
  );
  if ($active) {
    $form['workbench_access']['#default_value'] = $active;
  }
  // Get the configuration options for the active schemes.
  foreach ($info as $key => $value) {
    if (!isset($info[$key]['configuration'])) {
      $info[$key]['configuration'] = $key . '_workbench_access_configuration';
    }
    if (function_exists($info[$key]['configuration'])) {
      $func = $info[$key]['configuration'];
      $func($form, $form_state);
      if (isset($form[$key . '_workbench_access_info'])) {
        $form[$key . '_workbench_access_info']['#description'] = t('Changing this value in production may <em>disrupt</em> your workflow.');
      }
      foreach (array('validate', 'submit') as $action) {
        if (function_exists($func . '_' . $action)) {
          $form['#' . $action][] = $func . '_' . $action;
        }
      }
    }
  }
  $types = node_type_get_types();
  if (!empty($types)) {
    $form['node_types'] = array(
      '#type' => 'fieldset',
      '#title' => t('Enabled content types'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($types as $type => $data) {
      $form['node_types']['workbench_access_node_type_' . $type] = array(
        '#title' => check_plain($data->name),
        '#type' => 'checkbox',
        '#default_value' => variable_get('workbench_access_node_type_' . $type, 1),
      );
    }
    $form['node_types']['message'] = array(
      '#markup' => t('Only selected content types will have Workbench Access rules <em>enforced</em>.'),
    );
    // Set the field settings for field-based modules, if required.
    if (!variable_get('workbench_access_custom_form', 1) && array_key_exists($active, $info) && empty($info[$active]['form_field'])) {
      $form['field_elements'] = array(
        '#type' => 'fieldset',
        '#title' => t('Access control fields'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#tree' => TRUE,
        '#description' => t('Set the field elements that control access to each content type.'),
      );
      if (!module_exists('field_property')) {
        $form['field_elements']['#collapsed'] = FALSE;
        $form['field_elements']['#description'] = '<strong>' . t('Installing and enabling the <a href="!url">Field Property module</a> is recommended.', array('!url' => 'http://drupal.org/project/field_property')) . '</strong><br />' . $form['field_elements']['#description'];
      }
      foreach ($types as $type => $data) {
        $fields = workbench_access_get_assigned_fields($type);
        $available = workbench_access_get_available_fields($type);
        $name = node_type_get_name($type);
        $controlled = variable_get('workbench_access_node_type_' . $type, 1);
        if (empty($controlled)) {
          $form['field_elements'][$type] = array(
            '#type' => 'item',
            '#title' => t('%type content type access control fields', array('%type' => $name)),
            '#markup' => t('This content type is not under access control.'),
          );
        }
        elseif (empty($available)) {
          $message = t('The %type content type does not have any fields that can be used for access control.', array('%type' => $name));
          drupal_set_message($message, 'warning', FALSE);
          $form['field_elements'][$type] = array(
            '#type' => 'item',
            '#title' => t('%type content type fields', array('%type' => $name)),
            '#markup' => $message,
          );
        }
        else {
          $field_options = array();
          $default_options = array();
          $message = '';
          if (empty($fields)) {
            $message = t('The %type content type does not have an access field configured.', array('%type' => $name));
            drupal_set_message($message, 'warning', FALSE);
            $field_options['wa-no-access-field'] = t('No access control field');
            $default_options[] = 'wa-no-access-field';
          }
          foreach ($available as $field => $info) {
            $field_options[$field] = t('!label (!field)', array('!label' => $info['instance_info']['label'], '!field' => $field));
            if (!empty($info['instance_info']['workbench_access_field'])) {
              $default_options[$field] = $field;
            }
          }
          $form['field_elements'][$type] = array(
            '#type' => 'select',
            '#title' => t('%type content type access control fields', array('%type' => $name)),
            '#options' => $field_options,
            '#default_value' => $default_options,
            '#multiple' => variable_get('workbench_access_allow_multiple', 0),
            '#description' => $message,
          );
        }
      }
    }
  }
  $form['workbench_access_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Workbench Access message label'),
    '#default_value' => variable_get('workbench_access_label', 'Section'),
    '#description' => t('Text that will be shown in front of Workbench Access messages.'),
  );
  $form['workbench_access_auto_assign'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automated section assignment'),
    '#default_value' => variable_get('workbench_access_auto_assign', 1),
    '#description' => t('Enable all sections automatically for the active scheme.'),
  );
  $form['workbench_access_allow_multiple'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow multiple section assignments'),
    '#default_value' => variable_get('workbench_access_allow_multiple', 0),
    '#description' => t('Let content be assigned to multiple sections.'),
  );
  $form['workbench_access_custom_form'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require a Workbench Access form element'),
    '#default_value' => variable_get('workbench_access_custom_form', 1),
    '#description' => t('If not selected, Workbench Access settings will inherit from the standard node form.'),
  );
  $form = system_settings_form($form);
  $form['#validate'][] = 'workbench_access_settings_validate';
  $form['#submit'][] = 'workbench_access_settings_submit';
  return $form;
}

/**
 * Check configuration.
 *
 * If no access schemes are selected, things go boom. Due to the
 * use of JS $states in the form, we can't just make fields required.
 */
function workbench_access_settings_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (empty($values['workbench_access'])) {
    form_set_error('workbench_access', t('You must select an access scheme.'));
  }
  $target = 'workbench_access_' . $values['workbench_access'];
  $error = FALSE;
  if (empty($values[$target])) {
    $error = TRUE;
  }
  else {
    // Can't run an empty() check on array_filter() inside an IF.
    $selections = array_filter($values[$target]);
    if (empty($selections)) {
      $error = TRUE;
    }
  }
  if ($error) {
    form_set_error($target, t('You must enable at least one @type scheme.', array('@type' => $values['workbench_access'])));
  }
}

/**
 * Set configuration.
 */
function workbench_access_settings_submit($form, &$form_state) {
  // Reset the tree.
  workbench_access_reset_tree();
  // If auto-assign, then do so.
  if (empty($form_state['values']['workbench_access_auto_assign'])) {
    return;
  }
  // Get the new tree rules and check for changes.
  $active = workbench_access_get_active_tree();
  foreach ($active['tree'] as $key => $item) {
    $data = array_merge($active['access_scheme'], $item);
    if (!isset($active['active'][$key]) && !empty($form_state['values']['workbench_access_' . $active['access_scheme']['access_scheme']][$item['access_type_id']])) {
      workbench_access_section_save($data);
    }
    elseif (empty($form_state['values']['workbench_access_' . $active['access_scheme']['access_scheme']][$item['access_type_id']])) {
      workbench_access_section_delete($data);
    }
  }
  // Make sure we cleaned out all the old sections.
  $sections = db_query("SELECT * FROM {workbench_access} WHERE access_type = :access_type",
    array(':access_type' => $active['access_scheme']['access_type'])
  )->fetchAll();
  foreach ($sections as $section) {
    if (empty($form_state['values']['workbench_access_' . $active['access_scheme']['access_scheme']][$section->access_type_id])) {
      workbench_access_section_delete((array) $section);
    }
  }
  // If field settings are present, save them.
  if (isset($form_state['values']['field_elements'])) {
    workbench_access_save_field_elements($form_state['values']['field_elements']);
  }
}

/**
 * Save field element settings for native forms.
 *
 * @param $types
 *  An array of field options for each active node type.
 */
function workbench_access_save_field_elements($types) {
  foreach ($types as $type => $settings) {
    if ($settings == 'wa-no-access-field') {
      return;
    }
    // Multiple options return an array. Single a string.
    if (!is_array($settings)) {
      $selection[] = $settings;
    }
    else {
      $selection = $settings;
    }
    $fields = workbench_access_get_available_fields($type);
    foreach ($fields as $field => $info) {
      $instance = $info['instance_info'];
      $instance['workbench_access_field'] = in_array($field, $selection);
      field_update_instance($instance);
    }
  }
}

/**
 * Administer section definitions.
 */
function workbench_access_section_form($form, &$form_state) {
  $active = workbench_access_get_active_tree();
  // Ensure that we have configured access controls.
  if (!$active = workbench_access_get_active_tree()) {
    $form['help']['#markup'] = workbench_access_configuration_needed_message();
    return $form;
  }
  $form = array();
  $form['access_scheme'] = array(
    '#type' => 'value',
    '#value' => $active['access_scheme'],
  );
  $form['access_tree'] = array(
    '#type' => 'value',
    '#value' => $active['tree'],
  );
  $form['help'] = array(
    '#markup' => '<h2>' . t('Active editorial sections') . '</h2><p>' . t('Below is a list of the editorial sections defined for your site.') . '</p>',
  );
  if (variable_get('workbench_access_auto_assign', 1)) {
    $form['help']['#markup'] .= '<p>' . t('All sections are set to be active automatically. <a href="!url">Disable the <em>Automated section assignment</em> option</a> to make changes.', array('!url' => url('admin/config/workbench/access/settings'))) . '</p>';
  }
  $form['sections']['#tree'] = TRUE;
  $active_items = array_keys($active['active']);
  $parent = 0;
  $used = array();
  foreach ($active['tree'] as $section) {
    if (in_array($section['access_id'], $used)) {
      continue;
    }
    if ($section['depth'] == 0) {
      $parent = $section['access_id'];
      $collapsed = TRUE;
      if (isset($active['active'][$parent])) {
        $collapsed = FALSE;
      }
      elseif (!empty($section['children'])) {
        $check = array_intersect($active_items, $section['children']);
        if (!empty($check)) {
          $collapsed = FALSE;
        }
      }
      $form['sections'][$parent] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($section['name']),
        '#collapsible' => TRUE,
        '#collapsed' => $collapsed,
        '#tree' => TRUE,
      );
    }
    $string = str_repeat('-', $section['depth']) . ' ' . check_plain($section['name']);
    $form['sections'][$parent][$section['access_id']] = array(
      '#type' => 'checkbox',
      '#title' => $section['depth'] == 0 ? t('All of @string', array('@string' => $string)): t('@string', array('@string' => $string)),
      '#default_value' => isset($active['active'][$section['access_id']]),
      '#disabled' => variable_get('workbench_access_auto_assign', 1),
    );
    $used[] = $section['access_id'];
  }
  if (!variable_get('workbench_access_auto_assign', 1)) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save sections'),
    );
  }
  return $form;
}

/**
 * Save the active section definitions.
 */
function workbench_access_section_form_submit(&$form, &$form_state) {
  $access_scheme = $form_state['values']['access_scheme'];
  $access_tree = $form_state['values']['access_tree'];
  $results = $form_state['values']['sections'];
  $selection = array();
  $sections = array();
  foreach ($results as $result) {
    $selection = array_merge($selection, array_keys(array_filter($result)));
  }
  foreach ($selection as $access_id) {
    $sections[$access_id] = $access_tree[$access_id];
  }
  workbench_access_rebuild_scheme($access_scheme, $sections);
  if (empty($sections)) {
    drupal_set_message(workbench_access_sections_needed_message(), 'warning');
  }
  else {
    drupal_set_message(t('Editorial sections have been saved.'));
  }
}

/**
 * Assign sections to a user.
 *
 * @param $account
 *   The user account being acted upon.
 */
function workbench_access_user_form($form, &$form_state, $account) {
  if (!isset($account->workbench_access)) {
    $account = user_load($account->uid);
  }
  $active = workbench_access_get_active_tree();
  $form = array();
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $account->uid,
  );
  $form['helptext'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('The list below shows your editorial groups. You may edit any content in these sections and their children.') . '</p>',
  );
  if (user_access('assign_workbench_access')) {
    $form['helptext']['#markup'] .= '<p>' . t('You may edit these settings by checking the proper options.') . '</p>';
  }
  $sections = $account->workbench_access;
  $form['sections']['#tree'] = TRUE;
  $active_items = array_keys($active['active']);
  $section_items = array_keys($sections);
  $parent = 0;
  $used = array();
  foreach ($active['tree'] as $section) {
    $disabled = FALSE;
    if (in_array($section['access_id'], $used)) {
      continue;
    }
    if ($section['depth'] == 0) {
      $display = FALSE;
      $parent = $section['access_id'];
      $collapsed = TRUE;
      if (!empty($sections[$section['access_id']])) {
        $collapsed = FALSE;
        $display = TRUE;
      }
      elseif (!empty($section['children'])) {
        $check = array_intersect($section_items, $section['children']);
        if (!empty($check)) {
          $collapsed = FALSE;
        }
      }
      // Do we show inactive sections here?
      if (!empty($active['active'][$section['access_id']])) {
        $display = TRUE;
      }
      elseif (!empty($section['children'])) {
        $check = array_intersect($active_items, $section['children']);
        if (!empty($check)) {
          $display = TRUE;
        }
      }
      if ($display) {
        $form['sections'][$parent] = array(
          '#type' => 'fieldset',
          '#title' => check_plain($section['name']),
          '#collapsible' => TRUE,
          '#collapsed' => $collapsed,
          '#tree' => TRUE,
        );
      }
    }
    // Do we show inactive sections here?
    if (isset($active['active'][$section['access_id']])) {
      if (user_access('assign workbench access') && !empty($active['active'][$section['access_id']])) {
        $string = str_repeat('-', $section['depth']) . ' ' . check_plain($section['name']);
        if (isset($account->workbench_access_by_role[$section['access_id']])) {
          $string .= '*';
          $show_message = TRUE;
          $disabled = TRUE;
        }
        $form['sections'][$parent][$section['access_id']] = array(
          '#type' => 'checkbox',
          '#title' => $section['depth'] == 0 ? t('All of @string', array('@string' => $string)): t('@string', array('@string' => $string)),
          '#default_value' => isset($sections[$section['access_id']]),
          '#disabled' => !empty($disabled),
        );
      }
      elseif (isset($sections[$section['access_id']])) {
        $string = str_repeat('-', $section['depth']) . ' ' . check_plain($section['name']);
        if (isset($account->workbench_access_by_role[$section['access_id']])) {
          $string .= '*';
          $show_message = TRUE;
        }
        $form['sections'][$parent][$section['access_id']] = array(
          '#type' => 'markup',
          '#markup' => $section['depth'] == 0 ? t('All of @string', array('@string' => $string)): t('@string', array('@string' => $string)) . '<br />',
        );
      }
      /* Unused. Here for reference.
      elseif (variable_get('workbench_access_display_unassigned_sections', 0)) {
        $form['sections'][$parent][$section['access_id']] = array(
          '#type' => 'markup',
          '#markup' => ($section['depth'] == 0 ? t('All of') . ' ' : '') . str_repeat('-', $section['depth']) . ' ' . check_plain($section['name']) . '<br />',
        );
        $form['sections'][$parent][$section['access_id']]['#prefix'] = '<span class="workbench-access-disabled">';
        $form['sections'][$parent][$section['access_id']]['#suffix'] = '</span>';
      } */
    }
    else {
      $form['sections'][$parent][$section['access_id']] = array(
        '#type' => 'value',
        '#value' => 0,
      );
    }
    $used[] = $section['access_id'];
  }
  if (!empty($show_message)) {
    $form['sections'][$parent]['message'] = array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Items marked with an asterisk (*) are assigned by role.') . '</p>',
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save sections'),
    '#access' => user_access('assign workbench access'),
  );
  return $form;
}

/**
 * Save user assignments.
 */
function workbench_access_user_form_submit($form, &$form_state) {
  $results = $form_state['values']['sections'];
  $sections = array();
  foreach ($results as $result) {
    $sections = array_merge($sections, array_keys(array_filter($result)));
  }
  if (empty($sections)) {
    drupal_set_message(t('There are now no editorial sections for this user.'), 'warning');
  }
  $uid = $form_state['values']['uid'];
  workbench_access_rebuild_user($uid, $sections);
  if (!empty($sections)) {
    drupal_set_message(t('User permissions have been updated.'));
  }
}

/**
 * Show user sections.
 */
function workbench_access_sections() {
  global $user;
  $account = $user;
  if (!isset($account->workbench_access)) {
    workbench_access_user_load_data($account);
  }
  return drupal_get_form('workbench_access_user_form', $account);
}

/**
 * Display the editors for a section.
 *
 * If no group specified, then show a list of active groups, otherwise, load
 * the proper form to edit the members of the group.
 *
 * @param $access_type
 *   The type of access requested (e.g.g taxonomy).
 * @param $access_type_id
 *   The id for this specific access (here, a taxnomy term tid).
 * @param $type
 *   The page type being displayed (editor or role).
 *
 * @return
 *   An editing form or a list of section editors.
 *
 * @see workbench_access_editor_form()
 */
function workbench_access_editors($access_type = NULL, $access_type_id = NULL, $type = 'editor') {
  if (is_null($access_type) || is_null($access_type_id)) {
    // Set proper breadcrumb trails.
    if ($type == 'editor') {
      $breadcrumb[] = l(t('Workbench Access'), 'admin/config/workbench/access');
      workbench_access_breadcrumb($breadcrumb);
    }
    // Ensure that we have configured access controls.
    if (!$active = workbench_access_get_active_tree()) {
      return workbench_access_configuration_needed_message();
    }
    $active['access_scheme']['access_id'] = $access_type_id;
    $active_keys = array_keys($active['active']);
    if ($type == 'role') {
      $output = '<h2>' . t('Editorial assignments by role') . '</h2>';
    }
    elseif ($type == 'editor') {
      $output = '<h2>' . t('Editorial assignments by editor') . '</h2>';
    }
    $output .= '<p>' . t('The following sections are currently active.');
    if (user_access('administer workbench access')) {
      $output .= ' ' . t('You may <a href="!url">enable or disable sections</a>.', array('!url' => url('admin/config/workbench/access/sections'))) . '</p>';
    }
    $rows = array();
    foreach ($active['tree'] as $access_id => $section) {
      if (!isset($active['active'][$access_id])) {
        continue;
      }
      // Nest the children so the user understands the hierarchy.
      if ($section['depth'] == 0 || !isset($active['active'][$section['parent']])) {
        $parent = $section['name'];
      }
      $row = array(
        str_repeat('-', $section['depth'] ) . ' ' . l($section['name'], 'admin/config/workbench/access/' . "{$type}s/" . $active['access_scheme']['access_type'] . '/' . $access_id),
      );
      $roles = workbench_access_get_roles('access workbench access by role');
      if (empty($roles)) {
        if (user_access('administer permissions')) {
          return t('To continue, at least one role must be have the <a href="!url">Allow all members of this role to be assigned to Workbench Access sections</a> permission', array('!url' => url('admin/people/permissions', array('fragment' => 'module-workbench_access'))));
        }
        else {
          return t('There are no roles who have permission to edit sections. Please contact a site administrator.');
        }
      }
      if ($type == 'editor') {
        if (!isset($roles[DRUPAL_AUTHENTICATED_RID])) {
          $count = db_query("SELECT COUNT(DISTINCT wau.uid) FROM {workbench_access_user} wau
            INNER JOIN {users_roles} ur ON wau.uid = ur.uid
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id
            AND ur.rid IN (:rids)",
            array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id, ':rids' => array_keys($roles))
          )->fetchField();
        }
        else {
          $count = db_query("SELECT COUNT(DISTINCT wau.uid) FROM {workbench_access_user} wau
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id",
            array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id)
          )->fetchField();
        }
        $row[] = l(format_plural($count, '1 editor', '@count editors'), 'admin/config/workbench/access/editors/' . $active['access_scheme']['access_type'] . '/' . $access_id);
      }
      else {
        $count2 = db_query("SELECT COUNT(DISTINCT war.rid) FROM {workbench_access_role} war
          WHERE war.access_scheme = :access_scheme AND war.access_id = :access_id
          AND war.rid IN (:rids)",
          array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id, ':rids' => array_keys($roles))
        )->fetchField();
        $row[] = l(format_plural($count2, '1 role', '@count roles'),  'admin/config/workbench/access/roles/' . $active['access_scheme']['access_type'] . '/' . $access_id);
      }
      $rows[] = $row;
    }
    $header = array(t('Section'), t('@types', array('@type' => $type)));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
    $build['content']['#markup'] = $output;
    return $build;
  }
  return drupal_get_form('workbench_access_editor_form', $access_type, $access_type_id);
}

/**
 * Generate a user overview form for a section.
 *
 * @param $access_type
 *   The type of access requested (e.g.g taxonomy).
 * @param $access_type_id
 *   The id for this specific access (here, a taxnomy term tid).
 *
 * @return
 *   A form.
 */
function workbench_access_editor_form($form, &$form_state, $access_type, $access_type_id) {
  // Set proper breadcrumb trails.
  $breadcrumb[] = l(t('Workbench Access'), 'admin/config/workbench/access');
  $breadcrumb[] = l(t('Editors'), 'admin/config/workbench/access/editors');
  workbench_access_breadcrumb($breadcrumb);

  $form = array();
  $active = workbench_access_get_active_tree();
  $active['access_scheme']['access_id'] = $access_type_id;
  if ($active['access_scheme']['access_type'] != $access_type || !isset($active['active'][$access_type_id])) {
    drupal_access_denied();
    drupal_exit();
  }

  // Get the list of user roles that can be assigned workbench access.
  $roles = workbench_access_get_roles('access workbench access by role');

  $query = db_select('users', 'u')
    ->fields('u', array('uid', 'name'));
  $query->join('workbench_access_user', 'wau', 'u.uid = wau.uid');
  $query->condition('wau.access_scheme', $access_type)
    ->condition('wau.access_id', $access_type_id)
    ->extend('PagerDefault')->limit(25);
  // If all authorized users are not allowed, JOIN to user_roles.
  if (!isset($roles[DRUPAL_AUTHENTICATED_RID])) {
    $query->join('users_roles', 'ur', 'u.uid = ur.uid');
    $query->condition('ur.rid', array_keys($roles), 'IN');
  }
  $result = $query->execute();
  $rows = array();
  $form['users']['#tree'] = TRUE;
  foreach ($result as $account) {
    $form['users'][$account->uid]['name'] = array('#markup' => l(format_username($account), 'user/' . $account->uid));
    $form['users'][$account->uid]['remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Remove'),
    );
  }
  $form['add_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Add editor'),
    '#autocomplete_path' => 'workbench_access/autocomplete/' . $access_type . '/' . $access_type_id,
  );
  $form['workbench_access'] = array(
    '#type' => 'value',
    '#value' => $active['access_scheme'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update editors'),
  );
  return $form;
}

/**
 * Process form submission for adding editors.
 */
function workbench_access_editor_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load_by_name($values['add_user']);
    if (empty($account)) {
      form_set_error('add_user', t('The selected user does not exist.'));
    }
    elseif (!user_access('access workbench access by role', $account)) {
      form_set_error('add_user', t('The selected user does not have permission to be added as an editor.'));
    }
  }
}

/**
 * Process form submission for adding editors.
 */
function workbench_access_editor_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load_by_name($values['add_user']);
    $sections = $account->workbench_access;
    // If the user is assigned by role, ignore that and add anyway.
    if (!empty($account->workbench_access_by_role)) {
      foreach ($account->workbench_access_by_role as $key) {
        unset($sections[$key]);
      }
    }
    if (!empty($account->status) && !in_array($values['workbench_access']['access_id'], array_keys($sections))) {
      workbench_access_user_section_save($account->uid, $values['workbench_access']['access_id'], $values['workbench_access']['access_scheme']);
    }
  }
  if (!empty($values['users'])) {
    foreach ($values['users'] as $key => $value) {
      if (!empty($value['remove'])) {
        workbench_access_user_section_delete($key, $values['workbench_access']['access_id'], $values['workbench_access']['access_scheme']);
      }
    }
  }
}

/**
 * Theme the editor list form.
 */
function theme_workbench_access_editor_form($variables) {
  $form = $variables['form'];
  $scheme = $form['workbench_access']['#value'];
  $access_info = workbench_access_load_access_info($scheme);
  $output = '<h2>' . t('%name editors by account', array('%name' => $access_info['name'])) . '</h2>';
  $output .= '<p>' . t('Active editors for the %section section, as assigned by account. <a href="!url">View editors by role</a>.', array('%section' => $access_info['name'], '!url' => url('admin/config/workbench/access/roles/' . $scheme['access_type'] . '/' . $scheme['access_id'])));
  $header = array(t('Editor'), t('Actions'));
  $rows = array();
  foreach (element_children($form['users']) as $key) {
    $rows[] = array(
      drupal_render($form['users'][$key]['name']),
      drupal_render($form['users'][$key]['remove']),
    );
  }
  $variables = array(
    'header' => $header,
    'rows' => $rows,
    'empty' => t('No active editors have been found.'),
  );
  $output .= theme('table', $variables);
  $output .= drupal_render_children($form);
  return $output;
}

 /**
 * Display the roles for a section.
 *
 * @param $access_type
 *   The type of access requested (e.g.g taxonomy).
 * @param $access_type_id
 *   The id for this specific access (here, a taxnomy term tid).
 *
 * @return
 *   A list of editors within the given role.
 *
 * @see workbench_access_editor_form()
 */
function workbench_access_roles($access_type = NULL, $access_type_id = NULL) {
  if (is_null($access_type) || is_null($access_type_id)) {
    return workbench_access_editors(NULL, NULL, 'role');
  }
  return drupal_get_form('workbench_access_role_form', $access_type, $access_type_id);
}

/**
 * Generate a role overview form for a section.
 *
 * @param $access_type
 *   The type of access requested (e.g.g taxonomy).
 * @param $access_type_id
 *   The id for this specific access (here, a taxnomy term tid).
 *
 * @return
 *   A form.
 */
function workbench_access_role_form($form, &$form_state, $access_type, $access_type_id) {
  // Set proper breadcrumb trails.
  $breadcrumb[] = l(t('Roles'), 'admin/config/workbench/access/roles');
  workbench_access_breadcrumb($breadcrumb);

  $active = workbench_access_get_active_tree();
  $active['access_scheme']['access_id'] = $access_type_id;
  if ($active['access_scheme']['access_type'] != $access_type || !isset($active['active'][$access_type_id])) {
    drupal_access_denied();
    drupal_exit();
  }

  // Build the list of user roles that can be assigned workbench access.
  $roles = workbench_access_get_roles('access workbench access by role');

  // Form markup elements.
  $access_info = workbench_access_load($access_type, $access_type_id);
  $output = '<h2>' . t('%name editors by role', array('%name' => $access_info['name'])) . '</h2>';
  $output .= '<p>' . t('Active editors for the %section section, as determined by role. <a href="!url">View editors by account</a>.', array('%section' => $access_info['name'], '!url' => url('admin/config/workbench/access/editors/' . $active['access_scheme']['access_type'] . '/' . $access_type_id)));
  $header = array(t('Editors'), t('Roles'));
  $rows = array();
  $access_rids = array();
  if (!empty($roles)) {
    $access_rids = db_query("SELECT war.rid FROM {workbench_access_role} war WHERE war.rid IN (:rids) AND war.access_scheme = :access_scheme AND war.access_id = :access_type_id", array(':rids' => array_keys($roles), ':access_scheme' => $access_type, ':access_type_id' => $access_type_id))->fetchAllAssoc('rid');
  }
  $users = array();
  if (!empty($access_rids)) {
    if (!isset($access_rids[DRUPAL_AUTHENTICATED_RID])) {
      $users = db_query("SELECT u.name, u.uid, r.name AS roles FROM {users} u INNER JOIN {users_roles} ur ON ur.uid = u.uid LEFT JOIN {role} r ON r.rid = ur.rid WHERE ur.rid IN (:rids) AND u.status > 0", array(':rids' => array_keys($access_rids)));
    }
    else {
      $uids = db_query("SELECT u.uid FROM {users} u WHERE u.status > 0 AND u.uid > 0")->fetchCol();
      $users = user_load_multiple($uids);
    }
  }
  $users_by_role = array();
  foreach ($users as $data) {
    $users_by_role[$data->uid]['name'] = format_username($data);
    if (is_array($data->roles)) {
      array_walk($data->roles, 'check_plain');
      $users_by_role[$data->uid]['roles'] = array_values($data->roles);
    }
    else {
      $users_by_role[$data->uid]['roles'][] = check_plain($data->roles);
    }
  }
  // Add anonymous users, if selected.
  if (isset($access_rids[DRUPAL_ANONYMOUS_RID])) {
    $users_by_role[0] = array(
      'name' => variable_get('anonymous', t('Anonymous')),
      'roles' => array(
        'anonymous user',
      ),
    );
  }
  foreach ($users_by_role as $uid => $item) {
    $rows[] = array(
      l($item['name'], 'user/' . $uid),
      theme('item_list', array('items' => $item['roles'], 'type' => 'ul')),
    );
  }
  $table = theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('No active roles have been found.')));
  $form['content'] = array(
    '#weight' => -5,
    '#markup' => $output,
  );
  $form['table'] = array(
    '#weight' => -3,
    '#markup' => $table,
  );
  // User role form.
  $default = array_keys(db_query("SELECT rid FROM {workbench_access_role} WHERE access_scheme = :access_scheme AND access_id = :access_type_id", array(':access_scheme' => $access_type, ':access_type_id' => $access_type_id))->fetchAllAssoc('rid'));
  $form['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#options' => $roles,
    '#default_value' => $default,
    '#description' => empty($roles) ? t('There are no roles with the proper permissions.') : format_plural(count($roles), t('Select the role that should have all users assigned to this section.'), t('Select the roles that should have all users assigned to this section.')),
  );
  // TODO: replace with fancy jQuery.
  if (isset($roles[DRUPAL_AUTHENTICATED_RID])) {
    $form['roles']['#description'] .= '<p>' . t('Selecting the %auth role will select all registered users.', array('%auth' => $roles[DRUPAL_AUTHENTICATED_RID])) . '</p>';
  }
  $form['default_roles'] = array('#type' => 'value', '#value' => !empty($roles) ? $default : array());
  $form['workbench_access'] = array(
    '#type' => 'value',
    '#value' => $active['access_scheme'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update roles'),
  );
  return $form;
}

/**
 * Process form submission for adding roles.
 */
function workbench_access_role_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  // Handle the authenticated user role, which is all roles but anonymous.
  if (!empty($values['roles'][DRUPAL_AUTHENTICATED_RID])) {
    foreach ($values['roles'] as $key => $value) {
      if ($key > DRUPAL_ANONYMOUS_RID) {
        $values['roles'][$key] = $key;
      }
    }
  }
  // Role handling.
  foreach ($values['roles'] as $rid => $status) {
    if (!empty($status) && !in_array($rid, $values['default_roles'])) {
      workbench_access_role_section_save($rid, $values['workbench_access']['access_id'], $values['workbench_access']['access_scheme']);
    }
    elseif (empty($status) && in_array($rid, $values['default_roles'])) {
      workbench_access_role_section_delete($rid, $values['workbench_access']['access_id'], $values['workbench_access']['access_scheme']);
    }
  }
}

/**
 * Install a test vocabulary.
 *
 * Multistep process:
 *  1) Tell the user to configure this module.
 *  2) Create our vocabulary.
 *  3) Create some sample terms.
 *  4) Set the active schema for the site.
 *  5) Set all sections to active.
 *  6) Assign the super-user to the main section.
 *  7) Assign all nodes to the main section.
 *
 */
function workbench_access_example_taxonomy() {
  $vocabulary = workbench_access_sample_vocabulary();
  $exists = workbench_access_vocabulary_exists($vocabulary);
  // If the vocabulary exists, do not create any terms for it.
  if ($exists) {
    drupal_set_message(t('Workbench Access vocabulary has already been installed.'));
    return;
  }
  // Save.
  taxonomy_vocabulary_save($vocabulary);
  // Use the proper translation function, in case this is run from the install.
  $t = get_t();
  // Create some terms.
  $terms = array(
    $t('Exhibits'),
    $t('Library'),
    $t('Gift Shop'),
  );
  $children = array(
    $t('Staff'),
    $t('Visitors'),
  );
  // Get the proper filter format for taxonomy descriptions.
  $account = new stdClass();
  $account->uid = 0;
  $account->roles = array(DRUPAL_ANONYMOUS_RID);
  $format = filter_default_format($account);
  $ids = array('workbench_access');
  $i = -5;
  foreach ($terms as $name) {
    $term = new stdClass();
    $term->name = $name;
    $term->vocabulary_machine_name = 'workbench_access';
    $term->vid = $vocabulary->vid;
    $term->description = $t('Test term for Workbench Access.');
    $term->format = $format;
    $term->weight = $i;
    taxonomy_term_save($term);
    $i = $i +5;
    $ids[] = $term->tid;
    // Create child terms.
    foreach ($children as $child) {
      $item = new stdClass();
      $item->name = $name . ' ' . $child;
      $item->parent = $term->tid;
      $item->vocabulary_machine_name = 'workbench_access';
      $item->vid = $vocabulary->vid;
      $item->format = $format;
      $item->description = $t('Test child term for Workbench Access.');
      taxonomy_term_save($item);
      $ids[] = $item->tid;
    }
  }

  // Set our vocabulary as the default.
  variable_set('workbench_access_taxonomy', array($vocabulary->machine_name => $vocabulary->machine_name));
  // Set taxonomy as the active scheme.
  variable_set('workbench_access', 'taxonomy');
  // Set up the sections.
  $section = array(
    'access_scheme' => 'taxonomy',
    'access_type' => 'taxonomy',
    'access_type_id' => $vocabulary->machine_name,
  );
  foreach ($ids as $id) {
    $section['access_id'] = $id;
    workbench_access_section_save($section);
  }
  // Give the admin account access to all sections.
  workbench_access_user_section_save(1, 'workbench_access', 'taxonomy');

  // Get all nodes and save them to {workbench_access_node}.
  $nids = db_query("SELECT nid FROM {node}")->fetchAll();
  $values = array();
  foreach ($nids as $nid) {
    $values[] = array(
      'nid' => $nid->nid,
      'access_id' => 'workbench_access',
      'access_scheme' => 'taxonomy',
    );
  }
  if (empty($values)) {
    return;
  }
  $query = db_insert('workbench_access_node')->fields(array('nid', 'access_id', 'access_scheme'));
  foreach ($values as $record) {
    $query->values($record);
  }
  $query->execute();
  drupal_set_message('Sample configuration installed.');
}

/**
 * Check to see if our vocabulary is installed.
 *
 * @param $vocabulary
 *   A vocabulary object,
 *
 * @return
 *   Boolean TRUE or FALSE.
 */
function workbench_access_vocabulary_exists($vocabulary) {
  // Ensure that this is a unique vocabulary.
  $existing = taxonomy_get_vocabularies();
  foreach ($existing as $voc) {
    if ($voc->machine_name == $vocabulary->machine_name) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Define a sample vocabulary for testing.
 *
 * @return
 *   A vocabulary object.
 */
function workbench_access_sample_vocabulary() {
  $t = get_t();
  $vocabulary = new stdClass();
  $vocabulary->name = $t('Museum');
  $vocabulary->module = 'workbench_access';
  $vocabulary->machine_name = 'workbench_access';
  $vocabulary->description = $t('Access control for editorial content.');
  $vocabulary->hierarchy = 1;
  $vocabulary->weight = -10;
  return $vocabulary;
}

/**
 * Confirm install of the sample configuration.
 */
function workbench_access_install_form($form, &$form_state, $path = 'admin/config/workbench/access/settings') {
  $actions['items'] = array(
    t('Creates a sample <em>Museum</em> vocabulary.'),
    t('Creates taxonomy terms in that vocabulary.'),
    t('Enables all terms as site editorial sections.'),
    t('Assigns all site content to the <em>Museum</em> section.'),
    t('Assigns user 1 to the <em>Museum</em> section.'),
  );
  $form['help'] = array(
    '#markup' => t('The sample installation will perform the following actions: !actions', array('!actions' => theme('item_list', $actions))),
  );
  $form['path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $question = t('Are you sure you want to install the test configuration?');
  return confirm_form($form, $question, $path);
}

/**
 * Install the sample configuration.
 */
function workbench_access_install_form_submit(&$form, &$form_state) {
  $form_state['redirect'] = $form_state['values']['path'];
  workbench_access_example_taxonomy();
}

/**
 * Adds breadcrumb trails for admin pages.
 *
 * @param $breadcrumb
 *   An array of links to add to the breadcrumb trail.
 */
function workbench_access_breadcrumb($breadcrumb = array()) {
  $current = drupal_get_breadcrumb();
  $current = array_merge($current, $breadcrumb);
  drupal_set_breadcrumb($current);
}
