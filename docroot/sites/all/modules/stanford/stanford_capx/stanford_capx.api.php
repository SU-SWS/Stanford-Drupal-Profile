<?php

/**
 * @file
 * API Documentation.
 */

/**
 * hook_capx_pre_map_field_alter
 *
 * Allows altering of data from the api before the field mapping happens.
 *
 * @param object $entity
 *   The host entity.
 * @param string $field_name
 *   The name of the field on the host that is being mapped to.
 * @param string $remote_data_paths
 *   The json path to the remote data.
 * @param array $data
 *   The data from the API repsonse.
 *
 * @see EntityMapper.php
 */
function hook_capx_pre_map_field_alter(&$entity, &$field_name, &$remote_data_paths, array &$data) {
  // Alter the data here.
}

/**
 * hook_capx_post_map_field_alter
 *
 * @param object $entity
 *   The host entity that has had data mapped to.
 * @param string $field_name
 *   The field name of the entity that was processed.
 *
 * @see EntityMapper.php
 */
function hook_capx_post_map_field_alter(&$entity, &$field_name) {
  // Allows you to change data after it has been put in the field but before
  // the entity has been saved.
}

/**
 * hook_capx_new_fc_alter
 *
 * When creating a new field collection for an entity mapping you get a chance
 * to alter it here. This is a good place for setting defaults.
 *
 * @param object $field_collection
 *   The field collection entity.
 *
 * @see FieldCollectionProcessor.php
 */
function hook_capx_new_fc_alter(&$field_collection) {
  // Add or change defaults.
}

/**
 * hook_capx_pre_update_entity_alter
 *
 * Before an updated entity is processed you have a chance to change values on
 * the entity or the data.
 *
 * @param object $entity
 *   The entity that is going to be updated.
 * @param array $data
 *   The data from the API.
 * @param object $mapper
 *   The mapping object.
 *
 * @see EntityProcessor.php
 */
function hook_capx_pre_update_entity_alter(&$entity, array &$data, &$mapper) {
}

/**
 * hook_capx_post_update_entity_alter
 *
 * An alter hook to adjust an entity and it's values after it has been updated
 * and saved to the database.
 *
 * @param object $entity
 *   The entity that was just updated.
 *
 * @see EntityProcessor.php
 */
function hook_capx_post_update_entity_alter(&$entity) {

}

/**
 * hook_capx_pre_entity_create_alter
 *
 * Just before a new entity is created you can alter the entity or data.
 *
 * @param array $values
 *   An associative array of information.
 *   $properties = $values['properties'];
 *   $entityType = $values['entity_type'];
 *   $bundleType = $values['bundle_type'];
 *   $mapper = $values['mapper'];
 *   $data = $values['data'];
 *   $guid = $values['guid'];.
 *
 * @see EntityProcessor.php
 */
