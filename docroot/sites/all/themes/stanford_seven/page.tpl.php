<?php if (($user->uid) && ($page['admin_shortcuts'])): ?>
<div id="admin-shortcuts" class="clearfix admin-shortcuts"> 
<?php print render($page['admin_shortcuts']); ?> 
</div>
<?php endif; ?>

<div id="branding" class="clearfix"> 
<?php print $breadcrumb; ?> <?php print render($title_prefix); ?>
  <?php if ($title): ?>
  <h1 class="page-title"><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?> <?php print render($primary_local_tasks); ?> 
</div>
  
<div id="page">
	
    <?php if ($page['main_top']): ?>
    <div id="main-top"> <?php print render($page['main_top']); ?> </div>
    <?php endif; ?>

  <?php if ($secondary_local_tasks): ?>
  <div class="tabs-secondary clearfix"><?php print render($secondary_local_tasks); ?></div>
  <?php endif; ?>
  
  <div id="content" class="clearfix<?php if ($page['sidebar_second']) { print " sidebar-second"; } ?>">
  
    <div class="element-invisible"><a id="main-content"></a></div>
    
    <?php if ($messages): ?>
    <div id="console" class="clearfix"><?php print $messages; ?></div>
    <?php endif; ?>
    
    <?php if ($page['help']): ?>
    <div id="help"> <?php print render($page['help']); ?> </div>
    <?php endif; ?>
    
    <?php if ($action_links): ?>
    <ul class="action-links">
      <?php print render($action_links); ?>
    </ul>
    <?php endif; ?>
    
    <?php if ($page['content_top']): ?>
    <div id="content-top"> <?php print render($page['content_top']); ?> </div>
    <?php endif; ?>
    
    <div id="content-body">
	<?php print render($page['content']); ?> 
    </div>
    
    <?php if ($page['content_bottom']): ?>
    <div id="content-bottom"> <?php print render($page['content_bottom']); ?> </div>
    <?php endif; ?>
    
  </div>
  
  <?php if ($page['sidebar_second']): ?>
    <div id="sidebar-second"> <?php print render($page['sidebar_second']); ?> </div>
  <?php endif; ?>
  
  
  <?php if ($page['main_bottom']): ?>
    <div id="main-bottom"> <?php print render($page['main_bottom']); ?> </div>
    <?php endif; ?>
    
  <div id="footer"> <?php print $feed_icons; ?> </div>
</div>
