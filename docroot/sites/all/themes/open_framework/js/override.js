(function($) {

    Drupal.behaviors.open_framework_override = {
        attach: function(context, settings) {

            // Bootstrap dropdown menu in top nav bar
            // Bootstrap dropdown menu in secondary menu
            $('nav ul, #secondary-menu ul')
                .children('li')
                .filter(':has(.active)')
                .addClass('active')
                .end()
                .filter(':has(ul .active)')
                .removeClass('active')
                .end()
                .end()
                .find('ul a')
                .removeAttr('data-toggle')
                .removeAttr('data-target')

            // Bootstrap Menu Block behavior in sidebar
            $('.sidebar .block-menu-block ul.menu.nav a').removeAttr('data-toggle');
            $('.sidebar .block-menu-block ul.menu.nav a').removeAttr('data-target');
            $('.sidebar .block-menu-block ul.menu.nav li').removeClass('dropdown-submenu');
            $('.sidebar .block-menu-block ul.menu.nav ul').removeClass('dropdown-menu');

            // Set up theme specific responsive behaviors
            function responsive_behaviors() {
                var viewportwidth;
                var viewportheight;

                // the more standards compliant browsers (mozilla/netscape/opera/IE7) use window.innerWidth and window.innerHeight

                if (typeof window.innerWidth != 'undefined') {
                    viewportwidth = window.innerWidth,
                    viewportheight = window.innerHeight
                }

                // IE6 in standards compliant mode (i.e. with a valid doctype as the first line in the document)
                else if (typeof document.documentElement != 'undefined' && typeof document.documentElement.clientWidth !=
                    'undefined' && document.documentElement.clientWidth != 0) {
                    viewportwidth = document.documentElement.clientWidth,
                    viewportheight = document.documentElement.clientHeight
                }

                // older versions of IE
                else {
                    viewportwidth = document.getElementsByTagName('body')[0].clientWidth,
                    viewportheight = document.getElementsByTagName('body')[0].clientHeight
                }

                if (viewportwidth < 768) {
                    $('nav li li.expanded').removeClass('dropdown-submenu');
                    $('nav ul ul ul').removeClass('dropdown-menu');
                    $('div.next-row').addClass('clear-row');
                } else {
                    $('nav li li.expanded').addClass('dropdown-submenu');
                    $('nav ul ul ul').addClass('dropdown-menu');
                    $('div.next-row').removeClass('clear-row');
                }

                if ((viewportwidth >= 768) && (viewportwidth < 980)) {
                    $('.two-sidebars')
                        .find('.site-sidebar-first')
                        .removeClass('span3')
                        .addClass('span4')
                        .end()
                        .find('.site-sidebar-second')
                        .removeClass('span3')
                        .addClass('span12')
                        .end()
                        .find('.mc-content')
                        .removeClass('span6')
                        .addClass('span8')
                        .end()
                        .find('.region-sidebar-second .block')
                        .addClass('span4')
                        .end();
                    $('.sidebar-first')
                        .find('.site-sidebar-first')
                        .removeClass('span3')
                        .addClass('span4')
                        .end()
                        .find('.mc-content')
                        .removeClass('span9')
                        .addClass('span8')
                        .end();
                    $('.sidebar-second')
                        .find('.site-sidebar-second')
                        .removeClass('span3')
                        .addClass('span12')
                        .end()
                        .find('.mc-content')
                        .removeClass('span9')
                        .addClass('span12')
                        .end()
                        .find('.region-sidebar-second .block')
                        .addClass('span4')
                        .end();
                } else {
                    $('.two-sidebars')
                        .find('.site-sidebar-first')
                        .removeClass('span4')
                        .addClass('span3')
                        .end()
                        .find('.site-sidebar-second')
                        .removeClass('span12')
                        .addClass('span3')
                        .end()
                        .find('.mc-content')
                        .removeClass('span8')
                        .addClass('span6')
                        .end()
                        .find('.region-sidebar-second .block')
                        .removeClass('span4')
                        .end();
                    $('.sidebar-first')
                        .find('.site-sidebar-first')
                        .removeClass('span4')
                        .addClass('span3')
                        .end()
                        .find('.mc-content')
                        .removeClass('span8')
                        .addClass('span9')
                        .end();
                    $('.sidebar-second')
                        .find('.site-sidebar-second')
                        .removeClass('span12')
                        .addClass('span3')
                        .end()
                        .find('.mc-content')
                        .removeClass('span12')
                        .addClass('span9')
                        .end()
                        .find('.region-sidebar-second .block')
                        .removeClass('span4')
                        .end();
                }
            }

            // Update CSS classes based on window load and resize
            $(window)
                .load(responsive_behaviors)
                .resize(responsive_behaviors);
        }
    }

})(jQuery);
