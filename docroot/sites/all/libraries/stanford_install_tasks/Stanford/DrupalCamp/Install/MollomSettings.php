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
class MollomSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Stanford Session Node Form.
    $mollom_session_form = array(
      'form_id' => 'stanford_session_node_form',
      'entity' => 'node',
      'bundle' => 'stanford_session',
      'mode' => 2,
      'checks' => array("spam"),
      'unsure' => 'captcha',
      'discard' => 0,
      'moderation' => 0,
      'enabled_fields' => array("title", "body"),
      'strictness' => 'relaxed',
      'module' => 'node',
    );

    mollom_form_save($mollom_session_form);

    // User Register Form.
    $mollom_user_form = array(
      'form_id' => 'user_register_form',
      'entity' => 'user',
      'bundle' => 'user',
      'mode' => 2,
      'checks' => array("spam", "profanity"),
      'unsure' => 'captcha',
      'discard' => 1,
      'moderation' => 0,
      'enabled_fields' => array("field_s_user_first_name", "field_s_user_last_name"),
      'strictness' => 'normal',
      'module' => 'user',
    );

    mollom_form_save($mollom_user_form);
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'mollom',
    );
  }

}
