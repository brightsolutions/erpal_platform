<?php

/**
 * @file
 * Views handler for pdf link.
 */

/**
 * Simple entity generic views handler for a invoice PDF link.
 */
class erpal_commerce_commerce_billy_pdf_field_handler extends commerce_billy_pdf_field_handler{

  function render_link($order, $values) {
    if (erpal_commerce_ui_invoice_view_access($order)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "invoice-pdf/$order->order_id";
      $text = !empty($this->options['text']) ? $this->options['text'] : $order->order_number;
      return $text;
    }
  }
}
