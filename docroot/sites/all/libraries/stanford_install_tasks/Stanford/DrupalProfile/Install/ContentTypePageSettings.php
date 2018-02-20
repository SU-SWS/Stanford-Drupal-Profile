<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;
use \ITasks\AbstractInstallTask;

class ContentTypePageSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Defaults for the Page content type
    variable_set('comment_anonymous_page', 0);
    variable_set('comment_default_mode_page', 1);
    variable_set('comment_default_per_page_page', '50');
    variable_set('comment_form_location_page', 1);
    variable_set('comment_page', '1');
    variable_set('comment_preview_page', '1');
    variable_set('comment_subject_field_page', 1);
    variable_set('node_preview_page', '1');
    variable_set('node_submitted_page', 0);
    variable_set('menu_parent_page', 'main-menu:0');
    $menu_options_page = array('main-menu');
    variable_set('menu_options_page', $menu_options_page);
    $node_options_page = array('status', 'promote', 'revision');
    variable_set('node_options_page', $node_options_page);
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'node',
      'menu',
    );
  }

}
