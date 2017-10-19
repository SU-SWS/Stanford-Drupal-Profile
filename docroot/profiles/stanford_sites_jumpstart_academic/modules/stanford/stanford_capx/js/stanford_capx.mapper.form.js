Drupal.behaviors.yourvariablehere = {
  attach: function(context, settings) {

  (function ($) {

    /**
     * [doHeight description]
     * @return {[type]} [description]
     */
    var doHeight = function() {
      var maxH = Math.round($(window).height() * 0.7) - 30;
      var block = $("#block-stanford-capx-data-browser-launch");

      // If it is floating we can go a bit bigger.
      if (block.hasClass("is-floating")) {
        maxH = Math.round($(window).height() * 0.95) - 30;
      }

      block.css("height", maxH + "px");
      block.css("max-height", maxH + "px");
    };

    // Set this variable with the height of your sidebar + header.
    // ------------------------------------------------------------------------.
    var theformraw = $("#stanford-capx-mapper-form")[0];
    var thepageraw = $("html")[0];
    var offsetForm = theformraw.getBoundingClientRect().top;
    var offsetPage = thepageraw.getBoundingClientRect().top;

    if (offsetForm < 0) {
      offsetForm *= -1;
    }

    var offsetPixels = offsetPage + offsetForm;

    if (offsetPixels < 0) {
      offsetPixels *= -1;
    }

    $(window).scroll(function() {

      var scrollTop = $(window).scrollTop() + 30;

      if (scrollTop > offsetPixels) {
        var block = $("#block-stanford-capx-data-browser-launch");
        var new_position = Math.round(scrollTop - offsetPixels);

        block.css({
            "position": "relative",
            "top": new_position + "px",
            "right": 0
          });

        if (!block.hasClass("is-floating")) {
          block.addClass("is-floating");
        }
        // Resize the block.
        doHeight();
      }
      else {
        $("#block-stanford-capx-data-browser-launch").css({
          "position": "static"
        })
          .removeClass("is-floating");

        // Resize the block.
        doHeight();
      }
    });


    // Resize the height.
    // ------------------------------------------------------------------------.
    $(window).resize(function() {
      // Resize the block.
      doHeight();
    });


  })(jQuery);

  }
};

