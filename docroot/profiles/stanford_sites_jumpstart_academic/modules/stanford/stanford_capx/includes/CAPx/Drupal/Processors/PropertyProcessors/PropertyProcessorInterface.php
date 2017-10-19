<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\PropertyProcessors;

interface PropertyProcessorInterface {

  /**
   * One way in. No way out!
   * @param  [type] $data [description]
   * @return [type]       [description]
   */
  public function put($data);

}
