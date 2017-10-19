<?php
/**
 * @file
 * stanford_bean_types.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_bean_types_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_big_text_block_body'
  $field_bases['field_s_big_text_block_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_big_text_block_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_s_big_text_block_lead_text'
  $field_bases['field_s_big_text_block_lead_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_big_text_block_lead_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 100,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_big_text_block_more_link'
  $field_bases['field_s_big_text_block_more_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_big_text_block_more_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_contact_address_line_1'
  $field_bases['field_s_contact_address_line_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_address_line_1',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_contact_address_line_2'
  $field_bases['field_s_contact_address_line_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_address_line_2',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_contact_address_line_3'
  $field_bases['field_s_contact_address_line_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_address_line_3',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_contact_city_state_zip'
  $field_bases['field_s_contact_city_state_zip'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_city_state_zip',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_contact_email'
  $field_bases['field_s_contact_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_s_contact_fax'
  $field_bases['field_s_contact_fax'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_fax',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_contact_link'
  $field_bases['field_s_contact_link'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_contact_phone'
  $field_bases['field_s_contact_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_contact_phone',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_icon_body'
  $field_bases['field_s_icon_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_icon_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_s_icon_icon'
  $field_bases['field_s_icon_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_icon_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'icon-adjust' => 'Adjust',
        'icon-adn' => 'Adn',
        'icon-align-center' => 'Align-Center',
        'icon-align-justify' => 'Align-Justify',
        'icon-align-left' => 'Align-Left',
        'icon-align-right' => 'Align-Right',
        'icon-ambulance' => 'Ambulance',
        'icon-anchor' => 'Anchor',
        'icon-android' => 'Android',
        'icon-angle-down' => 'Angle-Down',
        'icon-angle-left' => 'Angle-Left',
        'icon-angle-right' => 'Angle-Right',
        'icon-angle-up' => 'Angle-Up',
        'icon-apple' => 'Apple',
        'icon-archive' => 'Archive',
        'icon-arrow-down' => 'Arrow-Down',
        'icon-arrow-left' => 'Arrow-Left',
        'icon-arrow-right' => 'Arrow-Right',
        'icon-arrow-up' => 'Arrow-Up',
        'icon-asterisk' => 'Asterisk',
        'icon-backward' => 'Backward',
        'icon-ban-circle' => 'Ban-Circle',
        'icon-bar-chart' => 'Bar-Chart',
        'icon-barcode' => 'Barcode',
        'icon-beaker' => 'Beaker',
        'icon-beer' => 'Beer',
        'icon-bell' => 'Bell',
        'icon-bell-alt' => 'Bell',
        'icon-bitbucket' => 'Bitbucket',
        'icon-bitbucket-sign' => 'Bitbucket-Sign',
        'icon-bold' => 'Bold',
        'icon-bolt' => 'Bolt',
        'icon-book' => 'Book',
        'icon-bookmark' => 'Bookmark',
        'icon-bookmark-empty' => 'Bookmark-Empty',
        'icon-briefcase' => 'Briefcase',
        'icon-btc' => 'Btc',
        'icon-bug' => 'Bug',
        'icon-building' => 'Building',
        'icon-bullhorn' => 'Bullhorn',
        'icon-bullseye' => 'Bullseye',
        'icon-calendar' => 'Calendar',
        'icon-calendar-empty' => 'Calendar-Empty',
        'icon-camera' => 'Camera',
        'icon-camera-retro' => 'Camera-Retro',
        'icon-caret-down' => 'Caret-Down',
        'icon-caret-left' => 'Caret-Left',
        'icon-caret-right' => 'Caret-Right',
        'icon-caret-up' => 'Caret-Up',
        'icon-certificate' => 'Certificate',
        'icon-check' => 'Check',
        'icon-check-empty' => 'Check-Empty',
        'icon-check-minus' => 'Check-Minus',
        'icon-check-sign' => 'Check-Sign',
        'icon-chevron-down' => 'Chevron-Down',
        'icon-chevron-left' => 'Chevron-Left',
        'icon-chevron-right' => 'Chevron-Right',
        'icon-chevron-sign-down' => 'Chevron-Sign-Down',
        'icon-chevron-sign-left' => 'Chevron-Sign-Left',
        'icon-chevron-sign-right' => 'Chevron-Sign-Right',
        'icon-chevron-sign-up' => 'Chevron-Sign-Up',
        'icon-chevron-up' => 'Chevron-Up',
        'icon-circle' => 'Circle',
        'icon-circle-arrow-down' => 'Circle-Arrow-Down',
        'icon-circle-arrow-left' => 'Circle-Arrow-Left',
        'icon-circle-arrow-right' => 'Circle-Arrow-Right',
        'icon-circle-arrow-up' => 'Circle-Arrow-Up',
        'icon-circle-blank' => 'Circle-Blank',
        'icon-cloud' => 'Cloud',
        'icon-cloud-download' => 'Cloud-Download',
        'icon-cloud-upload' => 'Cloud-Upload',
        'icon-cny' => 'Cny',
        'icon-code' => 'Code',
        'icon-code-fork' => 'Code-Fork',
        'icon-coffee' => 'Coffee',
        'icon-cog' => 'Cog',
        'icon-cogs' => 'Cogs',
        'icon-collapse-alt' => 'Collapse',
        'icon-collapse' => 'Collapse',
        'icon-collapse-top' => 'Collapse-Top',
        'icon-columns' => 'Columns',
        'icon-comment' => 'Comment',
        'icon-comment-alt' => 'Comment',
        'icon-comments' => 'Comments',
        'icon-comments-alt' => 'Comments',
        'icon-compass' => 'Compass',
        'icon-copy' => 'Copy',
        'icon-credit-card' => 'Credit-Card',
        'icon-crop' => 'Crop',
        'icon-css3' => 'Css3',
        'icon-cut' => 'Cut',
        'icon-dashboard' => 'Dashboard',
        'icon-desktop' => 'Desktop',
        'icon-double-angle-down' => 'Double-Angle-Down',
        'icon-double-angle-left' => 'Double-Angle-Left',
        'icon-double-angle-right' => 'Double-Angle-Right',
        'icon-double-angle-up' => 'Double-Angle-Up',
        'icon-download-alt' => 'Download',
        'icon-download' => 'Download',
        'icon-dribbble' => 'Dribbble',
        'icon-dropbox' => 'Dropbox',
        'icon-edit' => 'Edit',
        'icon-edit-sign' => 'Edit-Sign',
        'icon-eject' => 'Eject',
        'icon-ellipsis-horizontal' => 'Ellipsis-Horizontal',
        'icon-ellipsis-vertical' => 'Ellipsis-Vertical',
        'icon-envelope-alt' => 'Envelope',
        'icon-envelope' => 'Envelope',
        'icon-eraser' => 'Eraser',
        'icon-eur' => 'Eur',
        'icon-exchange' => 'Exchange',
        'icon-exclamation' => 'Exclamation',
        'icon-exclamation-sign' => 'Exclamation-Sign',
        'icon-expand-alt' => 'Expand',
        'icon-expand' => 'Expand',
        'icon-external-link' => 'External-Link',
        'icon-external-link-sign' => 'External-Link-Sign',
        'icon-eye-close' => 'Eye-Close',
        'icon-eye-open' => 'Eye-Open',
        'icon-facebook' => 'Facebook',
        'icon-facebook-sign' => 'Facebook-Sign',
        'icon-facetime-video' => 'Facetime-Video',
        'icon-fast-backward' => 'Fast-Backward',
        'icon-fast-forward' => 'Fast-Forward',
        'icon-female' => 'Female',
        'icon-fighter-jet' => 'Fighter-Jet',
        'icon-file-alt' => 'File',
        'icon-file' => 'File',
        'icon-file-text-alt' => 'File-Text',
        'icon-file-text' => 'File-Text',
        'icon-film' => 'Film',
        'icon-filter' => 'Filter',
        'icon-fire' => 'Fire',
        'icon-fire-extinguisher' => 'Fire-Extinguisher',
        'icon-flag' => 'Flag',
        'icon-flag-alt' => 'Flag',
        'icon-flag-checkered' => 'Flag-Checkered',
        'icon-flickr' => 'Flickr',
        'icon-folder-close' => 'Folder-Close',
        'icon-folder-close-alt' => 'Folder-Close',
        'icon-folder-open' => 'Folder-Open',
        'icon-folder-open-alt' => 'Folder-Open',
        'icon-font' => 'Font',
        'icon-food' => 'Food',
        'icon-forward' => 'Forward',
        'icon-foursquare' => 'Foursquare',
        'icon-frown' => 'Frown',
        'icon-fullscreen' => 'Fullscreen',
        'icon-gamepad' => 'Gamepad',
        'icon-gbp' => 'Gbp',
        'icon-gift' => 'Gift',
        'icon-github' => 'Github',
        'icon-github-alt' => 'Github',
        'icon-github-sign' => 'Github-Sign',
        'icon-gittip' => 'Gittip',
        'icon-glass' => 'Glass',
        'icon-globe' => 'Globe',
        'icon-google-plus' => 'Google-Plus',
        'icon-google-plus-sign' => 'Google-Plus-Sign',
        'icon-group' => 'Group',
        'icon-h-sign' => 'H-Sign',
        'icon-hand-down' => 'Hand-Down',
        'icon-hand-left' => 'Hand-Left',
        'icon-hand-right' => 'Hand-Right',
        'icon-hand-up' => 'Hand-Up',
        'icon-hdd' => 'Hdd',
        'icon-headphones' => 'Headphones',
        'icon-heart' => 'Heart',
        'icon-heart-empty' => 'Heart-Empty',
        'icon-home' => 'Home',
        'icon-hospital' => 'Hospital',
        'icon-html5' => 'Html5',
        'icon-inbox' => 'Inbox',
        'icon-indent-left' => 'Indent-Left',
        'icon-indent-right' => 'Indent-Right',
        'icon-info' => 'Info',
        'icon-info-sign' => 'Info-Sign',
        'icon-inr' => 'Inr',
        'icon-instagram' => 'Instagram',
        'icon-italic' => 'Italic',
        'icon-jpy' => 'Jpy',
        'icon-key' => 'Key',
        'icon-keyboard' => 'Keyboard',
        'icon-krw' => 'Krw',
        'icon-laptop' => 'Laptop',
        'icon-leaf' => 'Leaf',
        'icon-legal' => 'Legal',
        'icon-lemon' => 'Lemon',
        'icon-level-down' => 'Level-Down',
        'icon-level-up' => 'Level-Up',
        'icon-lightbulb' => 'Lightbulb',
        'icon-link' => 'Link',
        'icon-linkedin' => 'Linkedin',
        'icon-linkedin-sign' => 'Linkedin-Sign',
        'icon-linux' => 'Linux',
        'icon-list-alt' => 'List',
        'icon-list' => 'List',
        'icon-list-ol' => 'List-Ol',
        'icon-list-ul' => 'List-Ul',
        'icon-location-arrow' => 'Location-Arrow',
        'icon-lock' => 'Lock',
        'icon-long-arrow-down' => 'Long-Arrow-Down',
        'icon-long-arrow-left' => 'Long-Arrow-Left',
        'icon-long-arrow-right' => 'Long-Arrow-Right',
        'icon-long-arrow-up' => 'Long-Arrow-Up',
        'icon-magic' => 'Magic',
        'icon-magnet' => 'Magnet',
        'icon-mail-reply-all' => 'Mail-Reply-All',
        'icon-male' => 'Male',
        'icon-map-marker' => 'Map-Marker',
        'icon-maxcdn' => 'Maxcdn',
        'icon-medkit' => 'Medkit',
        'icon-meh' => 'Meh',
        'icon-microphone' => 'Microphone',
        'icon-microphone-off' => 'Microphone-Off',
        'icon-minus' => 'Minus',
        'icon-minus-sign' => 'Minus-Sign',
        'icon-minus-sign-alt' => 'Minus-Sign',
        'icon-mobile-phone' => 'Mobile-Phone',
        'icon-money' => 'Money',
        'icon-moon' => 'Moon',
        'icon-move' => 'Move',
        'icon-music' => 'Music',
        'icon-off' => 'Off',
        'icon-ok' => 'Ok',
        'icon-ok-circle' => 'Ok-Circle',
        'icon-ok-sign' => 'Ok-Sign',
        'icon-paper-clip' => 'Paper-Clip',
        'icon-paste' => 'Paste',
        'icon-pause' => 'Pause',
        'icon-pencil' => 'Pencil',
        'icon-phone' => 'Phone',
        'icon-phone-sign' => 'Phone-Sign',
        'icon-picture' => 'Picture',
        'icon-pinterest' => 'Pinterest',
        'icon-pinterest-sign' => 'Pinterest-Sign',
        'icon-plane' => 'Plane',
        'icon-play' => 'Play',
        'icon-play-circle' => 'Play-Circle',
        'icon-play-sign' => 'Play-Sign',
        'icon-plus' => 'Plus',
        'icon-plus-sign' => 'Plus-Sign',
        'icon-plus-sign-alt' => 'Plus-Sign',
        'icon-print' => 'Print',
        'icon-pushpin' => 'Pushpin',
        'icon-puzzle-piece' => 'Puzzle-Piece',
        'icon-qrcode' => 'Qrcode',
        'icon-question' => 'Question',
        'icon-question-sign' => 'Question-Sign',
        'icon-quote-left' => 'Quote-Left',
        'icon-quote-right' => 'Quote-Right',
        'icon-random' => 'Random',
        'icon-refresh' => 'Refresh',
        'icon-remove' => 'Remove',
        'icon-remove-circle' => 'Remove-Circle',
        'icon-remove-sign' => 'Remove-Sign',
        'icon-renren' => 'Renren',
        'icon-reorder' => 'Reorder',
        'icon-repeat' => 'Repeat',
        'icon-reply' => 'Reply',
        'icon-reply-all' => 'Reply-All',
        'icon-resize-full' => 'Resize-Full',
        'icon-resize-horizontal' => 'Resize-Horizontal',
        'icon-resize-small' => 'Resize-Small',
        'icon-resize-vertical' => 'Resize-Vertical',
        'icon-retweet' => 'Retweet',
        'icon-road' => 'Road',
        'icon-rocket' => 'Rocket',
        'icon-rss' => 'Rss',
        'icon-rss-sign' => 'Rss-Sign',
        'icon-save' => 'Save',
        'icon-screenshot' => 'Screenshot',
        'icon-search' => 'Search',
        'icon-share' => 'Share',
        'icon-share-alt' => 'Share',
        'icon-share-sign' => 'Share-Sign',
        'icon-shield' => 'Shield',
        'icon-shopping-cart' => 'Shopping-Cart',
        'icon-sign-blank' => 'Sign-Blank',
        'icon-signal' => 'Signal',
        'icon-signin' => 'Signin',
        'icon-signout' => 'Signout',
        'icon-sitemap' => 'Sitemap',
        'icon-skype' => 'Skype',
        'icon-smile' => 'Smile',
        'icon-sort' => 'Sort',
        'icon-sort-by-alphabet' => 'Sort-By-Alphabet',
        'icon-sort-by-alphabet-alt' => 'Sort-By-Alphabet',
        'icon-sort-by-attributes' => 'Sort-By-Attributes',
        'icon-sort-by-attributes-alt' => 'Sort-By-Attributes',
        'icon-sort-by-order' => 'Sort-By-Order',
        'icon-sort-by-order-alt' => 'Sort-By-Order',
        'icon-sort-down' => 'Sort-Down',
        'icon-sort-up' => 'Sort-Up',
        'icon-spinner' => 'Spinner',
        'icon-stackexchange' => 'Stackexchange',
        'icon-star' => 'Star',
        'icon-star-empty' => 'Star-Empty',
        'icon-star-half' => 'Star-Half',
        'icon-star-half-empty' => 'Star-Half-Empty',
        'icon-step-backward' => 'Step-Backward',
        'icon-step-forward' => 'Step-Forward',
        'icon-stethoscope' => 'Stethoscope',
        'icon-stop' => 'Stop',
        'icon-strikethrough' => 'Strikethrough',
        'icon-subscript' => 'Subscript',
        'icon-suitcase' => 'Suitcase',
        'icon-sun' => 'Sun',
        'icon-superscript' => 'Superscript',
        'icon-table' => 'Table',
        'icon-th-list' => 'Table List',
        'icon-th-large' => 'Table-Large',
        'icon-tablet' => 'Tablet',
        'icon-tag' => 'Tag',
        'icon-tags' => 'Tags',
        'icon-tasks' => 'Tasks',
        'icon-terminal' => 'Terminal',
        'icon-text-height' => 'Text-Height',
        'icon-text-width' => 'Text-Width',
        'icon-th' => 'Thable',
        'icon-thumbs-down-alt' => 'Thumbs-Down',
        'icon-thumbs-down' => 'Thumbs-Down',
        'icon-thumbs-up-alt' => 'Thumbs-Up',
        'icon-thumbs-up' => 'Thumbs-Up',
        'icon-ticket' => 'Ticket',
        'icon-time' => 'Time',
        'icon-tint' => 'Tint',
        'icon-trash' => 'Trash',
        'icon-trello' => 'Trello',
        'icon-trophy' => 'Trophy',
        'icon-truck' => 'Truck',
        'icon-tumblr' => 'Tumblr',
        'icon-tumblr-sign' => 'Tumblr-Sign',
        'icon-twitter' => 'Twitter',
        'icon-twitter-sign' => 'Twitter-Sign',
        'icon-umbrella' => 'Umbrella',
        'icon-underline' => 'Underline',
        'icon-undo' => 'Undo',
        'icon-unlink' => 'Unlink',
        'icon-unlock' => 'Unlock',
        'icon-unlock-alt' => 'Unlock',
        'icon-upload' => 'Upload',
        'icon-upload-alt' => 'Upload',
        'icon-usd' => 'Usd',
        'icon-user' => 'User',
        'icon-user-md' => 'User-Md',
        'icon-vk' => 'Vk',
        'icon-volume-down' => 'Volume-Down',
        'icon-volume-off' => 'Volume-Off',
        'icon-volume-up' => 'Volume-Up',
        'icon-warning-sign' => 'Warning-Sign',
        'icon-weibo' => 'Weibo',
        'icon-windows' => 'Windows',
        'icon-wrench' => 'Wrench',
        'icon-xing' => 'Xing',
        'icon-xing-sign' => 'Xing-Sign',
        'icon-youtube' => 'Youtube',
        'icon-youtube-play' => 'Youtube-Play',
        'icon-youtube-sign' => 'Youtube-Sign',
        'icon-zoom-in' => 'Zoom-In',
        'icon-zoom-out' => 'Zoom-Out',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_s_icon_link'
  $field_bases['field_s_icon_link'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_icon_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_large_blk_read_more_link'
  $field_bases['field_s_large_blk_read_more_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_large_blk_read_more_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_large_block_body'
  $field_bases['field_s_large_block_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_large_block_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_s_large_block_file_insert'
  $field_bases['field_s_large_block_file_insert'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_large_block_file_insert',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_s_large_block_image_insert'
  $field_bases['field_s_large_block_image_insert'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_large_block_image_insert',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'display_default' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_s_postcard_body'
  $field_bases['field_s_postcard_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_postcard_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_s_postcard_file'
  $field_bases['field_s_postcard_file'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_postcard_file',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_s_postcard_image_insert'
  $field_bases['field_s_postcard_image_insert'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_postcard_image_insert',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_s_postcard_link'
  $field_bases['field_s_postcard_link'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_postcard_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_facebook'
  $field_bases['field_s_smc_facebook'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_facebook',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_flickr'
  $field_bases['field_s_smc_flickr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_flickr',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_googleplus'
  $field_bases['field_s_smc_googleplus'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_googleplus',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_instagram'
  $field_bases['field_s_smc_instagram'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_instagram',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_linkedin'
  $field_bases['field_s_smc_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_linkedin',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_pinterest'
  $field_bases['field_s_smc_pinterest'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_pinterest',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_tumblr'
  $field_bases['field_s_smc_tumblr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_tumblr',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_twitter'
  $field_bases['field_s_smc_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_twitter',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_vimeo'
  $field_bases['field_s_smc_vimeo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_vimeo',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_smc_youtube'
  $field_bases['field_s_smc_youtube'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_smc_youtube',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_s_testimonial_credits'
  $field_bases['field_s_testimonial_credits'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_testimonial_credits',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_s_testimonial_quote'
  $field_bases['field_s_testimonial_quote'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_testimonial_quote',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 350,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_testimonial_more_link'
  $field_bases['field_testimonial_more_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_testimonial_more_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
