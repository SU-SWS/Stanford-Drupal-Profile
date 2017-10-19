<?php
/**
 * @file
 * This class creates redirects.
 */

namespace Stanford\Utility\Install;

class CreateRedirects extends \ITasks\AbstractInstallTask {


  /**
   * Create redirects
   * @param $args an array where the key is the "from" path and the value is the "to" path.
   *
   * E.g., array("source" => "destination", "from" => "to")
   */
  public function execute(&$args = array()) {
    foreach ($args as $source => $dest) {
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
   * Define module requirements.
   * @return array An array of required modules.
   */
  public function requirements() {
    return array(
      'redirect',
    );
  }


}
