<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;

class UserConfig extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Enable user picture support and set the default to a square thumbnail option.
    variable_set('user_pictures', '1');
    variable_set('user_picture_dimensions', '1024x1024');
    variable_set('user_picture_file_size', '800');
    variable_set('user_picture_style', 'thumbnail');

    // Allow visitor account creation with administrative approval.
    variable_set('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL);
  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}



