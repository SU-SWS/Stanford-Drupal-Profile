<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareSunetOrgCodes implements ComparisonInterface {

  /**
   * Find orphans between sunet and orgcode.
   *
   * Compare the orphans identified in the SuNet missing items to the OrgCode
   * Missing items.
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
    if (empty($orphans['uids']) || empty($orphans['orgCodes'])) {
      return $orphans;
    }

    foreach ($orphans['uids'] as $index => $profileId) {
      if (!in_array($profileId, $orphans['orgCodes'])) {
        // Not an orphan.
        unset($orphans['uids'][$index]);
      }
    }

    return $orphans;
  }

}
