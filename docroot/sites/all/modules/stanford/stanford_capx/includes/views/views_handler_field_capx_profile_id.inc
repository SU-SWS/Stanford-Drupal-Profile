<?php

/**
 * @file
 * Definition of stanford_capx_handler_field_configuration_settings.
 */

use CAPx\Drupal\Util\CAPxMapper;

/**
 * Field handler to create a link to CAP profiles.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_capx_profile_id extends views_handler_field_numeric {

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    $options['link_to_cap'] = array('default' => 0);
    return $options;
  }

  function options_form(&$form, &$form_state) {

    // Get the regular number options.
    parent::options_form($form, $form_state);

    // Add a link to cap.
    $form['link_to_cap'] = array(
      '#type' => 'checkbox',
      '#title' => t("Link to CAP website profile"),
      '#description' => t("Create a link to the CAP website public profile."),
      '#weight' => -100,
      '#default_value' => $this->options['link_to_cap'],
    );

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
      '#dependency' => array('edit-options-link-to-cap' => array(1)),
      '#weight' => -99,
    );

    // Adjust the weights of the regular form.
    $form['separator']['#dependency'] = array('edit-options-link-to-cap' => array(0));
    $form['format_plural']['#dependency'] = array('edit-options-link-to-cap' => array(0));
    $form['format_plural_singular']['#dependency'] = array('edit-options-link-to-cap' => array(0));
    $form['format_plural_plural']['#dependency'] = array('edit-options-link-to-cap' => array(0));
    $form['prefix']['#dependency'] = array('edit-options-link-to-cap' => array(0));
    $form['suffix']['#dependency'] = array('edit-options-link-to-cap' => array(0));

  }

  function render($values) {

    if ($this->options['link_to_cap']) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "https://profiles.stanford.edu/" . $values->capx_profiles_profile_id;
      $text = !empty($this->options['text']) ? $this->options['text'] : t('View on CAP');
    }
    else  {
      $text = $values->capx_profiles_profile_id;
    }

    return $text;

  }



}
