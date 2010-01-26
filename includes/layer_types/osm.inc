<?php
// $Id$

/**
 * @file
 * Yahoo Layer Type
 */
 
class openlayers_layer_type_osm extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if ($this->data) {
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'layer_handler' => 'xyz',
      'layer_type' => 'osm',
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
      'base_url' => array(
        '#type' => 'textfield',
        '#title' => t('Base URL'),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    return $this->options;
  }
}