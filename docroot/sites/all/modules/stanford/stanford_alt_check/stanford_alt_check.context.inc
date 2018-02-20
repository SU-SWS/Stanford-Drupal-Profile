<?php

/**
 * @file
 * stanford_alt_check.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_alt_check_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'manage_images_landing_page';
  $context->description = 'Landing page for the manage image blocks';
  $context->tag = 'Manage Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/images*' => 'admin/images*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-manage-content-by-type' => array(
          'module' => 'menu',
          'delta' => 'menu-manage-content-by-type',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['manage_images_landing_page'] = $context;

  return $export;
}
