#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libxmp::xmp_shared" for configuration "Release"
set_property(TARGET libxmp::xmp_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libxmp::xmp_shared PROPERTIES
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libxmp.so.4"
  IMPORTED_SONAME_RELEASE "libxmp.so.4"
  )

list(APPEND _cmake_import_check_targets libxmp::xmp_shared )
list(APPEND _cmake_import_check_files_for_libxmp::xmp_shared "/SDK/local/newlib/lib/libxmp.so.4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
