<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
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


$eod = <<<EOD
    <h2>Launch Checklist</h2>
    <table border="0" cellpadding="0" cellspacing="0" style="border:none;" width="100%">
      <tbody>
        <tr>
          <td>
            <h3>Content Cleanup</h3>
            <ul>
              <li>Have you renamed or removed any starter pages that aren&rsquo;t relevant to your site?</li>
              <li>Has all placeholder text in starter pages been replaced?</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Blocks</h3>
            <ul>
              <li>Have you hidden the Blocks that aren&rsquo;t relevant to your site?</li>
              <li>Do your homepage and footer Blocks have the correct content in them?</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Images</h3>
            <ul>
              <li>Are all placeholder images relevant to your site or have they been replaced?</li>
              <li>Do all images have short descriptive alternate text for accessibility?</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Links</h3>
            <ul>
              <li>Are all &ldquo;Read More&rdquo; text set as links and the links within content correct?</li>
              <li>Are all of your menu links correct?</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>URL Redirects</h3>
            <ul>
              <li>If you have an existing website, it&rsquo;s likely that users have bookmarked specific pages. Inventory the most important pages from your old website; Stanford Web Services will build redirects, so that those old bookmarks will still work after launch. Here is an <a href="https://stanford.box.com/s/h85hy9rgqhfaks2no07m" target="_blank">Example Spreadsheet</a>.</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Vanity URL</h3>
            <ul>
              <li>Do you already have a Vanity URL (e.g. https://<em>mysite</em>.stanford.edu)? Stanford Web Services will handle the switchover for you, just tell us what it is.</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Google Analytics</h3>
            <ul>
              <li>Do you have a existing Google Analytics account? Please provide us with the&nbsp;Web Property ID&nbsp;(e.g., UA-1234567-8). If not, Stanford Web Services can request one and set that up for you.</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Existing Website</h3>
            <ul style="letter-spacing: 0.16px; line-height: 22.4px;">
              <li>Do you have a existing website? If yes,&nbsp;consider what to do with the old site.</li>
              <li>Do you need to access the old site after launch?&nbsp;You might consider setting up a <a href="http://web.stanford.edu/dept/as/mais/applications/workgroup/">Workgroup</a> to control user access permissions, or looking into <a href="https://library.stanford.edu/projects/web-archiving/archivability">archiving the site within Stanford Libraries</a>.</li>
            </ul>
          </td>
        </tr>
        <tr>
          <td>
            <h3>Approval</h3>
            <ul>
              <li>Does your site need to be approved by anyone other than you before launching?</li>
            </ul>
          </td>
        </tr>
      </tbody>
    </table>
    <div class="block-extrainfo-full">
      <h2>Are you ready to launch your site?</h2>
      <p>Launching your site means:</p>
      <ul>
        <li>It will be assigned a Vanity URL (such as http://mysite.stanford.edu)</li>
        <li>It will be made available to search engines</li>
        <li>You can still request an additional consultation with Stanford Web Services for a content and design review</li>
      </ul>
      <p>Once you have gone through the launch checklist above, you can request to launch your site.&nbsp;Stanford Web Services requests at least two weeks&#39; advanced notice. Launches are scheduled Tuesdays through Thursdays. During peak periods, some dates may not be available; date flexibility is appreciated!</p>
      <p>Congratulations! This may sound scary, but you have a team behind you to make sure that launch goes as smoothly as possible.</p>
      <p><a class="btn btn-request" href="https://stanforduniversity.qualtrics.com/SE/?SID=SV_01I4MJkFACIhhIN" target="_blank">Request Site Launch</a></p>
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
