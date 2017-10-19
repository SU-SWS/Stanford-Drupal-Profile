<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartVPSA\Install\Content;
/**
 *
 */
class ImportJSVPSANodes extends \ITasks\AbstractInstallTask {

  /**
   * Import JSVPSA Nodes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // All RECENT CONTENT.
    $content_types = array(
      // 'stanford_event', removed in order to allow for specific tagging.
      'stanford_news_item',
      'stanford_slide',
      'stanford_person',
    );

    $importer = new \SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->add_field_processor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $importer->add_field_processor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));

    // Tell the importer what is what.
    $importer->add_import_content_type($content_types);

    // Calling this imports the 20 most recent of each content type.
    $importer->importer_content_nodes_recent_by_type();

    // JSVPSA ONLY CONTENT: tid 39 = JSVPSA.
    $filters = array('tid_raw' => array('39'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $view_importer->add_field_processor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->add_field_processor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->import_content_by_views_and_filters();

  }

}







