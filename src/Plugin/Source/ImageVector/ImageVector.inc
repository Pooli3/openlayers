<?php
/**
 * @file
 * Source: ImageVector.
 */

/**
 * Plugin definition.
 */
function openlayers_ImageVector_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Source\\ImageVector',
    ),
  );
}