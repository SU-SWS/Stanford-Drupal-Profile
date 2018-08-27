<?php
/**
 * @file
 * stanford_video.jw_player_presets.inc
 */

/**
 * Implements hook_default_jw_player_presets().
 */
function stanford_video_default_jw_player_presets() {
  $export = array();

  $jw_player_preset = new stdClass();
  $jw_player_preset->disabled = FALSE; /* Edit this to true to make a default jw_player_preset disabled initially */
  $jw_player_preset->api_version = 1;
  $jw_player_preset->preset_name = 'Stanford Web Video 320x240';
  $jw_player_preset->machine_name = 'stanford_web_video_320_240';
  $jw_player_preset->description = 'Default 320x240 (small) configuration for Stanford Web Video';
  $jw_player_preset->settings = array(
    'mode' => 'flash',
    'width' => '320',
    'height' => '240',
    'controlbar' => 'over',
    'skin' => '',
    'autoplay' => 0,
  );
  $export['stanford_web_video_320_240'] = $jw_player_preset;

  $jw_player_preset = new stdClass();
  $jw_player_preset->disabled = FALSE; /* Edit this to true to make a default jw_player_preset disabled initially */
  $jw_player_preset->api_version = 1;
  $jw_player_preset->preset_name = 'Stanford Web Video 640x480';
  $jw_player_preset->machine_name = 'stanford_web_video_640_480';
  $jw_player_preset->description = 'Default 640x480 configuration for Stanford Web Video';
  $jw_player_preset->settings = array(
    'mode' => 'flash',
    'width' => '640',
    'height' => '480',
    'controlbar' => 'over',
    'skin' => '',
    'autoplay' => 0,
  );
  $export['stanford_web_video_640_480'] = $jw_player_preset;

  return $export;
}
