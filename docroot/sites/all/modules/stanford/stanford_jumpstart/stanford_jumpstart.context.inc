<?php

/**
 * @file
 * Context block placement.
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_context_default_contexts() {
  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_framework_version';
  $context->description = '';
  $context->tag = 'Manage Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/stanford-jumpstart' => 'admin/stanford-jumpstart',
        'admin/stanford-jumpstart/help' => 'admin/stanford-jumpstart/help',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_jumpstart-stanford_jumpstart_version' => array(
          'module' => 'stanford_jumpstart',
          'delta' => 'stanford_jumpstart_version',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  return array('stanford_framework_version' => $context);
}