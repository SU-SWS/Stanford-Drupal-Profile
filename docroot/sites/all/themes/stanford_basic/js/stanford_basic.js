<!--
if ((window.screen.width < 640) || (window.screen.height < 640)){document.write('<meta name="viewport" content="width=device-width, user-scalable=yes, initial-scale=1" />')}
//-->

$(document).ready(function(){
	
	// Header Drupal Search Box
	$('#header [name=search_theme_form]').val('Search this site...');
	$('#header input[name=op]').val('');
	$('#header [name=search_theme_form]').focus(function () {
	$('#header [name=search_theme_form]').val('');
	});
	
	// Show Stanford Search Box
	$("#javascript").show();
	
	// Header Stanford Search Box
	$('#header [name=q]').val('Search Stanford...');
	$('#header [name=q]').focus(function () {
	$('#header [name=q]').val('');
	});
	
	$('a:has(img)').css('border', 'none');

});