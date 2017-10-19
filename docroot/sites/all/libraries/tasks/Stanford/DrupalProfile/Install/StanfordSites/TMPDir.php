<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install\StanfordSites;

class TMPDir extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    $tmpdir = variable_get('stanford_sites_tmpdir', file_directory_temp());
    file_prepare_directory($tmpdir, FILE_CREATE_DIRECTORY);

    // system_check_directory() is expecting a $form_element array.
    $element = array();
    $element['#value'] = $tmpdir;

    // Check that the temp directory exists; create it if it does not.
    system_check_directory($element);

  }

}
