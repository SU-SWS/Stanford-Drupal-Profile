<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartPlus\Install\Content;
/**
 *
 */
class ImportJSPlusNodes extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // NODES.
    // Import types.
    $content_types = array(
      'stanford_event',
      'stanford_event_importer',
      'stanford_news_item',
    );

    // Restrictions.
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      '2efac412-06d7-42b4-bf75-74067879836c',   // Recent News Page
      '6d48181f-7387-40e8-81ba-199de7ede938',   // Courses Page.
      'b10b8889-73b1-4842-8e1b-b8a21120e2d9',   // Past events Page. (Delete after 4.5)
    );

    $importer = new \SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->add_import_content_type($content_types);
    $importer->add_uuid_restrictions($restrict);
    $importer->importer_content_nodes_recent_by_type();

    // JS+ ONLY CONTENT
    $filters = array('tid_raw' => array('41'));  // 41 is term id for JS+
    $view_importer = new \SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $importer->add_uuid_restrictions($restrict);
    $view_importer->import_content_by_views_and_filters();

  }

}







