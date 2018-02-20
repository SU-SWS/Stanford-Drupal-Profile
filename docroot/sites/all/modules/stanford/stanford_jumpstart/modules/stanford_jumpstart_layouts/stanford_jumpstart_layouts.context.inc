<?php
/**
 * @file
 * stanford_jumpstart_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '12-col-banner-nsb-homepage';
  $context->description = 'Home page layout with a 12 column banner and no sidebars';
  $context->tag = 'Home Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dev/home' => 'dev/home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-flexi-block-for-the-home-page' => array(
          'module' => 'bean',
          'delta' => 'flexi-block-for-the-home-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'bean-homepage-about-block' => array(
          'module' => 'bean',
          'delta' => 'homepage-about-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'bean-homepage-banner-image' => array(
          'module' => 'bean',
          'delta' => 'homepage-banner-image',
          'region' => 'main_upper',
          'weight' => '-10',
        ),
        'bean-announcements-block' => array(
          'module' => 'bean',
          'delta' => 'announcements-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('Home page layout with a 12 column banner and no sidebars');
  $export['12-col-banner-nsb-homepage'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '9-col-banner-fsb-homepage';
  $context->description = 'Home page layout with a 9 column banner and first sidebar';
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
          'region' => 'sidebar_first',
          'weight' => '-25',
        ),
        'bean-flexi-block-for-the-home-page' => array(
          'module' => 'bean',
          'delta' => 'flexi-block-for-the-home-page',
          'region' => 'sidebar_first',
          'weight' => '-24',
        ),
        'bean-homepage-banner-image' => array(
          'module' => 'bean',
          'delta' => 'homepage-banner-image',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'bean-announcements-block' => array(
          'module' => 'bean',
          'delta' => 'announcements-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('Home page layout with an 8 column banner and first sidebar');
  $export['9-col-banner-fsb-homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_but_homepage';
  $context->description = 'All pages but the home page';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_jumpstart_layouts-2' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jumpstart_layouts-2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages but the home page');
  t('Sub-pages');
  $export['all_pages_but_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
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
        'menu_block-stanford_jumpstart_layouts-1' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jumpstart_layouts-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'search_box',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-contact-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-contact-block',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'bean-optional-footer-block' => array(
          'module' => 'bean',
          'delta' => 'optional-footer-block',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'menu-menu-related-links' => array(
          'module' => 'menu',
          'delta' => 'menu-related-links',
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
  $export['sitewide'] = $context;

  return $export;
}
