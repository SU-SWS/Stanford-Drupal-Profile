#[Stanford Publication](https://github.com/SU-SWS/stanford_publication)
##### Version: 7.x-2.2-dev

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

The Stanford Publication feature contains a set of features for creating and displaying publications on your website. Included in this feature is a content type, a set of fields, and a collection of views for displaying and listing the publication content.

**Manage Content View**
This contains a view for the stanford_manage feature. It provides a bulk operation view where content authors can make changes to multiple publications in one task.


Sub Modules
---

**[Stanford Publication Common Views](modules/stanford_publication_common_views)**
This sub module was created because of the split between publication views with a person reference and publication views without a person reference. Inside contains a number of reference independant views that can be used on any site with the stanford_publication content type.

* **4 Item publication block with images**
The 4 item publication block with images contains a formatted list of up to four most recent publications. Included in the list is a thumbnail and a title which link to the publication’s page.
* **4 Item most recent publications block**
The 4 most recent publications block contains a formatted list of up to four of the most recent publications. The formatted list contains a title, the author(s), and a publication date. The titles link to to the publication’s page.

**[Stanford Publication Views](modules/stanford_publication_views)**
This sub module contains views that do not use the stanford_person reference field. This module should be enabled only if the Stanford Publication Views With Reference module is disabled as they conflict.

* **21 Item Publication Page**
The 21 item publication page contains a formatted list of publication items in a page view. The formatted list displays an image, title, publication year, author, and publication date. The publication list is sorted by the most recent publication and uses a pager to navigate to older items.
* **14 Item Publication Page Block**
The 14 item publication page block contains a formatted list of publication items in a block. The formatted list contains a thumbnail, title, author, and publication date.

**[Stanford Publication Views With Reference](modules/stanford_publication_views_reference)**
This sub module contains publication views with references to stanford_person content types. These views provide clickable authors that take the end user to the stanford_person’s profile page. This module should not be enabled if the Stanford Publication Views module is enabled as they conflict.

* **Person Block**
The person block contains a block view that displays a simple list of publications that are related to a Stanford Person. This block should be placed on a Stanford Person content type page.
* **Landing Page**
The landing page view contains a formatted list of publications. This page can be found at /publications when the module is enabled. The formatted list of publications contain a thumbnail, author(s), author link(s), title, and publication date.
* **Search Page**
The publication search page provides a page view that allows end users to search through a list of publications by a number of exposed filters. End users can filter by title, author, and type. The formatted list contains a thumbnail, title, author(s), author link(s), and a publication date.
* **Landing Block**
The landing block view is identical to the landing page view except that is a block instead of a page view.
* **Group by Type Block**
The group by type block is similar to the landing page and search pages but groups the list of publications by publication type. The formatted list of publications display a thumbnail, title, author(s), author link(s), date, and publication type.
* **Small Block**
The small block displays up to four publications with a view more publications link that sends the end user to the publications landing page. The formatted list of publications display a thumbnail, title, author(s), author link(s), and date. The view is sorted by the first four publications.
* **Most Recent Block**
The most recent block is identical to the Small Block view except that it displays the four most recent publications.


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
