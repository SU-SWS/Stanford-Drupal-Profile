<?php

/**
 * @file
 * Definition of views_handler_field_configuration_metadata.
 */

use CAPx\Drupal\Util\CAPxMapper;

/**
 * Field handler to show data of serialized Importer metadata.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_configuration_metadata extends views_handler_field_serialized {

  function option_definition() {
    $options = parent::option_definition();
    $options['timestamp'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['format']['#options']['count'] = t('Number of profiles');
    $form['format']['#options']['lastUpdateHuman'] = t('Last update date');

    $form['timestamp'] = array(
      '#type' => 'checkbox',
      '#title' => t('Render as Unix timestamp'),
      '#default_value' => $this->options['timestamp'],
      '#dependency' => array('edit-options-format' => array('lastUpdateHuman')),
    );

  }

  function render($values) {

    switch ($this->options['format']) {
      case 'count':
        $value = $values->{$this->field_alias};
        $field_values = unserialize($value);
        return isset($field_values['count']) ? check_plain($field_values['count']) : NULL;
        break;

      case 'lastUpdateHuman':
        $value = $values->{$this->field_alias};
        $field_values = unserialize($value);
        $field_name = $this->options['timestamp'] ? 'lastUpdate' : 'lastUpdateHuman';
        return isset($field_values[$field_name]) ? check_plain($field_values[$field_name]) : NULL;
        break;
    }

    return parent::render($values);
  }
}
