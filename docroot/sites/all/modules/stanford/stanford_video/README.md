#[Stanford Video](https://github.com/SU-SWS/stanford_video)
##### Version: 7.x-2.2

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)
[Changelog.txt](CHANGELOG.txt)

This module creates a custom content type that uses the JWPlayer video player for playing streaming video hosted by Stanford Video (http://stanfordvideo.stanford.edu/streaming), and integrating captions provided by the Stanford Office of Accessible Education's Caption Tool (http://captioning.stanford.edu).

Installation
---

Install as you would with any other Drupal contributed module. This module requires the JWPlayer Javascript library; download it from http://www.longtailvideo.com/jw-player/download/ and place it in sites/all/libraries.

Configuration
---

* Create a new video node at node/add/stanford-video
* You can upload videos directly (.flv, .mp3, .mp4, .m4v, .webm) and attach captions (.srt, .dfxp, .xml)
* You also can stream videos from an RTMP streamer; the URL for the Stanford Video streaming server is provided by default
** For more information on streaming video hosting through Stanford Video, visit http://stanfordvideo.stanford.edu/streaming
** For more information on creating caption files for videos, visit http://captioning.stanford.edu
* You also can embed videos from third-party providers (YouTube, Vimeo, etc.) by pasting the embed code into the "External Video Embed" field
** This field relies on the "Full HTML" text format. You should only grant access to that text format to trusted users and roles.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)


KNOWN ISSUES
------------
The JW Player captions plugin is not compatible with the Firefox "HTTPS Everywhere" plugin.
Captions will not display if you have this Firefox plugin enabled.
