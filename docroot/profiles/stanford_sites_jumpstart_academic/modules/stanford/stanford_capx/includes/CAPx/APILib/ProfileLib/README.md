# ProfileLib

The ProfileLib library is used to search for and find profiles on a number of
parameters. This library is also used for fetching individual profile data.

    $client = new HTTPClient();
    $results = $client->api('profile')->search($type, $args, FALSE, TRUE);

    $client = new HTTPClient();
    $profile = $cleint->api('profile')->get(34234);
