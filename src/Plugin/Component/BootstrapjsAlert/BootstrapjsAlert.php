<?php
/**
 * @file
 * Component: Bootstrap JS.
 */

namespace Drupal\openlayers\Plugin\Component\BootstrapjsAlert;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Plugin\Type\Component;

/**
 * Class BootstrapjsAlert.
 *
 * @Plugin(
 *  id = "BootstrapjsAlert"
 * )
 *
 */
class BootstrapjsAlert extends Component {

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

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['message'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to display'),
      '#default_value' => $this->getOption('message'),
    );
  }

}
