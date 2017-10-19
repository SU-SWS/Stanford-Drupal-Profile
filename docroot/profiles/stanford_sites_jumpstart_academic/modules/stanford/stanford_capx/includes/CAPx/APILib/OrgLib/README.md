# OrgLib

The OrgLib class is used for communicating with the CAP API's org endpoint.
This class can return information about the organization itself or the
profiles that are attached to it. To see the org codes and heirarchy please
refer to the Org Chart: http://web.stanford.edu/dept/pres-provost/budget/org/orgchart/

EXAMPLE:

    $client = new HTTPClient();
    $orgs = array('AA00', 'AABB');
    $orgsInfo = $client->api('org')->get($orgs);

    $client = new HTTPClient();
    $org = 'AA00';
    $orgInfo = $client->api('org')->getOrg($org);

    $client = new HTTPClient();
    $org = 'AA00'
    $profiles = $client->api('org')->getProfiles($org);
