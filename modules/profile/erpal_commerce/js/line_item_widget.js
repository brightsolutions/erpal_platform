(function($) {

  Drupal.behaviors.lineItemWidget = {
    attach: function (context, settings) {
      if (typeof settings.ReferencesDialog !== 'undefined') {
        $.each(settings.ReferencesDialog.fields, function (key, widget_settings) {

          // Field for which will be added this functionality.
          var fieldClass = 'field-name-field-payment-modality';
          hideAddlink(fieldClass);

          // Remove value from form.
          $('.' + fieldClass + ' .' + key + ' span.delete-dialog', context).click(function (e) {
            var key_el = $('.' + fieldClass + ' #' + key);
                key_el.val('');
                key_el.change();
            $('.' + key).parent().closest('tr').css({ display: "none" });

          });

          // On change value change dialog links.
          $('.' + fieldClass + ' #' + key, context).change(function (e) {
            var value = $(this).val();
            var first = value.lastIndexOf("(");
            var last = value.lastIndexOf(")");
            var id = value.slice(first + 1, last);

            if (parseInt(id)) {
              var addlink = $('.' + fieldClass + ' .' + key + ' a.add-dialog');
              addlink
                .attr("href", settings.basePath + "erpal/payment-modality/" + id + "/edit")
                .text(value)
                .addClass('edit-dialog')
                .removeClass('add-dialog');
                
              var editlink = $('.' + fieldClass + ' .' + key + ' a.edit-dialog');
              editlink.text(value);
            }
            hideAddlink(fieldClass);
          });

          // Hide all add links and only show first.
          function hideAddlink (fieldClass) {
            $('.' + fieldClass).each(function(index) {
              var flag = false;
              $('a.add-dialog', $(this)).each(function () {
                if (flag === false) {
                  flag = true;
                  $(this).parent().closest('tr').show();
                }
                else {
                  $(this).parent().closest('tr').hide();
                }
              });
            });
          }
        });
      }
    }
  };

})(jQuery);
