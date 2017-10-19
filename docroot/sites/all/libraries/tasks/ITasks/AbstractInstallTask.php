<?php
/**
 * @file
 * Abstract Task Class
 */

namespace ITasks;

/**
 * Abstract install tasks.
 */
abstract class AbstractInstallTask extends \ITasks\AbstractTask implements \ITasks\InstallTaskInterface {

  protected $displayName;
  protected $display = TRUE;
  protected $installType = "normal";
  protected $installRun = INSTALL_TASK_RUN_IF_NOT_COMPLETED;
  protected $installFunction = "itask_run_install_task";
  protected $description;

  /**
   * Allows for the altering of installation tasks prior to install.
   *
   * @param array $tasks
   *   An array of installation task objects.
   */
  public function installTaskAlter(&$tasks) {
    // You can modify other installation tasks here.
  }

  /**
   * @return string
   */
  public function getDisplayName() {
    if (!empty($this->displayName)) {
      return $this->displayName;
    }

    $className = get_class($this);
    $xp = explode("\\", $className);
    return array_pop($xp);
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

  /**
   * [setDescription description]
   * @param [type] $desc [description]
   */
  public function setDescription($desc) {
    $this->description = $desc;
  }

  /**
   * [getDescription description]
   * @return [type] [description]
   */
  public function getDescription() {
    if (!is_null($this->description)) {
      return $this->description;
    }

    return $this->getMachineName() . ": Missing description";
  }

  /**
   * [form description]
   * @param  [type] $form        [description]
   * @param  [type] &$form_state [description]
   * @return [type]              [description]
   */
  public function form(&$form, &$form_state) {
    return;
  }

  /**
   * [validate description]
   * @return [type] [description]
   */
  public function validate(&$form, &$form_state) {
    // Nothing needed.
  }

  /** [submit description] */
  public function submit(&$form, &$form_state) {
    // Nothing needed.
  }

}
