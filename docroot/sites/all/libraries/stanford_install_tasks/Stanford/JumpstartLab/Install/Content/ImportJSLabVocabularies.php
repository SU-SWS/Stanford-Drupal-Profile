<?php

namespace Stanford\JumpstartLab\Install\Content;

use \ITasks\AbstractInstallTask;

/**
 * Class ImportJSLabVocabularies.
 *
 * @package Stanford\JumpstartLab\Install\Content
 */
class ImportJSLabVocabularies extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // Restrictions.
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      // Tags vocabulary.
      'tags',
      // Products vocabulary.
      'sites_products',
    );

    // Vocabularies.
    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->addRestrictedVocabularies($restrict);
    $importer->importVocabularyTrees();

  }

}







