<?php
/**
 * @file
 * stanford_fwb.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_fwb_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_slides_full_width_banner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Slides: Full Width Banner';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field: Image (field_s_image_info) */
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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
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
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => 'full-width-banner',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="full-width-banner">

<div class="banner-image">[field_s_image_image]</div>

<div class="banner-overlay [field_s_slide_caption_color] [field_s_slide_caption_position_h]">
  <div>
  <div class="slide-title"><h2>[title]</h2></div>
    <div class="slide-caption">[field_s_image_caption]</div>
    <div class="more-link">[field_s_slide_link]</div>
    <div class="edit-link">[edit_node]</div>
 </div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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

  /* Display: Slide Block: Full Width */
  $handler = $view->new_display('block', 'Slide Block: Full Width', 'block');

  /* Display: Short block: caption and credits below */
  $handler = $view->new_display('block', 'Short block: caption and credits below', 'shorts_block_caption_credits_below');
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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_s_slide_link']['id'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['table'] = 'field_data_field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['field'] = 'field_s_slide_link';
  $handler->display->display_options['fields']['field_s_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_s_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_slide_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_s_slide_link']['click_sort_column'] = 'url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_s_image_image']['id'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['table'] = 'field_data_field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['field'] = 'field_s_image_image';
  $handler->display->display_options['fields']['field_s_image_image']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_image']['element_wrapper_class'] = 'banner-image';
  $handler->display->display_options['fields']['field_s_image_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_image_image']['settings'] = array(
    'image_style' => 'full_width_banner_shorts_scale_and_crop_1600x400',
    'image_link' => '',
  );
  /* Field: Field collection item: Caption */
  $handler->display->display_options['fields']['field_s_image_caption']['id'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['table'] = 'field_data_field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['field'] = 'field_s_image_caption';
  $handler->display->display_options['fields']['field_s_image_caption']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_caption']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['preserve_tags'] = '<em> <strong>';
  $handler->display->display_options['fields']['field_s_image_caption']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_caption']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_caption']['element_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_caption']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_caption']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_s_image_caption']['settings'] = array(
    'trim_length' => '1000',
  );
  /* Field: Field collection item: Credits */
  $handler->display->display_options['fields']['field_s_image_credits']['id'] = 'field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['table'] = 'field_data_field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['field'] = 'field_s_image_credits';
  $handler->display->display_options['fields']['field_s_image_credits']['relationship'] = 'field_s_image_info_value';
  $handler->display->display_options['fields']['field_s_image_credits']['label'] = '';
  $handler->display->display_options['fields']['field_s_image_credits']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_image_credits']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_credits']['element_class'] = 'descriptor';
  $handler->display->display_options['fields']['field_s_image_credits']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_s_image_credits']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_image_credits']['element_wrapper_type'] = 'div';
  /* Field: Global: View rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="full-width-banner">
  <div class="banner-image">[field_s_image_image]</div>
  <div class="banner-overlay">
    <div>
      <div class="slide-title"><h2>[title]</h2></div>
      <div class="more-link">[field_s_slide_link]</div>
      <div class="edit-link">[edit_node]</div>
    </div>
  </div>
</div>
<div class="below-banner">
  <div class="descriptor caption-style">[field_s_image_caption]</div>
  <div class="descriptor credits-style">[field_s_image_credits]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['stanford_slides_full_width_banner'] = $view;

  return $export;
}
