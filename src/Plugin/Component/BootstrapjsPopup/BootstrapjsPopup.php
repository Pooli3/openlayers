<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Plugin\Component\BootstrapjsPopup;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Plugin\Type\Component;

/**
 * Class BootstrapjsPopup.
 *
 * @Plugin(
 *  id = "BootstrapjsPopup"
 * )
 *
 */
class BootstrapjsPopup extends Component {

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array('bootstrapjs');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrapjs',
    );
  }

}
