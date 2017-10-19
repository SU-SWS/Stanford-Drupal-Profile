<?php
/**
 * @file
 * Feeds Tamper Plugin
 * Format date string using date().
 */

/**
 * Plugin Definition
 */
$plugin = array(
  'form' => 'stanford_courses_format_form',
  'callback' => 'stanford_courses_format_callback',
  'multi' => 'loop',
  'name' => 'Format date/time string',
  'category' => 'Date/time',
);

/**
 * Returns a configuration form for feeds tamper.
 * @param  [type] $importer    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $settings    [description]
 * @return array                The Form
 */
function stanford_courses_format_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Format a string using the !date function.', array('!date' => l('date()', 'http://www.php.net/manual/en/function.date.php')));
  $form['format']['#type'] = 'textfield';
  $form['format']['#title'] = t('Format string');
  if(isset($settings['format'])) {
    $form['format']['#default_value'] = $settings['format'];
  }
  $form['format']['#size'] = '60';
  $form['format']['#description'] = t('Enter the format you would like to use to output this string. See !datedocs for more information.', array('!datedocs' => l('the date() function documentation', 'http://www.php.net/manual/en/function.date.php')));

  return $form;
}

/**
 * Feeds tamper format callback. Parses the data from the feed into a formatted
 * date set by the configuration form.
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 * @return string              a formatted date string
 */
function stanford_courses_format_callback($source, $item_key, $element_key, &$field, $settings) {

  // Ensure we have configuration settings.
  if (isset($settings['format'])) {
    $format = $settings['format'];
  }

  // Check to see if we have a number!
  // If not then just return the field as is.
  if (!is_numeric($field)) {
    return;
  }

  // Set the formatted date.
  $field = date($format, $field);
}
