<?php
/**
 * @file
 * stanford_gallery_block.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_gallery_block_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_gallery';
  $bean_type->label = 'Stanford Gallery';
  $bean_type->options = '';
  $bean_type->description = 'This block allows a content author to display a stanford_gallery node in a block.';
  $export['stanford_gallery'] = $bean_type;

  return $export;
}
