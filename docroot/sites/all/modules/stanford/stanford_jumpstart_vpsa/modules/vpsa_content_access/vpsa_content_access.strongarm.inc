<?php
/**
 * @file
 * vpsa_content_access.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vpsa_content_access_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_page';
  $strongarm->value = array(
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'per_node' => 1,
    'priority' => '0',
  );
  $export['content_access_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_stanford_page';
  $strongarm->value = array(
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'per_node' => 1,
    'priority' => '0',
  );
  $export['content_access_stanford_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_stanford_video';
  $strongarm->value = array(
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 19,
      3 => 15,
    ),
    'per_node' => 1,
    'priority' => '0',
  );
  $export['content_access_stanford_video'] = $strongarm;

  return $export;
}
