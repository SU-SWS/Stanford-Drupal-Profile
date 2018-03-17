<?php
/**
 * @file
 * stanford_bean_types_call_to_action.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_bean_types_call_to_action_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_cta_icon'.
  $field_bases['field_s_cta_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_cta_icon',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'stanford_field_formatters',
    'settings' => array(
      'subset' => array(),
    ),
    'translatable' => 0,
    'type' => 'fontawesome_icon',
  );

  // Exported field_base: 'field_s_cta_image'.
  $field_bases['field_s_cta_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_cta_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_s_cta_link'.
  $field_bases['field_s_cta_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_cta_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
