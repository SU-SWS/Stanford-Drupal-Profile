# [Stanford Private Page](https://github.com/SU-SWS/stanford_private_page)
##### Version: 7.x-2.0-alpha3

Maintainers: [cynmij](https://github.com/cynmij) and [cjwest](https://github.com/cjwest)

[Changelog.txt](CHANGELOG.txt)

This module provides a content type (Stanford Private Page) that incorporates the Stanford Image Field Collection and file upload. It is essentially the same as the Stanford Page except it is designed to provide pages within a site that can restrict viewing.
Using the Content Access module, this feature allows the site administrator to use permissions to limit the roles that can view and edit the private pages.

Sub Modules
---

### Stanford Private Page Access
Provides the configuration settings for content access. This limits access to private pages by role. On installation this rebuilds the permissions.

### Stanford Private Page administration
A manage content feature which provides an administration page where users can view, sort, search, and filter through Stanford Private Page content.

### Stanford Private Page Section
Provides the context and menus to support a private section.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

You can configure settings at admin/stanford/private-page. Here you can:
* indicate whether or not a message displays on the private page
* set the message that displays on the private page

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
