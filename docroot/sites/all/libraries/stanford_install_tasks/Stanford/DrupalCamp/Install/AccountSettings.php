<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class AccountSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $this->addDefaultUserPicture();

    variable_set("user_cancel_method", "user_cancel_block");
    variable_set("user_email_verification", 0);
    variable_set("user_pictures", 1);
    variable_set("user_picture_default", "public://dries.png");
    variable_set("user_picture_dimensions", "1024x1024");
    variable_set("user_picture_file_size", "800");
    variable_set("user_picture_path", "pictures");
    variable_set("user_picture_style", "thumbnail");
    variable_set("user_register", 1);
    variable_set("user_signatures", 0);

  }

  /**
   * Adds the default user picture.
   */
  protected function addDefaultUserPicture() {
    // @todo: this thing.
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
