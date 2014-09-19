(function($) {

  Drupal.behaviors.erpalChangeTab = {
    attach: function (context, settings) {
      $('.vbo-views-form').each(function() {
        var action = $('form', $(this)).attr('action');
        if(action.indexOf("#") == -1) {
          var hash = $(this).closest("div[id^='tabs']").attr('id');
          if (hash) {
            $('form', $(this)).attr('action', action + '#' + hash);
          }
        }
      });
    }
  };

})(jQuery);
