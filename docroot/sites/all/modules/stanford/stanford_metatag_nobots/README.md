#[Stanford Metatag Nobots](https://github.com/SU-SWS/stanford_metatag_nobots)
##### Version: 7.x-3.1

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

This module prevents search engine robots from crawling and indexing a website while it is still in development. This module should only be enabled if you do not want your website to indexed. Please disable this module when a site is ‘live’.

Simple Drupal Features module blocking search engine robots from indexing a site
via the X-Robots-Tag HTTP header.

See https://developers.google.com/webmasters/control-crawl-index/docs/robots_meta_tag
for more information on that HTTP header.

To use: enable the Feature. This will check the User Agent string of the client
that is accessing your website. If the User Agent is one of the common search engine
bots (Google, Yahoo!, Bing, Baidu), it will return the following header:

X-Robots-Tag:noindex,nofollow,noarchive

This will block robots from crawling your website.

You probably will want to disable this module before launching a site.

To test if it's working, you can use curl to specify the user agent string:

    curl -A Googlebot -I https://foo.stanford.edu/

The HTTP headers will be written to stdout

Or, if you want to be more fancy:

    curl -sS -A Googlebot -I https://foo.stanford.edu/ | grep 'X-Robots'

That should output "X-Robots-Tag: noindex,nofollow,noarchive" if the headers are being sent correctly.


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
