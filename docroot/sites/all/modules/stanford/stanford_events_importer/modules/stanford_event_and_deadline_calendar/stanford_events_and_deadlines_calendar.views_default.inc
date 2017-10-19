<?php
/**
 * @file
 * stanford_events_and_deadlines_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_events_and_deadlines_calendar_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'stanford_create_new_event_link';
  $view->description = 'View that provides a create new event link.  Add to other views to assist with editing.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Create new event link';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="https://sites.stanford.edu/undergrad/node/add/stanford-event">Create New Event</a>';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['stanford_create_new_event_link'] = $view;

  $view = new view;
  $view->name = 'stanford_undergrad_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Undergrad Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Undergrad Calendar';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View Undergrad Calendar';
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
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'stanford_create_new_event_link:block';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No deadlines listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_short_month_and_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field_api_classes'] = 0;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['link_class'] = '[view_node]';
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_wrapper_class'] = 'border-bottom';
  $handler->display->display_options['fields']['field_stanford_event_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'ug-sm-square',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_stanford_event_image']['field_api_classes'] = 0;
  /* Field: Content: Is this a deadline? */
  $handler->display->display_options['fields']['field_stanford_event_deadline']['id'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['text'] = 'Dates & Deadlines';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field_api_classes'] = 0;
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
<div class="event-title"><h3 class="lead-event">[title]<h3></div>
<div class="descriptor">
<div class="event-date-long">[field_stanford_event_datetime] <span class="descriptor-light">|</span> [field_stanford_event_datetime_1]</div>
</div>
<div class="edit-link">[edit_node]</div>

</div>
</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['sorts']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  /* Contextual filter: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['value'] = array(
    1 => '1',
  );

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_month');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_stanford_event_deadline',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view_2']['id'] = 'view_2';
  $handler->display->display_options['footer']['view_2']['table'] = 'views';
  $handler->display->display_options['footer']['view_2']['field'] = 'view';
  $handler->display->display_options['footer']['view_2']['empty'] = TRUE;
  $handler->display->display_options['footer']['view_2']['view_to_insert'] = 'stanford_create_new_event_link:block';
  $handler->display->display_options['footer']['view_2']['inherit_arguments'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="span12" style="clear:left;"><h3>Events</h3></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'stanford_undergrad_calendar:block_month_events';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="span12" style="clear:left;"><h3>Dates & Deadlines</h3></div>
<p>None listed.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'calendar/month';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_day');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_stanford_event_deadline',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view_2']['id'] = 'view_2';
  $handler->display->display_options['footer']['view_2']['table'] = 'views';
  $handler->display->display_options['footer']['view_2']['field'] = 'view';
  $handler->display->display_options['footer']['view_2']['empty'] = TRUE;
  $handler->display->display_options['footer']['view_2']['view_to_insert'] = 'stanford_create_new_event_link:block';
  $handler->display->display_options['footer']['view_2']['inherit_arguments'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="span12" style="clear:left;"><h3>Events</h3></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'stanford_undergrad_calendar:block_day_events';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="span12" style="clear:left;"><h3>Dates & Deadlines</h3></div>
<p>None listed.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_short_month_and_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field_api_classes'] = 0;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_stanford_event_image']['field_api_classes'] = 0;
  /* Field: Content: Is this a deadline? */
  $handler->display->display_options['fields']['field_stanford_event_deadline']['id'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['text'] = 'Dates & Deadlines';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field_api_classes'] = 0;
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
<div class="event-title"><h3 class="lead-event">[title]</h3></div>
<div class="descriptor">
<div class="event-date-long">[field_stanford_event_datetime] | [field_stanford_event_datetime_1]</div>
</div>
<div class="edit-link">[edit_node]</div>

</div>
</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['path'] = 'calendar/day';
  $handler->display->display_options['menu']['title'] = 'Calendar';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Mini Month Block */
  $handler = $view->new_display('block', 'Mini Month Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
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

  /* Display: Month events block */
  $handler = $view->new_display('block', 'Month events block', 'block_month_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['display_description'] = 'Month events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No events listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
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
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['group'] = 2;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

  /* Display: Upcoming deadlines block */
  $handler = $view->new_display('block', 'Upcoming deadlines block', 'block_upcoming_deadlines');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Dates & Deadlines';
  $handler->display->display_options['display_description'] = 'Upcoming deadlines block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span6 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'stanford_short_month_and_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field_api_classes'] = 0;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['id'] = 'field_stanford_event_datetime_1';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['settings'] = array(
    'format_type' => 'stanford_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime_1']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_event_image']['id'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['table'] = 'field_data_field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['field'] = 'field_stanford_event_image';
  $handler->display->display_options['fields']['field_stanford_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_event_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_stanford_event_image']['field_api_classes'] = 0;
  /* Field: Content: Is this a deadline? */
  $handler->display->display_options['fields']['field_stanford_event_deadline']['id'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field'] = 'field_stanford_event_deadline';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['text'] = 'Deadlines';
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_deadline']['field_api_classes'] = 0;
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
<div class="event-date-long">[field_stanford_event_datetime] | [field_stanford_event_datetime_1]</div>
</div>
<div class="edit-link">[edit_node]</div>

</div>
</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['filters']['date_filter']['operator'] = '>';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

  /* Display: Day events block */
  $handler = $view->new_display('block', 'Day events block', 'block_day_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['display_description'] = 'Day events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No events listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date and Time -  start date (field_stanford_event_datetime) */
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['id'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['field'] = 'field_stanford_event_datetime_value';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_stanford_event_datetime_value']['granularity'] = 'day';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['group'] = 2;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

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
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_stanford_event_datetime']['id'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['table'] = 'field_data_field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field'] = 'field_stanford_event_datetime';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_stanford_event_datetime']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_event_datetime']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_event_datetime']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
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

  /* Display: Upcoming events block */
  $handler = $view->new_display('block', 'Upcoming events block', 'block_upcoming_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span6 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No events listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['filters']['date_filter']['operator'] = '>';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

  /* Display: Upcoming 3 events block */
  $handler = $view->new_display('block', 'Upcoming 3 events block', 'block_upcoming_3_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'calendar/day/now';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No events listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['tid']['title'] = '%1 Calendar';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'stanford_subsites_sites' => 'stanford_subsites_sites',
  );
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_subsites_sites' => 'stanford_subsites_sites',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = '1';
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
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
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );

  /* Display: Upcoming 3 events mainsite block */
  $handler = $view->new_display('block', 'Upcoming 3 events mainsite block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergrad Events';
  $handler->display->display_options['display_description'] = 'Upcoming events mainsite block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'calendar/day/now';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span12 clear-none clear-left-margin';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No events listed.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['tid']['title'] = '%1 Calendar';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 1;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'stanford_mainsite' => 'stanford_mainsite',
  );
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'stanford_mainsite' => 'stanford_mainsite',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = '1';
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
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
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value' => 'field_data_field_stanford_event_datetime.field_stanford_event_datetime_value',
  );
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['id'] = 'field_stanford_event_deadline_value_1';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_stanford_event_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Is this a deadline? (field_stanford_event_deadline) */
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['id'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['table'] = 'field_data_field_stanford_event_deadline';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['field'] = 'field_stanford_event_deadline_value';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_stanford_event_deadline_value']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_event' => 'stanford_event',
  );
  $export['stanford_undergrad_calendar'] = $view;

  return $export;
}
