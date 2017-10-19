Stanford Time Limit Booster
=======================

This module allows one to increase the PHP max_execution_time, using the ini_set()
function. The default value whatever is in php.ini; that can be increased or
decreased by setting the 'stanford_time_limit' variable, e.g.,:

drush vset stanford_time_limit 180

Syntax for the stanford_time_limit variable is the same as for the max_execution_time
setting in php.ini.

See http://php.net/manual/en/info.configuration.php#ini.max-execution-time
