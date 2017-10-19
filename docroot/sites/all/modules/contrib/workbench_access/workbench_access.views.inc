<?php

/**
 * @file
 *  Views integration for Workbench Access.
 */

/**
 * Implements hook_views_data().
 */
function workbench_access_views_data() {
  $data = array();
  $data['workbench_access']['table']['group']  = t('Workbench Access');
  $data['workbench_access']['edit'] = array(
    'title' => t('Edit link'),
    'help' => t('A link to edit the node.'),
    'field' => array(
      'handler' => 'workbench_access_handler_field_edit_node',
      'click sortable' => FALSE,
    ),
  );
  $data['workbench_access']['section'] = array(
    'title' => variable_get('workbench_access_label', 'Section'),
    'help' => t('The section to which this node belongs.'),
    'field' => array(
      'handler' => 'workbench_access_handler_field_section',
      'click sortable' => FALSE,
    ),
    // Temporarily disable sortability for the section handler.
    // @see http://drupal.org/node/1243186
    //'sort' => array(
    //  'handler' => 'workbench_access_handler_sort_section',
    //),
  );
  $data['workbench_access']['access_id'] = array(
    'title' => t('Access filter'),
    'help' => t('Filter nodes by access level.'),
    'filter' => array(
      'handler' => 'workbench_access_handler_filter_access',
    ),
  );

  $data['workbench_access_node']['table']['group'] = t('Workbench Access');
  $data['workbench_access_node']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('Nid'),
  );
  $data['workbench_access_node']['table']['join'] = array(
    //...to the node table
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),

    //...to taxonomy_term_data
    'taxonomy_term_data' => array(
      'left_field' => 'tid',
      'field' => 'access_id',
    ),
  );
  $data['workbench_access']['table']['join'] = array(
    //...to the node table
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node_revision' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  return $data;
}

/**
 * Implements hook_view_pre_view().
 *
 * Dynamically adds the exposed fitlers that workbench_access provides to
 * appropriate Views.
 *
 * There are a lot of 'if () {} else {}' statements in here to find out which
 * options to target. These look at a given option and check if it uses the
 * default settings or an override. The given option is then modified to add
 * filters/fields/settings from workbench_access.
 */
function workbench_access_views_pre_view(&$view, &$display_id, &$args) {
  // If not configured, do nothing.
  $tree = workbench_access_get_active_tree();
  if (empty($tree['active'])) {
    return;
  }
  // Target any view with a workbench tag that uses 'node' as the base_table.
  // TODO: support the node_revision table.
  if (is_numeric(strripos($view->tag, 'Workbench')) && ($view->base_table == 'node' || $view->base_table == 'node_revision')) {
    // This shorthand variable will increase readability.
    $current_display = $view->current_display;

    // If the current display uses default filters, target them.
    if ($current_display == 'default' || $view->display[$current_display]->handler->options['defaults']['filters']) {
      $filters = &$view->display['default']->handler->options['filters'];
    }
    // Otherwise, target this display's filters.
    else {
      $filters = &$view->display[$current_display]->handler->options['filters'];
    }

    // Add the access_id filter to the filters array.
    $filters['access_id'] = _workbench_access_views_access_id_filter_definition();

    // If the current display uses the default style_plugin, target the default
    // style_plugin and style options.
    if ($current_display== 'default' || $view->display[$current_display]->handler->options['defaults']['style_plugin']) {
      $style_plugin  = &$view->display['default']->handler->options['style_plugin'];
      $style_options = &$view->display['default']->handler->options['style_options'];
    }
    // Otherwise, target this display's style_plugin and style options.
    else {
      $style_plugin = &$view->display[$current_display]->handler->options['style_plugin'];
      $style_options = &$view->display[$current_display]->handler->options['style_options'];
    }

    // Only add a section field and style options if this is a table.
    if ($style_plugin == 'table') {

      // If the current display uses the default fields, target them.
      if ($current_display== 'default' || $view->display[$current_display]->handler->options['defaults']['fields']) {
        $fields = &$view->display['default']->handler->options['fields'];
      }
      // Otherwise, target this display's fields.
      else {
        $fields = &$view->display[$current_display]->handler->options['fields'];
      }

      // This temporary variable will take all the values from
      // the existing fields array and add a section field after the title.
      $new_view_fields = array();
      foreach ($fields as $key => $value) {
        $new_view_fields[$key] = $value;
        if ($key == 'title') {
          $new_view_fields['section'] = _workbench_access_views_section_field_definition();
        }
      }

      // Set the new fields array on the actual view.
      $fields = $new_view_fields;

      $style_options['columns']['section'] = 'section';
      $style_options['info']['section'] = array(
        // Only do a sortable section column on Views using the node table.
        // A PDO error occurs with the node_revision table.
        'sortable' => ($view->base_table == 'node'),
        'align' => '',
        'separator' => '',
      );
    }
  }
}

