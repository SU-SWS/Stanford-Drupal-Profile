<?php
/**
 * @file
 * stanford_news_extras.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_news_extras_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_news_extras';
  $context->description = 'Context for news items with extras fields';
  $context->tag = 'News';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news/*' => 'news/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-banner' => array(
          'module' => 'ds_extras',
          'delta' => 'banner',
          'region' => 'fullwidth_top',
          'weight' => '-10',
        ),
        'ds_extras-banner_overlay' => array(
          'module' => 'ds_extras',
          'delta' => 'banner_overlay',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
    'context_reaction_view_mode' => array(
      'entity_types' => array(
        'bean' => array(
          'stanford_banner' => 'none',
          'stanford_big_text_block' => 'none',
          'stanford_contact' => 'none',
          'stanford_icon_block' => 'none',
          'stanford_large_block' => 'none',
          'stanford_postcard' => 'none',
          'stanford_social_media_connect' => 'none',
          'stanford_testimonial_block' => 'none',
        ),
        'field_collection_item' => array(
          'field_s_image_info' => 'none',
          'field_s_gallery_image_info' => 'none',
          'field_landing_page_item' => 'none',
        ),
        'node' => array(
          'stanford_affiliate_organization' => 'none',
          'article' => 'none',
          'page' => 'none',
          'stanford_gallery' => 'none',
          'stanford_landing_page' => 'none',
          'stanford_news_importer' => 'none',
          'stanford_news_item' => 'stanford_news_extras',
          'stanford_person' => 'none',
          'stanford_private_page' => 'none',
          'stanford_publication' => 'none',
          'stanford_event' => 'none',
          'stanford_event_importer' => 'none',
          'stanford_event_series' => 'none',
          'stanford_page' => 'none',
          'webform' => 'none',
        ),
        'capx_cfe' => array(
          'mapper' => 'none',
          'importer' => 'none',
        ),
        'capx_cfe_type' => array(
          'capx_cfe_type' => 'none',
        ),
        'file' => array(
          'image' => 'none',
          'video' => 'none',
          'audio' => 'none',
          'document' => 'none',
        ),
        'taxonomy_term' => array(
          'stanford_affiliate_organization_type' => 'none',
          'stanford_affiliation' => 'none',
          'stanford_faculty_type' => 'none',
          'stanford_field_of_study' => 'none',
          'stanford_interests' => 'none',
          'stanford_staff_type' => 'none',
          'stanford_student_type' => 'none',
          'stanford_event_audience' => 'none',
          'stanford_event_categories' => 'none',
          'stanford_event_type' => 'none',
          'publication_type' => 'none',
          'news_categories' => 'none',
          'tags' => 'none',
          'stanford_slide_category' => 'none',
          'fellowship_location' => 'none',
          'capx_organizations' => 'none',
          'research_themes' => 'none',
          'school_themes' => 'none',
          'stanford_department' => 'none',
        ),
        'user' => array(
          'user' => 'none',
        ),
        'wysiwyg_profile' => array(
          'wysiwyg_profile' => 'none',
        ),
        'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-bean',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for news items with extras fields');
  t('News');
  $export['stanford_news_extras'] = $context;

  return $export;
}
