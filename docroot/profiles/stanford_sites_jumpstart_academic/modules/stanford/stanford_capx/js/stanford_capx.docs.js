/**
 * @file
 * Renders the CAP Schema JSON tree.
 */

/**
 * Render the schema on page load.
 */
jQuery(document).ready(function () {

    jQuery('#capx-schema').tree({
        data: Drupal.settings.stanford_capx.schema,
        autoOpen: false,
        dragAndDrop: false
    });

    var xpand = jQuery("<a />")
                  .addClass("capx-schema-expand btn button")
                  .attr("name", "capx-xpandall")
                  .attr("href", "#")
                  .text("- Expand All -");

    xpand.click(function(e) {
      jQuery(".jqtree-closed")
      .removeClass("jqtree-closed")
    });


    var collapse = jQuery("<a />")
                    .addClass("capx-schema-collapse btn button")
                    .attr("name", "capx-collapseall")
                    .attr("href", "#")
                    .text("- Collapse All -");

    collapse.click(function(e) {
      jQuery(".jqtree-folder")
        .addClass("jqtree-closed");
    });

    jQuery(".capx-schema-controls").append(xpand);
    jQuery(".capx-schema-controls").append(collapse);

});
