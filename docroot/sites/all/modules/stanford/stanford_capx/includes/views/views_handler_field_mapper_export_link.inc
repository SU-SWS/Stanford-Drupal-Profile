<?php

/**
 * @file
 * Definition of views_handler_field_node_link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_mapper_export_link extends views_handler_field_entity {

  /**
   * Restrict access to this file to advanced users only.
   * @return bool
   */
  function access() {
    return user_access('capx advanced administrator');
  }

  /**
   * @return array
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  /**
   * @param $values
   * @return null|string
   */
  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity);
    }
  }

  /**
   * @param $mapper
   * @return null|string
   */
  function render_link($mapper) {

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/config/capx/preset/export/mapper/" . $mapper->getMachineName();
    $this->options['alter']['query'] = drupal_get_destination();
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Export');
    return $text;
  }
}
