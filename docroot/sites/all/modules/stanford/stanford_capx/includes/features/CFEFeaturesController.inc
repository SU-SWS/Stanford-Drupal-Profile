<?php
/**
 * @file
 */

/**
 * Our class for the features controller. Thanks API!
 */
class CFEFeaturesController extends EntityDefaultFeaturesController {

  /**
   * Generates the result for hook_features_export_render().
   */
  function export_render($module, $data, $export = NULL) {
    $output = array();
    $output[] = '  $items = array();';
    foreach (entity_load_multiple_by_name($this->type, $data) as $name => $entity) {

      // We add addtional data to the top level of the entity when we don't
      // really need it for the export.
      if ($entity->type == "mapper") {
        foreach ($entity->settings as $key => $v) {
          unset($entity->{$key});
        }
      }

      $export  = "  \$items['$name'] = entity_import('{$this->type}', '";
      // Make sure to escape the characters \ and '.
      $export .= addcslashes(entity_export($this->type, $entity, '  '), '\\\'');
      $export .= "');";
      $output[] = $export;
    }
    $output[] = '  return $items;';
    $output = implode("\n", $output);

    $hook = isset($this->info['export']['default hook']) ? $this->info['export']['default hook'] : 'default_' . $this->type;
    return array($hook => $output);
  }

}
