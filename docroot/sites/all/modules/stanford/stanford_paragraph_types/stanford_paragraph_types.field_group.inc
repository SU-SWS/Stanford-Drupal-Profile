<?php
/**
 * @file
 * stanford_paragraph_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_paragraph_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_callout_span|paragraphs_item|p_callout|default';
  $field_group->group_name = 'group_callout_span';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_callout';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Callout Span',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_callout_text',
      1 => 'field_p_callout_more_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Callout Span',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'span8 offset2',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_callout_span|paragraphs_item|p_callout|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_title|field_collection_item|field_p_cards_card|default';
  $field_group->group_name = 'group_card_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_cards_card';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card Title',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_card_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Card Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-card-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_card_title|field_collection_item|field_p_cards_card|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_image|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_featured_image';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_menu_main';
  $field_group->data = array(
    'label' => 'Featured Image',
    'weight' => '7',
    'children' => array(
      0 => 'field_p_menu_image',
      1 => 'group_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Featured Image',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-featured-image field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_featured_image|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_image|paragraphs_item|p_menu|form';
  $field_group->group_name = 'group_featured_image';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_content';
  $field_group->data = array(
    'label' => 'Featured Image',
    'weight' => '3',
    'children' => array(
      0 => 'field_p_menu_image',
      1 => 'field_p_menu_image_caption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-featured-image field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_featured_image|paragraphs_item|p_menu|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_h2|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_header_h2';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_menu_main';
  $field_group->data = array(
    'label' => 'Header H2',
    'weight' => '6',
    'children' => array(
      0 => 'field_p_menu_header',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Header H2',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-header-h2 field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_header_h2|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline_h2|paragraphs_item|p_hero|default';
  $field_group->group_name = 'group_headline_h2';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_hero';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_overlay_text';
  $field_group->data = array(
    'label' => 'Headline H2',
    'weight' => '10',
    'children' => array(
      0 => 'field_p_hero_headline',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Headline H2',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-headline-h2 field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_headline_h2|paragraphs_item|p_hero|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_caption|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_image_caption';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_featured_image';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '16',
    'children' => array(
      0 => 'field_p_menu_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'caption',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_image_caption|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_column|paragraphs_item|p_menu|form';
  $field_group->group_name = 'group_left_column';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_p_menu';
  $field_group->data = array(
    'label' => 'Left Column',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_menu_below_menu',
      1 => 'field_p_menu_menu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_left_column|paragraphs_item|p_menu|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_column|paragraphs_item|p_wysiwyg|default';
  $field_group->group_name = 'group_left_column';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Column',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_wysiwyg_body',
      1 => 'group_wysiwyg_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left-column field-group-div span6',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_left_column|paragraphs_item|p_wysiwyg|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|paragraphs_item|p_menu|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_p_menu';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_menu_file_insert',
      1 => 'field_p_menu_header',
      2 => 'field_p_menu_image_insert',
      3 => 'field_p_menu_wysiwyg',
      4 => 'group_featured_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_main_content|paragraphs_item|p_menu|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_column|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_menu_column';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu Column',
    'weight' => '0',
    'children' => array(
      0 => 'group_sidebar',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Menu Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-menu-column field-group-div span3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_menu_column|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_main|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_menu_main';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_menu_wysiwyg',
      1 => 'group_featured_image',
      2 => 'group_header_h2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-menu-main field-group-div span9',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_menu_main|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay_text|paragraphs_item|p_hero|default';
  $field_group->group_name = 'group_overlay_text';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_hero';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_hero_more_link',
      1 => 'field_p_hero_superhead',
      2 => 'group_headline_h2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay Text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-overlay-text field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_overlay_text|paragraphs_item|p_hero|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay_text|paragraphs_item|p_hero|form';
  $field_group->group_name = 'group_overlay_text';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_p_hero';
  $field_group->data = array(
    'label' => 'Overlay Text',
    'weight' => '11',
    'children' => array(
      0 => 'field_p_hero_alignment',
      1 => 'field_p_hero_headline',
      2 => 'field_p_hero_more_link',
      3 => 'field_p_hero_superhead',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overlay-text field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_overlay_text|paragraphs_item|p_hero|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_buttons|paragraphs_item|p_buttons|form';
  $field_group->group_name = 'group_p_buttons';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_buttons';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buttons',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_buttons_button',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Buttons',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-buttons field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_buttons|paragraphs_item|p_buttons|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_callout|paragraphs_item|p_callout|form';
  $field_group->group_name = 'group_p_callout';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_callout';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Callout Text',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_callout_more_link',
      1 => 'field_p_callout_text',
      2 => 'field_p_callout_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Callout Text',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-callout field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_callout|paragraphs_item|p_callout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_card_color|field_collection_item|field_p_cards_card|form';
  $field_group->group_name = 'group_p_card_color';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_cards_card';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add Some Color',
    'weight' => '3',
    'children' => array(
      0 => 'field_p_card_color',
      1 => 'field_p_card_pattern',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add Some Color',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-card-color field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_p_card_color|field_collection_item|field_p_cards_card|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_card_cta|field_collection_item|field_p_cards_card|form';
  $field_group->group_name = 'group_p_card_cta';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_cards_card';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call To Action',
    'weight' => '3',
    'children' => array(
      0 => 'field_p_card_action_button',
      1 => 'field_p_card_cta',
      2 => 'field_p_card_file',
      3 => 'field_p_card_hide_cta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Call To Action',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-card-cta field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_card_cta|field_collection_item|field_p_cards_card|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_cards|paragraphs_item|p_cards|form';
  $field_group->group_name = 'group_p_cards';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_cards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser Cards',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_cards_card',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Cards',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-cards field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_cards|paragraphs_item|p_cards|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_hero|paragraphs_item|p_hero|form';
  $field_group->group_name = 'group_p_hero';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_hero';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_hero_image',
      1 => 'field_p_hero_video',
      2 => 'field_p_hero_style',
      3 => 'group_overlay_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Hero',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-hero field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_hero|paragraphs_item|p_hero|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_readmore|field_collection_item|field_p_icon_columns|default';
  $field_group->group_name = 'group_p_icon_readmore';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_icon_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_icon_readmore|field_collection_item|field_p_icon_columns|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_readmore|field_collection_item|field_p_icon_columns|full';
  $field_group->group_name = 'group_p_icon_readmore';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_icon_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_icon_readmore|field_collection_item|field_p_icon_columns|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_readmore|field_collection_item|field_p_icon_columns|stanford_list';
  $field_group->group_name = 'group_p_icon_readmore';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'stanford_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_icon_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_icon_readmore|field_collection_item|field_p_icon_columns|stanford_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_title|field_collection_item|field_p_icon_columns|default';
  $field_group->group_name = 'group_p_icon_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_icon_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-icon-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_p_icon_title|field_collection_item|field_p_icon_columns|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_title|field_collection_item|field_p_icon_columns|full';
  $field_group->group_name = 'group_p_icon_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_icon_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-icon-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_p_icon_title|field_collection_item|field_p_icon_columns|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon_title|field_collection_item|field_p_icon_columns|stanford_list';
  $field_group->group_name = 'group_p_icon_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'stanford_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_icon_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-icon-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_p_icon_title|field_collection_item|field_p_icon_columns|stanford_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icons|paragraphs_item|p_icon|form';
  $field_group->group_name = 'group_p_icons';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_icon';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icons',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_icon_columns',
      1 => 'field_p_icons_per_row',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Icons',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-icons field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_icons|paragraphs_item|p_icon|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_icon|field_collection_item|field_p_icon_columns|form';
  $field_group->group_name = 'group_p_icon';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icon',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_icon_color',
      1 => 'field_p_icon_icon',
      2 => 'field_p_icon_image',
      3 => 'field_p_icon_icon_style',
      4 => 'field_p_icon_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-p-icon field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_p_icon|field_collection_item|field_p_icon_columns|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_menu|paragraphs_item|p_menu|form';
  $field_group->group_name = 'group_p_menu';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_left_column',
      1 => 'group_main_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Menu Group',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-menu field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_menu|paragraphs_item|p_menu|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_wysiwyg_body|paragraphs_item|p_wysiwyg|full';
  $field_group->group_name = 'group_p_wysiwyg_body';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_p_wysiwyg_wrapper';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_p_wysiwyg_body',
      1 => 'group_p_wysiwyg_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-wysiwyg-body field-group-div span8 offset2',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_wysiwyg_body|paragraphs_item|p_wysiwyg|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_wysiwyg_title|paragraphs_item|p_wysiwyg|full';
  $field_group->group_name = 'group_p_wysiwyg_title';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_p_wysiwyg_body';
  $field_group->data = array(
    'label' => 'WYSIWYG Title',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_wysiwyg_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'WYSIWYG Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-wysiwyg-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_p_wysiwyg_title|paragraphs_item|p_wysiwyg|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_wysiwyg_wrapper|paragraphs_item|p_wysiwyg|full';
  $field_group->group_name = 'group_p_wysiwyg_wrapper';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_p_wysiwyg_body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-wysiwyg-wrapper field-group-div row-fluid',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_wysiwyg_wrapper|paragraphs_item|p_wysiwyg|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_wysiwyg|paragraphs_item|p_wysiwyg|form';
  $field_group->group_name = 'group_p_wysiwyg';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Area',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_wysiwyg_body',
      1 => 'field_p_wysiwyg_button',
      2 => 'field_p_wysiwyg_image',
      3 => 'field_p_wysiwyg_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Text Area',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-wysiwyg field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_wysiwyg|paragraphs_item|p_wysiwyg|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_read_more|field_collection_item|field_p_icon_columns|stanford_block';
  $field_group->group_name = 'group_read_more';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'stanford_block';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '3',
    'children' => array(
      0 => 'field_p_icon_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_read_more|field_collection_item|field_p_icon_columns|stanford_block'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_column|paragraphs_item|p_wysiwyg|default';
  $field_group->group_name = 'group_right_column';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Column',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_wysiwyg_button',
      1 => 'field_p_wysiwyg_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right Column',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right-column field-group-div span6',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_right_column|paragraphs_item|p_wysiwyg|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|paragraphs_item|p_menu|default';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_menu_column';
  $field_group->data = array(
    'label' => 'Sidebar Nav',
    'weight' => '10',
    'children' => array(
      0 => 'field_p_menu_menu',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sidebar Nav',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-sidebar field-group-div sidebar',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_sidebar|paragraphs_item|p_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|field_collection_item|field_p_icon_columns|stanford_block';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_p_icon_columns';
  $field_group->mode = 'stanford_block';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '2',
    'children' => array(
      0 => 'field_p_icon_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_title|field_collection_item|field_p_icon_columns|stanford_block'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wysiwyg_title|paragraphs_item|p_wysiwyg|default';
  $field_group->group_name = 'group_wysiwyg_title';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_left_column';
  $field_group->data = array(
    'label' => 'WYSIWYG Title',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_wysiwyg_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'WYSIWYG Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-wysiwyg-title field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_wysiwyg_title|paragraphs_item|p_wysiwyg|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Some Color');
  t('Buttons');
  t('Call To Action');
  t('Callout Span');
  t('Callout Text');
  t('Caption');
  t('Card Title');
  t('Featured Image');
  t('Header H2');
  t('Headline H2');
  t('Hero');
  t('Icon');
  t('Icons');
  t('Left Column');
  t('Main');
  t('Main Content');
  t('Menu Column');
  t('Menu Group');
  t('Overlay Text');
  t('Read More');
  t('Right Column');
  t('Sidebar Nav');
  t('Teaser Cards');
  t('Text Area');
  t('Title');
  t('WYSIWYG Title');
  t('Wrapper');

  return $field_groups;
}
