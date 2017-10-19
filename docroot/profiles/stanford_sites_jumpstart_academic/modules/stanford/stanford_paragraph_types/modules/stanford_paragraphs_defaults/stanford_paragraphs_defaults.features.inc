<?php

/**
 * @file
 * Stanford_paragraphs_defaults.features.inc.
 *
 * @see http://www.drupalcontrib.org/api/drupal/contributions!features!features.api.php/7
 */

/**
 * Implements hook_features_export_files().
 *
 * Include the default configuration files into the feature.
 */
function stanford_paragraphs_defaults_features_export_files($module_name, $export) {
  $export_files = &drupal_static('stanford_paragraphs_defaults_files');
  if (!$export_files) {
    return array();
  }

  $files = array();
  foreach ($export_files as $feature_name => $feature_files) {
    if ($feature_name != $module_name) {
      continue;
    }

    foreach ($feature_files as $file) {
      $file_name = drupal_basename($file);
      $files["assets/$file_name"] = array(
        'file_path' => $file,
      );
    }
  }

  return $files;
}

/**
 * Implements hook_features_export_options().
 */
function paragraphs_defaults_features_export_options() {
  $defaults = stanford_paragraphs_defaults_load_multiple();
  $items = array();
  foreach ($defaults as $uid => $default) {
    $entity_info = entity_get_info($default['entity_type']);
    $label = $entity_info['label'] . ' - ';
    $label .= $entity_info['bundles'][$default['bundle']]['label'] . ' - ';
    $label .= $default['label'];
    $items[$uid] = $label;
  }
  return $items;
}

/**
 * Implements hook_features_export().
 */
