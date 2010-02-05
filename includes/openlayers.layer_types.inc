<?php
// $Id$

/**
 * @file
 * This file contains layer types implementations
 *
 * @ingroup openlayers
 */

/**
 * Layer Type Implementation
 *
 * Internal callback for openlayers layer types implementation.
 *
 * @return
 *   Array of layer types
 */
function _openlayers_openlayers_layer_types() {
  return array(
    'openlayers_layer_type_google' => array(
      'title' => t('Google'),
      'description' => t('Google Maps API Map'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') .'/includes/layer_types',
        'file' => 'google.inc',
        'class' => 'openlayers_layer_type_google',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_yahoo' => array(
      'title' => t('Yahoo'),
      'description' => t('Yahoo Maps API Map'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') .'/includes/layer_types',
        'file' => 'yahoo.inc',
        'class' => 'openlayers_layer_type_yahoo',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_virtualearth' => array(
      'title' => t('Virtual Earth'),
      'description' => t('Microsoft Virtual Earth'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') .'/includes/layer_types',
        'file' => 'virtualearth.inc',
        'class' => 'openlayers_layer_type_virtualearth',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_cloudmade' => array(
      'title' => t('CloudMade'),
      'description' => t('CloudMade'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') .'/includes/layer_types',
        'file' => 'cloudmade.inc',
        'class' => 'openlayers_layer_type_cloudmade',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_wms' => array(
      'title' => t('WMS'),
      'description' => t('Web Map Service'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') . '/includes/layer_types',
        'file' => 'wms.inc',
        'class' => 'openlayers_layer_type_wms',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_tms' => array(
      'title' => t('TMS'),
      'description' => t('Tiled Map Service'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') . '/includes/layer_types',
        'file' => 'tms.inc',
        'class' => 'openlayers_layer_type_tms',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_osm' => array(
      'title' => t('OSM'),
      'description' => t('OpenStreetMap Standard'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') . '/includes/layer_types',
        'file' => 'osm.inc',
        'class' => 'openlayers_layer_type_osm',
        'parent' => 'openlayers_layer_type',
      ),
    ),
    'openlayers_layer_type_xyz' => array(
      'title' => t('XYZ'),
      'description' => t('XYZ'),
      'layer_type' => array(
        'path' => drupal_get_path('module', 'openlayers') . '/includes/layer_types',
        'file' => 'xyz.inc',
        'class' => 'openlayers_layer_type_xyz',
        'parent' => 'openlayers_layer_type',
      ),
    ),
  );
}