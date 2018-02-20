<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class AddFeaturesPage extends AbstractInstallTask {

  /**
   * Set Content for the Add features page.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $addblocks = l('Request This Feature', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=Add%20Blocks%20or%20Change%20Block%20Layouts', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));
    $admin_access = l('Request Full Admin Access', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=Full%20Administrative%20Access', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));
    $site_protection = l('Request This Feature', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=In-Development%20Site%20Protection', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));
    $googleanalytics = l('Request This Feature', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=Google%20Analytics', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));
    $afsquota = l('Request This Feature', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=Increased%20File%20Storage', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));
    $rss = l('Request This Feature', 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]&Feature=Display%20an%20External%20RSS%20Feed', array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));

$eod = <<<EOD
    <p>Features are a great way to enhance the functionality of your site. Because Drupal is a fully extensible content management system, you can easily extend the functionality of your site. In the list below you can choose from the standard features offered by Stanford Web Services. Additional features and functionality are available upon request.</p>
    <table width="100%" border="0" cellspacing="0" cellpadding="0" style="border:none;">
     <tr>
        <td><h2>Add Blocks or Change Block Layouts</h2>
        <p>By default, your site includes several blocks located on the homepage and footer (for example). You can request additional blocks for subpage sidebars or landing pages and also request alternate block layouts as seen on the <a href="https://sites.stanford.edu/jumpstart-demo2/" target="_blank">Jumpstart layouts demo pages</a>. When requesting a new block, let us know exactly on which page(s) the block will be displayed (include URLs). If you'd like an alternate block layout, contact us and tell us <a href="https://sites.stanford.edu/jumpstart-demo2/" target="_blank">which layout</a> you would like.</p>
        </td>
        <td><p>{$addblocks}</p></td>
     </tr>
     <tr>
        <td><h2>In-Development Site Protection</h2>
        <p>By default, your site is hidden from search engines while you are in development, but anyone you send the URL to can access the site. If you have sensitive content that you want to protect under WebAuth  while you are developing your site, then request this feature.</p>
        </td>
        <td width="150"><p>{$site_protection}</p></td>
      </tr>
      <tr>
        <td><h2>Google Analytics</h2>
        <p>Tracking your site's usage statistics can be an important part of your website strategy. We can work with you to enable this commonly-used tool to track these stats.</p>
        </td>
        <td><p>{$googleanalytics}</p></td>
      </tr>
      <tr>
        <td><h2>Increased File Storage</h2>
        <p>By default, your site comes with up to 100 MB of file storage. We can work with you to determine how much additional storage you need.</p>
        </td>
        <td><p>{$afsquota}</p></td>
      </tr>
      <tr>
        <td><h2>Display an External RSS Feed</h2>
        <p>Want to display items from a single, external RSS feed or aggregate many feeds into a list on your website? We can generate a block and a full page listing of the most recent items. We can work with you to add this dynamic content to your website. When submitting your request, include links to the RSS feed(s) you want to pull in to your site.</p>
        </td>
        <td><p>{$rss}</p></td>
      </tr>
    </table>
    <div class="block-extrainfo-full">
    <h2>Request Full Admin Access</h2>
    <p>If you are experienced in using Drupal's full administrative options and want the power to enable modules, create Views, and more, you can contact Stanford Web Services to request full administrative access. Having full administrative access means that you can more easily break your site, so we will want to make sure that you have sufficient Drupal knowledge and hear more about your specific goals before enabling this permission. </p>
    <p>{$admin_access}</p>
    </div>
EOD;

    // Set the render array markup.
    variable_set("stanford_jumpstart_help_pages_features",
      array(
        "content" =>
        array(
          "#markup" => $eod
        )
      )
    );

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'token',
      'stanford_jumpstart',
    );
  }


}
