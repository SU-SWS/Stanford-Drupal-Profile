Description
-----------
Adds a new condition to the context module that allows performing regular
expression tests on the useragent string ($_SERVER['HTTP_USER_AGENT']). This
allows adding different reactions based on the user's browser, operating system,
or other needed contexts that may be found in the useragent string.

Requirements
------------
Drupal 6.x
Context 3.0 or higher

Installation
------------
1. Copy the entire context_useragent directory the Drupal sites/[all]/modules
   directory

2. Login as an administrator. Enable the module in "Administration" -> "Modules"

3. (Optional) Enable the context_useragent_default module which will provide you
   with some default contexts.

4. Create a new context at admin/structure/context and select the "Useragent
   string" condition to test it out.
     a. Strings should be regular expressions, no token replacement is
        currently available, without forward slashes surrounding them.
        Example: Chrome\/\d would test for Chrome/[0-9]
     b. Set any reaction you would like to be triggered by the condition and
        save.

5. (Optional) If you enabled the context_useragent_default module you will
   notice a number of new contexts available at admin/structure/context.  View
   the source of any page to see the new body classes added to your pages
   by these contexts and start using them to conditionally style your site for
   specific browsers.
   Example: <body id="pid-node" class="...linux firefox fx-3...">
     CSS Usage: body.fx-3 #yay{color:blue;}

Support
-------
Please use the issue queue for filing bugs with this module at
http://drupal.org/project/issues/context_useragent
