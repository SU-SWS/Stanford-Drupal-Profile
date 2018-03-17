#[Stanford Bean Types](https://github.com/SU-SWS/stanford_bean_types)
##### Version: 7.x-2.8

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

This module provides default BEAN types. Contained in this feature are the Stanford Banner, Stanford Contact, Stanford Large Block, Stanford Postcard, and Stanford Social Media Connect beans. Site administrators can create any number of these Bean blocks and place them on their site.

**Stanford Banner**
This bean type provides a block with the ability to create image banners. Users can add an image, credits, source information, and a caption.

**Stanford Call-to-action**
This bean type provides a block with a background image, icon, title, and link.

**Stanford Contact**
This bean type provides a uniform and easy to edit contact block. Users can add an address, fax, phone number, email address, and a number of links. When placed using a Stanford theme end users will see a nicely formatted address block.

**Stanford Large Block**
For larger amounts of content than a traditional side-bar block, this block is also used in larger spaces. Use this when content spans 8 columns. You can insert files and images into your body content. There is no header image.

**Stanford Postcard**
The basic building block of the bean types, this block allows users a lot of flexibility as it has options for image upload, links, and wysiwyg content.

**Stanford Social Media Connect**
This block provides a group of social media icons that link to your social media pages. Included in the options are: Facebook, Twitter, GooglePlus, LinkedIn, YouTube, Vimeo, Tumblr, Pinterest, Instagram, and Flickr.

**Stanford Large Text Block**
Needs Description.

**Stanford Testimonial Block**
Needs Description.


Sub Modules
---

**[Stanford Bean Types Permissions](https://github.com/SU-SWS/stanford_bean_types/tree/7.x-2.x-dev/modules/stanford_bean_types_permissions)**
Stanford Bean Type Permissions modules provides some out of the box permissions that may be installed through an installation profile as it is dependant on the Stanford Bean Types module. This module may be safely disabled and overridden through the permissions setting page.

**[DS Bean Fields](https://github.com/SU-SWS/stanford_bean_types/tree/7.x-2.x-dev/modules/ds_bean_fields)**
Display suite handling of the title field in BEAN types.

**[Stanford Call To Action](https://github.com/SU-SWS/stanford_bean_types/tree/7.x-2.x-dev/modules/stanford_bean_types_call_to_action)**
Stanford Call To Action modules provide a Bean type that can be used for call to action blocks (with the ability to add an image and a Font Awesome icon overlay). After installing and enabling the module, follow these steps to complete setup:

1. Navigate to Stanford Call to Action blocks at **admin/structure/block-types/manage/stanford-call-to-action/display**.
2. Enable Full Content display setting.
3. Select the One Column layout.
4. Navigate to the Full Content display.
5. Move fields and field groups to be placed in the following order:
* ex. (Link group (Image Style (Image, Icon), Title Style (Title)))
6. Save


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
