<?php

/**
 * @file
 * Stanford Alt Check Upload Form.
 */

/**
 * Stanford Alt check edit form.
 */
function stanford_alt_check_form($form, &$form_state) {
  if (module_exists('colorbox')) {
    // Allow colorbox-load class to open the image.
    _colorbox_doheader();
  }

  $form['#tree'] = TRUE;
  $form = _stanford_alt_check_filter_form($form, $form_state);

  list($rows, $total_rows) = _stanford_alt_check_get_images();
  foreach ($rows as $row_num => $row) {

    $entity = entity_load_single($row['entity_type'], $row['entity_id']);
    $alt_field = array('#markup' => $row['alt_text']);

    if ($entity && entity_access('update', $row['entity_type'], $entity)) {
      $alt_field = array(
        '#type' => 'textfield',
        '#title' => t('Alt Text for !src', array('!src' => $row['uri'])),
        '#default_value' => $row['alt_text'],
        '#title_display' => 'invisible',
        '#maxlength' => 512,
      );
    }

    $form[$row_num] = array(
      'image' => array('#markup' => _stanford_alt_check_build_image($row['uri'])),
      'title' => array('#markup' => l($row['host_title'], $row['image_meta']['host_uri'])),
      'type' => array('#markup' => $row['host_type']),
      'bundle' => array('#markup' => $row['host_bundle']),
      'published' => array('#markup' => $row['host_published'] ? t('Yes') : t('No')),
      'changed' => array('#markup' => format_interval(time() - $row['host_changed'])),
      'alt' => $alt_field,
    );
    $form_state['images'][$row_num] = $row;
  }

  $form['pager'] = array(
    '#markup' => theme('pager', array(
      'quantity',
      $total_rows,
    )),
  );
  $form['rescan_description'] = array(
    '#prefix' => '<div>',
    '#suffix' => '</div>',
    '#markup' => t('Warning: "Rescan Image" will take some time. Please be patient while it processes. Thank you.'),
  );
  $form['save'] = array('#type' => 'submit', '#value' => t('Save'));
  $form['rescan'] = array(
    '#type' => 'submit',
    '#value' => t('Rescan images'),
    '#submit' => array('_stanford_alt_check_rescan'),
  );
  $form['#attached']['css'][] = drupal_get_path('module', 'stanford_alt_check') . '/css/stanford_alt_check.admin.css';

  return $form;
}

/**
 * Save form submit.
 */
function stanford_alt_check_form_submit($form, &$form_state) {
  $num_changed = 0;
  foreach ($form_state['images'] as $key => $image_data) {
    if ($form_state['values'][$key]['alt'] != $image_data['alt_text']) {
      $num_changed++;
      $entity = entity_load_single($image_data['entity_type'], $image_data['entity_id']);

      if ($image_data['entity_field_wysiwyg']) {
        _stanford_alt_check_wysiwyg_set($entity, $form_state['values'][$key]['alt'], $image_data);
      }
      else {
        $field = $image_data['entity_field'];
        $delta = $image_data['image_meta']['delta'];
        $entity->{$field}[LANGUAGE_NONE][$delta]['alt'] = $form_state['values'][$key]['alt'];
      }
      entity_save($image_data['entity_type'], $entity);
    }
  }
  drupal_set_message(t('Alt text updated for %num images.', array('%num' => $num_changed)));
}

/**
 * Add filter set to the form.
 */
function _stanford_alt_check_filter_form($form, &$form_state) {
  $get = array(
    'alt_text' => NULL,
    'fields' => NULL,
    'host_type' => NULL,
    'host_bundle' => NULL,
    'entity_field_wysiwyg' => NULL,
  );
  $get = array_merge($get, drupal_get_query_parameters($_GET));

  // Filters.
  $form['filter_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter'),
  );
  $form['filter_set']['alt_text'] = array(
    '#type' => 'select',
    '#title' => t('Images'),
    '#options' => array(
      -1 => t('All'),
      'empty' => t('Empty Alt'),
      'filled' => t('Populated Alt'),
    ),
    '#default_value' => $get['alt_text'],
  );
  $form['filter_set']['entity_field_wysiwyg'] = array(
    '#type' => 'select',
    '#title' => t('Fields'),
    '#options' => array(
      -1 => t('All'),
      1 => t('WYSIWYG Fields'),
      0 => t('Upload Fields'),
    ),
    '#default_value' => $get['entity_field_wysiwyg'],
  );
  $form['filter_set']['host_type'] = array(
    '#type' => 'select',
    '#title' => t('Entity Type'),
    '#options' => array(-1 => t('All')) + _stanford_alt_check_column_values('host_type'),
    '#default_value' => $get['host_type'],
    '#ajax' => array(
      'callback' => '_stanford_alt_check_host_bundle',
      'wrapper' => 'host-bundle-select',
    ),
  );

  $condition = array('host_type' => $get['host_type']);
  if (isset($form_state['values']['filter_set']['host_type'])) {
    $host_type = $form_state['values']['filter_set']['host_type'];
    if ($host_type != -1) {
      $condition = array('host_type' => $host_type);
    }
  }

  $form['filter_set']['host_bundle'] = array(
    '#type' => 'select',
    '#title' => t('Entity Bundle'),
    '#options' => array(-1 => t('All')) + _stanford_alt_check_column_values('host_bundle', $condition),
    '#default_value' => $get['host_bundle'],
    '#prefix' => '<div id="host-bundle-select">',
    '#suffix' => '</div>',
  );
  // Filter Buttons.
  $form['filter_set']['actions'] = array('#type' => 'actions');
  $form['filter_set']['actions']['filter_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#name' => 'filter-submit',
    '#submit' => array('_stanford_alt_check_form_filter_submit'),
  );
  $form['filter_set']['actions']['filter_reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#name' => 'filter-reset',
    '#submit' => array('_stanford_alt_check_form_filter_submit'),
  );
  return $form;
}

