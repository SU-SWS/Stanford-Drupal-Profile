#[Stanford Jumpstart](https://github.com/SU-SWS/stanford_jumpstart)
##### Version: 7.x-4.5

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

The Stanford Jumpstart module provides custom functionality for the [Stanford Jumpstart Product](https://github.com/SU-SWS/stanford_sites_jumpstart). It has a collection of sub modules that assist the installation profile during installation as well as provide run time functionality.


Sub Modules
---

**[Stanford Jumpstart Layouts](modules/stanford_jumpstart_layouts)**
This module contains a number of contexts that provide page layout options for the home page and internal pages.

**[Stanford Jumpstart Roles](modules/stanford_jumpstart_roles)**
This module contains a number of default user roles. Included in the roles are the ‘site owner’ and ‘editor’ roles.

**[Stanford Jumpstart Permissions](modules/stanford_jumpstart_permissions)**
This module contains a number of default permissions. This module is dependant on the roles provided in stanford_jumpstart_roles

**[Stanford Jumpstart Shortcuts](modules/stanford_jumpstart_shortcuts)**
This module provides a shortcuts bar of menu options to the top of the page for those users with the correct permissions. In the menu are links to commonly used administrative tasks. Also included in this module is a special cache clearing function that is provided to the roles in the jumpstart roles feature.

**[Stanford Jumpstart Site Actions](modules/stanford_jumpstart_site_actions)**
A complimentary module to the Stanford Jumpstart Shortcuts module that places additional items into the site actions menu that are specific to only Jumpstart.

**[Stanford Jumpstart WYSIWYG](modules/stanford_jumpstart_wysiwyg)**
This module contains the default configuration and input formats for all WYSIWYG fields.


Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Nothing special needed.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
