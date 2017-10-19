<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareOrgCodesWorkgroups implements ComparisonInterface {

  /**
   * Check to see if any of the orphans in the organization groups are in a
   * workgroup.
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

    // If both workgroup and organizations are selected we need to see that the
    // orphan is missing from both and the sunet is not in the ids.
    if (empty($orphans['orgCodes'])) {
      return $orphans;
    }

    // Loopy loop.
    foreach ($orphans['orgCodes'] as $index => $profileId) {
      // Scenario: Orphan in orgCodes but not privGroups.
      if (isset($orphans['privGroups']) && !in_array($profileId, $orphans['privGroups'])) {
        // Not an orphan. Remove it.
        unset($orphans['orgCodes'][$index]);
      }
    }

    return $orphans;
  }

}
