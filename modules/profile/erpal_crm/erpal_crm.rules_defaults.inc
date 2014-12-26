<?php
/**
 * @file
 * erpal_crm.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_crm_default_rules_configuration() {
  $items = array();
  $items['rules_change_sales_process_status_prospect'] = entity_import('rules_config',
    '{ "rules_change_sales_process_status_prospect" : {
      "LABEL" : "Change sales process status to prospect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal CRM" ],
      "REQUIRES" : [ "rules", "rules_conditional", "entity" ],
      "ON" : { "commerce_order_insert" : [], "commerce_order_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-order" ],
            "type" : "commerce_order",
            "bundle" : { "value" : { "quote" : "quote" } }
          }
        },
        { "NOT data_is_empty" : { "data" : [ "commerce-order:field-sales-process" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "crm_core_activity",
              "id" : [ "commerce-order:field-sales-process:activity-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "sales_process" : "Sales process" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "entity_has_field" : { "entity" : [ "sales-process" ], "field" : "field_activity_status" } },
              "DO" : [
                { "data_set" : { "data" : [ "sales-process:field-activity-status" ], "value" : "3" } }
              ]
            }
          ]
        }
      ]
    }
  }');

  $items['rules_change_sales_process_status_to_win'] = entity_import('rules_config',
    '{ "rules_change_sales_process_status_to_win" : {
      "LABEL" : "Change sales process status to win",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal CRM" ],
      "REQUIRES" : [ "rules", "rules_conditional", "entity" ],
      "ON" : { "commerce_order_insert" : [], "commerce_order_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-order" ],
            "type" : "commerce_order",
            "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
          }
        },
        { "NOT data_is_empty" : { "data" : [ "commerce-order:field-quote" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_order",
              "id" : [ "commerce-order:field-quote:order-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "quote_entity" : "Quote entity" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "entity_has_field" : { "entity" : [ "quote-entity" ], "field" : "field_sales_process" } },
              "DO" : [
                { "entity_fetch" : {
                    "USING" : {
                      "type" : "crm_core_activity",
                      "id" : [ "quote-entity:field-sales-process:activity-id" ]
                    },
                    "PROVIDE" : { "entity_fetched" : { "sales_process" : "Sales process" } }
                  }
                },
                { "CONDITIONAL" : [
                    {
                      "IF" : { "entity_has_field" : { "entity" : [ "sales-process" ], "field" : "field_activity_status" } },
                      "DO" : [
                        { "data_set" : { "data" : [ "sales-process:field-activity-status" ], "value" : "4" } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        }
      ]
    }
  }');

  $items['rules_automatically_create_new_crm_contact_when_user_registered'] = entity_import('rules_config', '{ "rules_automatically_create_new_crm_contact_when_user_registered" : {
      "LABEL" : "Automatically create new CRM contact when user has been registered",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "Erpal CRM" ],
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "crm_core_contact" },
            "PROVIDE" : { "entity_created" : { "crm_contact" : "CRM Contact" } }
          }
        },
        { "data_set" : { "data" : [ "crm-contact:type" ], "value" : "individual" } },
        { "data_set" : { "data" : [ "crm-contact:uid" ], "value" : [ "account:uid" ] } },
        { "CONDITIONAL" : [
            {
              "IF" : { "entity_has_field" : { "entity" : [ "crm-contact" ], "field" : "contact_name" } },
              "DO" : [
                { "data_set" : {
                    "data" : [ "crm-contact:contact-name:given" ],
                    "value" : [ "account:name" ]
                  }
                }
              ]
            }
          ]
        },
        { "entity_save" : { "data" : [ "crm-contact" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "account:field-user-crm-contact" ],
            "value" : [ "crm-contact" ]
          }
        }
      ]
    }
  }');

  return $items;
}
