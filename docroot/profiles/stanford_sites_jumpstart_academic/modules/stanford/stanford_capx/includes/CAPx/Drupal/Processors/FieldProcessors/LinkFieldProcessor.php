<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class LinkFieldProcessor extends FieldTypeProcessor {

  /**
   * Default implementation of put.
   *
   * @see FieldProcessorAbstract::put()
   */
  public function put($data) {
    $data = $this->prepareData($data);
    parent::put($data);
  }

  /**
   * Prepares CAP API data to feet to Drupal field.
   *
   * @param array $data
   *   CAP API field data.
   *
   * @return array
   *   Prepared data.
   */
  public function prepareData($data) {
    foreach ($data as $column => $values) {
      foreach ($values as $delta => $value) {

        if (!is_string($value)) {
          $data[$column][$delta] = '';
          // @todo: Do we really want to log this?
          // Keep in mind that log will be polluted.
          $this->logIssue(new \Exception(t('Received not allowed value, expecting string got %type.', array('%type' => gettype($value)))));
        }

        // If autotruncating is enabled lets do that here. This is to help
        // avoid issues when trying to map data to the API.
        if (variable_get("stanford_capx_autotruncate_textfields", TRUE)) {

          $maxlength = 2048; // Default for url.

          // Title has custom setting.
          if ($column == "title") {
            $info = field_info_field($this->fieldName);
            $maxlength = $info['settings']['title_maxlength'];
          }

          if (strlen($value) > $maxlength) {
            $data[$column][$delta] = substr($value, 0, $maxlength);
          }
        }

      }
    }

    return $data;
  }

}
