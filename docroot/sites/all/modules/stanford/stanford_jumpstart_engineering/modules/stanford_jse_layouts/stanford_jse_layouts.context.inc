<?php
/**
 * @file
 * stanford_jse_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jse_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jumpstart_help_page';
  $context->description = 'Landing page for the Jumpstart Help page';
  $context->tag = 'Help';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/stanford-jumpstart' => 'admin/stanford-jumpstart',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_help-stanford_site_specific_help' => array(
          'module' => 'stanford_help',
          'delta' => 'stanford_site_specific_help',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Help');
  t('Landing page for the Jumpstart Help page');
  $export['jumpstart_help_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_jse';
  $context->description = 'Sitewide - All pages';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-stanford_jsa_layouts-2' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jsa_layouts-2',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'search_box',
          'weight' => '-10',
        ),
        'bean-jse-linked-logo-block' => array(
          'module' => 'bean',
          'delta' => 'jse-linked-logo-block',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-contact-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-contact-block',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'bean-jumpstart-custom-footer-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-custom-footer-block',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'stanford_private_page-stanford_internal_login' => array(
          'module' => 'stanford_private_page',
          'delta' => 'stanford_internal_login',
          'region' => 'footer',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Sitewide - All pages');
  $export['sitewide_jse'] = $context;

  return $export;
}
