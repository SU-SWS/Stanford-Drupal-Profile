(function ($) {
  Drupal.behaviors.stanfordParagraphPCardsFix = {
    attach: function (context, settings) {

      function fixCards() {
        $('.field-name-field-p-card-title .field-item').css('height', 'auto');

        if ($(window).width() <= 766) {
          return;
        }

        $('.field-name-field-p-cards-card').each(function () {
          var maxHeight = 0;
          $(this).find('.field-name-field-p-card-title .field-item').each(function () {
            if ($(this).height() > maxHeight) {
              maxHeight = $(this).height();
            }
          });

          $(this).find('.field-name-field-p-card-title .field-item').height(maxHeight);
        });
      }

      fixCards();
      $(window).resize(fixCards);
    }
  }
})(jQuery);