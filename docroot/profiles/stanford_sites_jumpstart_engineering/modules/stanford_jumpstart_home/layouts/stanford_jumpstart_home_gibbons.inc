<?php
/**
 * @file
 * Code for the Stanford Jumpstart Gibbons Homepage layout.
 *  @author Caryl Westerberg <cjwest@stanford.edu>
 */

$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_gibbons';
$context->description = 'Homepage: Gibbons layout with full-width banner, large about, news, four small custom block, and events.';
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
      'bean-homepage-about-block' => array(
        'module' => 'bean',
        'delta' => 'homepage-about-block',
        'region' => 'content',
        'weight' => '-20',
      ),
      // News.
      'views-f73ff55b085ea49217d347de6630cd5a' => array(
        'module' => 'views',
        'delta' => 'f73ff55b085ea49217d347de6630cd5a',
        'region' => 'content',
        'weight' => '-18',
      ),
      // News Extras.
      'views-9bf4ec9695a5b13242ba5a4898a6b635' => array(
        'module' => 'views',
        'delta' => '9bf4ec9695a5b13242ba5a4898a6b635',
        'region' => 'content',
        'weight' => '-16',
      ),
      'bean-jumpstart-small-custom-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block',
        'region' => 'content_row3',
        'weight' => '-10',
      ),
      'bean-jumpstart-small-custom-block-2' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block-2',
        'region' => 'content_row3',
        'weight' => '-9',
      ),
      'bean-jumpstart-small-custom-block-3' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block-3',
        'region' => 'content_row3',
        'weight' => '-8',
      ),
      'bean-jumpstart-small-custom-block-4' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block-4',
        'region' => 'content_row3',
        'weight' => '-7',
      ),
      'bean-jumpstart-small-custom-block-5' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block-5',
        'region' => 'content_row3',
        'weight' => '-6',
      ),
      'views-stanford_events_views-block' => array(
        'module' => 'views',
        'delta' => 'stanford_events_views-block',
        'region' => 'content_row3',
        'weight' => '-5',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: Gibbons layout with full-width banner, large about, news, four small custom block, and events.');
