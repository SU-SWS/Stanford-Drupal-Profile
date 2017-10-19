<?php
/**
 * Register CAPx namespace with PHP's spl_autoload_register
 */

define('CAPxPATH', realpath(dirname(__FILE__)));
function capx_autoloader($class) {
    $filename = CAPxPATH . '/' . str_replace('\\', '/', $class) . '.php';
    if (file_exists($filename)) {
      include_once($filename);
    }
}
spl_autoload_register('capx_autoloader');
