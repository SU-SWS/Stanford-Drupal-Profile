<?php
/**
 * @file
 * stanford_carousel.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_carousel_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'carousel slide';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="offscreen" role="heading" aria-level="2">Carousel Start</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="carousel-controls">
    <button accesskey="p" type="button" class="carousel-control left" data-target="" data-slide="prev"><span aria-hidden="true">&lsaquo;</span><span class="offscreen">Previous Slide</span></button>
    <button accesskey="n" type="button" class="carousel-control right" data-target="" data-slide="next"><span aria-hidden="true">&rsaquo;</span><span class="offscreen">Next Slide</span></button>
    </div>
    <div class="carousel-dots">
    </div>
  <div class="offscreen">Carousel End</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Relationship: Content: Image (field_s_image_info) */
  $handler->display->display_options['relationships']['field_s_image_info_value']['id'] = 'field_s_image_info_value';
  $handler->display->display_options['relationships']['field_s_image_info_value']['table'] = 'field_data_field_s_image_info';
  $handler->display->display_options['relationships']['field_s_image_info_value']['field'] = 'field_s_image_info_value';
  $handler->display->display_options['relationships']['field_s_image_info_value']['label'] = 'Image info field collection';
  $handler->display->display_options['relationships']['field_s_image_info_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_s_image_info_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['ui_name'] = 'Content: URL Link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['text'] = '<a href="[field_s_slide_link-url]">';
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link']['type'] = 'link_plain';
  /* Field: Content: Text Link */
  $handler->display->display_options['fields']['field_s_slide_link_1']['id'] = 'field_s_slide_link_1';
  $handler->display->display_options['fields']['field_s_slide_link_1']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['ui_name'] = 'Content: Text Link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['text'] = '</a>';
  $handler->display->display_options['fields']['field_s_slide_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_1']['type'] = 'link_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_slide_link_2']['id'] = 'field_s_slide_link_2';
  $handler->display->display_options['fields']['field_s_slide_link_2']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_2']['type'] = 'link_title_plain';
  /* Field: Content: Caption Color */
  $handler->display->display_options['fields']['field_s_slide_caption_color']['id'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['table'] = 'field_data_field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['field'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['text'] = 'carousel-[field_s_slide_caption_color]';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['type'] = 'list_key';
  /* Field: Content: Caption Position - Horizontal */
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['id'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['table'] = 'field_data_field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['field'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_h]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['type'] = 'list_key';
  /* Field: Content: Caption Position - Vertical */
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['id'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['table'] = 'field_data_field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['field'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_v]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['type'] = 'list_key';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['path'] = '[field_s_slide_link_1]';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => '9-col-banner',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Global: Rewrite view */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite view';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="carousel-caption stanford-carousel-text [field_s_slide_caption_color] [field_s_slide_caption_position_h] [field_s_slide_caption_position_v]">
    <h2 class="slide-title">[field_s_slide_link][title][field_s_slide_link_1]</h2>
    <div class="slide-caption">[field_s_slide_link][field_s_image_caption][field_s_slide_link_1]</div>
    <div class="more-link">[field_s_slide_link][field_s_slide_link_2][field_s_slide_link_1]</div>
    <div class="edit-link">[edit_node]</div>
    </div>
    <div>[field_s_slide_link][field_s_image_image][field_s_slide_link_1]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  /* Sort criterion: Content: Weight (field_s_slide_weight) */
  $handler->display->display_options['sorts']['field_s_slide_weight_value']['id'] = 'field_s_slide_weight_value';
  $handler->display->display_options['sorts']['field_s_slide_weight_value']['table'] = 'field_data_field_s_slide_weight';
  $handler->display->display_options['sorts']['field_s_slide_weight_value']['field'] = 'field_s_slide_weight_value';
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
    'stanford_slide' => 'stanford_slide',
  );
  /* Filter criterion: Content: Featured (field_s_slide_featured) */
  $handler->display->display_options['filters']['field_s_slide_featured_value']['id'] = 'field_s_slide_featured_value';
  $handler->display->display_options['filters']['field_s_slide_featured_value']['table'] = 'field_data_field_s_slide_featured';
  $handler->display->display_options['filters']['field_s_slide_featured_value']['field'] = 'field_s_slide_featured_value';
  $handler->display->display_options['filters']['field_s_slide_featured_value']['value'] = array(
    1 => '1',
  );

  /* Display: No Caption - Span 9 */
  $handler = $view->new_display('block', 'No Caption - Span 9', 'nocaption_span9');
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['ui_name'] = 'Content: URL Link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['text'] = '<a href="[field_s_slide_link-url]">';
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link']['type'] = 'link_plain';
  /* Field: Content: Text Link */
  $handler->display->display_options['fields']['field_s_slide_link_1']['id'] = 'field_s_slide_link_1';
  $handler->display->display_options['fields']['field_s_slide_link_1']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['ui_name'] = 'Content: Text Link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['text'] = '</a>';
  $handler->display->display_options['fields']['field_s_slide_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_1']['type'] = 'link_plain';
  /* Field: Content: Caption Color */
  $handler->display->display_options['fields']['field_s_slide_caption_color']['id'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['table'] = 'field_data_field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['field'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['text'] = 'carousel-[field_s_slide_caption_color]';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['type'] = 'list_key';
  /* Field: Content: Caption Position - Horizontal */
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['id'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['table'] = 'field_data_field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['field'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_h]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['type'] = 'list_key';
  /* Field: Content: Caption Position - Vertical */
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['id'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['table'] = 'field_data_field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['field'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_v]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['type'] = 'list_key';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['path'] = '[field_s_slide_link_1]';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => '9-col-banner',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Global: Rewrite view */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite view';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>[field_s_slide_link][field_s_image_image][field_s_slide_link_1]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';

  /* Display: No Caption - Span 12 */
  $handler = $view->new_display('block', 'No Caption - Span 12', 'nocaption_span12');
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['ui_name'] = 'Content: URL Link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['text'] = '<a href="[field_s_slide_link-url]">';
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link']['type'] = 'link_plain';
  /* Field: Content: Text Link */
  $handler->display->display_options['fields']['field_s_slide_link_1']['id'] = 'field_s_slide_link_1';
  $handler->display->display_options['fields']['field_s_slide_link_1']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['ui_name'] = 'Content: Text Link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['text'] = '</a>';
  $handler->display->display_options['fields']['field_s_slide_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_1']['type'] = 'link_plain';
  /* Field: Content: Caption Color */
  $handler->display->display_options['fields']['field_s_slide_caption_color']['id'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['table'] = 'field_data_field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['field'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['text'] = 'carousel-[field_s_slide_caption_color]';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['type'] = 'list_key';
  /* Field: Content: Caption Position - Horizontal */
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['id'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['table'] = 'field_data_field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['field'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_h]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['type'] = 'list_key';
  /* Field: Content: Caption Position - Vertical */
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['id'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['table'] = 'field_data_field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['field'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_v]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['type'] = 'list_key';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['path'] = '[field_s_slide_link_1]';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => '12-col-banner',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Global: Rewrite view */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite view';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>[field_s_slide_link][field_s_image_image][field_s_slide_link_1]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';

  /* Display: Caption - Span 9 */
  $handler = $view->new_display('block', 'Caption - Span 9', 'caption_span9');

  /* Display: Caption - Span 12 */
  $handler = $view->new_display('block', 'Caption - Span 12', 'caption_span12');
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['ui_name'] = 'Content: URL Link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['text'] = '<a href="[field_s_slide_link-url]">';
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link']['type'] = 'link_plain';
  /* Field: Content: Text Link */
  $handler->display->display_options['fields']['field_s_slide_link_1']['id'] = 'field_s_slide_link_1';
  $handler->display->display_options['fields']['field_s_slide_link_1']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['ui_name'] = 'Content: Text Link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['text'] = '</a>';
  $handler->display->display_options['fields']['field_s_slide_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_1']['type'] = 'link_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_slide_link_2']['id'] = 'field_s_slide_link_2';
  $handler->display->display_options['fields']['field_s_slide_link_2']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_2']['type'] = 'link_title_plain';
  /* Field: Content: Caption Color */
  $handler->display->display_options['fields']['field_s_slide_caption_color']['id'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['table'] = 'field_data_field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['field'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['text'] = 'carousel-[field_s_slide_caption_color]';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['type'] = 'list_key';
  /* Field: Content: Caption Position - Horizontal */
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['id'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['table'] = 'field_data_field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['field'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_h]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['type'] = 'list_key';
  /* Field: Content: Caption Position - Vertical */
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['id'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['table'] = 'field_data_field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['field'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_v]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['type'] = 'list_key';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['path'] = '[field_s_slide_link_1]';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => '12-col-banner',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Global: Rewrite view */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite view';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="carousel-caption stanford-carousel-text [field_s_slide_caption_color] [field_s_slide_caption_position_h] [field_s_slide_caption_position_v]">
    <h2 class="slide-title">[field_s_slide_link][title][field_s_slide_link_1]</h2>
    <div class="slide-caption">[field_s_slide_link][field_s_image_caption][field_s_slide_link_1]</div>
    <div class="more-link">[field_s_slide_link][field_s_slide_link_2][field_s_slide_link_1]</div>
    <div class="edit-link">[edit_node]</div>
    </div>
    <div>[field_s_slide_link][field_s_image_image][field_s_slide_link_1]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';

  /* Display: Caption Block - Span 9 */
  $handler = $view->new_display('block', 'Caption Block - Span 9', 'caption_block_span9');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item carousel-block';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Caption Block - Span 12 */
  $handler = $view->new_display('block', 'Caption Block - Span 12', 'caption_block_span12');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item carousel-block';
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['ui_name'] = 'Content: URL Link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['alter']['text'] = '<a href="[field_s_slide_link-url]">';
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link']['type'] = 'link_plain';
  /* Field: Content: Text Link */
  $handler->display->display_options['fields']['field_s_slide_link_1']['id'] = 'field_s_slide_link_1';
  $handler->display->display_options['fields']['field_s_slide_link_1']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['ui_name'] = 'Content: Text Link';
  $handler->display->display_options['fields']['field_s_slide_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['alter']['text'] = '</a>';
  $handler->display->display_options['fields']['field_s_slide_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_1']['type'] = 'link_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_slide_link_2']['id'] = 'field_s_slide_link_2';
  $handler->display->display_options['fields']['field_s_slide_link_2']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link_2']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_s_slide_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_s_slide_link_2']['type'] = 'link_title_plain';
  /* Field: Content: Caption Color */
  $handler->display->display_options['fields']['field_s_slide_caption_color']['id'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['table'] = 'field_data_field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['field'] = 'field_s_slide_caption_color';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['alter']['text'] = 'carousel-[field_s_slide_caption_color]';
  $handler->display->display_options['fields']['field_s_slide_caption_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_color']['type'] = 'list_key';
  /* Field: Content: Caption Position - Horizontal */
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['id'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['table'] = 'field_data_field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['field'] = 'field_s_slide_caption_position_h';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_h]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_h']['type'] = 'list_key';
  /* Field: Content: Caption Position - Vertical */
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['id'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['table'] = 'field_data_field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['field'] = 'field_s_slide_caption_position_v';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['alter']['text'] = 'carousel-position-[field_s_slide_caption_position_v]';
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_caption_position_v']['type'] = 'list_key';
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['alter']['path'] = '[field_s_slide_link_1]';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => '12-col-banner',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Global: Rewrite view */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite view';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="carousel-caption stanford-carousel-text [field_s_slide_caption_color] [field_s_slide_caption_position_h] [field_s_slide_caption_position_v]">
    <h2 class="slide-title">[field_s_slide_link][title][field_s_slide_link_1]</h2>
    <div class="slide-caption">[field_s_slide_link][field_s_image_caption][field_s_slide_link_1]</div>
    <div class="more-link">[field_s_slide_link][field_s_slide_link_2][field_s_slide_link_1]</div>
    <div class="edit-link">[edit_node]</div>
    </div>
    <div>[field_s_slide_link][field_s_image_image][field_s_slide_link_1]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $export['stanford_carousel'] = $view;

  return $export;
}
