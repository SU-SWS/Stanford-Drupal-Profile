#[Stanford Courses](https://github.com/SU-SWS/stanford_courses)
##### version: 7.x-4.x

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

Drupal Features module for pulling course information from explorecourses.stanford.edu. Contains a content type for courses, a content type for course importers, a feeds importer, a few default views, and some custom feeds plugins.


Sub Modules
---

**[Stanford Course Views](modules/stanford_course_views)**
A collection of default views for use with the course module. This module should not be enabled when the Stanford Person Reference Views feature is enabled. Included in the views are:

* **Search Courses Page with exposed filter block**
A listing of all courses complete with an exposed filter block that allows users to search, sort, and filter through the list of courses.

* **Current Courses Page**
A listing of all courses that are in progress. This view will only show courses that are active for the current term. All components are included with the exception of Discussion Section (DIS), Independent Study (INS),  Practicum (PRC), and Thesis/Dissertation (T/D).

* **Section Information Block**
The section information block is used when placed on a course node to display a table of section information.

* **Faculty Courses Block**
A listing of courses as taught by an instructor. Requires the Stanford person feature and uses entity references that are manually created.

**[Stanford Course Administration](modules/stanford_courses_administration)**
This module contains a view for the stanford_manage feature. It provides a bulk operation view where content authors can make changes to multiple courses in one task.

**[Stanford Course Link To Page](modules/stanford_courses_link_to_page)**
This is a simple module that changes both the Stanford views and the Stanford person reference views to link to the course node instead of the explore courses entry for that node. It is recommended that you enable the Stanford Courses Node View module in order to have an aesthetically pleasing layout.

**[Stanford Courses Matrix](modules/stanford_courses_matrix)**
Uses [views matrix](https://www.drupal.org/project/views_matrix) module to display course details in a more usable way.

**[Stanford Courses Node View](modules/stanford_courses_node_display)**
This feature module contains a display suite view mode for the Stanford course content type. With out it the course node does not have much structure. If you are planning on using the Stanford Course Link To Page feature you should enable this module as well.

**[Stanford Courses Person Reference](modules/stanford_courses_person_reference)**
The Stanford Courses Person Reference feature adds an entity reference field to the stanford_course content type. This allows content authors to reference stanford_person content types by editing course nodes. It is recommended that when you enable this module that you also enable the Stanford courses person reference views and disable the default course views module.

**[Stanford Courses Person Reference Views](modules/stanford_courses_person_reference_views)**
The person reference views is a replacement set of views for the default course views. When enabled the default course views module should be disabled. Included in this set of views is an extra field for a link to a Stanford Person content type but is otherwise identical to the default course views.

**[Stanford Courses Tag Translate](modules/stanford_courses_tag_translate)**
Adds a field to the course content type that allows for the storage of a human readable version of the explore courses tags. Also, by default, this module alters the course importer to allow you to automatically have the translations.


Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Nothing special needed.

Troubleshooting
---

Pretty URL:
http://explorecourses.stanford.edu/search?view=catalog&academicYear=&page=0&q=BIOE&filter-departmentcode-BIOE=on&filter-coursestatus-Active=on&filter-term-Spring=on

XML URL:
https://explorecourses.stanford.edu/search?view=xml-20140630&academicYear=&page=0&q=BIOE&filter-departmentcode-BIOE=on&filter-coursestatus-Active=on&filter-term-Spring=on

view options: xml-20140630

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
