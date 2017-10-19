<?php

/**
 * @file
 * CAPx Filters forms.
 */

use \CAPx\Drupal\Util\CAPx;
use \CAPx\Drupal\Entities\CFEntity;

/**
 * Form builder factory function.
 *
 * @param string $action
 *   The filter action.
 * @param object $importer
 *   The importer object.
 * @param int $filter_id
 *   The id of the filter.
 *
 * @return array
 *   The form array.
 */
function capx_filters_build_form($action, $importer, $filter_id = -1) {
  $form_id = "capx_filters_$action";
  return drupal_get_form($form_id, $importer, $filter_id);
}

/**
 * Menu Callback to display current filters active on the CAPx mapper.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $importer
 *   An instance of a CFEntity importer object.
 * @param int $filter_id
 *   The integer id (key/order) of the filter.
 *
 * @return array
 *   The form array.
 */
function capx_filters_list(array $form, array &$form_state, CFEntity $importer, $filter_id = NULL) {
  // Set the page title.
  drupal_set_title($importer->title . " Filters");

  $filters = array();
  if (isset($importer->settings['filters'])) {
    foreach ($importer->settings['filters'] as $key => $filter) {
      $actions = l(t('Edit'), CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters/$key/edit");
      $actions .= ' | ';
      $actions .= l(t('Delete'), CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters/$key/delete");
      $filters[] = array(
        'key' => $filter['key'],
        'comparison' => $filter['comparison'],
        'value' => $filter['value'],
        'exclude' => $filter['exclude'] ? 'Exclude' : 'Include',
        'actions' => $actions,
      );
    }
  }

  $form['menu'] = stanford_capx_management_menu_block();

  $form['table'] = array(
    '#theme' => 'table',
    '#header' => array(
      t('Path'),
      t('Comparison'),
      t('Value'),
      t('Include/Exclude'),
      t('Actions'),
    ),
    '#rows' => $filters,
    '#empty' => t('No Filters Configured'),
  );

  $add_button = l(t("+ Add New Filter"), CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters/add", array("attributes" => array("class" => array("button"))));
  $form['addbutton'] = array(
    "#markup" => $add_button,
  );

  $form['delete'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filters Delete'),
  );

  $form['delete']['filters_delete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove existing on match'),
    '#description' => t('If checked, existing content will be deleted if it matches a filter. Content from the API can change and when it does a previously imported item that now matches a filter will be removed from this website.'),
    '#default_value' => isset($importer->filters_delete) ? $importer->filters_delete : 0,
  );

  $form['delete']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for the filters list form.
 *
 * Saves and sets variables for the filter form on an importer.
 *
 * @param array $form
 *   The form.
 * @param array $form_state
 *   The form state array from submission.
 */
function capx_filters_list_submit(array $form, array &$form_state) {

  // Set a global variable so that other hooks can patch up the entity save.
  global $_capx_filters_updated;
  $_capx_filters_updated = TRUE;

  $importer = $form_state['build_info']['args'][0];
  $importer->settings['filters_delete'] = $form_state['values']['filters_delete'];
  entity_save('capx_cfe', $importer);

  drupal_set_message(t('Settings Saved'));
}

/**
 * Form to create or edit a filter for the given CAPx Importer.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $importer
 *   An instance of a CFEntity importer object.
 * @param int $filter_id
 *   The integer id (key/order) of the filter.
 *
 * @return array
 *   The form array.
 */
function capx_filters_edit(array $form, array &$form_state, CFEntity $importer, $filter_id = -1) {
  $key = '';
  $value = '';
  $comparison = '=';
  $exclude = 0;

  if ($filter_id !== -1) {
    // Filter ID was given, but check to see if it actually exists.
    if (isset($importer->settings['filters']) && isset($importer->settings['filters'][$filter_id])) {
      $filter = $importer->settings['filters'][$filter_id];
      $key = $filter['key'];
      $value = $filter['value'];
      $comparison = $filter['comparison'];
      $exclude = $filter['exclude'];

      drupal_set_title(t('!importer Filter #!id', array(
        '!importer' => $importer->label(),
        '!id' => $filter_id + 1,
      )));
    }
    else {
      drupal_not_found();
      drupal_exit();
    }
  }
  else {
    drupal_set_title(t('Add Filter to !importer', array('!importer' => $importer->label())));
  }

  $breadcrumbs = array(
    l(t('Home'), '/'),
    l(t('Administration'), '/admin'),
    l(t('Configuration'), '/admin/config'),
    l(t('CAPx'), '/admin/config/capx'),
    l(t('Import'), '/admin/config/capx/import'),
    l(t($importer->label()), '/admin/config/capx/importer/' . $importer->getMachineName() . '/filters'),
  );
  drupal_set_breadcrumb($breadcrumbs);

  // Filter exists and is valid. Carry on and generate a form.
  $form = array();

  $form['mapper_id'] = array(
    '#type' => 'hidden',
    '#value' => $importer->getMachineName(),
  );
  $form['filter_id'] = array(
    '#type' => 'hidden',
    '#value' => $filter_id,
  );
  $form['key'] = array(
    '#type' => 'textfield',
    '#title' => t('CAP API path'),
    '#default_value' => $key,
    '#required' => TRUE,
  );
  $form['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#default_value' => $value,
  );
  $form['comparison'] = array(
    '#type' => 'select',
    '#title' => t('Comparison operation'),
    '#options' => array(
      'Boolean' => array(
        'bool' => t("True / False"),
      ),
      'Text' => array(
        '=' => '=',
        '!=' => '!=',
        'contains' => t('Contains'),
      ),
      'Numeric' => array(
        '>' => '>',
        '<' => '<',
      ),
      'Date' => array(
        'before' => t('Before'),
        'after' => t('After'),
      ),
      'Other' => array(
        'not empty' => t('Not Empty'),
      ),
    ),
    '#default_value' => $comparison,
    '#required' => TRUE,
  );
  $form['exclude'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude content with this value'),
    '#default_value' => $exclude,
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#name' => 'submit',
  );
  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#name' => 'cancel',
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'stanford_capx') . '/js/stanford_capx.mapper.form.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'capx_filters') . '/css/capx_filters.css';
  $form['#attributes'] = array('id' => array('stanford-capx-mapper-form'));
  return $form;
}

/**
 * Validation function for filter create/edit form.
 *
 * Sets a form error if there is a validation issue.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function capx_filters_edit_validate(array $form, array &$form_state) {
  if ($form_state['clicked_button']['#name'] == 'cancel') {
    return;
  }

  if ($form_state['values']['comparison'] == 'before' || $form_state['values']['comparison'] == 'after') {
    $date = capx_filters_parse_date($form_state['values']['value']);
    if (!$date) {
      form_set_error('value', t('Invalid date string.'));
    }
  }
}

/**
 * Saves the filter to the given CAPx Mapper.
 */
function capx_filters_edit_submit(array $form, array &$form_state) {
  /** @var CFEntity $importer */
  $importer = $form_state['build_info']['args'][0];

  if ($form_state['clicked_button']['#name'] == 'cancel') {
    $form_state['redirect'] = CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters";
    return;
  }

  global $_capx_filters_updated;
  $_capx_filters_updated = TRUE;

  $filter = array(
    'key' => $form_state['values']['key'],
    'value' => strtolower($form_state['values']['value']),
    'comparison' => $form_state['values']['comparison'],
    'exclude' => $form_state['values']['exclude'],
  );

  if (!isset($importer->settings['filters'])) {
    $importer->settings['filters'] = array();
  }

  if ($form_state['values']['filter_id'] !== -1) {
    $importer->settings['filters'][$form_state['values']['filter_id']] = $filter;
  }
  else {
    array_push($importer->settings['filters'], $filter);
  }

  $importer->settings['filters'] = array_values($importer->settings['filters']);
  capx_mapper_save($importer);

  // When filters change we must invalidate the etags to ensure that profiles
  // get updated again.
  CAPx::invalidateEtags('importer', $importer);

  $form_state['redirect'] = CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters";
}

/**
 * Form to confirm the deletion of the filter.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param object $importer
 *   An instance of a CFEntity importer object.
 * @param int $filter_id
 *   The integer id (key/order) of the filter.
 *
 * @return array
 *   The form array.
 */
function capx_filters_delete(array $form, array &$form_state, CFEntity $importer, $filter_id) {
  drupal_set_title(t('Delete Filter #!id from !label?', array(
    '!id' => $filter_id + 1,
    '!label' => $importer->label(),
  )));
  $form = array();
  $form['disclaimer'] = array(
    '#markup' => t('Are you sure you wish to delete this filter? This action cannot be undone'),
  );
  $form['mapper_id'] = array(
    '#type' => 'hidden',
    '#value' => $importer->getMachineName(),
  );
  $form['filter_id'] = array(
    '#type' => 'hidden',
    '#value' => $filter_id,
  );
  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#name' => 'delete',
    '#value' => t('Delete'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#name' => 'cancel',
    '#value' => t('Cancel'),
  );

  return $form;
}

/**
 * Removes the filter from the CAPx mapper settings array.
 */
function capx_filters_delete_submit(array $form, array &$form_state) {

  // Used in entity save functions elsewhere.
  global $_capx_filters_updated;
  $_capx_filters_updated = TRUE;

  // @var CFEntity $importer.
  $importer = $form_state['build_info']['args'][0];

  $form_state['redirect'] = CAPX_FILTERS_PAGE . "/{$importer->getMachineName()}/filters";
  if ($form_state['triggering_element']['#name'] == 'cancel') {
    return;
  }

  unset($importer->settings['filters'][$form_state['values']['filter_id']]);
  $importer->settings['filters'] = array_values($importer->settings['filters']);
  capx_mapper_save($importer);

  // When filters change we must invalidate the etags to ensure profiles get
  // updated on the next sync.
  CAPx::invalidateEtags('importer', $importer);
}
