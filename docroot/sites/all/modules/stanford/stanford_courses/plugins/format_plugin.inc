<?php

/**
 * @file
 * Feeds Tamper Plugin.
 *
 * Format date string using date().
 */

/**
 * Plugin Definition.
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
 */
function stanford_courses_format_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Format a string using the !date function.', array('!date' => l(t('date()'), 'http://www.php.net/manual/en/function.date.php')));
  $form['format']['#type'] = 'textfield';
  $form['format']['#title'] = t('Format string');
  if (isset($settings['format'])) {
    $form['format']['#default_value'] = $settings['format'];
  }
  $form['format']['#size'] = '60';
  $form['format']['#description'] = t('Enter the format you would like to use to output this string. See !datedocs for more information.', array('!datedocs' => l(t('the date() function documentation'), 'http://www.php.net/manual/en/function.date.php')));

  return $form;
}

/**
 * Feeds tamper format callback.
 *
 * Parses the data from the feed into a formatted date set by the configuration
 * form.
 */
function stanford_courses_format_callback($source, $item_key, $element_key, &$field, $settings) {
  // Ensure we have configuration settings.
  if (!isset($settings['format'])) {
    return;
  }
  $format = $settings['format'];

  // Check to see if we have a number!
  // If not then just return the field as is.
  if (!is_numeric($field)) {
    return;
  }
  elseif ($format) {
    // Set the formatted date.
    $field = date($format, $field);
  }
}
