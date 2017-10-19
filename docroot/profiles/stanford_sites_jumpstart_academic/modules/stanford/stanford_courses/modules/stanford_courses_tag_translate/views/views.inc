<?php

/**
 * Implements hook_views_default_views().
 */
function stanford_courses_tag_translate_get_install_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_courses_ref_human_tag';
  $view->description = 'Courses imported from Explore Courses';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses with reference and human tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_s_course_ec_link' => 'field_s_course_ec_link',
    'field_s_course_code_integer' => 'field_s_course_code_integer',
    'field_s_course_subject_1' => 'title',
    'field_s_course_section_number' => 'field_s_course_section_number',
    'field_s_course_code_2' => 'title',
    'title' => 'title',
    'field_s_course_person' => 'field_s_course_person',
    'field_s_course_co_person' => 'field_s_course_person',
    'field_s_course_section_year' => 'field_s_course_section_year',
    'field_s_course_term' => 'field_s_course_section_year',
    'field_s_course_dow' => 'field_s_course_dow',
    'field_s_course_time_end' => 'field_s_course_time_end',
    'field_s_course_time' => 'field_s_course_dow',
    'field_s_course_location' => 'field_s_course_dow',
    'field_s_course_year' => 'field_s_course_year',
    'nid' => 'nid',
    'edit_node' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_s_course_ec_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_code_integer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_subject_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_section_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_code_2' => array(
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
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'field_s_course_person' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_co_person' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_section_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_s_course_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_dow' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_s_course_time_end' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_course_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Current Courses displays all courses offered in the current quarter.</p>
    <p>&nbsp;</p>
    [hook_views_pre_build:courses/search]';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Section Information (field_s_course_section_info) */
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['id'] = 'field_s_course_section_info_value';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['table'] = 'field_data_field_s_course_section_info';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['field'] = 'field_s_course_section_info_value';
  $handler->display->display_options['relationships']['field_s_course_section_info_value']['delta'] = '-1';
  /* Field: Content: ExploreCourses Link */
  $handler->display->display_options['fields']['field_s_course_ec_link']['id'] = 'field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['table'] = 'field_data_field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['field'] = 'field_s_course_ec_link';
  $handler->display->display_options['fields']['field_s_course_ec_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_ec_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_ec_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_ec_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_course_ec_link']['type'] = 'link_plain';
  /* Field: Content: Code (Integer) */
  $handler->display->display_options['fields']['field_s_course_code_integer']['id'] = 'field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['table'] = 'field_data_field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['field'] = 'field_s_course_code_integer';
  $handler->display->display_options['fields']['field_s_course_code_integer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_code_integer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_code_integer']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_s_course_subject_1']['id'] = 'field_s_course_subject_1';
  $handler->display->display_options['fields']['field_s_course_subject_1']['table'] = 'field_data_field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject_1']['field'] = 'field_s_course_subject';
  $handler->display->display_options['fields']['field_s_course_subject_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_subject_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_subject_1']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Section Number */
  $handler->display->display_options['fields']['field_s_course_section_number']['id'] = 'field_s_course_section_number';
  $handler->display->display_options['fields']['field_s_course_section_number']['table'] = 'field_data_field_s_course_section_number';
  $handler->display->display_options['fields']['field_s_course_section_number']['field'] = 'field_s_course_section_number';
  $handler->display->display_options['fields']['field_s_course_section_number']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_section_number']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_section_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_section_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_section_number']['alter']['text'] = '(section [field_s_course_section_number])';
  $handler->display->display_options['fields']['field_s_course_section_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_section_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_s_course_code_2']['id'] = 'field_s_course_code_2';
  $handler->display->display_options['fields']['field_s_course_code_2']['table'] = 'field_data_field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code_2']['field'] = 'field_s_course_code';
  $handler->display->display_options['fields']['field_s_course_code_2']['label'] = 'Course Number';
  $handler->display->display_options['fields']['field_s_course_code_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_code_2']['alter']['text'] = '[field_s_course_subject_1] [field_s_course_code_2] [field_s_course_section_number]';
  $handler->display->display_options['fields']['field_s_course_code_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_code_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_code_2']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field collection item: Instructor */
  $handler->display->display_options['fields']['field_s_course_person']['id'] = 'field_s_course_person';
  $handler->display->display_options['fields']['field_s_course_person']['table'] = 'field_data_field_s_course_person';
  $handler->display->display_options['fields']['field_s_course_person']['field'] = 'field_s_course_person';
  $handler->display->display_options['fields']['field_s_course_person']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_person']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_person']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_person']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_person']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Co Instructor */
  $handler->display->display_options['fields']['field_s_course_co_person']['id'] = 'field_s_course_co_person';
  $handler->display->display_options['fields']['field_s_course_co_person']['table'] = 'field_data_field_s_course_co_person';
  $handler->display->display_options['fields']['field_s_course_co_person']['field'] = 'field_s_course_co_person';
  $handler->display->display_options['fields']['field_s_course_co_person']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_co_person']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_co_person']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_co_person']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_co_person']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_co_person']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_co_person']['type'] = 'text_plain';
  /* Field: Field collection item: Year */
  $handler->display->display_options['fields']['field_s_course_section_year']['id'] = 'field_s_course_section_year';
  $handler->display->display_options['fields']['field_s_course_section_year']['table'] = 'field_data_field_s_course_section_year';
  $handler->display->display_options['fields']['field_s_course_section_year']['field'] = 'field_s_course_section_year';
  $handler->display->display_options['fields']['field_s_course_section_year']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_section_year']['label'] = 'Quarter';
  $handler->display->display_options['fields']['field_s_course_section_year']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Quarter */
  $handler->display->display_options['fields']['field_s_course_term']['id'] = 'field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['table'] = 'field_data_field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['field'] = 'field_s_course_term';
  $handler->display->display_options['fields']['field_s_course_term']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_term']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_term']['alter']['text'] = '[field_s_course_term] [field_s_course_year]';
  $handler->display->display_options['fields']['field_s_course_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_term']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_term']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_term']['delta_offset'] = '0';
  /* Field: Field collection item: Day(s) of Week */
  $handler->display->display_options['fields']['field_s_course_dow']['id'] = 'field_s_course_dow';
  $handler->display->display_options['fields']['field_s_course_dow']['table'] = 'field_data_field_s_course_dow';
  $handler->display->display_options['fields']['field_s_course_dow']['field'] = 'field_s_course_dow';
  $handler->display->display_options['fields']['field_s_course_dow']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_dow']['label'] = 'Day, Time, Location';
  $handler->display->display_options['fields']['field_s_course_dow']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_dow']['element_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_course_dow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_dow']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_dow']['element_wrapper_class'] = 'descriptor';
  /* Field: Field collection item: End Time */
  $handler->display->display_options['fields']['field_s_course_time_end']['id'] = 'field_s_course_time_end';
  $handler->display->display_options['fields']['field_s_course_time_end']['table'] = 'field_data_field_s_course_time_end';
  $handler->display->display_options['fields']['field_s_course_time_end']['field'] = 'field_s_course_time_end';
  $handler->display->display_options['fields']['field_s_course_time_end']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_time_end']['label'] = '';
  $handler->display->display_options['fields']['field_s_course_time_end']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_time_end']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Start Time */
  $handler->display->display_options['fields']['field_s_course_time']['id'] = 'field_s_course_time';
  $handler->display->display_options['fields']['field_s_course_time']['table'] = 'field_data_field_s_course_time';
  $handler->display->display_options['fields']['field_s_course_time']['field'] = 'field_s_course_time';
  $handler->display->display_options['fields']['field_s_course_time']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_s_course_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_course_time']['alter']['text'] = '[field_s_course_time] - [field_s_course_time_end]';
  $handler->display->display_options['fields']['field_s_course_time']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_course_time']['hide_empty'] = TRUE;
  /* Field: Field collection item: Location(s) */
  $handler->display->display_options['fields']['field_s_course_location']['id'] = 'field_s_course_location';
  $handler->display->display_options['fields']['field_s_course_location']['table'] = 'field_data_field_s_course_location';
  $handler->display->display_options['fields']['field_s_course_location']['field'] = 'field_s_course_location';
  $handler->display->display_options['fields']['field_s_course_location']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['fields']['field_s_course_location']['label'] = 'Room';
  $handler->display->display_options['fields']['field_s_course_location']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_course_location']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href=[edit_node]>Edit</a>';
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Subject (field_s_course_subject) */
  $handler->display->display_options['sorts']['field_s_course_subject_value']['id'] = 'field_s_course_subject_value';
  $handler->display->display_options['sorts']['field_s_course_subject_value']['table'] = 'field_data_field_s_course_subject';
  $handler->display->display_options['sorts']['field_s_course_subject_value']['field'] = 'field_s_course_subject_value';
  /* Sort criterion: Content: Code (field_s_course_code) */
  $handler->display->display_options['sorts']['field_s_course_code_value']['id'] = 'field_s_course_code_value';
  $handler->display->display_options['sorts']['field_s_course_code_value']['table'] = 'field_data_field_s_course_code';
  $handler->display->display_options['sorts']['field_s_course_code_value']['field'] = 'field_s_course_code_value';
  /* Sort criterion: Field collection item: Date Range -  start date (field_s_course_section_dates) */
  $handler->display->display_options['sorts']['field_s_course_section_dates_value']['id'] = 'field_s_course_section_dates_value';
  $handler->display->display_options['sorts']['field_s_course_section_dates_value']['table'] = 'field_data_field_s_course_section_dates';
  $handler->display->display_options['sorts']['field_s_course_section_dates_value']['field'] = 'field_s_course_section_dates_value';
  $handler->display->display_options['sorts']['field_s_course_section_dates_value']['relationship'] = 'field_s_course_section_info_value';
  /* Sort criterion: Field collection item: Section Number (field_s_course_section_number) */
  $handler->display->display_options['sorts']['field_s_course_section_number_value']['id'] = 'field_s_course_section_number_value';
  $handler->display->display_options['sorts']['field_s_course_section_number_value']['table'] = 'field_data_field_s_course_section_number';
  $handler->display->display_options['sorts']['field_s_course_section_number_value']['field'] = 'field_s_course_section_number_value';
  $handler->display->display_options['sorts']['field_s_course_section_number_value']['relationship'] = 'field_s_course_section_info_value';
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
  /* Filter criterion: Field collection item: Component (field_s_course_component) */
  $handler->display->display_options['filters']['field_s_course_component_value']['id'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['table'] = 'field_data_field_s_course_component';
  $handler->display->display_options['filters']['field_s_course_component_value']['field'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_s_course_component_value']['value'] = array(
    'DIS' => 'DIS',
    'INS' => 'INS',
    'PRC' => 'PRC',
    'T/D' => 'T/D',
  );
  $handler->display->display_options['filters']['field_s_course_component_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Date Range -  start date (field_s_course_section_dates) */
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['id'] = 'field_s_course_section_dates_value';
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['table'] = 'field_data_field_s_course_section_dates';
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['field'] = 'field_s_course_section_dates_value';
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_s_course_section_dates_value']['default_date'] = 'now';
  /* Filter criterion: Field collection item: Date Range - end date (field_s_course_section_dates:value2) */
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['id'] = 'field_s_course_section_dates_value2';
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['table'] = 'field_data_field_s_course_section_dates';
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['field'] = 'field_s_course_section_dates_value2';
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_s_course_section_dates_value2']['default_date'] = 'now';

  /* Display: Contextual Filter */
  $handler = $view->new_display('page', 'Contextual Filter', 'current_courses_page_human');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Courses by tags';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Course Tags Human (field_s_course_tag_human) */
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['id'] = 'field_s_course_tag_human_tid';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['table'] = 'field_data_field_s_course_tag_human';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['field'] = 'field_s_course_tag_human_tid';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['title'] = 'Courses by tag %1';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['validate_options']['vocabularies'] = array(
    'course_tags_human' => 'course_tags_human',
  );
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_s_course_tag_human_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Field collection item: Component (field_s_course_component) */
  $handler->display->display_options['filters']['field_s_course_component_value']['id'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['table'] = 'field_data_field_s_course_component';
  $handler->display->display_options['filters']['field_s_course_component_value']['field'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_s_course_component_value']['value'] = array(
    'DIS' => 'DIS',
    'INS' => 'INS',
    'PRC' => 'PRC',
    'T/D' => 'T/D',
  );
  $handler->display->display_options['filters']['field_s_course_component_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'courses/tag/%';

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'search_page_human');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Exposed Filter';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No courses are available based on your search.</p>
    <p>&nbsp;</p>
    [hook_views_pre_build:courses/search]';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Field collection item: Component (field_s_course_component) */
  $handler->display->display_options['filters']['field_s_course_component_value']['id'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['table'] = 'field_data_field_s_course_component';
  $handler->display->display_options['filters']['field_s_course_component_value']['field'] = 'field_s_course_component_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_component_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_s_course_component_value']['value'] = array(
    'DIS' => 'DIS',
    'INS' => 'INS',
    'PRC' => 'PRC',
    'T/D' => 'T/D',
  );
  $handler->display->display_options['filters']['field_s_course_component_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search all courses by keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_s_course_subject_1' => 'field_s_course_subject_1',
    'field_s_course_code_2' => 'field_s_course_code_2',
    'title' => 'title',
  );
  /* Filter criterion: Field collection item: Year (field_s_course_section_year) */
  $handler->display->display_options['filters']['field_s_course_section_year_value']['id'] = 'field_s_course_section_year_value';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['table'] = 'field_data_field_s_course_section_year';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['field'] = 'field_s_course_section_year_value';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['value'] = array(
    2013 => '2013',
    2014 => '2014',
  );
  $handler->display->display_options['filters']['field_s_course_section_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['operator_id'] = 'field_s_course_section_year_value_op';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['label'] = 'Academic year';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['operator'] = 'field_s_course_section_year_value_op';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['identifier'] = 'field_s_course_section_year_value';
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_s_course_section_year_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field collection item: Quarter (field_s_course_term) */
  $handler->display->display_options['filters']['field_s_course_term_value']['id'] = 'field_s_course_term_value';
  $handler->display->display_options['filters']['field_s_course_term_value']['table'] = 'field_data_field_s_course_term';
  $handler->display->display_options['filters']['field_s_course_term_value']['field'] = 'field_s_course_term_value';
  $handler->display->display_options['filters']['field_s_course_term_value']['relationship'] = 'field_s_course_section_info_value';
  $handler->display->display_options['filters']['field_s_course_term_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_course_term_value']['expose']['operator_id'] = 'field_s_course_term_value_op';
  $handler->display->display_options['filters']['field_s_course_term_value']['expose']['label'] = 'Quarter';
  $handler->display->display_options['filters']['field_s_course_term_value']['expose']['operator'] = 'field_s_course_term_value_op';
  $handler->display->display_options['filters']['field_s_course_term_value']['expose']['identifier'] = 'field_s_course_term_value';
  $handler->display->display_options['filters']['field_s_course_term_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Course Tags Human (field_s_course_tag_human) */
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['id'] = 'field_s_course_tag_human_tid';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['table'] = 'field_data_field_s_course_tag_human';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['field'] = 'field_s_course_tag_human_tid';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['expose']['operator_id'] = 'field_s_course_tag_human_tid_op';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['expose']['operator'] = 'field_s_course_tag_human_tid_op';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['expose']['identifier'] = 'field_s_course_tag_human_tid';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_course_tag_human_tid']['vocabulary'] = 'course_tags_human';
  $handler->display->display_options['path'] = 'courses/tags';

  $export['stanford_courses_ref_human_tag'] = $view;

  return $export;
}
