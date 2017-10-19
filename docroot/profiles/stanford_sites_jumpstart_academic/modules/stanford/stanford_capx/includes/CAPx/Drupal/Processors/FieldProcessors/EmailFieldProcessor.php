<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class EmailFieldProcessor extends FieldTypeProcessor {

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
      }
    }

    return $data;
  }

}
