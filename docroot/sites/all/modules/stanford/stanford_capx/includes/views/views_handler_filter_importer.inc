<?php

/**
 * @file
 * Definition of views_handler_filter_importer
 */

use CAPx\Drupal\Util\CAPxImporter;

/**
 * Filter by Importer type.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_importer extends views_handler_filter_in_operator {
  function get_value_options() {

    if (!isset($this->value_options)) {
      $this->value_title = t('Importer');
      $importers = CAPxImporter::loadAllImporters();
      $options = array();
      foreach ($importers as $index => $info) {
        $options[$info->machine_name] = t($info->title);
      }
      asort($options);
      $this->value_options = $options;
    }

  }
}
