<?php

/**
 * @file social_share.networks.inc
 */

/**
 * Form callback: Social network tabledrag form.
 */
function social_share_admin_networks($form, &$form_state) {
  $networks = social_share_available_networks(TRUE);

  $form['networks']['#tree'] = TRUE;

  foreach ($networks as $network) {
    if (!isset($network['weight'])) {
      $network['weight'] = count($networks);
    }

    $form['networks'][$network['machine_name']] = array(
      'human_name' => array(
        '#markup' => $network['human_name'],
      ),
      'url' => array(
        '#markup' => $network['url'],
      ),
      'edit' => array(
        '#markup' => l('Edit', 'admin/config/services/social-share/networks/' . $network['machine_name'] . '/edit'),
      ),
    );

    if (!$network['locked']) {
      $form['networks'][$network['machine_name']]['remove'] = array(
        '#markup' => l('Remove', 'admin/config/services/social-share/networks/' . $network['machine_name'] . '/remove'),
      );
    }

    $form['networks'][$network['machine_name']]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => $network['weight'],
      '#delta' => 20,
      '#title_display' => 'invisible',
    );
  }

  $form['actions'] = array('#type' => 'actions');

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
    '#submit' => array('social_share_admin_networks_submit'),
  );

  $form['actions']['add_network'] = array(
    '#markup' => l('Add Social Network', 'admin/config/services/social-share/networks/new', array(
      'attributes' => array(
        'class' => array(
          'button'
        )
      )
        )
    ),
  );


  return $form;
}

/**
 * Submit handler for social network tabledrag form.
 */
function social_share_admin_networks_submit($form, &$form_state) {
  $values = $form_state['values']['networks'];
  foreach ($values as $machine_name => $weight) {
    db_update('social_share_networks')
        ->condition('machine_name', $machine_name, '=')
        ->fields($weight)
        ->execute();
  }

  social_share_update_network_order();

  drupal_set_message('Your changes have been saved.');
}

/**
 * Helper function to reorder enabled networks for block and all node types
 */
function social_share_update_network_order() {
  $available_networks = social_share_available_networks(TRUE);

  // Update network order by newly saved weight values for block, if enabled:
  if (variable_get('social_share_block', 0)) {
    $block_settings = variable_get('social_share_block_settings', array());
    $new_order = array();
    $networks = $block_settings['social_share_networks'];
    foreach ($available_networks as $available_network) {
      $new_order[$available_network['machine_name']] = in_array($available_network['machine_name'], array_keys($networks)) ? $networks[$available_network['machine_name']] : 0;
    }
    $block_settings['social_share_networks'] = $new_order;
    variable_set('social_share_block_settings', $block_settings);
  }

  $node_types = array_keys(node_type_get_types());
  foreach ($node_types as $type) {
    if ($networks = variable_get('social_share_networks_' . $type, FALSE)) {
      $new_order = array();
      foreach ($available_networks as $available_network) {
        if (in_array($available_network['machine_name'], $networks)) {
          $new_order[] = $available_network['machine_name'];
        }
      }
      variable_set('social_share_networks_' . $type, $new_order);
    }
  }
}

/**
 * Callback function for verifying whether a machine name exists or not.
 */
function social_share_check_machine_name($name) {
  if (social_share_get_network($name)) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Form callback for social network add/edit form.
 */
function social_share_admin_networks_network($form, &$form_state, $machine_name = NULL) {
  if ($machine_name) {
    $network = social_share_get_network($machine_name);
    $form['new'] = array(
      '#type' => 'hidden',
      '#value' => FALSE,
    );
  }
  else {
    $form['new'] = array(
      '#type' => 'hidden',
      '#value' => TRUE,
    );
  }

  $form += array(
    'human_name' => array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => isset($network['human_name']) ? $network['human_name'] : '',
      '#maxlength' => 255,
      '#required' => TRUE,
    ),
    'url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#default_value' => isset($network['url']) ? $network['url'] : '',
      '#size' => 100,
      '#maxlength' => 512,
      '#required' => TRUE,
      '#description' => t('Provide the share url for this network.') .
      '<br />' .
      t('These are the only valid placeholders: !placeholders', array(
        '!placeholders' =>
        theme('item_list', array('items' => array(
            '<em>%TITLE%</em>  --  ' . t('Title of page, node, etc'),
            '<em>%DESC%</em>  --  ' . t('Node body, description, etc (Note: most social networks ignore this)'),
            '<em>%URL%</em>  --  ' . t('URL being shared (Note: This is _REQUIRED_ for all social networks)'),
            '<em>%IMAGE%</em>  --  ' . t('URL of image to share (Note: Very few networks accept this, most parse the page content to find images. Pinterest is a notable exception.)'),
      )))
      )),
    ),
  );

  $form['actions'] = array('#type' => 'actions');

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
    '#submit' => array('social_share_admin_networks_network_submit'),
  );

  return $form;
}

/**
 * Submit handler for social network add/edit form.
 */
