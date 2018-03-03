#[Stanford Related Content](https://github.com/SU-SWS/stanford_related_content)
##### Version: 7.x-1.0-dev

Maintainers: [cjwest](https://github.com/cjwest)
[Changelog.txt](CHANGELOG.txt)

The Related Content feature is a Drupal Features module for displaying aggregated content. It allows you to create relationships between different content and can display this related content on a single page. Contains a taxonomy, Related Content; and a term reference field to be added to an entity.

Sub Modules
---
These modules add functionality needed to make the related content function. For each content type you'd like to include, enable the corresponding module.

* [stanford_related_courses](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_courses) - TBD
- [stanford_related_events](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_events)
- [stanford_related_news](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_news)
- [stanford_related_page](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_page)
- [stanford_related_person](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_person)
- [stanford_related_publication](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_publication) - TBD


Installation
---
When enabling the submodules (listed above) check that the dependencies are met, since each submodule depends on one or more other Stanford feature modules. To install [stanford_related_person](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_person), for example:

1. Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)
2. Install and enable [Stanford Person](https://github.com/SU-SWS/stanford_person/tree/7.x-5.x-dev) along with the submodule [Stanford Person Grid View](https://github.com/SU-SWS/stanford_person/tree/5.x-grid-view/modules/stanford_person_grid_view)
3. Enable [Stanford Related Content](https://github.com/SU-SWS/stanford_related_content) and [Stanford Related Person](https://github.com/SU-SWS/stanford_related_content/tree/7.x-1.x/modules/stanford_related_person)


Configuration
---

In order to understand and create relationships with Related Content, there are a few planning considerations to make. As conceived, Related Content relationships can be presented on any “page” that is created with the “Stanford Page” content type.  This page serves as the one-to-many relationship that presents the aggregated content.  The “many” content comes from other content types - currently, news, events, and people - that will be presented as abbreviated block lists on the presentation page. In order to create the relationship, a vocabulary of “related content” taxonomy terms must be defined and selected in both the target and aggregate content nodes.



Upon installation of the related content feature module, there will be three key additions that site owners should be aware of:

1. A “Related Content” vocabulary taxonomy list is created but requires filling in of terms. These terms will be specific to your site.
2. Once the terms are defined, new checkboxes are added to the news, events, and person node edit form allowing you identify content to aggregate by selecting terms from the Related Content vocabulary.
3. Similarly, Related Content checkboxes are also added to the Stanford Page content type node edit form. When editing a Stanford Page you can select terms that will add related content to the page display of for that node.
Here are the steps to use Related Content:

###Add terms to the Related Content vocabulary###
1. From the **Site Actions** menu, select **Manage Taxonomies**
2. Select the **Related Content** vocabulary
3. If the vocabulary terms are there, proceed to the next section otherwise, select **Add**
4. Type your terms into the text area, one per line
5. Scroll down and select **Add** again
6. When the page refreshes, check that you entered the new terms properly

###Identify your target page for related content###
1. Navigate to the page (or select from the **Manage All Content** list) that you wish to have display related content. Your target page must be a [Stanford Page](https://github.com/SU-SWS/stanford_page) type node.
2. Select **Edit**
3. On the edit form, scroll down until you see **Related Content**
4. Select one term that you wish to match and aggregate to this page
5. Scroll to the bottom of the edit form and select **Save**

###Tag your content###
To tag your content, you will select the same terms on all the pieces of related content.

1. Navigate to the piece of content you would like to include
2. Select *Edit*
3. On the edit form, scroll down until you see **Related Content**
4. Select all terms that apply to this page
5. Scroll to the bottom of the edit form and select **Save**

###Check your results###
Navigate to the page on which the content is to display and verify it is now displaying as expected.

Troubleshooting
---
If you're having trouble with having events display, check the dates on those events and make sure that they are upcoming.

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)


