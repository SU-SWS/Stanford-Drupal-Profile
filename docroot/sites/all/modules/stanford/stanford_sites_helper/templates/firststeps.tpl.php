<?php
/*
 * @file Template file for Quickstart/First Steps block.
 */

/*
 * Variables
 */
$user_login_text = l(t('Log in with your SUNetID.'), 'sites/default/webauth/login');
$webauth_allow_local = variable_get('webauth_allow_local');
$password_reset = l(t('password reset form'), 'user/password');
$user_login_block = "<h2>Welcome to Your Stanford Sites Website</h2>";
// check if WMD is set to allow local Drupal logins.
// if so, display the login text to have the user log in as user 1
if ($webauth_allow_local === 0) {
  $user_login_block .= '<p>' . $user_login_text . '</p>';
}
else {
  $user_login_block .= "<p>If you haven't already, you should log in via the form to the left.</p>\n";
  $user_login_block .= "<p>Your user name is <strong>admin</strong> and you created a password when you set up the site.</p>\n";
  $user_login_block .= "<p>If you cannot remember your password, you can reset it by entering <strong>&quot;admin&quot;</strong> as the username in the " . $password_reset . ".</p>\n";
}
$user_login_block .= "<p>Once you have logged in, you will be able to remove this text from your homepage (follow the steps under &quot;Get rid of this Quick Steps content&quot;, below).</p>\n<hr />";
$images = drupal_get_path('module', 'stanford_sites_helper') . '/images/';
$stanford_sites_helper_node = variable_get('stanford_sites_helper_node');
$edit_homepage = l(t("Edit Your Homepage Content"), 'node/' . $stanford_sites_helper_node . '/edit', array('attributes' => array('class' => array('btn'))));
$edit_site_info = l(t("Edit Your Site's Information"), 'admin/config/system/site-information', array('attributes' => array('class' => array('btn'))));
$create_new_page = l(t("Create a New Page"), 'node/add/page', array('attributes' => array('class' => array('btn'))));
$learn_more_content_types = l(t("Learn more about content types in Drupal"), 'http://drupal.org/node/21947');
$edit_main_menu = l(t("Edit Your Main Menu"), 'admin/structure/menu/manage/main-menu', array('attributes' => array('class' => array('btn'))));
$create_new_menu = l(t("Create a New Menu"), 'admin/structure/menu/add', array('attributes' => array('class' => array('btn'))));
$getting_started = l(t("Getting Started"), 'getting-started');
$edit_firststeps_block = l(t("Hide This Block"), 'admin/structure/block/manage/stanford_sites_helper/firststeps/configure', array('attributes' => array('class' => array('btn'))));
$edit_blocks = l(t("Configure All Blocks"), 'admin/structure/block', array('attributes' => array('class' => array('btn'))));
$learn_more_menus = l(t("Learn more about menus in Drupal"), 'http://drupal.org/documentation/modules/menu');
$modules = l(t("Visit Your Modules"), 'admin/modules', array('attributes' => array('class' => array('btn'))));
$learn_more_modules = l(t("Learn more about the available modules on Stanford Sites"), 'https://itservices.stanford.edu/service/web/stanfordsites/userguide');
$edit_theme_settings = l(t("Edit Your Theme Settings"), 'admin/appearance/settings', array('attributes' => array('class' => array('btn'))));
$create_css_injector = l(t("Create a CSS Injector rule"), 'admin/config/development/css-injector/add');
$add_user = l(t("Add a new user"), 'admin/people/create');
$add_role = l(t("Create a new user role"), 'admin/people/permissions/roles');
$edit_permissions = l(t("Edit permissions"), 'admin/people/permissions');
$create_view = l(t("Create a new View"), 'admin/structure/views/add');
//add css and js
drupal_add_js('misc/collapse.js');
drupal_add_js('misc/form.js');
$path = drupal_get_path('module', 'stanford_sites_helper') . '/css/stanford-sites-helper-firststeps.css';
drupal_add_css($path);

?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if(user_is_anonymous()) { print $user_login_block; }?>


  <?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
<?php endif;?>
  <?php print render($title_suffix); ?>
  
  <div id="welcome">
  <div id="quickstart">
    <ol>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>plus.png" alt="plus" /> <span class="fieldset-legend">Create a new page on your site</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">Do you want an &quot;about&quot; or other page  on your site? When creating new pages, you can directly add them to the Main Menu navigation in the Menu Settings section of the form.</p>
            <p><?php print $create_new_page; ?></p>
            <p><?php print $learn_more_content_types; ?></p>
          </div>
        </fieldset>
      </li>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>plant.png" alt="plant" /> <span class="fieldset-legend">Change your site's name and information</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">You can rename your site, add a slogan, or set an existing page to be the homepage of your site by visiting the site information page.</p>
            <p> <?php print $edit_site_info; ?> </p>
            
          </div>
        </fieldset>
      </li>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>remove.png" alt="minus" /> <span class="fieldset-legend">Get rid of this &quot;Quick Steps&quot; content</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">Want to make these &quot;Quick Steps&quot; go away?</p>
            <p>Drupal uses a system called <strong>&quot;blocks&quot;</strong> to layout content on your website. (This Quick Steps are in a block, but even if you disable it, you can always get back to it at <?php print $getting_started; ?>.)</p>
            <p><?php print $edit_firststeps_block; ?><?php print $edit_blocks; ?></p>
          </div>
        </fieldset>
      </li>
            
    </ol>
  </div>
  <h3>More advanced tasks:</h3>
  <div id="nextsteps">
    <ol>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>menu.png" alt="menu" /> <span class="fieldset-legend">Edit your  navigation menus</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">Drupal comes pre-packaged with a Main menu navigation  to which you can add your existing pages. First create new pages, and then add them to your menu. You can create a new menu and add items to it by visiting the Menus page. Move your menus around using the Blocks page.</p>
            <p><?php print $edit_main_menu; ?><?php print $create_new_menu; ?></p>
            <p><?php print $learn_more_menus; ?></p>
          </div>
        </fieldset>
      </li>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>gear.png" alt="gear" /> <span class="fieldset-legend">Add functionality and features</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">Want to add a contact form to your site? Looking to do more with your site? Enable functionality on the Modules page, but first you might want to learn what the available modules do and why you might want to enable them.</p>
            <p><?php print $modules; ?></p>
            <p><?php print $learn_more_modules; ?></p>
          </div>
        </fieldset>
      </li>
      <li>
        <fieldset class="field-group-fieldset collapsible collapsed">
          <legend><img src="<?php print $images ?>brush.png" alt="brush" /> <span class="fieldset-legend">Edit the look and feel of your site</span></legend>
          <div class="fieldset-wrapper">
            <p class="intro">Your site comes pre-packaged with the Stanford Light theme. Edit the settings for Stanford Light to add a background image and change the color scheme. If you're looking to do more custom CSS for your site, use the CSS Injector module.</p>
            <p><?php print $edit_theme_settings; ?></p>
            <p><?php print $create_css_injector; ?></p>
          </div>
        </fieldset>
      </li>
    </ol>
  </div>
  <h3>Going further:</h3>
  <div id="shortcuts">
    <ul>
      <li><?php print $add_user; ?></li>
      <li><?php print $add_role; ?></li>
      <li><?php print $edit_permissions; ?></li>
      <li><?php print $create_view; ?></li>
    </ul>
  </div>
</div>
</div>
