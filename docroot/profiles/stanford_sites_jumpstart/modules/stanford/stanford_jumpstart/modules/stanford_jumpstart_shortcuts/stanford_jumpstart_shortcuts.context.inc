<?php
/**
 * @file
 * stanford_jumpstart_shortcuts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_shortcuts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_jumpstart_admin_shortcuts';
  $context->description = 'Place menus and blocks in the Admin Shortcuts region';
  $context->tag = 'Stanford Sites Jumpstart';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-admin-shortcuts' => array(
          'module' => 'menu',
          'delta' => 'menu-admin-shortcuts',
          'region' => 'admin_shortcuts',
          'weight' => '-10',
        ),
        'stanford_jumpstart_shortcuts-hello' => array(
          'module' => 'stanford_jumpstart_shortcuts',
          'delta' => 'hello',
          'region' => 'admin_shortcuts',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place menus and blocks in the Admin Shortcuts region');
  t('Stanford Sites Jumpstart');
  $export['stanford_jumpstart_admin_shortcuts'] = $context;

  return $export;
}
