Stanford Memory Booster
=======================

This module allows one to increase the PHP memory_limit, using the ini_set() 
function. The default value whatever is in php.ini; that can be increased or
decreased by setting the 'stanford_memory_limit' variable, e.g.,:

drush vset stanford_memory_limit 196M

Syntax for the stanford_memory_limit variable is the same as for the memory_limit 
setting in php.ini.

See http://www.php.net/manual/en/ini.core.php#ini.memory-limit
