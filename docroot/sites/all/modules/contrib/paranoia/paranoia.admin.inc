<?php

/**
 * @file
 * Defines administration form for Paranoia module.
 */

/**
 * Administration form.
 */
function paranoia_admin_form() {
  $form = array();

  $form['paranoia_access_threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('User access threshold (in days)'),
    '#default_value' => variable_get('paranoia_access_threshold', 730),
    '#description' => t('Accounts that go unaccessed for more than this number
    of days can have their passwords randomized using the "drush
    paranoia-reset-stale-accounts" command.'),
  );
  $form['paranoia_email_notification'] = array(
    '#type' => 'checkbox',
    '#title' => t('Email affected users'),
    '#default_value' => variable_get('paranoia_email_notification', FALSE),
    '#description' => t('Check this box to notify users by email when their
    account passwords have been randomized.'),
  );

  return system_settings_form($form);
}
