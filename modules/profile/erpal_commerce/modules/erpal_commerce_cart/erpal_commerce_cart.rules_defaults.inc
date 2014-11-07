<?php

/**
 * @file
 * Provides default rules for ERPAL Commerce Cart module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_commerce_cart_default_rules_configuration() {
  $items = array();
  $items['rules_create_invoice_after_payment'] = entity_import('rules_config', '{ "rules_create_invoice_after_payment" : {
    "LABEL" : "Create new invoice when order has been payed",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "ERPAL Commerce Cart" ],
    "REQUIRES" : [ "rules", "commerce_billy", "commerce_payment" ],
    "ON" : { "commerce_payment_order_paid_in_full" : [] },
    "IF" : [
      { "entity_is_of_bundle" : {
          "entity" : [ "commerce-order" ],
          "type" : "commerce_order",
          "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
        }
      }
    ],
    "DO" : [
      { "entity_create" : {
          "USING" : {
            "type" : "commerce_order",
            "param_status" : "invoiced",
            "param_type" : "invoice",
            "param_owner" : [ "commerce-order:owner" ],
            "param_commerce_order_total" : [ "commerce-order:commerce-order-total" ]
          },
          "PROVIDE" : { "entity_created" : { "invoice" : "Invoice" } }
        }
      },
      { "data_set" : {
          "data" : [ "invoice:field-invoice-order" ],
          "value" : [ "commerce-order" ]
        }
      },
      { "data_set" : {
          "data" : [ "invoice:field-vendor" ],
          "value" : [ "commerce-order:field-vendor" ]
        }
      },
      { "data_set" : {
          "data" : [ "invoice:field-vendor-address" ],
          "value" : [ "commerce-order:field-vendor-address" ]
        }
      },
      { "data_set" : {
          "data" : [ "invoice:field-customer" ],
          "value" : [ "commerce-order:field-customer" ]
        }
      },
      { "data_set" : {
          "data" : [ "invoice:commerce-customer-billing" ],
          "value" : [ "commerce-order:commerce-customer-billing" ]
        }
      },
      { "data_set" : {
          "data" : [ "invoice:field-commerce-billy-i-date" ],
          "value" : [ "site:current-date" ]
        }
      },
      { "entity_save" : { "data" : [ "invoice" ], "immediate" : 1 } },
      { "commerce_billy_invoice_nr" : { "order" : [ "invoice" ] } },
      { "LOOP" : {
          "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
          "ITEM" : { "line_item" : "Current line item" },
          "DO" : [
            { "entity_create" : {
                "USING" : {
                  "type" : "commerce_line_item",
                  "param_order" : [ "invoice" ],
                  "param_type" : "invoice",
                  "param_line_item_label" : [ "line-item:line-item-label" ],
                  "param_quantity" : [ "line-item:quantity" ],
                  "param_commerce_unit_price" : [ "line-item:commerce-unit-price" ],
                  "param_commerce_total" : [ "line-item:commerce-total" ]
                },
                "PROVIDE" : { "entity_created" : { "created_line_item" : "Created line item" } }
              }
            },
            { "data_set" : {
                "data" : [ "created-line-item:field-line-item-delivery-date" ],
                "value" : [ "site:current-date" ]
              }
            },
            { "data_set" : {
                "data" : [ "created-line-item:field-line-item-order" ],
                "value" : [ "commerce-order" ]
              }
            },
            { "entity_save" : { "data" : [ "created-line-item" ], "immediate" : 1 } },
            { "list_add" : {
                "list" : [ "invoice:commerce-line-items" ],
                "item" : [ "created-line-item" ],
                "unique" : 1
              }
            }
          ]
        }
      }
    ]
  }
}');

  $items['rules_assign_vendor_to_commerce_order_when_cart_has_been_created'] = entity_import('rules_config', '{ "rules_assign_vendor_to_commerce_order_when_cart_has_been_created" : {
    "LABEL" : "Add vendor to cart\u0027s order when cart has been created",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "ERPAL Commerce Cart" ],
    "REQUIRES" : [ "rules", "commerce_cart" ],
    "ON" : { "commerce_cart_product_add" : [] },
    "IF" : [
      { "entity_is_of_bundle" : {
          "entity" : [ "commerce-order" ],
          "type" : "commerce_order",
          "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
        }
      },
      { "data_is_empty" : { "data" : [ "commerce-order:field-vendor" ] } }
    ],
    "DO" : [
      { "data_set" : {
          "data" : [ "commerce-order:field-vendor" ],
          "value" : [ "site:vendor" ]
        }
      },
      { "data_set" : {
          "data" : [ "commerce-order:field-vendor-address" ],
          "value" : [ "site:vendor-address" ]
        }
      }
    ]
  }
}');

  $items['rules_add_customer_address_to_order_and_quote_on_its_creation'] = entity_import('rules_config', '{ "rules_add_customer_address_to_order_and_quote_on_its_creation" : {
    "LABEL" : "Add customer address to the order and quote on its creation during checkout",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "ERPAL Commerce Cart" ],
    "REQUIRES" : [ "rules", "rules_conditional", "erpal_commerce_cart" ],
    "ON" : { "erpal_commerce_cart_commerce_customer_insert" : [] },
    "IF" : [
      { "entity_is_of_bundle" : {
          "entity" : [ "commerce-order" ],
          "type" : "commerce_order",
          "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
        }
      }
    ],
    "DO" : [
      { "data_set" : {
          "data" : [ "commerce-order:commerce-customer-billing" ],
          "value" : [ "commerce-customer-profile" ]
        }
      },
      { "CONDITIONAL" : [
          {
            "IF" : { "NOT data_is_empty" : { "data" : [ "commerce-order:field-quote" ] } },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : {
                    "type" : "commerce_order",
                    "id" : [ "commerce-order:field-quote:order-id" ]
                  },
                  "PROVIDE" : { "entity_fetched" : { "quote" : "Quote" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "entity_is_of_bundle" : {
                        "entity" : [ "quote" ],
                        "type" : "commerce_order",
                        "bundle" : { "value" : { "quote" : "quote" } }
                      }
                    },
                    "DO" : [
                      { "data_set" : {
                          "data" : [ "quote:commerce-customer-billing" ],
                          "value" : [ "commerce-customer-profile" ]
                        }
                      }
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

  $items['rules_add_customer_to_carts_order_when_cart_has_been_created'] = entity_import('rules_config', '{ "rules_add_customer_to_carts_order_when_cart_has_been_created" : {
    "LABEL" : "Add customer to cart\u0027s order when cart has been created",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "ERPAL Commerce Cart" ],
    "REQUIRES" : [ "rules", "rules_conditional", "commerce_cart" ],
    "ON" : { "commerce_cart_product_add" : [] },
    "IF" : [
      { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_customer" } },
      { "data_is_empty" : { "data" : [ "commerce-order:field-customer" ] } }
    ],
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "user", "id" : [ "site:current-user:uid" ] },
          "PROVIDE" : { "entity_fetched" : { "current_user" : "Current user" } }
        }
      },
      { "CONDITIONAL" : [
          {
            "IF" : { "entity_has_field" : { "entity" : [ "current-user" ], "field" : "field_user_crm_contact" } },
            "DO" : [
              { "data_set" : {
                  "data" : [ "commerce-order:field-customer" ],
                  "value" : [ "current-user:field-user-crm-contact" ]
                }
              }
            ]
          }
        ]
      }
    ]
  }
}');

  $items['rules_add_customer_address_to_the_crm_contact_on_its_creation'] = entity_import('rules_config', '{ "rules_add_customer_address_to_the_crm_contact_on_its_creation" : {
    "LABEL" : "Add customer address to the CRM contact on its creation during checkout",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "ERPAL Commerce Cart" ],
    "REQUIRES" : [ "rules", "rules_conditional", "erpal_commerce_cart" ],
    "ON" : { "erpal_commerce_cart_commerce_customer_insert" : [] },
    "IF" : [
      { "entity_is_of_bundle" : {
          "entity" : [ "commerce-order" ],
          "type" : "commerce_order",
          "bundle" : { "value" : { "commerce_order" : "commerce_order" } }
        }
      },
      { "NOT data_is_empty" : { "data" : [ "commerce-order:field-customer" ] } }
    ],
    "DO" : [
      { "entity_fetch" : {
          "USING" : {
            "type" : "crm_core_contact",
            "id" : [ "commerce-order:field-customer:contact-id" ]
          },
          "PROVIDE" : { "entity_fetched" : { "crm_contact" : "CRM Contact" } }
        }
      },
      { "CONDITIONAL" : [
          {
            "IF" : { "entity_has_field" : { "entity" : [ "crm-contact" ], "field" : "field_customer_profiles" } },
            "DO" : [
              { "list_add" : {
                  "list" : [ "crm-contact:field-customer-profiles" ],
                  "item" : [ "commerce-customer-profile" ],
                  "unique" : 1
                }
              }
            ]
          }
        ]
      }
    ]
  }
}');

  return $items;
}
