<?php
/**
 * @file
 * Sets the 404 page path
 */

namespace Stanford\Jumpstart\Install\Content;
/**
 *
 */
class FourOFour extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    drupal_flush_all_caches();
    $four_oh_four = drupal_get_normal_path('404');
    variable_set('site_404', $four_oh_four);
  }

}
