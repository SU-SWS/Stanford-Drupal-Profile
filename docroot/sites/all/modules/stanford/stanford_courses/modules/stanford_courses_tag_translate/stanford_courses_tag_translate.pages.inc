<?php
/**
 * Pages and forms oh my!
 */

/**
 * The landing page for the this module's configuration.
 *
 * Displays a table of all of the tag translations sorted by the explore courses
 * tag, alpabetically.
 *
 * @return array
 *   Drupal render array.
 */
function stanford_courses_tag_translate_settings() {
  $render = array();

  // More configuration.
  $render["default_form"] = drupal_get_form("stanford_courses_tag_default_value_form");

  // Get the stuff out of the DB.
  $results = stanford_courses_tag_translate_get_translation_table();

  // If nothing there then provide some options.
  if (!$results) {

    $render["ttable"]["#markup"] = "<h3>" . t("No, translations found. Please start by !create or !import.",
        array(
          '!create' => l(t("creating one"), "admin/config/stanford/courses/tag-translate/new"),
          '!import' => l(t("importing some defaults"), "admin/config/stanford/courses/tag-translate/import"),
        )
      );
  }

  // Put all of the values in to one big table.
  if ($results) {
    $render["ttable"] = stanford_courses_tag_translate_get_table_list($results);
  }

  return $render;
}

/**
 * [stanford_courses_tag_default_value_form description]
 *
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 *
 * @return [type]             [description]
 */
function stanford_courses_tag_default_value_form($form, &$form_state) {

  $form["configgroup"] = array(
    "#type" => "fieldset",
    "#description" => t(""),
    "#title" => t("Default Settings"),
    "#collapsed" => FALSE,
    "#collaspible" => FALSE,
  );

  $form["configgroup"]["tag_default"] = array(
    "#type" => 'checkbox',
    "#title" => "Use the original source if no translation is available for a tag.",
    "#description" => t("Check this box to use the original source as the translation if no translation is provided below. If left unchecked, any tags that don't have a translation will be ignored."),
    "#default_value" => variable_get("stanford_courses_tag_translation_tag_default", ""),
    "#return_value" => "[original]",
  );

  $form["configgroup"]["submit"] = array(
    "#type" => "submit",
    "#value" => "Save",
  );


  return $form;
}

/**
 * [stanford_courses_tag_default_value_form_submit description]
 *
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 *
 * @return [type]              [description]
 */
function stanford_courses_tag_default_value_form_submit($form, &$form_state) {
  $values = $form_state["values"];
  $clean = check_plain($values["tag_default"]);
  variable_set("stanford_courses_tag_translation_tag_default", $clean);
  drupal_set_message(t("Default values successfully updated"));
}

/**
 * Return a table render array of the results from the db.
 *
 * @param array $results
 *   An associative array of database results from stanford_courses_tag.
 *
 * @return array
 *   A Drupal render array of a table.
 */
function stanford_courses_tag_translate_get_table_list($results = array()) {
  $render = array();

  // Render array defaults.
  $render["#theme"] = "table";
  $render["#header"] = array("Tag", "Translation", "Operations");
  $rows = array();

  // Loop through the results and create a row for each entry with options.
  foreach ($results as $values) {
    $opts = "";
    $opts .= l(t("Edit"), "admin/config/stanford/courses/tag-translate/edit/" . $values->ctid);
    $opts .= " | ";
    $opts .= l(t("Delete"), "admin/config/stanford/courses/tag-translate/delete/" . $values->ctid);

    $rows[] = array($values->ctag, $values->chuman, $opts);
  }

  // Add the rows and toss back to the caller.
  $render["#rows"] = $rows;
  return $render;
}


/**
 * Create a new tag translation form page.
 *
 * @return array
 *   A Drupal render array.
 */
function stanford_courses_tag_translate_new() {
  $render = array();
  drupal_set_title("Create new courses tag translation");

  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_fields_form");

  return $render;
}

/**
 * Create / Edit translate tag form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param string $ftype
 *   The form type as this form can be used for "edit" or "new".
 * @param object $tobj
 *   The translate object from the database.
 *
 * @return array
 *   The form array.
 */
