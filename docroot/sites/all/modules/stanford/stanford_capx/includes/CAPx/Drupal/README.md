# Drupal CAP Library

This is a PHP library that handles data from the CAP API and turns it into useful information for Drupal. The concept of this library is to be able to map information from CAP Profile data directly into an existing entity type through the UI. Included in this library is a collection of PHP classes that work together to allow for multiple configurations and options.

## Documentation

* Importers are objects that define who/what gets imported and contain mappers. [Read More](Importer/README.md)
* Mappers are objects that define what CAP data goes into which entity's fields. Mappers contain processors to assist in this transaction. [Read More](Mapper/README.md)
* [Processors](Processors/README.md) are objects that turn CAP data into a format that Drupal can use. There are two types of Processors; [Property](PropertyProcessors/README.md) and [Field](FieldProcessors/README.md).
* Utility functions are common functions that are globally available. [Read More](Util/README.md)


## Requirements

* CAPx APILib PHP library for communicating with the CAP API.
* Guzzle PHP Library
* Drupal Entity Module
* Drupal Date Module
* PHP >= 5.2.3 probably with cURL

## Usage

Needs to be re-written when it really works.







