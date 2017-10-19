# SchemaLib

The SchemaLib library is used to communicate with the CAP API's schemea
endpoint. The schema endpoint describes the XML schema for a profile.

EXAMPLES

    $client = new HTTPClient();
    $schema = $client->api('schema')->profile();

    $client = new HTTPClient();
    $schema = $client->api('schema')->get('profile');
