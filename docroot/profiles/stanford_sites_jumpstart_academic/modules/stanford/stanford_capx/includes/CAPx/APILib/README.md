# CAP API Library

This is a small PHP library that handles the communication between your PHP app and the CAP API. This library uses the Guzzle HTTPClient to authenticate and communicate with the CAP Api.

## Requirements

* PHP >= 5.3.2 probably with the cURL extension
* Guzzle Library
* A working Username and Password for the CAP API web service.


## Installation

Autoloading is supported using the PSR-0 coding standard. You will need to
register this library with PHP as it has not been add to composer as of yet.
Create a new file titled autoload.php and place it directly outside of the CAPx
library. In the autoload.php file place the example function below.

    eg:
      /my/path/autoload.php
      /my/path/CAPx


Example autoload function:

    define('CAPxPATH', realpath(dirname(__FILE__)));
    function capx_autoloader($class) {
        $filename = CAPxPATH . '/' . str_replace('\\', '/', $class) . '.php';
        if (file_exists($filename)) {
          include_once($filename);
        }
    }
    spl_autoload_register('capx_autoloader');


## Usage

    require_once 'autoload.php'; // see Installation section.
    use CAPx\APILib\HTTPClient;

    $client = new HTTPClient();

    $auth = $client->api('auth');
    $auth->authenticate('username', 'password');
    $token = $auth->getAuthToken();
    $client->setAPIToken($token);

    $schema = $client->api('schema')->profile();



## Documentation

[Authentication](AuthLib/README.md)

[Layouts](LayoutsLib/README.md)

[Organizations](OrgLib/README.md)

[Profiles](ProfileLib/README.md)

[Schema](SchemaLib/README.md)

[Search](SearchLib/README.md)







