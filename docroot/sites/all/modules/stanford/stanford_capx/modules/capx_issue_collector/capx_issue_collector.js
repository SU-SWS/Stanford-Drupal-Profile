/**
 * Javascript issue collector.
 */

(function ($) {
  Drupal.behaviors.capx_issue_collector = {
    attach: function (context, settings) {

      $.ajax({
        url: "https://stanfordits.atlassian.net/s/7fbdb1a66f93c45a855a9c5e854450f9-T/en_US-ekvyw5/65001/66/1.4.25/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs.js?locale=en-US&collectorId=d2cc7e6a",
        type: "get",
        cache: true,
        dataType: "script"
      });

    }
  };

})(jQuery);
