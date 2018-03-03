<?php
/**
 * @file
 * stanford_private_page_section.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_private_page_section_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'private';
  $context->description = 'Landing page in Private section';
  $context->tag = 'private';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'private' => 'private',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-menu-private-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-menu-private-pages',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page in Private section');
  t('private');
  $export['private'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'private_pages';
  $context->description = 'All subpages in Private section';
  $context->tag = 'private';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'private/*' => 'private/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-menu-private-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-menu-private-pages',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All subpages in Private section');
  t('private');
  $export['private_pages'] = $context;

  return $export;
}
