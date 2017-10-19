<?php
/**
 * A user who gets here is trying to visit a site that is not yet registered
 * with either the Site Factory or Hosting.
 */

// Don't run any of this code if we are drush or a CLI script.
if (function_exists('drush_main') || !function_exists('drupal_bootstrap') || drupal_is_cli()) {
  if (!function_exists('drush_main')) {
    header($_SERVER['SERVER_PROTOCOL'] . ' 404 Not Found');
  }
  return;
}

// Print a 404 response and a small HTML page.
header("HTTP/1.0 404 Not Found");
header('Content-type: text/html; charset=utf-8');

print <<<HTML
<!DOCTYPE html>
<html>
 <head>
  <meta charset="UTF-8" />
  <title>404 Page Not Found</title>
  <meta name="robots" content="noindex, nofollow, noarchive" />
 </head>
 <body>
HTML;

print('<p>' . t('The site you are looking for could not be found.') . '</p>');

print <<<HTML
 </body>
</html>
HTML;

exit();
