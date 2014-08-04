<?php
/**
 * @file
 * erpal_commerce_ui.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_commerce_ui_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_create_invoice'] = entity_import('rules_config', '{ "rules_link_condition_create_invoice" : {
      "LABEL" : "Rules link: Create invoice condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "commerce_order" } },
      "AND" : []
    }
  }');
  $items['rules_link_condition_create_order'] = entity_import('rules_config', '{ "rules_link_condition_create_order" : {
      "LABEL" : "Rules link: Create order condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "commerce_order" } },
      "AND" : []
    }
  }');
  $items['rules_link_set_create_invoice'] = entity_import('rules_config', '{ "rules_link_set_create_invoice" : {
      "LABEL" : "Rules link: Create invoice rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "erpal_commerce_ui" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "commerce_order" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "new_commerce_order" : { "new_commerce_order" : "New order" } },
            "IF" : [
              { "component_rules_link_condition_create_invoice" : { "commerce_order" : [ "commerce_order" ] } }
            ],
            "DO" : [
              { "erpal_commerce_ui_replicate_order" : {
                  "USING" : { "commerce_order" : [ "commerce_order" ] },
                  "PROVIDE" : { "new_commerce_order" : { "new_commerce_order" : "New order" } }
                }
              },
              { "redirect" : { "url" : "invoice\\/[new-commerce-order:value]\\/edit" } }
            ],
            "LABEL" : "Create invoice"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_create_order'] = entity_import('rules_config', '{ "rules_link_set_create_order" : {
      "LABEL" : "Rules link: Create order rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "erpal_commerce_ui" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "commerce_order" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "new_commerce_order" : { "new_commerce_order" : "New order" } },
            "IF" : [
              { "component_rules_link_condition_create_order" : { "commerce_order" : [ "commerce_order" ] } }
            ],
            "DO" : [
              { "erpal_commerce_ui_replicate_order" : {
                  "USING" : { "commerce_order" : [ "commerce_order" ] },
                  "PROVIDE" : { "new_commerce_order" : { "new_commerce_order" : "New order" } }
                }
              },
              { "redirect" : { "url" : "order\\/[new-commerce-order:value]\\/edit" } }
            ],
            "LABEL" : "Create order"
          }
        }
      ]
    }
  }');
  return $items;
}
