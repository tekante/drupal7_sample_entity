; Build file for the house.gov platform. THis includes
; all core and modules patches as well.
;
;     $ drush make house.make [directory]

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.0

projects[views][subdir] = contrib
projects[views][version] = 3.0-alpha1

projects[ctools][subdir] = contrib
projects[ctools][type] = module
projects[ctools][version] = 1.0-alpha2

projects[entity][subdir] = contrib
projects[entity][version] = 1.0-beta8
; patch for revisions
projects[entity][patch][] = http://drupal.org/files/issues/996696-entity-api-revision-support.patch

projects[devel][subdir] = contrib
projects[devel][version] = 1.0
