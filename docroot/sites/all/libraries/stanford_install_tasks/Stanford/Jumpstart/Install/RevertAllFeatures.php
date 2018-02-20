<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\Jumpstart\Install;
use \ITasks\AbstractInstallTask;

class RevertAllFeatures extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Kill all static vars.
    drupal_static_reset();

    // If features are around lets rebuild them to be sure they
    // are as they should be.
    features_rebuild();
    features_revert();

    // Flush all caches.
    drupal_flush_all_caches();

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'features',
    );
  }

}
