<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Content;
/**
 *
 */
class FixAliases extends \ITasks\AbstractInstallTask {


  /**
   * The aliases from the content server don't always match what we want. This
   * function will change those.
   *
   *   @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Existing URL alias => new alias.
    $map = array(
      'news/announcements'      => 'news',
      'events/upcoming-events'  => 'events',
      'about/about-us-0'        => 'about',
    );
    // Update alias table.
    foreach ($map as $existing => $new) {
      db_update('url_alias')
        ->fields(
          array('alias' => $new)
        )
        ->condition('alias', $existing)
        ->execute();
    }
  }

}







