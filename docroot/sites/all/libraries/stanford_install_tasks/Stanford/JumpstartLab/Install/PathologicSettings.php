<?php

namespace Stanford\JumpstartLab\Install;

use ITasks\AbstractInstallTask;

/**
 * Class LabsPathologicSettings.
 *
 * @package Stanford\JumpstartLab\Install.
 */
class PathologicSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $paths = array(
      'https://sites.stanford.edu/jsa-content/',
      '/jsa-content',
    );
    foreach (filter_formats() as $key => $format) {
      $local_paths = array();
      $settings = db_select('filter', 'f')
        ->fields('f', array('settings'))
        ->condition('format', $key)
        ->condition('name', 'pathologic')
        ->execute()->fetchField();
      if ($settings) {
        $settings = unserialize($settings);
        $local_paths = explode("\n", $settings['local_paths']);
        db_delete('filter')
          ->condition('format', $key)
          ->condition('name', 'pathologic')
          ->execute();
      }

      foreach ($paths as $path) {
        if (!in_array($path, $local_paths)) {
          $local_paths[] = $path;
        }
      }

      $settings['local_paths'] = implode("\n", $local_paths);
      $row = array(
        'format' => $key,
        'module' => 'pathologic',
        'name' => 'pathologic',
        'weight' => 99,
        'status' => 1,
        'settings' => serialize($settings),
      );
      db_insert('filter')
        ->fields($row)
        ->execute();
    }
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
