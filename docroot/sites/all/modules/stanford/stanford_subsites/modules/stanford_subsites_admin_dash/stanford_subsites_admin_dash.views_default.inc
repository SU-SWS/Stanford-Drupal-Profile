<?php
/**
 * Default views file.
 */

function stanford_subsites_admin_dash_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'subsite_dashboard_manage_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Subsite Dashboard Manage Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'field_stanford_subsite_sname',
    'field_stanford_subsite_sname' => 'field_stanford_subsite_sname',
    'field_stanford_subsite_2nd_line' => 'field_stanford_subsite_sname',
    'type' => 'type',
    'changed' => 'changed',
    'name' => 'name',
    'status' => 'status',
    'field_s_content_status' => 'field_s_content_status',
    'edit_node' => 'view_node',
    'view_node' => 'view_node',
    'delete_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_stanford_subsite_sname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_stanford_subsite_2nd_line' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_content_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'Sorry';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>Sorry, but there is no content associated with the active subsite choice.</p>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Site Name */
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['id'] = 'field_stanford_subsite_sname';
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['table'] = 'field_data_field_stanford_subsite_sname';
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['field'] = 'field_stanford_subsite_sname';
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['label'] = 'Title';
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_subsite_sname']['empty'] = '[title]';
  /* Field: Content: Site Name Second Line */
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['id'] = 'field_stanford_subsite_2nd_line';
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['table'] = 'field_data_field_stanford_subsite_2nd_line';
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['field'] = 'field_stanford_subsite_2nd_line';
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_stanford_subsite_2nd_line']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'stanford_date_year_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'stanford_time';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Content Status */
  $handler->display->display_options['fields']['field_s_content_status']['id'] = 'field_s_content_status';
  $handler->display->display_options['fields']['field_s_content_status']['table'] = 'field_data_field_s_content_status';
  $handler->display->display_options['fields']['field_s_content_status']['field'] = 'field_s_content_status';
  $handler->display->display_options['fields']['field_s_content_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_content_status']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  /* Contextual filter: Field: Subsite Tags (field_stanford_subsite_sub_tags) */
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['id'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['table'] = 'field_data_field_stanford_subsite_sub_tags';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['field'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['default_argument_type'] = 'subsite';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    17 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    17 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    17 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Content Status (field_s_content_status) */
  $handler->display->display_options['filters']['field_s_content_status_value']['id'] = 'field_s_content_status_value';
  $handler->display->display_options['filters']['field_s_content_status_value']['table'] = 'field_data_field_s_content_status';
  $handler->display->display_options['filters']['field_s_content_status_value']['field'] = 'field_s_content_status_value';
  $handler->display->display_options['filters']['field_s_content_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_s_content_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_content_status_value']['expose']['operator_id'] = 'field_s_content_status_value_op';
  $handler->display->display_options['filters']['field_s_content_status_value']['expose']['label'] = 'Content Status';
  $handler->display->display_options['filters']['field_s_content_status_value']['expose']['operator'] = 'field_s_content_status_value_op';
  $handler->display->display_options['filters']['field_s_content_status_value']['expose']['identifier'] = 'field_s_content_status_value';
  $handler->display->display_options['filters']['field_s_content_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    17 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: Field: Subsite Tags (field_stanford_subsite_sub_tags) */
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['id'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['table'] = 'field_data_field_stanford_subsite_sub_tags';
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['field'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_stanford_subsite_sub_tags_tid']['vocabulary'] = 'stanford_subsites_sites';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['subsite_dashboard_manage_content'] = array(
    t('Master'),
    t('Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Sorry'),
    t('<p>Sorry, but there is no content associated with the active subsite choice.</p>'),
    t('author'),
    t('Title'),
    t('[title]'),
    t('Type'),
    t('Updated date'),
    t('Author'),
    t('Published'),
    t('Content Status'),
    t('Edit'),
    t('Actions'),
    t('View'),
    t('Delete'),
    t('All'),
    t('Block'),
  );


  $export['subsite_dashboard_manage_content'] = $view;
  return $export;
}
