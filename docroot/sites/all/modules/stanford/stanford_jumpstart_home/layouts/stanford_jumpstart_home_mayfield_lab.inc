<?php

/**
 * @file
 * Homepage layout for Jumpstart Lab.
 */

$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_mayfield_lab';
$context->description = 'Tagline with Research Projects, Recent Publications, and Recent News blocks';
$context->tag = 'Home Page';
$context->conditions = array(
  'path' => array(
    'values' => array(
      '<front>' => '<front>',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'search-form' => array(
        'module' => 'search',
        'delta' => 'form',
        'region' => 'search_box',
        'weight' => '-10',
      ),
      'bean-jumpstart-lead-text-with-body' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-lead-text-with-body',
        'region' => 'content_top',
        'weight' => '-10',
      ),
      'bean-jumpstart-lab-homepage-research-' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-lab-homepage-research-',
        'region' => 'content_row3',
        'weight' => '-10',
      ),
      'views-publications_common-block_4' => array(
        'module' => 'views',
        'delta' => 'publications_common-block_4',
        'region' => 'content_row3',
        'weight' => '-9',
      ),
      'views-f73ff55b085ea49217d347de6630cd5a' => array(
        'module' => 'views',
        'delta' => 'f73ff55b085ea49217d347de6630cd5a',
        'region' => 'content_row3',
        'weight' => '-8',
      ),
      'bean-jumpstart-lab-footer-logo-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-lab-footer-logo-block',
        'region' => 'footer',
        'weight' => '-10',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Tagline with Research Projects, Recent Publications, and Recent News blocks');
