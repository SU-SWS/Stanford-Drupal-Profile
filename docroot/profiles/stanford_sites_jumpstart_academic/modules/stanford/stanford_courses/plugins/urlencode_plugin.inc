<?php
/*
 * @file Run values through urlencode().
 */

$plugin = array(
  'form' => 'stanford_courses_urlencode_form',
  'callback' => 'stanford_courses_urlencode_callback',
  'multi' => 'loop',
  'name' => 'URL Encode',
  'category' => 'Other',
 );

function stanford_courses_urlencode_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Run values through the !urlencode function.', array('!urlencode' => l('urlencode()', 'http://us3.php.net/urlencode')));
  return $form;
}

function stanford_courses_urlencode_callback($source, $item_key, $element_key, &$field, $settings) {
  $field = urlencode($field);
}
