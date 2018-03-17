<?php
/**
 * @file
 * stanford_events_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_events_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_events_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Events Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar of Events';
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_month');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events Calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No events currently scheduled.  See other <a href="/events">upcoming events</a>.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '[field_stanford_event_datetime]';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_month_two_digit_date_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_month_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">

  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>

  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>

  <div class="edit-link">[edit_node]</div>

  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'events/month';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-stanford-event-datetime/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events Calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No events currently scheduled.  See other <a href="/events">upcoming events</a>.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_month_two_digit_date_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '[field_stanford_event_datetime]';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">

  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>

  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime]</div>
  <div class="event-location">[field_stanford_event_location]</div>

  <div class="edit-link">[edit_node]</div>

  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'events/day';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-stanford-event-datetime/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines well';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['block_description'] = 'Calendar of Events';

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );

  /* Display: Month Events Block */
  $handler = $view->new_display('block', 'Month Events Block', 'block_month_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '[field_stanford_event_datetime]';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_month_two_digit_date_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'month';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['stanford_events_calendar'] = $view;

  $view = new view();
  $view->name = 'stanford_events_manage';
  $view->description = 'View, edit, and delete your site\'s content.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Event: Manage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Stanford Events';
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
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_stanford_event_image' => 'field_stanford_event_image',
    'title' => 'title',
    'timestamp' => 'title',
    'status' => 'status',
    'changed' => 'changed',
    'field_stanford_event_datetime' => 'field_stanford_event_datetime',
    'field_stanford_event_location' => 'field_stanford_event_location',
    'field_s_event_type' => 'field_s_event_type',
    'title_1' => 'title_1',
    'nid' => 'nid',
    'feed_nid' => 'feed_nid',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
    'delete_node' => 'edit_node',
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
    'field_stanford_event_image' => array(
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
    'field_stanford_event_datetime' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stanford_event_location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_event_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
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
    'feed_nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
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
  );
  /* Relationship: Feeds item: Owner feed */
  $handler->display->display_options['relationships']['feed_nid']['id'] = 'feed_nid';
  $handler->display->display_options['relationships']['feed_nid']['table'] = 'feeds_item';
  $handler->display->display_options['relationships']['feed_nid']['field'] = 'feed_nid';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Row';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Modify',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'stanford_event::field_s_event_type' => 'stanford_event::field_s_event_type',
          'stanford_event::field_s_event_grouping' => 'stanford_event::field_s_event_grouping',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'thmb-square',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type']['id'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_event_type']['multi_type'] = 'ul';
  /* Field: Content: Event Grouping */
  $handler->display->display_options['fields']['field_s_event_grouping']['id'] = 'field_s_event_grouping';
  $handler->display->display_options['fields']['field_s_event_grouping']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['fields']['field_s_event_grouping']['field'] = 'field_s_event_grouping';
  $handler->display->display_options['fields']['field_s_event_grouping']['settings'] = array(
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'feed_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Feed Title';
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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
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
    15 => 0,
    17 => 0,
  );
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
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    13 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Location (field_stanford_event_location) */
  $handler->display->display_options['filters']['field_stanford_event_location_value']['id'] = 'field_stanford_event_location_value';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['field'] = 'field_stanford_event_location_value';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['group'] = 1;
  $handler->display->display_options['filters']['field_stanford_event_location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stanford_event_location_value']['expose']['operator_id'] = 'field_stanford_event_location_value_op';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['expose']['operator'] = 'field_stanford_event_location_value_op';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['expose']['identifier'] = 'field_stanford_event_location_value';
  $handler->display->display_options['filters']['field_stanford_event_location_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    13 => 0,
    11 => 0,
    9 => 0,
    7 => 0,
    5 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'feed_nid';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Owner feed title';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['group'] = 1;
  $handler->display->display_options['filters']['field_s_event_grouping_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_event_grouping_value']['expose']['operator_id'] = 'field_s_event_grouping_value_op';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['expose']['label'] = 'Event Grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['expose']['operator'] = 'field_s_event_grouping_value_op';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['expose']['identifier'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
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
  $handler->display->display_options['path'] = 'admin/manage/events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-content-by-type';
  $handler->display->display_options['menu']['context'] = 0;
  $export['stanford_events_manage'] = $view;

  $view = new view();
  $view->name = 'stanford_events_views';
  $view->description = 'List-style page and sidebar block';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Events List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Currently, no future events are scheduled.</p>
  <p><a class="more-link" href="/events/past-events">View Past Events</a></p>';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '<div class="clearfix">[field_stanford_event_datetime]</div>';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['text'] = '[field_stanford_event_datetime]
  [field_stanford_event_datetime_1]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
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
    'stanford_event' => 'stanford_event',
  );
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';

  /* Display: 5 Item Upcoming - List Page */
  $handler = $view->new_display('page', '5 Item Upcoming - List Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events currently scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '<div class="clearfix">[field_stanford_event_datetime]</div>';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['text'] = '[field_stanford_event_datetime]
  [field_stanford_event_datetime_1]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_stanford_event_location']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_stanford_event_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_location']['settings'] = array(
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
    'stanford_event' => 'stanford_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['group'] = 1;
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );
  $handler->display->display_options['filters']['field_s_event_grouping_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'events/upcoming-events';
  $handler->display->display_options['menu']['title'] = 'Upcoming Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 2 Item Upcoming Block - Date Stacked */
  $handler = $view->new_display('block', '2 Item Upcoming Block - Date Stacked', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events currently scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['text'] = '<div class="clearfix">[field_stanford_event_datetime]</div>';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_short_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['text'] = '[field_stanford_event_datetime]
  [field_stanford_event_datetime_1]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_two_digit_day',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_stanford_event_location']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">

  <div class="date-stacked">
  <div class="date-month">[field_stanford_event_datetime]</div>
  <div class="date-day">[field_stanford_event_datetime_1]</div>
  </div>

  <div>
  <div class="event-title normal-link"><h3>[title]</h3></div>
  <div class="event-location descriptor">[field_stanford_event_location]</div>
  <div class="event-date-long descriptor">[field_stanford_event_datetime_2]</div>
  <div class="edit-link">[edit_node]</div>
  </div>

  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
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
    'stanford_event' => 'stanford_event',
  );
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );

  /* Display: Upcoming Feed */
  $handler = $view->new_display('feed', 'Upcoming Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'stanford-events/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: 5 Item Upcoming - List Block */
  $handler = $view->new_display('block', '5 Item Upcoming - List Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Includes images';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events currently scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
    'stanford_event' => 'stanford_event',
  );
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );

  /* Display: 5 Item Past Events - List Block */
  $handler = $view->new_display('block', '5 Item Past Events - List Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Includes images';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Currently, no past events are listed.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type_1']['id'] = 'field_s_event_type_1';
  $handler->display->display_options['fields']['field_s_event_type_1']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['text'] = '<span class="descriptor">Type: </span>';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_offset'] = '0';
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type']['id'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['order'] = 'DESC';
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
    'stanford_event' => 'stanford_event',
  );
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );

  /* Display: 5 Item Upcoming - List Block with no pager */
  $handler = $view->new_display('block', '5 Item Upcoming - List Block with no pager', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Includes images';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_date_year_time_space',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_stanford_event_location']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
    'stanford_event' => 'stanford_event',
  );
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );

  /* Display: Past Events - List Page */
  $handler = $view->new_display('page', 'Past Events - List Page', 'events_past_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events currently scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year_time_space',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type_1']['id'] = 'field_s_event_type_1';
  $handler->display->display_options['fields']['field_s_event_type_1']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['text'] = '<span class="descriptor">Type: </span>';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_offset'] = '0';
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type']['id'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['order'] = 'DESC';
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
    'stanford_event' => 'stanford_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['group'] = 1;
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'today';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'ours' => 'ours',
  );
  $handler->display->display_options['filters']['field_s_event_grouping_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'events/past-events';
  $handler->display->display_options['menu']['title'] = 'Upcoming Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 5 Item Upcoming - Related Page */
  $handler = $view->new_display('page', '5 Item Upcoming - Related Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No related events currently scheduled.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'sm-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2] ';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['id'] = 'field_stanford_event_datetime_2';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['text'] = '[title]
  [field_stanford_event_datetime_2]';
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_2']['settings'] = array(
    'format_type' => 'stanford_long_day_date_year_time_space',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_stanford_event_location']['id'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['table'] = 'field_data_field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['field'] = 'field_stanford_event_location';
  $handler->display->display_options['fields']['field_stanford_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_location']['element_label_colon'] = FALSE;
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type_1']['id'] = 'field_s_event_type_1';
  $handler->display->display_options['fields']['field_s_event_type_1']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['alter']['text'] = '<span class="descriptor">Type: </span>';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_event_type_1']['delta_offset'] = '0';
  /* Field: Content: Event Type */
  $handler->display->display_options['fields']['field_s_event_type']['id'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['table'] = 'field_data_field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['field'] = 'field_s_event_type';
  $handler->display->display_options['fields']['field_s_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_event_type']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_event_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_event_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_event_type']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
  <div>
  <div class="event-image">[field_stanford_event_image]</div>
  </div>
  <div>
  <div class="event-title"><h3>[title]</h3></div>
  <div class="descriptor">
  <div class="event-date-long">[field_stanford_event_datetime_2]</div>
  <div class="event-location">[field_stanford_event_location]</div>
  </div>
  </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
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
    'stanford_event' => 'stanford_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['group'] = 1;
  $handler->display->display_options['filters']['field_stanford_event_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event Grouping (field_s_event_grouping) */
  $handler->display->display_options['filters']['field_s_event_grouping_value']['id'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['table'] = 'field_data_field_s_event_grouping';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['field'] = 'field_s_event_grouping_value';
  $handler->display->display_options['filters']['field_s_event_grouping_value']['value'] = array(
    'related' => 'related',
  );
  $handler->display->display_options['filters']['field_s_event_grouping_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'events/related-events';
  $handler->display->display_options['menu']['title'] = 'Upcoming Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stanford_events_views'] = $view;

  return $export;
}
