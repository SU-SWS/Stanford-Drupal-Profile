<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

class FullHTMLFormat extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    if (!module_exists("filter")) {
      module_enable(array("filter"));
    }

    // Add text formats.
    $full_html_format = array(
      'format' => 'full_html',
      'name' => 'Full HTML',
      'weight' => 1,
      'filters' => array(
        // URL filter.
        'filter_url' => array(
          'weight' => 0,
          'status' => 1,
        ),
        // Line break filter.
        'filter_autop' => array(
          'weight' => 1,
          'status' => 1,
        ),
        // HTML corrector filter.
        'filter_htmlcorrector' => array(
          'weight' => 10,
          'status' => 1,
        ),
      ),
    );
    $full_html_format = (object) $full_html_format;
    filter_format_save($full_html_format);
  }

  /**
   * [installTaskAlter description]
   * @param  [type] &$tasks [description]
   * @return [type]         [description]
   */
  public function installTaskAlter(&$tasks) {

    // This task needs to happen just after the core modules are installed
    // so that the dependency modules have what they need.

    // Store me in a variable and unset in tasks array.
    $me = $tasks[$this->getMachineName()];
    unset($tasks[$this->getMachineName()]);

    // Find out what index bootstrap task is so we can insert after.
    $index = array_search("install_bootstrap_full", array_keys($tasks));
    $index++;

    // Slick up and patch in $me at the proper place.
    $tasks = array_slice($tasks, 0, $index, TRUE) +
      array($this->getMachineName() => $me) +
      array_slice($tasks, $index, count($tasks) - $index, TRUE);
 }

}
