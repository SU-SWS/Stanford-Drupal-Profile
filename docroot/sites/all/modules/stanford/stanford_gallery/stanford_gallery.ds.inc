<?php
/**
 * @file
 * stanford_gallery.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_gallery_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'gallery_large';
  $ds_view_mode->label = 'Gallery Large';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['gallery_large'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'gallery_medium';
  $ds_view_mode->label = 'Gallery Medium';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['gallery_medium'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'gallery_small';
  $ds_view_mode->label = 'Gallery Small';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['gallery_small'] = $ds_view_mode;

  return $export;
}
