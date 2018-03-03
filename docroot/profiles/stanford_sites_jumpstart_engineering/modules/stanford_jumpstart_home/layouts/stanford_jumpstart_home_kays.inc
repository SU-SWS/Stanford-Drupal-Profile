<?php
/**
 * @file
 * Code for the Stanford Jumpstart Kays Homepage layout.
 *  @author Caryl Westerberg <cjwest@stanford.edu>
 */

$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_kays';
$context->description = 'Homepage: Kays layout with full-width banner, a large custom block, and a small custom block.';
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
      'bean-jumpstart-home-page-full-width-b' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-home-page-full-width-b',
        'region' => 'fullwidth_top',
        'weight' => '-10',
      ),
      'bean-jumpstart-large-custom-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-large-custom-block',
        'region' => 'content_lower',
        'weight' => '-10',
      ),
      'bean-jumpstart-small-custom-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block',
        'region' => 'content_lower',
        'weight' => '-9',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: Kays layout with full-width banner, a large custom block, and a small custom block.');
