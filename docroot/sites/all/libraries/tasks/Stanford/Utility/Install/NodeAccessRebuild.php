<?php
/**
 * @file
 * This function rebuilds the node access database.
 */

namespace Stanford\Utility\Install;

/**
 * Rebuild the node access database.
 */
class NodeAccessRebuild extends \ITasks\AbstractInstallTask {


  public function execute(&$args = array()) {

    node_access_rebuild();
  }

}

