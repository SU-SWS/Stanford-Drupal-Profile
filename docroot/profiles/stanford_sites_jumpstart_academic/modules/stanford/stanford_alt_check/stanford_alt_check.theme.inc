<?php

/**
 * @file
 * Stanford Alt Check Theme.
 */

/**
 * Themes the form as a table.
 *
 * @param array $vars
 *   Form array.
 *
 * @return string
 *   Rendered html.
 */
function theme_stanford_alt_check_form(array $vars) {
  $form = $vars['form'];
  $header = _stanford_alt_check_table_headers();

  $rows = array();
  foreach (element_children($form) as $key) {
    // Skips buttons and fieldsets.
    if (!isset($form[$key]['alt'])) {
      continue;
    }

    $rows[] = array(
      'Image' => drupal_render($form[$key]['image']),
      'Title' => drupal_render($form[$key]['title']),
      'Entity Type' => drupal_render($form[$key]['type']),
      'Entity Bundle' => drupal_render($form[$key]['bundle']),
      'Published' => drupal_render($form[$key]['published']),
      'Alt Text' => drupal_render($form[$key]['alt']),
      'Changed' => drupal_render($form[$key]['changed']),
    );
  }

  $table_vars = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(),
    'empty' => t('No images available at this time.'),
    'caption' => '',
    'colgroups' => array(),
    'sticky' => FALSE,
  );

  $output = drupal_render($form['filter_set']);
  $output .= theme('table', $table_vars);
  $output .= drupal_render_children($form);

  return $output;
}
