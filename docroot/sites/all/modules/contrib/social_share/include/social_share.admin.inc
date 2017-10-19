<?php

/**
 * @file
 * Configuration options for Simple Share social network links.
 */

/**
 * Menu callback; Settings administration.
 */
function social_share_admin_settings() {
  $types = node_type_get_types();
  $form['#attached'] = array(
    'js' => array(
      'social-share-admin' => drupal_get_path('module', 'social_share') . '/js/social_share.admin.js',
    ),
  );

  $form['node_types'] = array(
    '#prefix' => '<label>' . t('Node types') . '</label>',
    '#suffix' => '<br />',
  );
  $available = social_share_available_networks();
  foreach ($types as $type) {
    $enabled_networks = variable_get('social_share_networks_' . $type->type, array());
    if (!empty($enabled_networks)) {
      foreach ($enabled_networks as &$network) {
        foreach ($available as $n) {
          if ($n['machine_name'] == $network) {
            $network = $n['human_name'];
            continue;
          }
        }
      }
      $networks = '<span id="social-share-enabled-' . $type->type . '-networks">' . implode(', ', $enabled_networks) . ' ' . format_plural(count($enabled_networks), '(1 social network)', '(@count social networks)') . '</span>';
    }
    else {
      $networks = '';
    }
    $form['node_types']['social_share_enabled_' . $type->type] = array(
      '#type' => 'checkbox',
      '#title' => $type->name . '<small> [' . l('edit', 'admin/structure/types/manage/' . $type->type, array('query' => array('destination' => 'admin/config/content/social-share'))) . '] ' . $networks . '</small>',
      '#default_value' => variable_get('social_share_enabled_' . $type->type, 0),
    );
  }

  $form['social_share_new_window'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open Links in new window'),
    '#description' => t('If enabled, the share links will open in a new window'),
    '#default_value' => variable_get('social_share_new_window', 0),
  );

  $form['social_share_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make links available as a block'),
    '#description' => t('If enabled, the share links will be available in a block called "Social Share"'),
    '#default_value' => variable_get('social_share_block', 0),
  );

  $form['social_share_twitter_truncate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Truncate titles when sharing to twitter'),
    '#description' => t('If enabled, node titles will be truncated if the URL being shared and the title exceed the twitter character limit of 140
       characters. <br /><strong>NOTE:</strong> Enabling this may cause issues with unicode text (Arabic, Kanji, etc)'),
    '#default_value' => variable_get('social_share_twitter_truncate', 0),
  );

  $form['social_share_max_desc_length'] = array(
    '#type' => 'textfield',
    '#maxlength' => 3,
    '#size' => 3,
    '#description' => t('Define the maximum description length passed through the link. Anything over 100 is excessive.'),
    '#title' => t('Maximum description length'),
    '#default_value' => variable_get('social_share_max_desc_length', 50),
  );

  $utm_settings = variable_get('social_share_utm_settings', array());
  $form['social_share']['social_share_utm_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('UTM-settings'),
    '#collapsible' => TRUE,
    '#collapsed' => ($utm_settings['social_share_append_utm'] && !empty($utm_settings['social_share_utm_campaign'])),
    '#tree' => TRUE,
  );

  $form['social_share']['social_share_utm_settings']['social_share_append_utm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append UTM-parameters to links'),
    '#description' => t('If checked, !utm_parameters will be added to the link that\'s shared.', array('!utm_parameters' => l('UTM-parameters', 'https://support.google.com/analytics/answer/1033867'))),
    '#default_value' => $utm_settings['social_share_append_utm'],
  );

  $form['social_share']['social_share_utm_settings']['social_share_utm_campaign'] = array(
    '#type' => 'textfield',
    '#title' => t('UTM campaign'),
    '#description' => t('The value for the UTM-campaign parameter'),
    '#default_value' => $utm_settings['social_share_utm_campaign'],
  );

  $site_languages = language_list();
  $default_language = language_default();
  $labels = variable_get('social_share_label', array($default_language->language => t('Share to')));
  if (count($site_languages) > 1) {
    $form['social_share_label'] = array(
      '#type' => 'fieldset',
      '#title' => t('Share label (by language)'),
      '#collapsible' => TRUE,
      '#collapsed' => (count($site_languages) > 3) ? TRUE : FALSE,
      '#tree' => TRUE,
    );
  }
  else {
    $form['social_share_label'] = array(
      '#type' => 'markup',
      '#tree' => TRUE,
    );
  }
  foreach ($site_languages as $lang_code => $lang) {
    if (count($site_languages) > 1) {
      if ($lang->name != $lang->native) {
        $lang_title = $lang->name . ' (' . $lang->native . ')';
      }
      else {
        $lang_title = $lang->name;
      }
    }
    else {
      $lang_title = t('Share label');
    }
    $form['social_share_label'][$lang_code] = array(
      '#type' => 'textfield',
      '#title' => $lang_title,
      '#default_value' => (isset($labels[$lang_code])) ? $labels[$lang_code] : '',
    );
  }

  return system_settings_form($form);
}
