<?php
/**
 * @file
 * stanford_bean_types.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_bean_types_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_banner';
  $bean_type->label = 'Stanford Banner';
  $bean_type->options = '';
  $bean_type->description = 'Displays a banner image to be used in the header on pages.';
  $export['stanford_banner'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_big_text_block';
  $bean_type->label = 'Stanford Big Text Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['stanford_big_text_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_contact';
  $bean_type->label = 'Stanford Contact';
  $bean_type->options = '';
  $bean_type->description = 'Contact information (e.g., address, phone, email, etc.)';
  $export['stanford_contact'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_icon_block';
  $bean_type->label = 'Stanford Icon Block';
  $bean_type->options = 'A postcard like block with the ability to have a font-awesome based icon next to the title.';
  $bean_type->description = '';
  $export['stanford_icon_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_large_block';
  $bean_type->label = 'Stanford Large Block';
  $bean_type->options = '';
  $bean_type->description = 'For larger amounts of content than a traditional side-bar block, this block is also used in larger spaces. Use this when content spans 8 columns.
You can insert files and images into your body content. There is no header image.';
  $export['stanford_large_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_postcard';
  $bean_type->label = 'Stanford Postcard';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['stanford_postcard'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_social_media_connect';
  $bean_type->label = 'Stanford Social Media Connect';
  $bean_type->options = '';
  $bean_type->description = 'Add your social media links (e.g., Facebook, Twitter, YouTube, etc.)';
  $export['stanford_social_media_connect'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_testimonial_block';
  $bean_type->label = 'Stanford Testimonial Block';
  $bean_type->options = '';
  $bean_type->description = 'Testimonial blocks are used to feature a headshot, quote, and attribution.';
  $export['stanford_testimonial_block'] = $bean_type;

  return $export;
}
