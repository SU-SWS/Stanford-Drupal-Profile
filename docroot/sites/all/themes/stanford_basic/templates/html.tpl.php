<?php
$layout_classes = theme_get_setting('layout_classes'); 
$header_padding_classes = theme_get_setting('header_padding_classes');
$color_classes = theme_get_setting('color_classes'); 
$border_classes = theme_get_setting('border_classes'); 
$corner_classes = theme_get_setting('corner_classes'); 
$body_bg_type = theme_get_setting('body_bg_type'); 
$body_bg_classes = theme_get_setting('body_bg_classes'); 
$body_bg_path = theme_get_setting('body_bg_path'); 
?>
<!DOCTYPE html>
<html>
<head>
<?php print $head; ?>
<!-- Set the viewport width to device width for mobile -->
<meta name="viewport" content="width=device-width" />
<title><?php print $head_title; ?></title>
<?php print $styles; ?><?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?> <?php print $body_bg_type; ?> <?php print $body_bg_classes; ?> <?php print $header_padding_classes; ?> <?php print $layout_classes; ?> <?php print $color_classes; ?> <?php print $border_classes; ?> <?php print $corner_classes; ?>" <?php print $attributes;?> <?php if ($body_bg_classes): ?>style="background: url('<?php print file_create_url(theme_get_setting('body_bg_path')); ?>') repeat top left;" <?php endif; ?>>
<?php print $page_top; ?> <?php print $page; ?> <?php print $page_bottom; ?>
</body>
</html>