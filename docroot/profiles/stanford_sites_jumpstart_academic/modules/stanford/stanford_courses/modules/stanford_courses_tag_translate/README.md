#[Stanford Courses Tag Translate](https://github.com/SU-SWS/stanford_courses)
##### Version: 7.x-4.0

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

This module has a plugin for allowing direct string replacement from a table
in the database. It is primarily used on the new field in this module. The new
field is appended to stanford_course content types to allow for a translation
between the tags that come from explorecourses.stanford.edu and the end user.

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Go to `admin/config/stanford/courses/tag-translate` and click on either the
New tag translation link or the Import tab to get started. Once a there are a
few options available they should appear in the list with an edit and delete
link.

*Importing:*

When importing tags be aware that it will fully replace what is currently in the
database with what is being imported. The import must be a valid json object
with key pairs where the key is the tag from explorecourses.stanford.edu and the
value is the human readable version.

e.g.:

```
{
  "course::tag": "Course Tag",
  "other::tag": "Another tag"
}
```


Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
