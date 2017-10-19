<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Lookups;

class LookupMissingMultipleByGUUID implements LookupInterface {

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
    $results = $orphaner->getResults();
    $profiles = $orphaner->getProfiles();
    $importer = $orphaner->getImporter()->getMachineName();
    $mapper = $orphaner->getImporter()->getMapper();
    $guuidquery = $mapper->getGUUIDQuery();
    $parts = explode(".", $guuidquery);
    $subquery = "$.." . array_pop($parts);
    $remoteGUUIDs = $mapper->getRemoteDataByJsonPath($results, $subquery);
    $localInfo = $this->getLocalGUUIDs($profiles, $importer);
    $localGUUIDs = array_keys($localInfo);
    $diff = array_diff($localGUUIDs, $remoteGUUIDs);

    // No orphans. Yay.
    if (empty($diff)) {
      return array();
    }

    // New column for the comparisons.
    $orphans = array('multiple' => array());
    foreach ($diff as $key => $guuid) {
      $orphans['multiple'][] = $localInfo[$guuid]->entity_id;
    }

    return $orphans;
  }

  /**
   * @param $profileIDs
   * @param $importerMachineName
   */
  protected function getLocalGUUIDs($profileIDs, $importerMachineName) {
    $or = db_or()->condition('profile_id', $profileIDs);
    $results = db_select("capx_profiles", "cxp")
      ->fields('cxp', array('entity_id', 'guuid'))
      ->condition($or)
      ->condition("importer", $importerMachineName)
      ->execute()
      ->fetchAllAssoc('guuid');
    return $results;
  }

}
