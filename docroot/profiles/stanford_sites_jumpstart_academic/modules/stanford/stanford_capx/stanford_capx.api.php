<?php
/**
 * @file
 * API Documentation
 */

/**
 * [hook_capx_pre_map_field description]
 * @see  EntityMapper.php
 * @param  [type] $entity            [description]
 * @param  [type] $field_name        [description]
 * @param  [type] $remote_data_paths [description]
 * @return [type]                    [description]
 */
function hook_capx_pre_map_field_alter(&$entity, &$field_name, &$remote_data_paths, &$data) {

}

/**
 * [hook_capx_post_map_field_alter description]
 * @see  EntityMapper.php
 * @param  [type] $entity     [description]
 * @param  [type] $field_name [description]
 * @return [type]             [description]
 */
function hook_capx_post_map_field_alter(&$entity, &$field_name) {

}

/**
 * [hook_capx_new_fc_alter description]
 * @see  FieldCollectionProcessor.php
 * @param  [type] $field_collection [description]
 * @return [type]                   [description]
 */
function hook_capx_new_fc_alter(&$field_collection) {

}

/**
 * [hook_capx_pre_update_entity description]
 * @see  EntityProcessor.php
 * @param  [type] $entity [description]
 * @param  [type] $data   [description]
 * @param  [type] $mapper [description]
 * @return [type]         [description]
 */
function hook_capx_pre_update_entity_alter(&$entity, &$data, &$mapper) {

}

/**
 * [hook_capx_post_update_entity description]
 * @see  EntityProcessor.php
 * @param  [type] $entity [description]
 * @return [type]         [description]
 */
function hook_capx_post_update_entity_alter(&$entity) {

}

/**
 * [hook_capx_pre_entity_create description]
 * @see  EntityProcessor.php
 * @param array $values
 */
function hook_capx_pre_entity_create_alter(&$values) {
  $properties = $values['properties'];
  $entityType = $values['entity_type'];
  $bundleType = $values['bundle_type'];
  $mapper = $values['mapper'];
  $data = $values['data'];
  $guid = $values['guid'];
}

/**
 * After the entity has completed mapping and processing it is saved.
 *
 * This is an alter hook after the entity has been saved and it a real object
 * in the system.
 *
 * @param object $entity
 *   The saved entity.
 * @param array $data
 *   The data array of the information from the api.
 *
 * @see EntityProcessor.php
 */
function hook_capx_post_entity_create_alter(&$entity, $data) {
  // Do additional actions after the entity has been saved.
}

/**
 * [hook_capx_pre_property_set description]
 * @see  PropertyProcessorAbstract.php
 * @param  [type] $entity        [description]
 * @param  [type] $data          [description]
 * @param  [type] $property_name [description]
 * @return [type]                [description]
 */
function hook_capx_pre_property_set_alter(&$entity, &$data, &$property_name) {

}

/**
 * [hook_capx_field_processor_pre_set_alter description]
 * @param  [type] $entity     [description]
 * @param  [type] $data       [description]
 * @param  [type] $field_name [description]
 * @return [type]             [description]
 */
function hook_capx_field_processor_pre_set_alter(&$entity, &$data, &$field_name) {

}

/**
 * [hook_capx_pre_fetch_remote_file_alter description]
 * @see  FileFieldProcessor.php
 * @param  [type] $data [description]
 * @return [type]       [description]
 */
function hook_capx_pre_fetch_remote_file_alter(&$data) {

}

/**
 * [hook_capx_post_save_remote_file_alter description]
 * @see  FileFieldProcessor.php
 * @param  [type] $file     [description]
 * @param  [type] $filename [description]
 * @return [type]           [description]
 */
function hook_capx_post_save_remote_file_alter(&$file, $filename) {

}

/**
 * [hook_capx_field_type_processor_widget_alter description]
 * @see  FieldTypeProcessor.php
 * @param  [type] $widget [description]
 * @param  [type] $type   [description]
 * @return [type]         [description]
 */
function hook_capx_field_type_processor_widget_alter(&$widget, $type) {

}

/**
 * [hook_capx_field_processor_field_alter description]
 * @see  FieldProcessor.php
 * @param  [type] $processor  [description]
 * @param  [type] $type       [description]
 * @param  [type] $field_name [description]
 * @param  [type] $entity     [description]
 * @return [type]             [description]
 */
function hook_capx_field_processor_field_alter(&$processor, $type, $field_name, &$entity) {

}

/**
 * [hook_capx_field_processor_widget_alter description]
 * @see  FieldProcessor.php
 * @param  [type] $processor  [description]
 * @param  [type] $type       [description]
 * @param  [type] $field_name [description]
 * @param  [type] $entity     [description]
 * @return [type]             [description]
 */
function hook_capx_field_processor_widget_alter(&$processor, $type, $field_name, &$entity) {

}

/**
 * Act on the results from a API server request. This is the first chance you
 * get prior to any processing on the item.
 * @param  [array] $results  an array of results from a request from the server.
 * @param  [EntityImporter] $importer the entity importer that made the request.
 * @return [type]           [description]
 */
function hook_capx_preprocess_results_alter(&$results, &$importer) {
}

/**
 * Acts on profile data received from CAP before sync.
 *
 * This happens when user clicks on "Update this profile from CAP"
 * button on eny profile editing page.
 *
 * @param array $profile
 *   Profile data received from CAP.
 * @param object $importer
 *   CAPx\Drupal\Importer\EntityImporter object.
 */
function hook_capx_preprocess_profile_update_alter(&$profile, &$importer) {
}

/**
 * [hook_capx_find_org_orphans_codes_alter description]
 * @param  [type] $codes [description]
 * @return [type]        [description]
 */
function hook_capx_find_org_orphans_codes_alter($codes) {

}

/**
 * [hook_capx_find_org_orphans description]
 * @param  [type] $orphans [description]
 * @return [type]          [description]
 */
function hook_capx_find_org_orphans_alter($orphans) {

}

/**
 * [hook_capx_find_workgroup_orphans_groups_alter description]
 * @param  [type] $groups [description]
 * @return [type]         [description]
 */
function hook_capx_find_workgroup_orphans_groups_alter($groups) {

}

/**
 * [hook_capx_find_workgroup_orphans_alter description]
 * @param  [type] $orphans [description]
 * @return [type]          [description]
 */
function hook_capx_find_workgroup_orphans_alter($orphans) {

}

/**
 * [hook_capx_find_sunet_orphans_alter description]
 * @param  [type] $orphans [description]
 * @return [type]          [description]
 */
function hook_capx_find_sunet_orphans_alter($orphans) {

}

/**
 * @param EntityDrupalWrapper $entity
 * @param string $type
 * @param string $bundle
 * @param array $data
 * @param CAPx\Drupal\Mapper\EntityMapper $mapper
 */
function hook_capx_entity_presave_alter(&$entity, $mapper) {

}
