<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareSunetWorkgroups implements ComparisonInterface {

  /**
   * Compare sunet orphans with orgcode orphans.
   *
   * Check to see if our missing sunet options are in an org group by checking
   * to see if the org group has the same missing profile id.
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

    // If either orphan group is empty we cannot continue.
    if (empty($orphans['uids']) || empty($orphans['privGroups'])) {
      return $orphans;
    }

    foreach ($orphans['uids'] as $index => $profileId) {
      if (!in_array($profileId, $orphans['privGroups'])) {
        // Not an orphan.
        unset($orphans['uids'][$index]);
      }
    }

    return $orphans;
  }

}
