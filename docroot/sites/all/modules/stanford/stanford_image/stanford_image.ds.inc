<?php
/**
 * @file
 * stanford_image.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_image_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_s_image_info|header_370x170';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_s_image_info';
  $ds_layout->view_mode = 'header_370x170';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_image_border_style',
        1 => 'field_s_image_image',
      ),
    ),
    'fields' => array(
      'group_s_image_border_style' => 'ds_content',
      'field_s_image_image' => 'ds_content',
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
  $export['field_collection_item|field_s_image_info|header_370x170'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_s_image_info';
  $ds_layout->view_mode = 'stanford_fw_banner_tall_caption';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_image_border_style',
        1 => 'group_s_caption_style',
        2 => 'field_s_image_caption',
        3 => 'field_s_image_image',
      ),
    ),
    'fields' => array(
      'group_s_image_border_style' => 'ds_content',
      'group_s_caption_style' => 'ds_content',
      'field_s_image_caption' => 'ds_content',
      'field_s_image_image' => 'ds_content',
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
  $export['field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_image_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'header_370x170';
  $ds_view_mode->label = 'Header (370x170)';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['header_370x170'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_12_col_banner';
  $ds_view_mode->label = 'Banner 12 Column';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_12_col_banner'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_3_col_header';
  $ds_view_mode->label = 'Header 3 Column';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_3_col_header'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_4_col_header';
  $ds_view_mode->label = 'Header 4 Column';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_4_col_header'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_6_col_banner';
  $ds_view_mode->label = ' Banner 6 Column';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_6_col_banner'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_6_col_banner_short';
  $ds_view_mode->label = 'Banner 6 Column Short';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_6_col_banner_short'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_6_col_banner_tall';
  $ds_view_mode->label = 'Banner 6 Column Tall';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_6_col_banner_tall'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_6_col_photo_landscape';
  $ds_view_mode->label = 'Photo Landscape 6 Column';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_6_col_photo_landscape'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_8_col_banner';
  $ds_view_mode->label = 'Banner 8 Column';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['stanford_8_col_banner'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_8_col_banner_short';
  $ds_view_mode->label = 'Banner 8 Column Short';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_8_col_banner_short'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_8_col_banner_tall';
  $ds_view_mode->label = 'Banner 8 Column Tall';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_8_col_banner_tall'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_9_col_banner';
  $ds_view_mode->label = 'Banner 9 Column ';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_9_col_banner'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_9_col_banner_short';
  $ds_view_mode->label = 'Banner 9 Column Short ';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_9_col_banner_short'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_banner_850x400';
  $ds_view_mode->label = 'Banner (850x400)';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_banner_850x400'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_banner_fw_short_credits';
  $ds_view_mode->label = 'Banner Full Width Short Credits';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_banner_fw_short_credits'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_full_width_banner';
  $ds_view_mode->label = 'Banner Full Width';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_full_width_banner'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_full_width_banner_short';
  $ds_view_mode->label = 'Banner Full Width Short';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_full_width_banner_short'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_fw_banner_tall_caption';
  $ds_view_mode->label = 'Banner full width tall caption';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_fw_banner_tall_caption'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_header_150_width_left';
  $ds_view_mode->label = 'Header 150 Width Left';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['stanford_header_150_width_left'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_icon_profile';
  $ds_view_mode->label = 'Icon Profile';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_icon_profile'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_icon_scaled';
  $ds_view_mode->label = 'Icon Scaled';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_icon_scaled'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_icon_square';
  $ds_view_mode->label = 'Icon Square';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_icon_square'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_large_scaled';
  $ds_view_mode->label = 'Large Scaled';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_large_scaled'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_large_square';
  $ds_view_mode->label = 'Large Square';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_large_square'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_medium_square';
  $ds_view_mode->label = 'Medium Square';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_medium_square'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_sm_landscape_scaled';
  $ds_view_mode->label = 'Small Landscape Scaled';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_sm_landscape_scaled'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_sm_profile';
  $ds_view_mode->label = 'Small Profile';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_sm_profile'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_sm_scaled';
  $ds_view_mode->label = 'Small Scaled';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_sm_scaled'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_small_square';
  $ds_view_mode->label = 'Small Square';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_small_square'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_thumbnail_square';
  $ds_view_mode->label = 'Thumbnail Square';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_thumbnail_square'] = $ds_view_mode;

  return $export;
}
