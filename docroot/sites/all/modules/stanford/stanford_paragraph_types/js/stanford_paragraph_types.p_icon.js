(function ($) {
  Drupal.behaviors.stanfordParagraphPIconFix = {
    attach: function (context, settings) {

      function countText(countableItem) {
        var $this = $(countableItem), countTo = parseInt($this.text());
        if (!countTo) {
          return;
        }

        var suffix = $this.text().replace(countTo, '');

        $this.text(0);
        $({countNum: parseInt($this.text())}).animate({
          countNum: countTo
        }, {
          duration: 1500,
          easing: 'linear',
          step: function () {
            $this.text(Math.floor(this.countNum));
          },
          complete: function () {
            $this.text(this.countNum + suffix.trim());
          }

        });

      }

      function checkVisibility() {
        $('.field-name-field-p-icon-text .field-items').each(function () {
          if ($(this).hasClass('counted')) {
            return;
          }

          var bottomEdge = $(this).offset().top + $(this).height();
          if (
            bottomEdge <= $(window).height() + $(document).scrollTop() &&
            $(this).offset().top > $(document).scrollTop()
          ) {
            $(this).addClass('counted');
            countText(this);
          }
        })
      }

      $(window).scroll(checkVisibility);
      checkVisibility();
    }
  }
})(jQuery);