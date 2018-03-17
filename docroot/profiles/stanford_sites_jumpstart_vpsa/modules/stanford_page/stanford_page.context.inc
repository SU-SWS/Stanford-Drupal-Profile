<?php
/**
 * @file
 * stanford_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_page';
  $context->description = 'Context for VPSA testimonial';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_page' => 'stanford_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-stanford_page-block' => array(
          'module' => 'views',
          'delta' => 'stanford_page-block',
          'region' => 'sidebar_first',
          'weight' => '45',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for VPSA testimonial');
  t('Sub-pages');
  $export['vpsa_page'] = $context;

  return $export;
}
