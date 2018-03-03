<?php
/**
 * @file
 * stanford_related_events.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_related_events_field_default_field_instances() {

  $field_instances = array();

  // Exported field_instance: 'node-stanford_event-field_s_related_content'
  $field_instances['node-stanford_event-field_s_related_content'] = array(
  'bundle' => 'stanford_event',
  'default_value' => null,
  'deleted' => 0,
  'description' => 'Defines relationships for displaying aggregated content.',
  'display' => array(
    'default' => array(
      'label' => 'hidden',
      'module' => 'taxonomy',
      'settings' => array(),
      'type' => 'taxonomy_term_reference_plain',
      'weight' => 9,
    ),
    'teaser' => array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ),
  ),
  'entity_type' => 'node',
  'field_name' => 'field_s_related_content',
  'label' => 'Related Content',
  'required' => 0,
  'settings' => array(
    'user_register_form' => false,
  ),
  'widget' => array(
    'active' => 1,
    'module' => 'options',
    'settings' => array(),
    'type' => 'options_buttons',
    'weight' => 14,
  ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Defines relationships for displaying aggregated content.');
  t('Related Content');

  return $field_instances;
}
