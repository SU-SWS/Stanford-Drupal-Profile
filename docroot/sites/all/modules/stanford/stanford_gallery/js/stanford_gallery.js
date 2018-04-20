Drupal.behaviors.stanford_gallery = {
  attach: function(context, settings) {

  (function ($) {

    // Define selector.
    var selector = "stanford-gallery-image";

    // Default settings.
    var cboxsettings = {
      rel : "group",
      scalePhotos : true,
      returnFocus : true,
      trapFocus: true,
      maxWidth : "98%",
      maxHeight : "90%",
      title: function() {
        return StanfordGallery.caption(this);
      }
    };

    // Start by adding the appropriate class to all of the items.
    $(".field-name-field-s-gallery-image-info .field-items a", context).addClass(selector);

    // Store the selected items for use.
    var items = $("." + selector);

    // Init each gallery independantly.
    $.each($(".field-name-field-s-gallery-image-info"), function(i,v) {
      var galleryItems = $(v).find("." + selector);
      cboxsettings.rel = "group" + i;
      // Initialize the gallery.
      galleryItems.colorbox(cboxsettings);
    });

  })(jQuery);

  }

};

/**
 * StanfordGallery global object.
 * @type {Object}
 */
StanfordGallery = {};
StanfordGallery.caption = function(element) {
  // Shortcut.
  $ = jQuery;
  // Define selector.
  var selector = "stanford-gallery-image";
  var items = $("." + selector);
  var i = items.index(element);

  // Fetch the caption.
  var caption = Drupal.settings.stanford_gallery.captions[i];
  return caption;
};

// Add spoken feedback to the next/prev buttons.
jQuery(document).bind('cbox_complete', function() {
  jQuery("#cboxTitle .caption")
    .attr("role", "status")
    .attr("aria-live", "assertive");
});
