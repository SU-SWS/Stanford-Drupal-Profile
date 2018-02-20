# Composer Vendor Autoload
Simple module to load the Composer `autoload.php` file. This module allows the
site builder to manually manage the dependencies for the project themselves,
rather than relying on some sort of automation. You may even use this module
as a dependency in your Drupal site to load the autoload.php file.

## Installation
1. Copy the module into your sites/all/modules folder.
2. Go to http://example.com/admin/modules and enable the Composer Autoloader
   (or do so with drush with the command `drush pm-enable composer_manager`).

## Configuration
The default configuration is to load autoload.php that is located in
`../vendor/autoload.php`. The default assumes that your vendor directory is
just outside your webroot. If you need to customize this, you can do so by
adding the following line to your setting.php file:
```
$conf['composer_autoloader'] = '/ABSOLUTE/PATH/TO/vendor/autoload.php';
```
