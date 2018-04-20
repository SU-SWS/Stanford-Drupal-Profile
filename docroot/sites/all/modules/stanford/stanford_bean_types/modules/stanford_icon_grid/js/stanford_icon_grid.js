/**
 * @file
 * Fontawesome field widget.
 */

(function ($) {
  Drupal.behaviors.stanford_icon_grid = {
    attach: function (context, settings) {
      $('.field-name-field-s-icon-ext-columns-bg-colo option', context).each(function () {
        var values = $(this).attr('value');
        values = values.split(',');
        $(this).css('background-color', values[0]);
        if (values[1] !== undefined) {
          $(this).css('color', values[1]);
        }
      });

      $('.field-name-field-s-icon-ext-columns-style input', context).change(function () {
        var fieldset = $(this).closest('fieldset');
        iconStyleHideShow(fieldset, $(this).val());
      });

      function iconGridStyle() {
        $('.field-name-field-s-icon-ext-columns-style input:checked').each(function () {
          iconStyleHideShow($(this).closest('fieldset'), $(this).val());
        });
      }

      function iconStyleHideShow(fieldset, value) {
        var showFields = ['.field-name-field-s-icon-ext-columns-style'];
        var hideFields = [];

        switch (value) {
          case 'icon':
            showFields.push('.field-name-field-s-icon-ext-columns-fa-icon');
            hideFields.push('.field-name-field-s-icon-ext-columns-up-icon');
            hideFields.push('.field-name-field-s-icon-ext-columns-text');
            break;

          case 'image':
            showFields.push('.field-name-field-s-icon-ext-columns-up-icon');
            hideFields.push('.field-name-field-s-icon-ext-columns-fa-icon');
            hideFields.push('.field-name-field-s-icon-ext-columns-text');
            break;

          case 'text':
            showFields.push('.field-name-field-s-icon-ext-columns-text');
            hideFields.push('.field-name-field-s-icon-ext-columns-fa-icon');
            hideFields.push('.field-name-field-s-icon-ext-columns-up-icon');
            break;

        }
        $.each(showFields, function (i, field) {
          console.log('here');
          $(fieldset).find(field).show().find('select').trigger('chosen:updated');
        });
        $.each(hideFields, function (i, field) {
          $(fieldset).find(field).hide();
        });
      }

      iconGridStyle();
    }
  }
})(jQuery);
