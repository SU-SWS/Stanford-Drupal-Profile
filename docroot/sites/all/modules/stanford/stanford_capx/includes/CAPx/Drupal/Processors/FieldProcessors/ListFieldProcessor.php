<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class ListFieldProcessor extends FieldTypeProcessor {

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
    $fieldInfo = field_info_field($fieldName);
    $allowed = $fieldInfo['settings']['allowed_values'];
    $flipped = array_flip($allowed);
    $keys = array_keys($allowed);
    $return = array();

    foreach ($data as $column => $values) {
      foreach ($values as $value) {
        $bad_value = TRUE;

        if (in_array($value, $allowed)) {
          $return[$column][] = $flipped[$value];
          $bad_value = FALSE;
        }
        else {
          // Lets simplify key matching for booleans.
          if ($fieldInfo['type'] == 'list_boolean') {
            $value = ((bool) $value) ? 1 : 0;
          }
          if (in_array($value, $keys)) {
            $return[$column][] = $value;
            $bad_value = FALSE;
          }
        }

        if ($bad_value) {
          // @todo: Do we really want to log this?
          // Keep in mind that log will be polluted.
          $this->logIssue(new \Exception(t('Received not allowed value.')));
        }


      }
    }

    return $return;
  }

}
