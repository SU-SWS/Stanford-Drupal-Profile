Drupal.behaviors.stanfordframeworkthemesettings = {
  // Constructor
  attach: function(context, settings) {
    (function ($) {

      // Add active class on click to radio groups.
      var radiogroups = $(".form-radios", context);
      $.each(radiogroups, function(i, v) {

        var myitems = $(v).find('.form-type-radio');
        myitems.click(function(e) {
          $(this).parent().children().removeClass('active');
          $(this).addClass('active');
        });

        // If checked add the active class.
        myitems.find('input:checked').parents('.form-type-radio:first').addClass('active');

      });

    })(jQuery);
  }
};
