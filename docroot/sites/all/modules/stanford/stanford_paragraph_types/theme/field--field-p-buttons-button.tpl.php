<?php

/**
 * @file
 * Field_p_buttons_button template.
 */

$item_chunks = array_chunk($items, 3, TRUE);
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div
      class="field-label"<?php print $title_attributes; ?>><?php print $label ?>
      :&nbsp;</div>
  <?php endif; ?>

  <?php foreach ($item_chunks as $items): ?>
    <?php $offset = count($items) % 3 ? 'offset' . (count($items) % 3 * -2 + 6) : ''; ?>
    <div class="field-items row-fluid"<?php print $content_attributes; ?>>
      <?php foreach ($items as $delta => $item): ?>
        <div class="field-item span4 <?php print $delta % 2 ? 'odd' : 'even';
        print ($delta == key($items)) ? ' ' . $offset : ''; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
