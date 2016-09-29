; ### Drupal.org release file. ###
core = 7.x
api = 2

; ### Contrib Modules ###
projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.2"

projects[admin_menu][version] = "3.0-rc5"
projects[admin_menu][subdir] = "contrib"

projects[charts][version] = "2.0-rc1"
projects[charts][subdir] = "contrib"

projects[cat][version] = "1.0-rc1"
projects[cat][subdir] = "contrib"

projects[commerce_billy][version] = "1.1"
projects[commerce_billy][subdir] = "contrib"
projects[commerce_billy][patch][] = "https://www.drupal.org/files/issues/fixed_issues_on_pdf_view_mode_showing-2212793-8.patch"
projects[commerce_billy][patch][] = "https://www.drupal.org/files/issues/commerce_billy-better-usability-for-deleting-invoiced-orders-2543560.patch"

projects[commerce_reports][version] = "4.0-beta2"
projects[commerce_reports][subdir] = "contrib"

projects[ctools][version] = "1.10"
projects[ctools][subdir] = "contrib"

projects[custom_order_number][version] = "1.0-alpha1"
projects[custom_order_number][subdir] = "contrib"

projects[date][version] = "2.8"
projects[date][subdir] = "contrib"
projects[date][patch][] = "https://www.drupal.org/files/issues/date-undefined_index_timezone_1392472-22.patch"

projects[email][version] = "1.3"
projects[email][subdir] = "contrib"

projects[entity][version] = "1.8"
projects[entity][subdir] = "contrib"

projects[entitycache][version] = "1.5"
projects[entitycache][subdir] = "contrib"

projects[entityreference][version] = "1.2"
projects[entityreference][subdir] = "contrib"

projects[entityreference_prepopulate][version] = "1.6"
projects[entityreference_prepopulate][subdir] = "contrib"

projects[field_collection][version] = "1.0-beta11"
projects[field_collection][subdir] = "contrib"

projects[field_extrawidgets][version] = "1.1"
projects[field_extrawidgets][subdir] = "contrib"

projects[field_group][version] = "1.5"
projects[field_group][subdir] = "contrib"

projects[inline_entity_form][version] = "1.8"
projects[inline_entity_form][subdir] = "contrib"

projects[libraries][version] = "2.3"
projects[libraries][subdir] = "contrib"

projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

projects[mvf][version] = "1.0-beta3"
projects[mvf][subdir] = "contrib"
projects[mvf][patch][] = "http://drupal.org/files/issues/mvf_save-settings-in-field-instance_2223983_3.patch"

projects[panels][version] = "3.7"
projects[panels][subdir] = "contrib"

projects[panels_everywhere][version] = "1.0-rc2"
projects[panels_everywhere][subdir] = "contrib"

projects[pm_existing_pages][version] = "1.4"
projects[pm_existing_pages][subdir] = "contrib"

projects[references_dialog][version] = "1.0-beta2"
projects[references_dialog][subdir] = "contrib"
projects[references_dialog][patch][] = "https://www.drupal.org/files/issues/references_dialog-add-bundle-to-entity-access_2308071_1.patch"

projects[relation][version] = "1.0"
projects[relation][subdir] = "contrib"

projects[relation_add][version] = "1.6"
projects[relation_add][subdir] = "contrib"

projects[relation_view_formatter][version] = "1.0-alpha1"
projects[relation_view_formatter][subdir] = "contrib"

projects[replicate][version] = "1.1"
projects[replicate][subdir] = "contrib"

projects[rules][version] = "2.9"
projects[rules][subdir] = "contrib"

projects[rules_link][version] = "1.1"
projects[rules_link][subdir] = "contrib"

projects[rules_conditional][version] = "1.0-beta2"
projects[rules_conditional][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][subdir] = "contrib"

projects[url][version] = "1.0"
projects[url][subdir] = "contrib"

projects[views][version] = "3.14"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_field_view][version] = "1.2"
projects[views_field_view][subdir] = "contrib"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"

projects[subpathauto][subdir] = "contrib"
projects[subpathauto][version] = "1.3"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha3"

projects[ds][subdir] = "contrib"
projects[ds][version] = "2.14"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0"

projects[fpa][subdir] = "contrib"
projects[fpa][version] = "2.6"

