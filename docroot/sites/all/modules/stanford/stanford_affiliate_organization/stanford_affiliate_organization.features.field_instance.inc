<?php
/**
 * @file
 * stanford_affiliate_organization.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_affiliate_organization_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_affiliate_organization-body'
  $field_instances['node-stanford_affiliate_organization-body'] = array(
    'bundle' => 'stanford_affiliate_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'About',
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
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_affiliate_organization-field_s_affiliate_image'
  $field_instances['node-stanford_affiliate_organization-field_s_affiliate_image'] = array(
    'bundle' => 'stanford_affiliate_organization',
    'deleted' => 0,
    'description' => 'Upload a logo or image representing this organization',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'medium',
        ),
        'type' => 'image',
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
    'field_name' => 'field_s_affiliate_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x1000',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_affiliate_organization-field_s_affiliate_link'
  $field_instances['node-stanford_affiliate_organization-field_s_affiliate_link'] = array(
    'bundle' => 'stanford_affiliate_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter url for an affiliate organization / partner ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_affiliate_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_affiliate_organization-field_s_affiliate_type'
  $field_instances['node-stanford_affiliate_organization-field_s_affiliate_type'] = array(
    'bundle' => 'stanford_affiliate_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If appropriate, select the affiliate type(s) for this organization.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_affiliate_type',
    'label' => 'Affiliate Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-stanford_affiliate_organization-field_s_affiliate_weight'
  $field_instances['node-stanford_affiliate_organization-field_s_affiliate_weight'] = array(
    'bundle' => 'stanford_affiliate_organization',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'This integer field is used to control the sort order in views displays. Larger numbers are "heavier" and sink lower in the list.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_affiliate_weight',
    'label' => 'Sorting Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Affiliate Type');
  t('Enter url for an affiliate organization / partner ');
  t('If appropriate, select the affiliate type(s) for this organization.');
  t('Image');
  t('Link');
  t('Sorting Weight');
  t('This integer field is used to control the sort order in views displays. Larger numbers are "heavier" and sink lower in the list.');
  t('Upload a logo or image representing this organization');

  return $field_instances;
}
