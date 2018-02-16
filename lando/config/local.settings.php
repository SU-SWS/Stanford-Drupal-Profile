<?php

/**
 * Local Database Defaults For Lando.
 */
$databases = array(
  'default' =>
  array (
    'default' =>
    array (
      'database' => getenv('DB_NAME'),
      'username' => getenv('DB_USER'),
      'password' => getenv('DB_PASSWORD'),
      'host' => getenv('DB_HOST'),
      'port' => getenv('DB_PORT'),
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
