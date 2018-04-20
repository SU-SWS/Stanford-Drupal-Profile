<?php
/**
 * @file
 * stanford_news_extras.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function stanford_news_extras_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|stanford_news_item|stanford_extras_single_region';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'stanford_news_item';
  $ds_fieldsetting->view_mode = 'stanford_extras_single_region';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
      ),
    ),
  );
  $export['node|stanford_news_item|stanford_extras_single_region'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|stanford_news_item|stanford_news_extras';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'stanford_news_item';
  $ds_fieldsetting->view_mode = 'stanford_news_extras';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
      ),
    ),
  );
  $export['node|stanford_news_item|stanford_news_extras'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_news_extras_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_news_item|stanford_extras_single_region';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_news_item';
  $ds_layout->view_mode = 'stanford_extras_single_region';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'group_s_news_postcard',
        2 => 'group_s_news_teaser_style',
        3 => 'group_s_news_date_style',
        4 => 'group_s_news_source_style',
        5 => 'field_s_news_source',
        6 => 'group_s_news_byline_style',
        7 => 'field_s_news_date',
        8 => 'field_s_image_info',
        9 => 'group_s_news_body_style',
        10 => 'group_s_news_external_link_style',
        11 => 'body',
        12 => 'field_s_news_link',
        13 => 'field_s_news_teaser',
        14 => 'field_s_news_byline',
        15 => 'group_s_news_postcard_col_1',
        16 => 'group_s_news_postcard_col_2',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_s_news_postcard' => 'ds_content',
      'group_s_news_teaser_style' => 'ds_content',
      'group_s_news_date_style' => 'ds_content',
      'group_s_news_source_style' => 'ds_content',
      'field_s_news_source' => 'ds_content',
      'group_s_news_byline_style' => 'ds_content',
      'field_s_news_date' => 'ds_content',
      'field_s_image_info' => 'ds_content',
      'group_s_news_body_style' => 'ds_content',
      'group_s_news_external_link_style' => 'ds_content',
      'body' => 'ds_content',
      'field_s_news_link' => 'ds_content',
      'field_s_news_teaser' => 'ds_content',
      'field_s_news_byline' => 'ds_content',
      'group_s_news_postcard_col_1' => 'ds_content',
      'group_s_news_postcard_col_2' => 'ds_content',
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
  $export['node|stanford_news_item|stanford_extras_single_region'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_news_item|stanford_news_extras';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_news_item';
  $ds_layout->view_mode = 'stanford_news_extras';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        6 => 'group_s_postcard_image',
        7 => 'group_s_postcard_content',
        8 => 'field_s_news_date',
        9 => 'field_s_news_byline',
        10 => 'group_s_news_date_style',
        11 => 'group_s_news_byline_style',
        12 => 'field_s_image_info',
        13 => 'group_s_news_body_style',
        14 => 'body',
      ),
      'banner' => array(
        1 => 'group_s_new_banner_style',
        3 => 'field_s_news_banner',
      ),
      'banner_overlay' => array(
        2 => 'title',
        4 => 'group_s_news_teaser_style',
        5 => 'field_s_news_teaser',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'group_s_new_banner_style' => 'banner',
      'title' => 'banner_overlay',
      'field_s_news_banner' => 'banner',
      'group_s_news_teaser_style' => 'banner_overlay',
      'field_s_news_teaser' => 'banner_overlay',
      'group_s_postcard_image' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
      'field_s_news_date' => 'ds_content',
      'field_s_news_byline' => 'ds_content',
      'group_s_news_date_style' => 'ds_content',
      'group_s_news_byline_style' => 'ds_content',
      'field_s_image_info' => 'ds_content',
      'group_s_news_body_style' => 'ds_content',
      'body' => 'ds_content',
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
  $export['node|stanford_news_item|stanford_news_extras'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_news_extras_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_extras_single_region';
  $ds_view_mode->label = 'News extras single region';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['stanford_extras_single_region'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_news_extras';
  $ds_view_mode->label = 'News Extras';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['stanford_news_extras'] = $ds_view_mode;

  return $export;
}
