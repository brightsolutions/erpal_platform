(function($) {

  // Just change default tab if bulk operation was submited.
  Drupal.behaviors.erpalChangeTab = {
    attach: function (context, settings) {
      if ($("#edit-field-customer").length > 0){
        var tabsID = Drupal.settings.panelsTabs.tabsID;

        for (var key in Drupal.settings.panelsTabs.tabsID) {
          $('#' + tabsID[key], context)
            .tabs({ selected: 5 });
        }
      }
    }
  };

})(jQuery);