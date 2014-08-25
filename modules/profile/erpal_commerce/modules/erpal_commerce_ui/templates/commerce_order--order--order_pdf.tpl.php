<?php

/**
 * @file
 * Template for orders.
 */

?>

<div class="order">
  <div class="header">
    <img src="<?php print $content['order_logo']['#value']; ?>"/>
    <div class="order-header">
        <p><?php print render($content['order_header']); ?></p>
    </div>
  </div>

  <hr/>

  <div class="order-header-date"><?php print render($content['order_header_date']); ?></div>
  <div class="customer"><?php print render($content['commerce_customer_billing']); ?></div>
  <div class="order-number"><?php print render($content['order_number']); ?></div>
  <?php if (isset($content['order_quote_number'])) : ?>
    <div class="order-quote-number"><?php print render($content['order_quote_number']); ?></div>
  <?php endif; ?>
  <div class="line-items">
    <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
    <div class="order-total"><?php print render($content['commerce_order_total']); ?></div>
  </div>
  <div class="order-text"><?php print render($content['order_text']); ?></div>

  <div class="order-footer"><?php print render($content['order_footer']); ?></div>
</div>
