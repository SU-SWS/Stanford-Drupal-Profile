<?php
/**
 * @file
 * @author [author] <[email]>
 */

function stanford_capx_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'capx_mappers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'capx_cfe';
  $view->human_name = 'Mappings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Mappings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer capx';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'machine_name' => 'machine_name',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'machine_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Configuration Entity: Configuration Settings */
  $handler->display->display_options['fields']['settings_2']['id'] = 'settings_2';
  $handler->display->display_options['fields']['settings_2']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['settings_2']['field'] = 'settings';
  $handler->display->display_options['fields']['settings_2']['label'] = 'Bundle Machine Name';
  $handler->display->display_options['fields']['settings_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['settings_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['settings_2']['format'] = 'bundle_machine';
  $handler->display->display_options['fields']['settings_2']['mapper'] = 0;
  /* Field: Configuration Entity: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  /* Field: Configuration Entity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Configuration Entity: Configuration Settings */
  $handler->display->display_options['fields']['settings']['id'] = 'settings';
  $handler->display->display_options['fields']['settings']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['settings']['field'] = 'settings';
  $handler->display->display_options['fields']['settings']['label'] = 'Entity Type';
  $handler->display->display_options['fields']['settings']['format'] = 'key';
  $handler->display->display_options['fields']['settings']['key'] = 'entity_type';
  /* Field: Configuration Entity: Configuration Settings */
  $handler->display->display_options['fields']['settings_1']['id'] = 'settings_1';
  $handler->display->display_options['fields']['settings_1']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['settings_1']['field'] = 'settings';
  $handler->display->display_options['fields']['settings_1']['label'] = 'Bundle Type';
  $handler->display->display_options['fields']['settings_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['settings_1']['alter']['text'] = '[settings_1] ([settings_2])';
  $handler->display->display_options['fields']['settings_1']['format'] = 'bundle_title';
  $handler->display->display_options['fields']['settings_1']['key'] = 'bundle_type';
  $handler->display->display_options['fields']['settings_1']['mapper'] = 0;
  /* Field: Configuration Entity: Mapping delete link */
  $handler->display->display_options['fields']['mapper_delete_link']['id'] = 'mapper_delete_link';
  $handler->display->display_options['fields']['mapper_delete_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['mapper_delete_link']['field'] = 'mapper_delete_link';
  $handler->display->display_options['fields']['mapper_delete_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mapper_delete_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mapper_delete_link']['alter']['text'] = '| [mapper_delete_link] ';
  $handler->display->display_options['fields']['mapper_delete_link']['text'] = 'Delete';
  /* Field: Configuration Entity: Mapping edit link */
  $handler->display->display_options['fields']['mapper_edit_link']['id'] = 'mapper_edit_link';
  $handler->display->display_options['fields']['mapper_edit_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['mapper_edit_link']['field'] = 'mapper_edit_link';
  $handler->display->display_options['fields']['mapper_edit_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mapper_edit_link']['text'] = 'Edit';
  /* Field: Configuration Entity: Export Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Configuration Entity: Mapping export link */
  $handler->display->display_options['fields']['mapper_export_link']['id'] = 'mapper_export_link';
  $handler->display->display_options['fields']['mapper_export_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['mapper_export_link']['field'] = 'mapper_export_link';
  $handler->display->display_options['fields']['mapper_export_link']['label'] = '';
  $handler->display->display_options['fields']['mapper_export_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mapper_export_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mapper_export_link']['alter']['text'] = '| [mapper_export_link] ';
  $handler->display->display_options['fields']['mapper_export_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mapper_export_link']['text'] = 'Export';
  /* Field: Configuration Entity: Mapping revert link */
  $handler->display->display_options['fields']['mapper_revert_link']['id'] = 'mapper_revert_link';
  $handler->display->display_options['fields']['mapper_revert_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['mapper_revert_link']['field'] = 'mapper_revert_link';
  $handler->display->display_options['fields']['mapper_revert_link']['label'] = '';
  $handler->display->display_options['fields']['mapper_revert_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mapper_revert_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mapper_revert_link']['alter']['text'] = '| [mapper_revert_link] ';
  $handler->display->display_options['fields']['mapper_revert_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mapper_revert_link']['text'] = 'Revert';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[mapper_edit_link] [mapper_export_link][mapper_revert_link][mapper_delete_link] ';
  /* Sort criterion: Configuration Entity: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'capx_cfe';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Configuration Entity: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'capx_cfe';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Configuration Entity: type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'capx_cfe';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'mapper';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'mappers_manage_block');
  $handler->display->display_options['block_description'] = 'Manage Mappings Table';

  // Add view to return array.
  $views['capx_mappers'] = $view;

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  // Importers
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  $view = new view();
  $view->name = 'capx_importers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'capx_cfe';
  $view->human_name = 'Importers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Importers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer capx';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'machine_name' => 'machine_name',
    'title' => 'title',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'nothing_2' => 'nothing_2',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'machine_name' => array(
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
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Configuration Entity: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  /* Field: Configuration Entity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/config/capx/importer/edit/[machine_name]';
  /* Field: Configuration Entity: Configuration Settings */
  $handler->display->display_options['fields']['settings']['id'] = 'settings';
  $handler->display->display_options['fields']['settings']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['settings']['field'] = 'settings';
  $handler->display->display_options['fields']['settings']['label'] = 'Mapping Name';
  $handler->display->display_options['fields']['settings']['format'] = 'mapper';
  $handler->display->display_options['fields']['settings']['mapper'] = 0;
  /* Field: Configuration Entity: Meta Data */
  $handler->display->display_options['fields']['meta']['id'] = 'meta';
  $handler->display->display_options['fields']['meta']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['meta']['field'] = 'meta';
  $handler->display->display_options['fields']['meta']['label'] = 'Number of profiles';
  $handler->display->display_options['fields']['meta']['format'] = 'count';
  $handler->display->display_options['fields']['meta']['key'] = 'count';
  $handler->display->display_options['fields']['meta']['timestamp'] = 0;
  /* Field: Configuration Entity: Meta Data */
  $handler->display->display_options['fields']['meta_1']['id'] = 'meta_1';
  $handler->display->display_options['fields']['meta_1']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['meta_1']['field'] = 'meta';
  $handler->display->display_options['fields']['meta_1']['label'] = 'Last Update';
  $handler->display->display_options['fields']['meta_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['meta_1']['format'] = 'lastUpdateHuman';
  $handler->display->display_options['fields']['meta_1']['key'] = 'lastUpdateHuman';
  $handler->display->display_options['fields']['meta_1']['timestamp'] = 0;
  /* Field: Configuration Entity: Importer delete link */
  $handler->display->display_options['fields']['importer_delete_link']['id'] = 'importer_delete_link';
  $handler->display->display_options['fields']['importer_delete_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['importer_delete_link']['field'] = 'importer_delete_link';
  $handler->display->display_options['fields']['importer_delete_link']['label'] = '';
  $handler->display->display_options['fields']['importer_delete_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['importer_delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['importer_delete_link']['text'] = 'Delete';
  /* Field: Configuration Entity: Importer edit link */
  $handler->display->display_options['fields']['importer_edit_link']['id'] = 'importer_edit_link';
  $handler->display->display_options['fields']['importer_edit_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['importer_edit_link']['field'] = 'importer_edit_link';
  $handler->display->display_options['fields']['importer_edit_link']['label'] = '';
  $handler->display->display_options['fields']['importer_edit_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['importer_edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['importer_edit_link']['text'] = 'Edit';
  /* Field: Configuration Entity: Importer orphan profiles action link */
  $handler->display->display_options['fields']['importer_orphan_profiles']['id'] = 'importer_orphan_profiles';
  $handler->display->display_options['fields']['importer_orphan_profiles']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['importer_orphan_profiles']['field'] = 'importer_orphan_profiles';
  $handler->display->display_options['fields']['importer_orphan_profiles']['label'] = '';
  $handler->display->display_options['fields']['importer_orphan_profiles']['exclude'] = TRUE;
  $handler->display->display_options['fields']['importer_orphan_profiles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['importer_orphan_profiles']['text'] = 'Check for orphans';
  /* Field: Configuration Entity: Importer sync profiles action link */
  $handler->display->display_options['fields']['importer_sync_profiles']['id'] = 'importer_sync_profiles';
  $handler->display->display_options['fields']['importer_sync_profiles']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['importer_sync_profiles']['field'] = 'importer_sync_profiles';
  $handler->display->display_options['fields']['importer_sync_profiles']['label'] = '';
  $handler->display->display_options['fields']['importer_sync_profiles']['exclude'] = TRUE;
  $handler->display->display_options['fields']['importer_sync_profiles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['importer_sync_profiles']['text'] = 'Update profiles now';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[importer_edit_link] | [importer_delete_link] | [importer_sync_profiles] | [importer_orphan_profiles]';
  /* Filter criterion: Configuration Entity: type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'capx_cfe';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'importer';

  /* Display: Importer Manage Block */
  $handler = $view->new_display('block', 'Importer Manage Block', 'importer_manage_block');
  $views['capx_importers'] = $view;

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  $view = new view();
  $view->name = 'importers_overview_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'capx_cfe';
  $view->human_name = 'Importers - Overview page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Importers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer capx';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'machine_name' => 'machine_name',
    'title' => 'title',
    'settings' => 'settings',
    'meta_1' => 'meta_1',
    'meta' => 'meta',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'machine_name' => array(
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
      'separator' => '',
      'empty_column' => 0,
    ),
    'settings' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'meta_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'meta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Configuration Entity: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = '';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  /* Field: Configuration Entity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/config/capx/importer/edit/[machine_name]';
  /* Field: Configuration Entity: Configuration Settings */
  $handler->display->display_options['fields']['settings']['id'] = 'settings';
  $handler->display->display_options['fields']['settings']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['settings']['field'] = 'settings';
  $handler->display->display_options['fields']['settings']['label'] = 'Mapping';
  $handler->display->display_options['fields']['settings']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['settings']['alter']['path'] = 'admin/config/capx/mapper/edit/[settings]';
  $handler->display->display_options['fields']['settings']['format'] = 'mapper';
  $handler->display->display_options['fields']['settings']['key'] = 'mapper';
  $handler->display->display_options['fields']['settings']['mapper'] = 0;
  /* Field: Configuration Entity: Meta Data */
  $handler->display->display_options['fields']['meta_1']['id'] = 'meta_1';
  $handler->display->display_options['fields']['meta_1']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['meta_1']['field'] = 'meta';
  $handler->display->display_options['fields']['meta_1']['label'] = 'Number of profiles';
  $handler->display->display_options['fields']['meta_1']['format'] = 'count';
  $handler->display->display_options['fields']['meta_1']['key'] = 'count';
  $handler->display->display_options['fields']['meta_1']['timestamp'] = 0;
  /* Field: Configuration Entity: Meta Data */
  $handler->display->display_options['fields']['meta']['id'] = 'meta';
  $handler->display->display_options['fields']['meta']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['meta']['field'] = 'meta';
  $handler->display->display_options['fields']['meta']['label'] = 'Last Update';
  $handler->display->display_options['fields']['meta']['format'] = 'lastUpdateHuman';
  $handler->display->display_options['fields']['meta']['key'] = 'lastUpdateHuman';
  $handler->display->display_options['fields']['meta']['timestamp'] = 0;
  /* Field: Configuration Entity: Importer sync profiles action link */
  $handler->display->display_options['fields']['importer_sync_profiles']['id'] = 'importer_sync_profiles';
  $handler->display->display_options['fields']['importer_sync_profiles']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['importer_sync_profiles']['field'] = 'importer_sync_profiles';
  $handler->display->display_options['fields']['importer_sync_profiles']['exclude'] = TRUE;
  $handler->display->display_options['fields']['importer_sync_profiles']['text'] = 'Update profiles now';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[importer_sync_profiles]';
  /* Sort criterion: Configuration Entity: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'capx_cfe';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Configuration Entity: type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'capx_cfe';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'importer';

  /* Display: Importer Overview */
  $handler = $view->new_display('block', 'Importer Overview', 'importers_overview');
  $handler->display->display_options['display_description'] = 'Importer Overview';
  $handler->display->display_options['block_description'] = 'Importer Overview Block';

  $views['importers_overview_page'] = $view;

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  $view = new view();
  $view->name = 'capx_admin_profiles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'capx_profiles';
  $view->human_name = 'Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer capx';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100, 250, 500';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'delta' => 'delta',
    'name' => 'title',
    'title_1' => 'title',
    'title' => 'title',
    'entity_type' => 'entity_type',
    'bundle_type' => 'bundle_type',
    'importer_1' => 'importer_1',
    'sync' => 'sync',
    'last_sync' => 'last_sync',
    'orphaned' => 'orphaned',
    'edit_link' => 'edit_link',
    'edit_node' => 'edit_node',
    'edit_node_1' => 'edit_node_1',
    'profile_id' => 'profile_id',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'delta' => array(
      'sortable' => 0,
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
    'title_1' => array(
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
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'bundle_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'importer_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sync' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_sync' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'orphaned' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'profile_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Sorry, but there are no profiles available. Please create a mapping and an importer to import profiles.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: CAPx profile: CAPx Profile Node Information */
  $handler->display->display_options['relationships']['node']['id'] = 'node';
  $handler->display->display_options['relationships']['node']['table'] = 'capx_profiles';
  $handler->display->display_options['relationships']['node']['field'] = 'node';
  if (module_exists("bean")) {
    /* Relationship: CAPx profile: CAPx Profile BEAN Information */
    $handler->display->display_options['relationships']['bean']['id'] = 'bean';
    $handler->display->display_options['relationships']['bean']['table'] = 'capx_profiles';
    $handler->display->display_options['relationships']['bean']['field'] = 'bean';
  }
  /* Relationship: CAPx profile: CAPx Profile User Information */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'capx_profiles';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  if (module_exists("bean")) {
    /* Field: Block: Block Delta */
    $handler->display->display_options['fields']['delta']['id'] = 'delta';
    $handler->display->display_options['fields']['delta']['table'] = 'bean';
    $handler->display->display_options['fields']['delta']['field'] = 'delta';
    $handler->display->display_options['fields']['delta']['relationship'] = 'bean';
    $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  }
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = TRUE;
  $handler->display->display_options['fields']['name']['anonymous_text'] = ' ';
  if (module_exists("bean")) {
    /* Field: Block: Title */
    $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
    $handler->display->display_options['fields']['title_1']['table'] = 'bean';
    $handler->display->display_options['fields']['title_1']['field'] = 'title';
    $handler->display->display_options['fields']['title_1']['relationship'] = 'bean';
    $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['title_1']['alter']['path'] = 'block/[delta]/edit';
  }
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'node';
  /* Field: CAPx profile: Entity Type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  /* Field: CAPx profile: Bundle Type */
  $handler->display->display_options['fields']['bundle_type']['id'] = 'bundle_type';
  $handler->display->display_options['fields']['bundle_type']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['bundle_type']['field'] = 'bundle_type';
  /* Field: CAPx profile: Importer */
  $handler->display->display_options['fields']['importer_1']['id'] = 'importer_1';
  $handler->display->display_options['fields']['importer_1']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['importer_1']['field'] = 'importer';
  $handler->display->display_options['fields']['importer_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['importer_1']['alter']['path'] = 'admin/config/capx/importer/edit/[importer_1]';
  /* Field: CAPx profile: Sync Status */
  $handler->display->display_options['fields']['sync']['id'] = 'sync';
  $handler->display->display_options['fields']['sync']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['sync']['field'] = 'sync';
  $handler->display->display_options['fields']['sync']['not'] = 0;
  /* Field: CAPx profile: Last Sync */
  $handler->display->display_options['fields']['last_sync']['id'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['last_sync']['field'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['last_sync']['second_date_format'] = 'long';
  /* Field: CAPx profile: Orphaned Status */
  $handler->display->display_options['fields']['orphaned']['id'] = 'orphaned';
  $handler->display->display_options['fields']['orphaned']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['orphaned']['field'] = 'orphaned';
  $handler->display->display_options['fields']['orphaned']['label'] = 'Orphan';
  $handler->display->display_options['fields']['orphaned']['not'] = 0;
  if (module_exists("bean")) {
    /* Field: Block: Edit link */
    $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
    $handler->display->display_options['fields']['edit_link']['table'] = 'bean';
    $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
    $handler->display->display_options['fields']['edit_link']['relationship'] = 'bean';
    $handler->display->display_options['fields']['edit_link']['exclude'] = TRUE;
    $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  }
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['relationship'] = 'user';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'Edit';
  /* Field: CAPx profile: Profile ID */
  $handler->display->display_options['fields']['profile_id']['id'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['table'] = 'capx_profiles';
  $handler->display->display_options['fields']['profile_id']['field'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['label'] = 'View cap profile link';
  $handler->display->display_options['fields']['profile_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['profile_id']['text'] = 'View on CAP';
  $handler->display->display_options['fields']['profile_id']['link_to_cap'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]';
  if (module_exists("bean")) {
    $handler->display->display_options['fields']['nothing']['alter']['text'] .= "[edit_link]";
  }
  $handler->display->display_options['fields']['nothing']['alter']['text'] .= "[edit_node_1] | [profile_id]";
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'title_1' => 'title_1',
    'title' => 'title',
  );
  /* Filter criterion: CAPx profile: Entity Type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'capx_profiles';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  $handler->display->display_options['filters']['entity_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Entity Type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: CAPx profile: Bundle Type */
  $handler->display->display_options['filters']['bundle_type']['id'] = 'bundle_type';
  $handler->display->display_options['filters']['bundle_type']['table'] = 'capx_profiles';
  $handler->display->display_options['filters']['bundle_type']['field'] = 'bundle_type';
  $handler->display->display_options['filters']['bundle_type']['group'] = 1;
  $handler->display->display_options['filters']['bundle_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_type']['expose']['operator_id'] = 'bundle_type_op';
  $handler->display->display_options['filters']['bundle_type']['expose']['label'] = 'Bundle Type';
  $handler->display->display_options['filters']['bundle_type']['expose']['operator'] = 'bundle_type_op';
  $handler->display->display_options['filters']['bundle_type']['expose']['identifier'] = 'bundle_type';
  $handler->display->display_options['filters']['bundle_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: CAPx profile: Importer */
  $handler->display->display_options['filters']['importer']['id'] = 'importer';
  $handler->display->display_options['filters']['importer']['table'] = 'capx_profiles';
  $handler->display->display_options['filters']['importer']['field'] = 'importer';
  $handler->display->display_options['filters']['importer']['group'] = 1;
  $handler->display->display_options['filters']['importer']['exposed'] = TRUE;
  $handler->display->display_options['filters']['importer']['expose']['operator_id'] = 'importer_op';
  $handler->display->display_options['filters']['importer']['expose']['label'] = 'Importer';
  $handler->display->display_options['filters']['importer']['expose']['operator'] = 'importer_op';
  $handler->display->display_options['filters']['importer']['expose']['identifier'] = 'importer';
  $handler->display->display_options['filters']['importer']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: CAPx profile: Orphaned Status */
  $handler->display->display_options['filters']['orphaned']['id'] = 'orphaned';
  $handler->display->display_options['filters']['orphaned']['table'] = 'capx_profiles';
  $handler->display->display_options['filters']['orphaned']['field'] = 'orphaned';
  $handler->display->display_options['filters']['orphaned']['value'] = '0';
  $handler->display->display_options['filters']['orphaned']['exposed'] = TRUE;
  $handler->display->display_options['filters']['orphaned']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['orphaned']['expose']['label'] = 'Orphan';
  $handler->display->display_options['filters']['orphaned']['expose']['operator'] = 'orphaned_op';
  $handler->display->display_options['filters']['orphaned']['expose']['identifier'] = 'orphaned';
  $handler->display->display_options['filters']['orphaned']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Profiles */
  $handler = $view->new_display('page', 'Profiles', 'profiles');
  $handler->display->display_options['path'] = 'admin/config/capx/profiles';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Profiles';
  $handler->display->display_options['menu']['description'] = 'CAPx Profiles';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['capx_admin_profiles'] = $view;

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  return $views;
}
