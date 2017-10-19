<?php
/**
 * @file
 * Date fields processor.
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class DateFieldProcessor extends FieldTypeProcessor {

  protected $dbFormatValue = "date";

  /**
   * Getter function.
   *
   * A switch statement to get the type of date format the field is storing.
   *
   * @param string $type
   *   The name of the type of date the field is storing.
   *
   * @return string
   *   The date type format for reals.
   */
  public function getDBFormat($type) {
    switch ($type) {
      case 'datestamp':
        return date_type_format(DATE_UNIX);

      case 'datetime':
        return date_type_format(DATE_DATETIME);

      case 'date':
        return date_type_format(DATE_ISO);

      case 'array':
        return date_type_format(DATE_ARRAY);

      default:
        return date_type_format(DATE_OBJECT);
    }
  }

  /**
   * Put the data from the CAP API into the field that is being processed.
   *
   * Mangle, fandangle and change the data so that it fits the field's
   * configuration.
   *
   * @param array $data
   *   An array of data from the CAP API.
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
    $return = array();

    $fieldName = $this->getFieldName();
    $fieldInfo = field_info_field($fieldName);
    $columns = array_keys($fieldInfo['columns']);
    $timezone = date_get_timezone_db($fieldInfo['settings']['tz_handling']);
    $format = $this->getDBFormat($this->dbFormatValue);

    foreach ($data as $index => $row) {

      $value = isset($row[0]) ? $row[0] : $row['value'];
      $value2 = isset($row['value2']) ? $row['value2'] : $value;

      $value = strtotime($value);
      $value2 = strtotime($value2);

      // If there is only one value and the key is value then just give up the
      // text. An Array will blow things up. It also looks like entity metadata
      // wrappers expects the value to be an integer when just one. Fucker.
      if (in_array('value2', $columns)) {
        $value = format_date($value, 'custom', $format, $timezone);
        $value2 = format_date($value2, 'custom', $format, $timezone);
      }

      $return['value'][] = $value;
      $return['value2'][] = $value2;
    }

    return $return;
  }

}
