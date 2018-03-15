#!/usr/bin/env php
<?php

/**
 * @file
 * Scrubs a site after its database has been copied.
 *
 * This happens on staging, not on site duplication.
 */

if (empty($argv[3])) {
  echo "Error: Not enough arguments.\n";
  exit(1);
}

$site    = $argv[1]; // AH site group.
$env     = $argv[2]; // AH site env.
$db_role = $argv[3]; // Database name.

fwrite(STDERR, sprintf("Scrubbing site database: site: %s; env: %s; db_role: %s;\n", $site, $env, $db_role));

// Get a database connection.
require dirname(__FILE__) . '/../../acquia/db_connect.php';
$con = get_db($site, $env, $db_role);

// Get the location of acsf module from the system table.
$result = execute_query($con, "SELECT filename FROM system WHERE name = 'acsf' AND status = 1");
if ($result === FALSE || !isset($result[0]['filename'])) {
  error('Could not locate the ACSF module.');
}
else {
  $acsf_dir = dirname($result[0]['filename']);
}
mysqli_close($con);

// When the site being staged has a different code than its source, the original
// code will be deployed on the update environment to ensure that the scrubbing
// process will not fail due to code / data structure differences. The indicator
// to execute the following commands can be found in the sites.json which can be
// accessed by the sites.inc's helper functions.
$docroot = sprintf('/var/www/html/%s.%s/docroot', $site, $env);
include_once $docroot . '/sites/g/sites.inc';
$sites_json = gardens_site_data_load_file();
if (!$sites_json) {
  error('The site registry could not be loaded from the server.');
}
$new_domain = FALSE;
foreach ($sites_json['sites'] as $site_domain => $site_info) {
  if ($site_info['conf']['acsf_db_name'] === $db_role && !empty($site_info['flags']['preferred_domain'])) {
    $new_domain = $site_domain;
    fwrite(STDERR, "Site domain: $new_domain;\n");

    // When the site being staged has different a code than its source, the
    // original code will be deployed on the update environment to ensure that
    // the scrubbing process will not fail due to code / data structure
    // differences.
    if (!empty($site_info['flags']['staging_exec_on'])) {
      $env = $site_info['flags']['staging_exec_on'];
    }
    break;
  }
}
if (!$new_domain) {
  error('Could not find the domain that belongs to the site.');
}

$docroot = sprintf('/var/www/html/%s.%s/docroot', $site, $env);
$acsf_location = "$docroot/$acsf_dir";
fwrite(STDERR, "ACSF location: $acsf_location;\n");

// Create a cache directory for drush.
$cache_directory = sprintf('/mnt/tmp/%s.%s/drush_tmp_cache/%s', $site, $env, md5($new_domain));
shell_exec(sprintf('mkdir -p %s', escapeshellarg($cache_directory)));

// Clear all caches on the site without doing a full Drupal bootstrap.
$command = sprintf(
  'CACHE_PREFIX=%s \drush6 -r /var/www/html/%s.%s/docroot -i %s -l %s acsf-low-level-cache-clear-all',
  escapeshellarg($cache_directory),
  escapeshellarg($site),
  escapeshellarg($env),
  escapeshellarg($acsf_location),
  escapeshellarg($new_domain)
);
fwrite(STDERR, "Executing: $command;\n");
$result = shell_exec($command);
print $result;

// Execute the scrub.
$command = sprintf(
  'CACHE_PREFIX=%s \drush6 @%s.%s -r /var/www/html/%s.%s/docroot -l %s -y acsf-site-scrub',
  escapeshellarg($cache_directory),
  escapeshellarg($site),
  escapeshellarg($env),
  escapeshellarg($site),
  escapeshellarg($env),
  escapeshellarg($new_domain)
);
fwrite(STDERR, "Executing: $command;\n");
$result = shell_exec($command);
print $result;

// Clean up the drush cache directory.
shell_exec(sprintf('rm -rf %s', escapeshellarg($cache_directory)));
