<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Lookups;

class LookupWorkgroupOrphans implements LookupInterface {

  /**
   * Look through the workgroups for the profile results.
   *
   * @todo This function has the potential to send & receive a very large
   * request to/from the server and could be a potential breaking point. Need to
   * revisit this in order to break it out into a smaller check somehow.
   *
   * @param EntityImporterOrphans $orphaner
   *   The orphan processor object.
   *
   * @return array
   *   The remaining orphans
   */
  public function execute($orphaner) {

    $options = $orphaner->getImporterOptions();
    $orphans = $orphaner->getOrphans();

    // Check to see if there is something to run on.
    if (!in_array("privGroups", $options['types'])) {
      return $orphans;
    }

    $client = $orphaner->getClient();
    $profiles = $orphaner->getProfiles();
    $groups = explode(",", $options['workgroup']);
    $orphans['privGroups'] = array();

    // Flip the profileIds so that the profile array is keyed.
    $profiles = array_flip($profiles);

    // Workgroup profile information is only available if you look up a
    // workgroup directly. Unfortunately, that means that we need to make
    // another request to the server for each work group.

    // Setting limit of items per call to use the batch limit variable
    // so we don't overload the service.
    $limit = variable_get('stanford_capx_batch_limit', 50);
    $client->setLimit($limit);
    $response = $client->api('profile')->search("privGroups", $groups);

    // Try Twice To Ensure we get a valid response.
    if (!isset($response['values']) || !is_array($response['values'])) {
      $response = $client->api('profile')->search("privGroups", $groups);
    }

    // If still not a valid response throw an error.
    if (!isset($response['values']) || !is_array($response['values'])) {
      watchdog("LookupWorkgroupOrphans", "Client response was false. Possible connectivity issue. Stopped orphan processing. %data", array("%data" => serialize($response)), WATCHDOG_ERROR);
      throw new \Exception("Could not fetch workgroups from api in orphan lookup.", 1);
    }

    // Trim out the information we don't need so that the php variable doesn't
    // bloat and cause OOM errors.
    $results = $this->trimResults($response['values']);

    // Pull every existing page from CAPx one by one and merge to the results.
    for ($page = 2; $page <= $response['totalPages']; $page++) {
      $client->setPage($page);
      $response = $client->api('profile')->search("privGroups", $groups);
      if (!isset($response['values']) || !is_array($response['values'])) {
        watchdog("LookupWorkgroupOrphans", "Client response did not return any values. Cannot proceed with workgroup orphan check. %data", array("%data" => serialize($response)), WATCHDOG_ERROR);
        throw new \Exception("Could not fetch workgroups from api in orphan lookup.", 1);
      }
      $trimmed = $this->trimResults($response['values']);
      $results = $results + $trimmed;
    }

    drupal_alter('capx_orphan_profile_results', $results);

    // Loop through the results and unset the profiles from the passed in list.
    foreach ($results as $profileId) {
      unset($profiles[$profileId]);
    }

    // If we have any left over we have profiles that are not in this workgroup.
    $found = array_flip($profiles);

    if (!empty($found)) {
      $orphans['privGroups'] = $found;
    }

    return $orphans;
  }

  /**
   * Trims out bloat from a profile and return only the profileId in an array.
   *
   * @param array $results
   *   An array of results from the API.
   *
   * @return array
   *   An array keyed/valued with profileId => profileId
   */
  private function trimResults($results) {
    $return = array();

    foreach ($results as $profile) {
      $return[$profile['profileId']] = $profile['profileId'];
    }

    return $return;
  }

}
