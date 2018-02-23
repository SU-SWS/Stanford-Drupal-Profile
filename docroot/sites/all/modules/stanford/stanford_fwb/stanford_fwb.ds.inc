<?php
/**
 * @file
 * stanford_fwb.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_fwb_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_full_width_banner';
  $ds_view_mode->label = 'Banner Full Width';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['stanford_full_width_banner'] = $ds_view_mode;

  return $export;
}
