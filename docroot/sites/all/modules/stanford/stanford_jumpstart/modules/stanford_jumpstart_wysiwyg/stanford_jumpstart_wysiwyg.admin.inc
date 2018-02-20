<?php

/**
 * @file
 * stanford_jumpstart_wysiwyg.admin.inc
 */

/**
 * Configuration form for the responsive tables.
 */
function stanford_jumpstart_wysiwyg_responsive_table_config($form, &$form_state) {
  $form = array();

  drupal_set_title(t('Responsive Tables'));
  $form['help'] = array(
    '#markup' => t('Configure the settings for the responsive tables. A demo can be seen on the !link page.', array('!link' => l(t('TableSaw Demo'), 'http://filamentgroup.github.io/tablesaw/demo/modeswitch.html'))),
  );

  $form['default_mode'] = array(
    '#type' => 'select',
    '#title' => t('Default Responsive Mode'),
    '#options' => array(
      0 => t('None'),
      'stack' => t('Stack'),
      'swipe' => t('Swipe'),
      'toggle' => t('Toggle'),
    ),
    '#default_value' => variable_get('stanford_jumpstart_wysiwyg_tables_default', 0),
  );

  $form['visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Add responsive tables to specific pages'),
    '#options' => array(
      t('Every page except the listed pages'),
      t('The listed pages only'),
    ),
    '#default_value' => variable_get('stanford_jumpstart_wysiwyg_tables_visibility', 0),
  );

  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array(
    '%blog' => 'blog',
    '%blog-wildcard' => 'blog/*',
    '%front' => '<front>',
  ));

  $form['pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#description' => $description,
    '#title_display' => 'invisible',
    '#default_value' => variable_get('stanford_jumpstart_wysiwyg_tables_pages', STANFORD_JUMPSTART_WYSIWYG_PATHS),
    '#rows' => 10,
  );

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  return $form;
}

/**
 * Responsive table configuration submit.
 */
function stanford_jumpstart_wysiwyg_responsive_table_config_submit($form, &$form_state) {
  variable_set('stanford_jumpstart_wysiwyg_tables_default', $form_state['values']['default_mode']);
  variable_set('stanford_jumpstart_wysiwyg_tables_visibility', $form_state['values']['visibility']);
  variable_set('stanford_jumpstart_wysiwyg_tables_pages', $form_state['values']['pages']);
}
