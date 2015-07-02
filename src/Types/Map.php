<?php
/**
 * @file
 * Class Map.
 */

namespace Drupal\openlayers\Types;
use Drupal\openlayers\Openlayers;

/**
 * Class Map.
 */
abstract class Map extends Object implements MapInterface {

  /**
   * @var string
   */
  protected $id;

  /**
   * {@inheritdoc}
   */
  public function init() {
    parent::init();
    $this->setOption('target', $this->getId());
  }

  /**
   * {@inheritdoc}
   */
  protected function buildCollection() {
    parent::buildCollection();

    foreach (Openlayers::getPluginTypes(array('style', 'map')) as $type) {
      foreach ($this->getOption($type . 's', array()) as $object) {
        if ($merge_object = Openlayers::load($type, $object)) {
          $this->getCollection()->merge($merge_object->getCollection());
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    if (!isset($this->id)) {
      $css_map_name = drupal_clean_css_identifier($this->machine_name);
      // Use uniqid to ensure we've really an unique id - otherwise there will
      // occur issues with caching.
      $this->id = drupal_html_id('openlayers-map-' . $css_map_name . '-' . uniqid('', TRUE));
    }

    return $this->id;
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $map = $this;
    $build = array();

    // Run prebuild hook to all objects who implements it.
    $map->preBuild($build, $map);

    $asynchronous = 0;
    foreach ($map->getCollection()->getFlatList() as $object) {
      // Check if this object is asynchronous.
      $asynchronous += (int) $object->isAsynchronous();
    }

    $settings = $map->getCollection()->getJS();
    $settings['map'] = $settings['map'][0];
    $settings = array(
      'data' => array(
        'openlayers' => array(
          'maps' => array(
            $map->getId() => $settings,
          ),
        ),
      ),
      'type' => 'setting',
    );

    // If this is asynchronous flag it as such.
    if ($asynchronous) {
      $settings['data']['openlayers']['maps'][$map->getId()]['map']['async'] = $asynchronous;
    }

    $attached = $map->getCollection()->getAttached();
    $attached['js'][] = $settings;

    $styles = array(
      'width' => $map->getOption('width'),
      'height' => $map->getOption('height'),
      'overflow' => 'hidden',
    );

    $css_styles = '';
    foreach ($styles as $property => $value) {
      $css_styles .= $property . ':' . $value . ';';
    }

    $build += array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'openlayers-container-' . $map->getId(),
        'style' => $css_styles,
        'class' => array(
          'contextual-links-region',
          'openlayers-container',
        ),
      ),
      'map' => array(
        '#theme' => 'html_tag',
        '#tag' => 'div',
        '#value' => '',
        '#attributes' => array(
          'id' => $map->getId(),
          'class' => array(
            'openlayers-map',
            $map->machine_name,
          ),
        ),
        '#attached' => $attached,
      ),
    );

    // If this is an asynchronous map flag it as such.
    if ($asynchronous) {
      $build['map']['#attributes']['class'][] = 'asynchronous';
    }

    $map->postBuild($build, $map);

    return $build;
  }

  /**
   * @inheritdoc
   */
  public function getJS() {
    $js = parent::getJS();

    foreach(Openlayers::getPluginTypes() as $type) {
      unset($js['opt'][$type . 's']);
    }

    // Add the id to the JS settings.
    $js['map_id'] = $this->getId();

    return $js;
  }
}
