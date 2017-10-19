<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
/**
 *
 */
class PathologicSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Set pathologic Base Paths.
    global $base_url;

    $local_paths = "";
    if (strpos("https://sites.stanford.edu", $base_url)) {
      $local_paths = str_replace('https://sites.stanford.edu', '', $base_url) . '/';
    }

    $settings = serialize(array(
      'local_paths' => $local_paths,
      'protocol_style' => 'full',
    ));

    db_merge('filter')
      ->key(array(
        'format' => 'content_editor_text_format',
        'name' => 'pathologic',
      ))
      ->fields(array(
        'settings' => $settings,
      ))
      ->execute();
  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'pathologic',
      'stanford_jumpstart_wysiwyg', // content editor format.
    );
  }

}




