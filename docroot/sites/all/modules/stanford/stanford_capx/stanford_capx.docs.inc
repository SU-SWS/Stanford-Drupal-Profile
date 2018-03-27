<?php

/**
 * @file
 * A place to put documentation related functionality.
 */

use CAPx\Drupal\Util\CAPxConnection;
use \Peekmo\JsonPath\JsonStore as JsonParser;

define('STANFORD_CAPX_SAMPLE_PROFILE', 'sample_profile.json');

/**
 * Menu callback to display the CAPx Data Browser.
 *
 * @return array
 *   A render array for the data browser block.
 */
function stanford_capx_admin_config_data_browser() {
  $base = drupal_get_path('module', 'stanford_capx');

  // Render the refresh schema form button.
  $output['refresh'] = drupal_get_form('stanford_capx_admin_config_data_browser_refresh');

  // Provide a place to render the tree.
  $output['content']['#markup'] = '<div class="capx-schema-controls"></div><div id="capx-schema"></div>';

  // Load the CAP profile schema json.
  $schema = stanford_capx_schema_load('json');

  // Convert the schema to a jqTree compatible format.
  $jq_tree = stanford_capx_jqTree_get($schema);

  // Attach the default jsTree CSS.
  $output['#attached']['css'] = array();
  $output["#attached"]["css"][] = $base . '/js/jqTree/jqtree.css';
  $output["#attached"]["css"][] = $base . '/css/stanford_capx.docs.css';

  // Attach libs, js & render the formatted array to Drupal.settings.
  $output['#attached']['js'] = array(
    $base . '/js/jqTree/tree.jquery.js',
    $base . '/js/stanford_capx.docs.js',
    array(
      'data' => array(
        'stanford_capx' => array(
          'schema' => $jq_tree,
        ),
      ),
      'type' => 'setting',
    ),
  );

  return $output;
}

/**
 * Form to clear the cached CAP schema and sample profile data files.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state according to the Drupal api.
 *
 * @return array
 *   The form array.
 */
function stanford_capx_admin_config_data_browser_refresh(array $form, array &$form_state) {
  $form = array();

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh Schema'),
  );

  return $form;
}

/**
 * Form submit handler to clear the cached CAP files.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function stanford_capx_admin_config_data_browser_refresh_submit(array $form, array &$form_state) {
  stanford_capx_admin_data_browser_schema_flush();
}

/**
 * Delete the cached CAP schema files.
 */
function stanford_capx_admin_data_browser_schema_flush() {
  $files = array(
    'schema_file' => STANFORD_CAPX_FILE_PATH . "/" . STANFORD_CAPX_SCHEMA_FILE,
    'sample_data_file' => STANFORD_CAPX_FILE_PATH . "/" . STANFORD_CAPX_SAMPLE_PROFILE,
  );

  // Delete the cached files, which will be re-fetched on next page reload.
  foreach ($files as $file) {
    file_unmanaged_delete($file);
  }
}

/**
 * Render the CAP Profile Schema as a jqTree compatible JSON structure.
 *
 * @param string $schema_json
 *   The json string.
 *
 * @return mixed
 *   False if there is an error.
 */
function stanford_capx_jqTree_get($schema_json) {
  $decoded_json = json_decode($schema_json);
  return is_object($decoded_json) ? stanford_capx_jqTree_render($decoded_json->properties) : FALSE;
}

/**
 * Traverse the schema and render the desired schema elements.
 *
 * @param object $schema
 *   The schema array.
 * @param array $parents
 *   The parents for the schema array.
 *
 * @return array
 *   The jqtree renderable data.
 */
