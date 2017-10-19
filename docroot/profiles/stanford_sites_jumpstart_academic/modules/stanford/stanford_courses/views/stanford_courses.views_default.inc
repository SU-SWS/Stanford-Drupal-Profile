<?php
/**
 * @file
 * stanford_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_courses_get_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_courses';
  $view->description = 'Sortable table View of all Stanford Course nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
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
  $handler->display->display_options['fields']['title']['label'] = 'Course Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_s_course_ec_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Academic Year */
  $handler->display->display_options['fields']['field_s_course_year']['id'] = 'field_s_course_year';
  $handler->display->display_options['fields']['field_s_course_year']['table'] = 'field_data_field_s_course_year';
  $handler->display->display_options['fields']['field_s_course_year']['field'] = 'field_s_course_year';
  $handler->display->display_options['fields']['field_s_course_year']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_s_course_code']['id'] = 'field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code']['table'] = 'field_data_field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code']['field'] = 'field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code']['element_label_colon'] = FALSE;
  /* Field: Content: Requirements */
  $handler->display->display_options['fields']['field_s_course_ger']['id'] = 'field_s_course_ger';
  $handler->display->display_options['fields']['field_s_course_ger']['table'] = 'field_data_field_s_course_ger';
  $handler->display->display_options['fields']['field_s_course_ger']['field'] = 'field_s_course_ger';
  $handler->display->display_options['fields']['field_s_course_ger']['element_label_colon'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_s_course_subject']['id'] = 'field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['table'] = 'field_data_field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['field'] = 'field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject']['element_label_colon'] = FALSE;
  /* Field: Content: Section Information */
  $handler->display->display_options['fields']['field_s_course_section_info']['id'] = 'field_s_course_section_info';
  $handler->display->display_options['fields']['field_s_course_section_info']['table'] = 'field_data_field_s_course_section_info';
  $handler->display->display_options['fields']['field_s_course_section_info']['field'] = 'field_s_course_section_info';
  $handler->display->display_options['fields']['field_s_course_section_info']['label'] = 'Section(s)';
  $handler->display->display_options['fields']['field_s_course_section_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_section_info']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_s_course_section_info']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_course_section_info']['multi_type'] = 'ul';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stanford-courses';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'stanford-courses/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  $export['stanford_courses'] = $view;

  return $export;
}
