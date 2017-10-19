<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;
use CAPx\Drupal\Mapper\EntityMapper;

abstract class ProcessorAbstract implements ProcessorInterface {

  protected $mapper;
  protected $data;
  protected $entityImporter;
  protected $status = 0;
  protected $statusMessage = "";

  /**
   * construction method
   * @param $mapper EntityMapper
   *   The mapper.
   * @param $data  array
   *   An array of cap data
   */
  public function __construct($mapper, $data) {
    $this->setMapper($mapper);
    $this->setData($data);
  }

  // ===========================================================================
  // GETTERS & SETTERS
  // ===========================================================================

  /**
   * Getter function
   * @return array an array of CAP API data.
   */
  protected function getData() {
    return $this->data;
  }

  /**
   * Setter function
   * @param array $data an array of CAP API information.
   */
  protected function setData(Array $data) {
    $this->data = $data;
  }

  /**
   * Getter function
   * @return EntityMapper A configured and loaded EntityMapper instance.
   */
  public function getMapper() {
    return $this->mapper;
  }

  /**
   * Setter function
   * @param EntityMapper $map A configured and loaded EntityMapper instance.
   */
  public function setMapper($map) {
    $this->mapper = $map;
  }

  /**
   * Setter function
   * @param EntityImporter $porter A configured EntityImporter instance.
   */
  public function setEntityImporter($porter) {
    $this->entityImporter = $porter;
  }

  /**
   * Getter function
   * @return EntityImporter A configured EntityImporter instance.
   */
  public function getEntityImporter() {
    return $this->entityImporter;
  }

  /**
   * [setStatus description]
   * @param [type] $int     [description]
   * @param [type] $message [description]
   */
  protected function setStatus($int, $message) {
    $this->status = $int;
    $this->setStatusMessage($message);
  }

  /**
   * [getStatus description]
   * @return [type] [description]
   */
  public function getStatus() {
    return $this->status;
  }

  /**
   * [setStatusMessage description]
   * @param [type] $message [description]
   */
  protected function setStatusMessage($message) {
    $this->statusMessage = $message;
  }

  /**
   * [getStatusMessage description]
   * @return [type] [description]
   */
  public function getStatusMessage() {
    return $this->statusMessage;
  }

}
