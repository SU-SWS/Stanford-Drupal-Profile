<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Content;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class ImportJSVPSAVocabularies extends AbstractInstallTask {

  /**
   * Import JSVPSA Vocabularies and terms.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // Restrictions
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      'tags',              // tags vocabulary
      'sites_products',    // products vocabulary
      'news_categories',   // news categories
    );

    // Vocabularies.
    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->addRestrictedVocabularies($restrict);
    $importer->importVocabularyTrees();

  }

}
