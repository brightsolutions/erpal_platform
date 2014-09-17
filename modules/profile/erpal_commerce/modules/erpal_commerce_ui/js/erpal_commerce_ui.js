(function($) {

  Drupal.behaviors.erpalChangeTab = {
    attach: function (context, settings) {
      var tabsID = Drupal.settings.panelsTabs.tabsID;

      for (var key in tabsID) {
        $('#' + tabsID[key] + '>ul li a', context).click(function (e) {
          var href = $(this).attr("href");

          $.cookie("panel_tab", href.substr(1));
        });
      }
    }
  };

})(jQuery);
