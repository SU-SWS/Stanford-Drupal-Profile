# Stanford CAPx
#### Version 3.0-beta1

Stanford CAP Extensible module builds on some great work. This module provides an interface for administrators to pull information directly from the CAP API into Drupal. This allows profile owners to continue to manage their profile information on the CAP web service and have that information automatically reflected into a Drupal website.

## What is CAP?

CAP Network is a virtual workspace, originally created by the School of Medicine, to support collaboration among faculty, graduate students, postdocs and staff. In 2013, it was expanded in partnership with various Schools, Institutes, and administrative offices to create the Stanford Profiles website.

Combining a profile directory with a social networking backend, CAP makes it easy for you to work closely with colleagues and track the projects that matter most to you—all in a private, secure environment

* [profiles.stanford.edu](https://profiles.stanford.edu)
* [cap.stanford.edu](https://cap.stanford.edu/)

## Installation

Install this module like [any other Drupal module](https://www.drupal.org/documentation/install/modules-themes/modules-7).

## Authentication

Before you get started you will need to have authentication credentials. To get authentication credentials, [file a HelpSU request](https://helpsu.stanford.edu/helpsu/3.0/auth/helpsu-form?pcat=CAP_API&dtemplate=CAP-OAuth-Info) to Administrative Applications/CAP Stanford Profiles.

## Configuration

For detailed documentation on the configuration and usage of this module, please see the [Docs section](./docs/).

## Developer

[GitHub](https://github.com/SU-SWS/stanford_capx) page.
Collaboration and bug reports are welcome. Please file bug reports on the github issues page. You are also welcome to suggest new functionality in the way of a pull request.

Also included in this package is a module called: capx_issue_collector. If you enable this module you will have a 'report feedback' button added to the bottom right hand corner of your website. This will allow you to post feedback directly to our Jira instance.

### Security
#### HTTPS
CAPx uses https for all API calls. Please follow this best practice as you develop with this module.
#### httpoxy mitigation:
In July 2016, the httpoxy security exploit was announced for PHP, including libraries such as Guzzle. CAPx installs were by default protected because of https usage (see above). In addition, **developers are encouraged to seek their own httpoxy mitigation steps at the server level**. Check with your hosting provider to ensure that your implementation is protected from httpoxy. See https://httpoxy.org for details.

## Credits

* Trellon, for the [original CAP module](https://github.com/Stanford/CAP_drupal) and all the problems they solved. A great amount of inspiration and information was used from this module.
* Kenneth Sharp, for his work on CAP lite and for his contributions to functionality.
* Zach Chandler, for his vision and direction.
* Stanford Web Services, for putting all the pieces together.
* CAP working group for all of their invaluable feedback and time spent.
* Brendan Walsh and the Office of International Affairs, for their sponsorship funding this module.
* Darryl Dieckman, for all his hard work and support on the API.
