<?php
$layout_classes = theme_get_setting('layout_classes'); 
$header_classes = theme_get_setting('header_classes');
$icon_classes = theme_get_setting('icon_classes');
$banner_classes = theme_get_setting('banner_classes');
?>
<!DOCTYPE html>
<!--[if lt IE 7]> <html class="ie6 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 9]>    <html class="ie9 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if !IE]> --> <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <!-- <![endif]-->
<head>
<?php print $head; ?>
<!-- Set the viewport width to device width for mobile -->
<meta name="viewport" content="width=device-width" />
<title><?php print $head_title; ?></title>
<?php print $styles; ?><?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?> <?php print $header_classes; ?> <?php print $layout_classes; ?> <?php print $icon_classes; ?> <?php if ($is_front): ?><?php print $banner_classes; ?><?php endif; ?>" <?php print $attributes;?>>
<?php print $page_top; ?> <?php print $page; ?> <?php print $page_bottom; ?>
</body>
</html>