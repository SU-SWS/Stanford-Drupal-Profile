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

// Get the site name from the database.
$result = execute_query($con, "SELECT value FROM acsf_variables WHERE name = 'acsf_site_info'");
if ($result === FALSE || !isset($result[0]['value'])) {
  error('Could not retrieve the site name from the database.');
}
else {
  $site_info = unserialize($result[0]['value']);
  $site_name = $site_info['site_name'];
}
fwrite(STDERR, "Site name: $site_name;\n");

// Get the location of acsf module from the system table.
$result = execute_query($con, "SELECT filename FROM system WHERE name = 'acsf' AND status = 1");
if ($result === FALSE || !isset($result[0]['filename'])) {
  error('Could not locate the ACSF module.');
}
else {
  $acsf_dir = dirname($result[0]['filename']);
}
$docroot = sprintf('/var/www/html/%s.%s/docroot', $site, $env);
$acsf_location = "$docroot/$acsf_dir";
fwrite(STDERR, "ACSF location: $acsf_location;\n");

mysqli_close($con);

// Get the Factory creds using acsf-get-factory-creds.
$command = sprintf(
  'AH_SITE_GROUP=%1$s AH_SITE_ENVIRONMENT=%2$s drush6 @%1$s.%2$s -r %4$s -i %3$s acsf-get-factory-creds --pipe',
  escapeshellarg($site),
  escapeshellarg($env),
  escapeshellarg($acsf_location),
  escapeshellarg($docroot)
);
fwrite(STDERR, "Executing: $command;\n");
$creds = json_decode(trim(shell_exec($command)));

// Get the domain suffix for hosted sites, from factory creds data. This must
// be present on staged environments, but is not on the production environment.
$url_suffix = $creds->url_suffix;
if (empty($url_suffix)) {
  error("Could not retrieve hosted sites' domain suffix.");
}

// Create a new standard domain name.
$new_domain = "$site_name.$url_suffix";

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
