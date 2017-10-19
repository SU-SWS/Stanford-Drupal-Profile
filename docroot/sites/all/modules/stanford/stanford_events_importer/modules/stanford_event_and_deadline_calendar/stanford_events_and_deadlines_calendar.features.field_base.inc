<?php
/**
 * @file
 * stanford_events_and_deadlines_calendar.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_events_and_deadlines_calendar_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_stanford_event_deadline'
  $field_bases['field_stanford_event_deadline'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stanford_event_deadline',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
