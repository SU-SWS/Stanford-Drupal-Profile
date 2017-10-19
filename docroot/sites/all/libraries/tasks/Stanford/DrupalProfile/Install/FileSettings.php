<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;

class FileSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Set public directory.
    $public_directory = 'sites/default/files';
    variable_set('file_public_path', $public_directory);
    // Set default scheme to public file handling.
    variable_set('file_default_scheme', 'public');
    // system_check_directory() is expecting a $form_element array.
    $element = array();
    $element['#value'] = $public_directory;
    $element['#name'] = 'file_public_path';
    // Check that the public directory exists; create it if it does not.
    system_check_directory($element);

  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'file',
    );
  }

}
