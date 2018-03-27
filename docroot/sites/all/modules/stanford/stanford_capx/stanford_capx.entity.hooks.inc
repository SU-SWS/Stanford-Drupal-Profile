<?php

/**
 * @file
 * A file to tie into Drupal module and core hooks.
 */

use CAPx\Drupal\Util\CAPx;
use CAPx\Drupal\Organizations\Orgs as Orgs;

/**
 * Implements hook_entity_info().
 */
function stanford_capx_entity_info() {

  // Base configuration entity settings.
  $return = array(
    'capx_cfe' => array(
      'label' => t('Configuration Entity'),
      'plural label' => t('Configuration Entities'),
      'entity class' => '\CAPx\Drupal\Entities\CFEntity',
      'controller class' => '\CAPx\Drupal\Entities\CFEControllerExportable',
      'features controller class' => 'CFEFeaturesController',
      'base table' => 'capx_cfe',
      'fieldable' => TRUE,
      'exportable' => TRUE,
      'default hook' => 'default_capx_cfe',
      'entity keys' => array(
        'id' => 'cfid',
        'bundle' => 'type',
        'name' => 'machine_name',
      ),
      'bundle keys' => array(
        'bundle' => 'type',
      ),
      'bundles' => array(),
      'load hook' => 'capx_cfe_load',
      'save hook' => 'capx_cfe_save',
      'delete hook' => 'capx_cfe_delete',
      'view modes' => array(
        'full' => array(
          'label' => t('Default'),
          'custom settings' => FALSE,
        ),
      ),
      'label callback' => 'entity_class_label',
      'uri callback' => 'entity_class_uri',
      'module' => 'stanford_capx',
      'access callback' => 'stanford_capx_access',
    ),
  );

  // The type entity allows us to create bundles for the above entity. You can
  // find additional bundle type information in the stanford_capx_cfe_types
  // hook.
  $return['capx_cfe_type'] = array(
    'label' => t('Configuration Entity Type'),
    'entity class' => '\CAPx\Drupal\Entities\CFEntityType',
    'controller class' => '\CAPx\Drupal\Entities\CFEntityTypeController',
    'base table' => 'capx_cfe_type',
    'fieldable' => FALSE,
    'bundle of' => 'capx_cfe',
    'entity keys' => array(
      'id' => 'id',
      'name' => 'type',
      'label' => 'label',
    ),
    'module' => 'stanford_capx',
    'access callback' => 'stanford_capx_access',
  );

  return $return;
}

/**
 * List of task Types.
 */
function stanford_capx_get_types($type_name = NULL) {
  $types = entity_load_multiple_by_name('capx_cfe_type', isset($type_name) ? array($type_name) : array());
  return isset($type_name) ? reset($types) : $types;
}

/**
 * The configuration entity bundle types.
 *
 * @return array
 *   An array of CFE types.
 */
function stanford_capx_default_capx_cfe_type() {
  $items = array();

  $items['mapper'] = entity_import('capx_cfe_type', '{
  "label": "CAPx Mapper",
  "type" : "mapper",
  "weight" : "0",
  "description" : "Mappers map data from the CAP API into a Drupal entity"
  }');

  $items['importer'] = entity_import('capx_cfe_type', '{
  "type" : "importer",
  "label": "CAPx Importer",
  "weight" : "0",
  "description" : "Importers set what profiles should be imported into Drupal"
  }');

  return $items;
}

/**
 * Implements hook_entity_info_alter().
 */
function stanford_capx_entity_info_alter(array &$entity_info) {
  foreach (stanford_capx_get_types() as $type => $info) {
    $entity_info['capx_cfe']['bundles'][$type] = array(
      'label' => $info->label,
    );
  }
}

/**
 * Loads a cfe by machine name.
 *
 * @param string $machine_name
 *   Machine name key.
 * @param string $type
 *   The bundle type. eg: mapper, importer.
 *
 * @return mixed
 *   A CFE or false.
 */
function capx_cfe_load_by_machine_name($machine_name, $type = NULL) {

  if (is_null($type)) {
    throw new Exception("\$type is required in capx_cfe_load_by_machine_name");
  }

  if (!is_string($machine_name)) {
    throw new Exception("Machine name required for loading by machine name");
  }

  $cfes = entity_load_multiple_by_name('capx_cfe', array($machine_name), array('type' => $type));

  // Return just one.
  if (is_array($cfes)) {
    return array_pop($cfes);
  }

  return FALSE;
}

/**
 * Load a cfe.
 *
 * @param int $cfid
 *   The entity id.
 * @param bool $reset
 *   Wether to reset the cache or not.
 */
function capx_cfe_load($cfid, $reset = FALSE) {
  $cfes = capx_cfe_load_multiple(array($cfid), array(), $reset);
  // Return just one.
  if (is_array($cfes)) {
    return array_pop($cfes);
  }
  return FALSE;
}

/**
 * Load multiple cfes based on certain conditions.
 *
 * @param mixed $cfids
 *   False or an array of integers.
 * @param array $conditions
 *   An array of sql conditions.
 * @param bool $reset
 *   Wether to reset the cache or not.
 *
 * @return mixed
 *   An entity object or false.
 */
function capx_cfe_load_multiple($cfids = FALSE, array $conditions = array(), $reset = FALSE) {
  return entity_load('capx_cfe', $cfids, $conditions, $reset);
}

/**
 * Save task.
 */
