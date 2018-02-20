<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Menu;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class JSVPSAMenuItems extends AbstractInstallTask {

  /**
   * Create menu items.
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
    // News Landing.
    $items['news'] = array(
      'link_path' => drupal_get_normal_path('news'),
      'link_title' => 'Announcements & News',
      'menu_name' => 'main-menu',
      'weight' => -9,
    );
    // News / Announcements.
    $items['news/announcements'] = array(
      'link_path' => 'news/announcements',
      'link_title' => 'Announcements',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'router_path' => 'news/announcements',
      'parent' => 'news',
      'customized' => 1,
    );
    // News / Recent News.
    $items['news/in-the-news'] = array(
      'link_path' => 'news/in-the-news',
      'link_title' => 'In the News',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'router_path' => 'news/in-the-news',
      'parent' => 'news',
      'customized' => 1,
    );
    // Events Landing.
    $items['events'] = array(
      'link_path' => drupal_get_normal_path('events'),
      'link_title' => 'Events',
      'menu_name' => 'main-menu',
      'weight' => -8,
    );
    // Events / Upcoming.
    $items['events/upcoming-events'] = array(
      'link_path' => 'events/upcoming-events',
      'link_title' => 'Upcoming Events',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => 'events',
      'router_path' => 'events/upcoming-events',
      'customized' => 1,
    );
    // Events / Past.
    $items['events/past-events'] = array(
      'link_path' => 'events/past-events',
      'link_title' => 'Past Events',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'events',
      'router_path' => 'events/past-events',
      'customized' => 1,
    );
    // Events / Related.
    $items['events/related-events'] = array(
      'link_path' => 'events/related-events',
      'link_title' => 'Related Events',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'events',
      'router_path' => 'events/related-events',
      'customized' => 1,
    );
    // People.
    $items['people'] = array(
      'link_path' => 'people',
      'link_title' => 'People',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'router_path' => 'people',
      'customized' => 1,
    );
    // About.
    $items['about'] = array(
      'link_path' => drupal_get_normal_path('about'),
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'weight' => -5,
    );
    // About / Contact.
    $items['about/contact'] = array(
      'link_path' => drupal_get_normal_path('about/contact'),
      'link_title' => 'Contact',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'about', // must be saved prior to contact item.
    );
    // About / Accessibility.
    $items['about/web-accessibility'] = array(
      'link_path' => drupal_get_normal_path('about/web-accessibility'),
      'link_title' => 'Web Accessibility',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'parent' => 'about', // must be saved prior to web-access item.
    );
    // Programs.
    $items['programs'] = array(
      'link_path' => drupal_get_normal_path('programs'),
      'link_title' => 'Programs',
      'menu_name' => 'main-menu',
      'weight' => -5,
    );
    // PRIVATE PAGE MENU.
    // ------––----------
    $items['private'] = array(
      'link_path' => drupal_get_normal_path('private'),
      'link_title' => 'Private Pages',
      'menu_name' => 'menu-menu-private-pages',
      'weight' => -9,
    );
    // For Faculty.
    $items['private/for-faculty'] = array(
      'link_path' => drupal_get_normal_path('private/for-faculty'),
      'link_title' => 'For Faculty',
      'menu_name' => 'menu-menu-private-pages',
      'weight' => -7,
    );
    // For Faculty / Sub-page.
    $items['private/for-faculty/sub-page'] = array(
      'link_path' => drupal_get_normal_path('private/for-faculty/sub-page'),
      'link_title' => 'Faculty Sub-Page',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'private/for-faculty', // must be already saved.
    );
    // For Students.
    $items['private/for-students'] = array(
      'link_path' => drupal_get_normal_path('private/for-students'),
      'link_title' => 'For Students',
      'menu_name' => 'menu-menu-private-pages',
      'weight' => -5,
    );
    // For Staff.
    $items['private/for-staff'] = array(
      'link_path' => drupal_get_normal_path('private/for-staff'),
      'link_title' => 'For Staff',
      'menu_name' => 'menu-menu-private-pages',
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
    // The home link weight needs to change.
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
