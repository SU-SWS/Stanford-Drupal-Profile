<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

class TaxonomyTermFieldProcessor extends FieldTypeProcessor {

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
   * @inheritdoc
   */
  public function repackageJsonDataForDrupal($data, $fieldInfo) {
    $data = parent::repackageJsonDataForDrupal($data, $fieldInfo);
    foreach ($data as $k => $v) {
      $data[$k] = $v['tid'];
    }
    return $data;
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
    $vocabulary = taxonomy_vocabulary_machine_name_load($fieldInfo['settings']['allowed_values'][0]['vocabulary']);
    $return = array();

    foreach ($data as $column => &$values) {

      // Loop through the values.
      foreach ($values as $key => $value) {

        // Handle an array of terms.
        if (is_array($value)) {
          $values = $values + $value;
          unset($values[$key]);
          continue;
        }

        // Sometimes the term name is the key.
        $termName = trim($value);
        if (is_bool($value)) {
          $termName = trim($key);
        }

        // Even here it is possible to have a comma separated list of terms.
        if (is_string($termName)) {
          $count = explode(",", $termName);
          if (count($count) > 1) {
            $values = $values + $count;
            unset($values[$key]);
            continue;
          }
        }
      }

      // You cannot add to an iterator in the middle of iterating and expect it
      // to iterate over the new items.
      foreach ($values as $key => $value) {
        // Sometimes the term name is the key.
        $termName = trim($value);
        if (is_bool($value)) {
          $termName = trim($key);
        }

        $ensured = $this->ensureTerm($termName, $vocabulary);

        if (is_bool($value) && !$value) {
          continue;
        }

        $return[$column][] = $ensured;
      }

    }

    return $return;
  }

  /**
   * Ensures that term exists.
   *
   * @param string $name
   *   Term name.
   * @param object $vocabulary
   *   Vocabulary to search term in.
   *
   * @return int
   *   Term ID.
   */
  public function ensureTerm($name, $vocabulary) {
    $terms = taxonomy_get_term_by_name($name, $vocabulary->machine_name);
    $term = array_shift($terms);

    if (empty($term->tid)) {
      // Term not found, create and save a new term.
      $term = new \stdClass();
      $term->name = trim($name);
      $term->description = '';
      $term->vid = $vocabulary->vid;
      taxonomy_term_save($term);
    }

    return $term;
  }

}
