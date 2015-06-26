<?php
/**
 * @file
 * Source: KML.
 */

namespace Drupal\openlayers\Plugin\Source\KML;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Plugin\Type\Source;

/**
 * Class KML.
 *
 * @Plugin(
 *  id = "KML"
 * )
 *
 */
class KML extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
  }
}
