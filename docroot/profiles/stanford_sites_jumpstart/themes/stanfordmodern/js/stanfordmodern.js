<!--
if ((window.screen.width < 640) || (window.screen.height < 640)){document.write('<meta name="viewport" content="width=device-width, user-scalable=yes, initial-scale=1" />')}
//-->

jQuery(document).ready(function($){
	
// Sticky Footer
if ($('#layout').outerHeight(true) < $(window).height()) {	
	$('#push').css('height', $('#global-footer').outerHeight(true));
	$('#layout').css('margin-bottom', 0 - $('#push').outerHeight(true) );
	}

// Header Drupal Search Box
$('#header [name=search_block_form]').val('Search this site...');
$('#header input[name=op]').val('');
$('#header [name=search_block_form]').focus(function () {
$('#header [name=search_block_form]').val('');
});

// Drawer Toggle Expand
$("#menu_expand").click(function (){
$("#nav ul ul").slideToggle("slow");
$('#menu_expand').hide();
$('#menu_hide').show();
});

// Drawer Toggle Hide
$("#menu_hide").click(function () {
$("#nav ul ul").slideToggle("slow");
$('#menu_expand').show();
$('#menu_hide').hide();
});

// Hide border for image links
$('a:has(img)').css('border', 'none');
});

// Hide Address Bar in Mobile View
addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false);
function hideURLbar(){
if (window.pageYOffset < 1) {
window.scrollTo(0, 1);
}
}