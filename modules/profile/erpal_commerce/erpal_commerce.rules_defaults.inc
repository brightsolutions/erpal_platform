<?php

/**
 * @file
 * Provides default rules for ERPAL Commerce module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_commerce_default_rules_configuration() {
  $items = array();
  $items['rules_auto_creating_invoice_line_item_in_advance'] = entity_import('rules_config', '{ "rules_auto_creating_invoice_line_item_in_advance" : {
      "LABEL" : "Auto creating invoice line item in advance",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ERPAL Commerce" ],
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
        },
        { "NOT data_is" : {
            "data" : [ "commerce-line-item:field-line-item-billable" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "erpal_commerce_create_invoice_line_item" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');

  $items['rules_change_quote_status_to_accepted'] = entity_import('rules_config', '{ "rules_change_quote_status_to_accepted" : {
      "LABEL" : "Change Quote status to accepted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ERPAL Commerce" ],
      "REQUIRES" : [ "rules", "erpal_commerce", "entity" ],
      "ON" : { "commerce_order_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-order" ],
            "type" : "commerce_order",
            "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
          }
        }
      ],
      "DO" : [
        { "erpal_commerce_change_quote_to_accepted" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  return $items;
}


/**
 * Implements hook_default_rules_configuration().
 */
function erpal_commerce_default_rules_configuration_alter(&$configs) {
  $configs['rules_commerce_billy_set_to_invoiced'] = entity_import('rules_config', '{ "rules_commerce_billy_set_to_invoiced" : {
      "LABEL" : "Set order to invoiced",
      "PLUGIN" : "rule",
      "TAGS" : [ "Commerce Billy" ],
      "REQUIRES" : [ "rules", "commerce_order", "commerce_billy" ],
      "USES VARIABLES" : { "order" : { "label" : "Order", "type" : "commerce_order" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "order" ], "field" : "field_commerce_billy_i_date" } }
      ],
      "DO" : [
        { "commerce_order_update_state" : { "commerce_order" : [ "order" ], "order_state" : "invoiced" } },
        { "data_set" : { "data" : [ "order:field-commerce-billy-i-date" ], "value" : "now" } }
      ]
    }
  }');
}