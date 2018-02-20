(function ($) {
  Drupal.behaviors.stanfordJumpstartMasonry = {
    attach: function (context, settings) {

      $('.view.masonry .view-content').once(function () {
        var maxHeight = 0;
        $(this).find('.views-row').each(function () {
          if ($(this).height() > maxHeight) {
            maxHeight = $(this).height();
          }
        });
        $(this).height(maxHeight);


        $(window).load(function () {
          $('.view.masonry .view-content').imagesLoaded(function () {
            var container = document.querySelector('.view.masonry .view-content');
            var msnry = new Masonry(container, {
              gutter: 20,
              isInitLayout: false
            });

            msnry._isLayoutInited = true;
            msnry.layout();
          });
        });
      });

    }
  }
})(jQuery);
