<?php

/**
 * @file
 * Menu integration for Workbench Access.
 */

/**
 * Implements hook_workbench_access_info().
 *
 * Defines the default handler for access controls.
 */
function menu_workbench_access_info() {
  return array(
    'menu' => array(
      'access_scheme' => 'menu',
      'name' => t('Menu'),
      'access_type' => 'menu',
      'access_type_id' => array_filter(variable_get('workbench_access_menu', array('main-menu'))),
      'description' => t('Uses the menu system for assigning hierarchical access control.'),
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
 * Defines configuration options for the default access scheme.
 *
 * @see workbench_access_workbench_access_info()
 */
function menu_workbench_access_configuration(&$form, &$form_state) {
  $options = array();
  $menus = menu_get_menus();
  foreach ($menus as $name => $menu) {
    $options[$name] = $menu;
  }
  $form['menu_workbench_access_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu scheme settings'),
    '#states' => array(
      'visible' => array(
        ':input[name=workbench_access]' => array('value' => 'menu'),
      ),
    ),
  );
  $form['menu_workbench_access_info']['workbench_access_menu'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Editorial menus'),
    '#description' => t('Select the menus to be used for access control.'),
    '#options' => $options,
    '#default_value' => variable_get('workbench_access_menu', array('main_menu')),
    '#states' => array(
      'visible' => array(
        ':input[name=workbench_access]' => array('value' => 'menu'),
      ),
    ),
  );
  $form['menu_workbench_access_info']['workbench_access_menu_limit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Limit available menu items based on Workbench Access.'),
    '#description' => t('If checked, when creating nodes users will not be able to choose a parent menu item to which they do not have editorial access.'),
    '#default_value' => variable_get('workbench_access_menu_limit', 1),
  );
}

/**
 * Implements hook_workbench_access_tree().
 *
 * Get the access tree for a menu item.
 *
 * @param $info
 *   An array defining the access scheme.
 * @param $keys
 *   Boolean value to return only array keys, or all data.
 *
 * @return
 *   An array of access_ids or a data array.
 */
function menu_workbench_access_tree($info, $keys) {
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
    foreach (array_filter($info['access_type_id']) as $key) {
      $items[$key] = 0;
    }
  }
  $tree = array();
  foreach ($items as $name => $mlid) {
    $data = menu_load($name);
    if (empty($data['menu_name'])) {
      break;
    }

    if ($mlid == 0) {
      $tree[$name] = array(
        'access_id' => $data['menu_name'],
        'access_type_id' => $data['menu_name'],
        'name' => $data['title'],
        'description' => $data['description'],
        'weight' => 0,
        'depth' => 0,
        'parent' => 0,
      );
      $mlid = TRUE;
    }
    // This call returns a nested array.
    // @todo, given the use of a private function here, we might need our
    // own lookup instead.
    $menu = _menu_build_tree($name);
    foreach ($menu['tree'] as $link) {
      // Ensure that we start at the top of the current request.
      // If mlid is TRUE, we are at the root.
      _workbench_access_menu_build_tree($tree, $link, $mlid);
    }
  }
  if ($keys) {
    return array_keys($tree);
  }
  return $tree;
}

/**
 * Recursive helper function to build menus.
 *
 * @param &$tree
 *   The workbench access tree being built.
 * @param $link
 *   The menu link being inspected.
 * @param $mlid
 *   The menu link id being acted upon. May be 0 if this is the top-level menu
 *   item. Switches to TRUE so that children of a matching item can be selected.
 */
function _workbench_access_menu_build_tree(&$tree, $link, $mlid = 0) {
  $item = (object) $link['link'];
  // If the item matches the expected link id, or is the top-level, continue.
  if ($item->mlid == $mlid || $mlid === TRUE) {
    $tree[$item->mlid] = array(
      'access_id' => $item->mlid,
      'access_type_id' => $item->menu_name,
      'name' => $item->link_title,
      'description' => isset($item->options['attributes']['title']) ? $item->options['attributes']['title'] : '',
      'weight' => $item->weight,
      'depth' => $item->depth,
      'parent' => ($item->plid == 0) ? $item->menu_name : $item->plid,
    );
    // Access to the parent grants access to the children.
    $mlid = TRUE;
  }
  // menu_tree_all_data() returns a nested array, so if we don't start at the
  // top level of the tree, then we must check below links individually.
  if (!empty($link['below'])) {
    foreach ($link['below'] as $below) {
      _workbench_access_menu_build_tree($tree, $below, $mlid);
    }
  }
}

