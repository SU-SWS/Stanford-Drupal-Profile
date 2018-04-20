<?php
/**
 * @file
 * stanford_bean_types_hero.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_bean_types_hero_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hero_block_hero'.
  $field_bases['field_hero_block_hero'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hero_block_hero',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_hero_block_style'.
  $field_bases['field_hero_block_style'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hero_block_style',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'static' => 'Standard Header (No movement)',
        'curtain' => 'Curtain Reveal',
        'scroll' => 'Scroll Button',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
