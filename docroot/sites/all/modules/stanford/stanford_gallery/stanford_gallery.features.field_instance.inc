<?php
/**
 * @file
 * stanford_gallery.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_gallery_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_s_gallery_image_info-field_s_image_caption'
  $field_instances['field_collection_item-field_s_gallery_image_info-field_s_image_caption'] = array(
    'bundle' => 'field_s_gallery_image_info',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally enter information to appear as a caption for this image. This caption appears in the modal pop up after the user clicks on a thumbnail.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'gallery_large' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'gallery_large_scaled' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'gallery_medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'gallery_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_image_caption',
    'label' => 'Caption',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_s_gallery_image_info-field_s_image_credits'
  $field_instances['field_collection_item-field_s_gallery_image_info-field_s_image_credits'] = array(
    'bundle' => 'field_s_gallery_image_info',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the photographer or organization credits.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'gallery_large' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'gallery_large_scaled' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'gallery_medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'gallery_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_image_credits',
    'label' => 'Credits',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_s_gallery_image_info-field_s_image_image'
  $field_instances['field_collection_item-field_s_gallery_image_info-field_s_image_image'] = array(
    'bundle' => 'field_s_gallery_image_info',
    'deleted' => 0,
    'description' => 'Your image will be scaled and cropped when it is displayed. You can choose a size through the \'Thumbnail size\' field above.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'med-square',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'gallery_large' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'large-square',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'gallery_large_scaled' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'large-scaled',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'gallery_medium' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'med-square',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'gallery_small' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'sm-square',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_image_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'gallery',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1200x1200',
      'min_resolution' => '50x50',
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
          'colorbox__caw-6-col-banner' => 0,
          'colorbox__caw-9-col-banner-tall' => 0,
          'colorbox__caw-banner' => 0,
          'colorbox__caw-carousel' => 0,
          'colorbox__caw-landscape-xlarge' => 0,
          'colorbox__caw-large-landscape' => 0,
          'colorbox__caw-med-landscape' => 0,
          'colorbox__caw-sm-landscape' => 0,
          'colorbox__icon-profile' => 0,
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
          'colorbox__sm-square' => 0,
          'colorbox__su-gallery-tabs-large' => 0,
          'colorbox__sweetener_-_card' => 0,
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
          'image_caw-6-col-banner' => 0,
          'image_caw-9-col-banner-tall' => 0,
          'image_caw-banner' => 0,
          'image_caw-carousel' => 0,
          'image_caw-landscape-xlarge' => 0,
          'image_caw-large-landscape' => 0,
          'image_caw-med-landscape' => 0,
          'image_caw-sm-landscape' => 0,
          'image_icon-profile' => 0,
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
          'image_sm-square' => 0,
          'image_su-gallery-tabs-large' => 0,
          'image_sweetener_-_card' => 0,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_s_gallery_image_info-field_s_image_source_info'
  $field_instances['field_collection_item-field_s_gallery_image_info-field_s_image_source_info'] = array(
    'bundle' => 'field_s_gallery_image_info',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This text field gives you a place to record source and other information for identifying this image. For example, if it has changed, you can enter the original name of this image. This record-keeping information is hidden and is not displayed with the image.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'gallery_large' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'gallery_large_scaled' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'gallery_medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'gallery_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_image_source_info',
    'label' => 'Source Info',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-stanford_gallery-body'
  $field_instances['node-stanford_gallery-body'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Content added to this field will show up above the thumbnails.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
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
    'label' => 'Description',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-stanford_gallery-field_s_gallery_image_info'
  $field_instances['node-stanford_gallery-field_s_gallery_image_info'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'stanford_gallery',
        'settings' => array(),
        'type' => 'stanford_gallery',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'stanford_gallery',
        'settings' => array(),
        'type' => 'stanford_gallery',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_gallery_image_info',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-stanford_gallery-field_s_gallery_show_capt'
  $field_instances['node-stanford_gallery-field_s_gallery_show_capt'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this box to display the captions in the modal pop up. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_s_gallery_show_capt',
    'label' => 'Show Captions',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-stanford_gallery-field_s_gallery_view_mode'
  $field_instances['node-stanford_gallery-field_s_gallery_view_mode'] = array(
    'bundle' => 'stanford_gallery',
    'default_value' => array(
      0 => array(
        'value' => 'gallery_medium',
      ),
    ),
    'deleted' => 0,
    'description' => 'Change the size of the thumbnails displayed on the page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_s_gallery_view_mode',
    'label' => 'Thumbnail Size',
    'required' => 1,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Caption');
  t('Change the size of the thumbnails displayed on the page.');
  t('Check this box to display the captions in the modal pop up. ');
  t('Content added to this field will show up above the thumbnails.');
  t('Credits');
  t('Description');
  t('Enter the photographer or organization credits.');
  t('Image');
  t('Optionally enter information to appear as a caption for this image. This caption appears in the modal pop up after the user clicks on a thumbnail.');
  t('Show Captions');
  t('Source Info');
  t('This text field gives you a place to record source and other information for identifying this image. For example, if it has changed, you can enter the original name of this image. This record-keeping information is hidden and is not displayed with the image.');
  t('Thumbnail Size');
  t('Your image will be scaled and cropped when it is displayed. You can choose a size through the \'Thumbnail size\' field above.');

  return $field_instances;
}
