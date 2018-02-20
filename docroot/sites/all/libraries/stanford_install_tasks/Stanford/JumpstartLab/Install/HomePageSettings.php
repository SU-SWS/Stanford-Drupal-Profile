<?php

namespace Stanford\JumpstartLab\Install;

use \ITasks\AbstractInstallTask;

/**
 * Class HomePageSettings.
 *
 * @package Stanford\JumpstartLab\Install
 */
class HomePageSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $default = 'stanford_jumpstart_home_mayfield_lab';
    $context_status = variable_get('context_status', array());
    $homecontexts = stanford_jumpstart_home_context_default_contexts();

    $names = array_keys($homecontexts);

    // Enable these for site owners.
    $enabled['stanford_jumpstart_home_lomita'] = 1;
    $enabled['stanford_jumpstart_home_mayfield_lab'] = 1;
    $enabled['stanford_jumpstart_home_palm_news_events'] = 1;
    $enabled['stanford_jumpstart_home_panama_news_events'] = 1;
    $enabled['stanford_jumpstart_home_serra_news_events'] = 1;

    unset($context_status['']);
    variable_set('stanford_jumpstart_home_active', $default);
    variable_set('stanford_jumpstart_home_active_body_class', 'stanford-jumpstart-home-mayfield-lab');
    variable_set('context_status', $context_status);

    foreach ($names as $context_name) {
      $context_status[$context_name] = TRUE;
      $settings = variable_get('sjh_' . $context_name, array());
      $settings['site_admin'] = isset($enabled[$context_name]);
      variable_set('sjh_' . $context_name, $settings);
    }

    $context_status[$default] = FALSE;
    unset($context_status['']);

    // Save header background image.
    // Beaker image.
    $uuid = '3331b480-51bd-4086-bafc-6b5cd342c410';
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    $file_processor = new \ImporterFieldProcessorFile();
    $file_processor->setEndpoint($endpoint);
    $file = $file_processor->processFieldFileCreateItem($uuid);
    $fid = $file->fid;

    $settings = variable_get("sjh_stanford_jumpstart_home_mayfield_lab", array());
    $settings['header_image'] = $fid;
    file_usage_add($file, 'stanford_jumpstart_home', 'mayfield_lab', 1, 1);

    // Save settings.
    variable_set("sjh_stanford_jumpstart_home_mayfield_lab", $settings);

  }

  /**
   * Install Tasks requirements.
   *
   * @return array
   *   An array of module dependency names.
   */
  public function requirements() {
    return array(
      'stanford_jumpstart_home',
    );
  }

}
