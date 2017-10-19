<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\Block;
/**
 *
 */
class RelatedLinksBlock extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $menu = array(
      "menu_name" => "menu-related-links",
      "title" => t("Related Links"),
      "description" => t("Related Links menu for mainsite footer"),
    );
    menu_save($menu);
    $links = array(
      'http://www.stanford.edu/' => t('Stanford University'),
      'http://www.stanford.edu/research/' => t('Research at Stanford'),
      'http://news.stanford.edu/' => t('Stanford News'),
    );
    // Loop through and save all links.
    $i = 0;
    foreach ($links as $url => $title) {
      $item = array(
        "link_path" => $url,
        "link_title" => $title,
        "menu_name" => $menu['menu_name'],
        'weight' => ++$i,
      );
      menu_link_save($item);
    }

  }

}
