<?php
/**
 * @file
 * Code for the Stanford Jumpstart Morris Homepage layout.
 *  @author Caryl Westerberg <cjwest@stanford.edu>
 */
$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_morris';
$context->description = 'Homepage: Morris layout with news and events';
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
      'bean-homepage-about-block' => array(
        'module' => 'bean',
        'delta' => 'homepage-about-block',
        'region' => 'main_top',
        'weight' => '-10',
      ),
      'bean-jumpstart-home-page-banner---no-' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-home-page-banner---no-',
        'region' => 'main_top',
        'weight' => '-9',
      ),
      'bean-jumpstart-small-custom-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-small-custom-block',
        'region' => 'content_row3',
        'weight' => '-20',
      ),
      // News.
      'views-f73ff55b085ea49217d347de6630cd5a' => array(
        'module' => 'views',
        'delta' => 'f73ff55b085ea49217d347de6630cd5a',
        'region' => 'content_row3',
        'weight' => '-18',
      ),
      // News extras.
      'views-9bf4ec9695a5b13242ba5a4898a6b635' => array(
        'module' => 'views',
        'delta' => '9bf4ec9695a5b13242ba5a4898a6b635',
        'region' => 'content_row3',
        'weight' => '-16',
      ),
      'views-stanford_events_views-block' => array(
        'module' => 'views',
        'delta' => 'stanford_events_views-block',
        'region' => 'content_row3',
        'weight' => '-14',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: Morris layout with news and events');
