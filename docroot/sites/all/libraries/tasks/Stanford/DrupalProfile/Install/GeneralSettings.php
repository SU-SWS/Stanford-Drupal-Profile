<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;

class GeneralSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Disable poormanscron functionality, as we are running cron externally.
    variable_set('cron_safe_threshold', 0);

    // Set OpenLayers library to use external https CDN.
    variable_set('openlayers_source_external', 'https://cdnjs.cloudflare.com/ajax/libs/openlayers/2.13.1/OpenLayers.js');
    variable_set('openlayers_source_type', 'external');

    // Set Pathauto to reduce paths to numbers and letters.
    variable_set('pathauto_reduce_ascii', 1);
    // Make the default pathauto setting be [node:title].
    $pathauto_node_pattern = '[node:title]';
    variable_set('pathauto_node_pattern', $pathauto_node_pattern);

    // Set errors only to go to the log.
    variable_set('error_level', 0);

    // Make the Seven admin theme use our favicon.
    $theme_seven_settings = array(
      'toggle_logo' => 1,
      'toggle_name' => 1,
      'toggle_slogan' => 1,
      'toggle_node_user_picture' => 1,
      'toggle_comment_user_picture' => 1,
      'toggle_comment_user_verification' => 1,
      'toggle_favicon' => 1,
      'toggle_main_menu' => 1,
      'toggle_secondary_menu' => 1,
      'default_logo' => 1,
      'logo_path' => '',
      'logo_upload' => '',
      'default_favicon' => 0,
      'favicon_path' => dirname(__FILE__) . '/resources/favicon.ico',
      'favicon_upload' => '',
      'favicon_mimetype' => 'image/vnd.microsoft.icon',
    );

    variable_set('theme_seven_settings', $theme_seven_settings);

  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      //'openlayers', // We set the variable to point to an external CDN for the OpenLayers library, but don't want to enable by default.
      'pathauto',
      'node',
    );
  }

}
