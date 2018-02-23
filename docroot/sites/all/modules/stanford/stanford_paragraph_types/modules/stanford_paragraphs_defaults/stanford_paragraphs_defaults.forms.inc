<?php

/**
 * @file
 * Stanford Paragraph Types Defaults Forms.
 */

/**
 * Overview list page of existing defaults.
 */
function stanford_paragraphs_defaults_overview() {
  drupal_set_title(t('Paragraphs Defaults'));
  $path = 'admin/structure/paragraphs/stanford-defaults';
  $output = array();
  foreach (field_read_fields(array('type' => 'paragraphs')) as $field_name => $field) {
    $rows = array();

    $field = field_info_field($field_name);

    foreach ($field['bundles'] as $type => $bundles) {
      // Don't want paragraphs embeded in field collections or other paragraphs
      // fields.
      if (in_array($type, array('paragraphs_item', 'field_collection_item'))) {
        continue;
      }

      $entity_info = entity_get_info($type);

      foreach ($bundles as $bundle) {
        $table_caption = $entity_info['label'] . ' - ';
        $table_caption .= $entity_info['bundles'][$bundle]['label'];
        $table_caption .= ' - ' . $field_name;

        $defaults = stanford_paragraphs_defaults_load_multiple(NULL, $type, $bundle, $field_name);

        foreach ($defaults as $uid => $default) {
          $actions = l(t('Edit'), "$path/edit/$uid") . ' | ';
          $actions .= l(t('Delete'), "$path/delete/$uid");
          $rows[] = array(
            $default['label'],
            $entity_info['label'],
            $entity_info['bundles'][$bundle]['label'],
            $actions,
          );
        }

        $add_link = l(t('Add New Default'), "$path/add/$type/$bundle/$field_name");
        $rows[] = array(
          'data' => array(array('data' => $add_link, 'colspan' => 4)),
        );
        $output[$type][$bundle][$field_name] = array(
          '#theme' => 'table',
          '#caption' => $table_caption,
          '#header' => array(
            t('Name'),
            t('Entity Type'),
            t('Entity Bundle'),
            t('Operations'),
          ),
          '#rows' => $rows,
        );
      }
    }
  }
  if (!$output) {
    $output['message']['#markup'] = t('No paragraph fields configured. Add a paragraph field to content to allow configuration of default settings.');
  }
  return $output;
}

/**
 * Default add form.
 *
 * @param array $form
 *   Drupal_get_form() form.
 * @param array $form_state
 *   Drupal_get_form() form_state.
 * @param string $entity_type
 *   Entity type machine name.
 * @param string $bundle
 *   Entity Bundle machine name.
 * @param string $field_name
 *   Field machine name.
 *
 * @return array
 *   Form render array.
 */
function stanford_paragraphs_defaults_add(array $form, array &$form_state, $entity_type, $bundle, $field_name) {
  if ((!$field = field_info_field($field_name)) || $field['type'] != 'paragraphs') {
    drupal_not_found();
    drupal_exit();
  }

  drupal_set_title(t('Set paragraph defaults for %field_name on %entity_type: %bundle_name', array(
    '%field_name' => $field_name,
    '%entity_type' => $entity_type,
    '%bundle_name' => $bundle,
  )), PASS_THROUGH);

  $form_state['entity_info'] = array(
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'field_name' => $field_name,
  );
  $form = array();

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#required' => TRUE,
  );
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine Name'),
    '#machine_name' => array(
      'exists' => '_stanford_paragraphs_defaults_machine_name',
    ),
  );

  $form['#parents'] = array();

  // Add the paragraphs field.
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);

  $info = entity_get_info($entity_type);
  $entity_vars = array('type' => $bundle);
  foreach ($info['entity keys'] as $key) {
    if ($key) {
      $entity_vars += array($key => NULL);
    }
  }
  $host_entity = entity_create($entity_type, $entity_vars);

  $items = array();
  $paragraphs_field = field_default_form($entity_type, $host_entity, $field, $instance, LANGUAGE_NONE, $items, $form, $form_state);
  $form += (array) $paragraphs_field;

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Add Form validation.
 */
function stanford_paragraphs_defaults_add_validate($form, &$form_state) {
  $field_items = &$form_state['values'][$form_state['entity_info']['field_name']][LANGUAGE_NONE];
  $weights = array();
  foreach ($field_items as &$item) {
    if (!isset($item['entity'])) {
      continue;
    }

    while (isset($weights[$item['_weight']])) {
      $item['_weight']++;
    }
    $weights[$item['_weight']] = $item['_weight'];
  }
}

/**
 * Add Form submit.
 */
function stanford_paragraphs_defaults_add_submit($form, &$form_state) {
  $entity_type = $form_state['entity_info']['entity_type'];
  $bundle = $form_state['entity_info']['bundle'];
  $field_name = $form_state['entity_info']['field_name'];
  $label = $form_state['values']['name'];
  $machine_name = $form_state['values']['machine_name'];
  stanford_paragraphs_defaults_save_defaults($entity_type, $bundle, $field_name, $label, $machine_name, $form_state['values'][$field_name]);
  $form_state['redirect'] = 'admin/structure/paragraphs/stanford-defaults';
}

