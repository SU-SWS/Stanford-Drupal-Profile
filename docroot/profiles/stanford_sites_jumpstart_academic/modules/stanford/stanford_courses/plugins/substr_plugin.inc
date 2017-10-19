<?php
/*
 * @file Run values through substr().
 */

$plugin = array(
  'form' => 'stanford_courses_substr_form',
  'callback' => 'stanford_courses_substr_callback',
  'multi' => 'loop',
  'name' => 'Substring',
  'category' => 'Text',
 );

function stanford_courses_substr_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Run values through the !substr function.', array('!substr' => l('substr()', 'http://us3.php.net/substr')));
  $form['start']['#type'] = 'textfield';
  $form['start']['#title'] = t('Starting character');
  $form['start']['#default_value'] = $settings['start'];
  $form['start']['#size'] = '3';
  $form['start']['#description'] = t('Enter the position of the starting character of your substring (counting from 0).');
  $form['length']['#type'] = 'textfield';
  $form['length']['#title'] = t('Length');
  $form['length']['#default_value'] = $settings['length'];
  $form['length']['#size'] = '3';
  $form['length']['#description'] = t('Enter the length of your substring.');

  return $form;
}

function stanford_courses_substr_callback($source, $item_key, $element_key, &$field, $settings) {
  $start = $settings['start'];
  if(!empty($settings['length']) && !empty($field)) {
    $length = $settings['length'];
    $field = substr($field, $start, $length);
  }
  else if (!empty($field)) {
    $field = substr($field, $start);
  }
}
