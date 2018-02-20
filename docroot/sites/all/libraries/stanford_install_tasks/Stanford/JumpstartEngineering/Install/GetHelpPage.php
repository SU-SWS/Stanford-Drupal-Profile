<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartEngineering\Install;
use \ITasks\AbstractInstallTask;

/**
 * Configure the Get Help page.
 */
class GetHelpPage extends AbstractInstallTask {

  /**
   * Set Content for the Get Help page.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $request_help_jse_url = 'https://stanforduniversity.qualtrics.com/SE/?SID=SV_1EK9guIGepRtvwh&source=soe&Name=[current-user:name]&Email=[current-user:mail]&URL=[site:url]';
    $gethelp = l('Request Assistance', $request_help_jse_url, array('attributes' => array('class' => array('btn', 'btn-request'), 'target' => 'blank')));

$eod = <<<EOD
    <div class="block-extrainfo block-need-assistance">
    <h2>Need assistance with your site?</h2>
    <p>Submit a help form to Stanford Web Services to request personal assistance with your site.</p>
    <p>{$gethelp}</p>
    </div>

    <h2>Jumpstart User Guide</h2>
    <p>Do you need help with Stanford Sites Jumpstart? Look no further! We have lots of helpful tips in our user guide. The following pages might get you started:</p>
    <ul>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/getting-started-your-new-site" target="_blank">Your new site</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/menus" target="_blank">Menus</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/pages" target="_blank">Pages</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/blocks" target="_blank">Blocks</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/content-editor" target="_blank">Content editor</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/multimedia" target="_blank">Multimedia</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/design" target="_blank">Design</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/users" target="_blank">Users</a></li>
      <li><a href="https://sites-jumpstart.stanford.edu/user-guide/premium-features" target="_blank">Premium Features</a> (including: news, events, profiles, publications, manage content, manage taxonomy, footer menu)</li>
    </ul>

    <h2>Drupal resources at Stanford</h2>
    <p>Stanford has a very active and engaged Drupal community, and many centrally offered and community created resources that might help you.</p>
    <ul>
      <li><a href="https://itservices.stanford.edu/service/techtraining/schedule" target="_blank">IT Services Technology Training</a><br />
      Check the upcoming courses schedule for Drupal-specific training courses offered to Stanford faculty and staff.  </li>
      <li><a href="http://itservices.stanford.edu/service/web/stanfordsites/userguide" target="_blank">Stanford Sites User Guide</a><br />
        Your site is hosted on the Stanford Sites platform.
      The Sites User Guide provides general information about using the service as well as how to videos for common Drupal tasks.</li>
      <li><a href="http://swsblog.stanford.edu" target="_blank">Stanford Web Services Blog</a><br />
        The Stanford Web Services team blogs about all things related to Stanford Sites, Drupal, design, site building, and many other topics. This is a great resource for SWS clients.</li>
      <li><a href="http://techcommons.stanford.edu/topics/drupal" target="_blank">Tech Commons</a><br />
        Tech Commons is a community-created resource for technical knowledge. There is a section for Drupal with many helpful tutorials, discussions, and information.</li>
      <li><a href="https://learndrupal.stanford.edu/" target="_blank">Learn Drupal</a><br />
        A clearinghouse for community voted best Drupal learning resources.
      </li>
      <li><a href="http://opensource.stanford.edu/moc" target="_blank">Mornings o' Code,  Drupallers Drop-in Help, Drupallers Co-Working Sessions</a><br />
      Stanford Drupallers (new and and experienced) meet regularly to help troubleshoot each others' problems. Check the schedule for upcoming co-working sessions</li>
    </ul>
    <h2>Connect with the Drupal Community</h2>
    <p>The main way the Stanford Drupal community communicates is through the Drupallers Mailing List. You can join this list to participate in the community discussion. Feel free to post questions to the list, or post responses to help others.</p>
    <ul>
      <li><a href="https://mailman.stanford.edu/mailman/listinfo/drupallers" target="_blank">Join the Drupallers Mailing List</a></li>
    </ul>

EOD;

    // Set the render array markup.
    variable_set("stanford_jumpstart_help_pages_help",
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
