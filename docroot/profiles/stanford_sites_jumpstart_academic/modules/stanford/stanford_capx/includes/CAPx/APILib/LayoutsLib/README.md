# LayoutsLib

The Layouts Library is used for communicating with the CAP API's layouts
endpoint. The layouts endpoint returns a json array of information about
the fields used with a particular profile type. A few helpful wrapper methods
are included.

Examples:

    $client = new HTTPClient();
    $staff = $client->api('layouts')->staff();
    $faculty = $client->api('layouts')->faculty();
    $other = $client->api('layouts')->getType('other');
