<?php

/**
 * @file
 * Calls results to administration's pages for the Node Revision Delete module.
 */

/**
 * Form constructor for Node Revision Delete administration form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function node_revision_delete_admin_settings_form(array $form, array &$form_state) {
  // Table header.
  $header = array(
    t('Content type'),
    t('Machine name'),
    t('Minimum to keep'),
    t('Minimum age'),
    t('When to delete'),
    t('Candidate nodes'),
    t('Operations'),
  );

  // Table rows.
  $rows = array();

  // Getting the config variables.
  $node_revision_delete_track = variable_get('node_revision_delete_track', array());
  // Looking for all the content types.
  $content_types = node_type_get_types();
  // Check if exists candidates nodes.
  $exists_candidates_nodes = FALSE;

  // Return to the same page after save the content type.
  $destination = 'admin/config/content/node_revision_delete';
  foreach ($content_types as $content_type) {
    // Operations dropbutton.
    $operations = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'admin/structure/types/manage/' . $content_type->type,
        'query' => array('destination' => $destination),
      ),
    );

    if (isset($node_revision_delete_track[$content_type->type])) {
      // Minimum revisions to keep in the database.
      $minimum_revisions_to_keep = $node_revision_delete_track[$content_type->type]['minimum_revisions_to_keep'];

      // Minimum age to delete (is a number, 0 for none).
      $minimum_age_to_delete_number = $node_revision_delete_track[$content_type->type]['minimum_age_to_delete'];
      $minimum_age_to_delete = (bool) $minimum_age_to_delete_number ? _node_revision_delete_time_string('minimum_age_to_delete', $minimum_age_to_delete_number) : t('None');

      // When to delete time (is a number, 0 for always).
      $when_to_delete_number = $node_revision_delete_track[$content_type->type]['when_to_delete'];
      $when_to_delete = (bool) $when_to_delete_number ? _node_revision_delete_time_string('when_to_delete', $when_to_delete_number) : t('Always delete');

      // Number of candidates nodes to delete theirs revision.
      $candidate_nodes = count(_node_revision_delete_candidates($content_type->type, $minimum_revisions_to_keep, $minimum_age_to_delete_number, $when_to_delete_number));
      // If we have candidates nodes then we will allow to run the batch job.
      if ($candidate_nodes && !$exists_candidates_nodes) {
        $exists_candidates_nodes = TRUE;
      }
      // Action to delete the configuration for the content type.
      $operations['untrack'] = array(
        'title' => t('Untrack'),
        'href' => '/admin/config/content/node_revision_delete/delete/' . $content_type->type,
        'query' => array('destination' => $destination),
      );
    }
    else {
      $minimum_revisions_to_keep = t('Untracked');
      $candidate_nodes = '-';
      $when_to_delete = t('Untracked');
      $minimum_age_to_delete = t('Untracked');
    }

    // We have ctools?
    if (module_exists('ctools')) {
      // Hack to get consistent style with views ctools dropbutton.
      if (module_exists('views_ui')) {
        if (module_load_include('inc', 'views_ui', 'includes/admin')) {
          foreach (views_ui_get_admin_css() as $file => $options) {
            drupal_add_css($file, $options);
          }
        }
      }
      // Rendering the dropbutton.
      $links = array(
        'links' => $operations,
        'attributes' => array(
          'class' => array(
            'links',
          ),
        ),
      );

      $dropbutton = '<div class="admin-operations">' . theme('links__ctools_dropbutton', $links) . '</div>';
    }
    else {
      $operations_list = array();
      foreach ($operations as $key => $value) {
        $link = l($operations[$key]['title'], $operations[$key]['href'], array('query' => $operations[$key]['query']));
        $operations_list[$key] = array('data' => $link);
      }

      $links = array(
        'items' => $operations_list,
        'attributes' => array(
          'class' => array(
            'links',
            'inline',
          ),
        ),
      );

      $links['attributes']['class'][] = 'inline';
      $dropbutton = '<div class="admin-operations">' . theme('item_list', $links) . '</div>';
    }
    // Setting the row values.
    $rows[] = array(
      $content_type->name,
      $content_type->type,
      $minimum_revisions_to_keep,
      $minimum_age_to_delete,
      $when_to_delete,
      $candidate_nodes,
      array('data' => '<div class="links">' . $dropbutton . '</div>', 'class' => array('links')),
    );
  }
  // Table with current configuration.
  $form['current_configuration'] = array(
    '#theme' => 'table',
    '#caption' => t('Current configuration'),
    '#header' => $header,
    '#rows' => $rows,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'node_revision_delete') . '/css/node_revision_delete.css',
      ),
    ),
  );
  // Available options for node_revision_delete_cron variable.
  $options_node_revision_delete_cron = array(
    10 => 10,
    20 => 20,
    50 => 50,
    100 => 100,
    200 => 200,
    500 => 500,
    1000 => 1000,
  );

  $form['node_revision_delete_cron'] = array(
    '#type' => 'select',
    '#title' => t('How many revisions do you want to delete per cron run?'),
    '#description' => t('Deleting node revisions is a database intensive task. Increase this value if you think that the server can handle more deletions per cron run.'),
    '#options' => $options_node_revision_delete_cron,
    '#default_value' => variable_get('node_revision_delete_cron'),
  );

  // Available options for node_revision_delete_time variable.
  $options_node_revision_delete_time = _node_revision_delete_time_value();
  $form['node_revision_delete_time'] = array(
    '#type' => 'select',
    '#title' => t('How often should revision be deleted while cron runs?'),
    '#description' => t('Frequency of the scheduled mass revision deletion.'),
    '#options' => $options_node_revision_delete_time,
    '#default_value' => variable_get('node_revision_delete_time'),
  );
  // Time options.
  $allowed_time = array(
    'days' => t('Days'),
    'weeks' => t('Weeks'),
    'months' => t('Months'),
  );
  // Configuration for the node_revision_delete_minimum_age_to_delete_time
  // variable.
  $form['minimum_age_to_delete'] = array(
    '#type' => 'fieldset',
    '#title' => t('Minimum age of revision to delete configuration'),
  );

  $node_revision_delete_minimum_age_to_delete_time = variable_get('node_revision_delete_minimum_age_to_delete_time');
  $form['minimum_age_to_delete']['node_revision_delete_minimum_age_to_delete_time_max_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number allowed'),
    '#description' => t('The maximum number in the "Minimum age of revision to delete" configuration in each content type edit page. If you change this number and the new value is smaller than the value defined for a content type in the "Minimum age of revision to delete" setting, the "Minimum age of revision to delete" setting for that content type will take it.'),
    '#default_value' => $node_revision_delete_minimum_age_to_delete_time['max_number'],
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['minimum_age_to_delete']['node_revision_delete_minimum_age_to_delete_time_time'] = array(
    '#type' => 'select',
    '#title' => t('The time value'),
    '#description' => t('The time value allowed in the "Minimum age of revision to delete" configuration in each content type edit page. If you change this value all the configured content types will take it.'),
    '#options' => $allowed_time,
    '#size' => 1,
    '#default_value' => $node_revision_delete_minimum_age_to_delete_time['time'],
  );

  // Configuration for the node_revision_delete_when_to_delete_time variable.
  $form['when_to_delete'] = array(
    '#type' => 'fieldset',
    '#title' => t('When to delete configuration'),
  );

  $node_revision_delete_when_to_delete_time = variable_get('node_revision_delete_when_to_delete_time');
  $form['when_to_delete']['node_revision_delete_when_to_delete_time_max_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number allowed'),
    '#description' => t('The maximum number allowed in the "When to delete" configuration in each content type edit page. If you change this number and the new value is smaller than the value defined for a content type in the "When to delete" setting, the "When to delete" setting for that content type will take it.'),
    '#default_value' => $node_revision_delete_when_to_delete_time['max_number'],
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['when_to_delete']['node_revision_delete_when_to_delete_time_time'] = array(
    '#type' => 'select',
    '#title' => t('The time value'),
    '#description' => t('The time value allowed in the "When to delete" configuration in each content type edit page. If you change this value all the configured content types will take it.'),
    '#options' => $allowed_time,
    '#size' => 1,
    '#default_value' => $node_revision_delete_when_to_delete_time['time'],
  );

  // Providing the option to run now the batch job.
  if ($exists_candidates_nodes) {
    $disabled = FALSE;
    $description = t('This will start a batch job to delete old revisions for tracked content types.');
  }
  else {
    $disabled = TRUE;
    $description = t('There not exists candidates nodes with revisions to delete.');
  }

  $form['run_now'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete revisions now'),
    '#description' => $description,
    '#disabled' => $disabled,
  );

  $form['dry_run'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dry run'),
    '#description' => t('Test run without deleting revisions but seeing the output results.'),
    '#states' => array(
      // Hide the dry run option when the run now checkbox is disabled.
      'visible' => array(
        ':input[name="run_now"]' => array('checked' => TRUE),
      ),
      'unchecked' => array(
        ':input[name="run_now"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form submit handler for the Node Revision Delete administration form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function node_revision_delete_admin_settings_form_submit(array $form, array &$form_state) {
  variable_set('node_revision_delete_cron', $form_state['values']['node_revision_delete_cron']);
  variable_set('node_revision_delete_time', $form_state['values']['node_revision_delete_time']);
  // Getting the values for node_revision_delete_when_to_delete_time.
  $when_to_delete_time_max_number = $form_state['values']['node_revision_delete_when_to_delete_time_max_number'];
  $node_revision_delete_when_to_delete_time = array(
    'max_number' => $when_to_delete_time_max_number,
    'time' => $form_state['values']['node_revision_delete_when_to_delete_time_time'],
  );
  // Getting the values for node_revision_delete_minimum_age_to_delete_time.
  $minimum_age_to_delete_time_max_number = $form_state['values']['node_revision_delete_minimum_age_to_delete_time_max_number'];
  $node_revision_delete_minimum_age_to_delete_time = array(
    'max_number' => $minimum_age_to_delete_time_max_number,
    'time' => $form_state['values']['node_revision_delete_minimum_age_to_delete_time_time'],
  );
  // We need to update the max_number in the existing content type
  // configuration if the new value is lower than the actual.
  _node_revision_delete_update_time_max_number_config('when_to_delete', $when_to_delete_time_max_number);
  _node_revision_delete_update_time_max_number_config('minimum_age_to_delete', $minimum_age_to_delete_time_max_number);
  // Saving the configuration.
  variable_set('node_revision_delete_when_to_delete_time', $node_revision_delete_when_to_delete_time);
  variable_set('node_revision_delete_minimum_age_to_delete_time', $node_revision_delete_minimum_age_to_delete_time);

  if ($form_state['values']['run_now']) {
    // Set up the batch job.
    $operations = array();

    // Getting the config variable.
    $node_revision_delete_track = variable_get('node_revision_delete_track', array());

    foreach ($node_revision_delete_track as $content_type => $content_type_info) {
      $operations[] = array('node_revision_delete_batch_process',
        array(
          $content_type,
          $content_type_info['minimum_revisions_to_keep'],
          $content_type_info['minimum_age_to_delete'],
          $content_type_info['when_to_delete'],
          $form_state['values']['dry_run'],
        ),
      );
    }
    $batch = array(
      'operations' => $operations,
      'title' => t('Node Revision Delete batch job'),
      'init_message' => t('Starting...'),
      'error_message' => t('An error occurred'),
      'finished' => 'node_revision_delete_batch_finish',
      'file' => drupal_get_path('module', 'node_revision_delete') . '/node_revision_delete.batch.inc',
    );
    batch_set($batch);
  }
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Page callback: Form constructor for content type configuration delete form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function node_revision_delete_content_type_configuration_delete_form(array $form, array &$form_state) {
  $content_type_machine_name = arg(5);
  // Getting all the content types.
  $content_types = node_type_get_types();
  // Getting the content type name.
  $content_type_name = $content_types[$content_type_machine_name]->name;
  // The question.
  $question = t('Are you sure you want to delete the configuration for the "%content_type" content type?', array('%content_type' => $content_type_name));
  // The cancel url.
  $cancel_url = 'admin/config/content/node_revision_delete';
  // The description.
  $description = '<p>' . t('This action will delete the Node Revision Delete configuration for the "@content_type" content type, if this action take place the content type will not be available for revision deletion.', array('@content_type' => $content_type_name)) . '</p>';
  $description .= '<p>' . t('The action cannot be undone.') . '</p>';
  // Submit and calcel button text.
  $submit = t('Delete');
  $cancel = t('Cancel');
  // Creating the confirm form.
  $form = confirm_form($form, $question, $cancel_url, $description, $submit, $cancel);

  return $form;
}

/**
 * Form submit handler for the content type configuration delete form.
 *
 * @param array $form
 *   The form element.
 * @param array $form_state
 *   The form state.
 */
function node_revision_delete_content_type_configuration_delete_form_submit(array $form, array &$form_state) {
  // Getting the content type machine name.
  $content_type_machine_name = arg(5);
  // Deleting the configuration.
  _node_revision_delete_delete_content_type_config($content_type_machine_name);
  // Searching the content type name.
  $content_types = node_type_get_types();
  $content_type_name = $content_types[$content_type_machine_name]->name;
  // Printing a confirmation message.
  drupal_set_message(t('The Node Revision Delete configuration for the "@content_type" content type has been deleted.', array('@content_type' => $content_type_name)));
}
