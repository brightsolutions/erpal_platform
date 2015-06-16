(function($) {
  Drupal.behaviors.lineItemWidget = {
    attach: function (context, settings) {
      var data = settings.erpal_platform_core,
        url = data.bannerUrl,
        title = data.bannerTitle;

      $('<a class="beta-banner" title="' + title + '" href="' + url + '">' + title + '</a>')
        .prependTo('.erpalsitetemplate-pageheaderleft');
    }
  };
})(jQuery);
