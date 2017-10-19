<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartAcademic\Install\Content;
/**
 *
 */
class ImportJSAcademicNodes extends \ITasks\AbstractInstallTask {

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
      'stanford_event_series',
      'stanford_event',
      'stanford_event_importer',
      'article',
      'stanford_person',
      'stanford_publication',
      'stanford_news_item',
      'stanford_course',
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

    // JSA ONLY CONTENT.
    $filters = array('tid_raw' => array('33'));  // 33 is term id for jsa
    $view_importer = new \SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $importer->add_uuid_restrictions($restrict);
    $view_importer->import_content_by_views_and_filters();

  }

}







