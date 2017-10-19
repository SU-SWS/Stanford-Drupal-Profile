<?php

/**
 * @file
 * Taxonomy integration for Workbench Access.
 */

/**
 * Implements hook_workbench_access_info().
 *
 * Defines the default handler for access controls.
 */
function taxonomy_workbench_access_info() {
  return array(
    'taxonomy' => array(
      'access_scheme' => 'taxonomy',
      'name' => t('Taxonomy'),
      'access_type' => 'taxonomy',
      'access_type_id' => array_filter(variable_get('workbench_access_taxonomy', array())),
      'description' => t('Uses taxonomy vocabularies for assigning hierarchical access control.'),
      'configuration' => 'taxonomy_workbench_access_configuration',
      'form_field' => NULL,
      'storage_column' => 'tid',
      'translatable' => TRUE,
      'query_field' => 'access_id',
      'field_table' => 'workbench_access_node',
      'adjust_join' => array(
        'taxonomy_term_data' => array(
          'original_table' => 'taxonomy_index',
          'original_field' => 'tid',
          'new_table' => 'workbench_access_node',
          'new_field' => 'access_id',
        ),
      ),
      'sort' => array(
        array(
          'table' => 'taxonomy_term_hierarchy',
          'field' => 'parent',
        ),
        array(
          'table' => 'taxonomy_term_data',
          'field' => 'weight',
          'order' => 'ASC',
        ),
        array(
          'table' => 'taxonomy_term_data',
          'field' => 'name',
          'order' => 'ASC',
        ),
      ),
    ),
  );
}

/**
 * Defines configuration options for the default access scheme.
 *
 * @see workbench_access_workbench_access_info()
 */
function taxonomy_workbench_access_configuration(&$form, &$form_state) {
  $options = array();
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vid => $vocabulary) {
    $options[$vocabulary->machine_name] = $vocabulary->name;
  }
  $form['taxonomy_workbench_access_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy scheme settings'),
    '#states' => array(
      'visible' => array(
        ':input[name=workbench_access]' => array('value' => 'taxonomy'),
      ),
    ),
  );
  $form['taxonomy_workbench_access_info']['workbench_access_taxonomy'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Editorial vocabulary'),
    '#description' => t('Select the vocabularies to be used for access control.'),
    '#options' => $options,
    '#default_value' => variable_get('workbench_access_taxonomy', array()),
    '#states' => array(
      'visible' => array(
        ':input[name=workbench_access]' => array('value' => 'taxonomy'),
      ),
    ),
  );
}

/**
 * Implements hook_workbench_access_FORM_ID_alter().
 */
function taxonomy_workbench_access_field_form_alter(&$form, &$form_state, $active) {
  _workbench_access_taxonomy_remove_option($form);
}

/**
 * Implements hook_workbench_access_FORM_ID_alter().
 */
function taxonomy_workbench_access_field_ui_field_edit_form_alter(&$form, &$form_state, $active) {
  _workbench_access_taxonomy_remove_option($form);
  $form['instance']['workbench_access_field'] = array(
    '#type' => 'checkbox',
    '#title' => t('Workbench Access control field'),
    '#description' => t('Use this field to determine access control for content editing.'),
    '#default_value' => !empty($form['#instance']['workbench_access_field']),
    '#weight' => -15,
  );
  $allowed = workbench_access_get_available_fields($form['#instance']['bundle']);
  $instance = $form['#instance']['field_name'];
  if (!isset($allowed[$instance])) {
    $form['instance']['workbench_access_field']['#disabled'] = TRUE;
    $form['instance']['workbench_access_field']['#default_value'] = 0;
    $form['instance']['workbench_access_field']['#description'] = t('This field cannot be used for access control.');
  }
}

/**
 * Implements hook_workbench_access_FORM_ID_alter().
 */
function taxonomy_workbench_access_field_ui_field_settings_form_alter(&$form, &$form_state, $active) {
  _workbench_access_taxonomy_remove_option($form);
}

/**
 * Helper function to remove the option from Field UI forms.
 */
function _workbench_access_taxonomy_remove_option(&$form) {
  if (!variable_get('workbench_access_custom_form', 1)) {
    return;
  }
  // The element we want is nested very deeply in the form.
  if (!isset($form['field']['settings']['allowed_values'])) {
    return;
  }
  // Cannot trust positional arrays to find the options.
  foreach ($form['field']['settings']['allowed_values'] as $key => $value) {
    if (is_array($value) && isset($value['vocabulary']) && isset($form['field']['settings']['allowed_values'][$key]['vocabulary']['#options']['workbench_access'])) {
      unset($form['field']['settings']['allowed_values'][$key]['vocabulary']['#options']['workbench_access']);
    }
  }
}

