<?php
/**
 * @file
 * This function rebuilds the node access database.
 */

namespace Stanford\Utility\Install;
use \ITasks\AbstractInstallTask;

/**
 * Rebuild the node access database.
 */
class NodeAccessRebuild extends AbstractInstallTask {


  public function execute(&$args = array()) {

    node_access_rebuild();
  }

}
