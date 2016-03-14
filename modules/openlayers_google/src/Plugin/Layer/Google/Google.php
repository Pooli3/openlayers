<?php
/**
 * @file
 * Layer: Vector.
 */

namespace Drupal\openlayers_google\Plugin\Layer\Google;

use Drupal\openlayers\Types\Layer;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Google.
 *
 * @OpenlayersPlugin(
 *  id = "Google"
 * )
 */
class Google extends Layer {
  /**
   * @inheritDoc
   */
  public function attached() {
    $attached = parent::attached();

    $attached['libraries_load'][] = array(
      'ol3-google-maps',
    );

    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return TRUE;
  }
}
