<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartPlus\Install\Menu;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class MenuRules extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    module_load_include('inc', 'menu_position', 'menu_position.admin');

    // Define the rules.
    $rules = array();
    $rules[] = array(
      'link_title' => 'About',
      'admin_title' => 'About by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'about/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_news_item' => 'stanford_news_item',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'news/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Events',
      'admin_title' => 'Events by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_event' => 'stanford_event',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Events',
      'admin_title' => 'Events by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'events/*',
        ),
      ),
    );

    foreach ($rules as $mp_rule) {
      $this->insert_menu_rule($mp_rule);
    }

  }

  /**
  * Create new Menu Position Rule.
  * @param array $mp_rules A multidimensional array with the following keys:
  * 'link_title' : Link title in the Main Menu. Assuming depth of 1
  * 'admin_title' : Administrative title of the Menu Position rule. Human-readable.
  * 'conditions' : multidimensional array of Menu Position conditions
  */
  protected function insert_menu_rule($mp_rule) {

    // Get the mlid of the parent link.
    $result = db_select('menu_links', 'm')
    ->fields('m', array('mlid'))
    ->condition('menu_name', 'main-menu')
    ->condition('depth', 1)
    ->condition('link_title', $mp_rule['link_title'])
    ->execute()
    ->fetchAssoc();

    $plid = $result['mlid'];


    // Create the array to populate the rule.
    $rule = array(
      'admin_title' => $mp_rule['admin_title'],
      'conditions' => $mp_rule['conditions'],
      'menu_name' => 'main-menu',
      'plid' => $plid,  // "News" item in main menu. Need to look this up programatically
    );

    // Calling menu_position_add_rule here because we can assume that no rules have been added.
    menu_position_add_rule($rule);
  }

  /**
   * Requirements. Duh.
   */
  public function requirements() {
    return array(
      'menu_position',
    );
  }

}
