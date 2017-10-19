# Context List Module

This module provides a means for inspecting all the contexts created with the Context module. It is intended to help inspect the state and usage of the contexts.

## Usage

You can find the context list as a tab on the main context page:

    admin/structure/context/contexts_list

## Development

The module has a few hooks in place that allow developers to create new display plugins. Display plugins are used to convert a condition or reaction into what is displayed on the context lists. The module currently ships with a few defacto plugins that should cover most needs.

### Condition Plugins

* **all**: `ContextListConditionDisplay`,
* **defaultcontent**: `ContextListConditionDisplay_defaultcontent`
* **path**: `ContextListConditionDisplay_path`

### Reaction Plugins

* **all**: `ContextListReactionDisplay`
* **block**: `ContextListReactionDisplay_block`
* **region**: `ContextListReactionDisplay_region`

### Creating New Plugins

Plugins are PHP classes that live in `context_list.plugins.inc`. You can extend the existing classes to create new displays and support new modules.

Each plugin has a `display()` method that is used to change the settings and condition/reaction into the output on the context list. After your new class is created, you need to implement `hook_context_list_register_condition_display` or `hook_context_list_register_reaction_display` to register your class(es). There is only one display class per reaction/condition.

## Hooks

There are a few hooks:

* hook_context_list_register_condition_display: registers a condition display plugin
* hook_context_list_register_reaction_display: registers a reaction display plugin
* hook_context_list_reaction_block_name: alters the block name
* hook_context_list_reaction_blocks: alters the blocks available to a reaction plugin
* hook_context_list_reaction_theme_name: alters the theme name
