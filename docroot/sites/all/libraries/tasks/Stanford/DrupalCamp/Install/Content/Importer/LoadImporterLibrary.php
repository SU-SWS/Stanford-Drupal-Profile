<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install\Content\Importer;
/**
 *
 */
class LoadImporterLibrary extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Try to use libraries module if available to find the path.
    if (function_exists('libraries_get_path')) {
      $library_path = DRUPAL_ROOT . '/' . libraries_get_path('stanford_sites_content_importer');
    }
    if (!file_exists($library_path . '/SitesContentImporter.php')) {
      $library_path = DRUPAL_ROOT . '/sites/all/libraries/stanford_sites_content_importer';
    }
    if (!file_exists($library_path . '/SitesContentImporter.php')) {
      $library_path = DRUPAL_ROOT . '/sites/default/libraries/stanford_sites_content_importer';
    }
    $library_path .= "/SitesContentImporter.php";
    include_once $library_path;

  }

}







