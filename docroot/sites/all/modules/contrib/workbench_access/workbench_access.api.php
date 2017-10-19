<?php

/**
 * @file
 * API documentation file for Workbench Access.
 *
 * Note that Workbench Access inplements hook_hook_info().
 * You module may place its hooks inside a file named
 * module.workbench_access.inc for auto-loading by Drupal.
 *
 * Workbench Access uses a pluggable system for managing
 * its access control hierarchies. By default, menu and taxonomy
 * core modules are supported. Other modules may add
 * support by registering with this hook and providing the
 * required data.
 *
 * Required hooks include:
 *  hook_workbench_access_info()
 *  hook_workbench_access_tree()
 *  hook_workbench_access_load()
 *  hook_workbench_access_configuration()
 *
 */

/**
 * Defines your implementation for Workbench Access.
 *
 * This hook declares your module to Workbench Access.
 *
 * @return
 *  An array keyed by the name of your access scheme. (This is generally
 *  the module name.)
 *
 * Array elements:
 *
 *  - 'access_scheme'
 *    The name of the scheme, generally the name of your module. Required.
 *  - 'name'
 *    The human-readable name of the scheme, wrapped in t(). Required.
 *  - 'access_type'
 *    The module that defines core hooks for your access scheme. This can
 *    be different from the access_scheme and use one provided by another
 *    module. Required.
 *  - 'access_type_id'
 *    An array of keys that define the default access items in your structure.
 *    This should be a variable_get() from an array of checkboxes. The
 *    variable should be named 'workbench_access_ACCESS_SCHEME'. Required.
 *  - 'description'
 *    A human-readable description of the access control scheme. Required.
 *  - 'configuration'
 *    The configuration callback function. (Will default to
 *    hook_workbench_access_configuration() if not supplied.) Optional.
 *  - 'form_field'
 *    The name of the default form element, if any, used by this scheme's
 *    implementation of hook_node_form_alter(). For FieldAPI-enabled modules,
 *    such as Taxonomy, this will be NULL. Optional.
 *  - 'storage_column'
 *    The name of the database column used to store the primary key of the
 *    element. This value is used with FormAPI and FIeldAPI to ensure that
 *    the proper data is saved when using native form elements. Required.
 *  - 'translatable'
 *    Boolean value that indicated the value is translatable via FieldAPI.
 *    Tells the module how to save language-sensitive data. Required.
 *
 *
 * The remainder of the elements are used with Views to provide proper query
 * execution. They provide run-time alterations to Views handlers provided by
 * Workbench Access. These elements will likely change as the module matures.
 * These elements are all optional.
 *
 *  - 'query_field'
 *    The join field to the node storage table. Always 'access_id'.
 *  - 'field_table'
 *    The table where the join field is stored. Always {workbench_access_node}.
 *  - 'adjust_join'
 *    An array that defines how to alter the Views join for the table. This
 *    value is used to prevent duplicate results. See
 *    taxonomy_workbench_access_info() for sample usage.
 *  - 'sort'
 *    The table(s) and fields to use for Views sorting.
 *
 */
function hook_workbench_access_info() {
  return array(
    'menu' => array(
      'access_scheme' => 'menu',
      'name' => t('Menu'),
      'access_type' => 'menu',
      'access_type_id' => array_filter(variable_get('workbench_access_menu', array('main-menu'))),
      'description' => t('Uses a menu for assigning hierarchical access control'),
      'configuration' => 'menu_workbench_access_configuration',
      'form_field' => 'menu',
      'storage_column' => 'mlid',
      'translatable' => FALSE,
      'node_table' => 'workbench_access_node',
      'query_field' => 'access_id',
      'field_table' => 'workbench_access_node',
      'adjust_join' => array(
        'menu_links' => array(
          'original_table' => 'menu_links',
          'original_field' => 'mlid',
          'new_table' => 'workbench_access_node',
          'new_field' => 'access_id',
        ),
      ),
      'sort' => array(
        array(
          'table' => 'menu_links',
          'field' => 'plid',
        ),
        array(
          'table' => 'menu_links',
          'field' => 'weight',
          'order' => 'ASC',
        ),
      ),
    ),
  );
}

