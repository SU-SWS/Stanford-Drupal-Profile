<?php

/**
 * @file
 * Calls results to administration's pages for the Node Revision Delete module.
 */

/**
 * Page callback: Form constructor for Node Revision Delete administration form.
 */
function node_revision_delete_form($form, &$form_state) {
  // List tracked content types.
  $headers = array(
    'Content type',
    'Machine name',
    'Revisions to keep',
    'Candidate nodes',
    'Operations',
  );

  $tracked_content_types = node_revision_delete_content_types();

  $rows = array();
  $exists_candidates_nodes = FALSE;

  foreach (node_type_get_names() as $type => $name) {
    $row = array(
      'name' => $name,
      'machine_name' => $type,
      'number' => t('Untracked'),
      'candidates' => '-',
      'link' => l(t('edit'), 'admin/structure/types/manage/' . $type, array('query' => array('destination' => 'admin/config/content/node_revision_delete'))),
    );

    if (array_key_exists($type, $tracked_content_types)) {
      $row['number'] = $tracked_content_types[$type];
      $candidate_nodes = count(node_revision_delete_candidates($type, $tracked_content_types[$type]));
      $row['candidates'] = $candidate_nodes;
      if ($candidate_nodes && !$exists_candidates_nodes) {
        $exists_candidates_nodes = TRUE;
      }
    }

    $rows[] = $row;
  }
  $form['tracked'] = array(
    '#theme' => 'table',
    '#caption' => t('Current configuration'),
    '#header' => $headers,
    '#rows' => $rows,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'node_revision_delete') . '/css/node_revision_delete.css',
      ),
    ),
  );

  // Number of revisions to delete per loop.
  $options_cron = array(10, 20, 50, 100, 200, 500, 1000);
  $form['node_revision_delete_cron'] = array(
    '#type' => 'select',
    '#title' => t('How many revisions do you want to delete per cron run?'),
    '#description' => t('Deleting node revisions is a database intensive task. Increase this value if you think that the server can handle more deletions per cron run.'),
    '#options' => array_combine($options_cron, $options_cron),
    '#default_value' => variable_get('node_revision_delete_cron', NODE_REVISION_DELETE_CRON),
  );

  // Available times to delete revisions.
  $option_time = array(
    'never' => 'Never',
    'every_time' => 'Every time cron runs',
    'everyday' => 'Everyday',
    'every_week' => 'Every Week',
    'every_10_days' => 'Every 10 Days',
    'every_15_days' => 'Every 15 Days',
    'every_month' => 'Every Month',
    'every_3_months' => 'Every 3 Months',
    'every_6_months' => 'Every 6 Months',
    'every_year' => 'Every Year',
  );
  $form['node_revision_delete_time'] = array(
    '#type' => 'select',
    '#options' => $option_time,
    '#title' => t('How often should revision be deleted while cron runs?'),
    '#default_value' => variable_get('node_revision_delete_time', NODE_REVISION_DELETE_TIME),
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
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Form submit handler for the settings form.
 */
function node_revision_delete_form_submit($form, &$form_state) {
  variable_set('node_revision_delete_cron', $form_state['values']['node_revision_delete_cron']);
  variable_set('node_revision_delete_time', $form_state['values']['node_revision_delete_time']);

  $node_revision_delete_content_types = node_revision_delete_content_types();
  if ($form_state['values']['run_now'] && count($node_revision_delete_content_types)) {
    // Set up the batch job.
    $operations = array();
    foreach ($node_revision_delete_content_types as $content_type => $revisions_to_keep) {
      $operations[] = array('node_revision_delete_batch_process',
        array(
          $content_type,
          $revisions_to_keep,
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
  drupal_set_message(t('Settings Saved Successfully.'));
}
