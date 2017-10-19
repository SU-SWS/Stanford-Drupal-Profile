<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalProfile\Install\StanfordSites;
class ThemeSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Departments' preferred theme is Stanford Wilbur.
    // Groups' and individuals' preferred theme is Open Framework.
    // Official groups can have the Stanford Wilbur theme enabled by ITS.
    $org_type = variable_get('stanford_sites_org_type');
    if ($org_type == 'dept') {
      $preferred_themes = array(
        'theme_default' => 'stanford_wilbur',
        'admin_theme' => 'seven',
        'node_admin_theme' => 1,
        'open_framework' => NULL,
        'stanford_framework' => NULL,
        'stanford_jordan' => NULL,
      );
      theme_enable($preferred_themes);
      foreach ($preferred_themes as $var => $theme) {
        if (!is_numeric($var)) {
          variable_set($var, $theme);
        }
      }
    }
    else {
      $preferred_themes = array(
        'theme_default' => 'stanford_light',
        'admin_theme' => 'seven',
        'node_admin_theme' => 1,
        'open_framework' => NULL,
      );
      theme_enable($preferred_themes);
      foreach ($preferred_themes as $var => $theme) {
        if (!is_numeric($var)) {
          variable_set($var, $theme);
        }
      }
    }
  }

}
