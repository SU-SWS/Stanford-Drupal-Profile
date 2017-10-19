<?php
/**
 * @file
 * Theme functions.
 */

/**
 * Implements hook_theme().
 */
function stanford_capx_theme($existing, $type, $theme, $path) {
  return array(
    'stanford_capx_columns_to_the_right' => array(
      'render element' => '',
    ),
  );
}

/**
 * Themes a form container by putting some information to the left and
 * all of the fields to the right in a consistent table. Uses global striping.
 * @return [type] [description]
 */
function theme_stanford_capx_columns_to_the_right($elements) {

  // Take the first element.
  $element = array_shift($elements);

  global $stanford_capx_theme_zebra;
  $stanford_capx_theme_zebra = ($stanford_capx_theme_zebra == "even") ? "odd" : "even";

  // Header row cell information.
  $header = array("<b>" . t(check_plain($element['#title'])) . "</b>", t('CAP API Path'));

  // Grab the description from either the field_info or instance info.
  $description = "";
  if (isset($element['#field_info']['description'])) {
    $description = $element['#field_info']['description'];
  }
  elseif (isset($element['#field_instance_info']['description'])) {
    $description = $element['#field_instance_info']['description'];
  }

  // Left cell content.
  $info = "";
  if (isset($element['#field_info']['field_name'])) {
    $info .= "<p><b>Machine Name</b>: <em>" . $element['#field_info']['field_name'] . "</em></p>";
  }
  $info .= "<p><b>Description</b>: " . check_plain($description) . "</p>";

  // Set the required text on the left cell.
  $req = t("FALSE");
  if (!empty($element["#attributes"]['class']) && in_array("required", $element['#attributes']['class'])) {
    $req = "<b>" . t("TRUE") . "</b>";
    $element['#children'] = preg_replace("/\<\/label>/", " <span class=\"form-required\" title=\"" . t("This field is required") . ".\">*</span>$0", $element['#children']);
  }

  // Set up the rows even though there will only be one.
  $rows = array();
  $rows[] = array(
    'data' => array(
      array('data' => $info, 'class' => 'info-cell', 'style' => 'width: 60%;'),
      array('data' => $element['#children']),
    ),
    'class' => array($stanford_capx_theme_zebra),
    'no_striping' => TRUE,
  );

  // Render and go!
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'class' => 'capx_mapper_table',
  ));

  return $output;
}
