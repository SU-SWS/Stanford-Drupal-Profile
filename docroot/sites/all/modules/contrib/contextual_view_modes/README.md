#[Conextual View Modes](https://www.drupal.org/project/contextual_view_modes)
##### Version: 7.x-3.x-dev

Maintainers: [sherakama](https://github.com/sherakama)

Ever want to change the view mode of something based off a context? Well now you can! Contextual view modes adds a context reaction where you can set the view mode of any entity. You can also set the view mode on a per node and per user basis using the node and user ui modules bundled inside.


Sub Modules
---

**Contextual View Modes Nodes**
This sub module provides an interface for selecting a view mode per node. Once
enabled there will be a vertical tab added to all of your node edit forms where
you can select a context and a view mode.

**Contextual View Modes Users**
This sub module provides an interface for selecting a view mode per user. Once
enabled there will be a vertical tab added to all of your user edit forms where
you can select a context and a view mode.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

To use, create a context with your desired condition and then add a 'View Mode'
reaction. Then find the entity and bundle type you wish to alter the view mode
for and select a view mode option from the drop down field.

You can also enable one of the two sub modules to provide more granular support
for your nodes or users. The per node and per user option trumps any view mode
change in the context reaction setting.


Troubleshooting
---

If you are experiencing issues with this module try clearing the caches first.
If the view mode is not being switched try adding the debug reaction to the
context to see if the context is being triggered. If it still is not working
please file a support ticket in the issue queue.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this
module. If you would like to suggest a fix or new functionality you may add a
new issue to the issue queue.

Testing
---
Now with Probo
