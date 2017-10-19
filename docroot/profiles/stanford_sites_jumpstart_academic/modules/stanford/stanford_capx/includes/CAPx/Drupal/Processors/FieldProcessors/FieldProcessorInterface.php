<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

interface FieldProcessorInterface {

  /**
   * One entry point for them all!
   * @param  array $data Data from the CAP API.
   */
  public function put($data);

}
