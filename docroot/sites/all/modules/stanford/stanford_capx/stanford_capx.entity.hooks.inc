<?php
/**
 * @file
 *
 * A file to tie into Drupal module and core hooks.
 *
 * @author [author] <[email]>
 */

use CAPx\Drupal\Util\CAPx;
use CAPx\Drupal\Entities\CFEntity;
use CAPx\Drupal\Entities\CFEControllerExportable;



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
      'base table' => 'capx_cfe',
      'fieldable' => TRUE,
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
  // find additional bundle type information in the stanford_capx_cfe_types hook
  $return['capx_cfe_type'] = array(
    'label' => t('Configuration Entity Type'),
    'entity class' => '\CAPx\Drupal\Entities\CFEntityType',
    'controller class' => '\CAPx\Drupal\Entities\CFEntityTypeController',
    'base table' => 'capx_cfe_type',
    'fieldable' => FALSE,
    'bundle of' => 'capx_cfe',
    'exportable' => TRUE,
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
  $types = entity_load_multiple_by_name('capx_cfe_type', isset($type_name) ? array($type_name) : FALSE);
  return isset($type_name) ? reset($types) : $types;
}

/**
 * The configuration entity bundle types.
 * @return [type] [description]
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
function stanford_capx_entity_info_alter(&$entity_info) {
  foreach (stanford_capx_get_types() as $type => $info) {
    $entity_info['capx_cfe']['bundles'][$type] = array(
      'label' => $info->label,
    );
  }
}

/**
 * Loads a cfe by machine name
 * @param  [type] $machine_name [description]
 * @param  [type] $type The bundle type. eg: mapper, importer
 * @return [type]               [description]
 */
function capx_cfe_load_by_machine_name($machine_name, $type = null) {
  if (is_null($type)) {
    throw new Exception("\$type is required in capx_cfe_load_by_machine_name");
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
 */
function capx_cfe_load_multiple($cfids = FALSE, $conditions = array(), $reset = FALSE) {
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
 * @param  [type] $mapper [description]
 * @return [type]         [description]
 */
function capx_mapper_save($mapper) {
  capx_cfe_save($mapper);
}

/**
 * Wrapper function for capx_cfe_save for importers.
 * @param  [type] $mapper [description]
 * @return [type]         [description]
 */
function capx_importer_save($importer) {
  capx_cfe_save($importer);
}

/**
 * Delete single task.
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
// /////////////////////////////////////////////////////////////////////////////

/**
 * implements hook_entity_delete
 * @param  [type] $entity [description]
 * @param  [type] $type   [description]
 * @return [type]         [description]
 */
function stanford_capx_entity_delete($entity, $type) {
  $entity = entity_metadata_wrapper($type, $entity);
  CAPx::deleteProfileRecord($entity);
}

/**
 * [stanford_capx_entity_insert description]
 * @param  [type] $entity [description]
 * @param  [type] $type   [description]
 * @return [type]         [description]
 */
function stanford_capx_entity_insert($entity, $type) {

}


/**
 * [stanford_capx_entity_update description]
 * @param  [type] $entity [description]
 * @param  [type] $type   [description]
 * @return [type]         [description]
 */
function stanford_capx_entity_update($entity, $type) {

}

/**
 * Add some extra information to every loaded entity.
 *
 * Looks like entity_load gets called A LOT. Especially if a view uses entities
 * rather than fields. So instead of making a number of calls. Call once and
 * static cache.
 *
 * @param  [type] $entities [description]
 * @param  [type] $type     [description]
 * @return [type]           [description]
 */
function stanford_capx_entity_load($entities, $type) {

  $ids = array_keys($entities);
  $meta = &drupal_static(__FUNCTION__, NULL);

  if (empty($meta)) {
    $meta = db_select("capx_profiles", 'capx')
      ->fields('capx')
      ->execute()
      ->fetchAllAssoc('entity_id');
  }

  // Add the capx information if it matches.
  foreach ($ids as $entity_id) {
    // If we do not find a match then carry on.
    if (isset($meta[$entity_id]) && $meta[$entity_id]->entity_type == $type) {
      $entities[$entity_id]->capx = (array) $meta[$entity_id];
    }
  }

}

/**
 * [stanford_capx_entity_view description]
 * @param  [type] $entity    [description]
 * @param  [type] $type      [description]
 * @param  [type] $view_mode [description]
 * @param  [type] $langcode  [description]
 * @return [type]            [description]
 */
function stanford_capx_entity_view($entity, $type, $view_mode, $langcode) {

}

/**
 * Add additional data to the organizations vocabulary terms.
 *
 * We need to track the organization aliases in order to find orphaned profiles.
 * @param  [type] $terms [description]
 * @return [type]        [description]
 */
function stanford_capx_taxonomy_term_load($terms) {

  // The tids of all the terms being loaded.
  $keys = array_keys($terms);
  $aliases = \CAPx\Drupal\Organizations\Orgs::getAliasesByTid($keys);

  // Just end if nothing to do.
  if (empty($aliases)) {
    return;
  }

  $vocab_name = \CAPx\Drupal\Organizations\Orgs::getVocabularyMachineName();
  // For each term add the aliases to them if they are a part of the org vocab.
  foreach($terms as &$term) {
    if ($term->vocabulary_machine_name == $vocab_name) {
      $term->capx = array("aliases" => $aliases);
    }
  }

  return $terms;
}

/**
 * Implements hook_taxonomy_term_save().
 *
 * @param  [type] $terms [description]
 * @return [type]        [description]
 */
function stanford_capx_taxonomy_term_insert($term) {
  stanford_capx_taxonomy_term_update($term);
}

/**
 * Implements hook_taxonomy_term_update.
 * @param  [type] $term [description]
 * @return [type]       [description]
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
// /////////////////////////////////////////////////////////////////////////////

/**
 * Wrapper for entity_get_info() with restricted types removed.
 * @return [type] [description]
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
