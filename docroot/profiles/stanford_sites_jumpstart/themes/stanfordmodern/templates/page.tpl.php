<div id="skipnav">
  <p>Skip to:</p>
  <ul>
    <li><a href="#main" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a></li>
    <?php if ($main_menu): ?>
    <li><a href="#nav" class="element-invisible element-focusable"><?php print t('Skip to navigation'); ?></a></li>
    <?php endif; ?>
  </ul>
</div>
<!-- /#skipnav -->
<div id="layout">
  <div id="wrapper" class="clearfix">
    <div id="header" role="banner" class="clearfix">
      <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
      <?php endif; ?>
      <?php if ($logo): ?>
      <a href="http://www.stanford.edu" title="Stanford University" id="logo"> <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /> </a>
      <?php endif; ?>
      <?php if ($site_name || $site_slogan): ?>
      <div id="site">
        <?php if ($site_name): ?>
        <div id="name"> <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><span><?php print $site_name; ?></span></a> </div>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
        <div id="slogan"> <?php print $site_slogan; ?> </div>
        <?php endif; ?>
      </div>
      <?php endif; ?>
    </div>
    <!-- /#header -->
    <?php if (($page['nav']) || ($main_menu)): ?>
    <div id="nav" role="navigation" class="clearfix">
      <?php if ($page['nav']): ?>
      <?php print render($page['nav']); ?>
      <?php endif; ?>
      <?php if (empty($page['nav'])): ?>
      <?php if ($main_menu): ?>
      <div id="main-menu"> <?php print theme('links__system_main_menu', array(
          'links' => $main_menu,
          'attributes' => array(
            'id' => 'main-menu-links',
            'class' => array('links', 'clearfix'),
          ),
          'heading' => array(
            'text' => t('Main menu'),
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?> </div>
      <!-- /#main-menu -->
      <?php endif; ?>
      <?php endif; ?>
    </div>
    <?php endif; ?>
    <!-- /#nav -->
    <?php if (($page['nav']) || ($main_menu)): ?>
    <div id="toggle">
      <div id="menu_expand">Expand Menus</div>
      <div id="menu_hide">Hide Menus</div>
    </div>
    <!-- /#toggle -->
    <?php endif; ?>
    <div id="container">
      <?php if ($page['top']): ?>
      <div id="top"><?php print render($page['top']); ?></div>
      <?php endif; ?>
      <?php print $messages; ?> <?php print render($title_prefix); ?>
      <?php if ($title): ?>
      <?php if (!$is_front): ?>
      <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($page['upper']): ?>
      <div id="upper"><?php print render($page['upper']); ?></div>
      <?php endif; ?>
      <?php if (!empty($tabs['#primary'])): ?>
      <div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div>
      <?php endif; ?>
      <?php if ($page['nav']): ?>
      <br>
      <?php endif; ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
      <?php endif; ?>
      <?php if ($page['feature']): ?>
      <div id="feature"><?php print render($page['feature']); ?></div>
      <?php endif; ?>
      <div id="content" class="clearfix">
        <?php if (($is_front) && (theme_get_setting('banner_classes') != "")): ?>
        <div id="front-banner"><img src="<?php print file_create_url(theme_get_setting('banner_image_path')); ?>" class="image_banner" role="presentation"></div>
        <?php endif; ?>
        <div id="main" role="main">
          <?php if ($breadcrumb): print $breadcrumb; endif;?>
          <?php if ($page['highlighted']): ?>
          <div id="highlighted"><?php print render($page['highlighted']); ?></div>
          <?php endif; ?>
          <?php print render($page['content']); ?> <?php print $feed_icons ?>
          <?php if ((!empty($node->changed)) && (!$is_front)): ?>
          <p class="last-modified">Last modified <?php print format_date($node->changed, 'custom', 'D, j M, Y \a\\t G:i') ?></p>
          <?php endif; ?>
        </div>
        <!-- /#main -->
        <?php if ($page['sidebar_first']): ?>
        <div id="sidebar-first" class="sidebar"> <?php print render($page['sidebar_first']); ?> </div>
        <!-- /#sidebar-first -->
        <?php endif; ?>
        <?php if ($page['sidebar_second']): ?>
        <div id="sidebar-second" class="sidebar"> <?php print render($page['sidebar_second']); ?> </div>
        <!-- /#sidebar-second -->
        <?php endif; ?>
      </div>
      <!-- /#content -->
      <?php if ($page['lower']): ?>
      <div id="lower" class="clearfix"><?php print render($page['lower']); ?></div>
      <?php endif; ?>
      <div id="footer-wrapper">
        <?php if ($page['bottom']): ?>
        <div id="bottom"><?php print render($page['bottom']); ?></div>
        <?php endif; ?>
        <?php if ($page['footer']): ?>
        <div id="footer"><?php print render($page['footer']); ?></div>
        <?php endif; ?>
      </div>
      <!-- /#footer-wrapper --> 
    </div>
    <!-- /#container --> 
  </div>
  <!-- /#wrapper -->
  <div id="push"></div>
  <!-- /#push --> 
</div>
<!-- /#layout -->
<div id="global-footer">
  <div class="wrap">
    <div id="bottom-logo"> <a href="http://www.stanford.edu"><img src="<?php print base_path() . path_to_theme(); ?>/images/footer-stanford-logo.png" alt="Stanford University"></a> </div>
    <div id="bottom-menu">
      <ul>
        <li><a href="http://www.stanford.edu">SU Home</a></li>
        <li><a href="http://visit.stanford.edu/plan/maps.html">Maps &amp; Directions</a></li>
        <li><a href="http://www.stanford.edu/search/">Search Stanford</a></li>
        <li><a href="http://www.stanford.edu/site/terms.html">Terms of Use</a></li>
        <li><a href="http://emergency.stanford.edu/">Emergency Info</a></li>
      </ul>
      <p id="copyright" class="vcard">&copy; <span class="fn org">Stanford University</span>, <span class="adr"><span class="locality">Stanford</span>, <span class="region">California</span> <span class="postal-code">94305</span></span>. <span class="copyright-links"><a href="http://www.stanford.edu/site/copyright.html">Copyright Complaints</a></span></p>
    </div>
    <!-- /#footer_content --> 
  </div>
  <!-- /#wrap --> 
</div>
<!-- /#footer --> 