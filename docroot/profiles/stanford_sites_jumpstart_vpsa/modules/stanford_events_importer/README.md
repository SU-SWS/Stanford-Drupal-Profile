#[Stanford Events Importer](https://github.com/SU-SWS/stanford_events_importer)
##### Version: 7.x-3.3-jsvpsa

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

The Stanford Events Importer provides custom functionality for importing from events.stanford.edu XML feeds. A new feed API is available that is customized to work with this importer. It is available at: http://events.stanford.edu/xml/drupal/v2.php
(See [http://events.stanford.edu/xml/](http://events.stanford.edu/xml/) for more information on feeds.)

It gives the following:
* A content type "Stanford Event Importer", which allows you to create a content node of this type to import each feed you wish
* A content type of "Stanford Event". Nodes of this type are created by the "Stanford Event Importer" nodes when using "Import".

The imported items are set to refresh once every 24 hours, and to update (rather than replace) existing nodes.


Sub Modules
---

**[Stanford Events & Deadline Calendar](modules/stanford_event_and_deadline_calendar)**
Driven by the design of the Undergrad website, this feature will provide a calendar view and additional event views.  The events will live at the calendar but use taxonomy to display on subsites.

**[Stanford Events Export](modules/stanford_events_export)**
The Stanford Events Export module contains Views that expose Stanford Event content as JSON and XML data. Useful in combination with the Stanford Drupal Events Importer module to migrate Stanford Event content from one Drupal site
to another.

**[Stanford Events Views](modules/stanford_events_views)**
This module provides default Views for use with the Stanford Events Importer module.

* **Manage Events Page**
This contains a view for the stanford_manage feature. It provides a bulk operation view where content authors can make changes to multiple events in one task.
* **Events Calendar Page (month/day/year)**
This view contains pages for viewing events by month, day, or year.
* **Upcoming Events Block**
The upcoming events block displays a formatted list of 5 upcoming events.
* **5 Item Upcoming Events List Page**
The upcoming events list page display a formatted list of the next 5 upcoming events with a pager option. The formatted list contains a title, image, date, and location.
* **5 Item Upcoming Events List Block**
The upcoming events list block displays a formatted list of the next 5 upcoming events with a pager.
* **2 Item Upcoming Events List Block**
The two item upcoming events list block displays a formatted list of the next 2 upcoming events. This view contains a title, date, and location.
* **Upcoming Feed**
The upcoming events list feed is an xml feed of events data. This is a good way for other sites to pull event information from your website.
* **5 Item Past Events List (block)**
This block provides a formatted list of past events. The five most recent past events are displayed with a pager at the bottom of the list. This view allows users to view recently completed events.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Nothing special needed.

External Dependencies
---
This module can be used as a standalone, but works best when integrated with events.stanford.edu.
Information on events.stanford.edu (event listings, category and organization information, etc.) is updated daily on the following schedule:
* 8am
* Noon
* 4pm
* 8pm

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
