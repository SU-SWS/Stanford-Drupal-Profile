<?php
/**
 * @file
 * stanford_paragraph_types_dynamic.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_paragraph_types_dynamic_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-p_views-field_p_views_view'.
  $field_instances['paragraphs_item-p_views-field_p_views_view'] = array(
    'bundle' => 'p_views',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'blockreference',
        'settings' => array(
          'show_empty_blocks' => FALSE,
        ),
        'type' => 'blockreference_without_title',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_p_views_view',
    'label' => 'View',
    'required' => 1,
    'settings' => array(
      'blockreference_modules' => array(
        'bean' => 0,
        'block' => 0,
        'calendar' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'diff' => 0,
        'ds_extras' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'search' => 0,
        'stanford_jumpstart' => 0,
        'stanford_jumpstart_shortcuts' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 'views',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiple_selects',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'multiple_selects',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('View');

  return $field_instances;
}
