/**
 * @file
 * Fontawesome field widget.
 */

(function ($) {
  Drupal.behaviors.stanford_field_formatters = {
    attach: function (context, settings) {
      $('.stanford-fontawesome-icon', context).find('option').each(function () {
        $(this).addClass('fa').addClass('fa-' + $(this).attr('value'));
      });
      $('.stanford-fontawesome-icon').trigger("chosen:updated");
    }
  }
})(jQuery);
