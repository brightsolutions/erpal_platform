<?php
/**
 * @file
 * erpal_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_commerce_default_rules_configuration() {
  $items = array();
  $items['rules_auto_creating_invoice_line_item_an_advance'] = entity_import('rules_config', '{ "rules_auto_creating_invoice_line_item_an_advance" : {
      "LABEL" : "Auto creating invoice line item an advance",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "erpal_commerce", "entity" ],
      "ON" : { "commerce_line_item_insert" : [], "commerce_line_item_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "product" : "product" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item" ],
            "field" : "field_payment_modality"
          }
        }
      ],
      "DO" : [
        { "erpal_commerce_create_invoice_line_item" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');
  return $items;
}
