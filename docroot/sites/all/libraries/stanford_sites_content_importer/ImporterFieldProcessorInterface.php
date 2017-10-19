<?php

/**
 * @file
 */

interface ImporterFieldProcessorInterface {

    public function process(&$entity, $entity_type, $field_name);

}
