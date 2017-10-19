<?php

/**
 * @file
 * Views Default Alters.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function capx_filters_views_default_views_alter(&$views) {

  // Only alter the importers view.
  if (!isset($views['capx_importers'])) {
    return;
  }

  // Add the filters link field to the view and patch it in to the global
  // re-write field so that the view has the filters link on it.
  // Fetch the handler.
  $handler = &$views['capx_importers']->display['default']->handler;

  /* Field: Configuration Entity: Manage Tampers link */
  $handler->display->display_options['fields']['filters_link']['id'] = 'filters_link';
  $handler->display->display_options['fields']['filters_link']['table'] = 'capx_cfe';
  $handler->display->display_options['fields']['filters_link']['field'] = 'filters_link';
  $handler->display->display_options['fields']['filters_link']['label'] = '';
  $handler->display->display_options['fields']['filters_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filters_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filters_link']['text'] = 'Filters';

  /* Field: Global: Custom text */
  $action_links = $handler->display->display_options['fields']['nothing_2'];
  unset($handler->display->display_options['fields']['nothing_2']);
  $action_links['alter']['text'] = trim($action_links['alter']['text']);
  $action_links['alter']['text'] .= ' | [filters_link]';

  // Put it back in.
  $handler->display->display_options['fields']['nothing_2'] = $action_links;
}
