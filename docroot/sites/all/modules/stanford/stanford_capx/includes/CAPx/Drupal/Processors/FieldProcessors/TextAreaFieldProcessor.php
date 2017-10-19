<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class TextAreaFieldProcessor extends FieldTypeProcessor {

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
    $fieldName = $this->getFieldName();
    $entity = $this->getEntity();
    $entityType = $entity->type();
    $bundle = $entity->getBundle();
    $fieldInstance = field_info_instance($entityType, $fieldName, $bundle);
    $process = isset($fieldInstance['settings']['text_processing']) ? $fieldInstance['settings']['text_processing'] : FALSE;
    $format = variable_get('stanford_capx_default_field_format', 'filtered_html');

    if ($process) {
      foreach ($data as $column => $values) {
        foreach ($values as $delta => $value) {
          $data['format'][$delta] = $format;
        }
      }
    }

    return $data;
  }

}
