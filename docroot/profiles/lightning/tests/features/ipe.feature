Feature: In-Place Editor with FPP

  @api @javascript
  Scenario: Use the IPE to build landing page(s) with FPP.
    Given I am logged in as a user with the "administrator" role
      When I go to "/node/add/landing"
        Then I fill in "title" with "Test"
          And I press "Save as Draft"
          Then I should see the heading "Test"
          And I should see "Customize this page"
          And I should see "Change layout"
          And I should see "Moderate Landing Page"
          And I should see "Draft"
      When I follow "Customize this page"
        Then I maximize the browser window
      When I follow "Add new pane"
        Then I should see "Add content to"
      When I click "Media" in the "CTools modal" region
        Then I should see "Configure new Media"
          And I should see "Make this reusable"
          And I fill in "title" with "My FPP"
          And I wait for live preview to finish
        Then I should see "My FPP" in the "CTools modal" region
      When I press "Save" in the "CTools modal" region
        Then I should see "My FPP" in the "Content" region
          And I should see "Edit"
          And I should see "Style"
          And I should see "Delete"
      When I press "Save as custom"
        Then I should see "My FPP"
      When I follow "Moderate Landing Page"
        Then I should see "View published"
          And I should see "View draft"
          And I should see "Edit draft"
          And I should see "Moderate"
          And I should see "Customize display"
      When I follow "Edit draft"
        Then I should see "New content: Your draft will be placed in moderation."
      When I press "Publish"
        Then I should see "Landing Page Test has been updated."
          And I should not see "Customize this page"
          And I should not see "Change layout"
          And I should see "Published"
      When I follow "Moderate Landing Page"
        Then I should not see "View draft"
          And I should not see "Edit draft"
          And I should see "New draft"
          And I follow "New draft"
      When I press "Save as Draft"
        Then I should see "Landing Page Test has been updated."
          And I should see "Customize this page"
      When I follow "Customize this page"
        Then I should see "Edit"
          And I should see "Style"
          And I should see "Delete"
      When I follow "Edit"
        Then I should see "Configure My FPP" in the "CTools modal" region
          And I fill in "title" with "My Revision"
          And I wait for live preview to finish
        Then I should see "My Revision" in the "CTools modal" region
     When I press "Save" in the "CTools modal" region
       Then I should see "My Revision" in the "Content" region
         And I should not see "My FPP" in the "Content" region  
     When I press "panels-ipe-save"
       Then I should see "My Revision"
     When I follow "Moderate Landing Page"
       Then I follow "View published"
         And I should see "My FPP"
         And I should not see "My Revision"
     When I follow "Moderate Landing Page"
       Then I follow "View draft"
         And I should not see "My FPP"
         And I should see "My Revision"
