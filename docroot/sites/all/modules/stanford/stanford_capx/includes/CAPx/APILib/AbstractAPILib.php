<?php
/**
 * @file
 * Abstract Library class. This API lib is used in most of the children libs and
 * controls the HTTP Client, the default endpoint, and has the default method
 * for making requests to the CAP API.
 */

namespace CAPx\APILib;
use CAPx\APILib\AbstractAPILibInterface;
use GuzzleHttp\Client as GuzzleClient;

abstract class AbstractAPILib implements AbstractAPILibInterface {

  // CAPx\HTTPClient. Client is an extension of the Guzzle HTTP Client.
  protected $client;
  // Deault Endpoint.
  protected $endpoint = 'https://api.stanford.edu';
  // Request Options. Used for storing things like the authentication token.
  protected $options = array();
  // The last response object. Good for debugging.
  protected $lastResponse;

  /**
   * Construction requires a Guzzle http client.
   *
   * @param GuzzleClient $client
   *   A Guzzle HTTP Client
   * @param array $options
   *   An array of HTTP options to use with the HTTP client.
   */
  public function __construct($client, $options = null) {

    // Inject the client.
    $this->setClient($client);

    // Merge in any additional options.
    if (is_array($options)) {
      $opts = $this->getOptions();
      $opts = array_merge($opts, $options);
      $this->setOptions($opts);
    }

  }

  /**
   * Setter for $client.
   *
   * @param GuzzleClient $client
   *   A Guzzle HTTP Client.
   */
  public function setClient($client) {
    $this->client = $client;
  }

  /**
   * Getter for client.
   *
   * @return GuzzleClient
   *   A guzzle http client.
   */
  public function getClient() {
    return $this->client;
  }

  /**
   * Setter for $endpoint.
   *
   * @param string $endpoint
   *   A fully qualified url. eg: http://client.somewhere.com/api/vi2/query
   */
  public function setEndpoint($endpoint) {
    $this->endpoint = $endpoint;
  }

  /**
   * Getter for endpoint url.
   *
   * @return string
   *   A fully qualified url without the last slash.
   */
  public function getEndpoint() {
    return $this->endpoint;
  }

  /**
   * Setter for options.
   *
   * Options are an array of HTTP options to pass through to the HTTP Client.
   *
   * @param array $options
   *   An assosiated array of options.
   */
  public function setOptions($options) {
    $this->options = $options;
  }

  /**
   * Getter for $options.
   *
   * @return array
   *   An array of HTTP Client options.
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Getter for lastResponse.
   * @return object
   *   The last response object from request->send();
   */
  public function getLastResponse() {
    return $this->lastResponse;
  }

  /**
   * Setter for the lastResponse variable.
   *
   * Last response should be the response from a request object.
   * $request->send();
   *
   * @param object
   *   Response object from a request object.
   */
  protected function setLastResponse($response) {
    $this->lastResponse = $response;
  }

  /**
   * The default request function for all libraries.
   *
   * This function is passed a number of parameters and requests data from the
   * CAP API. If no usable data is returned or something went wrong it returns
   * false. This function will return an array.
   *
   * @param string $endpoint
   *   The fully qualified url endpoint
   * @param array $params
   *   Additional query string parameters stored in an associative.
   *   eg: q=something.
   * @param array $extraOptions
   *   Additional options to pass through to the http client.
   *
   * @return mixed
   *   Returns either an array of data or false if something went wrong.
   */
  protected function makeRequest($endpoint, $params = array(), $extraOptions = NULL) {
    $response = $this->makeRawRequest($endpoint, $params, $extraOptions);

    if (!$response) {
      return FALSE;
    }

    try {
      $body = $response->getBody();
      $json = drupal_json_decode($body->getContents());
    }
    catch (\Exception $e) {
      return FALSE;
    }

    // JSON decoded valid response.
    return $json;
  }

  /**
   * Passed a number of parameters and requests data from the CAP API.
   *
   * If no usable data is returned or something went wrong it returns
   * false. This function will return JSON. The raw response is also stored and
   * can be retrieved using the getLastResponse() method.
   *
   * @param string $endpoint
   *   The fully qualified url endpoint.
   * @param array $params
   *   Additional query string parameters stored in an associative.
   *   eg: q=something.
   * @param array $extraOptions
   *   Additional options to pass through to the http client.
   *
   * @return mixed
   *   Returns either a JSON string or false if something went wrong.
   */
  protected function makeRawRequest($endpoint, $params = array(), $extraOptions = NULL) {

    $code = "";

    // Get the guzzle client.
    $client = $this->getClient();

    // Merge in any extra http options.
    $options = $this->getOptions();
    if (is_array($extraOptions)) {
      $options = array_merge($options, $extraOptions);
    }

    // Provide a default cert PEM.
    $relative_pem_file = drupal_get_path("module", "stanford_capx") . "/includes/CAPx/APILib/cacert.pem";
    $absolute_pem_file = drupal_realpath($relative_pem_file);
    $which_pem = variable_get('stanford_capx_verify_pem', FALSE);

    // Allow the option of using the bundled pem file.
    if ($which_pem !== FALSE) {

      // If the user set the var to a string use that. Otherwise go with the
      // default.
      if (is_string($which_pem)) {
        $options['verify'] = check_plain($which_pem);
      }
      else {
        $options['verify'] = $absolute_pem_file;
      }
    }

    // This is bad idea. You should rely on the cert pem above.
    if (variable_get("stanford_capx_ignore_ssl", FALSE)) {
      $options['verify'] = FALSE;
    }

    // Build and make the request.
    $response = FALSE;
    try {

      $response = $client->get($endpoint, $options);

      // Store the last response for later use.
      $this->setLastResponse($response);

      // Handle only valid response codes.
      $code = $response->getStatusCode();

    }
    catch(\Exception $e) {
      $code = $e->getCode();
      watchdog('AbstractAPILib', check_plain($e->getMessage()), array(), WATCHDOG_DEBUG);
    }

    // @todo: Handle non-valid response codes.
    switch ($code) {
      case '200':
        return $response;

      default:
        return FALSE;
      break;
    }

  }

}
