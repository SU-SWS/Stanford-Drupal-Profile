(function ($) {
  Drupal.behaviors.zStanfordJumpstartWysiwyg = {
    attach: function (context, settings) {

      switch (Drupal.settings.stanford_jumpstart_wysiwyg.default) {
        case 'swipe':
          $('table:not(.sticky-header)', context).each(addSwipe);
          break;

        case 'stack':
          $('table:not(.sticky-header)', context).each(addStack);
          break;

        case 'toggle':
          $('table:not(.sticky-header)', context).each(addToggle);
          break;
      }


      $('table.tablesaw-swipe, .tablesaw-swipe table:not(.sticky-header)', context).each(addSwipe);
      $('table.tablesaw-stack, .tablesaw-stack table:not(.sticky-header)', context).each(addStack);
      $('table.tablesaw-column-toggle, .tablesaw-column-toggle table:not(.sticky-header)', context).each(addToggle);

      // Swiping table
      function addSwipe(i, table) {
        if ($(table).hasClass('sticky-header') || $(this).closest('.calendar-calendar').length) {
          return;
        }

        $(table).addClass('tablesaw').attr('data-tablesaw-mode', 'swipe').attr('data-tablesaw-minimap', '');
      }

      // Stacking table.
      function addStack(i, table) {
        if ($(table).hasClass('sticky-header') || $(this).closest('.calendar-calendar').length) {
          return;
        }

        $(table).addClass('tablesaw').attr('data-tablesaw-mode', 'stack');
      }

      // Column Toggle Table
      function addToggle(i, table) {
        if ($(table).hasClass('sticky-header') || $(this).closest('.calendar-calendar').length) {
          return;
        }

        var priority = 0;
        $(table).addClass('tablesaw').attr('data-tablesaw-mode', 'columntoggle').find('th').each(function () {
          if (!priority) {
            $(this).attr('data-tablesaw-priority', 'persist');
          } else if (!$(table).attr('data-tablesaw-priority')) {

            if (priority <= 6) {
              $(this).attr('data-tablesaw-priority', priority);
            } else {
              // This should change to 0.
              $(this).attr('data-tablesaw-priority', 6);
            }

          }
          priority++;
        });
      }

      function setStickyHeader(e, table) {
        if (typeof table == 'undefined') {
          if (typeof e.currentTarget != 'undefined') {
            table = e.currentTarget;
          } else {
            return;
          }
        }

        var stickyHeaderTable = $(table).prevAll('table.sticky-header').first();
        // Make sure the sticky header is not wider than the actual table.
        var tableWidth = $(table).find('thead').width();
        $(stickyHeaderTable).width(tableWidth);

        var originalHeaders = $(table).find('thead tr > *');
        $.each(originalHeaders, function (i, header) {
          var stickyHeader = $(stickyHeaderTable).find('tr > *').get(i);

          // Set the widths of the sticky headers to match the normal headers.
          $(stickyHeader).width($(header).width());
          if ($(header).is(':visible')) {
            $(stickyHeader).show();
          } else {
            $(stickyHeader).hide();
          }
        })
      }


      $(window).on('scroll', function () {
        $('table.sticky-table[class*="tablesaw"]').each(setStickyHeader);
      });

      $(document).on('enhance.tablesaw', function () {
        $('table.sticky-table[class*="tablesaw"]').each(setStickyHeader);
        $('table.sticky-table').on('tablesawcolumns', setStickyHeader);
      })

    }
  };
})(jQuery);

document.addEventListener('DOMContentLoaded', function () {
  $(document).trigger('enhance.tablesaw');
});
