<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Lookups;

class LookupMissingFromSunetList implements LookupInterface {

  /**
   * Find orphans by looking at the result set and the sunets that we have
   * entered into the sunet option on the importer.
   *
   * @param EntityImporterOrphans $orphaner
   *   The orphan processor object.
   *
   * @return array
   *   The remaining orphans
   */
  public function execute($orphaner) {

    $orphans = $orphaner->getOrphans();
    $options = $orphaner->getImporterOptions();

    // Check to see if there is something to run on.
    if (!in_array("uids", $options['types'])) {
      return $orphans;
    }

    $orphans['uids'] = array();
    $results = $orphaner->getResults();
    $profiles = $orphaner->getProfiles();
    $orphans = $orphaner->getOrphans();
    $ids = explode(",", $options['sunet_id']);
    $ids = array_map('trim', $ids);
    $found = array();

    $sunetIds = array();
    foreach ($results as $index => $profile) {
      $sunetIds[$profile['profileId']] = $profile['uid'];
    }

    // Loop through the profiles looking for ids. If we cannot find one in the
    // list of ids then we have an orphan.
    foreach ($profiles as $index => $profileId) {
      $sunet = $sunetIds[$profileId];
      if (!in_array($sunet, $ids)) {
        $found[$sunetIds[$profileId]] = $profileId;
      }
    }

    if (!empty($found)) {
      $orphans['uids'] = $found;
    }

    return $orphans;
  }

}
