<?php
/**
 * @file
 * Configure CAPx importers
 */

namespace Stanford\JumpstartEngineering\Install\CAPx;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class CAPxConfig extends AbstractInstallTask {

  /**
   * Configure CAPx.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Loop through the mapper settings and save to the DB.
    $mappers = $this->get_capx_mappers();
    foreach ($mappers as $machine_name => $settings) {
      $mapper = entity_create('capx_cfe', array());
      $mapper->uid = 1;
      $mapper->title = $settings['title'];
      $mapper->machine_name = $machine_name;
      $mapper->type = "mapper";
      $mapper->settings = $settings;
      // Do the save.
      capx_mapper_save($mapper);
    }

    // Loop through the importer configurations and save them to the db.
    $importers = $this->get_capx_importers();
    foreach ($importers as $machine_name => $info) {
      $settings = $info['settings'];
      $meta = $info['meta'];
      $importer = entity_create('capx_cfe', array());
      $importer->type = "importer";
      $importer->machine_name = $machine_name;
      $importer->title = $info['title'];
      $importer->uid = 1;
      $importer->settings = $settings;
      $importer->meta = $meta;
      // Do the save.
      capx_importer_save($importer);
    }

  }

  /**
   * Verify function on wether this can be run.
   *
   * @return bool
   *   True for passes verification.
   */
  public function verify() {
    // Check to see if the items already exist.
    $machine_names = array('default', 'jse_default');
    $q = db_select('capx_cfe', 'cfe');
    $q->addField('cfe', 'machine_name');
    $q->condition('cfe.machine_name', $machine_names, 'IN');
    $r = $q->execute()->fetchObject();

    if ($r) {
      drush_log('jse capx config already imported', 'error');
      return FALSE;
    }

    // Pass. No previous config.
    return TRUE;
  }


