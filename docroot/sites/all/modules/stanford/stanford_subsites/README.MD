#[Stanford Subsites](https://github.com/SU-SWS/stanford_subsites)
##### Version 7.x-2.1

Maintainers: [Caryl Westerberg](https://github.com/cjwest), [Shea McKinney](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

This module provides the ability to create a site in a site, sort of. This module is unlike other implementations of subsite like functionality. This subsite module allows content authors to create subsite nodes in which automatically have their own context and menu associated with it. Content editors can select a new logo, title, slogan, and/or theme to go with the subsite node and all other pages within a subsite. Other content types can be added to a subsite by placing them within the menu structure of the subsite or by tagging them with the subsite specific term. 

This module does not provide any sort of editorial permission structure. You may add your own using a contrib module such as Taxonomy Access Control, or Content Access Control.

This module also does not provide any default homepage layouts for each subsite. Those will need to be created manually.

##Install the Stanford Subsites module on your Drupal 7 site

The [Stanford Subsites module can be downloaded from GitHub »] (git@github.com:SU-SWS/stanford_subsites.git)

##Enable Stanford Subsites module using Drush

Run the following Drush command: % drush en stanford_subsites -y

**Note:** Dependencies should be automagically handled.

##Enable Stanford Subsites module from the user interface

1. Click **Modules** and locate the Stanford Subsites module
2. Check the box next to each of the modules to enable them
3. Click **Save configuration**

[See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

##Configure Stanford Subsites module

1. From the administration menu, hover over **Configuration**
2. Click **Subsite Settings**

####Menus

1. **Where is my subsite's menu?** Subsite does not place menus out of the box, you need to configure the module to create a menu block and place it in your region of choice on the Subsite Settings page.
2. **Why is the main menu still appearing on Subsites?** If context or Drupal's native blocks configuration is being used to place the Main Menu throughout the website, that will need to be updated to exclude subsites, with Context you can use the "Active Subsite" Condition and "No Active Subsite" option. Be sure to require all Conditions.

####Building Views Using Contextual Arguments

One of the strengths of Subsites is the ability to create a single view with a contextual filter for the given subsite and place it on all subsite nodes. This feature can be used to create mini-calendars, news blocks, or carousels for all Subsite homepages. 

Configure the contextual filter where content has taxonomy term ID based on the Subsites vocabulary then provide a default value of taxonomy term ID from URL.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
