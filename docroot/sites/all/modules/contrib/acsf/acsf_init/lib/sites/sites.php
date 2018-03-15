<?php

/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 */

if (!function_exists('acsf_hooks_includes')) {
  /**
   * Scans a factory-hooks sub-directory and returns PHP files to be included.
   *
   * @param string $hook_name
   *   The name of the hook whose files should be returned.
   *
   * @return string[]
   *   A list of customer-defined hook files to include.
   */
  function acsf_hooks_includes($hook_name) {
    $hook_pattern = sprintf('%s/../factory-hooks/%s/*.php', getcwd(), $hook_name);
    return glob($hook_pattern, GLOB_NOSORT);
  }
}

// Include custom sites.php code from factory-hooks/pre-sites-php.
foreach (acsf_hooks_includes('pre-sites-php') as $pre_hook) {
  include_once $pre_hook;
}

if (!function_exists('is_acquia_host')) {
  /**
   * Checks whether the site is on Acquia Hosting.
   *
   * @return bool
   *   TRUE if the site is on Acquia Hosting, otherwise FALSE.
   */
  function is_acquia_host() {
    return file_exists('/var/acquia');
  }
}

// HTTP_HOST can be empty during early drush bootstrap. Also, check that we're
// on an Acquia server so we don't run this code for local development.
if (empty($_SERVER['HTTP_HOST']) || !is_acquia_host()) {
  return;
}

// There are some drush commands which run other commands as a post execution
// task, for example the drush updb which automatically executes a cache clear
// or rebuild after the update has finished, however this is handled by invoking
// the relevant drush command in a different process on the same site. Since we
// are calling these drush commands without an alias, drush8 is trying to
// discover if there is an alias that covers the current site, and in the
// process it walks over the drush aliases file and includes the sites.php for
// each entry. In our case drush will include the sites.php for the live and the
// update environment causing a fatal php error because sites.php includes
// sites.inc and the functions would be redefined on the fly.
// When calling the commands with an alias a different issue surfaces: starting
// from drush7, drush is static caching the alias entries as is, meaning that
// the extra root and uri parameters we pass to the drush command do not get
// applied to the static alias entry and when drush is trying to run the cache
// clear or rebuild using this static cache then it is going to try to run it on
// the wrong site.
// Therefore, for the time being, safeguard the sites.inc inclusion and avoid
// using aliases.
if (!function_exists('gardens_site_data_load_file')) {
  require_once dirname(__FILE__) . '/g/sites.inc';
}

// Prevents to run further if the sites.json file doesn't exists.
// This step also tries to prevent errors on a none acsf environment.
if (empty($_ENV['AH_SITE_GROUP']) || empty($_ENV['AH_SITE_ENVIRONMENT']) || !function_exists('gardens_site_data_get_filepath') || !file_exists(gardens_site_data_get_filepath())) {
  return;
}

// Drush site-install gets confused about the uri when we specify the
// --sites-subdir option. The HTTP_HOST is set incorrectly and we can't
// find it in the sites.json. By specifying the --acsf-install-uri option
// with the value of the standard domain, we can catch that here and
// correct the uri argument for drush site installs.
if (drupal_is_cli() && function_exists('drush_get_option') && ($http_host = drush_get_option('acsf-install-uri', FALSE))) {
  // The acsf-install-uri argument contains a pure domain string, one without a
  // leading http:// string. To make sure that the parse_url properly identifies
  // the host portion, add a http:// string.
  $host = $_SERVER['HTTP_HOST'] = parse_url('http://' . $http_host, PHP_URL_HOST);
  $acsf_uri_path = parse_url('http://' . $http_host, PHP_URL_PATH);
  $acsf_uri_path .= '/index.php';
}
else {
  $host = rtrim($_SERVER['HTTP_HOST'], '.');
  $acsf_uri_path = $_SERVER['SCRIPT_NAME'] ? $_SERVER['SCRIPT_NAME'] : $_SERVER['SCRIPT_FILENAME'];
}

$acsf_host = implode('.', array_reverse(explode(':', $host)));
// Build an array with maximum one path fragment. Since the paths always start
// with a '/' and we are splitting them by the '/', the array will always start
// with an empty string.
$acsf_uri_path_fragments = explode('/', $acsf_uri_path);
$acsf_uri_path_fragments = array_diff($acsf_uri_path_fragments, array('index.php'));
// Only check the first path fragment, then the base domain.
$acsf_uri_path_fragments = array_slice($acsf_uri_path_fragments, 0, 2);
// Check whether we can find site data for the hostname suffixed by one
// fragment, or for only the hostname.
$data = NULL;
for ($i = count($acsf_uri_path_fragments); $i > 0; $i--) {
  $dir = $acsf_host . implode('.', array_slice($acsf_uri_path_fragments, 0, $i));
  $acsf_uri = $acsf_host . implode('/', array_slice($acsf_uri_path_fragments, 0, $i));
  if (!GARDENS_SITE_DATA_USE_APC) {
    // gardens_site_data_refresh_one() will do a full parse if the domain is in
    // the file at all and a single line parse fails.
    $data = gardens_site_data_refresh_one($acsf_uri);
  }
  else {
    // Check for data in APC: FALSE means no; 0 means "not found" cached in APC;
    // NULL means "sites.json read failure" cached in APC.
    $data = gardens_site_data_cache_get($acsf_uri);
    if ($data === FALSE) {
      $data = gardens_site_data_refresh_one($acsf_uri);
    }
  }
  // Check again for a hostname with less fragments if we got a "not found";
  // stop if we got a read failure or found data.
  if ($data || $data === NULL) {
    break;
  }
}

// If either "not found" or "read failure" (from either the cache or the
// sites.json file): don't set $sites and fall through (to, probably, reading
// sites/default/settings.php for settings).
if (empty($data)) {
  if ($data === NULL) {
    // If we encountered a read error, indicate that we want the same (short)
    // cache time for the page, as we have for the data in APC.
    $GLOBALS['gardens_site_settings']['page_ttl'] = GARDENS_SITE_DATA_READ_FAILURE_TTL;
  }
  return;
}

$GLOBALS['gardens_site_settings'] = $data['gardens_site_settings'];
$sites[$dir] = $data['dir'];

// Include custom sites.php code from factory-hooks/post-sites-php, only when
// a domain was found.
foreach (acsf_hooks_includes('post-sites-php') as $post_hook) {
  include_once $post_hook;
}
