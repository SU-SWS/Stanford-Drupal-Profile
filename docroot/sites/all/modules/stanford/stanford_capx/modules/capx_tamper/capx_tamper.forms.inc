<?php

/**
 * @file
 * CAPx Tamper Forms.
 *
 * Mostly taken from feeds_tamper_ui.admin.inc.
 */

use \CAPx\Drupal\Entities\CFEntity;

/**
 * Form builder. Calls the correct form for the action.
 *
 * @param string $action
 *   Add, Edit, or Delete.
 * @param CFEntity $mapper
 *   CAPx Mapper.
 * @param string|null $source
 *   JSON Path string.
 *
 * @return array
 *   Form render array.
 */
function capx_tamper_build_form($action, CFEntity $mapper, $source = NULL) {
  $form_name = "capx_tamper_{$action}_form";
  return drupal_get_form($form_name, $mapper, $source);
}

/**
 * Shows the current tampers in table format for the given CAPx Mapper.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State.
 * @param CFEntity $mapper
 *   Mapper to apply tamper to.
 * @param null $source
 *   Null source since we want all sources.
 *
 * @return array
 *   Renderable array.
 */
function capx_tamper_list_form($form, &$form_state, CFEntity $mapper, $source = NULL) {
  drupal_set_title(t('!mapper Tamper Plugins', array('!mapper' => $mapper->title)));
  capx_tamper_breadcrumb($mapper);

  $form['#tree'] = TRUE;
  $form['mapper'] = array(
    '#type' => 'hidden',
    '#value' => $mapper->getMachineName(),
  );

  $sources = capx_tamper_get_mapper_sources($mapper);

  foreach ($sources as $target => $path) {
    if (!$path) {
      continue;
    }
    $path_tampers = capx_tamper_load_tampers(array(
      'mapper' => $mapper->getMachineName(),
      'target' => $target,
    ));

    if ($instance = field_info_instance($mapper->entity_type, $target, $mapper->bundle_type)) {
      $target_label = $instance['label'];
    }
    else {
      $target_label = ucwords($target);
    }

    $form['tampers'][$target] = array(
      'caption' => array(
        '#markup' => t('!to <- !from', array(
          '!from' => $path,
          '!to' => $target_label,
        )),
      ),
    );

    foreach ($path_tampers as $tamper) {
      $edit_url = CAPX_TAMPER . "/{$mapper->getMachineName()}/tamper/{$tamper->id}/edit";
      $delete_url = CAPX_TAMPER . "/{$mapper->getMachineName()}/tamper/{$tamper->id}/delete";
      $operations = l(t('Edit'), $edit_url) . " | " . l(t('Delete'), $delete_url);
      $plugin = feeds_tamper_get_plugin($tamper->plugin_id);

      $form['tampers'][$target][$tamper->id]['description'] = array(
        '#markup' => t($tamper->description),
      );
      $form['tampers'][$target][$tamper->id]['plugin_id'] = array(
        '#markup' => t($plugin['name']),
      );
      $form['tampers'][$target][$tamper->id]['operations'] = array(
        '#markup' => $operations,
      );
      $form['tampers'][$target][$tamper->id]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $tamper->weight,
        '#attributes' => array(
          'class' => array(capx_tamper_table_id($target) . '-weight'),
        ),
      );
      $form['tampers'][$target][$tamper->id]['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enabled'),
        '#default_value' => @!$tamper->disabled,
      );
    }
    $form['tampers'][$target]['add_link'] = array(
      '#markup' => l(t('Add Plugin'), CAPX_TAMPER . "/{$mapper->getMachineName()}/tamper/add/" . bin2hex("$target:$path")),
      '#prefix' => '<ul class="feeds-tamper-add action-links"><li>',
      '#suffix' => '</li></ul>',
    );
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['#attached']['css'] = array(drupal_get_path('module', 'capx_tamper') . '/css/capx_tamper.css');
  return $form;
}

/**
 * List form submit. Sets weights & enabled/disabled.
 */
function capx_tamper_list_form_submit($form, &$form_state) {
  $disabled = variable_get('capx_tamper_disabled', array());
  foreach ($form_state['values']['tampers'] as $tampers) {
    foreach ($tampers as $id => $settings) {
      $tamper = capx_tamper_load_tampers(array('id' => $id));
      $tamper = reset($tamper);
      $tamper->weight = $settings['weight'];
      capx_tamper_save_instance($tamper);

      if (!$settings['enabled']) {
        $disabled[$tamper->id] = TRUE;
      }
      else {
        unset($disabled[$tamper->id]);
      }
    }
  }
  variable_set('capx_tamper_disabled', $disabled);
  drupal_set_message(t('Settings saved'));
}

/**
 * Tamper add form.
 *
 * @param CFEntity $mapper
 *   CAPx Mapper used for the tamper.
 * @param string $source
 *   JSON string path.
 *
 * @return array
 *   Form render array.
 */
