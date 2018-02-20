<?php
/**
 * Expose http header changes as context reactions.
 */
class context_reaction_http_header extends context_reaction {

  function options_form($context) {
    $values = $this->fetch_from_context($context);
    
    $items['http_header'] = array(
      '#title' => t('HTTP Headers'),
      '#tree'  => 'tree',
    );
    // Retrieve hooked module data
    $items_from_hook = module_invoke_all('context_http_header_def');
    
    // Get set values from the context for these hooks  
    foreach ($items_from_hook as $header => $item) {
      $items_from_hook[$header]['#default_value'] = $values['http_header'][$header];
    }
    
    $items['http_header'] = array_merge($items['http_header'], $items_from_hook);
    
    return $items;
  }
  
  /**
   * Public method that is called from hooks or other integration points.
   */
  function execute() {
    $contexts = $this->get_contexts();
    
    foreach ($contexts as $context) {
      $http_header_items = $context->reactions['http_header']['http_header'];
      $header_builds = module_invoke_all('context_http_header_build', $http_header_items);
            
      // Query the headers and from context and inserts it into the conditioned pages
      
      $headers = _context_http_header_header_map($header_builds);

      // add headers to the page
      foreach ($headers as $key => $value) {
        drupal_add_http_header($key, $value);
      }
    }
  }
}