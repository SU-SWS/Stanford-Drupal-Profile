/**
 * @file
 * Fontawesome field widget.
 */

(function ($) {
  Drupal.behaviors.stanford_events_views = {
    attach: function (context, settings) {
      var setNoImageHeight = function () {
        $('.view-display-id-paragraphs_events_block').each(function () {
          var image_height = $(this).find('img').height();

          if (image_height && $(window).width() >= 767) {
            $(this).find('.date-stacked.no-image').css('height', image_height + 'px');
          } else {
            $(this).find('.date-stacked.no-image').css('height', '');
          }
        });
      };

      $(window).load(setNoImageHeight);
      $(window).resize(setNoImageHeight);
    }
  }
})(jQuery);
