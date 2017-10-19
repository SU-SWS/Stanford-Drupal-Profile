<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;
use CAPx\Drupal\Processors\FieldProcessors\FieldProcessorAbstract;


class FieldTypeProcessor extends FieldProcessorAbstract {

  /**
   * Constructor function
   * @param Entity $entity    The entity with the field being worked on.
   * @param String $fieldName the name of the field to be worked on.
   * @param String $type      The type of the field being worked on.
   */
  public function __construct($entity, $fieldName, $type = null) {
    parent::__construct($entity, $fieldName, $type);
  }


  /**
   * Default implementation of widget function.
   * Provides an alter and returns self.
   * @param  string $type
   * @return FieldTypeProcessor
   */
  public function widget($type) {
    $widget = $this;
    drupal_alter('capx_field_type_processor_widget', $widget, $type);
    return $widget;
  }

}
