#[Stanford Sites Jumpstart Plus](https://github.com/SU-SWS/stanford_sites_jumpstart_plus)
##### Version: 7.x-5.0

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

A Jumpstart site is a pre-packaged website solution, providing a defined package of modules, design layouts, and an easy-to-use, web-based administrative tool for content management. It is hosted on IT Services’ new Stanford Sites Drupal-hosting platform. Jumpstart sites are designed to meet common functional needs of university departments and administrative units in a visually compelling, university-branded design. A set of Stanford-branded theme options are available to choose from. Basic training, user support, and site maintenance are provided.

For more information please visit our website: [Jumpstart Plus Information](https://jumpstart.stanford.edu/products/jumpstart-plus)

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
drush si stanford_sites_jumpstart_plus
install_configure_form.itasks_extra_tasks=sites -y
install_configure_form.stanford_sites_requester_sunetid=sheamck
install_configure_form.stanford_sites_requester_name="Shea McKinney"
install_configure_form.stanford_sites_requester_email="sheamck@stanford.edu"

Troubleshooting
---

Ensure you are using the latest build from the 5.x branch of the [Jumpstart Deployer](https://github.com/SU-SWS/stanford-jumpstart-deployer).
You can use the [Geppetto Project](https://github.com/SU-SWS/stanford_geppetto) to assist in building.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
