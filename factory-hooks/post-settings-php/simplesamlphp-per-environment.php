<?php
/**
 * @file
 * This file configures the path to simplesamlphp on a per-environment basis.
 */

if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  // simplesamlphp lives in a different directory on different environments
  switch ($_ENV['AH_SITE_ENVIRONMENT'])
  {
    case '02dev':
      $conf['stanford_simplesamlphp_auth_installdir'] = '/var/www/html/cardinald7.02dev/simplesamlphp';
      break;
    case '02test':
      $conf['stanford_simplesamlphp_auth_installdir'] = '/var/www/html/cardinald7.02test/simplesamlphp';
      break;
    case '02live':
      $conf['stanford_simplesamlphp_auth_installdir'] = '/var/www/html/cardinald7.02live/simplesamlphp';
      break;
  }
}