/**
 * Implements hook_workbench_access_load().
 *
 * Load data for a menu.
 */
function menu_workbench_access_load($scheme) {
  $data = array();
  // This might be a menu or a single menu item.
  if ($menu = menu_load($scheme['access_id'])) {
    $menu = (object) $menu;
    $data = array(
      'access_id' => $menu->menu_name,
      'name' => $menu->title,
      'description' => $menu->description,
    );
  }
  elseif ($item = menu_link_load($scheme['access_id'])) {
    $item = (object) $item;
    $data = array(
      'access_id' => $item->mlid,
      'name' => $item->link_title,
      'description' => isset($item->options['attribute']['description']) ? $item->options['attribute']['description'] : '',
    );
  }
  return $data;
}


/**
 * Implements hook_menu_delete().
 *
 * If an active menu is deleted, cascade the change through our system.
 */
function workbench_access_menu_delete($menu) {
  $access_scheme = db_query("SELECT * FROM {workbench_access} WHERE access_type = :access_type AND access_id = :access_id", array(':access_type' => 'menu', ':access_id' => $menu['menu_name']))->fetchAssoc();
  if (!empty($access_scheme)) {
    workbench_access_section_delete($access_scheme);
  }
}

/**
 * Implements hook_menu_link_insert().
 *
 * If an new link is added, check to see if we need to create a section.
 */
function workbench_access_menu_link_insert($link) {
  if (variable_get('workbench_access') != 'menu' || !variable_get('workbench_access_auto_assign', 1)) {
    return;
  }
  $active = array_filter(variable_get('workbench_access_menu', array()));
  if (in_array($link['menu_name'], $active)) {
    $section = array(
      'access_id' => $link['mlid'],
      'access_type' => 'menu',
      'access_scheme' => 'menu',
      'access_type_id' => $link['menu_name'],
    );
    workbench_access_section_save($section);
  }
}

/**
 * Implements hook_menu_link_update().
 *
 * If a menu link is updated, refresh the tree.
 */
function workbench_access_menu_link_update($link) {
  workbench_access_reset_tree();
}

/**
 * Implements hook_menu_link_delete().
 *
 * If an active menu link is deleted, cascade the change through our system.
 */
function workbench_access_menu_link_delete($link) {
  $access_scheme = db_query("SELECT * FROM {workbench_access} WHERE access_type = :access_type AND access_id = :access_id", array(':access_type' => 'menu', ':access_id' => $link['mlid']))->fetchAssoc();
  if (!empty($access_scheme)) {
    workbench_access_section_delete($access_scheme);
  }
}

/**
 * Executes a form alter on a specific FieldAPI form element.
 */
function menu_workbench_access_default_form_alter(&$form, &$form_state, $options) {
  if (!isset($form['menu'])) {
    return;
  }

  // If no options, then no access.
  if (empty($options)) {
    $form['menu']['#access'] = FALSE;
    return;
  }

  // Nothing to do if we're not limiting menu items.
  if (!variable_get('workbench_access_menu_limit', 1)) {
    return;
  }

  // Note that we require menu data for access control.
  $form['menu']['enabled']['#description'] = t('To enforce access control, this content must be placed in the menu.');

  // Adjust the parent form.
  $parent = &$form['menu']['link']['parent'];
  $current = $parent['#options'];

  foreach ($parent['#options'] as $key => $value) {
    $ids = explode(':', $key);
    $menu = $ids[0];
    $plid = $ids[1];
    // Unset if the user does not not have access to this item and the item
    // is not the current parent.
    if (!isset($options[$plid]) && !isset($options[$menu]) && (!$form['menu']['enabled']['#default_value'] || $key != $parent['#default_value'])) {
      unset($parent['#options'][$key]);
    }
  }

  // Assume that all new content will be in the menu.
  if (empty($form['#node']->nid)) {
    $form['menu']['enabled']['#default_value'] = 1;
  }

  // Add a warning note if the user does not have rights to the current parent,
  // as the user will not be able to restore the item to its current value if
  // changed.
  if (array_key_exists($parent['#default_value'], $parent['#options'])) {
    $tree = workbench_access_get_user_tree();
    $default = explode(':', $parent['#default_value']);
    if ($default[1] != 0 && !isset($tree[$default[1]])) {
      $parent['#description'] = t('<strong>Note:</strong> since you do not have editorial access to the parent of this menu item, if you change the parent you may not be able to restore it to its original value.');
    }
  }
}
