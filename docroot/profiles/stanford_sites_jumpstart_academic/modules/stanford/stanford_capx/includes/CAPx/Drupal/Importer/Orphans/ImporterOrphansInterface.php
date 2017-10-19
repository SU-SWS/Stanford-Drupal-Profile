<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans;
use CAPx\Drupal\Importer\EntityImporter;

interface ImporterOrphansInterface {

  /**
   * [__construct description]
   * @param [type] $importer [description]
   * @param [type] $profiles [description]
   */
  public function __construct(EntityImporter $importer, Array $profiles, Array $lookups, Array $comparisons);

  /**
   * [batch description]
   * @return [type] [description]
   */
  public function batch();

  /**
   * [queue description]
   * @return [type] [description]
   */
  public function execute();

  /**
   * [addLookup description]
   * @param [type] $lookup [description]
   */
  public function addLookup($lookup);

  /**
   * [addComparison description]
   * @param [type] $comparison [description]
   */
  public function addComparison($comparison);

}
