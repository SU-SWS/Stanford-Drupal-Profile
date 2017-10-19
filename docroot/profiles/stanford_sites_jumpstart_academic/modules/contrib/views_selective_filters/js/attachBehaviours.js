// Trick to make exposed block work after refresh (https://drupal.org/node/2182885).
jQuery.fn.attachBehaviors = function () { Drupal.attachBehaviors(); };
