<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\Anchorage\Install;
/**
 *
 */
class S3FSFileSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    variable_set('s3fs_use_s3_for_public', 1);
    variable_set('s3fs_use_s3_for_private', 1);
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      's3fs',
      'stanford_s3fs_if'
    );
  }

}