projects[viewfield][subdir] = "contrib"
projects[viewfield][version] = "2.0"

projects[entity_autocomplete][subdir] = "contrib"
projects[entity_autocomplete][version] = "1.0-beta4"
projects[entity_autocomplete][patch][] = "https://www.drupal.org/files/issues/entity_autocomplete-support-form-api-ajax-2604356-13.patch"

projects[homebox][subdir] = "contrib"
projects[homebox][version] = "2.0-rc3"

projects[path_breadcrumbs][subdir] = "contrib"
projects[path_breadcrumbs][version] = "3.3"

projects[commerce][subdir] = "contrib"
projects[commerce][version] = "1.13"
projects[commerce][patch][] = "https://drupal.org/files/issues/commerce-made-order_number-to-be-unique-only-for-commerce_order-type_2236731_5.patch"

projects[commerce_custom_product][subdir] = "contrib"
projects[commerce_custom_product][version] = "1.0-beta2"


; ### DEV VERSIONS of contrib modules ###
projects[timed_messages][subdir] = "contrib"
projects[timed_messages][download][type] = "git"
projects[timed_messages][download][url] = "http://git.drupal.org/project/timed_messages.git"
projects[timed_messages][download][tag] = "7.x-1.1"

projects[pathauto_entity][subdir] = "contrib"
projects[pathauto_entity][download][type] = "git"
projects[pathauto_entity][download][url] = "http://git.drupal.org/project/pathauto_entity.git"
projects[pathauto_entity][download][branch] = "7.x-1.x"
projects[pathauto_entity][download][revision] = "3422ef11300485a79a5af7711b3611cc7c93ce99"

projects[date_item][subdir] = "contrib"
projects[date_item][download][type] = "git"
projects[date_item][download][url] = "http://git.drupal.org/project/date_item.git"
projects[date_item][download][branch] = "7.x-3.x"
projects[date_item][download][revision] = "c8cf0e4978dee0c6a08a0700ca9d47a429374538"

projects[dfv][subdir] = "contrib"
projects[dfv][download][type] = "git"
projects[dfv][download][url] = "http://git.drupal.org/project/dfv.git"
projects[dfv][download][branch] = "7.x-1.x"
projects[dfv][download][revision] = "7fa6057506f50102d9e15fefe9ae392dbfa60ce7"

projects[units][subdir] = "contrib"
projects[units][download][type] = "git"
projects[units][download][url] = "http://git.drupal.org/project/units.git"
projects[units][download][branch] = "7.x-1.x"
projects[units][download][revision] = "36d838b85a71c4afb3419690482f4abe1d39764c"
projects[units][patch][] = "https://www.drupal.org/files/issues/erpal_platform-fixed-error-on-unit-add.patch"

projects[name][subdir] = "contrib"
projects[name][version] = "1.x-dev"
projects[name][download][type] = "git"
projects[name][download][url] = "http://git.drupal.org/project/name.git"
projects[name][download][revision] = "d614771dcaffa7be355b9cc03ed3cd9ecbe63536"

projects[panels_tabs][subdir] = "contrib"
projects[panels_tabs][download][type] = "git"
projects[panels_tabs][download][url] = "http://git.drupal.org/project/panels_tabs.git"
projects[panels_tabs][download][branch] = "7.x-2.x"
projects[panels_tabs][download][revision] = "2caec501daab91001712d153398df585ff6c238c"

projects[views_date_format_sql][subdir] = "contrib"
projects[views_date_format_sql][download][type] = "git"
projects[views_date_format_sql][download][url] = "http://git.drupal.org/project/views_date_format_sql.git"
projects[views_date_format_sql][download][branch] = "7.x-3.x"
projects[views_date_format_sql][download][revision] = "fe85b24eaa066833b0995fc3aa6870ffe85c8b7a"

projects[views_filter_args][subdir] = "contrib"
projects[views_filter_args][download][type] = "git"
projects[views_filter_args][download][url] = "http://git.drupal.org/project/views_filter_args.git"
projects[views_filter_args][download][branch] = "7.x-1.x"
projects[views_filter_args][download][revision] = "c5ca64de67406ef10aa4c060460e9875840006af"

