<?php include('header.inc'); ?>

<div id ='page' class='clear-block limiter page-content'>
  <?php print render($title_suffix); ?>
  <?php if ($show_messages && $messages): ?>
    <div id='console' class='clear-block'><?php print $messages; ?></div>
  <?php endif; ?>
  <div id='content' class="block-region">
    <?php if (!empty($page['content'])): ?>
      <div class='content-wrapper clear-block'><?php print render($page['content']); ?></div>
    <?php endif; ?>
  </div>
  <div id='left' class='clear-block'>
    <?php print render($page['left']) ?>
  </div>
  <div id='right' class='block-region clear-block'>
    <?php print render($page['right']) ?>
  </div>
</div>

<?php include('footer.inc'); ?>
