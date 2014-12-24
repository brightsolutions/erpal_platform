<?php

/**
 * @file
 * Theme implementation for the ERPAL entity actions.
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="node-action-links">
<a class="trigger"><?php t('Show actions'); ?></a>
<?php print drupal_render($actions); ?>
</div>
