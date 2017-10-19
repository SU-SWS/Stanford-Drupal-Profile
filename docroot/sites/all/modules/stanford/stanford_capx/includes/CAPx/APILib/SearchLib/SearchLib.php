<?php
/**
 * @file
 * The SearchLib library supports results for an autocomplete search box and
 * a full keyword search. Search is performed by keyword and is typically used
 * with searching for profiles by name.
 *
 * EXAMPLES:
 * $client = new HTTPClient();
 * $autocomplete = $client->api('search')->autocomplete($string);
 *
 * $client = new HTTPClient();
 * $autocomplete = $client->api('search')->keyword($string);
 */

namespace CAPx\APILib\SearchLib;
use CAPx\APILib\AbstractAPILib as APILib;

class SearchLib extends APILib {

  /**
   * Autocomplete request method.
   *
   * @param string $string
   *   A string of text to search the cap api profiles for.
   *
   * @return mixed
   *   Either an array of possible autocomplete suggestions or false if
   *   something went wrong.
   */
  public function autocomplete($string = '') {
    $endpoint = $this->getEndpoint() . "/cap/v1/search/autocomplete";
    $options = $this->getOptions();
    $options['query']['q'] = $string;

    return $this->makeRequest($endpoint, array(), $options);
  }


  /**
   * Keyword serach method.
   *
   * @param string $string
   *   A string of text to search the cap api profiles for.
   *
   * @return mixed
   *   Either an array of matches or false if something went wrong.
   */
  public function keyword($string = '') {
    $endpoint = $this->getEndpoint() . "/cap/v1/search/keyword";
    $options = $this->getOptions();
    $options['query']['q'] = $string;

    return $this->makeRequest($endpoint, array(), $options);
  }

}
