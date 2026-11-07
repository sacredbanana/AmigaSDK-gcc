#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libxmp::xmp_static" for configuration "Release"
set_property(TARGET libxmp::xmp_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libxmp::xmp_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libxmp.a"
  )

list(APPEND _cmake_import_check_targets libxmp::xmp_static )
list(APPEND _cmake_import_check_files_for_libxmp::xmp_static "/SDK/local/newlib/lib/libxmp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