function social_share_admin_networks_network_submit($form, &$form_state) {
  $values = $form_state['values'];

  $values['machine_name'] = preg_replace('@[^a-z0-9_]+@', '_', strtolower($values['human_name']));
  $network_key = preg_replace('@[^a-z0-9_]+@', '_', strtolower($form['human_name']['#default_value']));

  if (!$values['new']) {
    db_update('social_share_networks')
        ->condition('machine_name', $network_key, '=')
        ->fields(array(
          'human_name' => $values['human_name'],
          'machine_name' => $values['machine_name'],
          'url' => $values['url']
        ))
        ->execute();

    social_share_update_network_order();

    drupal_set_message('Your changes have been saved.');
  }
  else {
    db_insert('social_share_networks')
        ->fields(array(
          'human_name' => $values['human_name'],
          'machine_name' => $values['machine_name'],
          'url' => $values['url']
        ))
        ->execute();

    social_share_update_network_order();

    drupal_set_message('Your new network has been added.');
  }
  drupal_goto('admin/config/services/social-share/networks');
}

/**
 * Form callback for confirmation of removal of a custom social network entry.
 */
function social_share_admin_networks_remove($form, &$form_state, $machine_name = NULL) {
  $path = 'admin/config/services/social-share/networks';
  if (!$machine_name) {
    drupal_goto($path);
  }
  $network = social_share_get_network($machine_name);

  $form['machine_name'] = array(
    '#type' => 'hidden',
    '#value' => $machine_name,
  );
  $form['human_name'] = array(
    '#type' => 'hidden',
    '#value' => $network['human_name'],
  );
  $form['#submit'] = array('social_share_admin_networks_remove_submit');

  $question = t('Are you sure you want to remove "@name"', array('@name' => $network['human_name']));

  return confirm_form($form, $question, $path, NULL, t('Remove'), NULL, 'confirm');
}

/**
 * Submit handler for social network remove confirmation form.
 */
function social_share_admin_networks_remove_submit($form, &$form_state) {
  db_delete('social_share_networks')
      ->condition('machine_name', $form_state['values']['machine_name'])
      ->execute();

  social_share_update_network_order(TRUE);

  drupal_set_message(t('"@name" has been removed.', array('@name' => $form_state['values']['human_name'])));
  drupal_goto('admin/config/services/social-share/networks');
}

/**
 * Get a list of default networks for installation.
 *
 * @return array
 */
function _social_share_get_networks() {
  $networks = array(
    'delicious' => array(
      'machine_name' => 'delicious',
      'human_name' => t('Delicious'),
      'url' => 'http://www.delicious.com/save?v=5&noui&jump=close&url=%URL%&title=%TITLE%',
      'locked' => TRUE,
    ),
    'digg' => array(
      'machine_name' => 'digg',
      'human_name' => t('Digg'),
      'url' => 'http://digg.com/share?url=%URL%&title=%TITLE%',
      'locked' => TRUE,
    ),
    'facebook' => array(
      'machine_name' => 'facebook',
      'human_name' => t('Facebook'),
      'url' => 'http://facebook.com/sharer.php?u=%URL%&t=%TITLE%',
      'locked' => TRUE,
    ),
    'googleplus' => array(
      'machine_name' => 'googleplus',
      'human_name' => t('Google Plus'),
      'url' => 'https://plus.google.com/share?url=%URL%',
      'locked' => TRUE,
    ),
    'hyves' => array(
      'machine_name' => 'hyves',
      'human_name' => t('Hyves'),
      'url' => 'http://www.hyves-share.nl/button/tip/?tipcategoryid=12&rating=5&title=%TITLE%&body=%DESC%Bron: [url=%URL%]%URL%[/url]',
      'locked' => TRUE,
    ),
    'linkedin' => array(
      'machine_name' => 'linkedin',
      'human_name' => t('LinkedIn'),
      'url' => 'http://www.linkedin.com/shareArticle?url=%URL%&mini=true&title=%TITLE%&ro=false&summary=%DESC%&source=',
      'locked' => TRUE,
    ),
    'msnlive' => array(
      'machine_name' => 'msnlive',
      'human_name' => t('MSN Live'),
      'url' => 'http://profile.live.com/badge/?url=%URL%&title=%TITLE%&description=%DESC%',
      'locked' => TRUE,
    ),
    'myspace' => array(
      'machine_name' => 'myspace',
      'human_name' => t('Myspace'),
      'url' => 'http://www.myspace.com/Modules/PostTo/Pages/default.aspx?u=%URL%&c=%TITLE%',
      'locked' => TRUE,
    ),
    'pinterest' => array(
      'machine_name' => 'pinterest',
      'human_name' => t('Pinterest'),
      'url' => 'http://pinterest.com/pin/create/button/?url=%URL%&media=%IMAGE%&description=%DESC%',
      'locked' => TRUE,
    ),
    'reddit' => array(
      'machine_name' => 'reddit',
      'human_name' => t('Reddit'),
      'url' => 'http://reddit.com/submit?url=%URL%&title=%TITLE%',
      'locked' => TRUE,
    ),
    'stumbleupon' => array(
      'machine_name' => 'stumbleupon',
      'human_name' => t('StumbleUpon'),
      'url' => 'http://stumbleupon.com/submit?url=%URL%&title=%TITLE%',
      'locked' => TRUE,
    ),
    'twitter' => array(
      'machine_name' => 'twitter',
      'human_name' => t('Twitter'),
      'url' => 'http://twitter.com/intent/tweet?url=%URL%&text=%TITLE%',
      'locked' => TRUE,
    ),
    'yahoo' => array(
      'machine_name' => 'yahoo',
      'human_name' => t('Yahoo'),
      'url' => 'http://bookmarks.yahoo.com/toolbar/savebm?opener=tb&u=%URL%&t=%TITLE%&d=%DESC%',
      'locked' => TRUE,
    ),
  );

  return $networks;
}
