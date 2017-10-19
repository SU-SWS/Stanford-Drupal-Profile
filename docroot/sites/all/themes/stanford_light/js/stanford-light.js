(function($) {
    Drupal.behaviors.stanford_light = {
        attach: function(context, settings) {

            if ($('#wrap').outerHeight(true) < $(window).height()) {
                $('#push').css('height', $('#footer').outerHeight(true));
                $('#wrap').css('margin-bottom', 0 - $('#push').outerHeight(true));
            }
        }
    }
}(jQuery));
