/**
 * @file
 * Applies some functionality on the paragraph types.
 */

(function ($) {
  Drupal.behaviors.stanfordParagraphTypes = {
    attach: function (context, settings) {
      $('.field-name-field-p-hero-image', context).each(function () {
        var video = $(this).siblings('.field-name-field-p-hero-video');

        if (video.length) {
          $(video).find('iframe').attr('title', Drupal.t('Video Player'));
          var videoUrl = $(video).find('div[data-video-embed-url]').attr('data-video-embed-url');

          var play = $('<a>', {
            class: 'play-video',
            href: videoUrl,
            html: $('<i>', {
              class: 'fa fa-youtube-play icon-youtube-play',
              html: 'Play Video',
              'aria-label': Drupal.t('Play Video - Opens to the video website')
            })
          }).click(function (e) {

            // Mouse has eventPhase 3, keyboard has 2.
            if (e.eventPhase == 3) {
              e.preventDefault();
              $dad = $(this).parent();
              $dad.hide();
              $dad.siblings('.group-overlay-text').hide();
              var iframe = $(video).find('iframe')[0];

              iframe.src += "&autoplay=1";
              $(iframe).attr('onload', 'this.contentWindow.focus()');
              $(video).show();
            }

          });

          $(this).prepend(play);
        }
      });
    }
  }
})(jQuery);
