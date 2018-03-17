<?php
/**
 * @file
 * stanford_bean_types_call_to_action.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_bean_types_call_to_action_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_call_to_action';
  $bean_type->label = 'Stanford Call To Action';
  $bean_type->options = '';
  $bean_type->description = 'The Call to Action block provides a link with text, optional image, and optional icon from Font Awesome.';
  $export['stanford_call_to_action'] = $bean_type;

  return $export;
}
