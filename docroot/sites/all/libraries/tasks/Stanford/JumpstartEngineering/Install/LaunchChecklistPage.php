<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartEngineering\Install;
/**
 *
 */
class LaunchChecklistPage extends \ITasks\AbstractInstallTask {

  /**
   * Set Content for the Add features page.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {


    $request_launch_jse_url = 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_01I4MJkFACIhhIN&source=soe&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]';
    $launchbutton = l('Request Site Launch', $request_launch_jse_url, array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));

$eod = <<<EOD
    <h2>Launch Checklist</h2>

    <table width="100%" border="0" cellspacing="0" cellpadding="0" style="border:none;">
      <tr>
        <td><h3>Content Cleanup</h3>
          <ul>
            <li>Have you renamed any starter pages that aren&rsquo;t relevant to your site?</li>
            <li>Has all placeholder text in starter pages been replaced?</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>Blocks</h3>
          <ul>
            <li>Have you hidden the Blocks that aren&rsquo;t relevant to your site?</li>
            <li>Do your homepage and footer Blocks have the correct content in them?</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>Images</h3>
          <ul>
            <li>Are all placeholder images relevant to your site or have they been replaced?</li>
            <li>Do all images have short descriptive alternate text?</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>Links</h3>
          <ul>
            <li>Are all &ldquo;Read More&rdquo; links and links within content correct?</li>
            <li>Are all of your menu links correct?</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>URL Redirects</h3>
          <ul>
            <li>If you have an existing website, it&rsquo;s likely that users have bookmarked specific pages. Inventory the most important pages from your old website; Stanford Web Services will build redirects, so that those old bookmarks will still work after launch. Here is an <a target="_blank" href="https://stanford.box.com/s/h85hy9rgqhfaks2no07m">Example Spreadsheet</a>.</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>Vanity URL</h3>
          <ul>
            <li>Do you already have a Vanity URL (e.g. https://<em>mysite</em>.stanford.edu)? Stanford Web Services will handle the switchover for you, just tell us what it is.</li>
          </ul>
        </td>
      </tr>
      <tr>
        <td><h3>Approval</h3>
          <ul>
            <li>Does your site need to be approved by anyone other than you?</li>
          </ul>
        </td>
      </tr>
    </table>

    <div class="block-extrainfo-full">
      <h2>Are you ready to launch your site?</h2>
      <p>Launching your site means:</p>
      <ul>
        <li>It will be assigned a Vanity URL (such as http://mysite.stanford.edu)</li>
        <li>It will be made available to search engines</li>
        <li>You can still request an additional consultation with Stanford Web Services for a content and design review</li>
      </ul>
      <p>Once you have gone through the launch checklist above, you can request to launch your site.</p>
      <p>Congratulations! This may sound scary, but you have a team behind you to make sure that launch goes as smoothly as possible.</p>
      <p>{$launchbutton}</p>
    </div>
EOD;

    // Set the render array markup.
    variable_set("stanford_jumpstart_help_pages_launch",
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
