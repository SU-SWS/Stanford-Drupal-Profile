<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;

class ImageFieldBase extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Create an image field named "Image",
    // Many of the following values will be defaulted, they're included here as an illustrative examples.
    // See http://api.drupal.org/api/function/field_create_field/7

    $field = array(
      'field_name' => 'field_image',
      'type' => 'image',
      'cardinality' => 1,
      'locked' => FALSE,
      'indexes' => array('fid' => array('fid')),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    );
    field_create_field($field);
  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'image',
      'file',
      'field',
    );
  }

}




















