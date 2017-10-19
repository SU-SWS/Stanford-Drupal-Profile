<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install;
/**
 *
 */
class BlockClass extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $values = array(
      array("bean", "drupalcamp-propose-a-session-but", "well"),
    );

    foreach ($values as $k => $value) {
      // UPDATE block SET (module="bean",delta="social-media",css_class="span4") WHERE module="bean" AND delta="social-media"
      $update = db_update('block')->fields(array('css_class' => $value[2]));
      $update->condition('module',$value[0]);
      $update->condition('delta',$value[1]);
      $update->execute();
    }

  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'block_class',
    );
  }

}
