<?php
/**
 * @file
 * stanford_person.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_person_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_person_manage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Manage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_s_person_profile_picture' => 'field_s_person_profile_picture',
    'title' => 'title',
    'timestamp' => 'title',
    'status' => 'status',
    'changed' => 'changed',
    'field_s_person_last_name' => 'field_s_person_last_name',
    'field_s_person_affiliation' => 'field_s_person_affiliation',
    'field_s_person_faculty_type' => 'field_s_person_faculty_type',
    'field_s_person_student_type' => 'field_s_person_student_type',
    'field_s_person_staff_type' => 'field_s_person_staff_type',
    'field_s_person_weight' => 'field_s_person_weight',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
    'delete_node' => 'edit_node',
    'field_s_person_first_name' => 'field_s_person_first_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_person_profile_picture' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'timestamp' => array(
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_person_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_person_affiliation' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_person_faculty_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_person_student_type' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_person_staff_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_person_weight' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_person_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Row';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Modify',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'stanford_person::field_s_person_faculty_type' => 'stanford_person::field_s_person_faculty_type',
          'stanford_person::field_s_person_student_type' => 'stanford_person::field_s_person_student_type',
          'stanford_person::field_s_person_affiliation' => 'stanford_person::field_s_person_affiliation',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Publish',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Unpublish',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'thmb-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Display Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_s_person_last_name']['id'] = 'field_s_person_last_name';
  $handler->display->display_options['fields']['field_s_person_last_name']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['fields']['field_s_person_last_name']['field'] = 'field_s_person_last_name';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  /* Field: Content: Faculty Status */
  $handler->display->display_options['fields']['field_s_person_faculty_type']['id'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['field'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Student Type */
  $handler->display->display_options['fields']['field_s_person_student_type']['id'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['table'] = 'field_data_field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['field'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Staff Type */
  $handler->display->display_options['fields']['field_s_person_staff_type']['id'] = 'field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['table'] = 'field_data_field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['field'] = 'field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_staff_type']['delta_offset'] = '0';
  /* Field: Content: Sorting Weight */
  $handler->display->display_options['fields']['field_s_person_weight']['id'] = 'field_s_person_weight';
  $handler->display->display_options['fields']['field_s_person_weight']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['fields']['field_s_person_weight']['field'] = 'field_s_person_weight';
  $handler->display->display_options['fields']['field_s_person_weight']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_s_person_first_name']['id'] = 'field_s_person_first_name';
  $handler->display->display_options['fields']['field_s_person_first_name']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['fields']['field_s_person_first_name']['field'] = 'field_s_person_first_name';
  $handler->display->display_options['fields']['field_s_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_first_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_person' => 'stanford_person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Display Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Faculty Status (field_s_person_faculty_type) */
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['id'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['field'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator_id'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['label'] = 'Faculty Status';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['identifier'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['vocabulary'] = 'stanford_faculty_type';
  /* Filter criterion: Content: Student Type (field_s_person_student_type) */
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['id'] = 'field_s_person_student_type_tid';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['table'] = 'field_data_field_s_person_student_type';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['field'] = 'field_s_person_student_type_tid';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['expose']['operator_id'] = 'field_s_person_student_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['expose']['label'] = 'Student Type';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['expose']['operator'] = 'field_s_person_student_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['expose']['identifier'] = 'field_s_person_student_type_tid';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_student_type_tid']['vocabulary'] = 'stanford_student_type';
  /* Filter criterion: Content: Staff Type (field_s_person_staff_type) */
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['id'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['table'] = 'field_data_field_s_person_staff_type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['field'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator_id'] = 'field_s_person_staff_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['label'] = 'Staff Type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator'] = 'field_s_person_staff_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['identifier'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['vocabulary'] = 'stanford_staff_type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Affiliation (field_s_person_affiliation) */
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['id'] = 'field_s_person_affiliation_tid';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['field'] = 'field_s_person_affiliation_tid';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['expose']['operator_id'] = 'field_s_person_affiliation_tid_op';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['expose']['label'] = 'Affiliation';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['expose']['operator'] = 'field_s_person_affiliation_tid_op';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['expose']['identifier'] = 'field_s_person_affiliation_tid';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['vocabulary'] = 'stanford_affiliation';
  $handler->display->display_options['filters']['field_s_person_affiliation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/manage/people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage People';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'menu-manage-content-by-type';
  $handler->display->display_options['menu']['context'] = 0;
  $export['stanford_person_manage'] = $view;

  return $export;
}
