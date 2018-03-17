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
  $view->name = 'admin_manage_stanford_news_item';
  $view->description = 'View, edit, and delete your site\'s content.';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'News: Manage';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Announcement/News Item Content';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
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
    'field_s_news_date' => 'field_s_news_date',
    'field_s_news_source' => 'field_s_news_source',
    'term_node_tid' => 'term_node_tid',
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
    'field_s_news_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_s_news_source' => array(
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'tags' => 0,
  );
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
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Stick',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unstick',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Modify News Categories',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'stanford_news_item::field_s_news_categories' => 'stanford_news_item::field_s_news_categories',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Promote to front page',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
      'postpone_processing' => 0,
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Demote from front page',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_thumbnail_square',
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
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_s_news_date']['id'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['field'] = 'field_s_news_date';
  $handler->display->display_options['fields']['field_s_news_date']['label'] = 'News Date';
  $handler->display->display_options['fields']['field_s_news_date']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  /* Field: Content: News Type */
  $handler->display->display_options['fields']['field_s_news_type']['id'] = 'field_s_news_type';
  $handler->display->display_options['fields']['field_s_news_type']['table'] = 'field_data_field_s_news_type';
  $handler->display->display_options['fields']['field_s_news_type']['field'] = 'field_s_news_type';
  $handler->display->display_options['fields']['field_s_news_type']['settings'] = array(
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
  $handler->display->display_options['fields']['field_s_news_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_s_news_type']['multi_type'] = 'ul';
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
  $handler->display->display_options['filters']['title']['group'] = 1;
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
  $handler->display->display_options['filters']['status']['group'] = 1;
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
    'stanford_news_item' => 'stanford_news_item',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: News Type (field_s_news_type) */
  $handler->display->display_options['filters']['field_s_news_type_value']['id'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['table'] = 'field_data_field_s_news_type';
  $handler->display->display_options['filters']['field_s_news_type_value']['field'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_s_news_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_news_type_value']['expose']['operator_id'] = 'field_s_news_type_value_op';
  $handler->display->display_options['filters']['field_s_news_type_value']['expose']['label'] = 'Announcement/News Type';
  $handler->display->display_options['filters']['field_s_news_type_value']['expose']['operator'] = 'field_s_news_type_value_op';
  $handler->display->display_options['filters']['field_s_news_type_value']['expose']['identifier'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['expose']['remember_roles'] = array(
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
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/manage/stanford_news_item';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Announcements/News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-content-by-type';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_manage_stanford_news_item'] = $view;

  $view = new view();
  $view->name = 'news_external_source';
  $view->description = 'View block with link to external URL source link.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News: External Source';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = 'View original news article';
  $handler->display->display_options['fields']['field_s_news_source']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['path'] = '[field_s_news_source-url]';
  $handler->display->display_options['fields']['field_s_news_source']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['link_class'] = 'btn';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_news_source']['settings'] = array(
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: This this an external news article (field_s_news_external) */
  $handler->display->display_options['filters']['field_s_news_external_value']['id'] = 'field_s_news_external_value';
  $handler->display->display_options['filters']['field_s_news_external_value']['table'] = 'field_data_field_s_news_external';
  $handler->display->display_options['filters']['field_s_news_external_value']['field'] = 'field_s_news_external_value';
  $handler->display->display_options['filters']['field_s_news_external_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['news_external_source'] = $view;

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
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See more announcements';
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
  $handler->display->display_options['empty']['area']['content'] = 'See all announcements and news in the archive.';
  $handler->display->display_options['empty']['area']['format'] = 'content_editor_text_format';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_news_source']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_s_news_source']['settings'] = array(
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
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_small_square',
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
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['fields']['field_s_news_source_1']['id'] = 'field_s_news_source_1';
  $handler->display->display_options['fields']['field_s_news_source_1']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source_1']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source_1']['alter']['text'] = '| [field_s_news_source_1]';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_news_source_1']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_s_news_source_1']['settings'] = array(
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
           <div class="descriptor">[field_s_news_date]</div>
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
  $handler->display->display_options['title'] = 'Announcements & News';
  $handler->display->display_options['display_description'] = 'Homepage block of two items';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news/announcements';
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
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_s_news_source']['id'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['text'] = '| [field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['field_s_news_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_news_source']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_s_news_source']['settings'] = array(
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
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_s_image_info']['id'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['field'] = 'field_s_image_info';
  $handler->display->display_options['fields']['field_s_image_info']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_info']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['field_s_image_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_info']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'stanford_icon_square',
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
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_s_news_source]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['fields']['field_s_news_source_1']['id'] = 'field_s_news_source_1';
  $handler->display->display_options['fields']['field_s_news_source_1']['table'] = 'field_data_field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source_1']['field'] = 'field_s_news_source';
  $handler->display->display_options['fields']['field_s_news_source_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_news_source_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_news_source_1']['alter']['text'] = '| [field_s_news_source_1]';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_wrapper_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_news_source_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_news_source_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_news_source_1']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_s_news_source_1']['settings'] = array(
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="descriptor">[field_s_news_date]</div>
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
  /* Filter criterion: Content: Date (field_s_news_date) */
  $handler->display->display_options['filters']['field_s_news_date_value']['id'] = 'field_s_news_date_value';
  $handler->display->display_options['filters']['field_s_news_date_value']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['filters']['field_s_news_date_value']['field'] = 'field_s_news_date_value';
  $handler->display->display_options['filters']['field_s_news_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_s_news_date_value']['default_date'] = 'now -31 day';

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

  /* Display: 5 Item News List Page with Pager */
  $handler = $view->new_display('page', '5 Item News List Page with Pager', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In the News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Contains exposed filter search for title and news categories';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more announcements';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: News Type (field_s_news_type) */
  $handler->display->display_options['filters']['field_s_news_type_value']['id'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['table'] = 'field_data_field_s_news_type';
  $handler->display->display_options['filters']['field_s_news_type_value']['field'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['value'] = array(
    'news' => 'news',
  );
  $handler->display->display_options['filters']['field_s_news_type_value']['group'] = 1;
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
  /* Filter criterion: Content: Categories (field_s_news_categories) */
  $handler->display->display_options['filters']['field_s_news_categories_tid']['id'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['field'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_news_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator_id'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['identifier'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_s_news_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['vocabulary'] = 'news_categories';
  $handler->display->display_options['path'] = 'news/in-the-news';
  $handler->display->display_options['menu']['title'] = 'Recent News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 3 Item News List Block with Details */
  $handler = $view->new_display('block', '3 Item News List Block with Details', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Announcements & News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Recent News block for Home page';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news/announcements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  /* Filter criterion: Content: Date (field_s_news_date) */
  $handler->display->display_options['filters']['field_s_news_date_value']['id'] = 'field_s_news_date_value';
  $handler->display->display_options['filters']['field_s_news_date_value']['table'] = 'field_data_field_s_news_date';
  $handler->display->display_options['filters']['field_s_news_date_value']['field'] = 'field_s_news_date_value';
  $handler->display->display_options['filters']['field_s_news_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_s_news_date_value']['default_date'] = 'now -31 day';

  /* Display: 5 Item Announcements List Page with Pager */
  $handler = $view->new_display('page', '5 Item Announcements List Page with Pager', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Announcements';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-row-lines';
  $handler->display->display_options['display_description'] = 'Contains exposed filter search for title and news categories';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more announcements';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: News Type (field_s_news_type) */
  $handler->display->display_options['filters']['field_s_news_type_value']['id'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['table'] = 'field_data_field_s_news_type';
  $handler->display->display_options['filters']['field_s_news_type_value']['field'] = 'field_s_news_type_value';
  $handler->display->display_options['filters']['field_s_news_type_value']['value'] = array(
    'announcements' => 'announcements',
  );
  $handler->display->display_options['filters']['field_s_news_type_value']['group'] = 1;
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
  /* Filter criterion: Content: Categories (field_s_news_categories) */
  $handler->display->display_options['filters']['field_s_news_categories_tid']['id'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['table'] = 'field_data_field_s_news_categories';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['field'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_news_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator_id'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['operator'] = 'field_s_news_categories_tid_op';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['identifier'] = 'field_s_news_categories_tid';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_s_news_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_news_categories_tid']['vocabulary'] = 'news_categories';
  $handler->display->display_options['path'] = 'news/announcements';
  $handler->display->display_options['menu']['title'] = 'Recent News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stanford_news'] = $view;

  return $export;
}
