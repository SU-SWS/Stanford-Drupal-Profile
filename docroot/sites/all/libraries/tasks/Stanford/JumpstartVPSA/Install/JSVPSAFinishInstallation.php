<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install;
/**
 *
 */
class JSVPSAFinishInstallation extends \ITasks\AbstractInstallTask {

  /**
   * Enable a couple of final modules because they depend on everything.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Set the homepage to the home node.
    $home_node_path = drupal_get_normal_path('home');
    variable_set('site_frontpage', $home_node_path);

    // Oh man so many static variables to kill!
    static $ordered;
    static $all_links;
    static $cache;
    static $drupal_static_cache;
    $ordered = null;
    $all_links = null;
    $cache = null;
    $drupal_static_cache = null;

    // Call flush all caches so that the blocks table gets populated.
    drupal_static_reset();
    drupal_flush_all_caches();

    // Small fix for a menu bug
    db_update('menu_links')
      ->fields(array(
        'router_path' => 'admin/manage'
      ))
      ->condition('link_path', 'admin/manage')
      ->execute();

    // Add some block titles.
    // module, delta, title
    $blocks = array(
      array('views', 'stanford_events_views-block_1',     'Upcoming Events'),
      array('views', '3b9ba5dd07e9aa559cbe7d1ced47f7b7',  'Announcements'),
    );
    foreach ($blocks as $index => $entry) {
      db_update('block')
        ->fields(array(
          'title' => $entry[2]
        ))
        ->condition('module', $entry[0])
        ->condition('delta', $entry[1])
        ->execute();
    }
  }

}
