<?php

/**
 * @file
 * Views Default Alters.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function capx_tamper_views_default_views_alter(&$views) {

  if (!isset($views['capx_mappers'])) {
    return;
  }

  // Add a tamper link to the mappers list view.
  $handler = &$views['capx_mappers']->display['default']->handler;

  /* Field: Configuration Entity: Manage Tampers link */
  $handler->display->display_options['fields']['tamper_link']['id'] = 'tamper_link';
  $handler->display->display_options['fields']['tamper_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['tamper_link']['field'] = 'tamper_link';
  $handler->display->display_options['fields']['tamper_link']['label'] = '';
  $handler->display->display_options['fields']['tamper_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tamper_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tamper_link']['text'] = 'Tampers';

  /* Field: Global: Custom text */
  $action_links = $handler->display->display_options['fields']['nothing_2'];
  unset($handler->display->display_options['fields']['nothing_2']);
  $action_links['alter']['text'] = trim($action_links['alter']['text']);
  $action_links['alter']['text'] .= ' | [tamper_link]';

  $handler->display->display_options['fields']['nothing_2'] = $action_links;
}
