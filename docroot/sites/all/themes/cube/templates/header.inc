
  <?php if ($help): ?>
  <div id='page-help'><div class='limiter clear-block'>
    <?php if ($help_toggler) print $help_toggler ?>
    <?php print render($help) ?>
  </div></div>
  <?php endif; ?>

  <div id='top'>
    <?php print render($title_prefix); ?>
    <div id='page-title' class='limiter clear-block'>
      <?php if ($main_menu) print theme('links', array('links' => $main_menu, 'attributes' => array('class' => 'links main-menu'))) ?>
      <?php if ($action_links): ?>
        <ul class='action-links clearfix'><?php print render($action_links) ?></ul>
      <?php endif; ?>
      <h1 class='page-title <?php print $page_icon_class ?>'>
        <?php if (!empty($page_icon_class)): ?><span class='icon'></span><?php endif; ?>
        <?php if ($title) print $title ?>
      </h1>
    </div>

    <div id='branding'><div class='limiter clear-block'>
      <?php if ($user_links) print theme('links', array('links' => $user_links)) ?>
      <div class='breadcrumb clear-block'><?php print $breadcrumb ?></div>
    </div></div>
  </div>

  <?php if($overlay): ?>
  <div class="limiter">
  <?php endif; ?>

  <?php if ($primary_tabs): ?>
    <div id='tabs'>
      <div class='page-tabs limiter clear-block'><ul class="tabs primary"><?php print render($primary_tabs) ?></ul></div>
      <?php if ($secondary_tabs): ?><div class='page-tabs limiter clear-block'><ul class="tabs secondary"><?php print render($secondary_tabs) ?></ul></div><?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if($overlay): ?>
  </div>
  <?php endif; ?>

  <?php if (isset($page['top']) && !empty($page['top'])): ?><div id='page-top' class='limiter block-region clear-block'><?php print render($page['top']) ?></div><?php endif; ?>