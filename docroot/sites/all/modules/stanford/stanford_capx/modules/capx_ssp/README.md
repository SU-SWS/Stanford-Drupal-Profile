#[CAPx SSP](https://github.com/SU-SWS/stanford_capx)
##### Version: 7.x-3.0-dev

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

Usage
---

Enable this module to allow user entities that are created with CAPx to log in with the `stanford_ssp` authentication module.
It allows user entities to be pre-populated from CAP (e.g., with additional fields) prior to having the user authenticate via SSO.

1. Enable `capx_ssp`
2. Import a user profile
3. Have the user log in via stanford_ssp at `/sso/login`
4. The user's `uid` is the same as the user entity that was imported via CAPx.

Limitations
---
If the user's email address is not public in [StanfordYou](https://stanfordyou.stanford.edu), `capx_ssp` will set the email address of the _Drupal_ user to `sunetid@stanford.edu`. This may not match the user's preferred email address.


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
