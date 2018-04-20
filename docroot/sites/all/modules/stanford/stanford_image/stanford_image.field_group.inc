<?php
/**
 * @file
 * stanford_image.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_image_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_caption_div|field_collection_item|field_s_image_info|stanford_large_scaled';
  $field_group->group_name = 'group_caption_div';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_large_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'classes' => 'caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_caption_div|field_collection_item|field_s_image_info|stanford_large_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_styles|field_collection_item|field_s_image_info|stanford_icon_scaled';
  $field_group->group_name = 'group_image_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_icon_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-image-styles field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_image_styles|field_collection_item|field_s_image_info|stanford_icon_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_styles|field_collection_item|field_s_image_info|stanford_sm_scaled';
  $field_group->group_name = 'group_image_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_sm_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-image-styles field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_image_styles|field_collection_item|field_s_image_info|stanford_sm_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_12_col_banner';
  $field_group->group_name = 'group_s_banner_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_12_col_banner';
  $field_group->parent_name = 'group_s_image_border_style';
  $field_group->data = array(
    'label' => 'Banner Overlay',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Overlay',
      'instance_settings' => array(
        'classes' => 'banner-overlay',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_12_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_12_col_banner_tall';
  $field_group->group_name = 'group_s_banner_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_12_col_banner_tall';
  $field_group->parent_name = 'group_s_image_border_style';
  $field_group->data = array(
    'label' => 'Banner Overlay',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Overlay',
      'instance_settings' => array(
        'classes' => 'banner-overlay',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_12_col_banner_tall'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_6_col_banner';
  $field_group->group_name = 'group_s_banner_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_6_col_banner';
  $field_group->parent_name = 'group_s_image_border_style';
  $field_group->data = array(
    'label' => 'Banner Overlay',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Overlay',
      'instance_settings' => array(
        'classes' => 'banner-overlay',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_6_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_8_col_banner';
  $field_group->group_name = 'group_s_banner_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_8_col_banner';
  $field_group->parent_name = 'group_s_image_border_style';
  $field_group->data = array(
    'label' => 'Banner Overlay',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Overlay',
      'instance_settings' => array(
        'classes' => 'banner-overlay',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_8_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_9_col_banner';
  $field_group->group_name = 'group_s_banner_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_9_col_banner';
  $field_group->parent_name = 'group_s_image_border_style';
  $field_group->data = array(
    'label' => 'Banner Overlay',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Overlay',
      'instance_settings' => array(
        'classes' => 'banner-overlay',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_banner_overlay|field_collection_item|field_s_image_info|stanford_9_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|full_width_banner_tall_caption';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'full_width_banner_tall_caption';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-caption-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|full_width_banner_tall_caption'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_3_col_header';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'classes' => 'caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_4_col_header';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'classes' => 'caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'classes' => 'group-s-caption-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_banner_850x400';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_850x400';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-caption-style field-group-div caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_banner_850x400'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-caption-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_fw_banner_tall_caption';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-caption-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_header_150_width_left';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_header_150_width_left';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '12',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-s-caption-style field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_header_150_width_left'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_caption_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled';
  $field_group->group_name = 'group_s_caption_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_sm_landscape_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-caption-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_caption_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_3_col_header';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'classes' => 'credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_4_col_header';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'classes' => 'credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'classes' => 'group-s-credits-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_banner_850x400';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_850x400';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-credits-style field-group-div credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_banner_850x400'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-credits-style ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_header_150_width_left';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_header_150_width_left';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-s-credits-style field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_header_150_width_left'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_large_scaled';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_large_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'classes' => 'credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_large_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_sm_landscape_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Credits Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-credits-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|default';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|full_width_banner_tall_caption';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'full_width_banner_tall_caption';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-border-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|full_width_banner_tall_caption'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|header_370x170';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'header_370x170';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-border-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|header_370x170'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_12_col_banner';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_12_col_banner';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_image',
      1 => 'group_s_banner_overlay',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_12_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_12_col_banner_tall';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_12_col_banner_tall';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_image',
      1 => 'group_s_banner_overlay',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_12_col_banner_tall'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_3_col_header';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_4_col_header';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_6_col_banner';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_6_col_banner';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
      1 => 'group_s_banner_overlay',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_6_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'group-s-image-border-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_8_col_banner';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_8_col_banner';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
      1 => 'group_s_banner_overlay',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_8_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_9_col_banner';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_9_col_banner';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_image',
      1 => 'group_s_banner_overlay',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_9_col_banner'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_banner_850x400';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_850x400';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-border-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_banner_850x400'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style	',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style	',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-border-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_banner_fw_short_credits'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_fw_banner_tall_caption';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-border-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_fw_banner_tall_caption'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_header_150_width_left';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_header_150_width_left';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style	',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-s-image-border-style field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_header_150_width_left'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_large_scaled';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_large_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_large_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_large_square';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_large_square';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_caption',
      1 => 'field_s_image_credits',
      2 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_large_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_med_profile';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_med_profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow border-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_med_profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_medium_square';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_medium_square';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_medium_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_sm_landscape_scaled';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style	',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style	',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-image-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_sm_landscape_scaled'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_small_square';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_small_square';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_small_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|field_collection_item|field_s_image_info|stanford_thumbnail_square';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_thumbnail_square';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_image_border_style|field_collection_item|field_s_image_info|stanford_thumbnail_square'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image|field_collection_item|field_s_image_info|form';
  $field_group->group_name = 'group_s_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add/Edit Image',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_caption',
      1 => 'field_s_image_credits',
      2 => 'field_s_image_image',
      3 => 'field_s_image_source_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add/Edit Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_s_image|field_collection_item|field_s_image_info|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_content|bean|stanford_postcard|stanford_banner_fw_short_credits'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '5',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard-image ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_image|bean|stanford_postcard|stanford_banner_fw_short_credits'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|stanford_banner_fw_short_credits';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_banner_fw_short_credits';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_content',
      1 => 'group_s_postcard_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard|bean|stanford_postcard|stanford_banner_fw_short_credits'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add/Edit Image');
  t('Banner Overlay');
  t('Caption Style');
  t('Credits Style');
  t('Image Border Style');
  t('Image Border Style	');
  t('Image Styles');
  t('Postcard');
  t('Postcard Content');
  t('Postcard Image');

  return $field_groups;
}
