<?php

/**
 * @file
 * Theme setting callbacks for the cube theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function cube_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['cube_width'] = array(
    '#type' => 'radios',
    '#title' => t('Content width'),
    '#options' => array(
      'fixed' => t('Fixed width'),
      'fluid' => t('Fluid width'),
    ),
    '#default_value' => (theme_get_setting('cube_width') ? theme_get_setting('cube_width') : 'fixed'),
    '#description' => t('Specify whether the content will wrap to a fixed width or will fluidly expand to the width of the browser window.'),
    // Place this above the color scheme options.
    '#weight' => -2,
  );
}
