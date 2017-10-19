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
class ImportJSVPSABeans extends \ITasks\AbstractInstallTask {

  /**
   * Import JSVPSA BEANs.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // BEANS
    // Fetch JSVPSA Beans.
    $uuids = array(
      '806b3a6e-4225-4ff7-8b8f-d96fd054280a', // Something to add
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e', // Jumpstart Home Page About Block
      'a4b63a55-2626-4591-a952-6db9c3c270fc', // Jumpstart Home Page Announcements Block
      '2066e872-9547-40be-9342-dbfb81248589', // Jumpstart Footer Social Media Connect Block
      '60ecdc50-e649-4433-b936-0228aa32fc55', // Jumpstart Contact Us Postcard
      'b7334d9f-b4d4-48ba-b1b5-e3ec7b9bb100', // Jumpstart Featured Event Block
      'ba352284-7aec-4044-a6dc-7e60441c2ccf', // Jumpstart Home Page In the Spotlight Block
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72', // Jumpstart Footer Optional Block
      '5ee82af2-bfac-4584-a006-a0fb0661af34', // Jumpstart Twitter Block
      '178acfee-6423-4817-af05-5533d2e95e3f', // Jumpstart Location Map Block
      '864a97ac-ecd9-43b8-94be-da553c1e0426', // Jumpstart Footer Contact Block
      'ea19d462-2709-49fa-b521-9052464fd482', // vpsa-helpful-links-footer-block
      '7a2374a1-df7d-45e4-b1be-2fcd68deda77', // vpsa-student-affairs-block
      '6d61755d-538d-4d08-bcd5-1e0be11d28c2', // VPSA Quick Links
      '6d5066df-346a-4a8a-adea-a9c10eff99a7', // VPSA Large About Block
      '58e5c099-5033-4889-a278-6294113fa998', // VPSA Custom Block 1
      '4e9a73f9-716b-469a-a473-84c261ad05ff', // VPSA Custom Block 2
      '3a68f54e-fb65-40ec-ace2-3e9e977c1765', // VPSA Story Telling Block
      'ff9d9ee1-3a23-433b-9d80-d15bb46a466b', // Full Width Banner Short
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