function stanford_courses_tag_translate_fields_form($form, &$form_state, $ftype = "new", $tobj = NULL) {

  // Explore courses tag to translate from.
  $form["ctag"] = array(
    "#type" => 'textfield',
    "#description" => t('The tag used on explorecourses, e.g., "REGISTRAR::training"'),
    "#default_value" => isset($tobj->ctag) ? $tobj->ctag : "",
    "#required" => TRUE,
  );

  // The human readable version.
  $form["chuman"] = array(
    "#type" => 'textfield',
    "#description" => t("The human readable translation of the tag"),
    "#default_value" => isset($tobj->chuman) ? $tobj->chuman : "",
    "#required" => TRUE,
  );

  // The type of form that is being submitted. Used in validation and submit hooks.
  $form["ftype"] = array(
    '#type' => 'value',
    '#value' => $ftype,
  );

  // If on the edit form pass along the ctid.
  if (isset($tobj->ctid)) {
    $form["ctid"] = array(
      '#type' => 'value',
      '#value' => $tobj->ctid,
    );
  }

  // Who doesn't like big shiny buttons.
  $form["submit"] = array(
    '#type' => "submit",
    "#value" => t("Save"),
  );

  return $form;
}


/**
 * Create / Edit translate tag form validation.
 *
 * If the user is trying to create a new translation check for uniqueness. Can
 * only have one translation per tag.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function stanford_courses_tag_translate_fields_form_validate(&$form, &$form_state) {
  $values = $form_state["values"];

  // Only act on new items.
  if ($values['ftype'] == "new") {

    // Look for what was submitted in the database.
    $result = db_select('stanford_courses_tag', 'sct')
      ->fields('sct')
      ->condition("ctag", check_plain($values["ctag"]))
      ->execute();

    // If we get a result then throw up an error in that users face!
    if ($result->rowCount()) {
      form_set_error("ctag", t("Translation for that tag already exists. There can only be one translation per tag."));
    }

  }

}

/**
 * Create / Edit translate tag form submit.
 *
 * Save or update a tag translation. The presence of the CTID value in the
 * submission will let us know if we are updating or inserting.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function stanford_courses_tag_translate_fields_form_submit(&$form, &$form_state) {
  $values = $form_state["values"];

  // Protection against php notices.
  if (!isset($values['ctid'])) {
    $values['ctid'] = '';
  }

  // The insert array for drupal_write_record.
  $insert = array(
    "ctag" => strtoupper(filter_xss($values["ctag"])),
    "chuman" => filter_xss($values['chuman']),
    "ctid" => filter_xss($values['ctid']),
  );

  // If new then insert.
  if ($values["ftype"] == "new") {
    drupal_write_record("stanford_courses_tag", $insert);
  }
  else {
    drupal_write_record("stanford_courses_tag", $insert, "ctid");
  }

  // That was nice you to let the user know the process worked. Do you want to
  // redirect to another page? No, they probably have more to insert.
  drupal_set_message(t("Tag translation was saved successfully"), "status");
}


/**
 * The edit form menu callback.
 *
 * This is the home for the edit form of tag translations.
 *
 * @return [type] [description]
 */
function stanford_courses_tag_translate_edit($ctid) {
  $render = array();

  // $ctid is passed in through the menu hook and should be numeric but users
  // do funny things and we don't trust them hobbitses.
  if (!is_numeric($ctid)) {
    drupal_set_message(t("Invalid course tag translation id."), "error");
    return drupal_not_found();
  }

  // Ok, they've played along so far. Try to get the tag translation by the id.
  $tobj = stanford_courses_tag_translate_get_translation($ctid);

  if (!$tobj) {
    drupal_set_message(t("Invalid course tag translation id."), "error");
    return drupal_not_found();
  }

  // Got everything we need. Load up the form and give it back to the user.
  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_fields_form", "edit", $tobj);

  return $render;
}

/**
 * Delete confirmation page.
 *
 * All delete operations should have a confirmation step because Shea likes to
 * randomly click around on pages.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param int $ctid
 *   The id or index key for the tag translation.
 *
 * @return array
 *   A Drupal form.
 */
function stanford_courses_tag_translate_delete_form($form, &$form_state, $ctid) {

  // If not a valid param then we should stop doing more.
  if (!is_numeric($ctid)) {
    drupal_set_message(t("Invalid course tag translation id."), "error");
    drupal_not_found();
    exit();
  }

  // Get the translation from the DB. Just to be sure.
  $tobj = stanford_courses_tag_translate_get_translation($ctid);

  // If it wasn't there then die.
  if (!$tobj) {
    drupal_set_message(t("Invalid course tag translation id."), "error");
    drupal_not_found();
    exit();
  }

  // Put the value in the form so we can use it to delete stuff later.
  $form["ctid"] = array(
    "#type" => "value",
    "#value" => $ctid,
  );

  // Prompt the user to confirm their choices in life.
  $question = t("Are you sure you want to remove this tag translation?");
  $path = "admin/config/stanford/courses/tag-translate";
  $description = t("This action cannot be un-done. Choose wisely.");
  $yes = t("Yes, delete this forever");

  $form = confirm_form($form, $question, $path, $description, $yes);
  return $form;
}

/**
 * Confirm delete submit hook.
 *
 * If the user confirms they want to delete the tag translation we should
 * probably actually do that thing we asked them about.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 *
 */