function stanford_capx_jqTree_render(&$schema, array $parents = array()) {
  // Initialize variables for collecting the field metadata.
  $branch = array();
  $metadata = array();

  // Iterate over each property of the schema objects.
  foreach ($schema as $name => $element) {
    // Initialize the leaf to collect a single piece of metadata E.g. Type.
    $leaf = new stdClass();

    // Is the current object property a string or a child object?
    switch (gettype($element)) {
      case 'string':
        // Strings describe the field metadata.
        switch ($name) {
          case 'type':
            // Render field type.
            $leaf->label = t('Type:') . ' ' . check_plain($element);
            $metadata[1] = $leaf;

            // Don't bother selecting branches, only leaves - actual values.
            if ($element !== 'array') {
              // Calculate and render the JSON selector.
              $leaf = new stdClass();
              $selector = '$.' . implode($parents, '.');
              $leaf->label = t('Selector:') . ' ' . $selector;
              $metadata[4] = $leaf;

              // Find and render the sample profile data.
              $sample_data = stanford_capx_sample_data($selector);
              $sample_data = check_plain(stanford_capx_sample_data_render($sample_data));

              // Only display sample data if sample data exists.
              if (!empty($sample_data)) {
                $leaf = new stdClass();
                $leaf->label = t('Sample data:') . ' ' . $sample_data;
                $metadata[5] = $leaf;
              }
            }
            break;

          case 'description':
            // Render field description.
            $leaf->label = t('Description:') . ' ' . check_plain($element);
            $metadata[2] = $leaf;
            break;

          case 'metadata':
            // Render field metadata property. Always 'true' if present.
            $leaf->label = t('Metadata:') . ' ' . check_plain($element);
            $metadata[3] = $leaf;
            break;
        }
        break;

      case 'object':
        // An object indicates another child (branch) in the tree to render.
        $child_branch = new stdClass();

        // Fall back to the element name if title property not set.
        $child_branch->label = isset($element->title) && is_string($element->title) ? check_plain($element->title) : check_plain($name);

        // Don't render object "properties" in the selector.
        if ($name !== 'properties') {
          // Push the current element name for calculating the JSON selector or
          // use the '*' operator to select all elements of the array.
          $name === 'items' ? array_push($parents, '*') : array_push($parents, $name);
        }

        // Recursively process child properties.
        $child_branch->children = stanford_capx_jqTree_render($element, $parents);

        // Pop the current element name; it was just recursively processed.
        if ($name !== 'properties') {
          array_pop($parents);
        }

        // Add the child branch to the current branch.
        $branch[] = $child_branch;
        break;
    }
  }

  // Sort the display order of element metadata by key.
  ksort($metadata);

  // Merge the arrays, forcing the metadata to the top of each property.
  return array_merge($metadata, $branch);
}

/**
 * Prepare the value(s) returned from querying the sample data.
 *
 * @param array $sample_data
 *   Sample data to use.
 *
 * @return mixed
 *   False if there was an error.
 */
function stanford_capx_sample_data_render($sample_data) {
  // Is there a boolean value in the $sample_data array?
  if (is_array($sample_data)) {
    if (count($sample_data)) {
      // Pull out the value.
      $sample_data = current($sample_data);
    }
    else {
      // No data was found.
      return FALSE;
    }
  }

  // Sometimes, the data is an array in an array E.g. 'keywords'.
  $sample_data = is_array($sample_data) ? stanford_capx_sample_data_render(array_pop($sample_data)) : $sample_data;

  // Render booleans - so that we don't print empty string for FALSE.
  if (is_bool($sample_data)) {
    $sample_data = $sample_data ? t('TRUE') : t('FALSE');
  }

  return $sample_data;
}

/**
 * Fetch, cache and query the sample data profile.
 *
 * @param string $selector
 *   The selector.
 *
 * @return string
 *   The selected data.
 */
function stanford_capx_sample_data($selector) {
  static $sample_profile;
  static $json_parser;
  $file = STANFORD_CAPX_FILE_PATH . "/" . STANFORD_CAPX_SAMPLE_PROFILE;

  // Load and static cache the sample data file.
  if (!isset($sample_profile)) {
    if (file_exists($file)) {
      // Load sample data from the file cache.
      $json = file_get_contents(STANFORD_CAPX_FILE_PATH . "/" . STANFORD_CAPX_SAMPLE_PROFILE);
    }
    else {
      // Fetch the profile from CAP and save to file cache.
      $client = CAPxConnection::getAuthenticatedHTTPClient();

      // Profile of "swberg".
      $response = $client->api('profile')->getRaw(32640);

      $json = $response->getBody(TRUE);
      file_unmanaged_save_data($json, $file, FILE_EXISTS_REPLACE);
    }

    // Decode to array format, as preferred by JsonParser.
    $sample_profile = json_decode($json, TRUE);
  }

  // Load and persist the parser.
  if (!isset($json_parser)) {
    $json_parser = new JsonParser($sample_profile);
  }

  // Find the value for the given selector.
  return $json_parser->get($selector);
}
