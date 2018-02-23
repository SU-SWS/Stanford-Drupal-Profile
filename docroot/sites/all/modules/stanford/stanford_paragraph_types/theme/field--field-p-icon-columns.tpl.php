<?php

/**
 * @file
 * Field Icon Block Template.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>

  <?php if(isset($item_chunks)): ?>
    <?php foreach($item_chunks as $chunk_delta => $items): ?>

      <div class="field-items clearfix <?php print $partial_offset ? 'partial-offset' : ''; ?>"<?php print $content_attributes; ?>>
        <?php foreach ($items as $delta => $item): ?>
          <div class="collection-field-item <?php print $delta % 2 ? 'odd ' : 'even '; print $offsets[$chunk_delta]; $offsets[$chunk_delta] = ''; print $span_per_item;?>"<?php print $item_attributes[$delta]; ?>>
            <?php print render($item); ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endforeach; ?>

  <?php else: ?>
    <?php
    // The original template for fields within the field collection.
    ?>
    <div class="field-items"<?php print $content_attributes; ?>>
      <?php foreach ($items as $delta => $item): ?>
        <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>

</div>
