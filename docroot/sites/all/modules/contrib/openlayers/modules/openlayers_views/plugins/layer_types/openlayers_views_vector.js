
/**
 * OpenLayers Views Vector Layer Handler
 */
Drupal.openlayers.layer.openlayers_views_vector = function(title, map, options) {
  // More explanations on this at: https://drupal.org/node/1993172#comment-7819199
  if (typeof(Drupal.settings.openlayers.maps[map.id]) !== undefined) {
    Drupal.settings.openlayers.maps[map.id] = undefined;
  }

  // Note, so that we do not pass all the features along to the Layer
  // options, we use the options.options to give to Layer
  options.options.drupalID = options.drupalID;
  // Allow to set z-order of features (#2241477)
  options.options.rendererOptions = {yOrdering: true};
  // Create projection
  options.projection = new OpenLayers.Projection(options.projection);
  // Get style map
  options.options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  // Create layer object
  var layer = new OpenLayers.Layer.Vector(title, options.options);

  // Add features if there are any
  if (options.features) {
    Drupal.openlayers.addFeatures(map, layer, options.features);
  }

  return layer;
};
