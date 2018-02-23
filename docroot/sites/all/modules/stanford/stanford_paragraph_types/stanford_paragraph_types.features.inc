<?php
/**
 * @file
 * stanford_paragraph_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_paragraph_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function stanford_paragraph_types_paragraphs_info() {
  $items = array(
    'p_buttons' => array(
      'name' => 'Buttons',
      'bundle' => 'p_buttons',
      'locked' => '1',
    ),
    'p_callout' => array(
      'name' => 'Callout Text',
      'bundle' => 'p_callout',
      'locked' => '1',
    ),
    'p_cards' => array(
      'name' => 'Teaser Cards',
      'bundle' => 'p_cards',
      'locked' => '1',
    ),
    'p_hero' => array(
      'name' => 'Hero',
      'bundle' => 'p_hero',
      'locked' => '1',
    ),
    'p_icon' => array(
      'name' => 'Icon Grid',
      'bundle' => 'p_icon',
      'locked' => '1',
    ),
    'p_menu' => array(
      'name' => 'Menu with Text Area',
      'bundle' => 'p_menu',
      'locked' => '1',
    ),
    'p_wysiwyg' => array(
      'name' => 'Text Area',
      'bundle' => 'p_wysiwyg',
      'locked' => '1',
    ),
  );
  return $items;
}
