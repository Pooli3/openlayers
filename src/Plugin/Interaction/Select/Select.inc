<?php
/**
 * @file
 * Interaction: Select.
 */

/**
 * Plugin definition.
 */
function openlayers_Select_openlayers_interaction() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Interaction\\Select',
    ),
  );
}