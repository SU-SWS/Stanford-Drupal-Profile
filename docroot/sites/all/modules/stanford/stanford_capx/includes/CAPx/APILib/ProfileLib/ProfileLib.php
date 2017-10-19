<?php
/**
 * @file
 * The ProfileLib library is used to search for and find profiles on a number of
 * parameters. This library is also used for fetching individual profile data.
 *
 * EXAMPLES:
 *
 * $client = new HTTPClient();
 * $results = $client->api('profile')->search($type, $args, FALSE, TRUE);
 *
 * $client = new HTTPClient();
 * $profile = $cleint->api('profile')->get(34234);
 *
 */

namespace CAPx\APILib\ProfileLib;
use CAPx\APILib\AbstractAPILib as APILib;

class ProfileLib extends APILib {

  /**
   * Queries the CAP API for profiles that match a set of search parameters.
   *
   * Search response contains a bunch of profile information but not the whole
   * profile. For that you will need to use the ->get(profileID) method.
   *
   * @param string $type
   *   The type of search being performed. Options are:
   *   ids, uids (sunet), university ids, orgCodes,
   *   privGroups, name, orgAlias
   * @param mixed $args
   *   array or string input. The search arguments.
   * @param bool $exact
   *   Wether or not to 'fuzzy' search. False is fuzzy.
   * @param bool $children
   *   Wether or not to include children orgs in an orgCodes search.
   * @param string $order
   *   The field to sort on. Options are name or id.
   *
   * @return mixed
   *   An array profiles that matched the search or false if something went
   *   wrong.
   */
  public function search($type, $args, $exact = FALSE, $children = FALSE, $order = '') {

    $endpoint = $this->getEndpoint() . "/profiles/v1";
    $options = $this->getOptions();

    switch ($type) {
      case "ids":
      case "uids":
      case "universityIds":
      case "orgCodes":
      case "privGroups":
        $options['query'][$type] = implode(",", $args);
        break;

      case "name":
      case "orgAlias":
        $options['query'][$type] = $args;
        break;

      default:
        throw new \Exception("Missing list type.");
    }

    $options['query']['exact'] = ($exact) ? "true" : "false";
    $options['query']['includeChildren'] = ($children) ? "true" : "false";

    if (!empty($order)) {
      $options['query']['order'] = $order;
    }

    return $this->makeRequest($endpoint, array(), $options);
  }

  /**
   * Get all the information about one specific profile.
   *
   * Fetch and return an array of profile information based on CAP's profile id.
   * You can find the profile id for a profile by using the search method.
   *
   * @param int $profileId
   *   The CAP API profile id.
   *
   * @return mixed
   *   An array of profile information or false if none.
   */
  public function get($profileId) {
    $endpoint = $this->getEndpoint() . "/profiles/v1/" . $profileId;
    return $this->makeRequest($endpoint);
  }

  /**
   * Get all the information about one specific profile.
   *
   * Fetch and return a JSON string of profile information based on CAP's
   * profile id.
   *
   * @param string $profileId
   *   The CAP API profile id.
   *
   * @return mixed
   *   An JSON string of profile information or false if none.
   */
  public function getRaw($profileId) {
    $endpoint = $this->getEndpoint() . "/profiles/v1/" . $profileId;
    return $this->makeRawRequest($endpoint);
  }

}
