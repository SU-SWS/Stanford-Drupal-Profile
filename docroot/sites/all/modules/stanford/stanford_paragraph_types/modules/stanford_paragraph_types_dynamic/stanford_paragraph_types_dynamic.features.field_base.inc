<?php
/**
 * @file
 * stanford_paragraph_types_dynamic.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_paragraph_types_dynamic_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_p_views_view'.
  $field_bases['field_p_views_view'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p_views_view',
    'indexes' => array(
      'moddelta' => array(
        0 => 'moddelta',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(),
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  return $field_bases;
}
