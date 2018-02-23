<?php
/**
 * @file
 * stanford_jsa_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_story_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_story_page';
  $context->description = 'Disables the sidebar regions on story page content type.';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_story_page' => 'stanford_story_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
        ),
      ),
      'open_framework' => array(
        'disable' => array(
          'admin_shortcuts' => 0,
          'site_login' => 0,
          'header' => 0,
          'navigation' => 0,
          'search_box' => 0,
          'fullwidth_top' => 0,
          'main_top' => 0,
          'main_upper' => 0,
          'sidebar_first' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top' => 0,
          'content_upper' => 0,
          'content' => 0,
          'content_row2' => 0,
          'content_col2-1' => 0,
          'content_col2-2' => 0,
          'content_row3' => 0,
          'content_col3-1' => 0,
          'content_col3-2' => 0,
          'content_col3-3' => 0,
          'content_row4' => 0,
          'content_col4-1' => 0,
          'content_col4-2' => 0,
          'content_col4-3' => 0,
          'content_col4-4' => 0,
          'content_lower' => 0,
          'content_bottom' => 0,
          'sidebar_second' => 0,
          'main_lower' => 0,
          'main_bottom' => 0,
          'fullwidth_bottom' => 0,
          'footer' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
        ),
      ),
      'stanford_framework' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'admin_shortcuts' => 0,
          'global_header' => 0,
          'header' => 0,
          'navigation' => 0,
          'search_box' => 0,
          'fullwidth_top' => 0,
          'main_top' => 0,
          'main_upper' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top' => 0,
          'content_upper' => 0,
          'content' => 0,
          'content_row2' => 0,
          'content_col2-1' => 0,
          'content_col2-2' => 0,
          'content_row3' => 0,
          'content_col3-1' => 0,
          'content_col3-2' => 0,
          'content_col3-3' => 0,
          'content_row4' => 0,
          'content_col4-1' => 0,
          'content_col4-2' => 0,
          'content_col4-3' => 0,
          'content_col4-4' => 0,
          'content_lower' => 0,
          'content_bottom' => 0,
          'main_lower' => 0,
          'main_bottom' => 0,
          'page_bottom' => 0,
          'fullwidth_bottom' => 0,
          'footer' => 0,
        ),
      ),
      'stanford_seven' => array(
        'disable' => array(
          'admin_shortcuts' => 0,
          'help' => 0,
          'page_top' => 0,
          'main_top' => 0,
          'content_top' => 0,
          'content' => 0,
          'content_bottom' => 0,
          'main_bottom' => 0,
          'page_bottom' => 0,
          'sidebar_second' => 0,
          'sidebar_first' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $export['stanford_story_page'] = $context;

  return $export;
}