/**
 * Return the array definition of the access_id exposed filter.
 *
 * This is called from workbench_access_views_pre_view() to dynamically.
 * add this filter to given Views.
 */
function _workbench_access_views_access_id_filter_definition() {
  return array(
    'id' => 'access_id',
    'table' => 'workbench_access',
    'field' => 'access_id',
    'operator' => 'or',
    'exposed' => TRUE,
    'expose' => array(
      'label' => 'Sections',
      'identifier' => 'access_id',
      'remember' => 1,
      'single' => 0,
    ),
    'access_id' => array(),
    'size' => '5',
    'group' => '0',
  );
}

/**
 * Return the array definition of the section field.
 *
 * This is called from workbench_access_views_pre_view() to dynamically
 * add this field to given Views.
 */
function _workbench_access_views_section_field_definition() {
  return array(
    'id' => 'section',
    'table' => 'workbench_access',
    'field' => 'section',
    'alter' => array(
      'alter_text' => 0,
      'make_link' => 0,
      'absolute' => 0,
      'trim' => 0,
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'hide_empty' => 0,
    'empty_zero' => 0,
  );
}


/**
 * Implements hook_views_data_alter().
 *
 * Stub handling of the {menu_links} table for use with
 * the menu access scheme.
 *
 * Note that this only loads completely if no other module defines this table.
 */
function workbench_access_views_data_alter(&$data) {
  if (isset($data['menu_links'])) {
    // Add our join to {workbench_access_node}.
    $data['menu_links']['table']['join']['workbench_access_node'] = array(
      'left_field' => 'access_id',
      'field' => 'mlid',
    );
    return;
  }
  // Otherwise, define a stub table for sorting.
  $data['menu_links']['table']['group'] = t('Menu links');
  $data['menu_links']['table']['join'] = array(
    'workbench_access_node' => array(
      'left_field' => 'access_id',
      'field' => 'mlid',
    ),
    'node' => array(
      'left_table' => 'workbench_access_node',
      'left_field' => 'access_id',
      'field' => 'mlid',
    ),
    'node_revision' => array(
      'left_table' => 'workbench_access_node',
      'left_field' => 'access_id',
      'field' => 'mlid',
    ),
  );
  // Note that these are all pretty useless in most regards.
  $data['menu_links']['menu_name'] = array(
    'title' => t('Menu name'),
    'help' => t('The name of the menu.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['link_title'] = array(
    'title' => t('Link title'),
    'help' => t('The link text used for the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description used for the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['link_path'] = array(
    'title' => t('Link path'),
    'help' => t('The link path for the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['mlid'] = array(
    'title' => t('Menu link id'),
    'help' => t('The unique menu link identifier.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['plid'] = array(
    'title' => t('Parent menu link id'),
    'help' => t("The unique menu link identifier for this item's parent."),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['weight'] = array(
    'title' => t('Weight'),
    'help' => t('The weight of the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['depth'] = array(
    'title' => t('Depth'),
    'help' => t('The depth of the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
  $data['menu_links']['p1'] = array(
    'title' => t('Parent'),
    'help' => t('The top-level parent of the menu item.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );
}
