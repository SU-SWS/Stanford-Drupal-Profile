<?php
/**
 * @file
 * Display the JW Player.
 *
 * Variables available:
 * - $html_id: Unique id generated for each video.
 * - $width: Width of the video player.
 * - $height: Height of the video player.
 * - $file_url: The url of the file to be played.
 * - $jw_player_inline_js_code: JSON data with configuration settings for the video player.
 * - $poster: URL to an image to be used for the poster (ie. preview image) for this video.
 * - $streaming: boolean; 1 if this is a streaming video
 *
 * @see template_preprocess_jw_player()
 */
$source = '<source src="' . $file_url . '"';
if(isset($file_mime)){
  $source .= ' type="' . $file_mime .'"';
}
$source .= ' />';
?>
<div class="jwplayer-video">
  <video id="<?php print $html_id ?>" width="<?php print $width ?>" height="<?php print $height ?>" controls="controls" preload="none"<?php if(isset($poster)) : ?> poster="<?php print $poster ?>"<?php endif ?>>
  <?php
    if($streaming != 1){
      print $source;
    }
  ?>
  Your browser does not support this video type.
  </video>
</div>
<?php if(isset($jw_player_inline_js_code)): ?>
  <script type="text/javascript">
    jwplayer('<?php print $html_id ?>').setup(<?php print $jw_player_inline_js_code?>);
  </script>
<?php endif ?>
