<?php
/**
 * @file
 * The SchemaLib library is used to communicate with the CAP API's schemea
 * endpoint. The schema endpoint describes the XML schema for a profile.
 *
 * EXAMPLES
 *
 * $client = new HTTPClient();
 * $schema = $client->api('schema')->profile();
 *
 * $client = new HTTPClient();
 * $schema = $client->api('schema')->get('profile');
 *
 */

namespace CAPx\APILib\SchemaLib;
use CAPx\APILib\AbstractAPILib as APILib;

class SchemaLib extends APILib {

  /**
   * Wrapper for get(profile).
   *
   * @return mixed
   *   Either an array of schema data describing profiles or false if there is
   *   an error.
   */
  public function profile() {
    return $this->get('profile');
  }


  /**
   * Get function for the schemas endpoint.
   *
   * Returns an array of informationdescribing a schema type.
   *
   * @param string $type
   *   Currently only known supported type is 'profile'
   *
   * @return mixed
   *   Either an array of schema data describing profiles or false if there is
   *   an error.
   */
  public function get($type) {
    $endpoint = $this->getEndpoint() . "/cap/v1/schemas/" . $type;
    return $this->makeRequest($endpoint);
  }


  /**
   * Get function for the schemas endpoint.
   *
   * Returns a JSON string of information describing a schema type.
   *
   * @param string $type
   *   Currently only known supported type is 'profile'
   *
   * @return mixed
   *   Either an array of schema data describing profiles or false if there is
   *   an error.
   */
  public function getRaw($type) {
    $endpoint = $this->getEndpoint() . "/cap/v1/schemas/" . $type;
    return $this->makeRawRequest($endpoint);
  }

}