function stanford_courses_tag_translate_delete_form_submit($form, &$form_state) {

  // Get the ctid from the form submission.
  $values = $form_state["values"];
  $ctid = check_plain($values["ctid"]);

  // With fire!
  db_delete("stanford_courses_tag")
    ->condition("ctid", $ctid)
    ->execute();

  // Ok, done. Now go back to the main page.
  drupal_set_message(t("Tag translation was successfully removed."), "status");
  drupal_goto("admin/config/stanford/courses/tag-translate");
}

/**
 * Import tag translations form.
 *
 * Get and render the import form. Also, provide a helpful little message saying
 * they are going to blow away everything that already exists.
 *
 */
function stanford_courses_tag_translate_import() {
  $render = array();

  // Caution: Like, for realz.
  drupal_set_message(t("WARNING: Importing new values will empty and replace all existing values. This action is not recoverable."), "warning");

  // Get basic form block.
  $render["theform"] = drupal_get_form("stanford_courses_tag_translate_export_form");
  $render["theform"]["txtxprt"]['#title'] = t("Import");

  // Done done delta 58.
  return $render;
}

/**
 * Validate the import submission.
 *
 * Don't trust your users and don't trust their input. Check to see if what
 * they are sending us is in a valid json format.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function stanford_courses_tag_translate_import_form_validate($form, &$form_state) {

  // Get the submission value.
  $values = $form_state["values"];
  $json = filter_xss($values["txtxprt"]);

  // Try to change this from json into something php can use.
  $decode = drupal_json_decode($json);

  // If it fails then prompt the user to fix it.
  if (!$decode) {
    form_set_error("txtxprt", t("Invalid input code. Please check the integrity of the export."));
  }

}

/**
 * Save the new translation set.
 *
 * The input should be valid json at this point. Clear out the existing values
 * and save what was passed.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function stanford_courses_tag_translate_import_form_submit($form, &$form_state) {

  // Get and decode the values from the input.
  $values = $form_state["values"];
  $json = filter_xss($values["txtxprt"]);
  $decode = drupal_json_decode($json);

  // Remove existing tag translations.
  db_truncate("stanford_courses_tag")->execute();

  // Save the new tag translations.
  foreach ($decode as $key => $value) {
    $insert = array("ctag" => $key, "chuman" => $value);
    drupal_write_record("stanford_courses_tag", $insert);
  }

  // Message and redirect.
  drupal_set_message(t("Import successful"), "status");
  drupal_goto("admin/config/stanford/courses/tag-translate");

}

/**
 * The export page menu callback.
 *
 * Get the values from the database and give them up to the user in a nice
 * ball of json so they may save or import this set in to another website.
 *
 * @return array
 *   A Drupal render array.
 */
function stanford_courses_tag_translate_export() {
  $render = array();

  // Get all the tag translations from the db.
  $results = stanford_courses_tag_translate_get_translation_table();

  // If nothing then say so...
  if (empty($results)) {
    $render["tmp"]["#markup"] = "<h3>" . t("Nothing to export.") . "</h3>";
    return $render;
  }

  // Loop through all the values and put in to an array for encoding.
  $xport_values = array();
  foreach ($results as $key => $values) {
    $xport_values[$key] = $values->chuman;
  }

  // Encode to json and format to be nice and pretty.
  $xport_code = drupal_json_encode($xport_values);
  $xport_code = str_replace("{\"", "{\n\"", $xport_code);
  $xport_code = str_replace("\"}", "\"\n}", $xport_code);
  $xport_code = str_replace("\":\"", "\": \"", $xport_code);
  $xport_code = preg_replace("\",\"", ",\n", $xport_code);

  // Stick the whole export in a textarea box and be done with it.
  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_export_form", $xport_code);

  // Shares a form with the input function. Don't let them do that here.
  unset($render["theform"]["submit"]);

  return $render;
}

/**
 * Import / Export form fields.
 *
 * The fields used in the import and export forms.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param string $default_value
 *   A blob of json.
 *
 * @return array
 *   a Drupal form array.
 */
function stanford_courses_tag_translate_export_form($form, &$form_state, $default_value) {

  // The big ol code block.
  $form["txtxprt"] = array(
    "#type" => "textarea",
    "#title" => t("Export code"),
    "#default_value" => $default_value,
    "#rows" => 30,
  );

  // Submit button.
  $form["submit"] = array(
    "#type" => "submit",
    "#value" => "Import",
  );

  // Add submit and validate hooks but only for the import form.
  $form["#validate"][] = "stanford_courses_tag_translate_import_form_validate";
  $form["#submit"][] = "stanford_courses_tag_translate_import_form_submit";

  return $form;
}
