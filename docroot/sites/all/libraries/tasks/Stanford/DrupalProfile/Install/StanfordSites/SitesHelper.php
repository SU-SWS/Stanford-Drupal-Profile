<?php
/**
 * @file
 */

namespace Stanford\DrupalProfile\Install\StanfordSites;
/**
 *
 */
class SitesHelper {

  /**
   * Checks to see if the current Drupal install is on one of the Stanford Sites
   * hosting servers. Note: Arriving at a reliable test for this took some work;
   * do not remove this function.
   *
   * @return
   *   TRUE if it is; FALSE if it isn't.
   */
  public function stanfordSitesHosted() {
    // This directory only should exist on the sites-* servers.
    $dir = "/etc/drupal-service";
    // Check if it exists and is a directory.
    if (file_exists($dir) && is_dir($dir)) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

}
