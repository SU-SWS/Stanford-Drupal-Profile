/**
 * Fix the sticky headers of the views matrix table.
 *
 */

/**
 * On the page load also adjust the values.
 * @type {Object}
 */
Drupal.behaviors.stanford_courses_matrix = {
  attach: function(context, settings) {
    (function ($) {
      // Add our own scrolling helper.
      $(window).bind('scroll.stanford-courses-matrix-tableheader', function() {
        stanford_course_matrix_resize_sticky_header();
      });

      // Add our own resize where we resize the headings after.
      $(window).bind('resize.stanford-courses-matrix-tableheader', function() {
        stanford_course_matrix_resize_sticky_header();
      });

      // Resize and place the header in the right part.
      stanford_course_matrix_resize_sticky_header();
    })(jQuery);
  }
};

/**
 * Match the table heading cell widths and align with table.
 */
function stanford_course_matrix_resize_sticky_header() {

  // Get the header if available.
  var sticky = jQuery(".view-stanford-courses-matrix table.sticky-header");
  var main = jQuery(".view-stanford-courses-matrix table.views-matrix");

  // Set the header rows of the sticky table to the same width as the main table.
  var sheads = sticky.find("thead th, thead td");
  main.find("thead th, thead td").each(function(i, v) {
    sheads.eq(i).width(jQuery(v).width());
  });

}