function capx_tamper_add_form($form, &$form_state, CFEntity $mapper, $target_source) {
  list($target, $source) = explode(':', hex2bin($target_source), 2);

  drupal_set_title(t('Add Tamper Plugin for !to <- !from', array(
    '!from' => $source,
    '!to' => $target,
  )));
  capx_tamper_breadcrumb($mapper, TRUE);

  $form_state['mapper'] = $mapper;
  $form_state['source'] = $source;
  $form_state['target'] = $target;

  // Build plugin select list.
  $capx_tamper_plugins = feeds_tamper_get_plugins();
  $plugins = array();
  foreach ($capx_tamper_plugins as $plugin_id => $plugin) {
    $plugins[t($plugin['category'])][$plugin_id] = t($plugin['name']);
  }
  ksort($plugins);
  foreach ($plugins as &$p) {
    asort($p);
  }

  // Unsupported tampers.
  unset($plugins[t('Filter')]);
  unset($plugins[t('Field Collection')]);

  $machine_name = key(reset($plugins));
  if (!empty($form_state['values']['plugin_id'])) {
    $machine_name = $form_state['values']['plugin_id'];
  }
  $plugin = feeds_tamper_get_plugin($machine_name);

  $form['plugin_id'] = array(
    '#title' => t('The plugin to add'),
    '#type' => 'select',
    '#options' => $plugins,
    '#default_value' => '',
    '#tree' => TRUE,
    '#ajax' => array(
      'callback' => 'capx_tamper_ajax_callback',
      'wrapper' => 'capx-tamper-plugin',
      'progress' => 'none',
    ),
  );
  $form['update'] = array(
    '#type' => 'submit',
    '#limit_validation_errors' => array(array('plugin_id')),
    '#submit' => array('capx_tamper_ui_add_plugin_form_submit'),
    '#value' => t('Choose'),
    '#attributes' => array('class' => array('no-js')),
  );
  $form['plugin']['#prefix'] = '<div class="clear-fix" id="capx-tamper-plugin">';
  $form['plugin']['#suffix'] = '</div>';

  $form['plugin']['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => $plugin['default description'] ? t($plugin['default description']) : t($plugin['name']),
    '#required' => TRUE,
    '#description' => t('A useful description of what this plugin is doing.'),
  );
  $form['plugin']['id'] = array(
    '#title' => t('Machine name'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'capx_tamper_machine_name_callback',
      'source' => array('plugin', 'description'),
    ),
    '#default_value' => $machine_name,
  );
  $form['plugin']['settings'] = array(
    '#title' => t('Configure @name', array('@name' => $plugin['name'])),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $parser = new CapxTamperParser();
  $processor = new CapxTamperProcessor($mapper);
  $importer = new CapxTamper($mapper, $parser, $processor);

  $form['plugin']['settings'] += $plugin['form']($importer, $source, array(), $form_state);
  $form['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'capx_tamper') . '/css/capx_tamper.css';

  return $form;
}

/**
 * Tamper add form validation.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 */
function capx_tamper_add_form_validate($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Add')) {
    if (capx_tamper_machine_name_callback($form_state['values']['id'], $form, $form_state)) {
      form_set_error('id', t('The machine-readable name is already in use. It must be unique.'));
      return;
    }
    $plugin_id = $form_state['values']['plugin_id'];
    $plugin = feeds_tamper_get_plugin($plugin_id);
    if ($plugin['validate'] && isset($form_state['values']['settings'])) {
      $plugin['validate']($form_state['values']['settings']);
    }
    return;
  }
  unset($form_state['input']['id']);
  unset($form_state['input']['description']);
  unset($form_state['input']['settings']);
}

/**
 * Tamper add form submit to save to table.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 */
function capx_tamper_add_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Add')) {
    /** @var CFEntity $mapper */
    $mapper = $form_state['mapper'];
    $id = implode('-', array(
      $mapper->identifier(),
      $form_state['source'],
      $form_state['target'],
      $form_state['values']['id'],
    ));

    $tamper = new stdClass();
    $tamper->id = $id;
    $tamper->mapper = $mapper->identifier();
    $tamper->source = $form_state['source'];
    $tamper->target = $form_state['target'];
    $tamper->plugin_id = $form_state['values']['plugin_id'];
    $tamper->settings = $form_state['values']['settings'];
    $tamper->weight = '0';
    $tamper->description = $form_state['values']['description'];

    if (capx_tamper_save_instance($tamper)) {
      $form_state['redirect'] = CAPX_TAMPER . "/{$mapper->identifier()}/tamper";
      drupal_set_message(t('Plugin %description was successfully added to %source.', array(
        '%description' => $form_state['values']['description'],
        '%source' => $form_state['source'],
      )));
      return;
    }
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Tamper plugin edit form.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 * @param CFEntity $mapper
 *   CAPx Mapper used for the tamper.
 * @param string $tamper_id
 *   CAPx Tamper id.
 *
 * @return array
 *   Form render array.
 */
function capx_tamper_edit_form($form, &$form_state, CFEntity $mapper, $tamper_id) {
  $tamper = capx_tamper_load_tampers(array('id' => $tamper_id));
  $tamper = reset($tamper);
  if (!$tamper) {
    drupal_not_found();
    drupal_exit();
  }
  capx_tamper_breadcrumb($mapper, TRUE);

  $form_state['mapper'] = $mapper;
  $form_state['tamper'] = $tamper;

  drupal_set_title(t('Edit !title', array('!title' => $tamper->description)));

  $plugin = feeds_tamper_get_plugin($tamper->plugin_id);
  $form['#tree'] = TRUE;

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#description' => t('A useful description of what this plugin is doing.'),
    '#default_value' => $tamper->description,
  );
  $form['settings'] = array(
    '#title' => t('Configure @plugin', array('@plugin' => $plugin['name'])),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $parser = new CapxTamperParser();
  $processor = new CapxTamperProcessor($mapper);
  $importer = new CapxTamper($mapper, $parser, $processor);

  $form['settings'] += $plugin['form']($importer, $tamper->source, $tamper->settings, $form_state);

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'capx_tamper') . '/css/capx_tamper.css';
  return $form;
}

