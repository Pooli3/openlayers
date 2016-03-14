Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Google',
  init: function(data) {
    var options = {
      visible: 1
    };

    return new olgm.layer.Google(options);
  },
  attach: function(context, settings) {
    // There seem cases in which google is already defind, but the loading isn't
    // finished, so make sure we'll wait till the loading is complete before
    // calling the initialize function ourselves.
    if (Drupal.openlayers.pluginManager.getPlugin('openlayers.Layer:Google').scriptLoading) {
      return;
    }
    if (typeof google === 'undefined') {
      Drupal.openlayers.pluginManager.getPlugin('openlayers.Layer:Google').scriptLoading = true;

      var params = {
        v: 3.22,
        callback: 'Drupal.openlayers.openlayers_layer_internal_google_initialize'
      };

      // Add the script with the collected settings.
      var script = document.createElement('script');
      script.type = 'text/javascript';
      script.src = 'https://maps.googleapis.com/maps/api/js?' + jQuery.param(params);
      document.body.appendChild(script);
    }
    else {
      // Google API already available - initialize right away.
      Drupal.openlayers.openlayers_layer_internal_google_initialize();
    }
  },
  /**
   * Attaches the gmap API by loading the script.
   * Evaluates all google maps sources and uses the most complex set of settings.
   * Attention: It's not possible to have maps with different key, channel or
   * client parameters.
   */
  scriptLoading: false
});

/**
 * Callback to initialize all google maps as soon as the gmap API is available.
 */
Drupal.openlayers.openlayers_layer_internal_google_initialize = function() {
  Drupal.openlayers.pluginManager.getPlugin('openlayers.Layer:Google').scriptLoading = false;
  jQuery('.openlayers-map').each(function() {
    var map_id = jQuery(this).attr('id');
    var callback = Drupal.openlayers.asyncIsReadyCallbacks[map_id.replace(/[^0-9a-z]/gi, '_')];
    if (callback !== undefined) {
      callback();
    }
  });
};

(function ($, Drupal) {

  "use strict";

  $(document).on('openlayers.build_stop', function (event, objects) {
    objects.map.getLayers().forEach(function(layer) {
      if (layer instanceof olgm.layer.Google) {
        var olGM = new olgm.OLGoogleMaps({map: objects.map});
        olGM.activate();
      }
    });
  });

}(jQuery, Drupal));

