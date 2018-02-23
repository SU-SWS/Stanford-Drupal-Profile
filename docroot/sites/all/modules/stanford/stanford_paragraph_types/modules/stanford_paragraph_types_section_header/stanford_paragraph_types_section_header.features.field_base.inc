<?php
/**
 * @file
 * stanford_paragraph_types_section_header.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_paragraph_types_section_header_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_p_section_color'.
  $field_bases['field_p_section_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p_section_color',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'cool-gray' => 'Cool Gray',
        'light-taupe' => 'Light Taupe',
        'bright-green' => 'Bright Green',
        'bright-blue' => 'Bright Blue',
        'bright-yellow' => 'Bright Yellow',
        'bright-orange' => 'Bright Orange',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_p_section_heading'.
  $field_bases['field_p_section_heading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p_section_heading',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
