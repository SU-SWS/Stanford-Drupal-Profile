#[Stanford Date Timepicker](https://github.com/SU-SWS/stanford_date_timepicker)
##### Version: 7.x-1.1

Maintainers: [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

This module overrides the time field on all date_popup fields with a timepicker widget. See [Drupal.org project page](https://www.drupal.org/project/stanford_date_timepicker) for more information.


Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Download
https://github.com/trentrichardson/jQuery-Timepicker-Addon
Put the contents of the "src" directory into the libraries/jquery-ui-timepicker/ folder

Current supported version is 1.4

Final output should be:
sites/all/libraries/jquery-ui-timepicker/jquery-ui-timepicker-addon.js
OR
sites/default/libraries/jquery-ui-timepicker/jquery-ui-timepicker-addon.js


Configuration
---

Set any field to date_popup with a time granularity of at least hours and you will see a timepicker when you click into the time field instead of the default text-only javascript supported option.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
