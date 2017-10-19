<?php
/**
 * @file
 * stanford_story_page.features.paragraphs_defaults.inc
 */

/**
 * Implements hook_paragraphs_defaults().
 */
function stanford_story_page_paragraphs_defaults() {
  $paragraphs_defaults = array();
  $paragraphs_defaults['node-stanford_story_page-field_s_story_sections-article'] = array(
    'label' => 'Article',
    'machine_name' => 'article',
    'entity_type' => 'node',
    'field_name' => 'field_s_story_sections',
    'bundle' => 'stanford_story_page',
    'paragraphs' => array(
      0 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-right',
            ),
          ),
        ),
        'field_p_hero_headline' => array(
          'und' => array(
            0 => array(
              'value' => 'Feature a headline for your article here',
              'format' => NULL,
              'safe_value' => 'Feature a headline for your article here',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/thomas-henke-190697_0.jpg',
              'filesize' => 3824458,
            ),
          ),
        ),
        'field_p_hero_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'https://www.youtube.com/watch?v=lItPPxz5jOI',
              'title' => 'Watch Video',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'both',
            ),
          ),
        ),
        'field_p_hero_video' => array(
          'und' => array(
            0 => array(
              'video_url' => 'https://www.youtube.com/watch?v=lItPPxz5jOI',
              'video_data' => 'a:1:{s:7:"handler";s:7:"youtube";}',
              'embed_code' => NULL,
              'description' => NULL,
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      1 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p><em>Editors notes can go here. Lorem ipsum dolor sit amet, consectetur adipiscing elit.</em></p>
<p class="credits">March 7, 2016 |&nbsp;BYLINE</p>
<p class="summary">This is an example of an article page. You can feature a long-form article with video, images, quotes, and more. To edit the page and remove this placeholder content, click on the &quot;Edit&quot; tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click &quot;Save.&quot;</p>
<h3><span style="letter-spacing: 0.01em;">Lorem ipsum dolor sit amet</span></h3>
<div><span style="letter-spacing: 0.01em;">Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Tellus mauris a diam maecenas sed enim ut. Ultrices gravida dictum fusce ut placerat orci nulla. Convallis posuere morbi leo urna. Tellus pellentesque eu tincidunt tortor aliquam nulla facilisi cras fermentum. Posuere sollicitudin aliquam ultrices sagittis orci a scelerisque. Vestibulum rhoncus est pellentesque elit ullamcorper dignissim. Et tortor consequat id porta nibh venenatis cras. Egestas diam in arcu cursus euismod quis. Etiam erat velit scelerisque in dictum non consectetur. Venenatis a condimentum vitae sapien pellentesque habitant morbi tristique.</span></div>
<div>&nbsp;</div>
<div>Consequat mauris nunc congue nisi vitae suscipit tellus. A scelerisque purus semper eget. Quam quisque id diam vel quam. Massa sed elementum tempus egestas sed sed risus. Morbi leo urna molestie at. Condimentum id venenatis a condimentum vitae sapien. Donec adipiscing tristique risus nec feugiat in fermentum posuere urna. Pellentesque elit ullamcorper dignissim cras tincidunt lobortis. Etiam dignissim diam quis enim. In iaculis nunc sed augue. <a href="http://www.stanford.edu">Vitae suscipit tellus mauris.</a></div>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p><em>Editors notes can go here. Lorem ipsum dolor sit amet, consectetur adipiscing elit.</em></p>
<p class="credits">March 7, 2016 | BYLINE</p>
<p class="summary">This is an example of an article page. You can feature a long-form article with video, images, quotes, and more. To edit the page and remove this placeholder content, click on the "Edit" tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click "Save."</p>
<h3><span>Lorem ipsum dolor sit amet</span></h3>
<div><span>Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Tellus mauris a diam maecenas sed enim ut. Ultrices gravida dictum fusce ut placerat orci nulla. Convallis posuere morbi leo urna. Tellus pellentesque eu tincidunt tortor aliquam nulla facilisi cras fermentum. Posuere sollicitudin aliquam ultrices sagittis orci a scelerisque. Vestibulum rhoncus est pellentesque elit ullamcorper dignissim. Et tortor consequat id porta nibh venenatis cras. Egestas diam in arcu cursus euismod quis. Etiam erat velit scelerisque in dictum non consectetur. Venenatis a condimentum vitae sapien pellentesque habitant morbi tristique.</span></div>
<div> </div>
<div>Consequat mauris nunc congue nisi vitae suscipit tellus. A scelerisque purus semper eget. Quam quisque id diam vel quam. Massa sed elementum tempus egestas sed sed risus. Morbi leo urna molestie at. Condimentum id venenatis a condimentum vitae sapien. Donec adipiscing tristique risus nec feugiat in fermentum posuere urna. Pellentesque elit ullamcorper dignissim cras tincidunt lobortis. Etiam dignissim diam quis enim. In iaculis nunc sed augue. <a href="http://www.stanford.edu">Vitae suscipit tellus mauris.</a></div>
',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      2 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_callout',
        'field_p_callout_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>This is your callout text. You can feature a pull quote or quote from your article here.</p>',
              'format' => 'minimal_html',
              'safe_value' => '<p>This is your callout text. You can feature a pull quote or quote from your article here.</p>',
            ),
          ),
        ),
        'entity_bundle' => 'p_callout',
        'entity_type' => 'paragraphs_item',
      ),
      3 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/matt-jones-67740-a_0.jpeg',
                    'filesize' => 22139,
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/matt-jones-67740-b_0.jpeg',
                    'filesize' => 25163,
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
      4 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<h3>Lorem ipsum dolor sit amet</h3>
