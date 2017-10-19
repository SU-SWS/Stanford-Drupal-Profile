<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\DrupalCamp\Install\Content;
/**
 *
 */
class ImportDrupalCampNodes extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // JSV ONLY CONTENT - Tid 35 = JSV.
    $filters = array('tid_raw' => array('111'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $view_importer->add_field_processor(array("body" => "\Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->add_field_processor(array("field_s_destination_publish" => "\Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->import_content_by_views_and_filters();

  }

}







