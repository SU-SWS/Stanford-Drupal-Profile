<?php
/**
 * @file
 * stanford_news.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_news_item|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_news_item';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'group_s_postcard_image',
        2 => 'group_s_postcard_content',
        3 => 'group_descriptor_info',
        4 => 'body',
        5 => 'field_s_news_date',
        6 => 'field_s_news_link',
        7 => 'field_s_news_attachment',
        8 => 'field_s_image_info',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
      'group_descriptor_info' => 'ds_content',
      'body' => 'ds_content',
      'field_s_news_date' => 'ds_content',
      'field_s_news_link' => 'ds_content',
      'field_s_news_attachment' => 'ds_content',
      'field_s_image_info' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_news_item|full'] = $ds_layout;

  return $export;
}
