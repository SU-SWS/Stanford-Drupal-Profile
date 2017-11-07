<?php
/**
 * SAML 1.1 remote IdP metadata for SimpleSAMLphp.
 *
 * Remember to remove the IdPs you don't use from this file.
 *
 * See: https://simplesamlphp.org/docs/stable/simplesamlphp-reference-idp-remote
 */

/*
$metadata['theproviderid-of-the-idp'] = array(
	'SingleSignOnService'  => 'https://idp.example.org/shibboleth-idp/SSO',
	'certFingerprint'      => 'c7279a9f28f11380509e072441e3dc55fb9ab864',
);
*/

$metadata['https://idp.stanford.edu/'] = array (
  'entityid' => 'https://idp.stanford.edu/',
  'contacts' => 
  array (
  ),
  'metadata-set' => 'shib13-idp-remote',
  'SingleSignOnService' => 
  array (
    0 => 
    array (
      'Binding' => 'urn:mace:shibboleth:1.0:profiles:AuthnRequest',
      'Location' => 'https://idp.stanford.edu/idp/profile/Shibboleth/SSO',
    ),
    1 => 
    array (
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/POST/SSO',
    ),
    2 => 
    array (
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST-SimpleSign',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/POST-SimpleSign/SSO',
    ),
    3 => 
    array (
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
      'Location' => 'https://idp.stanford.edu/idp/profile/SAML2/Redirect/SSO',
    ),
  ),
  'ArtifactResolutionService' => 
  array (
  ),
  'keys' => 
  array (
    0 => 
    array (
      'encryption' => true,
      'signing' => true,
      'type' => 'X509Certificate',
      'X509Certificate' => '
MIIDnzCCAoegAwIBAgIJAJl9YtyaxKsZMA0GCSqGSIb3DQEBBQUAMGYxCzAJBgNV
BAYTAlVTMRMwEQYDVQQIDApDYWxpZm9ybmlhMREwDwYDVQQHDAhTdGFuZm9yZDEU
MBIGA1UECgwLSVQgU2VydmljZXMxGTAXBgNVBAMMEGlkcC5zdGFuZm9yZC5lZHUw
HhcNMTMwNDEwMTYzMTAwWhcNMzMwNDEwMTYzMTAwWjBmMQswCQYDVQQGEwJVUzET
MBEGA1UECAwKQ2FsaWZvcm5pYTERMA8GA1UEBwwIU3RhbmZvcmQxFDASBgNVBAoM
C0lUIFNlcnZpY2VzMRkwFwYDVQQDDBBpZHAuc3RhbmZvcmQuZWR1MIIBIjANBgkq
hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAm6466Bd6mDwNOR2qZZy1WRZdjyrG2/xW
amGEMekg38fyuoSCIiMcgeA9UIUbiRCpAN87yI9HPcgDEdrmCK3Ena3J2MdFZbRE
b6fdRt76K+0FSl/CnyW9xaIlAhldXKbsgUDei3Xf/9P8H9Dxkk+PWd9Ha1RZ9Viz
dOLe2S2iDKc1CJg2kdGQTuQu6mUEGrB9WJmrLHJS7GkGDqy96owFjRL/p0i9KBdR
kgWG+GFHWkxzeNQ99yrQra3+C9FQXa/xLCdOY+BGOsAG7ej4094NZXRNTyXui4jR
WCm2GVdIVl7YB9++XSntS7zQEJ9QBnC1D4bS0tljMfdOGAvdUuJY7QIDAQABo1Aw
TjAdBgNVHQ4EFgQUJk4zcQ4JupEcAp0gEkob4YRDkckwHwYDVR0jBBgwFoAUJk4z
cQ4JupEcAp0gEkob4YRDkckwDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOC
AQEAKvf9AO4+osJZOmkv6AVhNPm6JKoBSm9dr9NhwpSS5fpro6PrIjDZDLh/L5d/
+CQTDzuVsw3xwDtlm89lrzbqw5rSa2+ghJk79ijysSC0zOcD6ka9c17zauCNmFx9
lj9iddUw3aYHQcQRktWL8pvI2WCY6lTU+ouNM+owStya7umZ9rBdjg/fQerzaQxF
T0yV3tYEonL3hXMzSqZxWirwsyZ0TnhWJsgEnqqG9tCFAcFu2p+glwXn1WL2GCRv
BfuJMPzg7ZB419AEoeYnLktqAWiU+ISnVfbwFOJ+OM/O7VQOeHDm2AeYcwo12CAc
4GC9KWTs3QtS3GREPKYDlHRNxQ==
          ',
    ),
  ),
  'scope' => 
  array (
    0 => 'stanford.edu',
  ),
  'UIInfo' => 
  array (
    'DisplayName' => 
    array (
      'en' => 'Stanford University WebAuth',
    ),
    'Description' => 
    array (
    ),
    'InformationURL' => 
    array (
      'en' => 'http://shibboleth.stanford.edu/',
    ),
    'PrivacyStatementURL' => 
    array (
    ),
    'Logo' => 
    array (
      0 => 
      array (
        'url' => 'https://idp.stanford.edu/logo.png',
        'height' => 60,
        'width' => 80,
        'lang' => 'en',
      ),
    ),
  ),
  'name' => 
  array (
    'en' => 'Stanford University WebAuth',
  ),
);
