<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;

class DateTimeSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Disable user-configurable timezones by default.
    variable_set('configurable_timezones', 0);
    // Set the first day of the week to Sunday.
    variable_set('date_first_day', 0);
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'system',
    );
  }

}
