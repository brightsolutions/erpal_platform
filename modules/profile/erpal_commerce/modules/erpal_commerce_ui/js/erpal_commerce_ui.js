(function($) {

  // Just change default tab if bulk operation was submited.
  Drupal.behaviors.erpalChangeTab = {
    attach: function (context, settings) {

      if ($(".view-erpal-invoice-line-items").length &&
        $(".view-erpal-invoice-line-items .vbo-views-form").length == 0){
        var tabsID = Drupal.settings.panelsTabs.tabsID;

        for (var key in Drupal.settings.panelsTabs.tabsID) {
          var count = $('#' + tabsID[key] + '>ul li', context).size();
          $('#' + tabsID[key], context).tabs({
            selected: count - 1
          });
        }
      }
    }
  };

})(jQuery);
