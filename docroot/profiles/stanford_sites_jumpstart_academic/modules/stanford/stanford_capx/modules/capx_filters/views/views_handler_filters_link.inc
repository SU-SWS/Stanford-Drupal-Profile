<?php

/**
 * @file
 * Definition of views_handler_filters_link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class views_handler_filters_link extends views_handler_field_entity {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
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
   * {@inheritdoc}
   */
  public function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity);
    }
  }

  /**
   * Render a link to the importer filters page.
   *
   * @param object $importer
   *   The importer object.
   *
   * @return string
   *   The url to the filters edit page.
   */
  public function render_link($importer) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/config/capx/importer/" . $importer->getMachineName() . '/filters';
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Filters');
    return $text;
  }

}
