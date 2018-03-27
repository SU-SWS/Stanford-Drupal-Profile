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
  $view->name = 'stanford_web_video_manage';
  $view->description = 'View, edit, and delete your site\'s content.';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Web Video: Manage';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Stanford Web Video Content';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_s_image_info' => 'field_s_image_info',
    'title' => 'title',
    'timestamp' => 'title',
    'changed' => 'changed',
    'status' => 'status',
    'term_node_tid' => 'term_node_tid',
    'field_s_slide_featured' => 'field_s_slide_featured',
    'field_s_slide_weight' => 'field_s_slide_weight',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
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
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_slide_featured' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_slide_weight' => array(
      'sortable' => 1,
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
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
    ),
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
        'display_values' => array(),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Row';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_video_poster']['id'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['table'] = 'field_data_field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['field'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_poster']['settings'] = array(
    'image_style' => 'thmb-square',
    'image_link' => '',
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
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = ' New';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'NID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] |';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[view_node] |';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'edit-link';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = ' View';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = ' Delete';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'stanford_video' => 'stanford_video',
  );
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
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/manage/stanford_web_video';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Videos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-content-by-type';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stanford_web_video_manage'] = $view;

  $view = new view();
  $view->name = 'stanford_web_videos';
  $view->description = 'A simple View showing all Stanford Web Video nodes on your site';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Web Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford Web Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Account Name */
  $handler->display->display_options['fields']['field_stanford_video_account']['id'] = 'field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['table'] = 'field_data_field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['field'] = 'field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_account']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_account']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Caption File */
  $handler->display->display_options['fields']['field_stanford_video_caption']['id'] = 'field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['table'] = 'field_data_field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['field'] = 'field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_caption']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_caption']['settings'] = array(
    'jwplayer_preset' => 'stanford_video',
  );
  /* Field: Content: File Name */
  $handler->display->display_options['fields']['field_stanford_video_filename']['id'] = 'field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['table'] = 'field_data_field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['field'] = 'field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_filename']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_filename']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_video_poster']['id'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['table'] = 'field_data_field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['field'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_poster']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_poster']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_poster']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_poster']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Streaming Server */
  $handler->display->display_options['fields']['field_stanford_video_server']['id'] = 'field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['table'] = 'field_data_field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['field'] = 'field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_server']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_server']['element_label_colon'] = FALSE;
  /* Field: Content: External Video Embed */
  $handler->display->display_options['fields']['field_stanford_video_external']['id'] = 'field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['table'] = 'field_data_field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['field'] = 'field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_external']['element_label_colon'] = FALSE;
  /* Field: Content: Video File */
  $handler->display->display_options['fields']['field_stanford_video_file']['id'] = 'field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['table'] = 'field_data_field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['field'] = 'field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_file']['type'] = 'stanford_video';
  $handler->display->display_options['fields']['field_stanford_video_file']['settings'] = array(
    'jwplayer_preset' => 'stanford_web_video_640_480',
  );
  /* Field: Content: Video Link */
  $handler->display->display_options['fields']['field_stanford_video_link']['id'] = 'field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['table'] = 'field_data_field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['field'] = 'field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stanford_video_link']['type'] = 'stanford_video';
  $handler->display->display_options['fields']['field_stanford_video_link']['settings'] = array(
    'jwplayer_preset' => 'stanford_web_video_640_480',
  );
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_video' => 'stanford_video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'stanford-web-videos';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'stanford-web-videos.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Recent Video';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Account Name */
  $handler->display->display_options['fields']['field_stanford_video_account']['id'] = 'field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['table'] = 'field_data_field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['field'] = 'field_stanford_video_account';
  $handler->display->display_options['fields']['field_stanford_video_account']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_account']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_account']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Caption File */
  $handler->display->display_options['fields']['field_stanford_video_caption']['id'] = 'field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['table'] = 'field_data_field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['field'] = 'field_stanford_video_caption';
  $handler->display->display_options['fields']['field_stanford_video_caption']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_caption']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_caption']['settings'] = array(
    'jwplayer_preset' => 'stanford_video',
  );
  /* Field: Content: File Name */
  $handler->display->display_options['fields']['field_stanford_video_filename']['id'] = 'field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['table'] = 'field_data_field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['field'] = 'field_stanford_video_filename';
  $handler->display->display_options['fields']['field_stanford_video_filename']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_filename']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_filename']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stanford_video_poster']['id'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['table'] = 'field_data_field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['field'] = 'field_stanford_video_poster';
  $handler->display->display_options['fields']['field_stanford_video_poster']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_poster']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_poster']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_poster']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_poster']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Streaming Server */
  $handler->display->display_options['fields']['field_stanford_video_server']['id'] = 'field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['table'] = 'field_data_field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['field'] = 'field_stanford_video_server';
  $handler->display->display_options['fields']['field_stanford_video_server']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_server']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stanford_video_server']['element_label_colon'] = FALSE;
  /* Field: Content: External Video Embed */
  $handler->display->display_options['fields']['field_stanford_video_external']['id'] = 'field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['table'] = 'field_data_field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['field'] = 'field_stanford_video_external';
  $handler->display->display_options['fields']['field_stanford_video_external']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_external']['element_label_colon'] = FALSE;
  /* Field: Content: Video File */
  $handler->display->display_options['fields']['field_stanford_video_file']['id'] = 'field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['table'] = 'field_data_field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['field'] = 'field_stanford_video_file';
  $handler->display->display_options['fields']['field_stanford_video_file']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stanford_video_file']['type'] = 'stanford_video';
  $handler->display->display_options['fields']['field_stanford_video_file']['settings'] = array(
    'jwplayer_preset' => 'stanford_web_video_320_240',
  );
  /* Field: Content: Video Link */
  $handler->display->display_options['fields']['field_stanford_video_link']['id'] = 'field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['table'] = 'field_data_field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['field'] = 'field_stanford_video_link';
  $handler->display->display_options['fields']['field_stanford_video_link']['label'] = '';
  $handler->display->display_options['fields']['field_stanford_video_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stanford_video_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stanford_video_link']['type'] = 'stanford_video';
  $handler->display->display_options['fields']['field_stanford_video_link']['settings'] = array(
    'jwplayer_preset' => 'stanford_web_video_320_240',
  );
  $export['stanford_web_videos'] = $view;

  return $export;
}
