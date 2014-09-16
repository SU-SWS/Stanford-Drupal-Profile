# Stanford Sites Jumpstart Plus
* **Author:** Shea McKinney <sheamck@stanford.edu>
* **Changed:** September 16, 2014


Install profile for Stanford Sites Jumpstart. This profile is a stand alone profile but is intended for use as a parent profile much like how themes can have a base theme and a child theme. This profile goes one further and allows sub profiles to have a sub profile of their own. So you can have something like:

Base Profile [this]:

— Red Profile

—— Blue Profile

——— Purple Profile

For this particular installation profile 'Stanford Sites Jumpstart' there is also a dependency on the Standard and Stanford Installation profiles. These profiles are included in the profile parent/child tree depicted above before the base profile. They are not listed as they have been hard coded into the installation profile and have special cases.

## Installation Logic

The idea behind this profile is to allow children profiles to add to, alter, and remove dependencies and installation tasks  then install all of them in order. This will allow you to use logic from a parent profile but make any necessary changes. The installation process has been altered slightly with this profile and the new order of operations are

1. **Choose Profile**
2. **Choose Language**
3. **Verify Requirements**   | Altered to verify all child/parent profiles.
4. **Install System** | Core.
5. **Install standard assets** | Standard profile dependant modules.
6. **Install common asses** | The entire install tree of declared dependency modules are installed here. This includes the Stanford profile modules, the base profile modules, all sub profile modules, and the profile's hook_install() themselves.
7. **Configuration Form** | Altered to allow all profiles to add/change this form
8. **Installation Tasks** | Install tasks are defined in each profile and will be executed in order from the top most parent installation profile to the bottom most child. Tasks can be altered/removed by children profiles.
9. **Finish** | Finished notification page.

## Profile

See [API.md](API.md) for more.

### Example Profiles

See [GITHUB](https://github.com/SU-SWS/stanford_sites_jumpstart_sub_example) for an example sub profile.

## Installing VIA Drush

When installing via drush you can use the following flags

    --full_name | The full name of the site owner user.
    --sunetid | The sunet id of the site owner user.

    eg: drush si stanford_sites_jumpstart --full_name="John Wayne" --sunetid="johnway" --strict=0
