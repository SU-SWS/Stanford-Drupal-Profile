<?php

/**
 * @file
 * Filter based on a list of words/phrases.
 */

$plugin = array(
  'form' => 'stanford_courses_array_filter_form',
  'callback' => 'stanford_courses_array_filter_callback',
  'validate' => 'stanford_courses_array_filter_validate',
  'name' => 'Array keyword filter',
  'multi' => 'loop',
  'category' => 'List',
);

function stanford_courses_array_filter_form($importer, $element_key, $settings) {
  $form = array();
  $form['words'] = array(
    '#type' => 'textarea',
    '#title' => t('Words or phrases to filter on'),
    '#default_value' => isset($settings['words']) ? $settings['words'] : '',
    '#description' => t('A list of words/phrases that need to appear in the text.'),
  );
  $form['word_boundaries'] = array(
    '#type' => 'checkbox',
    '#title' => t('Respect word boundaries'),
    '#default_value' => isset($settings['word_boundaries']) ? $settings['word_boundaries'] : FALSE,
    '#description' => t('If checked, then "book" will match "book" but not "bookcase".'),
  );
  $form['exact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exact'),
    '#default_value' => isset($settings['exact']) ? $settings['exact'] : FALSE,
    '#description' => t('If checked, then "book" will only match "book". This will override the "Respect word boundaries" setting above.'),
  );
  $form['case_sensitive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Case sensitive'),
    '#default_value' => isset($settings['case_sensitive']) ? $settings['case_sensitive'] : FALSE,
    '#description' => t('If checked, then "book" will match "book" but not "Book" or "BOOK".'),
  );
  $form['invert'] = array(
    '#type' => 'checkbox',
    '#title' => t('Invert filter'),
    '#default_value' => isset($settings['invert']) ? $settings['invert'] : FALSE,
    '#description' => t('Inverting the filter will %remove items with the specified text.', array('%remove' => 'remove')),
  );
  return $form;
}

function stanford_courses_array_filter_validate(&$settings) {
  global $multibyte;
  $is_multibyte = ($multibyte == UNICODE_MULTIBYTE) ? TRUE : FALSE;

  $settings['words'] = str_replace("\r", '', $settings['words']);
  $settings['word_list'] = explode("\n", $settings['words']);
  $settings['word_list'] = array_map('trim', $settings['word_list']);
  $settings['regex'] = FALSE;

  if (!empty($settings['exact']) || $settings['word_boundaries']) {
    foreach ($settings['word_list'] as &$word) {
      if (!empty($settings['exact'])) {
        $word = '/^' . preg_quote($word, '/') . '$/u';
      }
      elseif ($settings['word_boundaries']) {
        // Word boundaries can only match a word with letters at the end.
        if (!preg_match('/^\w(.*\w)?$/u', $word)) {
          form_set_error('settings][words', t('Search text must begin and end with a letter, number, or underscore to use the %option option.', array('%option' => t('Respect word boundaries'))));
        }
        $word = '/\b' . preg_quote($word, '/') . '\b/u';
      }
      if (!$settings['case_sensitive']) {
        $word .= 'i';
      }
    }
    $settings['regex'] = TRUE;
  }

  elseif (!$settings['word_boundaries'] && $settings['case_sensitive']) {
    $settings['func'] = $is_multibyte ? 'mb_strpos' : 'strpos';
  }
  elseif (!$settings['word_boundaries'] && !$settings['case_sensitive']) {
    $settings['func'] = $is_multibyte ? 'mb_stripos' : 'stripos';
  }
}

/**
 * @param $result
 * @param $item_key
 * @param $element_key
 * @param $field
 * @param array $settings
 */
function stanford_courses_array_filter_callback(&$result, $item_key, $element_key, &$field, array $settings) {

  $pos = array_search($field, $result->items[$item_key][$element_key]);

  if ($settings['regex']) {
    foreach ($settings['word_list'] as $word) {
      if (preg_match($word, $field) > 0) {
        if (!$settings['invert']) {
          return;
        }
        unset($result->items[$item_key][$element_key][$pos]);
        return;
      }
    }
  }
  else {
    foreach ($settings['word_list'] as $word) {
      if ($settings['func']($field, $word) !== FALSE) {
        if (!$settings['invert']) {
          return;
        }
        unset($result->items[$item_key][$element_key][$pos]);
        return;
      }
    }
  }
  if (!$settings['invert']) {
    unset($result->items[$item_key][$element_key][$pos]);
  }
}
