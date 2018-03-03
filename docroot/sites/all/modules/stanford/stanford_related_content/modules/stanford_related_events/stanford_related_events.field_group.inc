<?php
/**
 * @file
 * stanford_related_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_related_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = false; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_related_content_style|node|stanford_event|default';
  $field_group->group_name = 'group_s_related_content_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This event is related to',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_related_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This event is related to',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-related-content-style field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );

  $export['group_s_related_content_style|node|stanford_event|default'] = $field_group;
  return $export;
}
