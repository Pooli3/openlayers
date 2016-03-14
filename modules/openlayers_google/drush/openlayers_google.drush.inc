<?php
/**
 * @file
 * Drush integration for Openlayers Google Maps integration library.
 */

/**
 * Implements hook_drush_command().
 */
function openlayers_google_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['dl-openlayers-google'] = array(
    'callback' => 'drush_openlayers_google_plugin',
    'description' => dt('Download and install the Openlayers Google Maps integration library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Openlayers Google Maps integration library. If omitted Drush will use the default location.'),
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function openlayers_google_drush_help($section) {
  switch ($section) {
    case 'drush:dl-openlayers-google':
      return dt('Download and install the Openlayers Google Maps integration library from https://github.com/mapgears/ol3-google-maps, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the Openlayers Google Maps integration library.
 */
function drush_openlayers_google_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $library = libraries_detect('ol3-google-maps');

  // Download the archive.
  if ($filepath = drush_download_file($library['download url'])) {
    $filename = basename($filepath);
    $dirname = basename($filepath, '.zip');

    // Remove any existing Openlayers library directory.
    if (is_dir($dirname) || is_dir('ol3-google-maps')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('ol3-google-maps', TRUE);
      drush_log(dt('An existing Openlayers Google Maps integration library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the archive.
    drush_tarball_extract($filename);
    drush_move_dir($dirname, 'ol3-google-maps', TRUE);
    $dirname = 'ol3-google-maps';
  }

  if (is_dir($dirname)) {
    drush_log(dt('Openlayers Google Maps integration library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Openlayers Google Maps integration library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
