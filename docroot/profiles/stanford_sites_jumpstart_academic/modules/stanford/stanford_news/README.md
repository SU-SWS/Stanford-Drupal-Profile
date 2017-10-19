#[Stanford News](https://github.com/SU-SWS/stanford_news)
##### Version: 7.x-3.1

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

Stanford News feature provides an out of the box solution for displaying news content on your website. This feature contains a content type, fields, a news page layout, and taxonomy. This module is a great replacement for the default Article content type.


Sub Modules
---

**[Stanford News Views](modules/stanford_news_views)**
This sub module contains a number of default page and block views for the Stanford News content type. Site administrators can choose to use these views with the Stanford News content type or create their own. Also included is a view that displays Stanford News content in an xml document that other sites could use.

* **Feeds**
The feeds view provides an xml feed of recent news information. This view provides a good way for other sites to gather your news information.

* **2 Item recent news list block**
The 2 item recent news block provides a simple two item list containing a thumbnail, title, and date. No pager on this view block.

* **5 Item news list block with pager**
The 5 item news list block displays the 5 most recent news items in a formatted list. This list contains a thumbnail, title, date, tags, and a short description of the news item with a pager at the bottom.

* **5 Item news list page with pager**
The 5 items news list page is identical to the 5 item list block except for that it is a page with a URL and does not have to be placed as a block.

* **3 Item news list block with page**   r
The three item news list block displays exactly three of the most recent news items in a formatted list. The list contains a thumbnail, title, date, tags, and short description.

* **Manage Content**
This contains a view for the stanford_manage feature. It provides a bulk operation view where content authors can make changes to multiple news items in one task.

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
