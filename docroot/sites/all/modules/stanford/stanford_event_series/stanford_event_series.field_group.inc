<?php
/**
 * @file
 * stanford_event_series.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_event_series_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_event_series_style|node|stanford_event|default';
  $field_group->group_name = 'group_s_event_series_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This event belongs to the following series',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_event_series',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This event belongs to the following series',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-event-series-style field-group-div header-striped',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_event_series_style|node|stanford_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_featured_image_style|node|stanford_event_series|default';
  $field_group->group_name = 'group_s_featured_image_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event_series';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured Image Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Featured Image Style',
      'instance_settings' => array(
        'id' => 'node_stanford_event_series_full_group_s_featured_image_style',
        'classes' => 'float-right border-simple-nowidth border-shadow group_s_postcard_image group-s-featured-image-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_featured_image_style|node|stanford_event_series|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_series_advanced|node|stanford_event_series|form';
  $field_group->group_name = 'group_s_series_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event_series';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_series_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_series_advanced|node|stanford_event_series|form'] = $field_group;

  return $export;
}
