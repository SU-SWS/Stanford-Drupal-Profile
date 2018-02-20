<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalProfile\Install;
use \ITasks\AbstractInstallTask;

class WYSIWYGSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Create configuration for CKEditor.
    $ckeditor_configuration = serialize(
      array(
        'default' => 1,
        'user_choose' => 0,
        'show_toggle' => 1,
        'theme' => 'advanced',
        'language' => 'en',
        'buttons' => array(
          'default' => array(
            'Bold' => 1,
            'Italic' => 1,
            'BulletedList' => 1,
            'NumberedList' => 1,
            'Outdent' => 1,
            'Indent' => 1,
            'Undo' => 1,
            'Redo' => 1,
            'Link' => 1,
            'Unlink' => 1,
            'Blockquote' => 1,
            'Cut' => 1,
            'Copy' => 1,
            'Paste' => 1,
            'PasteText' => 1,
            'PasteFromWord' => 1,
            'Format' => 1,
            'SelectAll' => 1,
          ),
        ),
        'toolbar_loc' => 'top',
        'toolbar_align' => 'left',
        'path_loc' => 'bottom',
        'resizing' => 1,
        'verify_html' => 1,
        'preformatted' => 0,
        'convert_fonts_to_spans' => 1,
        'remove_linebreaks' => 1,
        'apply_source_formatting' => 1,
        'paste_auto_cleanup_on_paste' => 1,
        'block_formats' => "p,address,pre,h2,h3,h4,h5,h6",
        'css_setting' => 'theme',
        'css_path' => '',
        'css_classes' => ''
      )
    );

    // Add CKEditor to wysiwyg.
    $query = db_insert('wysiwyg')
      ->fields(array(
        'format' => 'filtered_html',
        'editor' => 'ckeditor',
        'settings' => $ckeditor_configuration,
      ));
    $query->execute();
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'wysiwyg',
    );
  }

}
