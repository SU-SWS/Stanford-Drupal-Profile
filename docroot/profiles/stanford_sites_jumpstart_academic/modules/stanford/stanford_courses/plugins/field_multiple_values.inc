<?php
/**
 * @file
 * Feeds Tamper Plugin
 * Provides a sub xpath selector for parsing xml for field collections with
 * multiple value fields.
 */

/**
 * Plugin definition
 */
$plugin = array(
    'form' => 'stanford_courses_field_multiple_values_form',
    'callback' => 'stanford_courses_field_multiple_values_callback',
    'multi' => 'direct',
    'name' => 'Multiple Values to Multiple Value Field',
    'category' => 'Field Collection',
);

/**
 * Implements hook_form().
 *
 * Returns a configuration form for the field_multiple_values feeds tamper plugin
 */
function stanford_courses_field_multiple_values_form($importer, $element_key, $settings) {
    $form = array();
    $form['help']['#markup'] = 'Provide a secondary XPath selector. This selector starts from the results of the XPath parser that this tamper is applied to. This will allow you to maintain the correct order in field collection items with multiple values.';
    $form['subxpath'] = array(
      '#type' => 'textfield',
      '#title' => 'XPath',
      '#description' => t('Provide a secondary XPath selector for parsing individual items.'),
      '#default_value' => $settings['subxpath'],
    );
    $form['datatype'] = array(
      '#type' => 'select',
      '#title' => 'Data Type',
      '#options' => array(
        'string' => t('String'),
        'integer' => t('Integer'),
      ),
      '#description' => t('Provide the type of data the XPath selector should return.'),
      '#default_value' => $settings['datatype'],
    );
    return $form;
}

/**
 * Callback function for feeds tamper field_multiple values plugin. Takes the
 * results of an existing XPath results set as raw xml and runs another
 * sub query on the results in order to get multiple values into one field. Very
 * useful for when processing values on a field-collection.
 *
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 * @return [type]              [description]
 */
function stanford_courses_field_multiple_values_callback($source, $item_key, $element_key, &$field, $settings) {

  // Storage
  $new_field = array();
  $values = array();

  // Check for single and multiple value results from previous XPath.
  if (is_array($field)) {
   foreach ($field as $section) {
     // Turn raw result xml to a workable format.
      try {
        $values[] = new SimpleXMLElement($section);
      } catch(Exception $e) {
        // Could not parse field we need to continue.
        return;
      }
    }
  }
  else {
    // Turn raw result xml to a workable format.
    try {
      $values[] = new SimpleXMLElement($field);
    } catch(Exception $e) {
      // Could not parse field we need to continue.
      return;
    }
  }

  // Reset the field values.
  $field = array();

  // Loop through the previous XPath results and run through
  foreach($values as $k => $v) {

    // If not an xml object then just continue.
    if (!is_object($v)) {
      continue;
    }

    // On each result set of xml run another xpath over it to find the data
    // that we want.
    $subset = $v->xpath($settings['subxpath']);

    if (empty($subset)) {
      $field[$k][] = "";
      continue;
    }

    foreach ($subset as $result) {
      switch($settings['datatype']) {
        case "integer":
          $field[$k][] = (integer) $result;
          break;
        case "string":
        default:
          $field[$k][] = (string) $result;
      } //switch
    } // foreach

  } // foreach

}