  /**
   * Returns an array of mapper information to be used to save to the db.
   *
   * @return array
   *   An array of mapper information.
   */
  private function get_capx_mappers() {
    $mappers = array();
    // Default Mapper.
    $mappers['default'] = array(
      'fields' => array(
        'field_s_person_affiliation' => array(
          'tid' => '',
        ),
        'field_s_person_cohort' => array(
          'value' => '',
        ),
        'field_s_person_dissertatn_title' => array(
          'value' => '',
        ),
        'field_s_person_education' => array(
          'value' => '$.education.*.label.text',
        ),
        'field_s_person_email' => array(
          'email' => '$.primaryContact.email',
        ),
        'field_s_person_faculty_title' => array(
          'value' => '$.longTitle[0]',
        ),
        'field_s_person_faculty_type' => array(
          'tid' => '',
        ),
        'field_s_person_fax_display' => array(
          'value' => '$.primaryContact.fax',
        ),
        'field_s_person_file' => array(
          0 => '',
        ),
        'field_s_person_first_name' => array(
          'value' => '$.names.preferred.firstName',
        ),
        'field_s_person_graduation_year' => array(
          'value' => '',
        ),
        'field_s_person_info_links' => array(
          'url' => '',
          'title' => '',
        ),
        'field_s_person_interests' => array(
          'tid' => '',
        ),
        'field_s_person_last_name' => array(
          'value' => '$.names.preferred.lastName',
        ),
        'field_s_person_mail_address_dspl' => array(
          'value' => '$.primaryContact.address',
        ),
        'field_s_person_mail_code' => array(
          'value' => '',
        ),
        'field_s_person_middle_name' => array(
          'value' => '',
        ),
        'field_s_person_office_hours' => array(
          'value' => '',
        ),
        'field_s_person_office_location' => array(
          'value' => '',
        ),
        'field_s_person_phone_display' => array(
          'value' => '',
        ),
        'field_s_person_profile_picture' => array(
          0 => '',
        ),
        'field_s_person_staff_type' => array(
          'tid' => '',
        ),
        'field_s_person_student_type' => array(
          'tid' => '',
        ),
        'field_s_person_study' => array(
          'tid' => '',
        ),
        'field_s_person_weight' => array(
          'value' => '',
        ),
        'field_s_person_profile_link' => array(
          'url' => '$.meta.links[1].href',
          'title' => '',
        ),
        'body' => array(
          'value' => '',
          'summary' => '',
        ),
      ),
      'properties' => array(
        'title' => '$.displayName',
      ),
      'collections' => array(),
      'entity_type' => 'node',
      'bundle_type' => 'stanford_person',
      'multiple' => 0,
      'subquery' => '',
      'guuidquery' => '',
      'title' => t("Default"),
    );
    // JSE Default.
    $mappers["jse_default"] = array(
      'fields' => array(
        'field_s_person_affiliation' => array(
          'tid' => '',
        ),
        'field_s_person_cohort' => array(
          'value' => '',
        ),
        'field_s_person_dissertatn_title' => array(
          'value' => '',
        ),
        'field_s_person_education' => array(
          'value' => '$.education.*.label.text',
        ),
        'field_s_person_email' => array(
          'email' => '$.primaryContact.email',
        ),
        'field_s_person_faculty_title' => array(
          'value' => '$.titles.*.label.text',
        ),
        'field_s_person_faculty_type' => array(
          'tid' => '',
        ),
        'field_s_person_fax_display' => array(
          'value' => '$.primaryContact.fax',
        ),
        'field_s_person_file' => array(
          0 => '',
        ),
        'field_s_person_first_name' => array(
          'value' => '$.names.preferred.firstName',
        ),
        'field_s_person_graduation_year' => array(
          'value' => '',
        ),
        'field_s_person_info_links' => array(
          'url' => '$.internetLinks.*.url',
          'title' => '$.internetLinks.*.label.text',
        ),
        'field_s_person_interests' => array(
          'tid' => '',
        ),
        'field_s_person_last_name' => array(
          'value' => '$.names.preferred.lastName',
        ),
        'field_s_person_mail_address_dspl' => array(
          'value' => '$.primaryContact.address',
        ),
        'field_s_person_mail_code' => array(
          'value' => '',
        ),
        'field_s_person_middle_name' => array(
          'value' => '$.names.preferred.middleName',
        ),
        'field_s_person_office_hours' => array(
          'value' => '',
        ),
        'field_s_person_office_location' => array(
          'value' => '',
        ),
        'field_s_person_phone_display' => array(
          'value' => '$.primaryContact.phoneNumbers.*',
        ),
        'field_s_person_profile_picture' => array(
          0 => '$.profilePhotos.square',
        ),
        'field_s_person_staff_type' => array(
          'tid' => '',
        ),
        'field_s_person_student_type' => array(
          'tid' => '',
        ),
        'field_s_person_study' => array(
          'tid' => '',
        ),
        'field_s_person_weight' => array(
          'value' => '',
        ),
        'field_s_person_profile_link' => array(
          'url' => '$.meta.links[1].href',
          'title' => '',
        ),
        'body' => array(
          'value' => '$.bio.text',
          'summary' => '',
        ),
      ),
      'properties' => array(
        'title' => '$.displayName',
      ),
      'collections' => array(),
      'entity_type' => 'node',
      'bundle_type' => 'stanford_person',
      'multiple' => 0,
      'subquery' => '',
      'guuidquery' => '',
      'title' => t("JSE Default"),
    );
    return $mappers;
  }

  /**
   * Returns an array of importer configuration information.
   *
   * @return array
   *   An array of importer configuration information.
   */
  private function get_capx_importers() {
    $importers = array();
    // Default.
    $importers['default'] = array();
    $importers['default']['title'] = t("Default");
    $importers['default']['settings'] = array(
      'mapper' => 'jse_default',
      'organization' => '',
      'child_orgs' => 0,
      'workgroup' => '',
      'sunet_id' => '',
      'cron_option' => 'none',
      'cron_option_day_number' => '1',
      'cron_option_day_week' => 'monday',
      'cron_option_month' => '0',
      'cron_option_hour' => '2:00',
      'orphan_action' => 'unpublish',
    );
    $importers['default']['meta'] = array();
    return $importers;
  }
}
