/**
 * Creates autopopulation functionailty in javascript.
 * This is only for event node forms.
 * When a user selects a from time on data_popup fields the to value is
 * automatically populated with the same date and time +1 hour.
 *
 * @author Shea McKinney <sheamck@stanford.edu>
 *
 */


(function($){

  // Drupal Behaviours
  // ---------------------------------------------------------------------------


  Drupal.behaviors.stanford_events_importer = {
    attach: function (context, settings) {

      // Attach the blur handler to each date field.
      $.each($('.start-date-wrapper ', context), function(i, v) {
        var timefield = $(v).find('input:eq(1)');
        timefield.bind('blur.stanford_events_importer', from_time_blur_handler);
      });

    }
  };


  // Handlers and Callbacks
  // ---------------------------------------------------------------------------


  /**
   * Blur callback event handler for from time fields.
   * Adds functionality to add 1 hour to the 'to' time value in the
   * same field collection as the 'from' time value.
   */
  var from_time_blur_handler = function(e) {

    // First find the show end date checkbox and see if it is checked.
    var showend = $(this)
        .closest('.fieldset-wrapper')
        .find('.form-type-checkbox label:contains("Show End Date")')
        .siblings('input');
    var checked = showend.attr('checked');

    // If show end date is not checked then die.
    if (!checked) {
      return;
    }

    // Fields and variable definitions oh my!
    var fields = $(this)
                 .closest('.fieldset-wrapper')
                 .find('.end-date-wrapper input:not(.autopop-no-process)');
    var to_date_field   = fields.eq(0);
    var to_time_field   = fields.eq(1);
    var from_date_field = $(this)
                 .closest('.fieldset-wrapper')
                 .find('.start-date-wrapper input:eq(0)');
    var from_date_value = from_date_field.val();
    var from_time_value = $(this).val();
    var php_time_format = $(this).data('timeformat');

    // If we can't find the fields then we must end our journey.
    if (typeof to_date_field === undefined) { stanford_events_importer_unset_bind(this); return; }
    if (typeof to_time_field === undefined) { stanford_events_importer_unset_bind(this); return; }

    // Add a one time blur function to the 'to' time field so that when
    // the user manipulates that time manually we don't eff with it.
    to_time_field.one('blur', to_time_blur_handler);

    // If the date field is empty populate it.
    if (to_date_field.val().length === 0) {
      to_date_field.val(from_date_value);
    }

    // Date conversion needs 24hr format. Do some funny parsing.
    var from_time_value_twenty_four = stanford_events_importer_time_to_twenty_four(from_time_value);

    // Something went wrong. Die quietly.
    if(!from_time_value_twenty_four) { return; }

    // Format the new time appropriately.
    // Remove extra formatting
    var fdv = from_date_value.replace(/\-|\//g, ' ');
    var date_object = new Date(fdv + " " + from_time_value_twenty_four);

    // Something went wrong. Die quietly.
    if(date_object.toString() == "Invalid Date") { return; }

    // Add 1 hour to the time.
    date_object.setHours(date_object.getHours() + 1);

    // Get a properly formatted value based on what the PHP settings are.
    var formatted_time = stanford_events_importer_get_formatted_time(date_object, php_time_format);

    // Set the time field to the new date.
    to_time_field.val(formatted_time);
    to_time_field.quiet_highlight();

  };

  /**
   * An event handler to unbind the to_time_event_handler on blur.
   */
  var to_time_blur_handler = function(e) {
    // Fields and variable definitions oh my!
    var fields = $(this)
                 .closest('.fieldset-wrapper')
                 .find('.start-date-wrapper input');
    var from_time_field = fields.eq(1);

    // If we can't find the field then we must end our journey.
    if (typeof from_time_field === undefined) { return; }

    // Remove our blur handler.
    from_time_field.unbind('blur.stanford_events_importer');
  };





  // Public Functions
  // ---------------------------------------------------------------------------

  /**
   * Unbinds the blur event from something that doesnt need it.
   * @param  {object} element   the element with the blur event on it.
   */
  function stanford_events_importer_unset_bind(element) {
    $(element).unbind('blur.stanford_events_importer');
  }



  /**
   * Parse a time string eg: 4:33pm into a 24 hour time eg: 16:33
   * @param  {string} time a 12 hour time
   * @return {string} a 24 hour time
   */
  function stanford_events_importer_time_to_twenty_four(time) {

    // Invalid Syntax Provided.
    if (typeof time !== 'string' || time.length === 0) {
      return false;
    }

    // Define parts.
    var hours = Number(time.match(/^(\d+)/)[1]);
    var minutes = Number(time.match(/:(\d+)/)[1]);
    var seconds = time.match(/:(\d+)/)[2];
    var AMPM = time.match(/(am|pm)/gi);

    // If am/pm is found then look for pm and add 12hrs to the current time.
    if (AMPM instanceof Array) {
      if (AMPM[0].toLowerCase() == "pm" && hours <= 11) {
        hours = hours + 12;
      }
      if (AMPM[0].toLowerCase() == "am" && hours == 12) {
        hours = 0;
      }
    }

    // Convert Number to Strings times.
    var sHours = hours.toString();
    var sMinutes = minutes.toString();

    // Javascript and plugins like the preceeding 0s
    if(hours<10) sHours = "0" + sHours;
    if(minutes<10) sMinutes = "0" + sMinutes;

    // Construct formatted var.
    var formatted = sHours + ":" + sMinutes;

    // Add in seconds if seconds are present in the time.
    if(typeof seconds === 'string') {
      formatted += ":" + seconds;
    }

    // whew!
    return formatted;
  }


  /**
   * Parse a time into a format as defined by php.
   * @param  {object} date_object    [a date object]
   * @param  {string} php_format [the php string representation of the time
   * format we want]
   * @return {String}            [The formatted date string]
   */
  function stanford_events_importer_get_formatted_time(date_object, php_format) {

    var formatted = php_format;

    // Define date parts as string with preceeding 0s by default.
    var ampm = date_object.getHours() < 12 ? "am" : "pm";
    var hr_twentyfour = date_object.getHours() < 10 ? "0" + date_object.getHours().toString() : date_object.getHours().toString();
    var hr_twelve = hr_twentyfour;
    if (parseInt(hr_twelve, 10) > 12) { hr_twelve = parseInt(hr_twentyfour, 10) - 12; }
    if (hr_twelve == 0) { hr_twelve = 12; }
    hr_twelve = (hr_twelve < 10) ? "0" + hr_twelve : hr_twelve.toString();
    var min = date_object.getMinutes() < 10 ? "0" + date_object.getMinutes().toString() : date_object.getMinutes();
    var sec = date_object.getSeconds() < 10 ? "0" + date_object.getSeconds().toString() : date_object.getSeconds();

    // Hours.
    formatted = formatted.replace(/[H]/g, hr_twentyfour);
    formatted = formatted.replace(/[h]/g, hr_twelve);
    formatted = formatted.replace(/[g]/g, Math.round(hr_twelve));
    formatted = formatted.replace(/[G]/g, Math.round(hr_twentyfour));

    // Minutes.
    formatted = formatted.replace(/[i]/g, min);

    // Seconds.
    formatted = formatted.replace(/[s]/g, sec);

    // Am/Pm.
    formatted = formatted.replace(/[a]/g, ampm);
    formatted = formatted.replace(/[A]/g, ampm.toUpperCase());

    return formatted;
  }


// Jquery Plugins
// -----------------------------------------------------------------------------

  if(typeof $.fn.quiet_highlight !== "function") {
    /**
     * A quick yellow highlight that fades out.
     */
    $.fn.quiet_highlight = function() {

      $(this).each(function () {
        var el = $(this);
        el.css({position:"relative",zIndex:'1',background:"transparent"});
        el.parent().css({position:"relative"});

        var div = $("<div/>")
        .addClass('su-highlighter')
        .width(el.outerWidth())
        .height(el.outerHeight())
        .css({
            "position": "absolute",
            "left": 0,
            "top": 24,
            "background-color": "#ffff99",
            "opacity": ".7",
            "z-index": "0"
        });

        $(this).before(div);
        div.fadeOut(1000)
        .queue(function () {
          $(this).remove();
          el.css({background:"#FFFFFF"});
        });
      });
    };
  }
})(jQuery);
