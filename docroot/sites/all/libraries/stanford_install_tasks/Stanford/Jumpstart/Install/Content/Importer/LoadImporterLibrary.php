<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\Content\Importer;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class LoadImporterLibrary extends AbstractInstallTask {

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

    if (!is_file($library_path)) {
      throw new \Exception(t('Could not find the importer library in any of the library directories. Please ensure it is installed http://github.com/SU-SWS/stanford_sites_content_importer'));
    }

    include_once $library_path;

  }

}
