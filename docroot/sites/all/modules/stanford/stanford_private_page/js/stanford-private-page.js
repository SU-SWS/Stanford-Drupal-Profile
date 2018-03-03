Drupal.behaviors.stanford_private_page = {
  attach: function(context, settings) {
    (function ($) {

      // Wysiwyg links.
      $(".private-link", context).stanfordPrivatePage();

      // Menu block.
      $("#block-menu-menu-menu-private-pages a", context).stanfordPrivatePage();

      // Page title altering.
      $(".node-type-stanford-private-page #page-title", context).stanfordPrivatePage({
        spokenText: Drupal.t(". Protected page.")
      });

    })(jQuery);
  }
};
