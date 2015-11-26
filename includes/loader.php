<?php

/**
 * During the early parts of the installation process there is not a good way
 * to include dependencies. So this is why this ugly little guy is here.
 */

$here = dirname(__FILE__);

require_once $here . "/iTasks.php";
// require_once $here . "/AbstractInstallTask.php";
// require_once $here . "/AbstractTask.php";
// require_once $here . "/AbstractUpdateTask.php";
// require_once $here . "/InstallTaskInterface.php";
// require_once $here . "/TaskEngine.php";
