<?php
/**
 * @file
 * Feeds Tamper Plugin
 * Run values through some date math processing().
 */

/**
 * Plugin definition
 */
$plugin = array(
  'form' => 'stanford_courses_datemath_form',
  'callback' => 'stanford_courses_datemath_callback',
  'multi' => 'loop',
  'name' => 'Unix TimeStamp Date Math',
  'category' => 'Date/time',
 );

/**
 * Implements hook_form().
 * 
 * Returns a configuration form for the datemath feeds tamper plugin
 */
function stanford_courses_datemath_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Perform calculations on Unix TimeStamps.');

  $form['operative']['#type'] = 'select';
  $form['operative']['#title'] = t('Action');
  $form['operative']['#default_value'] = $settings['operative'];
  $form['operative']['#options'] = array(
    'add' => 'Add Amount of Time',
    'subtract' => 'Remove Amount of Time',
  );
  $form['operative']['#description'] = t('Add or remove an amount of time from a string');

  $form['amount']['#type'] = 'textfield';
  $form['amount']['#title'] = t('Amount of time');
  $form['amount']['#default_value'] = $settings['amount'];
  $form['amount']['#size'] = '80';
  $form['amount']['#description'] = t('Enter a human readable amount of time, e.g., "1 day", "12 hours", "9 months"');


  return $form;
}

/**
 * Callback function for feeds tamper datemath plugin. Processes input data into
 * a time and performs date math like 'add one day' to it.
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 * @return [type]              [description]
 */
function stanford_courses_datemath_callback($source, $item_key, $element_key, &$field, $settings) {

  // Ensure data is valid. Can't trust feeds.
  $datetime = $field;
  if (!is_numeric($datetime)) {
    $datetime = strtotime($field);
    if (!is_numeric($datetime)) {
      return $field;
    }
  }

  // So far only two operations. Add or remove.
  $opt = ($settings['operative'] == "subtract") ? "-" : "+";
  $datetime = strtotime($opt . $settings['amount'], $datetime);

  // Check to see if our math worked. If not then leave field as original.
  if (is_numeric($datetime)) {
    $field = $datetime;
  }

}
