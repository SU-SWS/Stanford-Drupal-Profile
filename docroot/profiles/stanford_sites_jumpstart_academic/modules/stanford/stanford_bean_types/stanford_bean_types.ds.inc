<?php
/**
 * @file
 * stanford_bean_types.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function stanford_bean_types_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|stanford_icon_block|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'stanford_icon_block';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['bean|stanford_icon_block|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_bean_types_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|stanford_icon_block|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'stanford_icon_block';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_postcard',
        1 => 'group_postcard_icon',
        2 => 'title',
        3 => 'group_postcard_content',
        4 => 'field_s_icon_body',
        5 => 'field_s_icon_icon',
        6 => 'field_s_icon_link',
      ),
    ),
    'fields' => array(
      'group_postcard' => 'ds_content',
      'group_postcard_icon' => 'ds_content',
      'title' => 'ds_content',
      'group_postcard_content' => 'ds_content',
      'field_s_icon_body' => 'ds_content',
      'field_s_icon_icon' => 'ds_content',
      'field_s_icon_link' => 'ds_content',
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
  $export['bean|stanford_icon_block|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_bean_types_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_12_col_banner_tall';
  $ds_view_mode->label = 'Banner 12 Column Tall';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_12_col_banner_tall'] = $ds_view_mode;

  return $export;
}
