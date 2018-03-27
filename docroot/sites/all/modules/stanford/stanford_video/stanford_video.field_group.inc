<?php
/**
 * @file
 * stanford_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_video_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_descriptor_info|node|stanford_video|default';
  $field_group->group_name = 'group_s_descriptor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Descriptor Info',
    'weight' => '14',
    'children' => array(
      0 => 'field_s_video_date',
      1 => 'group_s_category',
      2 => 'group_s_speakers',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor Info',
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
  $field_groups['group_s_descriptor_info|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_video|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '19',
    'children' => array(
      0 => 'body',
      1 => 'field_s_video_embed',
      2 => 'group_s_postcard_quote',
      3 => 'group_s_descriptor_info',
      4 => 'group_s_files',
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
  $field_groups['group_s_postcard_content|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_category|node|stanford_video|default';
  $field_group->group_name = 'group_s_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_descriptor_info';
  $field_group->data = array(
    'label' => 'Categories:',
    'weight' => '5',
    'children' => array(
      0 => 'field_s_video_categories',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categories:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-category',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_category|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_category|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_descriptor_info';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_video_categories',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-category',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_category|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_descriptor_info|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_descriptor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Descriptor Info',
    'weight' => '19',
    'children' => array(
      0 => 'field_s_video_date',
      1 => 'group_s_speakers',
      2 => 'group_s_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor Info',
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
  $field_groups['group_s_descriptor_info|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_files|node|stanford_video|default';
  $field_group->group_name = 'group_s_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '18',
    'children' => array(
      0 => 'field_s_video_file_insert',
      1 => 'field_s_video_transcript',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Resources',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-files field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_files|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_files|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '23',
    'children' => array(
      0 => 'field_s_video_file_insert',
      1 => 'field_s_video_transcript',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Resources',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-files field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_files|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '30',
    'children' => array(
      0 => 'body',
      1 => 'group_s_descriptor_info',
      2 => 'group_s_postcard_quote',
      3 => 'group_s_files',
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
  $field_groups['group_s_postcard_content|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_quote|node|stanford_video|default';
  $field_group->group_name = 'group_s_postcard_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Postcard Quote',
    'weight' => '16',
    'children' => array(
      0 => 'field_s_video_quote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Quote',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-quote',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_quote|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_quote|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_postcard_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Postcard Quote',
    'weight' => '21',
    'children' => array(
      0 => 'field_s_video_quote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Quote',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-quote',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_quote|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_video|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_postcard_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Video',
    'weight' => '28',
    'children' => array(
      0 => 'field_s_video_embed',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Video',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-video',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_video|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_video|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_content',
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
  $field_groups['group_s_postcard|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_content',
      1 => 'group_s_postcard_video',
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
  $field_groups['group_s_postcard|node|stanford_video|stanford_video_half_width'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_speakers|node|stanford_video|default';
  $field_group->group_name = 'group_s_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_descriptor_info';
  $field_group->data = array(
    'label' => 'Speaker(s):',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_video_speakers',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Speaker(s):',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-speakers',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_speakers|node|stanford_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_speakers|node|stanford_video|stanford_video_half_width';
  $field_group->group_name = 'group_s_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'stanford_video_half_width';
  $field_group->parent_name = 'group_s_descriptor_info';
  $field_group->data = array(
    'label' => 'Speaker(s):',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_video_speakers',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Speaker(s):',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-speakers',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_speakers|node|stanford_video|stanford_video_half_width'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Categories');
  t('Categories:');
  t('Descriptor Info');
  t('Postcard');
  t('Postcard Content');
  t('Postcard Quote');
  t('Postcard Video');
  t('Resources');
  t('Speaker(s):');
  t('Speaker(s):');

  return $field_groups;
}
