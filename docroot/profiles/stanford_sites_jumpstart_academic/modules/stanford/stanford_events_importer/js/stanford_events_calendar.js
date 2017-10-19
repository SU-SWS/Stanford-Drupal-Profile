Drupal.behaviors.stanford_events_calendar_aria = {
  attach: function(context, settings) {

    (function ($) {

      // Add accessibility controls for the small calendar widget.
      var block = $(".events-calendar-aria", context);
      if ($(context).hasClass("events-calendar-aria")) {
        block = context;
        block.find(".date-heading a").focus();
      }

      if (block.length) {
        var prev = block.find(".date-prev a");
        var next = block.find(".date-next a");
        block.attr("role", "navigation");
        block.attr("aria-label", Drupal.t("Events calendar"));
        prev.attr("aria-label", Drupal.t("Previous month"));
        next.attr("aria-label", Drupal.t("Next month"));
        $.each(block.find(".mini-day-on a"), function(i, v) {
          var mylabel = Drupal.t("See all events on ") + $(v).parents(".events-calendar-aria").find(".date-heading a").text() + " " + $(v).text();
          $(v).attr("aria-label", mylabel);
        });
        // Prevent space bar from jumping down page!
        prev.keydown(function (e) {
          var key = e.charCode ? e.charCode : e.keyCode ? e.keyCode : 0;
          if (key == 32) {
            e.preventDefault();
            $(this).trigger("click");
          }
        });
        // Next as well.
        next.keydown(function (e) {
          var key = e.charCode ? e.charCode : e.keyCode ? e.keyCode : 0;
          if (key == 32) {
            e.preventDefault();
            $(this).trigger("click");
          }
        });

      }

    })(jQuery);
  }
};
