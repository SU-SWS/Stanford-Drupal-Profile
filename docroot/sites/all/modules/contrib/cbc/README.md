#Contextual Block Class(es)
This module provides the ability to contextualize block classes. This module is similar to [contexual_block_class module](https://drupal.org/project/context_block_class) and complements the [block class module](https://drupal.org/project/block_class).
## Version
Drupal Core: 7.X

Release Version 7.x-1.0-alpha1

##Installation:
Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

##Configuration:
1. Create a context with any set of conditions. admin/structure/context/add
2. Add the "Administer Contextual Block Classes" permission to the appropriate roles. admin/people/permissions
3. Edit or create a new block. admin/structure/block/add
4. Find the contextual block class(es) collapsible fieldset and expand it.
5. Enter css classes without a period and separated by spaces into the context of choice. eg: 'clearfix header-one third-class'
6. Save block and place into a theme region.
