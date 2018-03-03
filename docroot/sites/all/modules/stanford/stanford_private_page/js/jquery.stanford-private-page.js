// @see: https://github.com/jquery-boilerplate
//
// the semi-colon before function invocation is a safety net against concatenated
// scripts and/or other plugins which may not be closed properly.
;(function ( $, window, document, undefined ) {

  "use strict";

    // undefined is used here as the undefined global variable in ECMAScript 3 is
    // mutable (ie. it can be changed by someone else). undefined isn't really being
    // passed in so we can ensure the value of it is truly undefined. In ES5, undefined
    // can no longer be modified.

    // window and document are passed through as local variable rather than global
    // as this (slightly) quickens the resolution process and can be more efficiently
    // minified (especially when both are regularly referenced in your plugin).

    // Create the defaults once
    var pluginName = "stanfordPrivatePage";
    var defaults = {
      spokenText: ". Requires login"
    };

    // The actual plugin constructor
    function Plugin ( element, options ) {
      this.element = element;
      this.settings = $.extend( {}, defaults, options );
      this._defaults = defaults;
      this._name = pluginName;
      this.init();
    }

    // Avoid Plugin.prototype conflicts
    $.extend(Plugin.prototype, {
      init: function () {
        // this.yourOtherFunction("jQuery Boilerplate");

        var element = $(this.element);
        var spokenText = element.text() + " ";
        var iconText = element.attr("title");

        if (typeof iconText !== "undefined" && iconText.length > 0) {
          spokenText += iconText;
        }
        else {
          spokenText += this.settings.spokenText;
        }

        element.attr("aria-label", spokenText);
        element.removeAttr('alt');

      },
      yourOtherFunction: function (text) {
        // some logic
        $(this.element).text(text);
      }
    });

    // A really lightweight plugin wrapper around the constructor,
    // preventing against multiple instantiations
    $.fn[ pluginName ] = function ( options ) {
      return this.each(function() {
        if ( !$.data( this, "plugin_" + pluginName ) ) {
          $.data( this, "plugin_" + pluginName, new Plugin( this, options ) );
        }
      });
    };

})( jQuery, window, document );
