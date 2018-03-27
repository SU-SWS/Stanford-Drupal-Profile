<?php
/**
 * @file
 * stanford_video.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_video|stanford_video_half_width';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_video';
  $ds_layout->view_mode = 'stanford_video_half_width';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'field_s_video_date',
        2 => 'field_s_video_speakers',
        3 => 'group_s_speakers',
        4 => 'field_s_video_categories',
        5 => 'group_s_category',
        6 => 'field_s_video_quote',
        7 => 'group_s_descriptor_info',
        8 => 'group_s_postcard_quote',
        9 => 'body',
        10 => 'group_s_files',
        11 => 'field_s_video_transcript',
        12 => 'field_s_video_file_insert',
        13 => 'group_s_postcard_video',
        14 => 'field_s_video_embed',
        15 => 'group_s_postcard_content',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'field_s_video_date' => 'ds_content',
      'field_s_video_speakers' => 'ds_content',
      'group_s_speakers' => 'ds_content',
      'field_s_video_categories' => 'ds_content',
      'group_s_category' => 'ds_content',
      'field_s_video_quote' => 'ds_content',
      'group_s_descriptor_info' => 'ds_content',
      'group_s_postcard_quote' => 'ds_content',
      'body' => 'ds_content',
      'group_s_files' => 'ds_content',
      'field_s_video_transcript' => 'ds_content',
      'field_s_video_file_insert' => 'ds_content',
      'group_s_postcard_video' => 'ds_content',
      'field_s_video_embed' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|stanford_video|stanford_video_half_width'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_video_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_video_half_width';
  $ds_view_mode->label = 'Half Width';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['stanford_video_half_width'] = $ds_view_mode;

  return $export;
}