<div>Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. In mollis nunc sed id. Vitae suscipit tellus mauris a diam maecenas. Elementum nisi quis eleifend quam adipiscing vitae proin sagittis nisl. Duis ultricies lacus sed turpis tincidunt id aliquet. Nunc pulvinar sapien et ligula. Mattis pellentesque id nibh tortor id aliquet. Malesuada pellentesque elit eget gravida cum sociis. Luctus venenatis lectus magna fringilla. Diam sit amet nisl suscipit adipiscing bibendum est.</div>
<div>&nbsp;</div>
<div><span style="letter-spacing: 0.01em;">Faucibus et molestie ac feugiat sed. Risus feugiat in ante metus dictum at tempor commodo. Arcu dui vivamus arcu felis. Faucibus scelerisque eleifend donec pretium vulputate sapien. Egestas diam in arcu cursus euismod quis viverra nibh. Vel fringilla est ullamcorper eget nulla. Magna etiam tempor orci eu. Aenean vel elit scelerisque mauris pellentesque pulvinar pellentesque habitant morbi. Mattis molestie a iaculis at erat pellentesque adipiscing commodo. Ultrices sagittis orci a scelerisque. Eu lobortis elementum nibh tellus molestie nunc non blandit massa.</span></div>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<h3>Lorem ipsum dolor sit amet</h3>
<div>Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. In mollis nunc sed id. Vitae suscipit tellus mauris a diam maecenas. Elementum nisi quis eleifend quam adipiscing vitae proin sagittis nisl. Duis ultricies lacus sed turpis tincidunt id aliquet. Nunc pulvinar sapien et ligula. Mattis pellentesque id nibh tortor id aliquet. Malesuada pellentesque elit eget gravida cum sociis. Luctus venenatis lectus magna fringilla. Diam sit amet nisl suscipit adipiscing bibendum est.</div>
<div> </div>
<div><span>Faucibus et molestie ac feugiat sed. Risus feugiat in ante metus dictum at tempor commodo. Arcu dui vivamus arcu felis. Faucibus scelerisque eleifend donec pretium vulputate sapien. Egestas diam in arcu cursus euismod quis viverra nibh. Vel fringilla est ullamcorper eget nulla. Magna etiam tempor orci eu. Aenean vel elit scelerisque mauris pellentesque pulvinar pellentesque habitant morbi. Mattis molestie a iaculis at erat pellentesque adipiscing commodo. Ultrices sagittis orci a scelerisque. Eu lobortis elementum nibh tellus molestie nunc non blandit massa.</span></div>
',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      5 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-right',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/robert-lamb-5397_1.jpg',
              'filesize' => 58169,
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'image',
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      6 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<div>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Fusce ut placerat orci nulla. Congue quisque egestas diam in arcu cursus euismod quis viverra. Cursus risus at ultrices mi tempus imperdiet nulla. Pellentesque diam volutpat commodo sed egestas. Netus et malesuada fames ac.</div>
<div>&nbsp;</div>
<div>Porta non pulvinar neque laoreet suspendisse interdum. Pharetra massa massa ultricies mi quis. Ut ornare lectus sit amet est placerat in egestas. Egestas dui id ornare arcu. Id leo in vitae turpis massa sed. Volutpat maecenas volutpat blandit aliquam. A scelerisque purus semper eget duis at tellus at. Sit amet consectetur adipiscing elit duis tristique sollicitudin.</div>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<div>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Fusce ut placerat orci nulla. Congue quisque egestas diam in arcu cursus euismod quis viverra. Cursus risus at ultrices mi tempus imperdiet nulla. Pellentesque diam volutpat commodo sed egestas. Netus et malesuada fames ac.</div>
<div> </div>
<div>Porta non pulvinar neque laoreet suspendisse interdum. Pharetra massa massa ultricies mi quis. Ut ornare lectus sit amet est placerat in egestas. Egestas dui id ornare arcu. Id leo in vitae turpis massa sed. Volutpat maecenas volutpat blandit aliquam. A scelerisque purus semper eget duis at tellus at. Sit amet consectetur adipiscing elit duis tristique sollicitudin.</div>
',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      7 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/igor-peftiev-61366_0.jpg',
                    'filesize' => 272149,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Insert caption here itae ultricies leo integer malesuada nunc.',
                    'format' => NULL,
                    'safe_value' => 'Insert caption here itae ultricies leo integer malesuada nunc.',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/arthur-105596_0.jpg',
                    'filesize' => 1122521,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Insert caption here itae ultricies leo integer malesuada nunc.',
                    'format' => NULL,
                    'safe_value' => 'Insert caption here itae ultricies leo integer malesuada nunc.',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
      8 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<h3>Lorem ipsum dolor sit amet</h3>
