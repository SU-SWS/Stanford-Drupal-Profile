<?php
/**
 * @file
 * Import JSE nodes.
 */

//use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
//use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartEngineering\Install\Content;
/**
 *
 */
class ImportJSENodes extends \ITasks\AbstractInstallTask {

  /**
   * Import JSE Nodes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // This could take a while.
    drupal_set_time_limit(600);

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");
    $filters = array('tid_raw' => array('55'));

    $view_importer = new \SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $view_importer->add_field_processor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->add_field_processor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->import_content_by_views_and_filters();

  }

}







