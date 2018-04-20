<?php
/**
 * @file
 * stanford_bean_types_hero.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_bean_types_hero_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_hero_block';
  $bean_type->label = 'stanford_hero_block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['stanford_hero_block'] = $bean_type;

  return $export;
}
