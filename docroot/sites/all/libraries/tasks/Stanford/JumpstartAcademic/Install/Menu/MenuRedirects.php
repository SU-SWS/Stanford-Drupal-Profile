<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartAcademic\Install\Menu;
/**
 *
 */
class MenuRedirects extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Create redirects.
    $redirects = array(
      'academics' => 'academics/academics-overview',
      'people' => 'people/faculty',
      'news' => 'news/recent-news',
      'events' => 'events/upcoming-events',
      'about' => 'about/about-us',
    );

    foreach ($redirects as $source => $dest) {
      $redirect = new \stdClass();
      $source_path = drupal_lookup_path('source', $source);

      if ($source_path == FALSE || $source_path == "<front>" || $source_path == "home") {
        $source_path = $source;
      }

      if (drupal_lookup_path('source', $dest)) {
        $dest = drupal_lookup_path('source', $dest);
      }

      // Check to see if redirect exists first.
      $found = redirect_load_by_source($source_path);
      if (!empty($found)) {
        // Redirect exists.
        continue;
      }

      module_invoke(
        'redirect',
        'object_prepare',
        $redirect,
        array(
          'source' => $source_path,
          'source_options' => array(),
          'redirect' => $dest,
          'redirect_options' => array(),
          'language' => LANGUAGE_NONE,
        )
      );

      if ($source_path !== $dest) {
        module_invoke('redirect', 'save', $redirect);
      }

    }

  }

  /**
   * Requirements. Duh.
   */
  public function requirements() {
    return array(
      'redirect',
    );
  }

}
