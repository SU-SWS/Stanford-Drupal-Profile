<?php

/**
 * @file
 * Views integration for Workbench Access.
 *
 * Provides a reliable 'edit' link field for nodes.
 */

class workbench_access_handler_field_edit_node extends views_handler_field {
  // No query for this field.
  function query() {}

  /**
   * Render the link.
   */
  function render($values) {
    if (!isset($values->nid)) {
      return '';
    }
    $node = node_load($values->nid);
    if (!node_access('update', $node)) {
      return '';
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');
    return l($text, "node/$values->nid/edit", array('query' => drupal_get_destination()));
  }
}
