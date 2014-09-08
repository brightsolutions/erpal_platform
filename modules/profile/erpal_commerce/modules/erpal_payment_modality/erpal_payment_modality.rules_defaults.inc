<?php
/**
 * @file
 * erpal_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_payment_modality_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_create_invoice_line_item'] = entity_import('rules_config', '{ "rules_link_condition_create_invoice_line_item" : {
      "LABEL" : "Rules link: Create invoice line item condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Payment Modality" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "erpal_payment_modality" : { "label" : "erpal_payment_modality", "type" : "erpal_payment_modality" } },
      "AND" : [
        { "entity_has_field" : { "entity" : [ "erpal-payment-modality" ], "field" : "field_due_with" } },
        { "text_matches" : {
            "text" : [ "erpal-payment-modality:field-due-with" ],
            "match" : "delivery"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_create_invoice_line_item'] = entity_import('rules_config', '{ "rules_link_set_create_invoice_line_item" : {
      "LABEL" : "Rules link: Create invoice line item rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Payment Modality" ],
      "REQUIRES" : [ "erpal_commerce" ],
      "USES VARIABLES" : { "erpal_payment_modality" : { "type" : "erpal_payment_modality", "label" : "erpal_payment_modality" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "erpal_payment_modality_create_invoice_line_item_delivery" : { "erpal_payment_modality" : [ "erpal_payment_modality" ] } }
            ],
            "LABEL" : "Create invoice line item"
          }
        }
      ]
    }
  }');
  $items['rules_auto_creating_payment_modality_on_line_item_creation'] = entity_import('rules_config', '{ "rules_auto_creating_payment_modality_on_line_item_creation" : {
      "LABEL" : "Auto creating payment modality on line item creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ERPAL Payment Modality" ],
      "REQUIRES" : [ "rules", "erpal_payment_modality", "entity" ],
      "ON" : { "commerce_line_item_presave" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "product" : "product" } }
          }
        }
      ],
      "DO" : [
        { "erpal_payment_modality_auto_create" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');
  return $items;
}
