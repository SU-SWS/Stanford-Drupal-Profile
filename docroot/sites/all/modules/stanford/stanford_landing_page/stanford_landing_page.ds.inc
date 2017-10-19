<?php
/**
 * @file
 * stanford_landing_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function stanford_landing_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_landing_page_item|large_landscape';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_landing_page_item';
  $ds_fieldsetting->view_mode = 'large_landscape';
  $ds_fieldsetting->settings = array(
    'tile_display_title' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['field_collection_item|field_landing_page_item|large_landscape'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_landing_page_item|stanford_4_col_header';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_landing_page_item';
  $ds_fieldsetting->view_mode = 'stanford_4_col_header';
  $ds_fieldsetting->settings = array(
    'stanford_display_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['field_collection_item|field_landing_page_item|stanford_4_col_header'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_landing_page_item|stanford_medium_square';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_landing_page_item';
  $ds_fieldsetting->view_mode = 'stanford_medium_square';
  $ds_fieldsetting->settings = array(
    'tile_display_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['field_collection_item|field_landing_page_item|stanford_medium_square'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_landing_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_landing_page_item|large_landscape';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_landing_page_item';
  $ds_layout->view_mode = 'large_landscape';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_tile_style',
        1 => 'field_s_lp_item_image',
        2 => 'field_s_lp_item_title',
        3 => 'group_s_tile_link_style',
        4 => 'field_s_lp_item_description',
      ),
    ),
    'fields' => array(
      'group_tile_style' => 'ds_content',
      'field_s_lp_item_image' => 'ds_content',
      'field_s_lp_item_title' => 'ds_content',
      'group_s_tile_link_style' => 'ds_content',
      'field_s_lp_item_description' => 'ds_content',
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
  $export['field_collection_item|field_landing_page_item|large_landscape'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_landing_page_item|stanford_4_col_header';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_landing_page_item';
  $ds_layout->view_mode = 'stanford_4_col_header';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_block_style',
        1 => 'field_s_lp_item_title',
        2 => 'field_s_lp_item_image',
        3 => 'field_s_lp_item_link',
        4 => 'field_s_lp_item_description',
        5 => 'group_s_more_link_style',
        6 => 'field_s_lp_2nd_links',
      ),
    ),
    'fields' => array(
      'group_s_block_style' => 'ds_content',
      'field_s_lp_item_title' => 'ds_content',
      'field_s_lp_item_image' => 'ds_content',
      'field_s_lp_item_link' => 'ds_content',
      'field_s_lp_item_description' => 'ds_content',
      'group_s_more_link_style' => 'ds_content',
      'field_s_lp_2nd_links' => 'ds_content',
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
  $export['field_collection_item|field_landing_page_item|stanford_4_col_header'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_landing_page_item|stanford_medium_square';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_landing_page_item';
  $ds_layout->view_mode = 'stanford_medium_square';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'field_s_lp_item_link',
        2 => 'field_s_lp_2nd_links',
        3 => 'field_s_lp_item_title',
        4 => 'field_s_lp_item_image',
        5 => 'field_s_lp_item_description',
        6 => 'group_s_more_link_style',
        7 => 'group_s_postcard_image',
        8 => 'group_s_postcard_content',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'field_s_lp_item_link' => 'ds_content',
      'field_s_lp_2nd_links' => 'ds_content',
      'field_s_lp_item_title' => 'ds_content',
      'field_s_lp_item_image' => 'ds_content',
      'field_s_lp_item_description' => 'ds_content',
      'group_s_more_link_style' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
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
  );
  $export['field_collection_item|field_landing_page_item|stanford_medium_square'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_landing_page_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'large_landscape';
  $ds_view_mode->label = 'Large Landscape';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['large_landscape'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_block';
  $ds_view_mode->label = 'Block';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_block'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_list';
  $ds_view_mode->label = 'List';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_list'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_tiles';
  $ds_view_mode->label = 'Cards';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_tiles'] = $ds_view_mode;

  return $export;
}