function paragraphs_defaults_features_export($data, &$export, $module_name) {
  $export['dependencies']['stanford_paragraphs_defaults'] = 'stanford_paragraphs_defaults';
  foreach ($data as $uid) {
    $export['features']['paragraphs_defaults'][$uid] = $uid;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 */
function paragraphs_defaults_features_export_render($module_name, $data, $export = NULL) {
  $defaults = stanford_paragraphs_defaults_load_multiple($data);
  $code = array('  $paragraphs_defaults = array();');

  foreach ($defaults as $uid => $item) {
    unset($item['uid'], $item['item_ids']);

    foreach ($item['paragraphs'] as &$paragraph_item) {
      $paragraph_item = _stanford_paragraphs_defaults_prepare_entity($paragraph_item, 'paragraphs_item', $module_name);
    }
    $item['paragraphs'] = array_values($item['paragraphs']);

    $code[] = "  \$paragraphs_defaults['{$uid}'] = " . features_var_export($item, '  ') . ";";
    $code[] = '';
  }

  $code[] = '  return $paragraphs_defaults;';
  return array('paragraphs_defaults' => implode("\n", $code));
}

/**
 * Prepare a given entity to produce a basic object with all field data.
 *
 * @param object $entity
 *   The entity to process.
 * @param string $entity_type
 *   The type of the entity.
 * @param string $module_name
 *   Feature machine name.
 *
 * @return \stdClass
 *   The prepared and processed entity as a standard object for easy export.
 */
function _stanford_paragraphs_defaults_prepare_entity($entity, $entity_type, $module_name) {
  $entity_info = entity_get_info($entity_type);
  $bundle_key = $entity_info['entity keys']['bundle'];

  $fields = field_read_fields(array(
    'entity_type' => $entity_type,
    'bundle' => $entity->{$bundle_key},
  ));

  foreach ($fields as $field_name => $field) {
    // Prepare specific field data depending on the field type.
    // Useful for images, files, field collections etc.
    $prepare_function = '_stanford_paragraphs_defaults_prepare_' . $field['type'];

    if (function_exists($prepare_function)) {
      $field_items = field_get_items($entity_type, $entity, $field_name);
      if ($field_items) {
        $field_items = $prepare_function($field_items, $module_name);
        $entity->{$field_name}[LANGUAGE_NONE] = $field_items;
      }
    }
  }

  // Clone and get just the properties we care about.
  $new_object = new stdClass();
  foreach ($entity as $property => $value) {
    if (!empty($value)) {
      $new_object->{$property} = $value;
    }
  }

  // Unset any unique identifiers.
  foreach ($entity_info['entity keys'] as $key => $field_name) {
    if (!($key == 'bundle' || $key == 'field_name')) {
      unset($new_object->{$field_name});
    }
  }
  unset($new_object->default_revision);

  // Set consistent entity type and bundle for the revert function.
  $new_object->entity_bundle = $entity->{$bundle_key};
  $new_object->entity_type = $entity_type;
  return $new_object;
}

/**
 * Prepare image field type items to only use basic attributes of the image.
 *
 * @param array $field_items
 *   Field items provided by field_get_items().
 * @param string $module_name
 *   Feature machine name.
 *
 * @return array
 *   Prepared field_items.
 */
function _stanford_paragraphs_defaults_prepare_image(array $field_items, $module_name) {
  $files = &drupal_static('stanford_paragraphs_defaults_files');
  foreach ($field_items as &$item) {
    if (!isset($files[$module_name])) {
      $files[$module_name] = array();
    }
    if (!isset($files[$module_name][drupal_basename($item['uri'])])) {
      $files[$module_name][drupal_basename($item['uri'])] = $item['uri'];
    }

    $item = array(
      'filemime' => $item['filemime'],
      'alt' => $item['alt'],
      'title' => $item['title'],
      'uri' => 'assets/' . drupal_basename($item['uri']),
      'filesize' => $item['filesize'],
    );
  }
  return $field_items;
}

/**
 * Prepare file field type items to only use basic attributes of the file.
 *
 * @param array $field_items
 *   Field items provided by field_get_items().
 * @param string $module_name
 *   Feature machine name.
 *
 * @return array
 *   Prepared field_items.
 */
function _stanford_paragraphs_defaults_prepare_file(array $field_items, $module_name) {
  $files = &drupal_static('stanford_paragraphs_defaults_files');
  foreach ($field_items as &$item) {
    if (!isset($files[$module_name])) {
      $files[$module_name] = array();
    }
    if (!isset($files[$module_name][drupal_basename($item['uri'])])) {
      $files[drupal_basename($item['uri'])] = $item['uri'];
    }

    $item = array(
      'filemime' => $item['filemime'],
      'display' => $item['display'],
      'description' => $item['description'],
      'uri' => 'assets/' . drupal_basename($item['uri']),
      'filesize' => $item['filesize'],
    );
  }
  return $field_items;
}

/**
 * Prepare video embed field type items to exclude some data.
 *
 * @param array $field_items
 *   Field items provided by field_get_items().
 * @param string $module_name
 *   Feature machine name.
 *
 * @return array
 *   Prepared field_items.
 */
function _stanford_paragraphs_defaults_prepare_video_embed_field(array $field_items, $module_name = NULL) {
  foreach ($field_items as &$item) {
    // Dont want that part of the field data.
    unset($item['thumbnail_path']);
  }
  return $field_items;
}

/**
 * Prepare paragraphs field type items.
 *
 * @param array $field_items
 *   Field items provided by field_get_items().
 * @param string $module_name
 *   Feature machine name.
 *
 * @return array
 *   Prepared field_items.
 */
function _stanford_paragraphs_defaults_features_prepare_paragraphs(array $field_items, $module_name) {
  foreach ($field_items as &$item) {
    // For some reason it seems drush fu acts differently than through the UI.
    if (is_array($item) && isset($item['value'])) {
      $item = paragraphs_item_load($item['value']);
    }
    $item = _stanford_paragraphs_defaults_prepare_entity($item, 'paragraphs_item', $module_name);
  }
  return $field_items;
}

/**
 * Prepare field collection field type items.
 *
 * @param array $field_items
 *   Field items provided by field_get_items().
 * @param string $module_name
 *   Feature machine name.
 *
 * @return array
 *   Prepared field_items.
 */
function _stanford_paragraphs_defaults_prepare_field_collection(array $field_items, $module_name) {
  foreach ($field_items as &$item) {
    // For some reason it seems drush fu acts differently than through the UI.
    if (is_array($item) && isset($item['value'])) {
      $item = field_collection_item_load($item['value']);
    }
    $item = _stanford_paragraphs_defaults_prepare_entity($item, 'field_collection_item', $module_name);
  }
  return $field_items;
}

/**
 * Implements hook_features_rebuild().
 */
function paragraphs_defaults_features_rebuild($module_name) {
  paragraphs_defaults_features_revert_save($module_name);
}

/**
 * Implements hook_features_revert().
 */
function paragraphs_defaults_features_revert($module_name) {
  paragraphs_defaults_features_revert_save($module_name);
}

/**
 * Try to revert/rebuild the feature.
 *
 * @param string $module_name
 *   Feature name.
 */
function paragraphs_defaults_features_revert_save($module_name) {
  $paragraphs_defaults = module_invoke($module_name, 'paragraphs_defaults');
  if (!empty($paragraphs_defaults)) {
    foreach ($paragraphs_defaults as $paragraph_default) {
      try {
        paragraphs_defaults_save($paragraph_default, $module_name);
      }
      catch (Exception $e) {
        drupal_set_message(t('Unable to rebuild %module_name. Please check the logs for more details.', array('%module_name' => $module_name)));
      }
    }
  }
}

/**
 * Save the features exported default settings.
 *
 * This is where the beast of the save happens.
 *
 * @param array $default
 *   Paragraph default exported.
 */
function paragraphs_defaults_save(array $default, $module_name) {
  // Clear out old default configuration.
  $uid = "{$default['entity_type']}-{$default['bundle']}-{$default['field_name']}-{$default['machine_name']}";
  stanford_paragraphs_defaults_delete_default($uid);

  if (in_array($default['entity_type'], array(
    'paragraphs_item',
    'field_collection_item',
  ))) {
    return;
  }

  // Check if entity type and bundle exist before saving.
  $entity_info = entity_get_info($default['entity_type']);
  if (!$entity_info || !isset($entity_info['bundles'][$default['bundle']])) {
    return;
  }

  // Create the empty entities so field collections can use the host data.
  _stanford_paragraphs_defaults_parse_default($default['paragraphs']);
  // Sets all the field values.
  _stanford_paragraphs_defaults_set_fields($default['paragraphs'], $module_name);
  // Resaves now that the field data has been saved.
  _stanford_paragraphs_defaults_resave($default['paragraphs']);

  // Grab the paragraphs item_id properties.
  $item_ids = array();
  foreach ($default['paragraphs'] as $weight => $paragraph) {
    // If the entity_type or bundle doesn't exist, skip that item.
    if (isset($paragraph['#entity'])) {
      list($item_id, ,) = entity_extract_ids('paragraphs_item', $paragraph['#entity']);
      $item_ids[$item_id] = $weight;
    }
  }

  // Write to the table to track the settings.
  if ($item_ids) {
    $fields = array(
      'label' => $default['label'],
      'machine_name' => $default['machine_name'],
      'entity_type' => $default['entity_type'],
      'field_name' => $default['field_name'],
      'bundle' => $default['bundle'],
      'item_ids' => serialize($item_ids),
    );

    db_merge('stanford_paragraphs_defaults')
      ->insertFields($fields)
      ->updateFields(array(
        'item_ids' => $fields['item_ids'],
      ))
      ->key(array(
        'uid' => $uid,
      ))
      ->execute();
  }
}

/**
 * Recursive function to find the entities to create.
 *
 * @param array|mixed $data
 *   The data to parse.
 * @param null|object $host_entity
 *   The host of the entity if one exists.
 */
function _stanford_paragraphs_defaults_parse_default(&$data, $host_entity_type = NULL, $host_entity = NULL) {
  if (!is_array($data)) {
    return;
  }

  // Find the entities starting points and create a new entity.
  if (isset($data['entity_type'])) {

    // Make sure the bundle exists that its trying to make.
    $entity_info = entity_get_info($data['entity_type']);
    if (!$entity_info || !isset($entity_info['bundles'][$data['entity_bundle']])) {
      return;
    }

    $host_entity = _stanford_paragraphs_defaults_create_entity($data, $host_entity_type, $host_entity);
    $host_entity_type = $data['entity_type'];
  }

  // Continue through the array to get all entities.
  foreach ($data as &$item) {
    _stanford_paragraphs_defaults_parse_default($item, $host_entity_type, $host_entity);
  }
}

/**
 * Using the default data to create an entity.
 *
 * @param array $entity_data
 *   The data from the feature.
 * @param null|object $host_entity
 *   The host entity if one exists.
 *
 * @return object
 *   The created entity.
 */
function _stanford_paragraphs_defaults_create_entity(array &$entity_data, $host_entity_type = NULL, $host_entity = NULL) {
  $entity_vars = array();
  foreach ($entity_data as $key => $value) {
    if (!is_array($value)) {
      $entity_vars[$key] = $value;
    }
  }
  // Create & save the entity.
  $entity = entity_create($entity_data['entity_type'], $entity_vars);
  _stanford_paragraphs_defaults_entity_save($entity_data['entity_type'], $entity, $host_entity_type, $host_entity);
  list($eid, $vid,) = entity_extract_ids($entity_data['entity_type'], $entity);

  // Sets the value & revision_id for field collection entities.
  $entity_data['value'] = $eid;
  $entity_data['revision_id'] = $vid;

  $entity_data['#entity'] = $entity;
  return $entity;
}

/**
 * Recursive function to set the field data and properties of the entities.
 *
 * @param array|mixed $data
 *   The data to find the entities and set fields.
 * @param string $module_name
 *   The feature name.
 */
function _stanford_paragraphs_defaults_set_fields(&$data, $module_name) {
  if (!is_array($data)) {
    return;
  }

  if (isset($data['#entity'])) {
    foreach ($data as $field_name => $value) {
      if (!is_object($value)) {
        // Check field values vs entity properties.
        if (is_array($value)) {
          $lang = key($value);
          _stanford_paragraphs_defaults_process_field_data($value[$lang], $module_name);
        }

        $data['#entity']->{$field_name} = $value;
      }
    }
  }

  // Continue through the array to find any other #entity elements.
  foreach ($data as &$item) {
    _stanford_paragraphs_defaults_set_fields($item, $module_name);
  }
}

/**
 * Make sure the entity has valid data and no embeded entities.
 *
 * @param mixed $entity
 *   Normally the initial entity to clean.
 */
function _stanford_paragraphs_defaults_clean_entity(&$entity) {
  if (!(is_array($entity) || is_object($entity))) {
    return;
  }

  if (is_array($entity) && isset($entity['#entity'])) {
    // Update the field data with the correct entity_id and revision id #s.
    $entity_value = entity_load_single($entity['entity_type'], $entity['value']);
    list($eid, $vid,) = entity_extract_ids($entity['entity_type'], $entity_value);
    $entity['value'] = $eid;
    $entity['revision_id'] = $vid;

    // Make sure we dont have an entity in field data.
    unset($entity['#entity']);
  }

  // Continue through the array to find any other field data to clean.
  foreach ($entity as &$value) {
    _stanford_paragraphs_defaults_clean_entity($value);
  }
}

/**
 * Save the entity differently based on the entity.
 *
 * @param string $entity_type
 *   The entity type to save.
 * @param object $entity
 *   The entity object.
 * @param null|object $host_entity
 *   The host entity if one exists.
 */
function _stanford_paragraphs_defaults_entity_save($entity_type, &$entity, $host_entity_type = NULL, $host_entity = NULL) {
  _stanford_paragraphs_defaults_clean_entity($entity);
  switch ($entity_type) {
    case 'field_collection_item':
      if ($host_entity) {
        $entity->setHostEntity($host_entity_type, $host_entity);
      }
      $entity->save(TRUE);
      break;

    case 'paragraphs_item':
      $entity->save(TRUE);
      break;

    default:
      entity_save($entity_type, $entity);
      break;
  }
}

/**
 * Recursive function to resave the entities after the fields have been set.
 *
 * @param mixed $entity_data
 *   Normally an array to locate and call the save function.
 */
function _stanford_paragraphs_defaults_resave(&$entity_data) {
  if (!is_array($entity_data)) {
    return;
  }

  // Dive deep into the array before saving. This allows the nested entities
  // to be saved first, which then sets the version ids correct for the parent
  // entities.
  foreach ($entity_data as &$item) {
    _stanford_paragraphs_defaults_resave($item);
  }

  if (isset($entity_data['#entity'])) {
    _stanford_paragraphs_defaults_entity_save($entity_data['entity_type'], $entity_data['#entity']);
  }
}

/**
 * Process entity field data to do any type of processing necessary.
 *
 * @param array $values
 *   Field items.
 * @param string $module_name
 *   Feature name.
 */
function _stanford_paragraphs_defaults_process_field_data(array &$values, $module_name) {
  foreach ($values as &$file_data) {

    // If field data is a file, copy and set the field data with the file.
    if (is_array($file_data) && isset($file_data['uri'])) {
      $file = _stanford_paragraphs_defaults_copy_file($file_data, $module_name);
      if ($file) {
        foreach ($file_data as $key => $value) {
          if ($key != 'uri') {
            $file->{$key} = $value;
          }
        }

        $file_data = (array) $file;

      }
      else {
        $file_data = array();
      }
    }
  }
}

/**
 * Copy a module's asset file into the public directory.
 *
 * @param array $file_data
 *   File meta data.
 * @param string $module_name
 *   Feature module name.
 *
 * @return bool|\stdClass
 *   File object if successful, false if failed.
 */
function _stanford_paragraphs_defaults_copy_file(array $file_data, $module_name) {
  $dir = file_default_scheme() . '://paragraphs_defaults';
  file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

  $dir .= "/$module_name";
  file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

  $file_name = drupal_basename($file_data['uri']);

  $fid = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('uri', "$dir/$file_name")
    ->execute()->fetchField();

  // File already exists.
  if ($fid) {
    return file_load($fid);
  }

  $file_path = drupal_get_path('module', $module_name) . '/' . $file_data['uri'];
  if (!file_exists($file_path)) {
    return FALSE;
  }

  // Create a very basic object to be used to copy.
  $old_file = new stdClass();
  foreach ($file_data as $key => $value) {
    $old_file->{$key} = $value;
  }
  $old_file->uri = $file_path;

  // Return the new file object or false if failed.
  return file_copy($old_file, "$dir/$file_name", FILE_EXISTS_REPLACE);
}
