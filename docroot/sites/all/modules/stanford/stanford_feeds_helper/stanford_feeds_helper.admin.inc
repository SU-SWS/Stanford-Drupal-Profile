<?php
/**
 * @file
 * Configuration interface for stanford_feeds_helper.
 */

function stanford_feeds_helper_configure() {
  $form = array();

  $form['stanford_feeds_helper_prevent_duplicates'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent duplicate items.'),
    '#description' => t("Prevent duplicate items from being created across all feeds importers."),
    '#default_value' => variable_get("stanford_feeds_helper_prevent_duplicates", FALSE),
  );

  $form['stanford_feeds_helper_limit_field_collections'] = array(
    '#type' => 'textfield',
    '#title' => t('Field collection limit.'),
    '#description' => t("Set a limit to the number of field collections a single node can have created during import. Set to -1 for unlimited items."),
    '#default_value' => variable_get("stanford_feeds_helper_limit_field_collections", -1),
  );

  return system_settings_form($form);
}
