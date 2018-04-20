(function ($) {
  Drupal.behaviors.stanfordBeanTypesHero = {
    attach: function (context, settings) {

      var classes = ['hero-curtain', 'hero-static', 'hero-scroll'];
      var menu = $('<div>', {id: 'hero-menu', html: $('.region-navigation div > ul').clone()});
      if (!settings.stanford_bean_types_hero.heroMenu) {
        menu = null;
      }

      $.each(classes, function (i, heroClass) {
        // Move the hero to the top of the body tag.
        $('.' + heroClass, context).each(function (i, a, b) {
          var clonedBlock = $(this).detach().prependTo('body')
            .prepend($('#global-header').clone().attr('id', 'global-header-hero').append(menu));
          var wrapper = $('<div>', {class: heroClass + '-reveal'});
          $(clonedBlock).siblings().wrapAll(wrapper);
        });
      });

      function setFocusOut() {
        $.each(classes, function (i, heroClass) {
          var hero = $('.' + heroClass);
          // If focus is moved away from the hero, scroll to the top of the normal page.
          $(hero).find('a').last().focusout(function (e) {
            if ($(this).is(':visible')) {
              var topPage = $(hero).height();
              $('body').scrollTop(topPage);
            }
          })
        });
      }

      function heroSetSize() {
        var winHeight = $(window).height();
        $.each(classes, function (i, heroClass) {
          var heroAssets = $('.' + heroClass)
            .find('img, iframe');

          $(heroAssets).parent()
            .height(winHeight)
            .css('overflow', 'hidden');
        });
        $('.hero-curtain').css('padding-bottom', $('.hero-curtain-reveal').height());
      }

      function heroScroller() {
        $('.hero-scroll').append($('<a>', {
          class: 'scroll-down',
          href: '#',
          title: Drupal.t('Scroll Down'),
          'aria-label': Drupal.t('Scroll Down'),
          html: '<div class="scroll-text">' + Drupal.t('Scroll') + '</div><div class="fa fa-arrow-circle-o-down"></div>'
        }).click(function (e) {
          e.preventDefault();
          $("html, body").animate({scrollTop: $('.hero-scroll').height()}, 800);
        }));
      }

      $(window).scroll(function (e) {
        $.each(classes, function (i, heroClass) {
          var curtain = $('.' + heroClass);
          var scrollPos = 0 - $(curtain).height() + $(window).scrollTop();

          if (scrollPos < 0) {
            $('.' + heroClass + '-reveal').removeClass('below-hero');
            $(curtain).removeClass('below-hero');
          } else {
            $('.' + heroClass + '-reveal').addClass('below-hero');
            $(curtain).addClass('below-hero');
          }
        });
      });

      $(window).load(function () {
        if (typeof $.imagesLoaded !== 'undefined') {
          $('.hero-curtain').imagesLoaded(heroSetSize);
        } else {
          heroSetSize();
        }
        setFocusOut();
      });

      $(window).resize(heroSetSize);
      heroSetSize();
      heroScroller();
    }
  }
})(jQuery);
