(function ($) {

Drupal.behaviors.social_shareFieldsetSummaries = {
  attach: function (context) {
    $('fieldset#edit-social-share', context).drupalSetSummary(function (context) {
      if ($('input#edit-social-share-enabled').is(':checked')) {
        $('.social-share-settings-wrapper').show();

        var numNetworks = $('#edit-social-share-networks input[type=checkbox]').filter(':checked').length;
        var networkNames = [];
        $('#edit-social-share-networks input[type=checkbox]').filter(':checked').each(function() {
          networkNames.push($(this).siblings('label').html().trim());
        });

        if (numNetworks > 0) {
          return Drupal.t('Enabled: !networks !num', {'!num': Drupal.formatPlural(numNetworks, '<br />(1 social network)', '<br />(@count social networks)'), '!networks': networkNames.join(', ')});
        }
        else {
          return Drupal.t('Enabled');
        }
      }
      else {
        $('.social-share-settings-wrapper').hide();
        return Drupal.t('Disabled');
      }


    });
  }
};

})(jQuery);
