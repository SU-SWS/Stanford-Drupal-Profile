# [Stanford News Extras Importer](https://github.com/SU-SWS/stanford_news)
##### Version: 7.x-3.2-dev

Stanford News Extras Importer feature provides an out of the box solution for importing news content on your website. This feature requires fields from the Stanford News Extras feature


Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

This module uses fields from the Stanford News Extras module which will need to be configured when the feature is installed. These fields include:

* **Organization Link**
Entity reference to other organizations

* **Research Theme**
Taxonomy of research areas

* **School Theme**
Taxomomy of school news related themes

* **Department**
Taxomomy of departments

Example use
-----
To import a feed, create a news importer node with fields:

URL: https://engineering.stanford.edu/news/xml
XPATH Parser: //news/news-item

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
