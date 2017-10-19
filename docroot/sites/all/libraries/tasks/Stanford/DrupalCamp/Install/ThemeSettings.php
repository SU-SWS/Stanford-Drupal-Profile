<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install;
/**
 *
 */
class ThemeSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $themes = array('stanford_framework');
    theme_enable($themes);
    variable_set('theme_default', 'stanford_framework');
    variable_set('node_admin_theme', 1);

    $settings = array(
      "toggle_logo" => 1,
      "toggle_name" => 1,
      "toggle_slogan" => 1,
      "toggle_node_user_picture" => 1,
      "toggle_comment_user_picture" => 1,
      "toggle_comment_user_verification" => 1,
      "toggle_favicon" => 1,
      "toggle_main_menu" => 1,
      "toggle_secondary_menu" => 0,
      "default_logo" => 1,
      "logo_path" => '',
      "logo_upload" => '',
      "default_favicon" => 1,
      "favicon_path" => '',
      "favicon_upload" => '',
      "content_order_classes" => '',
      "front_heading_classes" => '',
      "breadcrumb_classes" => '',
      "body_bg_classes" => '',
      "body_bg_path" => 'public://',
      "body_bg_upload" => '',
      "body_bg_type" => '',
      "border_classes" => '',
      "corner_classes" => '',
      "font_awesome_version" => 'font-awesome-3',
      "choosestyle_styleoptions" => 'style-custom',
      "logo_image_style_classes" => '',
      "site_title_first_line" => '',
      "site_title_second_line" => '',
      "site_title_style_classes" => '',
      "site_title_position_classes" => '',
      "styles" => 'styles-cardinal',
      "fonts" => 'fonts-sans',
      "header_bkg" => '',
      "header_bkg_path" => 'public://',
      "header_bkg_upload" => '',
      "header_bkg_style_front" => 0,
      "header_bkg_style" => 'header-bkg-image',
      "header_bkg_text" => 'header-bkg-text-light',
    );

    variable_set("theme_stanford_framework_settings", $settings);

  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      // 'stanford_framework',
    );
  }

}
