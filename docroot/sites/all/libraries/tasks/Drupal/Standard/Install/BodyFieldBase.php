<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;

class BodyFieldBase extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Adds default body field to node types.

    $field = field_info_field('body');
    if (empty($field)) {
      $field = array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'entity_types' => array('node'),
      );
      $field = field_create_field($field);
    }
  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'field',
    );
  }

}
