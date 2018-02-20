<?php

namespace Stanford\JumpstartLab\Install\CAPx;

use \ITasks\AbstractInstallTask;

/**
 * Class CAPxConfig.
 */
class CAPxConfigChange extends AbstractInstallTask {

  /**
   * Configure CAPx.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    db_update('capx_cfe')
      ->fields(array(
        'machine_name' => 'labs_default',
        'title' => t('LABs Default'),
      ))
      ->condition('machine_name', 'jse_default')
      ->execute();
    $importer_settings = db_select('capx_cfe', 'c')
      ->fields('c', array('cfid', 'settings'))
      ->condition('type', 'importer')
      ->execute();
    while ($importer = $importer_settings->fetchAssoc()) {
      $settings = $importer['settings'];
      $settings = unserialize($settings);
      $settings['mapper'] = 'labs_default';
      db_update('capx_cfe')
        ->condition('cfid', $importer['cfid'])
        ->fields(array('settings' => serialize($settings)))
        ->execute();
    }

  }

}
