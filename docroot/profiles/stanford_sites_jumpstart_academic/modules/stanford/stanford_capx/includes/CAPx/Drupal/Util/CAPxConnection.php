<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Util;
use CAPx\APILib\HTTPClient;
use Guzzle\Http\Exception\ClientErrorResponseException;

class CAPxConnection {

  /**
   * Test that both the API and Auth endpoints work.
   *
   * @return bool
   *   True for success.
   */
  public static function testConnection() {
    $auth = CAPxConnection::testAuthConnection();

    if ($auth->status && !empty($auth->token)) {
      variable_set('stanford_capx_token', $auth->token);
    }

    $api  = CAPxConnection::testApiConnection();

    if ($auth->status && $api->status) {
      return $auth;
    }

    if (!$auth->status) {
      return $auth;
    }

    return $api;
  }

  /**
   * Test that inputted settings can authenticate with the CAP API.
   *
   * @param string $username
   *   A decrypted username
   * @param string $password
   *   A decrypted password
   * @param string $authpoint
   *   A full url to the authentication point.
   *
   * @return object
   *   Information about the status
   */
  public static function testAuthConnection($username = null, $password = null, $authpoint = null) {

    $return = (object) array(
      'status' => 0,
      'message' => t('connection failed'),
      'code' => 0,
    );

    $username = is_null($username)    ? CAPx::getAuthUsername() : $username;
    $password = is_null($password)    ? CAPx::getAuthPassword() : $password;
    $authpoint = is_null($authpoint)  ? CAPx::getAuthEndpoint() : $authpoint;

    $client = new HTTPClient();
    $client->setEndpoint($authpoint);

    try {
      $auth = $client->api('auth')->authenticate($username, $password);
    }
    catch(\Exception $e) {
      $return->message = check_plain($e->getMessage());
      return $return;
    }

    $token = $auth->getAuthApiToken();
    $response = $auth->getLastResponse();

    if (!empty($response)) {
      $reasonPhrase = $response->getReasonPhrase();
      $code = $response->getStatusCode();
      $return->code = $code;
      $return->message = check_plain($reasonPhrase);
    }

    if (!empty($token)) {
      $return->status = 1;
      $return->token = $token;
    }

    return $return;
  }


  /**
   * Tests a token against the API for validity.
   *
   * @param string $token
   *   The authentication token.
   * @param string $endpoint
   *   The authentication uri.
   *
   * @return object
   *   $object->value
   */
  public static function testApiConnection($token = null, $endpoint = null) {

    $token    = is_null($token) ? variable_get('stanford_capx_token','') : $token;
    $endpoint = is_null($endpoint) ? CAPx::getAPIEndpoint() : $endpoint;

    $return = (object) array(
      'status' => 0,
      'message' => t('API connection failed'),
      'code' => "ERROR: ",
    );

    $client = new HTTPClient();
    $client->setEndpoint($endpoint);
    $client->setApiToken($token);
    $opts = $client->getHttpOptions();
    $opts['connect_timeout'] = 2.00;
    $opts['timeout'] = 5.00;
    $client->setHttpOptions($opts);

    try {
      $results = $client->api('orgs')->getOrg('BSWS');
    }
    catch(\Exception $e) {
      $return->message = $e->getMessage();
      return $return;
    }

    if (is_array($results)) {
      $return->status = 1;
      $return->message = t('Connection successful.');
      $return->code = 200;
    }

    return $return;
  }

  /**
   * Tokens can expire. This function renews the token with valid credentials.
   * @throws Exception
   *   If could not authenticate
   */
  public static function renewConnectionToken() {

    $username   = CAPx::getAuthUsername();
    $password   = CAPx::getAuthPassword();
    $authpoint  = CAPx::getAuthEndpoint();

    $client = new HTTPClient();
    $client->setEndpoint($authpoint);
    $response = $client->api('auth')->authenticate($username, $password);

    if ($response) {
      $token = $response->getAuthApiToken();
      variable_set('stanford_capx_token', $token);
      return TRUE;
    }

    throw new Exception("Could not authenticate with server.");
  }

  /**
   * Returns an authenticated HTTP Client for use.
   *
   * @return HTTPClient
   *   An authenticated HTTP client ready to use.
   */
  public static function getAuthenticatedHTTPClient() {
    $username   = CAPx::getAuthUsername();
    $password   = CAPx::getAuthPassword();
    $token      = variable_get('stanford_capx_token', '');
    $endpoint   = CAPx::getAPIEndpoint();
    $authpoint  = CAPx::getAuthEndpoint();

    $client = new HTTPClient();
    $client->setEndpoint($authpoint);

    $connection = CAPxConnection::testApiConnection($token);

    if (!$connection->status) {
      $response = $client->api('auth')->authenticate($username, $password);
      if ($response) {
        $token = $response->getAuthApiToken();
        variable_set('stanford_capx_token', $token);
      }
      else {
        throw new \Exception("Could not authenticate with API server.");
      }
    }

    $client->setApiToken($token);
    $client->setEndpoint($endpoint);

    return $client;
  }

}
