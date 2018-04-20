<?php
/**
 * @file
 * stanford_courses.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_courses_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_course_co_person'.
  $field_bases['field_s_course_co_person'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_co_person',
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

  // Exported field_base: 'field_s_course_code'.
  $field_bases['field_s_course_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_code',
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

  // Exported field_base: 'field_s_course_code_integer'.
  $field_bases['field_s_course_code_integer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_code_integer',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_s_course_component'.
  $field_bases['field_s_course_component'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_component',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ACT' => 'ACT',
        'CLK' => 'CLK',
        'COL' => 'COL',
        'DIS' => 'DIS',
        'SEM' => 'SEM',
        'RES' => 'RES',
        'INS' => 'INS',
        'ITR' => 'ITR',
        'LBS' => 'LBS',
        'LAB' => 'LAB',
        'LEC' => 'LEC',
        'PRC' => 'PRC',
        'LNG' => 'LNG',
        'IDS' => 'IDS',
        'ISF' => 'ISF',
        'ISS' => 'ISS',
        'SCS' => 'SCS',
        'T/D' => 'T/D',
        'WKS' => 'WKS',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_s_course_dow'.
  $field_bases['field_s_course_dow'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_dow',
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

  // Exported field_base: 'field_s_course_ec_link'.
  $field_bases['field_s_course_ec_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_ec_link',
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

  // Exported field_base: 'field_s_course_ec_tag'.
  $field_bases['field_s_course_ec_tag'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_ec_tag',
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

  // Exported field_base: 'field_s_course_ger'.
  $field_bases['field_s_course_ger'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_ger',
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

  // Exported field_base: 'field_s_course_grading'.
  $field_bases['field_s_course_grading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_grading',
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

  // Exported field_base: 'field_s_course_id'.
  $field_bases['field_s_course_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_s_course_instructor'.
  $field_bases['field_s_course_instructor'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_instructor',
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

  // Exported field_base: 'field_s_course_location'.
  $field_bases['field_s_course_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_location',
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

  // Exported field_base: 'field_s_course_scid'.
  $field_bases['field_s_course_scid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_scid',
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

  // Exported field_base: 'field_s_course_section_class_id'.
  $field_bases['field_s_course_section_class_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_section_class_id',
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

  // Exported field_base: 'field_s_course_section_dates'.
  $field_bases['field_s_course_section_dates'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_section_dates',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 1,
      'cache_enabled' => 1,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => 'optional',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_s_course_section_info'.
  $field_bases['field_s_course_section_info'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_section_info',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'hide_initial_item' => FALSE,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_s_course_section_number'.
  $field_bases['field_s_course_section_number'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_section_number',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_s_course_section_year'.
  $field_bases['field_s_course_section_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_section_year',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1891 => '1891-1892',
        1892 => '1892-1893',
        1893 => '1893-1894',
        1894 => '1894-1895',
        1895 => '1895-1896',
        1896 => '1896-1897',
        1897 => '1897-1898',
        1898 => '1898-1899',
        1899 => '1899-1900',
        1900 => '1900-1901',
        1901 => '1901-1902',
        1902 => '1902-1903',
        1903 => '1903-1904',
        1904 => '1904-1905',
        1905 => '1905-1906',
        1906 => '1906-1907',
        1907 => '1907-1908',
        1908 => '1908-1909',
        1909 => '1909-1910',
        1910 => '1910-1911',
        1911 => '1911-1912',
        1912 => '1912-1913',
        1913 => '1913-1914',
        1914 => '1914-1915',
        1915 => '1915-1916',
        1916 => '1916-1917',
        1917 => '1917-1918',
        1918 => '1918-1919',
        1919 => '1919-1920',
        1920 => '1920-1921',
        1921 => '1921-1922',
        1922 => '1922-1923',
        1923 => '1923-1924',
        1924 => '1924-1925',
        1925 => '1925-1926',
        1926 => '1926-1927',
        1927 => '1927-1928',
        1928 => '1928-1929',
        1929 => '1929-1930',
        1930 => '1930-1931',
        1931 => '1931-1932',
        1932 => '1932-1933',
        1933 => '1933-1934',
        1934 => '1934-1935',
        1935 => '1935-1936',
        1936 => '1936-1937',
        1937 => '1937-1938',
        1938 => '1938-1939',
        1939 => '1939-1940',
        1940 => '1940-1941',
        1941 => '1941-1942',
        1942 => '1942-1943',
        1943 => '1943-1944',
        1944 => '1944-1945',
        1945 => '1945-1946',
        1946 => '1946-1947',
        1947 => '1947-1948',
        1948 => '1948-1949',
        1949 => '1949-1950',
        1950 => '1950-1951',
        1951 => '1951-1952',
        1952 => '1952-1953',
        1953 => '1953-1954',
        1954 => '1954-1955',
        1955 => '1955-1956',
        1956 => '1956-1957',
        1957 => '1957-1958',
        1958 => '1958-1959',
        1959 => '1959-1960',
        1960 => '1960-1961',
        1961 => '1961-1962',
        1962 => '1962-1963',
        1963 => '1963-1964',
        1964 => '1964-1965',
        1965 => '1965-1966',
        1966 => '1966-1967',
        1967 => '1967-1968',
        1968 => '1968-1969',
        1969 => '1969-1970',
        1970 => '1970-1971',
        1971 => '1971-1972',
        1972 => '1972-1973',
        1973 => '1973-1974',
        1974 => '1974-1975',
        1975 => '1975-1976',
        1976 => '1976-1977',
        1977 => '1977-1978',
        1978 => '1978-1979',
        1979 => '1979-1980',
        1980 => '1980-1981',
        1981 => '1981-1982',
        1982 => '1982-1983',
        1983 => '1983-1984',
        1984 => '1984-1985',
        1985 => '1985-1986',
        1986 => '1986-1987',
        1987 => '1987-1988',
        1988 => '1988-1989',
        1989 => '1989-1990',
        1990 => '1990-1991',
        1991 => '1991-1992',
        1992 => '1992-1993',
        1993 => '1993-1994',
        1994 => '1994-1995',
        1995 => '1995-1996',
        1996 => '1996-1997',
        1997 => '1997-1998',
        1998 => '1998-1999',
        1999 => '1999-2000',
        2000 => '2000-2001',
        2001 => '2001-2002',
        2002 => '2002-2003',
        2003 => '2003-2004',
        2004 => '2004-2005',
        2005 => '2005-2006',
        2006 => '2006-2007',
        2007 => '2007-2008',
        2008 => '2008-2009',
        2009 => '2009-2010',
        2010 => '2010-2011',
        2011 => '2011-2012',
        2012 => '2012-2013',
        2013 => '2013-2014',
        2014 => '2014-2015',
        2015 => '2015-2016',
        2016 => '2016-2017',
        2017 => '2017-2018',
        2018 => '2018-2019',
        2019 => '2019-2020',
        2020 => '2020-2021',
        2021 => '2021-2022',
        2022 => '2022-2023',
        2023 => '2023-2024',
        2024 => '2024-2025',
        2025 => '2025-2026',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_s_course_subject'.
  $field_bases['field_s_course_subject'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_subject',
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

  // Exported field_base: 'field_s_course_syllabus'.
  $field_bases['field_s_course_syllabus'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_syllabus',
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

  // Exported field_base: 'field_s_course_tag_name'.
  $field_bases['field_s_course_tag_name'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_tag_name',
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

  // Exported field_base: 'field_s_course_tag_org'.
  $field_bases['field_s_course_tag_org'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_tag_org',
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

  // Exported field_base: 'field_s_course_term'.
  $field_bases['field_s_course_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_term',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Autumn' => 'Autumn',
        'Winter' => 'Winter',
        'Spring' => 'Spring',
        'Summer' => 'Summer',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_s_course_time'.
  $field_bases['field_s_course_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_time',
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

  // Exported field_base: 'field_s_course_time_end'.
  $field_bases['field_s_course_time_end'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_time_end',
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

  // Exported field_base: 'field_s_course_units'.
  $field_bases['field_s_course_units'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_units',
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

  // Exported field_base: 'field_s_course_year'.
  $field_bases['field_s_course_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_year',
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

  // Exported field_base: 'field_s_course_year_computed'.
  $field_bases['field_s_course_year_computed'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_year_computed',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'month' => 0,
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  return $field_bases;
}
