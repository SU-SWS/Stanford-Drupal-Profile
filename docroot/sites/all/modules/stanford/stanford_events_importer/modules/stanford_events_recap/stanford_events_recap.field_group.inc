<?php
/**
 * @file
 * stanford_events_recap.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_events_recap_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_post_events|node|stanford_event|form';
  $field_group->group_name = 'group_post_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Post Event Details',
    'weight' => '17',
    'children' => array(
      0 => 'field_s_event_post_video',
      1 => 'field_s_event_post_audio',
      2 => 'field_s_event_post_gallery',
      3 => 'field_s_event_post_recap',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Post Event Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-post-events field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_post_events|node|stanford_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recap_details|node|stanford_event|default';
  $field_group->group_name = 'group_recap_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Recap',
    'weight' => '-10',
    'children' => array(
      0 => 'field_s_event_post_video',
      1 => 'field_s_event_post_audio',
      2 => 'field_s_event_post_gallery',
      3 => 'field_s_event_post_recap',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Event Recap',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-recap-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_recap_details|node|stanford_event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event Recap');
  t('Post Event Details');

  return $field_groups;
}
