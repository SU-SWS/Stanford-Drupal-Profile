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
  $field_group->identifier = 'group_stanford_video_external|node|stanford_video|form';
  $field_group->group_name = 'group_stanford_video_external';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External Embedded Video',
    'weight' => '5',
    'children' => array(
      0 => 'field_stanford_video_external',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_stanford_video_external|node|stanford_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stanford_video_streaming|node|stanford_video|form';
  $field_group->group_name = 'group_stanford_video_streaming';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stanford_web_video';
  $field_group->data = array(
    'label' => 'Streaming Video',
    'weight' => '3',
    'children' => array(
      0 => 'field_stanford_video_link',
      1 => 'field_stanford_video_server',
      2 => 'field_stanford_video_account',
      3 => 'field_stanford_video_filename',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_stanford_video_streaming|node|stanford_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stanford_video_uploaded|node|stanford_video|form';
  $field_group->group_name = 'group_stanford_video_uploaded';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stanford_web_video';
  $field_group->data = array(
    'label' => 'Uploaded Video',
    'weight' => '4',
    'children' => array(
      0 => 'field_stanford_video_file',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_stanford_video_uploaded|node|stanford_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stanford_web_video|node|stanford_video|form';
  $field_group->group_name = 'group_stanford_web_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stanford Web Video',
    'weight' => '4',
    'children' => array(
      0 => 'field_stanford_video_caption',
      1 => 'field_stanford_video_poster',
      2 => 'group_stanford_video_streaming',
      3 => 'group_stanford_video_uploaded',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_stanford_web_video|node|stanford_video|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('External Embedded Video');
  t('Stanford Web Video');
  t('Streaming Video');
  t('Uploaded Video');

  return $field_groups;
}
