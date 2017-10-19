<?php
/**
 * @file
 * The OrgLib class is used for communicating with the CAP API's org endpoint.
 * This class can return information about the organization itself or the
 * profiles that are attached to it. To see the org codes and heirarchy please
 * refer to the Org Chart: http://web.stanford.edu/dept/pres-provost/budget/org/orgchart/
 *
 * EXAMPLE:
 * $client = new HTTPClient();
 * $orgs = array('AA00', 'AABB');
 * $orgsInfo = $client->api('org')->get($orgs);
 *
 * $client = new HTTPClient();
 * $org = 'AA00';
 * $orgInfo = $client->api('org')->getOrg($org);
 *
 * $client = new HTTPClient();
 * $org = 'AA00'
 * $profiles = $client->api('org')->getProfiles($org);
 *
 */

namespace CAPx\APILib\OrgLib;
use CAPx\APILib\AbstractAPILib as APILib;

class OrgLib extends APILib {

  /**
   * Get an array or organization information by an array of org codes.
   *
   * @param array $vars
   *   either a single string org code or an array of org codes
   *
   * @return mixed
   *   false if request fails or an array of data if it resolves.
   */
  public function get($vars) {
    // The endpoint. Usually default hard coded value.
    $endpoint = $this->getEndpoint();
    $options = $this->getOptions();

    if (!is_array($vars)) {
      $endpoint .= "/cap/v1/orgs/" . $vars;
    }
    else {
      $endpoint .= "/cap/v1/orgs";
      $options['query']['orgCodes'] = implode(",", $vars);
    }

    return $this->makeRequest($endpoint, array(), $options);
  }

  /**
   * Get an array of information about a single organization by org code.
   *
   * @param string $orgCode
   *   A valid Stanford Org Code
   *
   * @return mixed
   *   false if request fails or an array of data if it resolves.
   */
  public function getOrg($orgCode) {
    $endpoint = $this->getEndpoint();
    $endpoint .= "/cap/v1/orgs/" . $orgCode;
    return $this->makeRequest($endpoint);
  }

  /**
   * Get an array of profile information based on their relationship to an org code.
   *
   * @param string $orgCode
   *   A valid Stanford organization code
   *
   * @return mixed
   *   False if request fails or an array of data if it resolves.
   */
  public function getProfiles($orgCode) {
    $endpoint = $this->getEndpoint();
    $endpoint .= "/cap/v1/orgs/" . $orgCode . "/profiles";
    return $this->makeRequest($endpoint);
  }

}