/**
 * Implements hook_workbench_access_tree().
 *
 * Get the access tree for a taxonomy term.
 *
 * @param $info
 *   An array defining the access scheme.
 * @param $keys
 *   Boolean value to return only array keys, or all data.
 *
 * @return
 *   An array of access_ids or a data array.
 */
function taxonomy_workbench_access_tree($info, $keys) {
  $tree = array();
  $items = array();
  if (isset($info['access_id'])) {
    if ($info['access_type_id'] != $info['access_id']) {
      $items[$info['access_type_id']] = $info['access_id'];
    }
    else {
      $items[$info['access_type_id']] = 0;
    }
  }
  else {
    foreach (array_filter($info['access_type_id']) as $vid) {
      $items[$vid] = 0;
    }
  }
  foreach ($items as $vid => $tid) {
    if ($vocabulary = taxonomy_vocabulary_machine_name_load($vid)) {
      if ($tid == 0) {
        $tree[$vocabulary->machine_name] = array(
          'access_id' => $vocabulary->machine_name,
          'access_type_id' => $vocabulary->machine_name,
          'name' => $vocabulary->name,
          'description' => $vocabulary->description,
          'weight' => 0,
          'depth' => 0,
          'parent' => $vocabulary->machine_name,
        );
      }
      $children = taxonomy_get_tree($vocabulary->vid, $tid);
      foreach ($children as $child) {
        $tree[$child->tid] = array(
          'access_id' => $child->tid,
          'access_type_id' => $vocabulary->machine_name,
          'name' => $child->name,
          'description' => $child->description,
          'weight' => $child->weight,
          'depth' => $child->depth+1,
          'parent' => !empty($child->parents[0]) ? $child->parents[0] : $vocabulary->machine_name,
        );
      }
    }
  }
  if ($keys) {
    return array_keys($tree);
  }
  return $tree;
}

/**
 * Implements hook_workbench_access_load().
 *
 * Load data for a taxonomy term.
 */
function taxonomy_workbench_access_load($scheme) {
  $data = array();
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($scheme['access_id'])) {
    $data = array(
      'name' => $vocabulary->name,
      'description' => $vocabulary->description,
      'access_id' => $vocabulary->machine_name,
    );
  }
  elseif ($term = taxonomy_term_load($scheme['access_id'])) {
    $data = array(
      'name' => $term->name,
      'description' => $term->description,
      'access_id' => $term->tid,
    );
  }
  return $data;
}

/**
 * Executes a form alter on a specific FieldAPI form element.
 */
function taxonomy_workbench_access_default_form_alter(&$form, &$form_state, $options) {
  foreach ($form['workbench_access_fields']['#value'] as $item) {
    // If the element isn't set, we can't do anything.
    if (!isset($form[$item][$form[$item]['#language']])) {
      continue;
    }

    // Set the element to be altered.
    $element = &$form[$item][$form[$item]['#language']];
    // Set the options for the form.
    if (isset($form[$item][$form[$item]['#language']]['#options'])) {
      foreach ($element['#options'] as $key => $value) {
        if ($key != '_none' && !isset($options[$key])) {
          unset($element['#options'][$key]);
        }
      }
    }
    // For content access fields with autocomplete widget, we use our own autocomplete callback with node type.
    elseif (isset($element['#autocomplete_path'])) {
      $element['#autocomplete_path'] = 'workbench_access/taxonomy_autocomplete/' . $item . '/' . $form['#node']->type;
      // We need our own validation, too.
      $element['#element_validate'][] = 'workbench_access_autocomplete_validate';
    }
  }
}

/**
 * Helper function for autocompletion of taxonomy terms.
 *
 * To determine if this is an access control field, we need to know the node
 * type.
 *
 * @see workbench_access_menu_alter()
 * @see workbench_access_query_term_access_alter()
 *
 * @param $field_name
 *  The name of the field being queried.
 * @param $node_type
 *  The content type for this field instance.
 * @param $tags_typed
 *  The data input by the user.
 *
 * @return
 *  No return value, the taxonomy_autocomplete() fires a JSON object.
 */
function workbench_access_taxonomy_autocomplete($field_name, $node_type, $tags_typed = '') {
  module_load_include('inc', 'taxonomy', 'taxonomy.pages');
  taxonomy_autocomplete($field_name, $tags_typed);
}

/**
 * Form element validate handler for taxonomy term autocomplete element.
 *
 * @TODO: How to handle the creation (or not) of new items here?
 */
