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
  return $items;
}