<?php
/**
 * @file
 * Create redirects.
 */

namespace Stanford\JumpstartEngineering\Install\Menu;
use Stanford\Utility\Install\CreateRedirects;

/**
 *
 */
class JSEMenuRedirects extends \ITasks\AbstractInstallTask {

  /**
   * Create menu redirects.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Create redirects.
    $redirects = array(
      'research' => 'research/overview',
      'people' => 'people/all/grid/grouped',
      'news' => 'news/recent-news',
      'events' => 'events/upcoming-events',
      'about' => 'about/mission',
      'resources' => 'resources/overview',
    );
    $redirecter = new \Stanford\Utility\Install\CreateRedirects();
    $redirecter->execute($redirects);

  }

}
