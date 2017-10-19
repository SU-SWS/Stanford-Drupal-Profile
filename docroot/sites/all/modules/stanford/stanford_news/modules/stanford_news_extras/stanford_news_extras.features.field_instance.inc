<?php
/**
 * @file
 * stanford_news_extras.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_news_extras_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_news_item-field_s_news_banner'
  $field_instances['node-stanford_news_item-field_s_news_banner'] = array(
    'bundle' => 'stanford_news_item',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_news_extras' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'full-width-banner-short',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_banner',
    'label' => 'Banner',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'default_image_ft_source_var' => 'stanford_news_banner',
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__3-col-header' => 0,
          'colorbox__4-col-header' => 0,
          'colorbox__6-col-banner' => 0,
          'colorbox__6-col-banner-short' => 0,
          'colorbox__6-col-banner-tall' => 0,
          'colorbox__6-col-photo-landscape' => 0,
          'colorbox__8-col-banner' => 0,
          'colorbox__8-col-banner-short' => 0,
          'colorbox__8-col-banner-tall' => 0,
          'colorbox__9-col-banner' => 0,
          'colorbox__9-col-banner-short' => 0,
          'colorbox__12-col-banner' => 0,
          'colorbox__12-col-banner-tall' => 0,
          'colorbox__banner-850x400' => 0,
          'colorbox__full-width-banner' => 0,
          'colorbox__full-width-banner-short' => 0,
          'colorbox__half-page-profile' => 0,
          'colorbox__huge-landscape' => 0,
          'colorbox__icon-profile' => 0,
          'colorbox__icon-scaled' => 0,
          'colorbox__icon-square' => 0,
          'colorbox__large' => 0,
          'colorbox__large-landscape' => 0,
          'colorbox__large-landscape-scaled' => 0,
          'colorbox__large-profile' => 0,
          'colorbox__large-profile-scaled' => 0,
          'colorbox__large-scaled' => 0,
          'colorbox__large-square' => 0,
          'colorbox__med-landscape' => 0,
          'colorbox__med-landscape-scaled' => 0,
          'colorbox__med-profile' => 0,
          'colorbox__med-profile-scaled' => 0,
          'colorbox__med-square' => 0,
          'colorbox__medium' => 0,
          'colorbox__page-width' => 0,
          'colorbox__sm-landscape' => 0,
          'colorbox__sm-profile' => 0,
          'colorbox__sm-profile-scaled' => 0,
          'colorbox__sm-scaled' => 0,
          'colorbox__sm-square' => 0,
          'colorbox__thmb-landscape' => 0,
          'colorbox__thmb-profile' => 0,
          'colorbox__thmb-square' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_3-col-header' => 0,
          'image_4-col-header' => 0,
          'image_6-col-banner' => 0,
          'image_6-col-banner-short' => 0,
          'image_6-col-banner-tall' => 0,
          'image_6-col-photo-landscape' => 0,
          'image_8-col-banner' => 0,
          'image_8-col-banner-short' => 0,
          'image_8-col-banner-tall' => 0,
          'image_9-col-banner' => 0,
          'image_9-col-banner-short' => 0,
          'image_12-col-banner' => 0,
          'image_12-col-banner-tall' => 0,
          'image_banner-850x400' => 0,
          'image_full-width-banner' => 0,
          'image_full-width-banner-short' => 0,
          'image_half-page-profile' => 0,
          'image_huge-landscape' => 0,
          'image_icon-profile' => 0,
          'image_icon-scaled' => 0,
          'image_icon-square' => 0,
          'image_large' => 0,
          'image_large-landscape' => 0,
          'image_large-landscape-scaled' => 0,
          'image_large-profile' => 0,
          'image_large-profile-scaled' => 0,
          'image_large-scaled' => 0,
          'image_large-square' => 0,
          'image_med-landscape' => 0,
          'image_med-landscape-scaled' => 0,
          'image_med-profile' => 0,
          'image_med-profile-scaled' => 0,
          'image_med-square' => 0,
          'image_medium' => 0,
          'image_page-width' => 0,
          'image_sm-landscape' => 0,
          'image_sm-profile' => 0,
          'image_sm-profile-scaled' => 0,
          'image_sm-scaled' => 0,
          'image_sm-square' => 0,
          'image_thmb-landscape' => 0,
          'image_thmb-profile' => 0,
          'image_thmb-square' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-stanford_news_item-field_s_news_byline'
  $field_instances['node-stanford_news_item-field_s_news_byline'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '"By " + author name',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'stanford_news_extras' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_byline',
    'label' => 'Byline',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'content_editor_text_format' => 'content_editor_text_format',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'content_editor_text_format' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-stanford_news_item-field_s_news_department'
  $field_instances['node-stanford_news_item-field_s_news_department'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_department',
    'label' => 'Department',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_news_item-field_s_news_optional_image'
  $field_instances['node-stanford_news_item-field_s_news_optional_image'] = array(
    'bundle' => 'stanford_news_item',
    'deleted' => 0,
    'description' => 'Uploading a square thumbnail will replace the automatic square crop of the Feature Image that is displayed in news listing pages and teasers. It will not replace the image used in the news story detail view. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_optional_image',
    'label' => 'Optional Square Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '300x300',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__3-col-header' => 0,
          'colorbox__4-col-header' => 0,
          'colorbox__6-col-banner' => 0,
          'colorbox__6-col-banner-short' => 0,
          'colorbox__6-col-banner-tall' => 0,
          'colorbox__6-col-photo-landscape' => 0,
          'colorbox__8-col-banner' => 0,
          'colorbox__8-col-banner-short' => 0,
          'colorbox__8-col-banner-tall' => 0,
          'colorbox__9-col-banner' => 0,
          'colorbox__9-col-banner-short' => 0,
          'colorbox__12-col-banner' => 0,
          'colorbox__12-col-banner-tall' => 0,
          'colorbox__full-width-banner' => 0,
          'colorbox__full-width-banner-short' => 0,
          'colorbox__half-page-profile' => 0,
          'colorbox__huge-landscape' => 0,
          'colorbox__icon-profile' => 0,
          'colorbox__icon-scaled' => 0,
          'colorbox__icon-square' => 0,
          'colorbox__large' => 0,
          'colorbox__large-landscape' => 0,
          'colorbox__large-landscape-scaled' => 0,
          'colorbox__large-profile' => 0,
          'colorbox__large-profile-scaled' => 0,
          'colorbox__large-scaled' => 0,
          'colorbox__large-square' => 0,
          'colorbox__med-landscape' => 0,
          'colorbox__med-landscape-scaled' => 0,
          'colorbox__med-profile' => 0,
          'colorbox__med-profile-scaled' => 0,
          'colorbox__med-square' => 0,
          'colorbox__medium' => 0,
          'colorbox__page-width' => 0,
          'colorbox__sm-landscape' => 0,
          'colorbox__sm-profile' => 0,
          'colorbox__sm-profile-scaled' => 0,
          'colorbox__sm-scaled' => 0,
          'colorbox__sm-square' => 0,
          'colorbox__thmb-landscape' => 0,
          'colorbox__thmb-profile' => 0,
          'colorbox__thmb-square' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_3-col-header' => 0,
          'image_4-col-header' => 0,
          'image_6-col-banner' => 0,
          'image_6-col-banner-short' => 0,
          'image_6-col-banner-tall' => 0,
          'image_6-col-photo-landscape' => 0,
          'image_8-col-banner' => 0,
          'image_8-col-banner-short' => 0,
          'image_8-col-banner-tall' => 0,
          'image_9-col-banner' => 0,
          'image_9-col-banner-short' => 0,
          'image_12-col-banner' => 0,
          'image_12-col-banner-tall' => 0,
          'image_full-width-banner' => 0,
          'image_full-width-banner-short' => 0,
          'image_half-page-profile' => 0,
          'image_huge-landscape' => 0,
          'image_icon-profile' => 0,
          'image_icon-scaled' => 0,
          'image_icon-square' => 0,
          'image_large' => 0,
          'image_large-landscape' => 0,
          'image_large-landscape-scaled' => 0,
          'image_large-profile' => 0,
          'image_large-profile-scaled' => 0,
          'image_large-scaled' => 0,
          'image_large-square' => 0,
          'image_med-landscape' => 0,
          'image_med-landscape-scaled' => 0,
          'image_med-profile' => 0,
          'image_med-profile-scaled' => 0,
          'image_med-square' => 0,
          'image_medium' => 0,
          'image_page-width' => 0,
          'image_sm-landscape' => 0,
          'image_sm-profile' => 0,
          'image_sm-profile-scaled' => 0,
          'image_sm-scaled' => 0,
          'image_sm-square' => 0,
          'image_thmb-landscape' => 0,
          'image_thmb-profile' => 0,
          'image_thmb-square' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_news_item-field_s_news_organization'
  $field_instances['node-stanford_news_item-field_s_news_organization'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_organization',
    'label' => 'Organization Link',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_news_item-field_s_news_research_theme'
  $field_instances['node-stanford_news_item-field_s_news_research_theme'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_research_theme',
    'label' => 'Research Theme',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_news_item-field_s_news_school_theme'
  $field_instances['node-stanford_news_item-field_s_news_school_theme'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_school_theme',
    'label' => 'School Theme',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_news_item-field_s_news_slider_feature'
  $field_instances['node-stanford_news_item-field_s_news_slider_feature'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this box to indicate that the news item is being used as a slider feature on the site home page. This will prevent it from surfacing in the home page home page "Recent News" feed but not on the actual News Feed page.  ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'stanford_news_extras' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_slider_feature',
    'label' => 'Slider Feature',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-stanford_news_item-field_s_news_teaser'
  $field_instances['node-stanford_news_item-field_s_news_teaser'] = array(
    'bundle' => 'stanford_news_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Teaser is the short text which introduces a news story. Please keep this teaser under 180 characters.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'stanford_news_extras' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'taxonomy' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_news_teaser',
    'label' => 'Teaser',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'content_editor_text_format' => 'content_editor_text_format',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'content_editor_text_format' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('"By " + author name');
  t('Banner');
  t('Byline');
  t('Check this box to indicate that the news item is being used as a slider feature on the site home page. This will prevent it from surfacing in the home page home page "Recent News" feed but not on the actual News Feed page.  ');
  t('Department');
  t('Optional Square Thumbnail');
  t('Organization Link');
  t('Research Theme');
  t('School Theme');
  t('Slider Feature');
  t('Teaser');
  t('The Teaser is the short text which introduces a news story. Please keep this teaser under 180 characters.');
  t('Uploading a square thumbnail will replace the automatic square crop of the Feature Image that is displayed in news listing pages and teasers. It will not replace the image used in the news story detail view. ');

  return $field_instances;
}
