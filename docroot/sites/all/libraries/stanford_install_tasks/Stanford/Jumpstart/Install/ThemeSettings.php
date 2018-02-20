<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class ThemeSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Enable themes.
    $themes = array('stanford_framework', 'stanford_seven', 'open_framework');
    theme_enable($themes);

    variable_set('theme_default', 'stanford_framework');
    variable_set('admin_theme', 'stanford_seven');
    variable_set('node_admin_theme', 1);

     // Set the default theme options.
    $theme_settings = variable_get('theme_stanford_framework_settings', array());
    $theme_settings['choosestyle_styleoptions'] = 'style-custom';
    $theme_settings['fonts'] = 'fonts-sans';
    $theme_settings['styles'] = 'styles-light';
    variable_set('theme_stanford_framework_settings', $theme_settings);

  }

}
