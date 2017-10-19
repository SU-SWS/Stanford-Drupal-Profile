<?php

/**
 * @file
 * P_callout paragraph type.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="span12 center">
    <div class="content row-fluid"<?php print $content_attributes; ?>>
      <?php print render($content); ?>
    </div>
  </div>
</div>
