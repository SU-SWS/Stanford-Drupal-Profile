<?php
/**
 * @file
 * stanford_faq.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_faq_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-faq-field_s_faq_category'
  $field_instances['node-faq-field_s_faq_category'] = array(
    'bundle' => 'faq',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'These categories allow the FAQ to display with related data. Select one or more category.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_faq_category',
    'label' => 'Display categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-faq-field_s_faq_weight'
  $field_instances['node-faq-field_s_faq_weight'] = array(
    'bundle' => 'faq',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'This integer field is used to control the sort order in views displays. Larger numbers are "heavier" and sink lower in the list.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_faq_weight',
    'label' => 'Sorting Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Display categories');
  t('Sorting Weight');
  t('These categories allow the FAQ to display with related data. Select one or more category.');
  t('This integer field is used to control the sort order in views displays. Larger numbers are "heavier" and sink lower in the list.');

  return $field_instances;
}