/**
 * Tamper edit validation.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 */
function capx_tamper_edit_form_validate($form, &$form_state) {
  $plugin_id = $form_state['tamper']->plugin_id;
  $plugin = feeds_tamper_get_plugin($plugin_id);
  if ($plugin['validate']) {
    $plugin['validate']($form_state['values']['settings']);
  }
}

/**
 * Tamper plugin edit submit.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 */
function capx_tamper_edit_form_submit($form, &$form_state) {
  $mapper = $form_state['mapper'];
  $tamper = $form_state['tamper'];
  if (isset($form_state['values']['settings'])) {
    $tamper->settings = $form_state['values']['settings'];
  }
  $tamper->description = $form_state['values']['description'];

  if (capx_tamper_save_instance($tamper)) {
    drupal_set_message(t('The plugin %plugin has been updated.', array('%plugin' => $tamper->description)));
    $form_state['redirect'] = CAPX_TAMPER . "/{$mapper->identifier()}/tamper";
  }
}

/**
 * Confirmation of delete tamper.
 *
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 * @param CFEntity $mapper
 *   CAPx Mapper used for the tamper.
 * @param string $tamper_id
 *   CAPx Tamper id.
 *
 * @return array
 *   Form render array.
 */
function capx_tamper_delete_form($form, &$form_state, CFEntity $mapper, $tamper_id) {
  capx_tamper_breadcrumb($mapper, TRUE);
  $tamper = capx_tamper_load_tampers(array('id' => $tamper_id));
  $tamper = reset($tamper);
  $form_state['tamper'] = $tamper;
  $form_state['mapper'] = $mapper;
  $question = t('Would you really like to delete the plugin @tamper?', array('@tamper' => $tamper->description));
  $button_label = t('Delete');

  return confirm_form(
    $form,
    $question,
    CAPX_TAMPER . "/{$mapper->identifier()}/tamper",
    NULL,
    $button_label
  );
}

/**
 * Tamper delete form submit.
 */
function capx_tamper_delete_form_submit($form, &$form_state) {
  $tamper = $form_state['tamper'];
  /** @var CFEntity $mapper */
  $mapper = $form_state['mapper'];
  capx_tamper_delete_instance($tamper);
  drupal_set_message(t('The plugin %plugin has been deleted from %source.', array(
    '%plugin' => $tamper->description,
    '%source' => $tamper->source,
  )));
  $form_state['redirect'] = CAPX_TAMPER . "/{$mapper->identifier()}/tamper";
}

/**
 * Checks for existing machine name.
 *
 * @param string $id
 *   Machine name of the new plugin.
 * @param array $form
 *   Form Array.
 * @param array $form_state
 *   Form State Array.
 *
 * @return array
 *   Array of the existing tamper or an empty array.
 */
function capx_tamper_machine_name_callback($id, $form, &$form_state) {
  $check_id = implode('-', array(
    $form_state['mapper']->identifier(),
    $form_state['source'],
    $form_state['target'],
    $form_state['values']['id'],
  ));
  return capx_tamper_load_tampers(array('id' => $check_id));
}

/**
 * Ajax callback for add plugin form.
 */
function capx_tamper_ajax_callback($form, $form_state) {
  return $form['plugin'];
}

/**
 * Sets the breadcrumb links for the page.
 *
 * @param CFEntity $mapper
 *   CAPx Mapper in use.
 * @param bool $show_tamper
 *   Show the tamper page in the breadcrumb.
 */
function capx_tamper_breadcrumb(CFEntity $mapper, $show_tamper = FALSE) {
  $breadcrumb = array(
    l(t('Home'), '/'),
    l(t('Administration'), '/admin'),
    l(t('Configuration'), '/admin/config'),
    l(t('CAPx'), '/admin/config/capx'),
    l(t('Map'), '/admin/config/capx/mapper'),
    l(t($mapper->title), CAPX_TAMPER . "/edit/{$mapper->getMachineName()}"),
  );

  if ($show_tamper) {
    $breadcrumb[] = l(t('Tamper'), CAPX_TAMPER . "/{$mapper->getMachineName()}/tamper");
  }
  drupal_set_breadcrumb($breadcrumb);
}
