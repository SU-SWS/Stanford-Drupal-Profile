<?php

namespace Stanford\JumpstartLab\Install\Menu;

use \ITasks\AbstractInstallTask;

/**
 * Class MenuSettings.
 *
 * @package Stanford\JumpstartLab\Install\Menu
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

    // /////////////////////////////////////////////////////////////////////////
    // Jumpstart Lab Main Menus
    // /////////////////////////////////////////////////////////////////////////
    // People.
    $main_menu['people'] = array(
      'link_path' => drupal_get_normal_path('people'),
      'link_title' => 'People',
      'menu_name' => 'main-menu',
      'weight' => 0,
    );
    // People / Faculty.
    $main_menu['people/jacob-smith'] = array(
      'link_path' => drupal_get_normal_path('people/jacob-smith'),
      'link_title' => 'Director',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'customized' => 1,
      'parent' => 'people',
    );
    // People / Members.
    $main_menu['people/students'] = array(
      'link_path' => drupal_get_normal_path('people/students'),
      'link_title' => 'Students',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'customized' => 1,
      'parent' => 'people',
    );
    // People / Staff.
    $main_menu['people/staff'] = array(
      'link_path' => drupal_get_normal_path('people/staff'),
      'link_title' => 'Staff',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'people',
    );
    // Projects.
    $main_menu['projects'] = array(
      'link_path' => drupal_get_normal_path('projects'),
      'link_title' => 'Projects',
      'menu_name' => 'main-menu',
      'weight' => 5,
      'customized' => 1,
    );
    // Projects / Research Overview.
    $main_menu['projects/research-overview'] = array(
      'link_path' => drupal_get_normal_path('projects/research-overview'),
      'link_title' => 'Research Overview',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'projects',
    );
    // Projects / Sample Research Project One.
    $main_menu['projects/sample-research-project-one'] = array(
      'link_path' => drupal_get_normal_path('projects/sample-research-project-one'),
      'link_title' => 'Sample Research Project One',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'projects',
    );
    /*
    // Projects / Sample Research Project Two.
    $main_menu['projects/sample-research-project-two'] = array(
    'link_path' => drupal_get_normal_path('projects/sample-research-project-two'),
    'link_title' => 'Sample Research Project Two',
    'menu_name' => 'main-menu',
    'weight' => -6,
    'customized' => 1,
    'parent' => 'projects',
    );
    // Projects / Sample Research Project Three.
    $main_menu['projects/sample-research-project-three'] = array(
    'link_path' => drupal_get_normal_path('projects/sample-research-project-three'),
    'link_title' => 'Sample Research Project Three',
    'menu_name' => 'main-menu',
    'weight' => -6,
    'customized' => 1,
    'parent' => 'projects',
    );
     */
    // Projects / Tools/Materials.
    $main_menu['projects/toolsmaterials'] = array(
      'link_path' => drupal_get_normal_path('projects/toolsmaterials'),
      'link_title' => 'Tools/Materials',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'projects',
    );
    // Projects / Related Research.
    $main_menu['projects/related-research'] = array(
      'link_path' => drupal_get_normal_path('projects/related-research'),
      'link_title' => 'Related Research',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'projects',
    );
    // Publications.
    $main_menu['publications'] = array(
      'link_path' => drupal_get_normal_path('publications'),
      'link_title' => 'Publications',
      'menu_name' => 'main-menu',
      'weight' => 10,
      'customized' => 1,
    );
    // Participate.
    $main_menu['participate'] = array(
      'link_path' => drupal_get_normal_path('participate'),
      'link_title' => 'Participate',
      'menu_name' => 'main-menu',
      'weight' => 15,
      'customized' => 1,
    );
    // Participate / Research Assistant.
    $main_menu['participate/research-assistant'] = array(
      'link_path' => drupal_get_normal_path('participate/research-assistant'),
      'link_title' => 'Research Assistant',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'participate',
    );
    // Participate / Study Participant.
    $main_menu['participate/study-participant'] = array(
      'link_path' => drupal_get_normal_path('participate/study-participant'),
      'link_title' => 'Study Participant',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'customized' => 1,
      'parent' => 'participate',
    );
    /*
    // Participate / For Parents.
    $main_menu['participate/for-parents'] = array(
    'link_path' => drupal_get_normal_path('participate/for-parents'),
    'link_title' => 'For Parents',
    'menu_name' => 'main-menu',
    'weight' => -6,
    'customized' => 1,
    'parent' => 'participate',
    );
    // Participate / Sample Application Form.
    $main_menu['participate/sample-application-form'] = array(
    'link_path' => drupal_get_normal_path('participate/sample-application-form'),
    'link_title' => 'Sample Application Form',
    'menu_name' => 'main-menu',
    'weight' => -6,
    'customized' => 1,
    'parent' => 'participate',
    );
     */
    // Resources.
    $main_menu['resources'] = array(
      'link_path' => drupal_get_normal_path('resources'),
      'link_title' => 'Resources',
      'menu_name' => 'main-menu',
      'weight' => 20,
      'customized' => 1,
    );
    // About.
    $main_menu['about'] = array(
      'link_path' => drupal_get_normal_path('about/about-us'),
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'weight' => 25,
    );
    // About / Overview.
    $main_menu['about/overview'] = array(
      'link_path' => drupal_get_normal_path('about/about-us'),
      'link_title' => 'Overview',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => 'about',
    );
    // About / Video.
    $main_menu['about/video'] = array(
      'link_path' => drupal_get_normal_path('about/video'),
      'link_title' => 'Video',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'about',
    );
    // News Landing.
    $main_menu['news'] = array(
      'link_path' => drupal_get_normal_path('news'),
      'link_title' => 'News',
      'menu_name' => 'main-menu',
      'weight' => -5,
      'parent' => 'about',
    );
    // About / Courses.
    $main_menu['about/courses'] = array(
      'link_path' => drupal_get_normal_path('about/courses'),
      'link_title' => 'Courses',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'parent' => 'about',
    );
    // About / Directions & Parking.
    $main_menu['about/directions-parking'] = array(
      'link_path' => drupal_get_normal_path('about/directions-parking'),
      'link_title' => 'Directions & Parking',
      'menu_name' => 'main-menu',
      'weight' => -6,
      'parent' => 'about',
    );

    // About / Contact.
    $main_menu['about/contact-us'] = array(
      'link_path' => drupal_get_normal_path('about/contact-us'),
      'link_title' => 'Contact',
      'menu_name' => 'main-menu',
      'weight' => -4,
      'parent' => 'about',
    );
    // About / Make a Gift.
    $main_menu['about/giving'] = array(
      'link_path' => drupal_get_normal_path('about/giving'),
      'link_title' => 'Make A Gift',
      'menu_name' => 'main-menu',
      'weight' => -2,
      'parent' => 'about',
    );

    $main_menu['private/members-only'] = array(
      'link_path' => drupal_get_normal_path('private/members-only'),
      'link_title' => 'Members Only',
      'menu_name' => 'main-menu',
      'weight' => 50,
    );
    $main_menu['private/cell-phone-numbers'] = array(
      'link_path' => drupal_get_normal_path('private/cell-phone-numbers'),
      'link_title' => 'Cell Phone Numbers',
      'menu_name' => 'main-menu',
      'weight' => -2,
      'parent' => 'private/members-only',
    );
    $main_menu['private/sample-restricted-page-one'] = array(
      'link_path' => drupal_get_normal_path('private/sample-restricted-page-one'),
      'link_title' => 'Sameple Restricted Page One',
      'menu_name' => 'main-menu',
      'weight' => -2,
      'parent' => 'private/members-only',
    );
    $main_menu['private/forms'] = array(
      'link_path' => drupal_get_normal_path('private/forms'),
      'link_title' => 'Forms',
      'menu_name' => 'main-menu',
      'weight' => -2,
      'parent' => 'private/members-only',
    );

    // ///////////////////////////////////////////////////////////////////////////
    // Footer Menus
    // ///////////////////////////////////////////////////////////////////////////
    // About.
    $footer_about['about'] = array(
      'link_path' => drupal_get_normal_path('about'),
      'link_title' => 'About Us',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -50,
    );
    // About / Directions & Parking.
    $footer_about['about/directions-parking'] = array(
      'link_path' => drupal_get_normal_path('about/directions-parking'),
      'link_title' => 'Directions & Parking',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -49,
    );
    // About / Make a Gift.
    $footer_about['about/giving'] = array(
      'link_path' => drupal_get_normal_path('about/giving'),
      'link_title' => 'Make a Gift',
      'menu_name' => 'menu-footer-about-menu',
      'weight' => -42,
    );

    $items[] = $main_menu;
    $items[] = $footer_about;

    // Loop through each of the items and save them.
    foreach ($items as $index_one => $item) {
      foreach ($item as $k => $v) {
        // Check if there is a parent declaration. If there is then find the
        // mlid of the parent item and attach it to the menu item being saved.
        if (isset($v['parent'])) {
          $v['plid'] = $item[$v['parent']]['mlid'];
          // Remove fluff before save.
          unset($v['parent']);
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
