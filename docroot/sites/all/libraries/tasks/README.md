# iTasks Installation Tasks  
_A collection of small chunks of code._

Used in conjunction with the [iTasks installation profile](https://github.com/sherakama/itasks) to provide granular installation tasks.

Theory
---

Do one thing. And do it well! The concept behind this collection of code is to do one thing per file. This way the amount of change any one thing has is minimal. A smaller footprint will help with encapsulation and decoupling.

This collection of code should be sharable and re-usable. Keeping tasks well named and namespaced will help to reduce duplication of effort and collisions as multiple parties contribute to the shared code bank.

Creating a new namespace
---
When creating a new namespace for your installation profile be unique. An
organization name, url, or group might help. For us at Stanford we have many
sub groups and created a many level namespace:
Eg: Stanford\WebServices\Jumpstart\JumpstartAcademic

This namespace would be for Stanford's Web Services group's Jumpstart Academic
distribution from the Jumpstart distribution line.

Please follow PSR-4 naming conventions: http://www.php-fig.org/psr/psr-4/


Creating a new install task
---

Please follow PSR-4 naming conventions: http://www.php-fig.org/psr/psr-4/

Install tasks should always be placed in an `Install` folder and then named
descriptively. Install task files should always be named the same as the class
name. The class should always extend \ITasks\AbstractInstallTask. The AbstractInstallTask
class is found in the installation profile and not in this repository. Each
install task has one required method called `execute`. Please see the boilerplate
code below.

```
<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Organization\Group\Project\Install;

class MyInstallTaskName extends \ITasks\AbstractInstallTask {

  /**
   * Description of execute method.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Enable user picture support and set the default to a square thumbnail option.
    variable_set('user_pictures', '1');
  }

  /**
   * A list of requirements.
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
```

Creating a new update task
---

Please follow PSR-4 naming conventions: http://www.php-fig.org/psr/psr-4/

Update tasks should always be placed in an `Update` folder and then named
descriptively. Update task files should always be named the same as the class
name. The class should always extend \ITasks\AbstractUpdateTask. The AbstractUpdateTask
class is found in the installation profile and not in this repository. Each
update task has one required method called `execute` and should include a
$description variable. Please see the boilerplate code below.

```
<?php
/**
 * @file
 * Abstract Task Class.
 */
namespace Organization\Group\Project;
/**
 *
 */
class MyUpdateTask extends \ITasks\AbstractUpdateTask {

  // Description of update task.
  protected $description = "Change the site name to my new site name";

  /**
   * Description of execute task.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    variable_set("site_name", "My New Site Name IS: " . md5(time()));
  }

}
```

Installation Task Anatomy
---

### Variables

**$displayName**  
string  
The name displayed during installation through the UI

**$display**  
bool  
Wether to display the name in the UI or not.

**$installType**  
string  
See type: https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_install_tasks/7.x

**$installRun**  
int  
See run: https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_install_tasks/7.x

**installFunction**  
string  
Has to be "itasks_run_install_task"  

**description**
text  
A description of what the install tasks is doing. Currently does not show up
anywhere but there are future plans to use it.

### Methods

**execute(&$args)**  
REQUIRED
The passed in $args is an array of installation task args that would normally be
available to the install task. See: https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_install_tasks/7.x

This is the meat of the whole class. Add your specific functionality here.

**requirements()**  
Returns an array of module machine names that are dependencies of this install task.

**getMachineName()**  
Returns the machine name of this task.

**setMachineName()**  
Sets the machine name of this task.

**InstallTasksAlter(&$tasks)**  
The passed in parameter is an array of installation tasks. This function allows
tasks to alter the array of installation tasks. This means they can change the
order, add, or remove tasks conditionally.

**getDisplayName()**  
Returns the value of $displayName or the classname if undefined.

**getInstallDisplay()**  
Returns the value of $display.

**getRunType()**  
Returns the value of $installRun.

**getInstallType()**  
Returns the value of $installType.

**getInstallFunction()**  
Returns the value of $installFunction.

**setDescription($desc)**  
Sets the value of $description with the passed in value.

**getDescription()**  
Returns the value of $description or default text if not set.

**form()**  
Return form elements to add to the installation configuration form. This form is
used through the UI and should be the place to supply your variables. These form
elements are available to drush through the parameter:
installation_configuration_form.element_name=something_value

**validate()**  
Validation hook for the installation configuration form method.

**submit()**  
Submit hook for the installation configuration form method.
