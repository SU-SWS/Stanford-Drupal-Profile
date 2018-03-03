<?php
/**
 * @file
 * stanford_related_publication.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_related_publication_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'node-stanford_publication-field_s_related_content'
  $field_instances['node-stanford_publication-field_s_related_content'] = array(
    'bundle' => 'stanford_publication',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Defines relationships for displaying aggregated content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
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
    'field_name' => 'field_s_related_content',
    'label' => 'Related Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Defines relationships for displaying aggregated content.');
  t('Related Content');

  return $field_instances;
}
