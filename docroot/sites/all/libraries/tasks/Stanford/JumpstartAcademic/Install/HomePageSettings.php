<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartAcademic\Install;
/**
 *
 */
class HomePageSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $default = 'stanford_jumpstart_home_panama_news_events';
    $context_status = variable_get('context_status', array());
    $homecontexts = stanford_jumpstart_home_context_default_contexts();

    $names = array_keys($homecontexts);

    // Enable these for site owners
    $enabled['stanford_jumpstart_home_lomita'] = 1;
    $enabled['stanford_jumpstart_home_mayfield_news_events'] = 1;
    $enabled['stanford_jumpstart_home_palm_news_events'] = 1;
    $enabled['stanford_jumpstart_home_panama_news_events'] = 1;
    $enabled['stanford_jumpstart_home_serra_news_events'] = 1;

    unset($context_status['']);

    foreach ($names as $context_name) {
      $context_status[$context_name] = TRUE;
      $settings = variable_get('sjh_' . $context_name, array());
      $settings['site_admin'] = isset($enabled[$context_name]);
      variable_set('sjh_' . $context_name, $settings);
    }

    $context_status[$default] = FALSE;
    unset($context_status['']);

    // Save settings
    variable_set('stanford_jumpstart_home_active', $default);
    variable_set('stanford_jumpstart_home_active_body_class', 'stanford-jumpstart-home-panama');
    variable_set('context_status', $context_status);
  }

}