/**
 * Defines an access array for Workbench Access.
 *
 * For Workbench Access to find the position in the access hierarchy,
 * we have to have an easily traversable array. Unlike other _tree() functions
 * in Drupal, the primary goal here is to attach the parent ids to the childen.
 * Doing so allows the parents and children to be checked efficiently.
 *
 * The structure of your array should look like the following example:
 *
 *   array (
 *     'workbench_access' =>
 *     array (
 *       'access_id' => 'workbench_access',
 *       'access_type_id' => 'workbench_access',
 *       'name' => 'Workbench Access',
 *       'description' => 'Access control for editorial content.',
 *       'weight' => 0,
 *       'depth' => 0,
 *       'parent' => 0,
 *     ),
 *     1 =>
 *     array (
 *       'access_id' => '1',
 *       'access_type_id' => 'workbench_access',
 *       'name' => 'Museum',
 *       'description' => 'Test term for Workbench Access.',
 *       'weight' => '-5',
 *       'depth' => 1,
 *       'parent' => 'workbench_access',
 *     ),
 *     2 =>
 *     array (
 *       'access_id' => '2',
 *       'access_type_id' => 'workbench_access',
 *       'name' => 'Museum-Guests',
 *       'description' => 'Test child term for Workbench Access.',
 *       'weight' => '0',
 *       'depth' => 2,
 *       'parent' => '1',
 *     ),
 *     3 =>
 *     array (
 *       'access_id' => '3',
 *       'access_type_id' => 'workbench_access',
 *       'name' => 'Museum-Staff',
 *       'description' => 'Test child term for Workbench Access.',
 *       'weight' => '0',
 *       'depth' => 2,
 *       'parent' => '1',
 *     ),
 *   );
 *
 * A few things to note:
 *
 * Be sure to start at the top of the requested $info tree.
 *
 * The access_ids are the array keys. These are stored in the database as
 * VARCHARS, which allows us to mix machine names (strings) and serial ids
 * (integers) in our storage. This process allows us to use entire vocabularies
 * as access control sections, with the terms in the vocabulary as the children.
 *
 * There is a one-to-one ration of children to parent. That is, a child can only
 * have one parent item.
 *
 * Depth must start at 0, even for storage trees that normally start at 1 (like
 * menus). This lets us maintain a consistent API.
 *
 * This function is called in two contexts. The first builds a generic tree
 * structure used for access definitions. The second is when checking a user's
 * access rules. In the user case, we only care about the active access keys
 * that have been requested.
 *
 * @see workbench_access_get_active_tree()
 * @see workbench_access_get_access_tree()
 *
 * @param $info
 *   An array defining the access scheme, as defined in
 *   hook_workbench_access_info().
 * @param $keys
 *   Boolean value to return only array keys, or all data.
 *
 * @return
 *   An array of access_ids or a data array as defined above.
 */
function hook_workbench_access_tree($info, $keys) {
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
    $vocabulary = taxonomy_vocabulary_machine_name_load($vid);
    $tree[$vocabulary->machine_name] = array(
      'access_id' => $vocabulary->machine_name,
      'access_type_id' => $vocabulary->machine_name,
      'name' => $vocabulary->name,
      'description' => $vocabulary->description,
      'weight' => 0,
      'depth' => 0,
      'parent' => 0,
    );
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
  if ($keys) {
    return array_keys($tree);
  }
  return $tree;
}

/**
 * Loads information about an access_id.
 *
 * Simple lookup function to translate data from one storage system
 * to the Workbench Access API. This function will be passed a $scheme
 * array from hook_workbench_access_info() plus an 'access_id' element
 * that defines the access_id being checked.
 *
 * Note that our vocabulary example below checks machine name and term id
 * since we use VARCHAR storage keys.
 *
 * @param $scheme
 *   The active access scheme.
 *
 * @return
 *   The name, description and access_id for the given scheme.
 */
