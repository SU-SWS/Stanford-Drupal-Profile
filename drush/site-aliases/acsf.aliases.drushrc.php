<?php
### Wildcard for ACSF: Stanford & Cardinal
###
### Examples:
### @acsf.[stack].[acsf_site_name]
### @acsf.[dev|test].[stack].[acsf_site_name]
###
### @acsf.cardinald7.sheatest
### @acsf.dev.cardinald7.sheatest
### @acsf.cardinalsites.jsa2071012
### @acsf.test.cardinalsites.jsa2071012

// Fron the top of the Acquia exports.
if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}

// The command from the CLI.
$command = $_SERVER['argv'];
$alias_key = "acsf";
$stored = [];
$command_aliases = array_filter($command,
  function ($var) use ($alias_key) {
    return preg_match("/\b$alias_key\b/i", $var);
  }
);

// If no alias syntax found just return quietly.
// @todo: Find out if I can return here without impacting other alias files.
if (!count($command_aliases)) {
  return;
}

// Now we have found the alias in the command we need
// to parse it to go to the correct domain if the correct key is in place.
$alias = array_shift($command_aliases);
$parts = explode(".", $alias);

// End if we don't match the key, end.
if ($parts[0] !== "@" . $alias_key) {
  // @todo: Find out if I can return here without impacting other alias files.
  return;
}

// The parts of the command we want. If there are less than three "parts"
// separated by a period assume the production environment.
// eg: stack.site
// Otherwise the parts should start with the environment
// eg: environment.stack.site.
if (count($parts) <= 3) {
  // "acsf" = $parts[0];
  $stack = $parts[1];
  $site = $parts[2];
}
else {
  // "acsf" = $parts[0];
  // $environment = $parts[1];
  $stack = $parts[2];
  $site = $parts[3];
}

$stack_id = array(
  "cardinalsites" => "01",
  "cardinald7" => "02",
);

// Sanitize for drush rysnc. eg: @alias:%files/
$site = array_shift(explode(":", $site));

// Define the alias.
$aliases[$stack . "." . $site] = array(
  'root' => '/var/www/html/' . $stack . '.' . $stack_id[$stack] . 'live/docroot',
  'ac-site' => $stack,
  'ac-env' => $stack_id[$stack] . 'live',
  'ac-realm' => 'enterprise-g1',
  'uri' => $site . '.cardinalsites.acsitefactory.com',
  'remote-host' => $stack . $stack_id[$stack] . 'live.ssh.enterprise-g1.acquia-sites.com',
  'remote-user' => $stack . '.' . $stack_id[$stack] . 'live',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);

// Stage / Test Environment.
$aliases["test." . $stack . "." . $site] = array(
  'root' => '/var/www/html/' . $stack . '.' . $stack_id[$stack] . 'test/docroot',
  'ac-site' => $stack,
  'ac-env' => $stack_id[$stack] . 'test',
  'ac-realm' => 'enterprise-g1',
  'uri' => $site . '.test-cardinalsites.acsitefactory.com',
  'remote-host' => $stack . $stack_id[$stack] . 'test.ssh.enterprise-g1.acquia-sites.com',
  'remote-user' => $stack . '.' . $stack_id[$stack] . 'test',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);

// Development Environment.
$aliases["dev." . $stack . "." . $site] = array(
  'root' => '/var/www/html/' . $stack . '.' . $stack_id[$stack] . 'dev/docroot',
  'ac-site' => $stack,
  'ac-env' => $stack_id[$stack] . 'dev',
  'ac-realm' => 'enterprise-g1',
  'uri' => $site . '.dev-cardinalsites.acsitefactory.com',
  'remote-host' => $stack . $stack_id[$stack] . 'dev.ssh.enterprise-g1.acquia-sites.com',
  'remote-user' => $stack . '.' . $stack_id[$stack] . 'dev',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
