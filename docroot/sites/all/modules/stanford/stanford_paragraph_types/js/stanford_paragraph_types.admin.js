/**
 * @file
 * Applies some functionality on the paragraph types in the admin form.
 */

(function ($) {
  Drupal.behaviors.stanfordParagraphTypesAdmin = {
    attach: function (context, settings) {

      $('.field-name-field-p-icon-color option', context).each(function () {
        $(this).addClass('color-' + $(this).attr('value'));
      });

      $('.group-p-card-cta', context).each(function () {
        $group = this;
        $(this).find('.form-radio').each(function () {
          if ($(this).is(':checked')) {
            teaserCardsCTA($group, $(this).val());
          }
          $(this).change(function () {
            teaserCardsCTA($group, $(this).val());
          });
        });
      });

      $('.field-name-field-p-hero-style', context).each(function () {
        $style = $(this);

        $(this).find('.form-radio').each(function () {
          if ($(this).is(':checked')) {
            heroStyle($style, $(this).val());
          }
          $(this).change(function () {
            heroStyle($style, $(this).val());
          });
        });
      });

      // Used this method vs conditional_fields since the contrib module failed
      // to function correctly after a 2nd item was added.
      function teaserCardsCTA(group, radioVal) {
        if (radioVal == 'link') {
          $(group).find('.field-name-field-p-card-cta').show();
          $(group).find('.field-name-field-p-card-file').hide();
        }
        else {
          $(group).find('.field-name-field-p-card-cta').hide();
          $(group).find('.field-name-field-p-card-file').show();
        }
      }

      function heroStyle($style, radioVal) {
        if (radioVal == 'image') {
          $style.siblings('.field-name-field-p-hero-image').show();
          $style.siblings('.field-name-field-p-hero-video').hide();
        }
        else if (radioVal == 'video') {
          $style.siblings('.field-name-field-p-hero-image').hide();
          $style.siblings('.field-name-field-p-hero-video').show();
        }
        else {
          $style.siblings().show();
        }
      }

      $('.field-name-field-p-icon-icon-style input', context).change(function () {
        var fieldset = $(this).closest('fieldset');
        pIconStyleHideShow(fieldset, $(this).val());
      });

      function pIconGridStyle() {
        $('.field-name-field-p-icon-icon-style input:checked').each(function () {
          pIconStyleHideShow($(this).closest('fieldset'), $(this).val());
        });
      }

      function pIconStyleHideShow(fieldset, value) {
        var showFields = ['.field-name-field-p-icon-icon-style'];
        var hideFields = [];

        switch (value) {
          case 'icon':
            showFields.push('.field-name-field-p-icon-icon');
            hideFields.push('.field-name-field-p-icon-image');
            hideFields.push('.field-name-field-p-icon-text');
            break;

          case 'image':
            showFields.push('.field-name-field-p-icon-image');
            hideFields.push('.field-name-field-p-icon-icon');
            hideFields.push('.field-name-field-p-icon-text');
            break;

          case 'text':
            showFields.push('.field-name-field-p-icon-text');
            hideFields.push('.field-name-field-p-icon-icon');
            hideFields.push('.field-name-field-p-icon-image');
            break;

        }
        $.each(showFields, function (i, field) {
          $(fieldset).find(field).show().find('select').trigger('chosen:updated');
        });
        $.each(hideFields, function (i, field) {
          $(fieldset).find(field).hide();
        });
      }

      pIconGridStyle();
    }
  }
})(jQuery);
