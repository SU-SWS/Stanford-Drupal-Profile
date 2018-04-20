<?php
/**
 * @file
 * stanford_person_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_person_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_person_cap_list';
  $view->description = 'Provides a list display using CAP fields for people oriented towards students';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: CAP List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Student Type term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'stanford_student_type' => 'stanford_student_type',
    'stanford_affiliation' => 0,
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Thesis';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = 'Affiliation';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );

  /* Display: Student List Page */
  $handler = $view->new_display('page', 'Student List Page', 'page_list');
  $handler->display->display_options['display_description'] = 'List of people displaying student fields';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/cap-list';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: List Block */
  $handler = $view->new_display('block', 'List Block', 'block_list');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Group by Affiliation Page */
  $handler = $view->new_display('page', 'Group by Affiliation Page', 'group_by_affiliation_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Thesis';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = 'Affiliation';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/cap-list/grouped/affiliation';

  /* Display: Group by Student Page */
  $handler = $view->new_display('page', 'Group by Student Page', 'group_by_student_page');
  $handler->display->display_options['display_description'] = 'Group people by student type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_student_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Thesis';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = 'Affiliation';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Student Type */
  $handler->display->display_options['fields']['field_s_person_student_type']['id'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['table'] = 'field_data_field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['field'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_student_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_student_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_student_type']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_student_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_student_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/cap-list/grouped';
  $export['stanford_person_cap_list'] = $view;

  $view = new view();
  $view->name = 'stanford_person_directory';
  $view->description = 'Provides a directory display for people oriented toward staff. Sorted by weight, then by last and first names';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'people_affiliation_description:block';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
<div> [field_s_person_profile_picture]</div>

</div>

<div class="postcard-col2">
<h3>[title] </h3>
<div class="title-dept"> [field_s_person_faculty_title]</div>
[field_s_person_office_location]
[field_s_person_office_hours]
[field_s_person_phone_display]
[field_s_person_email]
<span class="edit-link">[edit_node]</span>
</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );

  /* Display: Directory Page */
  $handler = $view->new_display('page', 'Directory Page', 'page');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['display_description'] = 'Provides a directory type people listing';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/directory';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Directory Block */
  $handler = $view->new_display('block', 'Directory Block', 'block_staff');
  $handler->display->display_options['display_comment'] = 'Author: CJW';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Group by Page */
  $handler = $view->new_display('page', 'Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
<div> [field_s_person_profile_picture]</div>

</div>

<div class="postcard-col2">
<h3>[title] </h3>
<div class="title-dept"> [field_s_person_faculty_title]</div>
[field_s_person_office_location]
[field_s_person_office_hours]
[field_s_person_phone_display]
[field_s_person_email]
<span class="edit-link">[edit_node]</span>
</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/directory/grouped';
  $export['stanford_person_directory'] = $view;

  $view = new view();
  $view->name = 'stanford_person_faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_faculty_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Faculty Type term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_affiliation' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Faculty Status */
  $handler->display->display_options['fields']['field_s_person_faculty_type']['id'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['field'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Fields of Interest */
  $handler->display->display_options['fields']['field_s_person_interests']['id'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['table'] = 'field_data_field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['field'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_interests']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_interests']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_interests']['separator'] = ' ';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>
</div>

<div class="postcard-col2">
  <h3>[title]</h3>
 <div class="faculty-type"> [field_s_person_faculty_type]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
</div>

<div class="postcard-col3">
<div class="descriptor descriptor-btn">[field_s_person_interests]</div>

</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'faculty';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search faculty by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Faculty Status (field_s_person_faculty_type) */
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['id'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['field'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator_id'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['label'] = 'Filter by faculty status';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['identifier'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['vocabulary'] = 'stanford_faculty_type';
  /* Filter criterion: Content: Fields of Interest (field_s_person_interests) */
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['id'] = 'field_s_person_interests_tid_1';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['table'] = 'field_data_field_s_person_interests';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['field'] = 'field_s_person_interests_tid';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['operator_id'] = 'field_s_person_interests_tid_1_op';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['label'] = 'View by field of interest';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['operator'] = 'field_s_person_interests_tid_1_op';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['identifier'] = 'field_s_person_interests_tid_1';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['vocabulary'] = 'stanford_interests';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['hierarchy'] = 1;

  /* Display: Faculty Page */
  $handler = $view->new_display('page', 'Faculty Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/faculty';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Faculty Block - ajax */
  $handler = $view->new_display('block', 'Faculty Block - ajax', 'block_faculty_ajax');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Faculty Block */
  $handler = $view->new_display('block', 'Faculty Block', 'block_faculty');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['stanford_person_faculty'] = $view;

  $view = new view();
  $view->name = 'stanford_person_grid';
  $view->description = 'Provides a grid display for people.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Grid';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-grid-four';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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

  /* Display: Grid Block  */
  $handler = $view->new_display('block', 'Grid Block ', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Grid Page */
  $handler = $view->new_display('page', 'Grid Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/grid';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Group by Page */
  $handler = $view->new_display('page', 'Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/grid/grouped';
  $export['stanford_person_grid'] = $view;

  $view = new view();
  $view->name = 'stanford_person_grid_five';
  $view->description = 'Provides a grid display for people.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Grid Five';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-grid-five';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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

  /* Display: Grid Block  */
  $handler = $view->new_display('block', 'Grid Block ', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Grid Page */
  $handler = $view->new_display('page', 'Grid Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/grid-five';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Group by Page */
  $handler = $view->new_display('page', 'Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/grid-five/grouped';
  $export['stanford_person_grid_five'] = $view;

  $view = new view();
  $view->name = 'stanford_person_grid_six';
  $view->description = 'Provides a grid display for people.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Grid Six';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-grid-six';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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

  /* Display: Grid Block  */
  $handler = $view->new_display('block', 'Grid Block ', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Grid Page */
  $handler = $view->new_display('page', 'Grid Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/grid-six';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Group by Page */
  $handler = $view->new_display('page', 'Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['separator'] = '<br>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/grid-six/grouped';
  $export['stanford_person_grid_six'] = $view;

  $view = new view();
  $view->name = 'stanford_person_list';
  $view->description = 'Provides a list display grouped by affiliation for people and oriented towards students';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Dissertation';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );

  /* Display: Student List Page */
  $handler = $view->new_display('page', 'Student List Page', 'page_list');
  $handler->display->display_options['display_description'] = 'List of people displaying student fields';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/list';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Student List Block */
  $handler = $view->new_display('block', 'Student List Block', 'block_list');
  $handler->display->display_options['display_description'] = 'List of people displaying student fields';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Student List Group by Page */
  $handler = $view->new_display('page', 'Student List Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'List of people displaying student fields and grouped by Affiliation ';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Dissertation';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/list/grouped';
  $export['stanford_person_list'] = $view;

  $view = new view();
  $view->name = 'stanford_person_people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_faculty_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_person_office_location']['type'] = 'link_default';
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Mailing Address */
  $handler->display->display_options['fields']['field_s_person_mail_address_dspl']['id'] = 'field_s_person_mail_address_dspl';
  $handler->display->display_options['fields']['field_s_person_mail_address_dspl']['table'] = 'field_data_field_s_person_mail_address_dspl';
  $handler->display->display_options['fields']['field_s_person_mail_address_dspl']['field'] = 'field_s_person_mail_address_dspl';
  $handler->display->display_options['fields']['field_s_person_mail_address_dspl']['exclude'] = TRUE;
  /* Field: Content: Mail Code */
  $handler->display->display_options['fields']['field_s_person_mail_code']['id'] = 'field_s_person_mail_code';
  $handler->display->display_options['fields']['field_s_person_mail_code']['table'] = 'field_data_field_s_person_mail_code';
  $handler->display->display_options['fields']['field_s_person_mail_code']['field'] = 'field_s_person_mail_code';
  $handler->display->display_options['fields']['field_s_person_mail_code']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
<div> [field_s_person_profile_picture]</div>
</div>

<div class="postcard-col2">
<div>[title]</div>
[field_s_person_office_location]
[field_s_person_office_hours]
[field_s_person_phone_display]
[field_s_person_mail_address_dspl]
[field_s_person_mail_code]
[edit_node]
</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search faculty by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

  /* Display: People Page */
  $handler = $view->new_display('page', 'People Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'stanford/people';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['stanford_person_people'] = $view;

  $view = new view();
  $view->name = 'stanford_person_profiles';
  $view->description = 'Provides a profile display for people oriented towards faculty';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Faculty Status */
  $handler->display->display_options['fields']['field_s_person_faculty_type']['id'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['field'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Fields of Interest */
  $handler->display->display_options['fields']['field_s_person_interests']['id'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['table'] = 'field_data_field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['field'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_interests']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_interests']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_interests']['separator'] = ' ';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>
</div>

<div class="postcard-col2">
  <h3>[title]</h3>
 <div class="faculty-type"> [field_s_person_faculty_type]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
</div>

<div class="postcard-col3">
<div class="descriptor descriptor-btn">[field_s_person_interests]</div>

</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'People';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 'stanford_faculty_type',
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Faculty Status (field_s_person_faculty_type) */
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['id'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['field'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator_id'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['label'] = 'Filter by status';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['operator'] = 'field_s_person_faculty_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['identifier'] = 'field_s_person_faculty_type_tid';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_faculty_type_tid']['vocabulary'] = 'stanford_faculty_type';
  /* Filter criterion: Content: Fields of Interest (field_s_person_interests) */
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['id'] = 'field_s_person_interests_tid_1';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['table'] = 'field_data_field_s_person_interests';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['field'] = 'field_s_person_interests_tid';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['operator_id'] = 'field_s_person_interests_tid_1_op';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['label'] = 'View by field of interest';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['operator'] = 'field_s_person_interests_tid_1_op';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['expose']['identifier'] = 'field_s_person_interests_tid_1';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['vocabulary'] = 'stanford_interests';
  $handler->display->display_options['filters']['field_s_person_interests_tid_1']['hierarchy'] = 1;

  /* Display: Profile Page */
  $handler = $view->new_display('page', 'Profile Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/%/profiles';
  $handler->display->display_options['menu']['title'] = 'Faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Profile Block */
  $handler = $view->new_display('block', 'Profile Block', 'block_faculty');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Group by Page */
  $handler = $view->new_display('page', 'Group by Page', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Group people by Affiliation';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Faculty Status */
  $handler->display->display_options['fields']['field_s_person_faculty_type']['id'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['table'] = 'field_data_field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['field'] = 'field_s_person_faculty_type';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_faculty_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Fields of Interest */
  $handler->display->display_options['fields']['field_s_person_interests']['id'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['table'] = 'field_data_field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['field'] = 'field_s_person_interests';
  $handler->display->display_options['fields']['field_s_person_interests']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_interests']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_interests']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_person_interests']['separator'] = ' ';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>
</div>

<div class="postcard-col2">
  <h3>[title]</h3>
 <div class="faculty-type"> [field_s_person_faculty_type]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
</div>

<div class="postcard-col3">
<div class="descriptor descriptor-btn">[field_s_person_interests]</div>

</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid_1';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/%/profiles/grouped';
  $export['stanford_person_profiles'] = $view;

  $view = new view();
  $view->name = 'stanford_person_staff';
  $view->description = 'Sorted by type tax. term, by weight, then by last and first names';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Staff';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'people_affiliation_description:block';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Staff Type term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'stanford_staff_type' => 'stanford_staff_type',
    'stanford_affiliation' => 0,
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Staff Type */
  $handler->display->display_options['fields']['field_s_person_staff_type']['id'] = 'field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['table'] = 'field_data_field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['field'] = 'field_s_person_staff_type';
  $handler->display->display_options['fields']['field_s_person_staff_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_staff_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_staff_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_staff_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_staff_type']['delta_offset'] = '0';
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
<div> [field_s_person_profile_picture]</div>

</div>

<div class="postcard-col2">
<h3>[title] </h3>
<div class="title-dept"> [field_s_person_faculty_title]</div>
[field_s_person_office_location]
[field_s_person_office_hours]
[field_s_person_phone_display]
[field_s_person_email]
<span class="edit-link">[edit_node]</span>
</div>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'staff';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_staff_type' => 'stanford_staff_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search staff by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    13 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Staff Type (field_s_person_staff_type) */
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['id'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['table'] = 'field_data_field_s_person_staff_type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['field'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator_id'] = 'field_s_person_staff_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['label'] = 'Filter by staff type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator'] = 'field_s_person_staff_type_tid_op';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['identifier'] = 'field_s_person_staff_type_tid';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['vocabulary'] = 'stanford_staff_type';
  $handler->display->display_options['filters']['field_s_person_staff_type_tid']['hierarchy'] = 1;

  /* Display: Staff Page */
  $handler = $view->new_display('page', 'Staff Page', 'page');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/staff';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Staff Block */
  $handler = $view->new_display('block', 'Staff Block', 'block_staff');
  $handler->display->display_options['display_comment'] = 'Author: CJW';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Staff Page: Group by type */
  $handler = $view->new_display('page', 'Staff Page: Group by type', 'page_1');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_staff_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/staff/grouped';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['stanford_person_staff'] = $view;

  $view = new view();
  $view->name = 'stanford_person_student';
  $view->description = 'Student View is the Master display for cloning.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Student';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_student_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Student Type term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'stanford_student_type' => 'stanford_student_type',
    'stanford_affiliation' => 0,
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_faculty_type' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'stanford_staff_type' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Dissertation Title */
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['id'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['table'] = 'field_data_field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['field'] = 'field_s_person_dissertatn_title';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['label'] = 'Dissertation';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_label_class'] = 'descriptor ';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_dissertatn_title']['hide_empty'] = TRUE;
  /* Field: Content: Field of Study */
  $handler->display->display_options['fields']['field_s_person_study']['id'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['table'] = 'field_data_field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['field'] = 'field_s_person_study';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_study']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_study']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_study']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Student Type */
  $handler->display->display_options['fields']['field_s_person_student_type']['id'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['table'] = 'field_data_field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['field'] = 'field_s_person_student_type';
  $handler->display->display_options['fields']['field_s_person_student_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_student_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_student_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_student_type']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_s_person_student_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_student_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Cohort */
  $handler->display->display_options['fields']['field_s_person_cohort']['id'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['table'] = 'field_data_field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['field'] = 'field_s_person_cohort';
  $handler->display->display_options['fields']['field_s_person_cohort']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_label_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_person_cohort']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_cohort']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_cohort']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'students';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
    'stanford_student_type' => 'stanford_student_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search students by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

  /* Display: Student Page */
  $handler = $view->new_display('page', 'Student Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/students';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Student Block */
  $handler = $view->new_display('block', 'Student Block', 'block_student_ajax');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['stanford_person_student'] = $view;

  /* Alumni pages */
  $view = new view();
  $view->name = 'stanford_person_alumni';
  $view->description = 'Sorted by type tax. term, by weight, then by last and first names';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Alumni';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Alumni';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'people_affiliation_description:block';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>

  </div>

  <div class="postcard-col2">
  <h3>[title] </h3>
  <div class="title-dept"> [field_s_person_faculty_title]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
  </div>

  </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['argument'] = 'alumni';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search alumni by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    13 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Alumni Page */
  $handler = $view->new_display('page', 'Alumni Page', 'page');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/alumni';
  $handler->display->display_options['menu']['title'] = 'Alumni';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Alumni Block */
  $handler = $view->new_display('block', 'Alumni Block', 'block_alumni');
  $handler->display->display_options['display_comment'] = 'Author: CJW';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Alumni Page: Group by type */
  $handler = $view->new_display('page', 'Alumni Page: Group by type', 'page_alumni');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/alumni/grouped';
  $handler->display->display_options['menu']['title'] = 'Alumni';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['stanford_person_alumni'] = $view;
  $view = new view();
  $view->name = 'stanford_person_members';
  $view->description = 'Sorted by type tax. term, by weight, then by last and first names';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Person: Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Members';
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-person';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'people_affiliation_description:block';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'term-aff';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'stanford_affiliation' => 'stanford_affiliation',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>

  </div>

  <div class="postcard-col2">
  <h3>[title] </h3>
  <div class="title-dept"> [field_s_person_faculty_title]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
  </div>

  </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search alumni by name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    13 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Members Page */
  $handler = $view->new_display('page', 'Members Page', 'page');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'people/members';
  $handler->display->display_options['menu']['title'] = 'Alumni';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Members Block */
  $handler = $view->new_display('block', 'Members Block', 'block_members');
  $handler->display->display_options['display_comment'] = 'Author: CJW';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Members Page: Group by type */
  $handler = $view->new_display('page', 'Members Page: Group by type', 'page_members');
  $handler->display->display_options['display_comment'] = 'CJW';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_person_affiliation',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Title and Department */
  $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
  $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
  $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
  $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
  $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
  $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
  $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
  $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: View Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div class="postcard-col1">
  <div> [field_s_person_profile_picture]</div>

  </div>

  <div class="postcard-col2">
  <h3>[title] </h3>
  <div class="title-dept"> [field_s_person_faculty_title]</div>
  [field_s_person_office_location]
  [field_s_person_office_hours]
  [field_s_person_phone_display]
  [field_s_person_email]
  <span class="edit-link">[edit_node]</span>
  </div>

  </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliation */
  $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
  $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
  $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_person_weight) */
  $handler->display->display_options['sorts']['field_s_person_weight_value']['id'] = 'field_s_person_weight_value';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['table'] = 'field_data_field_s_person_weight';
  $handler->display->display_options['sorts']['field_s_person_weight_value']['field'] = 'field_s_person_weight_value';
  /* Sort criterion: Content: Last Name (field_s_person_last_name) */
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['id'] = 'field_s_person_last_name_value';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['table'] = 'field_data_field_s_person_last_name';
  $handler->display->display_options['sorts']['field_s_person_last_name_value']['field'] = 'field_s_person_last_name_value';
  /* Sort criterion: Content: First name (field_s_person_first_name) */
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['id'] = 'field_s_person_first_name_value';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['table'] = 'field_data_field_s_person_first_name';
  $handler->display->display_options['sorts']['field_s_person_first_name_value']['field'] = 'field_s_person_first_name_value';
  $handler->display->display_options['path'] = 'people/members/grouped';
  $handler->display->display_options['menu']['title'] = 'Alumni';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;


  $export['stanford_person_members'] = $view;
  return $export;
}
