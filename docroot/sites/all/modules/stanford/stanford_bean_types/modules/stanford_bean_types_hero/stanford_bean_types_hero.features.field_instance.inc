<?php
/**
 * @file
 * stanford_bean_types_hero.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_bean_types_hero_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-stanford_hero_block-field_hero_block_hero'.
  $field_instances['bean-stanford_hero_block-field_hero_block_hero'] = array(
    'bundle' => 'stanford_hero_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'large_landscape' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'stanford_12_col_banner_tall' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_hero_block_hero',
    'label' => 'Hero',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'p_buttons' => -1,
        'p_callout' => -1,
        'p_cards' => -1,
        'p_hero' => 'p_hero',
        'p_icon' => -1,
        'p_menu' => -1,
        'p_wysiwyg' => -1,
      ),
      'bundle_weights' => array(
        'p_buttons' => 2,
        'p_callout' => 3,
        'p_cards' => 4,
        'p_hero' => 5,
        'p_icon' => 6,
        'p_menu' => 7,
        'p_wysiwyg' => 8,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-stanford_hero_block-field_hero_block_style'.
  $field_instances['bean-stanford_hero_block-field_hero_block_style'] = array(
    'bundle' => 'stanford_hero_block',
    'default_value' => array(
      0 => array(
        'value' => 'curtain',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'large_landscape' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'stanford_12_col_banner_tall' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_hero_block_style',
    'label' => 'Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero');
  t('Style');

  return $field_instances;
}
