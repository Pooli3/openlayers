Drupal.openlayers.openlayers__component__autopopup = function(data) {
  var map = data.map;

  var container = jQuery('<div/>', {
    id: 'popup',
    'class': 'ol-popup'
  }).appendTo('body');
  var content = jQuery('<div/>', {
    id: 'popup-content'
  }).appendTo('#popup');
/*
  var closer = jQuery('<a/>', {
    href: '#',
    id: 'popup-closer',
    'class': 'ol-popup-closer'
  }).appendTo('#popup');
*/
  var container = document.getElementById('popup');
  var content = document.getElementById('popup-content');
  var closer = document.getElementById('popup-closer');

  /**
   * Add a click handler to hide the popup.
   * @return {boolean} Don't follow the href.
   */
  /*
  closer.onclick = function() {
    container.style.display = 'none';
    closer.blur();
    return false;
  };
  */

  /**
   * Create an overlay to anchor the popup to the map.
   */
  var overlay = new ol.Overlay({
    element: container
  });

  map.addOverlay(overlay);

  map.getLayers().forEach(function(layer) {
    var source = layer.getSource();
    if (source.machine_name === data.options.source) {
      source.on('change', function(evt) {
        var feature = source.getFeatures()[0];
        var coordinates = feature.getGeometry().flatCoordinates;
        if (feature) {
          var name = feature.get('name') || '';
          var description = feature.get('description') || '';

          overlay.setPosition(coordinates);
          content.innerHTML = '<div class="ol-popup-name">' + name + '</div><div class="ol-popup-description">' + description + '</div>';
          container.style.display = 'block';

          if (data.options.enableAnimations == 1) {
            var pan = ol.animation.pan({duration: data.options.animations.pan, source: map.getView().getCenter()});
            var zoom = ol.animation.zoom({duration: data.options.animations.zoom, resolution: map.getView().getResolution()});
            map.beforeRender(pan, zoom);
          }
          var dataExtent = feature.getGeometry().getExtent();
          map.getView().fitExtent(dataExtent, map.getSize());
          map.getView().setZoom(data.options.zoom);
        }
      }, source);

    }
  });
};
