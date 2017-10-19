<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;
use CAPx\Drupal\Mapper\EntityMapper;

interface ProcessorInterface {

  /**
   * Constructor function
   * @param $mapper  A fully loaded and configured EntityMapper instance.
   * @param Array  $capData An array of information from the CAP API.
   */
  public function __construct($mapper, $capData);

  /**
   * One way street.
   * @return [type] [description]
   */
  public function execute();

   /**
   * Returns an integer of status meaning.
   *
   * @return int
   *   An integer from 1 -> N
   */
  public function getStatus();

  /**
   * Returns a message about the execution.
   *
   * Returns a string in plain english what happened with the execution.
   * @return string
   *   A message in plain english.
   */
  public function getStatusMessage();

}
