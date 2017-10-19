<?php
/**
 * @file
 * stanford_manage_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_manage_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'manage_content_landing_page';
  $context->description = 'Landing page for the manage content blocks';
  $context->tag = 'Manage Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/manage' => 'admin/manage',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page for the manage content blocks');
  t('Manage Content');
  $export['manage_content_landing_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'manage_content_sub_pages';
  $context->description = 'Context for blocks on the manage content sub-pages';
  $context->tag = 'Manage Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/manage/*' => 'admin/manage/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-b419ccf5828646bf9846562329b6454b' => array(
          'module' => 'views',
          'delta' => 'b419ccf5828646bf9846562329b6454b',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for blocks on the manage content sub-pages');
  t('Manage Content');
  $export['manage_content_sub_pages'] = $context;

  return $export;
}
