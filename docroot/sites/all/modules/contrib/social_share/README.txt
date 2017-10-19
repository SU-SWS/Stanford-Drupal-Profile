README.txt
==========

Social Share adds configurable social network share links to nodes

Links can be added for these social networks:
 - Facebook
 - Twitter
 - Google Buzz
 - Myspace
 - MSN Live
 - Yahoo
 - Linked In
 - Orkut
 - Digg

Links are added to all nodes of the types configured to allow it, and appear
with a class name based on the social network being shared to.

Example:

<a class="social-share-facebook" href="...">Facebook</a>
<a class="social-share-twitter" href="...">Twitter</a>

This facilitates styling the links as icons, or whatever best suits the site.


ICONS
=======
Beginning with the 2.x branch, an icon pack based on the GPL licensed social
media icon set released by elegantthemes.com are included. These icons can be
optionally enabled via the admin config in 16px or 32px sizes.


DISPLAY SUITE WEIRDNESS
=======================
If you want to display social share links in a view, you can configure views and display suite using the following steps:

1. go to manage display for your content type
2. select the teaser display
3. select a layout such as "one column."
4. You will see a Field Called "Social Share" which can be dragged into the content area. Curiously, the social share field doesn't appear until you select a layout, but once it has appeared, you can delete the layout and the field remains.
5. save.
6. in your view, select the format display suite (instead of selecting fields) and for the settings, select the teaser view mode.

You are done. Now when you look at your view, you'll get the social share links.
