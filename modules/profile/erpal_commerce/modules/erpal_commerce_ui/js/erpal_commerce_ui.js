(function($) {

  Drupal.behaviors.erpalChangeTab = {
    attach: function (context, settings) {

      // Add hash of tab to form action.
      $('.vbo-views-form').each(function() {
        var action = $('form', $(this)).attr('action');
        if(action.indexOf("#") == -1) {
          var hash = $(this).closest("div[id^='tabs']").attr('id');
          if (hash) {
            $('form', $(this)).attr('action', action + '#' + hash);
          }
        }
      });

      $('.view-filters').each(function() {
        var action = $('form', $(this)).attr('action');
        if(action.indexOf("#") == -1) {
          var hash = $(this).closest("div[id^='tabs']").attr('id');
          if (hash) {
            $('form', $(this)).attr('action', window.location.pathname + '#' + hash);
          }
        }
      });
    }
  };

})(jQuery);
