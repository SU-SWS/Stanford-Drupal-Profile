<?php
/**
 * @file
 * stanford_news_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_news_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See more news';
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
  $handler->display->display_options['empty']['area']['label'] = 'News Item - No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No news items listed.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_small_square',
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
  $handler->display->display_options['fields']['field_s_news_date']['id'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['field'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories_1']['id'] = 'field_s_news_categories_1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['text'] = '<span class="descriptor"> | Posted In: </span>';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_offset'] = '0';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories']['id'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories']['delta_offset'] = '0';
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
           <div class="news-image">[field_s_image_info]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_news_date] [field_s_news_source][field_s_news_categories_1][field_s_news_categories]</div>
           <div>[body]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no news items to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Sort criterion: Content: Date (field_s_news_date) */
  $handler->display->display_options['sorts']['field_s_news_date_value']['id'] = 'field_s_news_date_value';
  $handler->display->display_options['sorts']['field_s_news_date_value']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['sorts']['field_s_news_date_value']['field'] = 'field_s_news_date_value';
  $handler->display->display_options['sorts']['field_s_news_date_value']['order'] = 'DESC';
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
    'stanford_news_item' => 'stanford_news_item',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
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
    'stanford_news_item' => 'stanford_news_item',
  );
  $handler->display->display_options['path'] = 'news.xml';
  $handler->display->display_options['displays'] = array(
    'block_5_item_news_list_with_pager' => 'block_5_item_news_list_with_pager',
    'default' => 0,
    'block_2_item_recent_news_list' => 0,
  );
  $handler->display->display_options['sitename_title'] = 1;

  /* Display: 2 Item Recent News List Block */
  $handler = $view->new_display('block', '2 Item Recent News List Block', 'block_2_item_recent_news_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['display_description'] = 'Homepage block of two items';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['link_url'] = 'news/recent-news';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_icon_square',
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
  $handler->display->display_options['fields']['field_s_news_date']['id'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['field'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories_1']['id'] = 'field_s_news_categories_1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['text'] = '<span class="descriptor"> | Posted In: </span>';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_offset'] = '0';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories']['id'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="descriptor">[field_s_news_date] [field_s_news_source]</div>
      <div class="postcard-left">

      <div class="postcard-image">
           <div class="news-image">[field_s_image_info]</div>
      </div>
      <div class="postcard-content">
           <div class="normal-link"><h3>[title]</h3></div>
      </div>

      </div>
      <div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no news items to display.';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;

  /* Display: 5 Item News List Block with Pager */
  $handler = $view->new_display('block', '5 Item News List Block with Pager', 'block_5_item_news_list_with_pager');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Recent News block for News Landing page';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_small_square',
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
  $handler->display->display_options['fields']['field_s_news_date']['id'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['field'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories_1']['id'] = 'field_s_news_categories_1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['text'] = '<span class="descriptor"> | Posted In: </span>';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_offset'] = '0';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories']['id'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
           <div class="news-image">[field_s_image_info]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_news_date] [field_s_news_source][field_s_news_categories_1][field_s_news_categories]</div>
           <div>[body]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['empty'] = 'There are no news items to display';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;

  /* Display: 5 Item News List Page with Pager */
  $handler = $view->new_display('page', '5 Item News List Page with Pager', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Contains exposed filter search for title and news categories';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'stanford_news_item' => 'stanford_news_item',
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
  /* Filter criterion: Content: Categories (field_s_news_categories) */
  $handler->display->display_options['filters']['field_s_news_categories_tid']['id'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['field'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator_id'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['identifier'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_s_news_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['vocabulary'] = 'news_categories';
  $handler->display->display_options['path'] = 'news/recent-news';
  $handler->display->display_options['menu']['title'] = 'Recent News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 3 Item News List Block with Details */
  $handler = $view->new_display('block', '3 Item News List Block with Details', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Recent News block for Home page';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news/recent-news';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_small_square',
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
  $handler->display->display_options['fields']['field_s_news_date']['id'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['field'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_date']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories_1']['id'] = 'field_s_news_categories_1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['alter']['text'] = '<span class="descriptor"> | Posted In: </span>';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_s_news_categories_1']['delta_offset'] = '0';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_s_news_categories']['id'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['field'] = 'field_s_news_categories';
  $handler->display->display_options['fields']['field_s_news_categories']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_s_news_categories']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_news_categories']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
           <div class="news-image">[field_s_image_info]</div>
      </div>

      <div class="postcard-content">
           <div><h3>[title]</h3></div>
           <div class="descriptor">[field_s_news_date] [field_s_news_source][field_s_news_categories_1][field_s_news_categories]</div>
           <div>[body]</div>
      </div>

      </div>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  $export['stanford_news'] = $view;

  return $export;
}
