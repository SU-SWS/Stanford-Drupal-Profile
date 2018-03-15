<?php

/**
 * @file
 * Drush integration for node_revision_delete.
 */

/**
 * Implements COMMANDFILE_drush_command().
 */
function node_revision_delete_drush_command() {
  $items = array();

  $items['node-revision-delete'] = array(
    'description' => dt('Deletes old node revisions for a given content type.'),
    'arguments' => array(
      'type' => dt("A content type's machine name."),
      'revisions' => dt('The maximum amount of revisions to keep per node for this content type.'),
    ),
    'required-arguments' => TRUE,
    'examples' => array(
      'drush nrd article 50' => dt('Keeps the latest 50 revisions of every article. Deletes the rest.'),
    ),
    'aliases' => array('nrd'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_validate($content_type, $revisions_to_keep) {
  // Make sure the content type exists.
  $content_types = array_keys(node_type_get_types());
  if (!in_array($content_type, $content_types)) {
    drush_set_error('NODE_REVISION_DELETE_WRONG_TYPE', dt('The content type "@type" does not exist. Available content types are @types', array(
      '@type' => $content_type,
      '@types' => implode(', ', $content_types),
    )));
  }

  // Make sure the number of revisions is a positive integer.
  // Based on Drupal's element_validate_integer_positive().
  if (!is_numeric($revisions_to_keep) || intval($revisions_to_keep) != $revisions_to_keep || $revisions_to_keep <= 0) {
    drush_set_error('NODE_REVISION_DELETE_WRONG_REVISIONS', dt('The amount of revisions to keep must be a positive integer.'));
  }
}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 */
function drush_node_revision_delete($content_type, $revisions_to_keep) {
  // Set up the batch job.
  $batch = array(
    'operations' => array(
      array('node_revision_delete_batch_process',
        array($content_type,
          $revisions_to_keep,
        ),
      ),
    ),
    'title' => dt('Node Revision Delete batch job'),
    'init_message' => dt('Starting...'),
    'error_message' => dt('An error occurred'),
    'finished' => 'node_revision_delete_batch_finish',
    'file' => drupal_get_path('module', 'node_revision_delete') . '/node_revision_delete.batch.inc',
  );

  // Start the batch job.
  batch_set($batch);
  drush_backend_batch_process();
}
