<?php

/**
 * @file
 * CAPx Tamper Theme functions.
 */

/**
 * Process sortable table.
 *
 * @param array $vars
 *   Variables.
 *
 * @return string
 *   Themed output.
 */
function theme_capx_tamper_list_form($vars) {
  $form = $vars['form'];

  $header = array(
    t('Description'),
    t('Plugin'),
    t('Operations'),
    t('Weight'),
    t('Enabled'),
  );

  $output = drupal_render($form['mapper']);

  foreach (element_children($form['tampers']) as $target) {
    $caption = drupal_render($form['tampers'][$target]['caption']);
    $rows = array();

    foreach (element_children($form['tampers'][$target]) as $tamper_id) {
      if ($tamper_id == 'caption' || $tamper_id == 'add_link') {
        continue;
      }
      $rows[] = array(
        'data' => array(
          drupal_render($form['tampers'][$target][$tamper_id]['description']),
          drupal_render($form['tampers'][$target][$tamper_id]['plugin_id']),
          drupal_render($form['tampers'][$target][$tamper_id]['operations']),
          drupal_render($form['tampers'][$target][$tamper_id]['weight']),
          drupal_render($form['tampers'][$target][$tamper_id]['enabled']),
        ),
        'class' => array('draggable', 'group-' . capx_tamper_table_id($target)),
      );
    }

    // Empty plugins.
    if (!$rows) {
      $rows[] = array(
        array(
          'data' => t('No plugins defined.'),
          'colspan' => count($header),
          'class' => array('add-tamper'),
        ),
      );
    }

    $add_link = drupal_render($form['tampers'][$target]['add_link']);
    $rows[] = array(
      'data' => array(array('data' => $add_link, 'colspan' => count($header))),
      'class' => array('capx-tamper-add'),
    );

    $output .= theme('table', array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(
        'id' => capx_tamper_table_id($target),
        'class' => array('feeds-tamper-table'),
      ),
      'caption' => $caption,
    ));

    drupal_add_tabledrag(capx_tamper_table_id($target), 'order', 'sibling', capx_tamper_table_id($target) . '-weight');
  }

  $output .= drupal_render_children($form);
  return $output;
}
