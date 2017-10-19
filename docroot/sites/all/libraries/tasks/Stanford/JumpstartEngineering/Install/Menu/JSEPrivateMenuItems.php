<?php
/**
 * @file
 * Create JSE menu items for the Private Pages section
 */

namespace Stanford\JumpstartEngineering\Install\Menu;
use Stanford\Utility\Install\CreateMenuLinks;

/**
 *
 */
class JSEPrivateMenuItems extends \ITasks\AbstractInstallTask {

  /**
   * Create menu items.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Private pages section landing page.
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
    // For Faculty / Sub-page.
    $items['private/for-faculty/sub-page'] = array(
      'link_path' => drupal_get_normal_path('private/for-faculty/sub-page'),
      'link_title' => 'Faculty Sub-Page',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'private/for-faculty', // must be already saved.
    );

    $linker = new \Stanford\Utility\Install\CreateMenuLinks();
    $linker->execute($items);

  }

}
