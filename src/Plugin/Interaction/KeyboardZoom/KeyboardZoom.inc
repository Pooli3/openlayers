<?php
/**
 * @file
 * Interaction: KeyboardZoom.
 */

/**
 * Plugin definition.
 */
function openlayers_KeyboardZoom_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\KeyboardZoom',
    ),
  );
}