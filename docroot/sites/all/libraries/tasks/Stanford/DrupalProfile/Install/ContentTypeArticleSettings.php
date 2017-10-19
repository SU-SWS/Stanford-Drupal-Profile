<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;

class ContentTypeArticleSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Defaults for the Article content type
    variable_set('comment_anonymous_article', 0);
    variable_set('comment_default_mode_article', 1);
    variable_set('comment_default_per_article_article', '50');
    variable_set('comment_form_location_article', 1);
    variable_set('comment_article', '1');
    variable_set('comment_preview_article', '1');
    variable_set('comment_subject_field_article', 1);
    variable_set('node_preview_article', '1');
    variable_set('node_submitted_article', 0);
    variable_set('menu_parent_article', 'main-menu:0');
    $menu_options_article = array('main-menu');
    variable_set('menu_options_article', $menu_options_article);
    $node_options_article = array('status', 'promote', 'revision');
    variable_set('node_options_article', $node_options_article);
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
