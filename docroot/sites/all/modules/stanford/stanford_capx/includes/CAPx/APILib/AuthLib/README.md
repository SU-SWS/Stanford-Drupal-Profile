# AuthLib.php

 Authentication Library for connecting with the CAP API service. This class
 is returned through the HTTPClient->api function when 'auth' is set. See
 example below. When valid username and password credentials are passed
 through the authenticate method the CAP API token is set. This token is used
 to make calls to protected parts of the API and is passed along as a
 parameter.


 EXAMPLE:

    $client = new HTTPClient();
    $response = $client->api('auth')->authenticate('xxx', 'xxx');
    $token = $response->getAuthApiToken();

For debugging you can get the last response via getLastResponse():

    $client = new HTTPClient();
    $response = $client->api('auth')->authenticate('xxx', 'xxx');
    $raw = $response->getLastResponse();
