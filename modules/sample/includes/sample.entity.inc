<?php

/**
 * Extend the base Entity class provided by the Entity module to make form creation
 * convenient (by defining all properties for this entity) and to aid in theming by
 * adding each property to the content array
 */
class SampleEntity extends Entity {
  /**
   * put the content that should be present in the render array for this entity
   * into place, for this entity this is done by putting each data item listed in
   * the extra fields into place
   */
  public function buildContent($view_mode, $langcode = NULL) {
    $content = array();
    $bundle = 'sample';
    $display_settings = field_extra_fields_get_display($this->entityType, $bundle, $view_mode);
    foreach ($display_settings as $prop => $settings) {
      $content[$prop] = array(
        '#markup' => $this->$prop,
        '#type' => 'markup',
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }
    return entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
  }

  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    // stub out NULL properties to avoid property not defined errors
    foreach($this->entityInfo['schema_fields_sql']['base table'] as $prop) {
      if (!isset($this->$prop)) {
        $this->$prop = NULL;
      }
    }
  }
}
