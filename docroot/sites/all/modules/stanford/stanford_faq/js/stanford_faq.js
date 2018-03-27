(function ($) {

/**
 * Drupal attach behaviour.
 */
Drupal.behaviors.stanford_faq = {
  attach: function (context, settings) {

  var toggles = $(".collapse-toggle", context);
  var contents = $("div.collapse", context);

  // Make the links in the collapsed fields hidden from tab by default.
  contents.find("a").attr("tabindex", '-1');

  // Make sure the aria controls are set right.
  toggles.attr("aria-expanded", "false");

  // Set up the spoken feedback.
  $.each(toggles, function(i, v) {
    $(v).attr("aria-controls", $(v).attr("href"));
  });

  // Trigger the expanded voice feedback.
  toggles.click(function(e) {

    // Which one was clicked.
    var index = toggles.index($(this));
    $(this).parents(".view-content").find("div.collapse").filter(":not('.in')").find("a").attr("tabindex", "-1");

    if ($(this).attr("aria-expanded") == "true") {
      $(this).parents(".view-content").find("div.collapse").eq(index).find("a").attr("tabindex", "-1");
      $(this).attr("aria-expanded", "false");
    }
    else {
      $(this).parents(".view-content").find("div.collapse").eq(index).find("a").attr("tabindex", "0");
      $(this).attr("aria-expanded", "true");
    }
  });

  // Prevent space bar from jumping down page and expand the thing!
  toggles.keydown(function (e) {
    var key = e.charCode ? e.charCode : e.keyCode ? e.keyCode : 0;
    if (key == 32) {
      e.preventDefault();
      $(this).trigger("click");
    }
  });


  }
};

})(jQuery);
