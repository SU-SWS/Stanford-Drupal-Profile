<?php
/**
 * @file
 */

define('ITASKS', realpath(dirname(__FILE__)));

/**
 * [itasks_autoloader description]
 * @param  [type] $class [description]
 * @return [type]        [description]
 */
function itasks_autoloader($class) {
  $filename = ITASKS . '/' . str_replace('\\', '/', $class) . '.php';
  if (file_exists($filename)) {
    include_once $filename;
  }
}

spl_autoload_register('itasks_autoloader');
