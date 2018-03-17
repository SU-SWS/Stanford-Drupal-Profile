(function ($) {
  $().ready(function() {
    var alertMsg = $('div.alert-success.alert-block.alert').text();
    var alertMatch = alertMsg.match(/Stanford Banner/g);
    if (alertMatch != null) {
      var newMsg = $('div.alert-success.alert-block.alert').html().replace('Stanford Banner', 'The block');
      $('div.alert-success.alert-block.alert').html(newMsg);
    }
    var alertMatch = alertMsg.match(/Stanford Contact/g);
    if (alertMatch != null) {
      var newMsg = $('div.alert-success.alert-block.alert').html().replace('Stanford Contact', 'The block');
      $('div.alert-success.alert-block.alert').html(newMsg);
    }
    var alertMatch = alertMsg.match(/Stanford Large Block/g);
    if (alertMatch != null) {
      var newMsg = $('div.alert-success.alert-block.alert').html().replace('Stanford Large Block', 'The block');
      $('div.alert-success.alert-block.alert').html(newMsg);
    }
    var alertMatch = alertMsg.match(/Stanford Postcard/g);
    if (alertMatch != null) {
      var newMsg = $('div.alert-success.alert-block.alert').html().replace('Stanford Postcard', 'The block');
      $('div.alert-success.alert-block.alert').html(newMsg);
    }
    var alertMatch = alertMsg.match(/Stanford Social Media Connect/g);
    if (alertMatch != null) {
      var newMsg = $('div.alert-success.alert-block.alert').html().replace('Stanford Social Media Connect', 'The block');
      $('div.alert-success.alert-block.alert').html(newMsg);
    }
  }); 
})(jQuery);