/**
 * Ajax callback for host_type selection.
 */
function _stanford_alt_check_host_bundle($form, &$form_state) {
  return $form['filter_set']['host_bundle'];
}

/**
 * Grab all distinct values from the table.
 *
 * @param string $column
 *   The column in the table to grab distinct values from.
 * @param array $conditions
 *   Any conditions to apply.
 *
 * @return array
 *   Keyed array of all distinct values.
 */
function _stanford_alt_check_column_values($column, array $conditions = array()) {
  if (!is_string($column) || !db_field_exists('stanford_alt_check', $column)) {
    return array();
  }
  $values = array();

  $query = db_select('stanford_alt_check', 's')
    ->distinct()
    ->fields('s', array($column));

  foreach ($conditions as $key => $value) {
    if ($value) {
      $query->condition($key, $value);
    }
  }

  $results = $query->execute();
  while ($item = $results->fetchField()) {
    $values[$item] = $item;
  }
  return $values;
}

/**
 * Create the html for the linked image.
 *
 * @param string $uri
 *   Image uri.
 *
 * @return string
 *   The html of the image link.
 */
function _stanford_alt_check_build_image($uri) {
  $thumbnail = $original = $uri;
  $uri_parts = parse_url($uri);
  if (count($uri_parts) <= 2) {
    $thumbnail = image_style_url('thumbnail', $uri);
    $original = file_create_url($uri);
  }

  $image_tag = theme('html_tag', array(
    'element' => array(
      '#tag' => 'img',
      '#attributes' => array(
        'src' => $thumbnail,
        'class' => 'alt-check-image',
      ),
    ),
  ));

  $link_tag = theme('html_tag', array(
    'element' => array(
      '#tag' => 'a',
      '#value' => $image_tag,
      '#attributes' => array(
        'href' => $original,
        'class' => 'colorbox-load',
        'target' => '_blank',
      ),
    ),
  ));

  return $link_tag;
}

/**
 * Filter form submit.
 */
function _stanford_alt_check_form_filter_submit($form, &$form_state) {
  if ($form_state['clicked_button']['#name'] == 'filter-reset') {
    $form_state['redirect'] = current_path();
    return;
  }

  $get = drupal_get_query_parameters($_GET);
  $filters = $form_state['values']['filter_set'];
  unset($filters['actions']);

  foreach ($filters as $key => $value) {
    if ($value == -1) {
      unset($get[$key]);
    }
    else {
      $get[$key] = $value;
    }
  }

  $form_state['redirect'] = array(
    current_path(),
    array('query' => array($get)),
  );
}

/**
 * Sets the alt text in the entity using the values from $value.
 *
 * @param object $entity
 *   The main object with the field data.
 * @param string $alt
 *   The alt to set.
 * @param array $image_data
 *   The submitted data.
 */
function _stanford_alt_check_wysiwyg_set($entity, $alt, array $image_data) {
  $field = $image_data['entity_field'];
  $delta = $image_data['image_meta']['delta'];
  $field_items = field_get_items($image_data['entity_type'], $entity, $field);
  $field_item = $field_items[$delta];

  $dom = new DOMDocument();
  libxml_use_internal_errors(TRUE);
  $dom->loadHTML($field_item['value'], LIBXML_HTML_NOIMPLIED | LIBXML_HTML_NODEFDTD);
  /** @var DOMElement $image */
  foreach ($dom->getElementsByTagName('img') as $position => $image) {
    if (
      $position == $image_data['image_meta']['position'] &&
      $image->getAttribute('src') == $image_data['image_meta']['raw_url']
    ) {
      $image->setAttribute('alt', $alt);
      break;
    }
  }
  $field_item['value'] = $dom->saveHTML();

  $entity->{$field}[LANGUAGE_NONE][$delta] = $field_item;
}

/**
 * Find all fieldable entities and create a batch to rescan them.
 */
function _stanford_alt_check_rescan() {
  db_truncate('stanford_alt_check')->execute();

  $batch = array(
    'operations' => array(),
    'title' => t('Rescan Entities'),
    'init_message' => t('Starting to rescan...'),
    'progress_message' => t('Scanned @current out of @total.'),
    'error_message' => t('Unable to rescan all entities.'),
  );

  foreach (entity_get_info() as $type => $definition) {
    if ($definition['fieldable']) {

      // Use EFQ so we dont have to use entity_load() and run out of memory.
      $field_query = new EntityFieldQuery();
      $field_query->entityCondition('entity_type', $type);
      $results = $field_query->execute();

      if ($results && isset($results[$type])) {
        foreach (array_keys($results[$type]) as $entity_id) {
          $batch['operations'][] = array(
            '_stanford_alt_check_rescan_entity',
            array($entity_id, $type),
          );
        }
      }
    }
  }

  batch_set($batch);
}
