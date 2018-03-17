<?php
/**
 * @file
 * stanford_events_and_deadlines_calendar.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_events_and_deadlines_calendar_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_event-field_stanford_event_deadline'
  $field_instances['node-stanford_event-field_stanford_event_deadline'] = array(
    'bundle' => 'stanford_event',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stanford_event_deadline',
    'label' => 'Is this a deadline?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Is this a deadline?');

  return $field_instances;
}
