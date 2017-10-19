#[Stanford Simple SAML PHP Auth](https://github.com/SU-SWS/stanford_ssp)
##### Version: 7.x-2.1-dev

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

This module is a fork of the contrib module: https://www.drupal.org/project/simplesamlphp_auth. It was being patched so heavily that we decided to adopt it.

The simplesamlphp_auth module makes it possible for Drupal to support SAML for authentication of users. The module will auto-provision user accounts into Drupal if you want it to. It can also dynamically assign Drupal roles based on identity attribute values.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

PREREQUISITES
---

1) You must have SimpleSAMLphp installed and configured as a working service
   point (SP) as the module uses your local SimpleSAMLphp SP for the SAML
   support. For more information on installing and configuring SimpleSAMLphp as
   an SP visit: http://www.simplesamlphp.org.

   IMPORTANT: Your SP must be configured to use something other than phpsession
   for session storage (in config/config.php set store.type => 'memcache'
   or 'sql').

   To use memcache session handling you must have memcached installed on your
   server and PHP must have the memcache extension. For more information on
   installing the memcache extension for PHP visit:
   http://www.php.net/manual/en/memcache.installation.php

   If you are on a shared host or a machine that you cannot install memcache on
   then consider using the sql handler (store.type => 'sql').

Configuration
---

The configuration of the module is fairly straight forward. You will need to know the names of the attributes that your SP will be making available to the module in order to map them into Drupal.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

The most common reason for things not working is the SP session storage type is still set to phpsession.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