<div>Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Morbi quis commodo odio aenean. Augue lacus viverra vitae congue eu. Morbi tristique senectus et netus et malesuada fames ac turpis. Blandit libero volutpat sed cras ornare arcu dui. Enim facilisis gravida neque convallis a. Lectus arcu bibendum at varius vel pharetra vel.</div>
<h3>Odio aenean sed adipiscing diam.</h3>
<div>Non tellus orci ac auctor augue mauris augue. Tortor pretium viverra suspendisse potenti nullam ac. Sed felis eget velit aliquet sagittis id consectetur. Ultrices neque ornare aenean euismod elementum nisi. Integer vitae justo eget magna. Auctor augue mauris augue neque.</div>
<div>&nbsp;</div>
<div>Pharetra magna ac placerat vestibulum lectus mauris ultrices. Posuere lorem ipsum dolor sit amet consectetur adipiscing elit. Leo vel orci porta non pulvinar. Arcu odio ut sem nulla. Congue quisque egestas diam in arcu. Lorem ipsum dolor sit amet consectetur adipiscing elit pellentesque. Ipsum dolor sit amet consectetur adipiscing elit pellentesque. Eget mi proin sed libero enim sed faucibus turpis in. Id cursus metus aliquam eleifend mi in nulla. Amet est placerat in egestas erat imperdiet.</div>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<h3>Lorem ipsum dolor sit amet</h3>
<div>Consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Morbi quis commodo odio aenean. Augue lacus viverra vitae congue eu. Morbi tristique senectus et netus et malesuada fames ac turpis. Blandit libero volutpat sed cras ornare arcu dui. Enim facilisis gravida neque convallis a. Lectus arcu bibendum at varius vel pharetra vel.</div>
<h3>Odio aenean sed adipiscing diam.</h3>
<div>Non tellus orci ac auctor augue mauris augue. Tortor pretium viverra suspendisse potenti nullam ac. Sed felis eget velit aliquet sagittis id consectetur. Ultrices neque ornare aenean euismod elementum nisi. Integer vitae justo eget magna. Auctor augue mauris augue neque.</div>
<div> </div>
<div>Pharetra magna ac placerat vestibulum lectus mauris ultrices. Posuere lorem ipsum dolor sit amet consectetur adipiscing elit. Leo vel orci porta non pulvinar. Arcu odio ut sem nulla. Congue quisque egestas diam in arcu. Lorem ipsum dolor sit amet consectetur adipiscing elit pellentesque. Ipsum dolor sit amet consectetur adipiscing elit pellentesque. Eget mi proin sed libero enim sed faucibus turpis in. Id cursus metus aliquam eleifend mi in nulla. Amet est placerat in egestas erat imperdiet.</div>
',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      9 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Read More',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/wynand-van-poortvliet-64523_0_0.jpg',
                    'filesize' => 78257,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                    'format' => NULL,
                    'safe_value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Related Article Title',
                    'format' => NULL,
                    'safe_value' => 'Related Article Title',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Read More',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/andrea-vincenzo-abbondanza-38989_0_0.jpg',
                    'filesize' => 80167,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                    'format' => NULL,
                    'safe_value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Related Article Title',
                    'format' => NULL,
                    'safe_value' => 'Related Article Title',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            2 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Read More',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/dino-reichmuth-85708_0_0.jpg',
                    'filesize' => 90817,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                    'format' => NULL,
                    'safe_value' => 'Short article teaser can go here. Sit amet mauris commodo quis imperdiet.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Related Article Title',
                    'format' => NULL,
                    'safe_value' => 'Related Article Title',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
    ),
  );

  $paragraphs_defaults['node-stanford_story_page-field_s_story_sections-campaign'] = array(
    'label' => 'Campaign',
    'machine_name' => 'campaign',
    'entity_type' => 'node',
    'field_name' => 'field_s_story_sections',
    'bundle' => 'stanford_story_page',
    'paragraphs' => array(
      0 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-left',
            ),
          ),
        ),
        'field_p_hero_headline' => array(
          'und' => array(
            0 => array(
              'value' => 'Feature a headline for your campaign here',
              'format' => NULL,
              'safe_value' => 'Feature a headline for your campaign here',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/joshua-earle-1794_0.jpg',
              'filesize' => 570421,
            ),
          ),
        ),
        'field_p_hero_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Learn more',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'image',
            ),
          ),
        ),
        'field_p_hero_superhead' => array(
          'und' => array(
            0 => array(
              'value' => 'Program Title',
              'format' => NULL,
              'safe_value' => 'Program Title',
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      1 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="summary">This is an example of a campaign page. Drive readers with specific call-to-action buttons like learn more, connect, attend, apply, etc. To edit the page and remove this placeholder content, click on the &quot;Edit&quot; tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click &quot;Save.&quot;</p>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p class="summary">This is an example of a campaign page. Drive readers with specific call-to-action buttons like learn more, connect, attend, apply, etc. To edit the page and remove this placeholder content, click on the "Edit" tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click "Save."</p>
',
            ),
          ),
        ),
        'field_p_wysiwyg_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/tamarcus-brown-134928_0_0.jpg',
              'filesize' => 221305,
            ),
          ),
        ),
        'field_p_wysiwyg_title' => array(
          'und' => array(
            0 => array(
              'value' => 'Insert a title here',
              'format' => NULL,
              'safe_value' => 'Insert a title here',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      2 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_callout',
        'field_p_callout_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Learn more',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_callout_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Insert callout text here. Feature a highlight, fun fact, quote, and more.</p>',
              'format' => 'minimal_html',
              'safe_value' => '<p>Insert callout text here. Feature a highlight, fun fact, quote, and more.</p>',
            ),
          ),
        ),
        'entity_bundle' => 'p_callout',
        'entity_type' => 'paragraphs_item',
      ),
      3 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Connect with us',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/steven-lewis-342_0_0.jpg',
                    'filesize' => 58782,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                    'format' => NULL,
                    'safe_value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Insert title here',
                    'format' => NULL,
                    'safe_value' => 'Insert title here',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Attend an event',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/alexis-brown-85793_0_0.jpg',
                    'filesize' => 65692,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                    'format' => NULL,
                    'safe_value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Insert title here',
                    'format' => NULL,
                    'safe_value' => 'Insert title here',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            2 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => 'www.stanford.edu',
                    'title' => 'Apply now',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => 'please insert alt text for all images',
                    'title' => '',
                    'uri' => 'assets/aidan-meyer-129877_0_0.jpg',
                    'filesize' => 61170,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                    'format' => NULL,
                    'safe_value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Insert title here',
                    'format' => NULL,
                    'safe_value' => 'Insert title here',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
      4 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-right',
            ),
          ),
        ),
        'field_p_hero_headline' => array(
          'und' => array(
            0 => array(
              'value' => 'Insert headline here',
              'format' => NULL,
              'safe_value' => 'Insert headline here',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/dmitri-popov-152263_0_0.jpg',
              'filesize' => 708228,
            ),
          ),
        ),
        'field_p_hero_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'https://www.youtube.com/watch?v=0qHWub21h5c',
              'title' => 'Watch video',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'both',
            ),
          ),
        ),
        'field_p_hero_video' => array(
          'und' => array(
            0 => array(
              'video_url' => 'https://www.youtube.com/watch?v=0qHWub21h5c',
              'video_data' => 'a:1:{s:7:"handler";s:7:"youtube";}',
              'embed_code' => NULL,
              'description' => NULL,
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      5 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p>&quot;Insert a quote or testimonial. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.&quot;</p>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p>"Insert a quote or testimonial. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."</p>
',
            ),
          ),
        ),
        'field_p_wysiwyg_button' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Read Joe\'s story',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_wysiwyg_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/fritz-walter-152075_0.jpg',
              'filesize' => 540201,
            ),
          ),
        ),
        'field_p_wysiwyg_title' => array(
          'und' => array(
            0 => array(
              'value' => 'Meet Joe Smith',
              'format' => NULL,
              'safe_value' => 'Meet Joe Smith',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      6 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p>&quot;Insert a quote or testimonial.&nbsp;Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.&quot;</p>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p>"Insert a quote or testimonial. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."</p>
',
            ),
          ),
        ),
        'field_p_wysiwyg_button' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Read Jane\'s Story',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_wysiwyg_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/clem-onojeghuo-210987_0.jpg',
              'filesize' => 550357,
            ),
          ),
        ),
        'field_p_wysiwyg_title' => array(
          'und' => array(
            0 => array(
              'value' => 'Meet Jane Smith',
              'format' => NULL,
              'safe_value' => 'Meet Jane Smith',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      7 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p>&quot;Insert a quote or testimonial.&nbsp;Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.&quot;</p>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p>"Insert a quote or testimonial. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."</p>
',
            ),
          ),
        ),
        'field_p_wysiwyg_button' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Read John\'s story',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_wysiwyg_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/norman-toth-177973_0.jpg',
              'filesize' => 457458,
            ),
          ),
        ),
        'field_p_wysiwyg_title' => array(
          'und' => array(
            0 => array(
              'value' => 'Meet John Doe',
              'format' => NULL,
              'safe_value' => 'Meet John Doe',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      8 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_callout',
        'field_p_callout_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'www.stanford.edu',
              'title' => 'Learn more',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_callout_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p><span style="font-size: 13.008px;">Insert callout text here. Feature a highlight, fun fact, quote, and more. </span></p>',
              'format' => 'minimal_html',
              'safe_value' => '<p>Insert callout text here. Feature a highlight, fun fact, quote, and more. </p>',
            ),
          ),
        ),
        'entity_bundle' => 'p_callout',
        'entity_type' => 'paragraphs_item',
      ),
    ),
  );

  $paragraphs_defaults['node-stanford_story_page-field_s_story_sections-fundraising'] = array(
    'label' => 'Fundraising',
    'machine_name' => 'fundraising',
    'entity_type' => 'node',
    'field_name' => 'field_s_story_sections',
    'bundle' => 'stanford_story_page',
    'paragraphs' => array(
      0 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-right',
            ),
          ),
        ),
        'field_p_hero_headline' => array(
          'und' => array(
            0 => array(
              'value' => 'Feature a headline for your fundraiser here',
              'format' => NULL,
              'safe_value' => 'Feature a headline for your fundraiser here',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/alejandro-alvarez-150148b_0.jpeg',
              'filesize' => 468462,
            ),
          ),
        ),
        'field_p_hero_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'makeagift.stanford.edu',
              'title' => 'Make a gift',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'image',
            ),
          ),
        ),
        'field_p_hero_superhead' => array(
          'und' => array(
            0 => array(
              'value' => 'Giving',
              'format' => NULL,
              'safe_value' => 'Giving',
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      1 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_callout',
        'field_p_callout_more_link' => array(
          'und' => array(
            0 => array(
              'url' => 'makeagift.stanford.edu',
              'title' => 'Make a gift online now',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_callout_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Insert callout text here. Feature a highlight, fun fact, quote, and more.</p>',
              'format' => 'minimal_html',
              'safe_value' => '<p>Insert callout text here. Feature a highlight, fun fact, quote, and more.</p>',
            ),
          ),
        ),
        'entity_bundle' => 'p_callout',
        'entity_type' => 'paragraphs_item',
      ),
      2 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<div>
	<p class="summary"><span style="letter-spacing: 0.01em;">This is an example fundraising page. Use compelling imagery with&nbsp;</span>call-to-action buttons<span style="letter-spacing: 0.01em;">&nbsp;to drive readers to make a gift. To edit the page and remove this placeholder content, click on the &quot;Edit&quot; tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click &quot;Save.&quot;</span></p>
</div>
<h3>Your gift matters</h3>
<div>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum.</div>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<div>
	<p class="summary"><span>This is an example fundraising page. Use compelling imagery with </span>call-to-action buttons<span> to drive readers to make a gift. To edit the page and remove this placeholder content, click on the "Edit" tab near the top of the page. When finished, be sure to scroll down to the bottom of the page and click "Save."</span></p>
</div>
<h3>Your gift matters</h3>
<div>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum.</div>
',
            ),
          ),
        ),
        'field_p_wysiwyg_button' => array(
          'und' => array(
            0 => array(
              'url' => 'makeagift.stanford.edu',
              'title' => 'Make a gift',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_wysiwyg_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/jpeg',
              'alt' => 'please insert alt text for all images',
              'title' => '',
              'uri' => 'assets/larm-rmah-216854_0.jpg',
              'filesize' => 753361,
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
    ),
  );

  $paragraphs_defaults['node-stanford_story_page-field_s_story_sections-homepage'] = array(
    'label' => 'Homepage',
    'machine_name' => 'homepage',
    'entity_type' => 'node',
    'field_name' => 'field_s_story_sections',
    'bundle' => 'stanford_story_page',
    'paragraphs' => array(
      0 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_hero',
        'field_p_hero_alignment' => array(
          'und' => array(
            0 => array(
              'value' => 'overlay-top overlay-left',
            ),
          ),
        ),
        'field_p_hero_headline' => array(
          'und' => array(
            0 => array(
              'value' => 'You can add a headline here',
              'format' => NULL,
              'safe_value' => 'You can add a headline here',
            ),
          ),
        ),
        'field_p_hero_image' => array(
          'und' => array(
            0 => array(
              'filemime' => 'image/png',
              'alt' => '',
              'title' => '',
              'uri' => 'assets/stanford-main.png',
              'filesize' => 10067260,
            ),
          ),
        ),
        'field_p_hero_more_link' => array(
          'und' => array(
            0 => array(
              'url' => '<front>',
              'title' => 'You can add a learn more link here',
              'attributes' => array(),
            ),
          ),
        ),
        'field_p_hero_style' => array(
          'und' => array(
            0 => array(
              'value' => 'image',
            ),
          ),
        ),
        'field_p_hero_superhead' => array(
          'und' => array(
            0 => array(
              'value' => 'Hero Image Title',
              'format' => NULL,
              'safe_value' => 'Hero Image Title',
            ),
          ),
        ),
        'entity_bundle' => 'p_hero',
        'entity_type' => 'paragraphs_item',
      ),
      1 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_section_header',
        'field_p_section_color' => array(
          'und' => array(
            0 => array(
              'value' => 'light-taupe',
            ),
          ),
        ),
        'field_p_section_heading' => array(
          'und' => array(
            0 => array(
              'value' => '"Department Name" Mission',
              'format' => NULL,
              'safe_value' => '&quot;Department Name&quot; Mission',
            ),
          ),
        ),
        'entity_bundle' => 'p_section_header',
        'entity_type' => 'paragraphs_item',
      ),
      2 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_icon',
        'field_p_icon_columns' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_icon_columns',
              'field_p_icon_color' => array(
                'und' => array(
                  0 => array(
                    'value' => 'red',
                  ),
                ),
              ),
              'field_p_icon_icon' => array(
                'und' => array(
                  0 => array(
                    'icon' => 'globe',
                  ),
                ),
              ),
              'field_p_icon_links' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Read how our work betters the world',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_icon_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Global Initiatives',
                    'format' => NULL,
                    'safe_value' => 'Global Initiatives',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_icon_columns',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_icon_columns',
              'field_p_icon_color' => array(
                'und' => array(
                  0 => array(
                    'value' => 'red',
                  ),
                ),
              ),
              'field_p_icon_icon' => array(
                'und' => array(
                  0 => array(
                    'icon' => 'graduation-cap',
                  ),
                ),
              ),
              'field_p_icon_links' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Explore our unrivaled programs',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_icon_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Degree Programs',
                    'format' => NULL,
                    'safe_value' => 'Degree Programs',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_icon_columns',
              'entity_type' => 'field_collection_item',
            ),
            2 => array(
              'field_name' => 'field_p_icon_columns',
              'field_p_icon_color' => array(
                'und' => array(
                  0 => array(
                    'value' => 'red',
                  ),
                ),
              ),
              'field_p_icon_icon' => array(
                'und' => array(
                  0 => array(
                    'icon' => 'flask',
                  ),
                ),
              ),
              'field_p_icon_links' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'See what or faculty is focused on',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_icon_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Research Areas',
                    'format' => NULL,
                    'safe_value' => 'Research Areas',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_icon_columns',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_icon',
        'entity_type' => 'paragraphs_item',
      ),
      3 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_wysiwyg',
        'field_p_wysiwyg_body' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Our mission is to&nbsp;Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
              'format' => 'content_editor_text_format',
              'safe_value' => '<p>Our mission is to Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
            ),
          ),
        ),
        'entity_bundle' => 'p_wysiwyg',
        'entity_type' => 'paragraphs_item',
      ),
      4 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_section_header',
        'field_p_section_color' => array(
          'und' => array(
            0 => array(
              'value' => 'light-taupe',
            ),
          ),
        ),
        'field_p_section_heading' => array(
          'und' => array(
            0 => array(
              'value' => '"Department Name" Experience',
              'format' => NULL,
              'safe_value' => '&quot;Department Name&quot; Experience',
            ),
          ),
        ),
        'entity_bundle' => 'p_section_header',
        'entity_type' => 'paragraphs_item',
      ),
      5 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Read her full story',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => '',
                    'title' => '',
                    'uri' => 'assets/quino-al-260327.jpg',
                    'filesize' => 4265875,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Ruby Nelson reflects on how finding ways to balance her studies and hobbies has lead to increased happiness and success.',
                    'format' => NULL,
                    'safe_value' => 'Ruby Nelson reflects on how finding ways to balance her studies and hobbies has lead to increased happiness and success.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Community Spotlight',
                    'format' => NULL,
                    'safe_value' => 'Community Spotlight',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Discover how our students team up',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => '',
                    'title' => '',
                    'uri' => 'assets/stefan-stefancik-257625.jpg',
                    'filesize' => 11260498,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'At Department Name, we believe that the power of us outweighs the power of I.',
                    'format' => NULL,
                    'safe_value' => 'At Department Name, we believe that the power of us outweighs the power of I.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'A Culture of Collaboration',
                    'format' => NULL,
                    'safe_value' => 'A Culture of Collaboration',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            2 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Meet the 2018 incoming class',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => '',
                    'title' => '',
                    'uri' => 'assets/faustin-tuyambaze-135473.jpg',
                    'filesize' => 5941123,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'What impact with this year\'s incoming freshman have on the world? What role will you play?',
                    'format' => NULL,
                    'safe_value' => 'What impact with this year&#039;s incoming freshman have on the world? What role will you play?',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'The Class of 2022',
                    'format' => NULL,
                    'safe_value' => 'The Class of 2022',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
      6 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_section_header',
        'field_p_section_color' => array(
          'und' => array(
            0 => array(
              'value' => 'light-taupe',
            ),
          ),
        ),
        'field_p_section_heading' => array(
          'und' => array(
            0 => array(
              'value' => 'Latest Happenings at "Department Name"',
              'format' => NULL,
              'safe_value' => 'Latest Happenings at &quot;Department Name&quot;',
            ),
          ),
        ),
        'entity_bundle' => 'p_section_header',
        'entity_type' => 'paragraphs_item',
      ),
      7 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_views',
        'field_p_views_view' => array(
          'und' => array(
            0 => array(
              'moddelta' => 'views:stanford_events_views-block',
            ),
            1 => array(
              'moddelta' => 'views:f73ff55b085ea49217d347de6630cd5a',
            ),
          ),
        ),
        'entity_bundle' => 'p_views',
        'entity_type' => 'paragraphs_item',
      ),
      8 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_section_header',
        'field_p_section_color' => array(
          'und' => array(
            0 => array(
              'value' => 'light-taupe',
            ),
          ),
        ),
        'field_p_section_heading' => array(
          'und' => array(
            0 => array(
              'value' => 'Connect With Us',
              'format' => NULL,
              'safe_value' => 'Connect With Us',
            ),
          ),
        ),
        'entity_bundle' => 'p_section_header',
        'entity_type' => 'paragraphs_item',
      ),
      9 => array(
        'field_name' => 'field_s_story_sections',
        'bundle' => 'p_cards',
        'field_p_cards_card' => array(
          'und' => array(
            0 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Find us on the web',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => '',
                    'title' => '',
                    'uri' => 'assets/kyra-preston-245906.jpg',
                    'filesize' => 3652957,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Stay informed on what\'s going with at Department Name by connecting with us online.',
                    'format' => NULL,
                    'safe_value' => 'Stay informed on what&#039;s going with at Department Name by connecting with us online.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => '#DeparmentNameSocial',
                    'format' => NULL,
                    'safe_value' => '#DeparmentNameSocial',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
            1 => array(
              'field_name' => 'field_p_cards_card',
              'field_p_card_action_button' => array(
                'und' => array(
                  0 => array(
                    'value' => 'link',
                  ),
                ),
              ),
              'field_p_card_cta' => array(
                'und' => array(
                  0 => array(
                    'url' => '<front>',
                    'title' => 'Subscribe to our newsletter',
                    'attributes' => array(),
                  ),
                ),
              ),
              'field_p_card_hide_cta' => array(
                'und' => array(
                  0 => array(
                    'value' => 0,
                  ),
                ),
              ),
              'field_p_card_image' => array(
                'und' => array(
                  0 => array(
                    'filemime' => 'image/jpeg',
                    'alt' => '',
                    'title' => '',
                    'uri' => 'assets/chris-adamus-30863.jpg',
                    'filesize' => 5383741,
                  ),
                ),
              ),
              'field_p_card_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Get monthly updates on all that\'s going on in Department Name.',
                    'format' => NULL,
                    'safe_value' => 'Get monthly updates on all that&#039;s going on in Department Name.',
                  ),
                ),
              ),
              'field_p_card_title' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Stay Up To Date',
                    'format' => NULL,
                    'safe_value' => 'Stay Up To Date',
                  ),
                ),
              ),
              'entity_bundle' => 'field_p_cards_card',
              'entity_type' => 'field_collection_item',
            ),
          ),
        ),
        'entity_bundle' => 'p_cards',
        'entity_type' => 'paragraphs_item',
      ),
    ),
  );

  return $paragraphs_defaults;
}
