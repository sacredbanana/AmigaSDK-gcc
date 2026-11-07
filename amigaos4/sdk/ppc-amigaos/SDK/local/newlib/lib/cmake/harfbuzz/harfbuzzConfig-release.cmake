#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "harfbuzz::harfbuzz" for configuration "Release"
set_property(TARGET harfbuzz::harfbuzz APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(harfbuzz::harfbuzz PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libharfbuzz.a"
  )

list(APPEND _cmake_import_check_targets harfbuzz::harfbuzz )
list(APPEND _cmake_import_check_files_for_harfbuzz::harfbuzz "/SDK/local/newlib/lib/libharfbuzz.a" )

# Import target "harfbuzz::harfbuzz-subset" for configuration "Release"
set_property(TARGET harfbuzz::harfbuzz-subset APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(harfbuzz::harfbuzz-subset PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libharfbuzz-subset.a"
  )

list(APPEND _cmake_import_check_targets harfbuzz::harfbuzz-subset )
list(APPEND _cmake_import_check_files_for_harfbuzz::harfbuzz-subset "/SDK/local/newlib/lib/libharfbuzz-subset.a" )

# Import target "harfbuzz::harfbuzz-raster" for configuration "Release"
set_property(TARGET harfbuzz::harfbuzz-raster APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(harfbuzz::harfbuzz-raster PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libharfbuzz-raster.a"
  )

list(APPEND _cmake_import_check_targets harfbuzz::harfbuzz-raster )
list(APPEND _cmake_import_check_files_for_harfbuzz::harfbuzz-raster "/SDK/local/newlib/lib/libharfbuzz-raster.a" )

# Import target "harfbuzz::harfbuzz-vector" for configuration "Release"
set_property(TARGET harfbuzz::harfbuzz-vector APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(harfbuzz::harfbuzz-vector PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libharfbuzz-vector.a"
  )

list(APPEND _cmake_import_check_targets harfbuzz::harfbuzz-vector )
list(APPEND _cmake_import_check_files_for_harfbuzz::harfbuzz-vector "/SDK/local/newlib/lib/libharfbuzz-vector.a" )

# Import target "harfbuzz::harfbuzz-gpu" for configuration "Release"
set_property(TARGET harfbuzz::harfbuzz-gpu APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(harfbuzz::harfbuzz-gpu PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/SDK/local/newlib/lib/libharfbuzz-gpu.a"
  )

list(APPEND _cmake_import_check_targets harfbuzz::harfbuzz-gpu )
list(APPEND _cmake_import_check_files_for_harfbuzz::harfbuzz-gpu "/SDK/local/newlib/lib/libharfbuzz-gpu.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
