(function ($) {

  /**
   * Attaches a JW Player element by using the JW Player Javascript Library
   */
  Drupal.behaviors.JWPlayer = {
    attach: function(context) {
      var players = Drupal.settings.jw_player;
      $.each(players, function(player_id, config) {
        if ($('#' + player_id, context).length) {
          jwplayer(player_id).setup(config);

          if (config.events) {
            $.each(config.events, function(event, callback) {
              jwplayer(player_id)[event](eval(callback));
            });
          };
        }
      });
    }
  };

})(jQuery);