function workbench_access_taxonomy_autocomplete_validate($element, &$form_state) {
  global $user;
  $item = $form_state['values'][$element['#field_name']][$form_state['values']['language']];
  if (empty($item)) {
    return;
  }
  if (!isset($user->workbench_access)) {
    workbench_access_user_load_data($user);
  }
  $tree = workbench_access_get_user_tree($user);
  // TODO: What if the user tree is empty?
  $terms = array();
  if (!empty($tree)) {
    foreach ($item as $key => $value) {
      if (!isset($tree[$value['tid']])) {
        $terms[] = check_plain($value['name']);
      }
    }
  }
  if (!empty($terms)) {
    form_set_error($element['#field_name'], t('You may not assign this content to: !terms', array('!terms' => implode(', ', $terms))));
  }
}

/**
 * Implements hook_query_TAG_alter().
 *
 * If this is a restricted taxonomy autocomplete query, add the conditions
 * required by Workbench Access.
 *
 * @see taxonomy_autocomplete()
 */
function workbench_access_query_term_access_alter(QueryAlterableInterface $query) {
  global $user;
  if (workbench_access_is_active_autocomplete()) {
    // Iterate through the query tables to find the taxonomy_term_data table alias
    $term_data_alias = 't';
    $tables = $query->getTables();
    foreach ($tables as $table_alias => $table_info) {
      if ($table_info['table'] == 'taxonomy_term_data') {
        $term_data_alias = $table_alias;
        break;
      }
    }
    // Alter the query.
    if (!isset($user->workbench_access)) {
      workbench_access_user_load_data($user);
    }
    $tree = workbench_access_get_user_tree($user);
    if (!empty($tree)) {
      $query->condition($term_data_alias . '.tid', array_keys($tree), 'IN');
    }
    // Force a NULL return if the user has no section assignments.
    else {
      $query->condition($term_data_alias . '.tid', -10);
    }
  }
}

/**
 * Implements hook_taxonomy_term_insert().
 *
 * If a new term is added, check to see if we need to create a section.
 */
function workbench_access_taxonomy_term_insert($term) {
  if (variable_get('workbench_access') != 'taxonomy' || !variable_get('workbench_access_auto_assign', 1)) {
    return;
  }
  $active = array_filter(variable_get('workbench_access_taxonomy', array()));
  if (in_array($term->vocabulary_machine_name, $active)) {
    $section = array(
      'access_id' => $term->tid,
      'access_type' => 'taxonomy',
      'access_scheme' => 'taxonomy',
      'access_type_id' => $term->vocabulary_machine_name,
    );
    workbench_access_section_save($section);
  }
}

/**
 * Implements hook_taxonomy_term_update().
 *
 * If a term is updated, reset the tree.
 */
function workbench_access_taxonomy_term_update($term) {
  workbench_access_reset_tree();
}

/**
 * Implements hook_taxonomy_term_delete().
 *
 * If an active term is deleted, cascade the change through our system.
 */
function workbench_access_taxonomy_term_delete($term) {
  $access_scheme = db_query("SELECT * FROM {workbench_access} WHERE access_type = :access_type AND access_id = :access_id", array(':access_type' => 'taxonomy', ':access_id' => $term->tid))->fetchAssoc();
  if (!empty($access_scheme)) {
    workbench_access_section_delete($access_scheme);
  }
}

/**
 * Implements hook_taxonomy_vocabulary_delete().
 *
 * If an active vocabulary is deleted, cascade the change through our system.
 */
function workbench_access_taxonomy_vocabulary_delete($vocabulary) {
  $access_scheme = db_query("SELECT * FROM {workbench_access} WHERE access_type = :access_type AND access_id = :access_id", array(':access_type' => 'taxonomy', ':access_id' => $vocabulary->machine_name))->fetchAssoc();
  if (!empty($access_scheme)) {
    workbench_access_section_delete($access_scheme);
  }
}

/**
 * Implements hook_taxonomy_vocabulary_update().
 *
 * If a machine_name is changed, then we must update our keys.
 */
function workbench_access_taxonomy_vocabulary_update($vocabulary) {
  // Update the section variable, if necessary.
  $active = variable_get('workbench_access_taxonomy', array());
  $original = $vocabulary->old_machine_name;

  // Check to see if the vocabulary is known and has changed.
  if (isset($active[$original]) && $vocabulary->machine_name != $original) {
    $find = $original;
    $replace = $vocabulary->machine_name;
    workbench_access_update_records($find, $replace, 'taxonomy');
  }
}
