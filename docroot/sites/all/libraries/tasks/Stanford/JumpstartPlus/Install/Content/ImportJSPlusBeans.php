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
class ImportJSPlusBEANs extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // BEANS
    $uuids = array(
      'e813c236-7400-4f43-ad18-736617ceb28e', // Jumpstart Home Page Banner Image.
      '8c4ed672-debf-45a5-8dfc-ef42794b975b', // Jumpstart Homepage Tall Banner
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e', // Jumpstart Home Page About Block
      'b880d372-ef1c-4c85-93e8-6a47726d98c2', // Jumpstart Postcard with Video
      '2066e872-9547-40be-9342-dbfb81248589', // Jumpstart Footer Social Media Connect Block
      'ba352284-7aec-4044-a6dc-7e60441c2ccf', // Jumpstart Home Page In the Spotlight Block
      '864a97ac-ecd9-43b8-94be-da553c1e0426', // Jumpstart Footer Contact Block
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72', // Jumpstart Footer Optional Block
      'd643d114-c4bc-47b0-b0df-dbf1dc673a1a', // Jumpstart Info Text Block
      'f00c9906-971f-4d9d-b75c-23db1499318c', // Jumpstart Homepage Mission Block
      '008d2300-a00d-4de9-bdce-39f7bc9f312d', // Jumpstart Homepage Mission Block 2
      '7c1bdc2c-cd07-4404-8403-8bdbe7ebc9bb', // Jumpstart Homepage Testimonial Block
      '68d11514-1a52-4716-94b4-3ef0110e75b2', // Jumpstart Lead Text With Body
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746', // Announcements
    );

    $importer = new \SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->set_bean_uuids($uuids);
    $importer->import_content_beans();

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'bean',
      'bean_admin_ui',
    );
  }

}







