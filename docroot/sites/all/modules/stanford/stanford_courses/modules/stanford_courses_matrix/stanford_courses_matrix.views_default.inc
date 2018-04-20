<?php
/**
 * @file
 * stanford_courses_matrix.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_courses_matrix_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_courses_matrix';
  $view->description = 'Sortable table View of all Stanford Course nodes';
  $view->tag = 'Stanford Courses';
  $view->base_table = 'node';
  $view->human_name = 'Course Matrix';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Matrix';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'matrix';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['xconfig'] = array(
    'field' => 'field_s_course_term',
    'sort' => 'asc',
    'class' => '',
  );
  $handler->display->display_options['style_options']['yconfig'] = array(
    'field' => 'field_s_course_code_1',
    'sort' => 'asc',
    'class' => '',
  );
  /* No results behavior: Entity: Rendered entity */
  $handler->display->display_options['empty']['entity']['id'] = 'entity';
  $handler->display->display_options['empty']['entity']['table'] = 'entity__global';
  $handler->display->display_options['empty']['entity']['field'] = 'entity';
  /* Relationship: Content: Section Information (field_s_course_section_info) */
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['id'] = 'field_s_course_section_info_value';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['table'] = 'field_data_field_s_course_section_info';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['field'] = 'field_s_course_section_info_value';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Code (Integer) */
  $handler->display->display_options['fields']['field_s_course_code_integer']['id'] = 'field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['table'] = 'field_data_field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['field'] = 'field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_code_integer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_code_integer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_code_integer']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: ExploreCourses Link */
  $handler->display->display_options['fields']['field_s_course_ec_link']['id'] = 'field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['table'] = 'field_data_field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['field'] = 'field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_ec_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_ec_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_ec_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_course_ec_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_s_course_ec_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Instructor(s) */
  $handler->display->display_options['fields']['field_s_course_instructor']['id'] = 'field_s_course_instructor';
  $handler->display->display_options['fields']['field_s_course_instructor']['table'] = 'field_data_field_s_course_instructor';
  $handler->display->display_options['fields']['field_s_course_instructor']['field'] = 'field_s_course_instructor';
  $handler->display->display_options['fields']['field_s_course_instructor']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_instructor']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_instructor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_instructor']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_instructor']['delta_offset'] = '0';
  /* Field: Field collection item: Quarter */
  $handler->display->display_options['fields']['field_s_course_term']['id'] = 'field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['table'] = 'field_data_field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['field'] = 'field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_term']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_term']['element_label_colon'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_s_course_subject']['id'] = 'field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['table'] = 'field_data_field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['field'] = 'field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_subject']['element_label_colon'] = FALSE;
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_s_course_code_1']['id'] = 'field_s_course_code_1';
  $handler->display->display_options['fields']['field_s_course_code_1']['table'] = 'field_data_field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code_1']['field'] = 'field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_code_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_code_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_code_1']['alter']['text'] = '<p>[field_s_course_subject] [field_s_course_code_1]</p>
    <h3>[title]</h3>';
  $handler->display->display_options['fields']['field_s_course_code_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Code (field_s_course_code) */
  $handler->display->display_options['sorts']['field_s_course_code_value']['id'] = 'field_s_course_code_value';
  $handler->display->display_options['sorts']['field_s_course_code_value']['table'] = 'field_data_field_s_course_code';
  $handler->display->display_options['sorts']['field_s_course_code_value']['field'] = 'field_s_course_code_value';
  /* Contextual filter: Field collection item: Year (field_s_course_section_year) */
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['id'] = 'field_s_course_section_year_value';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['table'] = 'field_data_field_s_course_section_year';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['field'] = 'field_s_course_section_year_value';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['title'] = 'Title overridden in module alter';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['default_argument_options']['argument'] = '2016';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['field_s_course_section_year_value']['limit'] = '0';
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
    'stanford_course' => 'stanford_course',
  );

  /* Display: Course Matrix Page */
  $handler = $view->new_display('page', 'Course Matrix Page', 'course_matrix_page');
  $handler->display->display_options['path'] = 'course-matrix/%';

  $export['stanford_courses_matrix'] = $view;

  return $export;
}
