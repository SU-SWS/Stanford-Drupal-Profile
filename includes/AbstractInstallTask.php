<?php
/**
 * @file
 * Abstract Task Class
 */

abstract class AbstractInstallTask extends AbstractTask {

  protected $displayName = "";
  protected $display = TRUE;
  protected $installType = "normal";
  protected $installRun = INSTALL_TASK_RUN_IF_NOT_COMPLETED;
  protected $installFunction = "itask_run_install_task";

  /**
   * @return string
   */
  public function getMachineName() {
    return "machine_name";
  }


  /**
   * @return string
   */
  public function getDisplayName() {
    return $this->displayName;
  }

  /**
   * @return bool
   */
  public function getInstallDisplay() {
    return $this->display;
  }

  /**
   * @return int
   */
  public function getRunType() {
    return $this->installRun;
  }

  /**
   * @return string
   */
  public function getInstallType() {
    return $this->installType;
  }

  /**
   * @return string
   */
  public function getInstallFunction() {
    return $this->installFunction;
  }

}
