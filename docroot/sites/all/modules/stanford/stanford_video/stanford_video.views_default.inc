<?php
/**
 * @file
 * stanford_video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'views-row-lines view-stanford-video';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See more videos';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Video - No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No recent videos listed.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
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
      <div class="postcard-image">
           <div>[field_s_image_info]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
           <div>[body]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no videos to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'med-landscape',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Date (field_s_video_date) */
  $handler->display->display_options['sorts']['field_s_video_date_value']['id'] = 'field_s_video_date_value';
  $handler->display->display_options['sorts']['field_s_video_date_value']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['sorts']['field_s_video_date_value']['field'] = 'field_s_video_date_value';
  $handler->display->display_options['sorts']['field_s_video_date_value']['order'] = 'DESC';
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
    'stanford_video' => 'stanford_video',
  );

  /* Display: 5 Item Video List Page with Pager */
  $handler = $view->new_display('page', '5 Item Video List Page with Pager', 'page_5_item_list_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Videos';
  $handler->display->display_options['display_description'] = 'Contains exposed filter search for title and video categories';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'med-landscape',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
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
      <div class="postcard-image">
           <div class="video-image">[field_s_video_featured_image]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
           <div>[body]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no videos to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
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
    'stanford_video' => 'stanford_video',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
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
  /* Filter criterion: Content: Categories (field_s_video_categories) */
  $handler->display->display_options['filters']['field_s_video_categories_tid']['id'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['field'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['operator_id'] = 'field_s_video_categories_tid_op';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['operator'] = 'field_s_video_categories_tid_op';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['identifier'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    12 => 0,
    10 => 0,
    8 => 0,
    6 => 0,
    20 => 0,
    14 => 0,
    16 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['field_s_video_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['vocabulary'] = 'stanford_video_categories';
  $handler->display->display_options['path'] = 'videos/recent-videos';
  $handler->display->display_options['menu']['title'] = 'Recent Videos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 3 Item Recent Videos List Block */
  $handler = $view->new_display('block', '3 Item Recent Videos List Block', 'block_3_item_recent_videos_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Videos';
  $handler->display->display_options['display_description'] = 'Homepage block of three items';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more recent videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
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
      <div class="postcard-image">
           <div>[field_s_video_featured_image]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no videos to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;

  /* Display: 1 Item Featured Video Block with Details */
  $handler = $view->new_display('block', '1 Item Featured Video Block with Details', 'block_1_featured_video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Videos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-stanford-video';
  $handler->display->display_options['display_description'] = 'Homepage block of 1 Featured video';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more recent videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '800',
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
  <div class="postcard-image">
    <div class>[field_s_video_featured_image]</div>
  </div>
  <div class="postcard-content">
    <div><h3>[title]</h3></div>
    <div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
    <div>[body]</div>
  </div>
</div>
<div class="edit-link">[edit_node]</div>
<hr>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no videos to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;

  /* Display: Featured Block Attachment */
  $handler = $view->new_display('attachment', 'Featured Block Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'stanford-video-grid-two view-stanford-video';
  $handler->display->display_options['display_description'] = 'View attachment for 1 Item Featured Video Block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more recent videos';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'med-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_video_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_video_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_video_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
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
  <div class="postcard-image">
    <div>[field_s_video_featured_image]</div>
    </div>
  <div class="postcard-content">
    <div><h3>[title]</h3></div>
     <div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
  </div>
</div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no videos to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  $handler->display->display_options['displays'] = array(
    'block_1_featured_video' => 'block_1_featured_video',
    'default' => 0,
    'page_5_item_list_page' => 0,
    'block_3_item_recent_videos_list' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: 12 Item Video Grid Page with Pager */
  $handler = $view->new_display('page', '12 Item Video Grid Page with Pager', 'page_12_grid_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Videos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'stanford-video-grid-four view-stanford-video';
  $handler->display->display_options['display_description'] = 'Contains exposed filter search for title and video categories';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_featured_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'large-square',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_video_categories']['id'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['field'] = 'field_s_video_categories';
  $handler->display->display_options['fields']['field_s_video_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_video_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_video_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_video_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_video_categories']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>[field_s_video_featured_image]</div>
<div class="descriptor">[field_s_video_date] | [field_s_video_categories]</div>
<div><h3>[title]</h3></div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'stanford_video' => 'stanford_video',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
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
  /* Filter criterion: Content: Categories (field_s_video_categories) */
  $handler->display->display_options['filters']['field_s_video_categories_tid']['id'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['table'] = 'field_data_field_s_video_categories';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['field'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['operator_id'] = 'field_s_video_categories_tid_op';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['operator'] = 'field_s_video_categories_tid_op';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['identifier'] = 'field_s_video_categories_tid';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    12 => 0,
    10 => 0,
    8 => 0,
    6 => 0,
    20 => 0,
    14 => 0,
    16 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['field_s_video_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_video_categories_tid']['vocabulary'] = 'stanford_video_categories';
  $handler->display->display_options['path'] = 'videos/recent-videos/grid';
  $handler->display->display_options['menu']['title'] = 'Recent Videos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stanford_video'] = $view;

  $view = new view();
  $view->name = 'stanford_video_manage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Video: Manage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Videos';
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
    'views_bulk_operations' => 'views_bulk_operations',
    'field_s_image_info' => 'field_s_image_info',
    'title' => 'title',
    'status' => 'status',
    'changed' => 'changed',
    'name' => 'name',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'field_s_image_info' => array(
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
    'name' => array(
      'sortable' => 0,
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
  );
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
        'show_all_tokens' => 1,
        'display_values' => array(
          'stanford_video::field_s_video_categories' => 'stanford_video::field_s_video_categories',
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
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_s_video_featured_image']['id'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['table'] = 'field_data_field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['field'] = 'field_s_video_featured_image';
  $handler->display->display_options['fields']['field_s_video_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_video_featured_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_video_date']['id'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['field'] = 'field_s_video_date';
  $handler->display->display_options['fields']['field_s_video_date']['label'] = 'Video Date';
  $handler->display->display_options['fields']['field_s_video_date']['settings'] = array(
    'format_type' => 'stanford_month_date_year',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Video Embed */
  $handler->display->display_options['fields']['field_s_video_embed']['id'] = 'field_s_video_embed';
  $handler->display->display_options['fields']['field_s_video_embed']['table'] = 'field_data_field_s_video_embed';
  $handler->display->display_options['fields']['field_s_video_embed']['field'] = 'field_s_video_embed';
  $handler->display->display_options['fields']['field_s_video_embed']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_s_video_embed']['type'] = 'video_embed_field_thumbnail';
  $handler->display->display_options['fields']['field_s_video_embed']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'source',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Categories';
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'stanford_affiliate_organization_type' => 0,
    'stanford_affiliation' => 0,
    'stanford_department' => 0,
    'stanford_event_type' => 0,
    'stanford_faculty_type' => 0,
    'fellowship_location' => 0,
    'stanford_field_of_study' => 0,
    'stanford_interests' => 0,
    'news_categories' => 0,
    'publication_type' => 0,
    'research_themes' => 0,
    'school_themes' => 0,
    'stanford_slide_category' => 0,
    'stanford_staff_type' => 0,
    'stanford_event_audience' => 0,
    'stanford_event_categories' => 0,
    'stanford_student_type' => 0,
    'tags' => 0,
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
  /* Sort criterion: Content: Date (field_s_video_date) */
  $handler->display->display_options['sorts']['field_s_video_date_value']['id'] = 'field_s_video_date_value';
  $handler->display->display_options['sorts']['field_s_video_date_value']['table'] = 'field_data_field_s_video_date';
  $handler->display->display_options['sorts']['field_s_video_date_value']['field'] = 'field_s_video_date_value';
  $handler->display->display_options['sorts']['field_s_video_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_video' => 'stanford_video',
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
    7 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Video Category';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'stanford_video_categories';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/manage/videos';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Videos';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'menu-manage-content-by-type';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stanford_video_manage'] = $view;

  return $export;
}
