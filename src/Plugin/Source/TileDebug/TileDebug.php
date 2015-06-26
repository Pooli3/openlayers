<?php
/**
 * @file
 * Source: TileDebug.
 */

namespace Drupal\openlayers\Plugin\Source\TileDebug;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Plugin\Type\Source;

/**
 * Class TileDebug.
 *
 * @Plugin(
 *  id = "TileDebug"
 * )
 *
 */
class TileDebug extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['maxZoom'] = array(
      '#title' => t('Maxzoom'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('maxZoom', 22),
    );
  }

}