projects[commerce_order_types][subdir] = "contrib"
projects[commerce_order_types][version] = "1.x-dev"
projects[commerce_order_types][download][type] = "git"
projects[commerce_order_types][download][url] = "http://git.drupal.org/project/commerce_order_types.git"
projects[commerce_order_types][download][revision] = "0879b45a6a31c7a5a5cb9ac5c61310843e3541b9"
projects[commerce_order_types][patch][] = "http://drupal.org/files/issues/1868540-refactoring_of_module_and_made_types_exportable-4.patch"

projects[relation_dialog][subdir] = "contrib"
projects[relation_dialog][version] = "1.x-dev"
projects[relation_dialog][download][type] = "git"
projects[relation_dialog][download][url] = "http://git.drupal.org/project/relation_dialog.git"
projects[relation_dialog][download][revision] = "fa981fe904a306bc65ec309fd7eef9dbf741a244"
projects[relation_dialog][patch][] = "https://www.drupal.org/files/issues/relation_dialog-add-entities-support_2309579_1.patch"

projects[commerce_line_item_widget][subdir] = "contrib"
projects[commerce_line_item_widget][download][type] = "git"
projects[commerce_line_item_widget][download][url] = "http://git.drupal.org/project/commerce_line_item_widget.git"
projects[commerce_line_item_widget][download][branch] = "7.x-1.x"

projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][download][type] = "git"
projects[logintoboggan][download][url] = "http://git.drupal.org/project/logintoboggan.git"
projects[logintoboggan][download][branch] = "7.x-1.x"

projects[crm_core][subdir] = "contrib"
projects[crm_core][download][type] = "git"
projects[crm_core][download][url] = "http://git.drupal.org/project/crm_core.git"
projects[crm_core][download][branch] = "7.x-1.x"


; ### ERPAL contributed modules ###
projects[erpal_core][subdir] = "erpal"
projects[erpal_core][download][type] = "git"
projects[erpal_core][download][url] = "http://git.drupal.org/project/erpal_core.git"
projects[erpal_core][download][branch] = "7.x-3.x"

projects[erpal_project][subdir] = "erpal"
projects[erpal_project][download][type] = "git"
projects[erpal_project][download][url] = "http://git.drupal.org/project/erpal_project.git"
projects[erpal_project][download][branch] = "7.x-3.x"

projects[erpal_invoice][subdir] = "erpal"
projects[erpal_invoice][download][type] = "git"
projects[erpal_invoice][download][url] = "http://git.drupal.org/project/erpal_invoice.git"
projects[erpal_invoice][download][branch] = "7.x-3.x"

projects[erpal_quote][subdir] = "erpal"
projects[erpal_quote][download][type] = "git"
projects[erpal_quote][download][url] = "http://git.drupal.org/project/erpal_quote.git"
projects[erpal_quote][download][branch] = "7.x-3.x"

projects[erpal_reports][subdir] = "erpal"
projects[erpal_reports][download][type] = "git"
projects[erpal_reports][download][url] = "http://git.drupal.org/project/erpal_reports.git"
projects[erpal_reports][download][branch] = "7.x-3.x"


; ### Erpal themes ###
projects[erpal_theme][type] = "theme"
projects[erpal_theme][download][type] = "git"
projects[erpal_theme][download][url] = "http://git.drupal.org/project/erpal_theme.git"
projects[erpal_theme][download][branch] = "7.x-3.x"

; ### Libraries ###
libraries[dompdf][download][type] = "file"
libraries[dompdf][download][url] = "https://github.com/dompdf/dompdf/releases/download/v0.6.2/dompdf-0.6.2.zip"

libraries[jquery][download][type] = "file"
libraries[jquery][download][url] = "http://code.jquery.com/jquery-1.11.1.min.js"

libraries[jquery-ui-multiselect-widget][download][type] = "file"
libraries[jquery-ui-multiselect-widget][download][url] = "https://github.com/ehynds/jquery-ui-multiselect-widget/archive/master.zip"

libraries[pause][download][type] = "file"
libraries[pause][download][url] = "https://github.com/tobia/Pause/archive/master.zip"

; ### Themes ###
projects[omega][type] = "theme"
projects[omega][version] = "4.4"

projects[phingdrushtask][subdir] = "contrib"
projects[phingdrushtask][version] = "1.3"
