(function ($) {
  Drupal.behaviors.social_shareAdminSettings = {
    attach: function (context) {
      $('input[id^=edit-social-share-enabled-]').click(function() {
        var id = $(this).attr('id').replace('edit-', '');
        if ($(this).is(':checked')) {
          $('span#' + id + '-networks').show();
        }
        else {
          $('span#' + id + '-networks').hide();
        }
      });
    }
  };
})(jQuery);
