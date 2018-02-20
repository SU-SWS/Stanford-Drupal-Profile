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
class MenuSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $items = array();

    // Rebuild the menu cache before starting this.
    drupal_static_reset();
    menu_cache_clear_all();
    menu_rebuild();

    $items['about'] = array(
      'link_path' => drupal_get_normal_path('about/what-to-expect'),
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'expanded' => TRUE,
    );

    $items['about/what-to-expect'] = array(
      'link_path' => drupal_get_normal_path('about/what-to-expect'),
      'link_title' => 'What to expect',
      'menu_name' => 'main-menu',
      'parent' => 'about',
      'weight' => -9,
    );

    $items['about/organizing-committee'] = array(
      'link_path' => drupal_get_normal_path('about/organizing-committee'),
      'link_title' => 'Organizing Committee',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'about',
    );

    $items['about/food-drink'] = array(
      'link_path' => drupal_get_normal_path('about/food-drink'),
      'link_title' => 'Food & Drink',
      'menu_name' => 'main-menu',
      'weight' => -7,
      'parent' => 'about',
      'hidden' => 1,
    );

    $items['about/code-conduct'] = array(
      'link_path' => drupal_get_normal_path('about/code-conduct'),
      'link_title' => 'Code of Conduct',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'parent' => 'about',
    );

    $items['about/past-camps'] = array(
      'link_path' => drupal_get_normal_path('about/past-camps'),
      'link_title' => 'Past Camps',
      'menu_name' => 'main-menu',
      'weight' => 10,
      'parent' => "about",
    );

    // $items['news/recent-news'] = array(
    //   'link_path' => drupal_get_normal_path('news/recent-news'),
    //   'link_title' => 'Updates',
    //   'menu_name' => 'main-menu',
    //   'weight' => -7,
    //   'expanded' => TRUE,
    // );

    $items['community'] = array(
      'link_path' => drupal_get_normal_path('community'),
      'link_title' => 'Community',
      'menu_name' => 'main-menu',
      'weight' => -4,
      'expanded' => TRUE,
    );

    $items['sponsors'] = array(
      'link_path' => drupal_get_normal_path('sponsors'),
      'link_title' => 'Sponsors',
      'menu_name' => 'main-menu',
      'weight' => -4,
      'expanded' => TRUE,
    );

    $items['venue'] = array(
      'link_path' => drupal_get_normal_path('venue'),
      'link_title' => 'Location',
      'menu_name' => 'main-menu',
      'weight' => -4,
      'expanded' => TRUE,
    );

    $items['venue/location'] = array(
      'link_path' => drupal_get_normal_path('venue'),
      'link_title' => 'Venue',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => "venue",
    );

    $items['venue/getting-here'] = array(
      'link_path' => drupal_get_normal_path('venue/getting-here'),
      'link_title' => 'Getting Here',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => "venue",
    );

    $items['sessions/proposed'] = array(
      'link_path' => drupal_get_normal_path('sessions/proposed'),
      'link_title' => 'Proposed Sessions',
      'menu_name' => 'main-menu',
      'weight' => -3,
    );

    $items['schedule'] = array(
      'link_path' => drupal_get_normal_path('schedule/2016-04-01'),
      'link_title' => 'Schedule',
      'menu_name' => 'main-menu',
      'weight' => -3,
      'hidden' => 1,
    );

    $items['schedule/2016-04-01'] = array(
      'link_path' => drupal_get_normal_path('schedule/2016-04-01'),
      'link_title' => 'Friday Sessions',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => "schedule",
      'hidden' => 1,
    );

    $items['schedule/2016-04-02'] = array(
      'link_path' => drupal_get_normal_path('schedule/2016-04-02'),
      'link_title' => 'Saturday Sessions',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => "schedule",
      'hidden' => 1,
    );

    $items['schedule/mine'] = array(
      'link_path' => drupal_get_normal_path('schedule/mine'),
      'link_title' => 'My Schedule',
      'menu_name' => 'main-menu',
      'weight' => -7,
      'parent' => "schedule",
      'hidden' => 1,
    );

    $items['stanford-jobs'] = array(
      'link_path' => drupal_get_normal_path('stanford-jobs'),
      'link_title' => 'Stanford Jobs',
      'menu_name' => 'main-menu',
      'weight' => -3,
    );

    // Loop through each of the items and save them.
    foreach ($items as $k => $v) {

      // Check to see if there is a parent declaration. If there is then find
      // the mlid of the parent item and attach it to the menu item being saved.
      if (isset($v['parent'])) {
        $v['plid'] = $items[$v['parent']]['mlid'];
        unset($v['parent']); // Remove fluff before save.
      }

      // Save the menu item.
      $mlid = menu_link_save($v);
      $v['mlid'] = $mlid;
      $items[$k] = $v;
    }

    // The home link weight needs to change so that it is in front..
    $home_search = db_select('menu_links', 'ml')
      ->fields('ml', array('mlid'))
      ->condition('menu_name', 'main-menu')
      ->condition('link_path', '<front>')
      ->condition('link_title', 'Home')
      ->execute()
      ->fetchAssoc();

    if (is_numeric($home_search['mlid'])) {
      $menu_link = menu_link_load($home_search['mlid']);
      $menu_link['weight'] = -50;
      menu_link_save($menu_link);
    }

  }

}
