<?php
  /**
   * Dashboard Template file.
   * admin/config/subsites/dashboard
   */
?>

<?php if (isset($page['main_top'])) : ?>
  <div class="main-top-region">
    <?php print render($page['main_top']); ?>
  </div>
<?php endif; ?>

<div class="main-content-region <?php if (isset($page['sidebar_second'])) { print 'sidebar-second'; } ?>">
  <?php print render($page['content']); ?>
</div>

<?php if (isset($page['sidebar_second'])) : ?>
  <div class="sidebar-second-region">
    <?php print render($page['sidebar_second']); ?>
  </div>
<?php endif; ?>
