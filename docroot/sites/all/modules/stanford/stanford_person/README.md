#[Stanford Person](https://github.com/SU-SWS/stanford_person)
##### Version: 7.x-5.2-dev

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

The Stanford Person feature is used to create pages for real life people. In this feature includes a content type, a carefully chosen set of fields, a page layout, a taxonomy, and a set of views. This content type can be used as a way to associate people with other types of content, such as Stanford Publications.


Sub Modules
---

**[Stanford Person Reference]()**
This module provides the Stanford Person entity reference field. By default an instance of this field is created on Stanford Publications but it may be added to other content types.

**[Stanford Person Views]()**
This module provides a collection of views that work with the Stanford Person content type.

* **Faculty Page**
The faculty page provides a list of formatted faculty stanford_person nodes. The page is found at /people/faculty and will display all faculty people. The formatted list contains a thumbnail, title, position title, address, phone number, email, and office hours. This view contains a number of exposed filters where end users can filter down options.

* **Faculty Block - Ajax**
The faculty ajax block is identical to the faculty page but in a block form. Along with the block comes a set of ajax powered exposed filters that allow end users to filter down options.

* **Faculty Block**
The faculty block is identical to the Faculty Ajax block except that it does not contain any exposed filters.

* **Manage Content**
This contains a view for the stanford_manage feature. It provides a bulk operation view where content authors can make changes to multiple persons in one task.

* **People Page**
The people page provides a view of all stanford_person nodes sorted by last name and first. The people page has an exposed title filter where users can filter down the results by the person’s name.

* **Staff Page**
The staff page provides a list of formatted staff stanford_person nodes. The page is found at /people/staff and will display all staff people. The formatted list contains a thumbnail, title, position title, address, phone number, and email. This view contains a number of exposed filters where end users can filter down options.

* **Staff Block**
The staff block is identical to the staff page view except that it is in a block and must be placed on to a page as other blocks are.

* **Staff Page: Group by type**
This view page is identical to the Staff page except that the formatted list is grouped by staff type.

* **Student Page**
The student list view page provides a list of formatted student stanford_person nodes. This view can be found at /people/students and will list all of the student nodes without a pager.

* **Student Block**
The student block view is identical to the student page view except that is a block instead of a page.

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