function hook_workbench_access_load($scheme) {
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($scheme['access_id'])) {
    $data = array(
      'name' => $vocabulary->name,
      'description' => $vocabulary->description,
      'access_id' => $vocabulary->machine_name,
    );
  }
  else {
    $term = taxonomy_term_load($scheme['access_id']);
    $data = array(
      'name' => $term->name,
      'description' => $term->description,
      'access_id' => $term->tid,
    );
  }
  return $data;
}

/**
 * Defines configuration options for your access scheme.
 *
 * This function is fun, because it uses Drupal 7's new JavaScript
 * $states properties to control the settings form.
 *
 * Your module is responsible for defining how it interacts with the
 * main form. If the 'workbench_access' value is equal to the name
 * of your access scheme, your options will be presented.
 *
 * Essentially, this is a custom hook_form_FORM_ID_alter() convenience
 * function.
 *
 * Note that your form should normally return checkboxes within a fieldset.
 * Do not make the checkboxes required, as this may be confusing if they are
 * in the 'hidden' state.
 *
 * @see drupal_process_states()
 *
 * @param &$form
 *   The base form, passed by reference.
 * @param &$form_state
 *   The form state, passed by reference.
 *
 * @return
 *   No return value. Modify $form by reference.
 */
function hook_workbench_access_configuration(&$form, &$form_state) {
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
    '#description' => t('Select the vocabulary to be used for access control. <strong>Warning: Changing this value in production may disrupt your workflow.</strong>'),
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
 * Responds to the saving of a Workbench Access section.
 *
 * This hook fires whenever we save changes to an access control section.
 * Normally, this hook is only fired on the initial creation of the section.
 *
 * @param $section
 *   Section data as defined by hook_workbench_access_info().
 */
function hook_workbench_access_save($section) {
  // Notify our module if the section is related to taxonomy.
  if ($section['access_type'] == 'taxonomy') {
    mymodule_do_something();
  }
}

/**
 * Responds to the deletion of a Workbench Access section.
 *
 * This hook fires whenever we delete an access control section.
 * Note that this hook fires _before_ the base tables are cleared,
 * in case you need to retrieve data from those tables.
 *
 * @param $section
 *   Section data as defined by hook_workbench_access_info().
 */
function hook_workbench_access_delete($section) {
  // Notify our module if the section is related to taxonomy.
  if ($section['access_type'] == 'taxonomy') {
    mymodule_delete_something();
  }
}

/**
 * Responds to the saving of a user-based section assignment.
 *
 * This hook fires when a user is assigned to a section.
 *
 * @param $account
 *   The active user account.
 * @param $access_id
 *   The access id to store.
 * @param $access_scheme
 *   The active access scheme as defined by hook_workbench_access_info().
 */
function hook_workbench_access_save_user($account, $access_id, $access_scheme) {
  // Notify our module if the section is related to taxonomy.
  if ($access_scheme['access_type'] == 'taxonomy') {
    mymodule_save_user($account, $access_id);
  }
}

/**
 * Responds to the deletion of a user-based section assignment.
 *
 * This hook fires when a user is removed from a section.
 * Note that this hook fires _before_ the base tables are cleared,
 * in case you need to retrieve data from those tables.
 *
 * @param $account
 *   The active user account.
 * @param $access_id
 *   The access id to store.
 * @param $access_scheme
 *   The active access scheme as defined by hook_workbench_access_info().
 */
function hook_workbench_access_delete_user($account, $access_id, $access_scheme) {
  // Notify our module if the section is related to taxonomy.
  if ($access_scheme['access_type'] == 'taxonomy') {
    mymodule_delete_user($account, $access_id);
  }
}

/**
 * Responds to the saving of a role-based section assignment.
 *
 * This hook fires when a role is assigned to a section.
 *
 * @param $role
 *   The active role object.
 * @param $access_id
 *   The access id to store.
 * @param $access_scheme
 *   The active access scheme as defined by hook_workbench_access_info().
 */
function hook_workbench_access_save_role($role, $access_id, $access_scheme) {
  // Notify our module if the section is related to taxonomy.
  if ($access_scheme['access_type'] == 'taxonomy') {
    mymodule_save_role($role, $access_id);
  }
}

/**
 * Responds to the deletion of a role-based section assignment.
 *
 * This hook fires when a roleis removed from a section.
 * Note that this hook fires _before_ the base tables are cleared,
 * in case you need to retrieve data from those tables.
 *
 * @param $role
 *   The active role object.
 * @param $access_id
 *   The access id to store.
 * @param $access_scheme
 *   The active access scheme as defined by hook_workbench_access_info().
 */
function hook_workbench_access_delete_role($role, $access_id, $access_scheme) {
  // Notify our module if the section is related to taxonomy.
  if ($access_scheme['access_type'] == 'taxonomy') {
    mymodule_delete_role($role, $access_id);
  }
}

/**
 * Allows modules to edit the Workbench Access node form element.
 *
 * This convenience function runs a hook_form_alter() targeted only at
 * the form element defined by Workbench Access.
 *
 * @param &$element
 *   The form element defined by workbench_access_form_alter(), passed
 *   by reference.
 * @param &$form_state
 *   The current form state, passed by reference.
 * @param $active
 *   The active data information for the access scheme.
 *
 * @see workbench_access_get_active_tree()
 *
 */
function hook_workbench_access_node_element_alter(&$element, $form_state, $active) {
  // Always make this element required.
  $element['#required'] = TRUE;
}

/**
 * Allows modules to edit forms associated with Workbench Access.
 *
 * This convenience function allows other modules to extend the
 * hook_form_alter() provided by workbench_access_form_alter(). This hook allows
 * other modules to change the behavior of the core module without worrying
 * about execution order of their hook respective to other modules.
 *
 * @param &$form
 *   The form element defined by workbench_access_form_alter(), passed
 *   by reference.
 * @param &$form_state
 *   The current form state, passed by reference.
 * @param $active
 *   The active data information for the access scheme.
 *
 * @see taxonomy_workbench_access_field_form_alter()
 */
function hook_workbench_access_FORM_ID_alter(&$form, &$form_state, $active) {
  /**
   * Workbench Access provides its own taxonomy, which cannot be used
   * in normal taxonomy selection forms. This sample alter hook operates on
   * field forms in order to remove the workbench_access vocabulary from
   * selection options.
   */
  if (!isset($form['field']['settings']['allowed_values'])) {
    return;
  }

  foreach ($form['field']['settings']['allowed_values'] as $key => $value) {
    if (isset($value['vocabulary']) && isset($form['field']['settings']['allowed_values'][$key]['vocabulary']['#options']['workbench_access'])) {
      unset($form['field']['settings']['allowed_values'][$key]['vocabulary']['#options']['workbench_access']);
    }
  }
}

/**
 * Allows modules to alter user privileges.
 *
 * Standard drupal_alter() hook to allow modules to modify the sections
 * that a user is allowed to edit. This hook is largely present to allow for
 * complex handling of content type permissions.
 *
 * @param &$access
 *   An array of access data, keyed by the access id. Passed by reference.
 * @param $account
 *   The active user account object. Note that this object may also be altered,
 *   since objects are implicitly passed by reference. Normally, you should not
 *   alter the $account object with this hook.
 */
function hook_workbench_access_user_alter(&$access, $account) {
  // Make content editing specific to assigned node types.
  if (empty($account->workbench_access)) {
    return;
  }
  $types = node_type_get_types();
  foreach ($access as $id => $data) {
    $access[$id]['update'] = array();
    foreach ($types as $type => $value) {
      if (user_access("edit any $type content", $account)) {
        $access[$id]['update'][] = $type;
      }
    }
  }
}
