<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
/**
 *
 */
class GeneralSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Turn views into more developer like.
    // This function is only available through drush...
    if (function_exists("views_development_settings")) {
      views_development_settings();
    }
    else {
      $this->viewsDevelopmentSettings();
    }

    // Unset user menu as secondary links.
    variable_set('menu_secondary_links_source', "");

  }

  /**
   * Patch function for when installing through the UI.
   * Pretty much a carbon copy of views_development_settings();
   */
  private function viewsDevelopmentSettings() {
    variable_set('views_ui_show_listing_filters', TRUE);
    variable_set('views_ui_show_master_display', TRUE);
    variable_set('views_ui_show_advanced_column', TRUE);
    variable_set('views_ui_always_live_preview', FALSE);
    variable_set('views_ui_always_live_preview_button', TRUE);
    variable_set('views_ui_show_preview_information', TRUE);
    variable_set('views_ui_show_sql_query', TRUE);
    variable_set('views_ui_show_performance_statistics', TRUE);
    variable_set('views_show_additional_queries', TRUE);
    variable_set('views_devel_output', TRUE);
    variable_set('views_devel_region', 'message');
    variable_set('views_ui_display_embed', TRUE);
  }

}