function hook_capx_pre_entity_create_alter(array &$values) {
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
function hook_capx_post_entity_create_alter(&$entity, array $data) {
  // Do additional actions after the entity has been saved.
}

/**
 * hook_capx_pre_property_set_alter
 *
 * This hook allows you to alter data that is going to be saved to an entity
 * property (title) before it is placed on the entity.
 *
 * @param object $entity
 *   The entity that is being mapped to.
 * @param array $data
 *   The data from the API.
 * @param string $property_name
 *   The name of the property on the $entity object that $data is going in to.
 *
 * @see PropertyProcessorAbstract.php
 */
function hook_capx_pre_property_set_alter(&$entity, array &$data, &$property_name) {

}

/**
 * hook_capx_field_processor_pre_set_alter
 *
 * Just before the data is going to be put in to the field on the $entity you
 * can alter it with this hook.
 *
 * @param object $entity
 *   The entity that is going to be mapped to.
 * @param array $data
 *   The data from the API.
 * @param string $field_name
 *   The field name that is being mapped to.
 */
function hook_capx_field_processor_pre_set_alter(&$entity, array &$data, &$field_name) {

}

/**
 * hook_capx_pre_fetch_remote_file_alter
 *
 * When a file is being mapped to an entity it needs to be fetched from the API.
 * This hook allows you to alter the data before the fetch (file_save) happens.
 *
 * @param array $data
 *   The data from the API.
 *
 * @see FileFieldProcessor.php
 */
function hook_capx_pre_fetch_remote_file_alter(array &$data) {

}

/**
 * hook_capx_post_save_remote_file_alter
 *
 * After the file has been fetched and saved to the file system you may alter
 * the file properties here.
 *
 * @param object $file
 *   The file object as Drupal knows it.
 * @param string $filename
 *   The name of the file that was saved.
 *
 * @see FileFieldProcessor.php
 */
function hook_capx_post_save_remote_file_alter(&$file, $filename) {

}

/**
 * hook_capx_field_type_processor_widget_alter
 *
 * Some widgets require special handling. You can do that here.
 *
 * @param array $widget
 *   The field widget information.
 * @param string $type
 *   The type of widget by name.
 *
 * @see FieldTypeProcessor.php
 */
function hook_capx_field_type_processor_widget_alter(array &$widget, $type) {

}

/**
 * hook_capx_field_processor_field_alter
 *
 * Alter data at the field processor level.
 *
 * @param object $processor
 *   The field processor object.
 * @param string $type
 *   The type of field being processed.
 * @param string $field_name
 *   The name of the field being processed.
 * @param object $entity
 *   The entity with the fields being processed.
 *
 * @see FieldProcessor.php
 */
function hook_capx_field_processor_field_alter(&$processor, $type, $field_name, &$entity) {

}

/**
 * hook_capx_field_processor_widget_alter
 *
 * Alter the field widget processor because why not?
 *
 * @param object $processor
 *   The field processor object.
 * @param string $type
 *   The type of field being processed.
 * @param string $field_name
 *   The name of the field being processed.
 * @param object $entity
 *   The entity with the fields being processed.
 *
 * @see FieldProcessor.php
 */
function hook_capx_field_processor_widget_alter(&$processor, $type, $field_name, &$entity) {

}

/**
 * hook_capx_preprocess_results_alter
 *
 * Act on the results from a API server request. This is the first chance you
 * get prior to any processing on the item.
 *
 * @param array $results
 *   An array of results from a request from the server.
 * @param object $importer
 *   The entity importer (EntityImporter) that made the request.
 */
function hook_capx_preprocess_results_alter(array &$results, &$importer) {

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
function hook_capx_preprocess_profile_update_alter(array &$profile, &$importer) {

}

/**
 * hook_capx_find_org_orphans_codes_alter
 *
 * Alter the org code lookup for orphans.
 *
 * @param array $codes
 *   An array or org code that a profile could belong to.
 */
function hook_capx_find_org_orphans_codes_alter(array $codes) {

}

/**
 * hook_capx_find_org_orphans
 *
 * Do stuff with orphans.
 *
 * @param array $orphans
 *   An array or orphans.
 */
function hook_capx_find_org_orphans_alter($orphans) {

}

/**
 * hook_capx_find_workgroup_orphans_groups_alter
 *
 * Workgroup lookup alter process. Mess with the orphans here.
 *
 * @param array $groups
 *   An array of groups an orphan could belong to.
 */
function hook_capx_find_workgroup_orphans_groups_alter($groups) {

}

/**
 * hook_capx_find_workgroup_orphans_alter
 *
 * After workgroup lookup orphan result altering found here in this function.
 *
 * @param array $orphans
 *   An array of entities that have been marked as orphans by the
 *   workgroup lookup.
 */
function hook_capx_find_workgroup_orphans_alter($orphans) {

}

/**
 * hook_capx_find_sunet_orphans_alter
 *
 * Find orphans by sunet alter.
 *
 * @param array $orphans
 *   An array of entities identified as an orphan.
 */
function hook_capx_find_sunet_orphans_alter($orphans) {

}

/**
 * hook_capx_entity_presave_alter
 *
 * Alter the entity just before it is going to be saved but after all the
 * data mapping has occurred.
 *
 * @param object $entity
 *   The entity about to be saved. EntityDrupalWrapper.
 * @param object $mapper
 *   CAPx\Drupal\Mapper\EntityMapper mapping object.
 */
function hook_capx_entity_presave_alter(&$entity, $mapper) {

}
