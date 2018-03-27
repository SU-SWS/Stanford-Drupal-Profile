<?php
/**
 * @file
 * stanford_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "jw_player" && $api == "jw_player_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_video_node_info() {
  $items = array(
    'stanford_video' => array(
      'name' => t('Stanford Web Video'),
      'base' => 'node_content',
      'description' => t('The Stanford Web Video content type is a custom content type that affords the ability to publish a captioned video to your website via direct file upload or remote stream. Streaming video service is available from Stanford Video, <a href="http://stanfordvideo.stanford.edu/streaming/">http://stanfordvideo.stanford.edu/streaming/</a>. Video post-production and transcript generation can be found at <a href="http://captioning.stanford.edu">http://captioning.stanford.edu</a>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
