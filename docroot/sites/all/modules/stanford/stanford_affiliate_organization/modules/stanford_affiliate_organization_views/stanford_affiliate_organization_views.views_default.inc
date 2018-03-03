<?php
/**
 * @file
 * stanford_affiliate_organization_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_affiliate_organization_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_affiliates';
  $view->description = 'A view of Stanford Affiliate Organizations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['css_class'] = 'span12';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'span3 column';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'large-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'stanford_affiliate_organization' => 'stanford_affiliate_organization',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['stanford_affiliates'] = $view;

  $view = new view();
  $view->name = 'stanford_affiliates_grid_page';
  $view->description = 'A view of Stanford Affiliate Organizations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliates: Grid Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Affiliates';
  $handler->display->display_options['css_class'] = 'views-grid-five';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all affiliates';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'views-align-center';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliate_organization_type' => 'stanford_affiliate_organization_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
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
    'stanford_affiliate_organization' => 'stanford_affiliate_organization',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_grid');
  $handler->display->display_options['path'] = 'affiliate-organizations';

  /* Display: Page with titles */
  $handler = $view->new_display('page', 'Page with titles', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'affiliate-organizations/titles';

  /* Display: Page Grouped */
  $handler = $view->new_display('page', 'Page Grouped', 'grouped_page');
  $handler->display->display_options['display_description'] = 'Affiliates grouped by affiliation type';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_affiliate_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'views-align-center';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Affiliate Type (field_s_affiliate_type) */
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['id'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['field'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliate Type */
  $handler->display->display_options['fields']['field_s_affiliate_type']['id'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['field'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['text'] = '<h2>[field_s_affiliate_type]</h2>';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_affiliate_type']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_s_affiliate_type_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'affiliate-organizations/grouped';

  /* Display: Page Grouped with Titles */
  $handler = $view->new_display('page', 'Page Grouped with Titles', 'grouped_titles_page');
  $handler->display->display_options['display_description'] = 'Affiliates grouped by affiliation type with titles';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_affiliate_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'views-align-center';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Affiliate Type (field_s_affiliate_type) */
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['id'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['field'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliate Type */
  $handler->display->display_options['fields']['field_s_affiliate_type']['id'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['field'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['text'] = '<h2>[field_s_affiliate_type]</h2>';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_affiliate_type']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_s_affiliate_type_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'affiliate-organizations/titles/grouped';
  $export['stanford_affiliates_grid_page'] = $view;

  $view = new view();
  $view->name = 'stanford_affiliates_large_block';
  $view->description = 'A view of Stanford Affiliate Organizations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliates: Large block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Affiliates';
  $handler->display->display_options['css_class'] = 'views-grid-five';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more affiliates';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'views-align-center';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'stanford_affiliate_organization' => 'stanford_affiliate_organization',
  );

  /* Display: One Row Block */
  $handler = $view->new_display('block', 'One Row Block', 'one_row_block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more affiliates';
  $handler->display->display_options['link_url'] = 'affiliate-organizations';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: All Block */
  $handler = $view->new_display('block', 'All Block', 'all_block');

  /* Display: All Block with Titles */
  $handler = $view->new_display('block', 'All Block with Titles', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['stanford_affiliates_large_block'] = $view;

  $view = new view();
  $view->name = 'stanford_affiliates_list_page';
  $view->description = 'A list view of Stanford Affiliate Organizations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliates: List Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Affiliates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all affiliates';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'stanford_affiliate_organization_type' => 'stanford_affiliate_organization_type',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
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
    'stanford_affiliate_organization' => 'stanford_affiliate_organization',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'affiliate-organizations/list';

  /* Display: Page with titles */
  $handler = $view->new_display('page', 'Page with titles', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'affiliate-organizations/list/titles';

  /* Display: Grouped Page */
  $handler = $view->new_display('page', 'Grouped Page', 'grouped_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_affiliate_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Affiliate Type (field_s_affiliate_type) */
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['id'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['field'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliate Type */
  $handler->display->display_options['fields']['field_s_affiliate_type']['id'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['field'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['text'] = '<h2>[field_s_affiliate_type]</h2>';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_affiliate_type']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_s_affiliate_type_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'affiliate-organizations/list/grouped';

  /* Display: Grouped Page with Titles */
  $handler = $view->new_display('page', 'Grouped Page with Titles', 'grouped_titles_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_affiliate_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Affiliate Type (field_s_affiliate_type) */
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['id'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['relationships']['field_s_affiliate_type_tid']['field'] = 'field_s_affiliate_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Affiliate Type */
  $handler->display->display_options['fields']['field_s_affiliate_type']['id'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['table'] = 'field_data_field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['field'] = 'field_s_affiliate_type';
  $handler->display->display_options['fields']['field_s_affiliate_type']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['alter']['text'] = '<h2>[field_s_affiliate_type]</h2>';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_affiliate_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_affiliate_type']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_type']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_s_affiliate_type_tid';
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'affiliate-organizations/list/titles/grouped';
  $export['stanford_affiliates_list_page'] = $view;

  $view = new view();
  $view->name = 'stanford_affiliates_stacked_block';
  $view->description = 'A view of Stanford Affiliate Organizations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliates: Stacked block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Affiliates';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See more affiliates';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'views-align-center';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sorting Weight (field_s_affiliate_weight) */
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['id'] = 'field_s_affiliate_weight_value';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['table'] = 'field_data_field_s_affiliate_weight';
  $handler->display->display_options['sorts']['field_s_affiliate_weight_value']['field'] = 'field_s_affiliate_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'stanford_affiliate_organization' => 'stanford_affiliate_organization',
  );

  /* Display: Two Stacked Block */
  $handler = $view->new_display('block', 'Two Stacked Block', 'two_stacked_block');
  $handler->display->display_options['link_url'] = 'affiliate-organizations';

  /* Display: Two Stacked Block with Titles */
  $handler = $view->new_display('block', 'Two Stacked Block with Titles', 'two_stacked_block_titles');
  $handler->display->display_options['link_url'] = 'affiliate-organizations';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_affiliate_link']['id'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['table'] = 'field_data_field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['field'] = 'field_s_affiliate_link';
  $handler->display->display_options['fields']['field_s_affiliate_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_affiliate_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_affiliate_image']['id'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['table'] = 'field_data_field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['field'] = 'field_s_affiliate_image';
  $handler->display->display_options['fields']['field_s_affiliate_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['alter']['path'] = '[field_s_affiliate_link]';
  $handler->display->display_options['fields']['field_s_affiliate_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_affiliate_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_affiliate_image']['settings'] = array(
    'image_style' => 'sm-profile-scaled',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_s_affiliate_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Edit link rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Edit link rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br>
<div class="edit-link">[edit_node]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['stanford_affiliates_stacked_block'] = $view;

  return $export;
}
