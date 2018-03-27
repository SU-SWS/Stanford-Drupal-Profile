THEME VARIABLES:
This module introduces a couple of extra variables into your page.tpl.php

*$alt*                   
The alt text provided in the image upload field on subsite
nodes. field_stanford_subsite_logo. This can be added to
the default page.tpl.php markup

*$logo_title*           
The title text provided in the image upload field on
subsite nodes. field_stanford_subsite_logo. This can be
added to the default page.tpl.php markup

*$subsite_logo_html*    
A fully rendered image and link tag complete with alt and
title text. This variable should replace the $logo
variable in page.tpl.php. It falls back to the default
$logo image if there is no subsite logo available. This is
different from the regular $logo variable as it has alt,
title text, and a link that can link to either the subsite
page or the drupal root home.

*$subsite_site_name_html*
A fully rendered link and site name heading tag. This
is different from the regular $site_name page variable
as it can have it's link go to either the subsite node
or the Drupal root home.

*$subsite_site_name_text*  
A plain text string of the currently active susbsite
site name text

*$subsite_is_front*     
A boolean value to determine if the current page that is
being viewed is a subsite 'front' page

*$subsite_front*       
A string of the complete url to the active subsite. False
if there is no active subsite.
eg: http://example.com/subsite

*$subsite_name_logo_setting*    
A string of text with the setting value for the
way the logo and site name variables should be
linked. The values are: default (link both to site
root), subsite (link both to subsite node), or
split (link logo to site root and site name to the
subsite logo)


Some additional variables are available to your html.tpl.php

*$subsite_site_name_html*   
A fully rendered link and site name heading tag. This
is different from the regular $site_name page variable
as it can have it's link go to either the subsite node
or the Drupal root home.

*$subsite_site_name_text*  
A plain text string of the currently active susbsite
site name text

*$site_name*                
The original site name.
