<?php
/**
 * @file
 * stanford_events_importer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_events_importer_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_caption_style|node|stanford_event|default';
  $field_group->group_name = 'group_caption_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption Style',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_event_image_caption',
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
  $export['group_caption_style|node|stanford_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descriptor_info|node|stanford_event|default';
  $field_group->group_name = 'group_descriptor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Descriptor group',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_event_map_link',
      1 => 'field_stanford_event_admission',
      2 => 'field_stanford_event_datetime',
      3 => 'field_stanford_event_location',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor group',
      'instance_settings' => array(
        'classes' => 'descriptor group-descriptor-info field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_descriptor_info|node|stanford_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_floatright|node|stanford_event|default';
  $field_group->group_name = 'group_floatright';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Float Right',
    'weight' => '0',
    'children' => array(
      0 => 'field_stanford_event_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Float Right',
      'instance_settings' => array(
        'classes' => 'float-right border-simple-nowidth border-shadow group-floatright field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_floatright|node|stanford_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stanford_event_advanced|node|stanford_event|form';
  $field_group->group_name = 'group_stanford_event_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '16',
    'children' => array(
      0 => 'field_s_event_feed_type',
      1 => 'field_s_event_type',
      2 => 'field_stanford_event_add_to_cal',
      3 => 'field_stanford_event_audience',
      4 => 'field_stanford_event_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stanford-event-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_stanford_event_advanced|node|stanford_event|form'] = $field_group;

  return $export;
}
