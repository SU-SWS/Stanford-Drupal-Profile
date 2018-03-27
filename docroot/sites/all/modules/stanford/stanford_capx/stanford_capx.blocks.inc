<?php

/**
 * @file
 * A place to put your blocks.
 */

use CAPx\Drupal\Util\CAPxConnection;
use CAPx\Drupal\Util\CAPxImporter;
use CAPx\Drupal\Util\CAPxMapper;

/**
 * Implements hook_block_info().
 */
function stanford_capx_block_info() {
  $blocks = array();

  $blocks['connection_status'] = array(
    'info' => t('Connection Status'),
    'cache' => DRUPAL_NO_CACHE,
    'properties' => array('administrative' => 1),
  );

  $blocks['data_browser_launch'] = array(
    'info' => t('Selecting fields'),
    'cache' => DRUPAL_NO_CACHE,
    'properties' => array('administrative' => 1),
    'region' => 'help',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'admin/config/capx/mapper/*',
  );

  $blocks['importer_in_use'] = array(
    'info' => t('Importer In Use'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
    'properties' => array('administrative' => 1),
    'region' => 'help',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'admin/config/capx/importer/edit/*',
  );

  $blocks['mapper_in_use'] = array(
    'info' => t('Mapping In Use'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
    'properties' => array('administrative' => 1),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'admin/config/capx/mapper/edit/*',
  );

  $blocks['capx_management_menu'] = array(
    'info' => t('CAPX management menu'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'properties' => array('administrative' => 1),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'admin/config/capx*',
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function stanford_capx_block_view($delta = '') {
  $block = array();

  switch ($delta) {

    case 'connection_status':
      $block['subject'] = t('Connection Status');
      $block['content'] = stanford_capx_connection_status_block();
      break;

    case "data_browser_launch":
      $block['subject'] = t('Data Browser');
      $block['content'] = stanford_capx_data_browser_launch_block();
      break;

    case "importer_in_use":
      $block['subject'] = t('Importer In Use');
      $block['title'] = t('Importer In Use');
      $block['content'] = stanford_capx_importer_in_use_block();
      break;

    case "mapper_in_use":
      $block['subject'] = t('Mapping In Use');
      $block['title'] = t('Mapping In Use');
      $block['content'] = stanford_capx_mapper_in_use_block();
      break;

    case "capx_management_menu":
      $block['subject'] = t('CAPX Management Menu');
      $block['title'] = "<none>";
      $block['content'] = stanford_capx_management_menu_block();

  }

  return $block;
}

/**
 * Connection status block content callback.
 *
 * Tests the API connection and outputs a text message.
 *
 * @return string
 *   Block content.
 */
function stanford_capx_connection_status_block() {
  $content = '';
  $connection = CAPxConnection::testConnection();

  // Try to authenticate if not connected first try.
  if (!$connection->status) {
    CAPxConnection::renewConnectionToken();
    $connection = CAPxConnection::testConnection();
  }

  // We good now!
  if ($connection->status) {
    $total_profiles = 0;
    $last_update_human = 'Never';
    $last_update = 0;

    $importers = CAPxImporter::loadAllImporters();
    foreach ($importers as $importer) {
      $total_profiles += $importer->meta['count'];
      if ($last_update < $importer->meta['lastUpdate']) {
        $last_update = $importer->meta['lastUpdate'];;
        $last_update_human = $importer->meta['lastUpdateHuman'];
      }
    }

    $content .= '<h2>' . t('Connected!') . '</h2>';
    $content .= '<div class="cap-status-ok"><p>Congratulations, you have successfully authenticated with the CAP API.</p></div>';

    $content .= '<div class="profiles"><p>' . t('@count profiles imported from CAP.', array('@count' => $total_profiles)) . '</p></div>';
    $content .= '<div class="last-updated"><p>' . t('Last import: @date', array('@date' => $last_update_human)) . '</p></div>';
    // There is no need to show sync all link if there are no importers
    // configured.
    if (count($importers) > 0) {
      $link_vars = array(
        'attributes' => array('class' => array('button')),
        'query' => array('destination' => current_path()),
      );
      $link = l(t('Update all profiles now'), 'admin/config/capx/importer/sync-all', $link_vars);
      $content .= '<div class="update-all"><p>' . $link . '</p></div>';
    }
  }
  // Something is not set correctly and we cannot connect.
  else {
    $content .= '<h2 class="error">' . t('Not Connected') . '</h2>';

    if ($connection->code == 0) {
      $content .= t("Please go to the !connt page to connect to the CAP API.", array("!connt" => l(t("CAPx settings"), "admin/config/capx/settings")));
    }
    else {
      $vars = array('@code' => $connection->code, '@message' => $connection->message);
      $content .= '<div class="cap-status-bad"><p>' . t('The server responded with error code: @code and message: @message.', $vars) . '</p></div>';
    }

  }

  return $content;
}

/**
 * Data browser launch block content callback.
 *
 * Creates the blocks contents for the mapping edit/new page.
 *
 * @return string
 *   HTML rendering.
 */
function stanford_capx_data_browser_launch_block() {
  $output = "";

  $output .= "<p>" . t("Having trouble finding the right field for mapping? Try viewing the data schema. We know... it is a lot. You can do it!") . "<br />";
  $output .= t("For more help please visit the !helppage.", array("!helppage" => l(t("help page"), "admin/config/capx/help"))) . "</p>";

  // Generate a link to the data browser, which opens in a new window.
  $browser_link = l(t('Open Data Schema'),
    'admin/config/capx/data-browser', array(
      'attributes' => array(
        'class' => 'btn button',
        'target' => '_blank',
      ),
    ));
  $output .= "<p>" . $browser_link . "</p>";

  $output .= "<p>Here are some commonly used settings:</p>";
  $header = array('Label', 'CAP API path');

  $rows = array();
  $rows[] = array('Title', '$.displayName');
  $rows[] = array('Body', '$.bio.html');
  $rows[] = array('Profile picture', '$.profilePhotos.bigger');
  $rows[] = array('Email', '$.primaryContact.email');
  $rows[] = array('Profiles URL', '$.meta.links[1].href');
  $rows[] = array('-------------', "--------------");
  // $rows[] = array('Cohort', '$.maintainers.*.title');.
  $rows[] = array('Affiliations', '$.affiliations');
  $rows[] = array('Job title short', '$.shortTitle.label.text');
  $rows[] = array('Job title long', '$.longTitle.title');
  // $rows[] = array('Dissertation title', '');.
  $rows[] = array('Degrees / education', '$.education.*.label.text');
  $rows[] = array('Title and department', '$.longTitle.title');
  // $rows[] = array('Faculty status', '');.
  $rows[] = array('Fax', '$.primaryContact.fax');
  $rows[] = array('CV - file', '$.documents.cv');
  $rows[] = array('CV - link', '$.documents.cv.url');
  $rows[] = array('Resume - file', '$.documents.resume');
  $rows[] = array('Resume - link', '$.documents.resume.url');
  $rows[] = array('First name legal', '$.names.legal.firstName');
  $rows[] = array('First name preferred', '$.names.preferred.firstName');
  $rows[] = array('Last name legal', '$.names.legal.lastName');
  $rows[] = array('Last name preferred', '$.names.preferred.lastName');
  $rows[] = array('Middle name legal', '$.names.legal.middleName');
  $rows[] = array('Middle name preferred', '$.names.preferred.middleName');
  $rows[] = array('Graduation year', '$.education.*.yearIssued');
  $rows[] = array('Personal info links title', '$.internetLinks.*.label.text');
  $rows[] = array('Personal info links url', '$.internetLinks.*.url');
  $rows[] = array('Lab website url', '$.internetLinks.[?(@.type="Lab Site")].url');
  $rows[] = array('Fields of interest', '$.professionalInterests.text');
  $rows[] = array('Mailing address', '$.primaryContact.address');
  $rows[] = array('Mailing address city', '$.primaryContact.city');
  $rows[] = array('Mailing address state', '$.primaryContact.state');
  $rows[] = array('Mailing address zip', '$.primaryContact.zip');
  // $rows[] = array('Office hours', '');.
  $rows[] = array('Office', '$.primaryContact.officeName');
  $rows[] = array('Phone', '$.primaryContact.phoneNumbers.*');
  $rows[] = array('Staff type', '$.titles.*.type');
  $rows[] = array('Field of study', '$.education.*.fieldOfStudy');
  $rows[] = array('Type', '$.titles.*.type');

  // Render all the rows.
  $output .= theme('table',
    array(
      'rows' => $rows,
      'header' => $header,
      'sticky' => FALSE,
    )
  );

  return $output;
}

/**
 * Creates and displays the importer in use block.
 *
 * @return mixed
 *   HTML representation of the page or false if there is an issue.
 */
function stanford_capx_importer_in_use_block() {
  $output = "";

  // Get machine name from url.
  $machine_name = arg(5);

  // If no machine name this must be a new importer. Just end.
  if (empty($machine_name)) {
    return FALSE;
  }

  // Try loading the importer.
  $importer = CAPxImporter::loadEntityImporter($machine_name);
  if (!$importer) {
    return FALSE;
  }

  // The metadata.
  $meta = $importer->getMeta();

  if ((int) $meta['count'] <= 0) {
    return FALSE;
  }

  $output .= "<p>";
  $output .= t("This importer is currently used to import !num profiles. Add or delete profiles by changing the settings below.", array("!num" => "<strong>" . $meta['count'] . "</strong>"));
  $output .= "</p><p>";
  $output .= t("Configure your !link to determine what will happen when profiles are deleted from your Importer or the CAP API.", array("!link" => l(t("CAPx Settings"), "admin/config/capx/settings")));
  $output .= "</p><p>";
  $output .= l(t("View all imported profiles"), "admin/config/capx/profiles", array("query" => array("importer" => $machine_name), "attributes" => array("class" => array("button"))));
  $output .= "</p>";

  return array(
    '#markup' => $output,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'stanford_capx') . '/css/stanford_capx.admin.css',
      ),
    ),
  );
}

/**
 * Creates the mapper in use block hook_view().
 *
 * Creates a render array of information to use on a mapper page.
 *
 * @return mixed
 *   A render array of block information or false if there is an issue.
 */
function stanford_capx_mapper_in_use_block() {
  $output = "";

  // Get machine name from url.
  $machine_name = arg(5);

  // If no machine name this must be a new importer. Just end.
  if (empty($machine_name)) {
    return FALSE;
  }

  // Do not need to check to see if this works or not as the page wont load if
  // the machine name is invalid.
  $mapper = CAPxMapper::loadMapper($machine_name);
  $importers = CAPxImporter::loadImportersByMapper($mapper);

  if (empty($importers)) {
    return FALSE;
  }

  $output .= "<p>";
  $output .= t("WARNING: Any changes you make to this mapping will update existing content on your next CAP sync.");
  $output .= "</p><p>";
  $output .= t("This mapping is currently used by: ");

  $porters = array();
  foreach ($importers as $importer) {
    $porters[] = l(t("!title", array("!title" => $importer->title)), "admin/config/capx/importer/edit/" . $importer->identifier());
  }

  $output .= implode(", ", $porters);
  $output .= "</p><p>";
  $output .= l(t("View all imported profiles"), "admin/config/capx/profiles", array("attributes" => array("class" => "button")));
  $output .= "</p>";

  return array(
    '#markup' => $output,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'stanford_capx') . '/css/stanford_capx.admin.css',
      ),
    ),
  );

}

/**
 * Returns the administrative menu items for CAPx.
 *
 * Returns a renderable array of html and attachments.
 *
 * @return array
 *   Render array of markup
 */
function stanford_capx_management_menu_block() {
  $output = array();

  $path = 'admin/config/capx';
  $parent = menu_link_get_preferred($path);
  $trail = menu_get_active_trail();
  $trail_mlids = array();
  foreach ($trail as $item) {
    if (!isset($item['mlid'])) {
      continue;
    }
    $trail_mlids[] = $item['mlid'];
  }

  $parameters = array(
    'active_trail' => $trail_mlids,
    'only_active_trail' => FALSE,
    'min_depth' => $parent['depth'] + 1,
    'max_depth' => $parent['depth'] + 1,
    'conditions' => array('plid' => $parent['mlid']),
  );

  $children = menu_build_tree($parent['menu_name'], $parameters);
  $menu_items = menu_tree_output($children);
  $rendered = "<div class=\"capx-menu-block\">" . drupal_render($menu_items) . "</div>";

  $output['#markup'] = $rendered;
  $output['#attached']['css'][] = drupal_get_path("module", "stanford_capx") . "/css/stanford_capx.admin.css";

  return $output;
}
