<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Menu;
/**
 *
 */
class JSVPSAMenuPositionRules extends \ITasks\AbstractInstallTask {

  /**
   * Create Menu Position Rules.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    # Set menu position default setting to 'mark the rule's parent menu item as being "active".'
    variable_set('menu_position_active_link_display', 'parent');
    // Define the rules.
    $rules = array();
    $rules[] = array(
      'link_title' => 'Announcements & News',
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
      'link_title' => 'Announcements & News',
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
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'People by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_person' => 'stanford_person',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'People by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'people/*',
        ),
      ),
    );
    foreach ($rules as $mp_rule) {
      $rule = new \Stanford\Utility\Install\InsertMenuRule();
      $rule->insert_menu_rule($mp_rule);
    }

  }

}
