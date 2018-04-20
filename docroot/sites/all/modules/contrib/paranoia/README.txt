Description:
===========
Paranoia module is for all the sysadmins out there who think that
allowing random CMS admins to execute PHP of their choice is not
a safe idea.

What it does:
=============
- Disable the PHP module.
- Disable granting of the "use PHP for block visibility" permission.
  Save the permissions form once to remove all previous grants.
  (An error appears in the site status report if a role still has this
  permission.)
- Disable granting to Anonymous or Authenticated any permission that is
  marked "restrict access" in a module's hook_permission.
- Disable granting several permissions from popular contribs that are not
  marked as "restrict access" but are still important.
- Remove the PHP and paranoia modules from the module admin page.
- Provides a hook to let you remove other modules from the module admin page.


Using the feature to scramble the password for stale accounts
=============================================================
Paranoia includes a feature to scramble the password of an account that has not
logged in for a while. This feature uses a queue so that it can scalably handle
scrambling the password of thousands of accounts. The "scramble" does not set a
new password. It sets the password to an invalid string which will
always fail when compared to any user input. To use this feature:

1. Navigate to /admin/config/system/paranoia to configure how many days an
   account must be inactive before it's password will be scrambled. Also
   choose whether or not to email users letting them know their password was
   reset.

2. Use the Drush command to queue up accounts to be marked as stale:

  drush -v paranoia-reset-stale-accounts

3. Run the queue to process the stale expirations:

  drush -v queue-run paranoia_stale_expirations

Using the -v option on drush will show extra information about the operations.

You can also let cron handle processing the queue, though that may take a long time.

NOTE on disabling:
=====
The only way to disable paranoia module is by changing its status in the
database system table.  By design it does not show up in the module
administration page after it is enabled. You can also disable it with drush:

drush dis paranoia

Support
=======
View current issues:
http://drupal.org/project/issues/paranoia
Submit a new issue:
http://drupal.org/node/add/project-issue/paranoia

Development
===========
All development happens in branches like 7.x-1.x and 6.x-1.x

Maintainers
======
Gerhard Killesreiter
Greg Knaddison @greggles
