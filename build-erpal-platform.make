api = 2
core = 7.x
; Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make
; Download the install profile and recursively build all its dependencies:
projects[erpal_platform][version] = 3.x-dev