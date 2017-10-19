<?php
/**
 * @file
 * stanford_paragraph_types_two_columns.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_paragraph_types_two_columns_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_p_2p_body'.
  $field_bases['field_p_2p_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p_2p_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
