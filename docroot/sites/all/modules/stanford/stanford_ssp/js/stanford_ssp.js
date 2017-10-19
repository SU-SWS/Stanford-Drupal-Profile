Drupal.behaviors.yourvariablehere = {
  attach: function(context, settings) {

  (function ($) {

    // On the load. Hide the add roles table if none is the action selected.
    var init = $("input[name='stanford_ssp_auth_role_map']:checked", context).val();
    if (init == "none") {
      $(".add-roles-table").hide();
    }
    else {
      $(".add-roles-table").show();
    }

    // On a Change. Hide the add roles table if none is the action selected.
    $("input[name='stanford_ssp_auth_role_map']", context).change(function() {
      var action = $("input[name='stanford_ssp_auth_role_map']:checked").val();
      if (action == "none") {
        $(".add-roles-table").hide();
      }
      else {
        $(".add-roles-table").show();
      }
    });

  })(jQuery);

  }
};