function capx_cfe_save($cfe) {
  entity_save('capx_cfe', $cfe);
}

/**
 * Wrapper function for capx_cfe_save for mappers.
 *
 * @param object $mapper
 *   The mapper object to save.
 */
function capx_mapper_save($mapper) {
  capx_cfe_save($mapper);
}

/**
 * Wrapper function for capx_cfe_save for importers.
 *
 * @param object $importer
 *   The importer object to save.
 */
function capx_importer_save($importer) {
  capx_cfe_save($importer);
}

/**
 * Delete single task.
 *
 * @param object $cfe
 *   The configuration entity to delete.
 */
function capx_cfe_delete($cfe) {
  entity_delete('capx_cfe', entity_id('capx_cfe', $cfe));
}

/**
 * Delete multiple tasks.
 */
function capx_cfe_delete_multiple($cfids) {
  entity_delete_multiple('capx_cfe', $cfids);
}

// hook_entity_[action]()
// /////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////.

/**
 * Implements hook_entity_delete().
 */
function stanford_capx_entity_delete($entity, $type) {
  $entity = entity_metadata_wrapper($type, $entity);
  CAPx::deleteProfileRecord($entity);
}

/**
 * Add some extra information to every loaded entity.
 *
 * Looks like entity_load gets called A LOT. Especially if a view uses entities
 * rather than fields. So instead of making a number of calls. Call once and
 * static cache.
 *
 * @param array $entities
 *   An array of entities to load keyed by id.
 * @param string $type
 *   The entity type.
 */
function stanford_capx_entity_load($entities, $type) {

  $ids = array_keys($entities);
  $meta = &drupal_static(__FUNCTION__, array());

  if (!isset($meta[$type])) {
    $meta[$type] = array();
  }

  // Some sites have wwaaayyy too many items in the capx_profiles table for this
  // to load with an appropriate amount of memory. You can thank Zach Chandler
  // for finding out this edge case. As such, we will apply two different
  // stategies for fetching the CAPx metadata. If the amount of profile entries
  // are over a value then switch from one big cached call to multiple pings of
  // the database. We are trading PHP memory for hammering the DB with multiple
  // queries.
  $count = db_select('capx_profiles')
    ->fields(NULL, array('id'))
    ->countQuery()
    ->execute()
    ->fetchField();

  if ($count > variable_get('stanford_capx_entity_load_limit', 10000)) {
    $query_entities = array_diff_key($entities, $meta[$type]);
    $query_results = db_select("capx_profiles", 'capx')
      ->fields('capx')
      ->condition('entity_type', $type)
      ->condition('entity_id', array_keys($query_entities))
      ->execute()
      ->fetchAllAssoc('entity_id');

    $meta[$type] = $meta[$type] + $query_results;
  }
  else {
    if (empty($meta[$type])) {
      $meta[$type] = db_select("capx_profiles", 'capx')
        ->fields('capx')
        ->execute()
        ->fetchAllAssoc('entity_id');
    }
  }

  // Add the capx information if it matches.
  foreach ($ids as $entity_id) {
    // If we do not find a match then carry on.
    if (isset($meta[$type][$entity_id]) && $meta[$type][$entity_id]->entity_type == $type && isset($entities[$entity_id])) {
      $entities[$entity_id]->capx = (array) $meta[$type][$entity_id];
    }
  }

}

/**
 * Add additional data to the organizations vocabulary terms.
 *
 * We need to track the organization aliases in order to find orphaned profiles.
 *
 * @param array $terms
 *   An array of term objects keyed by the term id.
 *
 * @return array
 *   The same array that was passed in but with capx data amended.
 */
function stanford_capx_taxonomy_term_load($terms) {

  // The tids of all the terms being loaded.
  $keys = array_keys($terms);
  $aliases = Orgs::getAliasesByTid($keys);

  // Just end if nothing to do.
  if (empty($aliases)) {
    return $terms;
  }

  $vocab_name = Orgs::getVocabularyMachineName();
  // For each term add the aliases to them if they are a part of the org vocab.
  foreach ($terms as &$term) {
    if ($term->vocabulary_machine_name == $vocab_name) {
      $term->capx = array("aliases" => $aliases);
    }
  }

  return $terms;
}

/**
 * Implements hook_taxonomy_term_save().
 */
function stanford_capx_taxonomy_term_insert($term) {
  stanford_capx_taxonomy_term_update($term);
}

/**
 * Implements hook_taxonomy_term_update.
 */
function stanford_capx_taxonomy_term_update($term) {
  if (empty($term->capx['aliases'])) {
    return;
  }

  db_delete('capx_org_aliases')
    ->condition('tid', $term->tid)
    ->execute();

  $insert = db_insert('capx_org_aliases');
  foreach ($term->capx['aliases'] as $al) {
    $insert->fields(array(
      'tid' => $term->tid,
      'code' => $term->name,
      'alias' => $al,
    ));
  }

  $insert->execute();

}

// Helper & Util
// /////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////.

/**
 * Wrapper for entity_get_info() with restricted types removed.
 *
 * @return array
 *   An array of entity type information.
 */
function capx_entity_get_info() {
  global $CAP_RESTRICTED_ENTITY_TYPES;
  $entity_types = entity_get_info();
  foreach ($entity_types as $entity_name => $values) {
    if (in_array($entity_name, $CAP_RESTRICTED_ENTITY_TYPES)) {
      unset($entity_types[$entity_name]);
    }
  }
  return $entity_types;
}
