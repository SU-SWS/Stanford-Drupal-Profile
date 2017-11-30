<?php
/**
 * @file
 * This file forces HTTPS.
 */
// Require HTTPS.
// We're behind a load-balancer, so we can't check $_SERVER['HTTPS'].
// Have to check HTTP_X_FORWARDED_PROTO.
// $_SERVER['HTTP_X_FORWARDED_PROTO'] is only set when we're serving over https,
// therefore check if it's set.
if (!array_key_exists('HTTP_X_FORWARDED_PROTO', $_SERVER) && !drupal_is_cli()) {
  header('HTTP/1.0 301 Moved Permanently');
  header('Location: https://'. $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
  exit();
}
