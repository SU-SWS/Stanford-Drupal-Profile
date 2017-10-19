<?php
/**
 * @file
 * This function creates a new Menu Position rule.
 */

namespace Stanford\Utility\Install;

/**
 * Create new Menu Position Rule.
 * @param array $mp_rules A multidimensional array with the following keys:
 * 'link_title' : Link title in the Main Menu. Assuming depth of 1
 * 'admin_title' : Administrative title of the Menu Position rule. Human-readable.
 * 'conditions' : multidimensional array of Menu Position conditions
 */

class InsertMenuRule extends \ITasks\AbstractInstallTask {


  public function insert_menu_rule(&$mp_rule = array()) {

    module_load_include('inc', 'menu_position', 'menu_position.admin');
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
      'plid' => $plid,
      // "News" item in main menu. Need to look this up programatically
    );
    // Calling menu_position_add_rule here because we can assume that no rules have been added.
    menu_position_add_rule($rule);
  }

}

