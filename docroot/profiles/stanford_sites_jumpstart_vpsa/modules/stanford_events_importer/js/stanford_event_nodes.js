Drupal.behaviors.stanford_event_nodes = {
  attach: function(context, settings) {
  (function ($) {
    $('.node-stanford-event .field-name-field-s-event-map-link a', context).prepend('<i class="icon-map-marker"></i> ');
    $('.node-stanford-event .field-name-field-s-event-map-link a', context).addClass('btn btn-sm');
  })(jQuery);
  }
};
