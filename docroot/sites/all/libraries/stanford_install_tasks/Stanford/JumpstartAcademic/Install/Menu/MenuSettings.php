<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartAcademic\Install\Menu;
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

    /////////////////////////////////////////////////////////////////////////////
    // Jumpstart Academic Main Menus
    /////////////////////////////////////////////////////////////////////////////

    // Academics.
    $main_menu['academics'] = array(
      'link_path' => drupal_get_normal_path('academics'),
      'link_title' => 'Academics',
      'menu_name' => 'main-menu',
      'weight' => -48,
    );
    // Academics Overview.
    $main_menu['academics/academics-overview'] = array(
      'link_path' => drupal_get_normal_path('academics/academics-overview'),
      'link_title' => 'Overview',
      'menu_name' => 'main-menu',
      'weight' => -50,
      'parent' => 'academics',
    );
    // Undergraduate Program.
    $main_menu['academics/undergraduate-program'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program'),
      'link_title' => 'Undergraduate Program',
      'menu_name' => 'main-menu',
      'weight' => -48,
      'parent' => 'academics',
    );
    // Major.
    $main_menu['academics/undergraduate-program/major'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/major'),
      'link_title' => 'Major',
      'menu_name' => 'main-menu',
      'weight' => -48,
      'parent' => 'academics/undergraduate-program',
    );
    // Minor.
    $main_menu['academics/undergraduate-program/minor'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/minor'),
      'link_title' => 'Minor',
      'menu_name' => 'main-menu',
      'weight' => -46,
      'parent' => 'academics/undergraduate-program',
    );
    // Honors.
    $main_menu['academics/undergraduate-program/honors'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/honors'),
      'link_title' => 'Honors',
      'menu_name' => 'main-menu',
      'weight' => -44,
      'parent' => 'academics/undergraduate-program',
    );
    // Coterminal Masters.
    $main_menu['academics/undergraduate-program/coterminal-masters'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/coterminal-masters'),
      'link_title' => 'Coterminal Masters',
      'menu_name' => 'main-menu',
      'weight' => -42,
      'parent' => 'academics/undergraduate-program',
    );
    // How to Declare.
    $main_menu['academics/undergraduate-program/how-declare'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/how-declare'),
      'link_title' => 'How to Declare',
      'menu_name' => 'main-menu',
      'weight' => -40,
      'parent' => 'academics/undergraduate-program',
    );
    // Preparing to Graduate.
    $main_menu['academics/undergraduate-program/preparing-graduate'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/preparing-graduate'),
      'link_title' => 'Preparing to Graduate',
      'menu_name' => 'main-menu',
      'weight' => -38,
      'parent' => 'academics/undergraduate-program',
    );
    // Peer Advisors.
    $main_menu['academics/undergraduate-program/peer-advisors'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/peer-advisors'),
      'link_title' => 'Peer Advisors',
      'menu_name' => 'main-menu',
      'weight' => -36,
      'parent' => 'academics/undergraduate-program',
    );
    // Forms.
    $main_menu['academics/undergraduate-program/forms'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/forms'),
      'link_title' => 'Forms',
      'menu_name' => 'main-menu',
      'weight' => -34,
      'parent' => 'academics/undergraduate-program',
    );
    // Resources.
   $main_menu['academics/undergraduate-program/resources'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program/resources'),
      'link_title' => 'Resources',
      'menu_name' => 'main-menu',
      'weight' => -32,
      'parent' => 'academics/undergraduate-program',
    );
    // Graduate Programs.
    $main_menu['academics/graduate-programs'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs'),
      'link_title' => 'Graduate Programs',
      'menu_name' => 'main-menu',
      'weight' => -46,
      'parent' => 'academics',
    );
    // Doctoral Program.
    $main_menu['academics/graduate-programs/doctoral-program'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/doctoral-program'),
      'link_title' => 'Doctoral Program',
      'menu_name' => 'main-menu',
      'weight' => -50,
      'parent' => 'academics/graduate-programs',
    );
    // Requirements.
    $main_menu['academics/graduate-programs/doctoral-program/requirements'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/doctoral-program/requirements'),
      'link_title' => 'Requirements',
      'menu_name' => 'main-menu',
      'weight' => -50,
      'parent' => 'academics/graduate-programs/doctoral-program',
    );
    // How to Apply.
    $main_menu['academics/graduate-programs/doctoral-program/how-apply'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/doctoral-program/how-apply'),
      'link_title' => 'How to Apply',
      'menu_name' => 'main-menu',
      'weight' => -48,
      'parent' => 'academics/graduate-programs/doctoral-program',
    );
    // Masters Program.
    $main_menu['academics/graduate-programs/masters-program'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/masters-program'),
      'link_title' => 'Masters Program',
      'menu_name' => 'main-menu',
      'weight' => -48,
      'parent' => 'academics/graduate-programs',
    );
    // Requirements.
    $main_menu['academics/graduate-programs/masters-program/requirements'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/masters-program/requirements'),
      'link_title' => 'Requirements',
      'menu_name' => 'main-menu',
      'weight' => -50,
      'parent' => 'academics/graduate-programs/masters-program',
    );
    // How to Apply.
    $main_menu['academics/graduate-programs/masters-program/how-apply'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/masters-program/how-apply'),
      'link_title' => 'How to Apply',
      'menu_name' => 'main-menu',
      'weight' => -48,
      'parent' => 'academics/graduate-programs/masters-program',
    );

    // Graduate Admissions.
    $main_menu['academics/graduate-programs/graduate-admissions'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/graduate-admissions'),
      'link_title' => 'Graduate Admissions',
      'menu_name' => 'main-menu',
      'weight' => -46,
      'parent' => 'academics/graduate-programs',
    );
    // Forms.
    $main_menu['academics/graduate-programs/forms'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/forms'),
      'link_title' => 'Forms',
      'menu_name' => 'main-menu',
      'weight' => -44,
      'parent' => 'academics/graduate-programs',
    );
    // Resources.
    $main_menu['academics/graduate-programs/resources'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/resources'),
      'link_title' => 'Resources',
      'menu_name' => 'main-menu',
      'weight' => -42,
      'parent' => 'academics/graduate-programs',
    );
    // Job Placement.
    $main_menu['academics/graduate-programs/job-placement'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs/job-placement'),
      'link_title' => 'Job Placement',
      'menu_name' => 'main-menu',
      'weight' => -40,
      'parent' => 'academics/graduate-programs',
    );
    // Courses.
    $main_menu['courses'] = array(
      'link_path' => drupal_get_normal_path('courses'),
      'link_title' => 'Courses',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'customized' => 1,
    );
    // People.
    $main_menu['people'] = array(
      'link_path' => drupal_get_normal_path('people'),
      'link_title' => 'People',
      'menu_name' => 'main-menu',
      'weight' => -7,
    );
    // Faculty.
    $main_menu['people/faculty'] = array(
      'link_path' => drupal_get_normal_path('people/faculty'),
      'link_title' => 'Faculty',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'customized' => 1,
      'parent' => 'people',
    );
    // Faculty.
    $main_menu['people/students'] = array(
      'link_path' => drupal_get_normal_path('people/students'),
      'link_title' => 'Students',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'customized' => 1,
      'parent' => 'people',
    );
    // Staff.
    $main_menu['people/staff'] = array(
      'link_path' => drupal_get_normal_path('people/staff'),
      'link_title' => 'Staff',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'people',
    );
    // Publications.
    $main_menu['publications'] = array(
      'link_path' => drupal_get_normal_path('publications'),
      'link_title' => 'Publications',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
    );
    // News Landing.
    $main_menu['news'] = array(
      'link_path' => drupal_get_normal_path('news'),
      'link_title' => 'News',
      'menu_name' => 'main-menu',
      'weight' => -5,
    );
    // News / Recent News.
    $main_menu['news/recent-news'] = array(
      'link_path' => 'news/recent-news',
      'link_title' => 'Recent News',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'news',
      'customized' => 1,
    );
    // News / Department Newsletter.
    $main_menu['news/department-newsletter'] = array(
      'link_path' => drupal_get_normal_path('news/department-newsletter'),
      'link_title' => 'Newsletter',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'news',
    );
    // News / subscribe.
    $main_menu['news/subscribe'] = array(
      'link_path' => drupal_get_normal_path('news/subscribe'),
      'link_title' => 'Subscribe',
      'menu_name' => 'main-menu',
      'weight' => -7,
      'parent' => 'news',
    );
    // Events Landing.
    $main_menu['events'] = array(
      'link_path' => drupal_get_normal_path('events'),
      'link_title' => 'Events',
      'menu_name' => 'main-menu',
      'weight' => -4,
    );
    // Events / Upcoming.
    $main_menu['events/upcoming-events'] = array(
      'link_path' => drupal_get_normal_path('events/upcoming-events'),
      'link_title' => 'Upcoming Events',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => 'events',
      'router_path' => 'events/upcoming-events',
      'customized' => 1,
    );
    // Events / Past.
    $main_menu['events/past-events'] = array(
      'link_path' => drupal_get_normal_path('events/past-events'),
      'link_title' => 'Past Events',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'events',
      'router_path' => 'events/past-events',
      'customized' => 1,
    );
    // About.
    $main_menu['about'] = array(
      'link_path' => drupal_get_normal_path('about'),
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'weight' => -3,
    );
    // About / Overview.
    $main_menu['about/overview'] = array(
      'link_path' => drupal_get_normal_path('about/about-us'),
      'link_title' => 'Overview',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => 'about', // must be saved prior to overview item.
    );
    // About / location.
    $main_menu['about/location'] = array(
      'link_path' => drupal_get_normal_path('about/location'),
      'link_title' => 'Location',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'about', // must be saved prior to contact item.
    );
    // About / Contact.
    $main_menu['about/contact'] = array(
      'link_path' => drupal_get_normal_path('about/contact'),
      'link_title' => 'Contact',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'parent' => 'about', // must be saved prior to web-access item.
    );
    // About / affiliated-programs.
    $main_menu['about/affiliated-programs'] = array(
      'link_path' => drupal_get_normal_path('about/affiliated-programs'),
      'link_title' => 'Affiliated Programs',
      'menu_name' => 'main-menu',
      'weight' => -4,
      'parent' => 'about', // must be saved prior to contact item.
    );
    // About / Make a Gift.
    $main_menu['about/giving'] = array(
      'link_path' => drupal_get_normal_path('about/giving'),
      'link_title' => 'Make A Gift',
      'menu_name' => 'main-menu',
      'weight' => -2,
      'parent' => 'about', // must be saved prior to web-access item.
    );

    /////////////////////////////////////////////////////////////////////////////
    // Footer Menus
    /////////////////////////////////////////////////////////////////////////////

    // About.
    $footer_about['about'] = array(
      'link_path' => drupal_get_normal_path('about'),
      'link_title' => 'About Us',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -50,
    );
    // Affiliated Programs.
    $footer_about['about/affiliated-programs'] = array(
      'link_path' => drupal_get_normal_path('about/affiliated-programs'),
      'link_title' => 'Affiliated Programs',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -48,
    );
    // Location.
    $footer_about['about/location'] = array(
      'link_path' => drupal_get_normal_path('about/location'),
      'link_title' => 'Location',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -46,
    );
    // Contact.
    $footer_about['about/contact'] = array(
      'link_path' => drupal_get_normal_path('about/contact'),
      'link_title' => 'Contact',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -44,
    );
    // Make a Gift.
    $footer_about['about/giving'] = array(
      'link_path' => drupal_get_normal_path('about/giving'),
      'link_title' => 'Make a Gift',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -42,
    );

    // -------------------------------------------------------------------------

    // Overview.
    $footer_academics['academics/academics-overview'] = array(
      'link_path' => drupal_get_normal_path('academics/academics-overview'),
      'link_title' => 'About Us',
      'menu_name' => 'menu-footer-academics-menu',
      'weight' => -50,
    );
    // Undergraduate Program.
    $footer_academics['academics/undergraduate-program'] = array(
      'link_path' => drupal_get_normal_path('academics/undergraduate-program'),
      'link_title' => 'Undergraduate Program',
      'menu_name' => 'menu-footer-academics-menu',
      'weight' => -48,
    );
    // Graduate Program.
    $footer_academics['academics/graduate-programs'] = array(
      'link_path' => drupal_get_normal_path('academics/graduate-programs'),
      'link_title' => 'Graduate Programs',
      'menu_name' => 'menu-footer-academics-menu',
      'weight' => -46,
    );
    // Courses.
    $footer_academics['courses'] = array(
      'link_path' => drupal_get_normal_path('courses'),
      'link_title' => 'Courses',
      'menu_name' => 'menu-footer-academics-menu',
      'weight' => -44,
    );

    // -------------------------------------------------------------------------

    // Department Newsletter.
    $footer_news_events['news/department-newsletter'] = array(
      'link_path' => drupal_get_normal_path('news/department-newsletter'),
      'link_title' => 'Department Newsletter',
      'menu_name' => 'menu-footer-news-events-menu',
      'weight' => -50,
    );
    // Recent News.
    $footer_news_events['news/recent-news'] = array(
      'link_path' => drupal_get_normal_path('news/recent-news'),
      'link_title' => 'Recent News',
      'menu_name' => 'menu-footer-news-events-menu',
      'weight' => -48,
    );
    // Subscribe.
    $footer_news_events['news/subscribe'] = array(
      'link_path' => drupal_get_normal_path('news/subscribe'),
      'link_title' => 'Subscribe',
      'menu_name' => 'menu-footer-news-events-menu',
      'weight' => -46,
    );
    // Upcoming events.
    $footer_news_events['events/upcoming-events'] = array(
      'link_path' => drupal_get_normal_path('events/upcoming-events'),
      'link_title' => 'Upcoming Events',
      'menu_name' => 'menu-footer-news-events-menu',
      'weight' => -44,
      'router_path' => 'events/upcoming-events',
      'customized' => 1,
    );

    // -------------------------------------------------------------------------

    // Faculty.
    $footer_people['people/faculty'] = array(
      'link_path' => drupal_get_normal_path('people/faculty'),
      'link_title' => 'Faculty',
      'menu_name' => 'menu-footer-people-menu',
      'weight' => -50,
    );
    // Students.
    $footer_people['people/students'] = array(
      'link_path' => drupal_get_normal_path('people/students'),
      'link_title' => 'Students',
      'menu_name' => 'menu-footer-people-menu',
      'weight' => -48,
    );
    // Staff.
    $footer_people['people/staff'] = array(
      'link_path' => drupal_get_normal_path('people/staff'),
      'link_title' => 'Staff',
      'menu_name' => 'menu-footer-people-menu',
      'weight' => -46,
    );

    $items[] = $main_menu;
    $items[] = $footer_about;
    $items[] = $footer_academics;
    $items[] = $footer_news_events;
    $items[] = $footer_people;

    // Loop through each of the items and save them.
    foreach ($items as $index_one => $item) {
      foreach($item as $k => $v) {
        // Check to see if there is a parent declaration. If there is then find
        // the mlid of the parent item and attach it to the menu item being saved.
        if (isset($v['parent'])) {
          $v['plid'] = $item[$v['parent']]['mlid'];
          unset($v['parent']); // Remove fluff before save.
        }
        // Save the menu item.
        $mlid = menu_link_save($v);
        $v['mlid'] = $mlid;
        $item[$k] = $v;
      }
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
