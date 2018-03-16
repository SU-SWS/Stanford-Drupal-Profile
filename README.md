# [Stanford Sites Jumpstart VPSA](https://github.com/SU-SWS/stanford_sites_jumpstart_vpsa)
##### Version: 7.x-6.0-alpha1

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)  
[Changelog.txt](CHANGELOG.txt)

A Jumpstart site is a pre-packaged website solution, providing a defined package of modules, design layouts, and an easy-to-use, web-based administrative tool for content management. It is hosted on IT Services’ new Stanford Sites Drupal-hosting platform. Jumpstart sites are designed to meet common functional needs of university departments and administrative units in a visually compelling, university-branded design. A set of Stanford-branded theme options are available to choose from. Basic training, user support, and site maintenance are provided.

For more information please visit our website: [Jumpstart Information](https://jumpstart.stanford.edu/products/jumpstart)

Sub Modules:
---

**[iTasks Update](https://github.com/sherakama/itasks)**
This helper module is a requirement of this installation profile. When creating
a new profile you should not have to re-name this sub-module. This module
provides the functionality for being able to run update tasks via the
`drush ipdb` command.

Dependencies:
---

This profile does not have all of it's code bundled inside of it. You will have
to either use a drush.make file to keep track of the contrib and custom modules
used with this installation profile or download them manually.

**Tasks Repo**  
The individual installation tasks can be found in a remote repository. For
example: [https://github.com/sherakama/itasks_tasks](https://github.com/sherakama/itasks_tasks)


Installation
---

This profile is based off of the iTasks installation profile architecture. You can find the original source here: [https://github.com/sherakama/itasks](https://github.com/sherakama/itasks). The install tasks have been abstracted out in to separate files that are located in the libraries folder (or elsewere if configured differently than the defaults). The tasks are separated out in order to share them amoungst multiple installation profiles as well as to provide a way to allow for enviroment specific builds. You can pass in values to the following parameters using drush si:

*Depends on*
[Stanford Install Tasks](https://github.com/SU-SWS/stanford_install_tasks)
Please download and place this repository in the libraries folder if not using the drush.make files.

### Drush Make Options

*install_configure_form.itasks_extra_tasks*
- sites
- anchorage
- local

*install_configure_form.stanford_sites_requester_sunetid*
- The site owner's sunet id

*install_configure_form.stanford_sites_requester_name*
- The site owner's full name

*install_configure_form.stanford_sites_requester_email*
- The site owner's email address.

Example:
drush si stanford_sites_jumpstart
install_configure_form.itasks_extra_tasks=sites -y
install_configure_form.stanford_sites_requester_sunetid=sheamck
install_configure_form.stanford_sites_requester_name="Shea McKinney"
install_configure_form.stanford_sites_requester_email="sheamck@stanford.edu"

## itasks_profile.info

**name**  
The profile name.

**description**  
A short description of this installation profile.

**version**  
The version of the installation profile. Use Drupal naming conventions.

**taskdir**  
The path to the itasks_tasks directory (not this profile). This is relative to the Drupal root so always start with sites/.

**task[install][]**  
The main list of installation tasks. These run in the order they appear unless they have a alter function in them to re-arrange their order. The value of each task declaration must be the full namespace of the install task found in `taskdir`. Do not include .php at the end of the declaration.

**task[new_group][install][]**  
An optional group of install tasks that can be installed on top of or after the main list of installation tasks. This group works with the `drush si` command and the `install_configure_form.itasks_extra_tasks` parameter. The value of this parameter must be the full namespace of the installation task. Do not include .php at the end of the declaration.

**task[update][7100]**  
An optional way to declare update hooks. In the example above 7100 is the update hook as if you were writing hook_update_N. The value of this declaration should be the full namespace to the update task.

**dependencies[]**  
The list of dependencies for this installation profile. Installation tasks can define dependencies as well so although it is not necessary to define all of the dependencies here it is recommended that you do so. In practice it is much harder to find all of the dependencies if they are scattered amongst multiple install task files.  

## itasks_profile.install

This is a regular old .install file and you can find out more information about the hooks available here on Drupal.org: https://www.drupal.org/node/876250

As this profile is meant to abstract most of what you can do in this file it should remain relatively un-used. Please do not add hook_install, hook_update_N or hook_enable to this file.

## itasks_profile.profile

This file contains a bunch of necessary boilerplate code in order to function. Many hooks are used and wrap itasks custom implementations of them. Please do not remove or alter any of the code that has been provided within each function.

Troubleshooting:
---

Tasks that are added to the .info file are autoloaded and should be named and
placed in the appropriate namespace. Please check for typos and case.

Installation tasks can declare dependencies. Look at the ones that are being installed for the any items that are being enabled that you don't want.

Ensure you are using the latest build from the 5.x branch of the [Jumpstart Deployer](https://github.com/SU-SWS/stanford-jumpstart-deployer).
You can use the [Geppetto Project](https://github.com/SU-SWS/stanford_geppetto) to assist in building.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
