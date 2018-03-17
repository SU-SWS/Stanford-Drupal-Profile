<?php
/**
 * @file
 * stanford_slides.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_slides_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_slide-field_s_image_info'
  $field_instances['node-stanford_slide-field_s_image_info'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'stanford_9_col_banner',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'view_mode' => 'stanford_6_col_banner',
        ),
        'type' => 'field_collection_fields',
        'weight' => 0,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'stanford_8_col_banner',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'stanford_9_col_banner',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'stanford_12_col_banner' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'stanford_12_col_banner',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => '',
          'description' => 0,
          'edit' => '',
          'view_mode' => 'stanford_thumbnail',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_image_info',
    'label' => 'Image',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_caption_color'
  $field_instances['node-stanford_slide-field_s_slide_caption_color'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => array(
      0 => array(
        'value' => 'dark',
      ),
    ),
    'deleted' => 0,
    'description' => 'This defines the color scheme used when displaying the caption.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_12_col_banner' => array(
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
    'field_name' => 'field_s_slide_caption_color',
    'label' => 'Caption Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_caption_position_h'
  $field_instances['node-stanford_slide-field_s_slide_caption_position_h'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => array(
      0 => array(
        'value' => 'left',
      ),
    ),
    'deleted' => 0,
    'description' => 'This field is used for the horizontal placement of the caption on your slide. This field is ignored for no-caption views displays.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_12_col_banner' => array(
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
    'field_name' => 'field_s_slide_caption_position_h',
    'label' => 'Caption Position - Horizontal',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_caption_position_v'
  $field_instances['node-stanford_slide-field_s_slide_caption_position_v'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => array(
      0 => array(
        'value' => 'bottom',
      ),
    ),
    'deleted' => 0,
    'description' => 'This field defines vertical alignment for the caption overlay on your slide. Vertical positioning is ignored for caption-block and no-caption views displays.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_12_col_banner' => array(
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
    'field_name' => 'field_s_slide_caption_position_v',
    'label' => 'Caption Position - Vertical',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_category'
  $field_instances['node-stanford_slide-field_s_slide_category'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'stanford_12_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_slide_category',
    'label' => 'Category',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_featured'
  $field_instances['node-stanford_slide-field_s_slide_featured'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'When "featured" this slide will appear in the slideshow.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'stanford_12_col_banner' => array(
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
    'field_name' => 'field_s_slide_featured',
    'label' => 'Featured',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-stanford_slide-field_s_slide_link'
  $field_instances['node-stanford_slide-field_s_slide_link'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
        ),
        'type' => 'link_default',
        'weight' => 2,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'stanford_12_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_slide_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => 'more-link',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
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

  // Exported field_instance: 'node-stanford_slide-field_s_slide_weight'
  $field_instances['node-stanford_slide-field_s_slide_weight'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this image is part of a group, the weight helps determine the sorting order.  ',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
      'stanford_6_col_banner' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'stanford_9_col_banner' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'stanford_12_col_banner' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_slide_weight',
    'label' => 'Weight',
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
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Caption Color');
  t('Caption Position - Horizontal');
  t('Caption Position - Vertical');
  t('Category');
  t('Featured');
  t('If this image is part of a group, the weight helps determine the sorting order.  ');
  t('Image');
  t('Link');
  t('This defines the color scheme used when displaying the caption.');
  t('This field defines vertical alignment for the caption overlay on your slide. Vertical positioning is ignored for caption-block and no-caption views displays.');
  t('This field is used for the horizontal placement of the caption on your slide. This field is ignored for no-caption views displays.');
  t('Weight');
  t('When "featured" this slide will appear in the slideshow.');

  return $field_instances;
}
