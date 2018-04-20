<?php
/**
 * @file
 * stanford_news_extras.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_news_extras_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_caption_div|field_collection_item|field_s_image_info|soe_news_item';
  $field_group->group_name = 'group_caption_div';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'soe_news_item';
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
  $field_groups['group_caption_div|field_collection_item|field_s_image_info|soe_news_item'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|field_collection_item|field_s_image_info|soe_news_item';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'soe_news_item';
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
  $field_groups['group_s_credits_style|field_collection_item|field_s_image_info|soe_news_item'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_new_banner_style|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_new_banner_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_news_banner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-new-banner-style field-group-div banner-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_new_banner_style|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_new_byline_descriptor|node|stanford_news_item|full';
  $field_group->group_name = 'group_s_new_byline_descriptor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_news_teaser';
  $field_group->data = array(
    'label' => 'Descriptor',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_news_byline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_new_byline_descriptor|node|stanford_news_item|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_body_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_body_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_2';
  $field_group->data = array(
    'label' => 'Body Style',
    'weight' => '7',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Body Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-body-style field-group-div body-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_body_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_body_style|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_news_body_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Body Style',
    'weight' => '33',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Body Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-body-style field-group-div body-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_body_style|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_byline_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_byline_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_1';
  $field_group->data = array(
    'label' => 'Byline Style',
    'weight' => '5',
    'children' => array(
      0 => 'field_s_news_byline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Byline Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-byline-style field-group-div byline-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_byline_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_byline_style|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_news_byline_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = 'group_s_postcard_image';
  $field_group->data = array(
    'label' => 'Byline Style',
    'weight' => '30',
    'children' => array(
      0 => 'field_s_news_byline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Byline Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-byline-style field-group-div credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_byline_style|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_date_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_date_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_1';
  $field_group->data = array(
    'label' => 'Date Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_news_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-div descriptor date-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_date_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_date_style|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_news_date_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = 'group_s_postcard_image';
  $field_group->data = array(
    'label' => 'Date Style',
    'weight' => '29',
    'children' => array(
      0 => 'field_s_news_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-date-style field-group-div credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_date_style|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_external_link_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_external_link_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_2';
  $field_group->data = array(
    'label' => 'External Link Style',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_news_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'External Link Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-div external-link-style more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_external_link_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_file_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_file_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File Style',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_news_attachment',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'File Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-file-style field-group-div file-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_file_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_link_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_link_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_links_group_style';
  $field_group->data = array(
    'label' => 'Link Style',
    'weight' => '6',
    'children' => array(
      0 => 'links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Link Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-link-style field-group-div link-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_link_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_links_group_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_links_group_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links group style',
    'weight' => '6',
    'children' => array(
      0 => 'group_s_news_external_link_style',
      1 => 'group_s_news_source_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links group style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-links-group-style field-group-div links-group-style more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_links_group_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_postcard_col_1|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_postcard_col_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '32',
    'children' => array(
      0 => 'field_s_image_info',
      1 => 'group_s_news_byline_style',
      2 => 'group_s_news_date_style',
      3 => 'group_s_news_source_style',
      4 => 'group_s_news_teaser_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-postcard-col-1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_postcard_col_1|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_postcard_col_2|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_postcard_col_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '33',
    'children' => array(
      0 => 'group_s_news_body_style',
      1 => 'group_s_news_external_link_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-postcard-col-2 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_postcard_col_2|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_source_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_source_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_1';
  $field_group->data = array(
    'label' => 'Source Style',
    'weight' => '4',
    'children' => array(
      0 => 'field_s_news_source',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Source Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-div source-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_source_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_taxonomy|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_news_research_theme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_s_news_taxonomy|node|stanford_news_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser_byline|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_teaser_byline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser/Byline',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_news_byline',
      1 => 'field_s_news_teaser',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Teaser/Byline',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-s-news-teaser-byline field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_s_news_teaser_byline|node|stanford_news_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser_style|node|stanford_news_item|stanford_extras_single_region';
  $field_group->group_name = 'group_s_news_teaser_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_extras_single_region';
  $field_group->parent_name = 'group_s_news_postcard_col_1';
  $field_group->data = array(
    'label' => 'Teaser style',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_news_teaser',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaser style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-div teaser-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_teaser_style|node|stanford_news_item|stanford_extras_single_region'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser_style|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_news_teaser_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_news_teaser',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaser Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'teaser-style',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_teaser_style|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser|node|stanford_news_item|full';
  $field_group->group_name = 'group_s_news_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '23',
    'children' => array(
      0 => 'field_s_news_teaser',
      1 => 'group_s_new_byline_descriptor',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaser',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-teaser field-group-div lead',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_news_teaser|node|stanford_news_item|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '23',
    'children' => array(
      0 => 'group_s_news_body_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_content|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '22',
    'children' => array(
      0 => 'field_s_image_info',
      1 => 'group_s_news_byline_style',
      2 => 'group_s_news_date_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_image|node|stanford_news_item|stanford_news_extras'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_news_item|stanford_news_extras';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'stanford_news_extras';
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
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard|node|stanford_news_item|stanford_news_extras'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner Style');
  t('Body Style');
  t('Byline Style');
  t('Caption Style');
  t('Categories');
  t('Credits Style');
  t('Date Style');
  t('Descriptor');
  t('External Link Style');
  t('File Style');
  t('Link Style');
  t('Links group style');
  t('Postcard');
  t('Postcard Column 1');
  t('Postcard Column 2');
  t('Postcard Content');
  t('Postcard Image');
  t('Source Style');
  t('Teaser');
  t('Teaser Style');
  t('Teaser style');
  t('Teaser/Byline');

  return $field_groups;
}
