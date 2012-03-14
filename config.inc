<?php

function get_stanford_installer() {
  $fields = array(
    'org_type' => 'group',
    'site_name' => 'swsdev99',
    'site_mail' => 'jbickar@stanford.edu',
    'sd_enable_webauth' => 1,
    'tmpdir' => 'sites.stanford.edu.swsdev99',
  );
  
  return $fields;
}
