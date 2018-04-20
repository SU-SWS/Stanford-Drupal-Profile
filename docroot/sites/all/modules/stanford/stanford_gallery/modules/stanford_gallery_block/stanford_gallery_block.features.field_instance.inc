<?php
/**
 * @file
 * stanford_gallery_block.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_gallery_block_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-stanford_gallery-field_s_gallery_reference'
  $field_instances['bean-stanford_gallery-field_s_gallery_reference'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'stanford_gallery_block',
        'settings' => array(),
        'type' => 'stanford_gallery_block',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_s_gallery_reference',
    'label' => 'Gallery',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-stanford_gallery-field_s_gallery_show_body'
  $field_instances['bean-stanford_gallery-field_s_gallery_show_body'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check to show the body content as well as the images.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_s_gallery_show_body',
    'label' => 'Show Body',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-stanford_gallery-field_s_gallery_view_mode'
  $field_instances['bean-stanford_gallery-field_s_gallery_view_mode'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Change the display of the thumbnails',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_s_gallery_view_mode',
    'label' => 'View Mode',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Change the display of the thumbnails');
  t('Check to show the body content as well as the images.');
  t('Gallery');
  t('Show Body');
  t('View Mode');

  return $field_instances;
}
