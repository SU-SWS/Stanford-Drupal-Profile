(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.contextListActive = {
    attach: function (context, settings) {
      // Attach the toggle behavior to the link in the overlay and the link at the bottom of the page (only used when
      // admin_menu is not present
      $('#context_list_active-overlay .context-list-active-toggle, #context-list-active-bottom .context-list-active-toggle', context).click(function (e) {
        $('#context_list_active-overlay').toggle();
        return false;
      });
    }
  };

  Drupal.admin = Drupal.admin || {};
  Drupal.admin.behaviors = Drupal.admin.behaviors || {};

  /**
   * @ingroup admin_behaviors
   * @{
   */

  /**
   * Toggles the context browser when clicked from the admin menu
   */
  Drupal.admin.behaviors.contextBrowserToggle = function (context, settings, $adminMenu) {
    var $toggle = $adminMenu.find('.context-list-active-toggle');
    $toggle.click(function () {
      $('#context_list_active-overlay').toggle();
      return false;
    });
  };

  /**
   * @} End of "ingroup admin_behaviors".
   */
})(jQuery, Drupal, this, this.document); //END - Closure