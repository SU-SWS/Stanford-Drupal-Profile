<?php

//  ////////////////////////////////////////////////////////////////////////////
//  VIEWS PLUGINS //
//  ////////////////////////////////////////////////////////////////////////////

/**
 * Add active subsite plugin option for views default argument handlers.
 *
 * @return array
 *   An array of plugin information for use in views
 */
function stanford_subsites_views_plugins() {
  $plugins = array();
  $plugins['argument validator'] = array(
    'subsite' => array(
      'title' => t('Active Subsite'),
      'handler' => 'views_plugin_argument_validate_subsite',
    ),
  );

  $plugins['argument default'] = array(
    'subsite' => array(
      'title' => t('Active Subsite'),
      'handler' => 'views_plugin_argument_default_subsite',
    ),
  );

  return $plugins;
}
