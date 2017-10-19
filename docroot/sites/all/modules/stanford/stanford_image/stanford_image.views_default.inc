<?php
/**
 * @file
 * stanford_image.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_image_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_bulk_fc_image_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Bulk Image Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bulk Image Operations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'url' => 'url',
    'counter' => 'counter',
    'field_s_image_image' => 'field_s_image_image',
    'title' => 'title',
    'timestamp' => 'title',
    'label' => 'label',
    'status' => 'status',
    'field_s_image_caption' => 'field_s_image_caption',
    'field_s_image_credits' => 'field_s_image_credits',
    'created' => 'created',
    'item_id' => 'item_id',
    'nothing' => 'item_id',
  );
  $handler->display->display_options['style_options']['default'] = 'field_s_image_credits';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_image_image' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
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
    'field_s_image_caption' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_image_credits' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Field collection item: Entity with the Featured Image (field_s_image_info) */
  $handler->display->display_options['relationships']['field_s_image_info_node']['id'] = 'field_s_image_info_node';
  $handler->display->display_options['relationships']['field_s_image_info_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_s_image_info_node']['field'] = 'field_s_image_info_node';
  $handler->display->display_options['relationships']['field_s_image_info_node']['label'] = 'Content using Image';
  /* Field: Bulk operations: Field collection item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_field_collection_item';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'file',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_s_image_info_node';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'field_s_image_info_node';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'field_s_image_info_node';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  /* Field: Field collection item: Credits */
  $handler->display->display_options['fields']['field_s_image_credits']['id'] = 'field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['table'] = 'field_data_field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['field'] = 'field_s_image_credits';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'field_s_image_info_node';
  $handler->display->display_options['fields']['created']['date_format'] = 'stanford_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'stanford_time';
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[url]/edit';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Filter criterion: Field collection item: Image (field_s_image_image:width) */
  $handler->display->display_options['filters']['field_s_image_image_width']['id'] = 'field_s_image_image_width';
  $handler->display->display_options['filters']['field_s_image_image_width']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['filters']['field_s_image_image_width']['field'] = 'field_s_image_image_width';
  $handler->display->display_options['filters']['field_s_image_image_width']['operator'] = '!=';
  $handler->display->display_options['filters']['field_s_image_image_width']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/stanford/images';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['stanford_bulk_fc_image_administration'] = $view;

  $view = new view();
  $view->name = 'stanford_image_credits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Image Credits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Image Credits';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_s_image_image' => 'field_s_image_image',
    'field_s_image_caption' => 'field_s_image_caption',
    'field_s_image_credits' => 'field_s_image_credits',
    'url' => 'url',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'field_s_image_credits';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_image_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_image_caption' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_s_image_credits' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'file',
  );
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['hide_empty'] = TRUE;
  /* Field: Field collection item: Credits */
  $handler->display->display_options['fields']['field_s_image_credits']['id'] = 'field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['table'] = 'field_data_field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['field'] = 'field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_s_image_credits']['hide_empty'] = TRUE;
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_field_collection_item';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Filter criterion: Field collection item: Image (field_s_image_image:width) */
  $handler->display->display_options['filters']['field_s_image_image_width']['id'] = 'field_s_image_image_width';
  $handler->display->display_options['filters']['field_s_image_image_width']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['filters']['field_s_image_image_width']['field'] = 'field_s_image_image_width';
  $handler->display->display_options['filters']['field_s_image_image_width']['operator'] = '>';
  $handler->display->display_options['filters']['field_s_image_image_width']['value']['value'] = '0';
  /* Filter criterion: Field collection item: Caption (field_s_image_caption) */
  $handler->display->display_options['filters']['field_s_image_caption_value']['id'] = 'field_s_image_caption_value';
  $handler->display->display_options['filters']['field_s_image_caption_value']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['filters']['field_s_image_caption_value']['field'] = 'field_s_image_caption_value';
  $handler->display->display_options['filters']['field_s_image_caption_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_s_image_caption_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_image_caption_value']['expose']['operator_id'] = 'field_s_image_caption_value_op';
  $handler->display->display_options['filters']['field_s_image_caption_value']['expose']['label'] = 'Filter by Caption';
  $handler->display->display_options['filters']['field_s_image_caption_value']['expose']['operator'] = 'field_s_image_caption_value_op';
  $handler->display->display_options['filters']['field_s_image_caption_value']['expose']['identifier'] = 'field_s_image_caption_value';
  /* Filter criterion: Field collection item: Credits (field_s_image_credits) */
  $handler->display->display_options['filters']['field_s_image_credits_value']['id'] = 'field_s_image_credits_value';
  $handler->display->display_options['filters']['field_s_image_credits_value']['table'] = 'field_data_field_s_image_credits';
  $handler->display->display_options['filters']['field_s_image_credits_value']['field'] = 'field_s_image_credits_value';
  $handler->display->display_options['filters']['field_s_image_credits_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_s_image_credits_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_image_credits_value']['expose']['operator_id'] = 'field_s_image_credits_value_op';
  $handler->display->display_options['filters']['field_s_image_credits_value']['expose']['label'] = 'Filter by Credits';
  $handler->display->display_options['filters']['field_s_image_credits_value']['expose']['operator'] = 'field_s_image_credits_value_op';
  $handler->display->display_options['filters']['field_s_image_credits_value']['expose']['identifier'] = 'field_s_image_credits_value';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'images';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $export['stanford_image_credits'] = $view;

  return $export;
}
