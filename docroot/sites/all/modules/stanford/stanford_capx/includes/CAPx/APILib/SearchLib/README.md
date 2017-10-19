# SearchLib

The SearchLib library supports results for an autocomplete search box and
a full keyword search. Search is performed by keyword and is typically used
with searching for profiles by name.

EXAMPLES:

    $client = new HTTPClient();
    $autocomplete = $client->api('search')->autocomplete($string);

    $client = new HTTPClient();
    $autocomplete = $client->api('search')->keyword($string);
