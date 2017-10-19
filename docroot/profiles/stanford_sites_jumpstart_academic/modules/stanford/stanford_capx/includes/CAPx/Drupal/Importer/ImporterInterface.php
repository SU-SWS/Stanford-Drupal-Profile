<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer;
use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\APILib\HTTPClient;
use CAPx\Drupal\Entities\CFEntity;

interface ImporterInterface {

  /**
   * A __construct description.
   *
   * @param CFEntity     $importer
   *   [description]
   * @param EntityMapper $mapper
   *   [description]
   * @param HTTPClient   $client
   *   [description]
   */
  public function __construct(CFEntity $importer, EntityMapper $mapper, HTTPClient $client);


}
