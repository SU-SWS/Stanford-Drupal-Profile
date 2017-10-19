<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Lookups;

class LookupMissingFromApi implements LookupInterface {

  /**
   * Checks the API server to see if the item still exists.
   *
   * @param EntityImporterOrphans $orphaner
   *   The orphan processor object.
   *
   * @return array
   *   The remaining orphans
   */
  public function execute($orphaner) {
    $resultIds = array();
    $results = $orphaner->getResults();
    $profiles = $orphaner->getProfiles();
    $orphans = $orphaner->getOrphans();

    // There are no results no need to continue. Keep the orphans the same.
    if (empty($results)) {
      return $orphans;
    }

    // Gather up the profileIds of the request results.
    foreach ($results as $index => $profile) {
      $resultIds[] = $profile['profileId'];
    }

    // Compare the results to the profiles we are looking for.
    $found = array_diff($profiles, $resultIds);
    // Allow alter.
    drupal_alter("capx_find_sunet_orphans", $found);

    if (!empty($found)) {
      $orphans['missing'] = $found;
    }

    return $orphans;
  }


}
