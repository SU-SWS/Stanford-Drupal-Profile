<?php
/**
 * @file
 * stanford_bean_types_hero.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_bean_types_hero_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero_curtain|bean|stanford_hero_block|default';
  $field_group->group_name = 'group_hero_curtain';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_hero_block';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero Curtain',
    'weight' => '0',
    'children' => array(
      0 => 'field_hero_block_hero',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hero Curtain',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'hero-curtain',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hero_curtain|bean|stanford_hero_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero_scroll|bean|stanford_hero_block|large_landscape';
  $field_group->group_name = 'group_hero_scroll';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_hero_block';
  $field_group->mode = 'large_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero Scroll',
    'weight' => '0',
    'children' => array(
      0 => 'field_hero_block_hero',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hero Scroll',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'hero-scroll field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hero_scroll|bean|stanford_hero_block|large_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero_static|bean|stanford_hero_block|stanford_12_col_banner_tall';
  $field_group->group_name = 'group_hero_static';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_hero_block';
  $field_group->mode = 'stanford_12_col_banner_tall';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero Static',
    'weight' => '4',
    'children' => array(
      0 => 'field_hero_block_hero',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hero Static',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'hero-static field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hero_static|bean|stanford_hero_block|stanford_12_col_banner_tall'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero Curtain');
  t('Hero Scroll');
  t('Hero Static');

  return $field_groups;
}