/**
 * Save the paragraph entities and write to defaults table.
 *
 * @param string $entity_type
 *   Parent entity type.
 * @param string $bundle
 *   Parent entity bundle.
 * @param string $field_name
 *   Field of the paragraphs field.
 * @param string $label
 *   Display label.
 * @param string $machine_name
 *   Machine name of  the default setting.
 * @param array $value
 *   Form submitted values.
 */
function stanford_paragraphs_defaults_save_defaults($entity_type, $bundle, $field_name, $label, $machine_name, array $value) {
  if (isset($value[LANGUAGE_NONE]) && !empty($value[LANGUAGE_NONE])) {
    $item_ids = array();

    // Save the paragraphs items and get the item_id number.
    foreach ($value[LANGUAGE_NONE] as $item) {
      if (isset($item['entity'])) {
        if ($entity = paragraphs_field_get_entity($item)) {
          if (isset($entity->removed) && $entity->removed) {
            $entity->delete();
          }
          else {
            // Save, but don't set the host entity.
            $entity->save(TRUE);
            $item_ids[$entity->item_id] = $item['_weight'];
          }
        }
      }
    }

    if ($item_ids) {
      // Keep track of the entity_id's in our own table.
      $uid = substr("$entity_type-$bundle-$field_name-$machine_name", 0, 254);
      $fields = array(
        'label' => $label,
        'machine_name' => $machine_name,
        'entity_type' => $entity_type,
        'field_name' => $field_name,
        'bundle' => $bundle,
        'item_ids' => serialize($item_ids),
      );
      db_merge('stanford_paragraphs_defaults')
        ->insertFields($fields)
        ->updateFields(array(
          'item_ids' => serialize($item_ids),
        ))
        ->key(array(
          'uid' => $uid,
        ))
        ->execute();
    }
  }
}

/**
 * Machine name callback in add form.
 *
 * @param string $string
 *   Machine name to check.
 * @param array $form
 *   Drupal_get_form() form.
 * @param array $form_state
 *   Drupal_get_form() form_state.
 *
 * @return int
 *   Row count of existing default with same machine name.
 */
function _stanford_paragraphs_defaults_machine_name($string, array $form, array &$form_state) {
  $query = db_select('stanford_paragraphs_defaults', 's')
    ->fields('s')
    ->condition('entity_type', $form_state['entity_info']['entity_type'])
    ->condition('bundle', $form_state['entity_info']['bundle'])
    ->condition('field_name', $form_state['entity_info']['field_name'])
    ->condition('machine_name', $string)
    ->execute()
    ->rowCount();
  return $query;
}

/**
 * Edit default configuration form.
 *
 * @param array $form
 *   Drupal_get_form() form.
 * @param array $form_state
 *   Drupal_get_form() form_state.
 * @param array $default
 *   Default configuration to edit.
 *
 * @return array
 *   Render form array.
 */
function stanford_paragraphs_defaults_edit(array $form, array &$form_state, array $default = array()) {
  $form = stanford_paragraphs_defaults_add($form, $form_state, $default['entity_type'], $default['bundle'], $default['field_name']);
  drupal_set_title($default['label']);

  $form['name']['#default_value'] = $default['label'];
  $form['machine_name']['#default_value'] = $default['machine_name'];
  $form['machine_name']['#attributes'] = array('disabled' => TRUE);

  $info = entity_get_info($default['entity_type']);
  $entity_vars = array('type' => $default['bundle']);

  // Sets the various keys of the entity to null to prevent errors.
  foreach ($info['entity keys'] as $key) {
    if ($key) {
      $entity_vars += array($key => NULL);
    }
  }
  $host_entity = entity_create($default['entity_type'], $entity_vars);

  $field = field_info_field($default['field_name']);
  $instance = field_info_instance($default['entity_type'], $default['field_name'], $default['bundle']);

  $items = array();
  foreach ($default['paragraphs'] as $paragraph_item) {
    $items[]['entity'] = $paragraph_item;
  }

  unset($form[$default['field_name']]);
  $field_state = &$form_state['field'][$default['field_name']][LANGUAGE_NONE];
  if (!$field_state['items_count']) {
    $field_state['items_count'] = count($items);
  }

  $paragraphs_field = field_default_form($default['entity_type'], $host_entity, $field, $instance, LANGUAGE_NONE, $items, $form, $form_state);
  $form += (array) $paragraphs_field;

  $form['#submit'][] = 'stanford_paragraphs_defaults_add_submit';
  $form['#validate'][] = 'stanford_paragraphs_defaults_add_validate';

  return $form;
}

/**
 * Delete default configuration form.
 *
 * @param array $form
 *   Drupal_get_form() form.
 * @param array $form_state
 *   Drupal_get_form() form_state.
 * @param array $default
 *   Default configuration to edit.
 *
 * @return array
 *   Render form array.
 */
function stanford_paragraphs_defaults_delete(array $form, array &$form_state, array $default) {
  $form_state['#default'] = $default;
  $path = 'admin/structure/paragraphs/stanford-defaults';
  $question = t('Delete default setting %label', array('%label' => $default['label']));
  $description = t('This action cannot be undone.');
  $form = confirm_form($form, $question, $path, $description, t('Delete'));
  return $form;
}

/**
 * Delete form submit.
 */
function stanford_paragraphs_defaults_delete_submit($form, &$form_state) {
  stanford_paragraphs_defaults_delete_default($form_state['#default']['uid']);
  drupal_set_message(t('Default Configuration deleted'));
  $form_state['redirect'] = 'admin/structure/paragraphs/stanford-defaults';
}
