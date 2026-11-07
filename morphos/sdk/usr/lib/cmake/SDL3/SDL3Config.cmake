# SDL3 CMake configuration file, sdl3 shared libraries for MorphOS
#
# libSDL3.a is the glue library opening sdl3.library (constructor). The
# targets have the upstream names:
#   SDL3::SDL3          the SDL3 library (here SDL3::SDL3-shared)
#   SDL3::SDL3-shared   libSDL3.a glue + sdl3.library
#   SDL3::Headers       include directory only
#   SDL3::SDL3_test     libSDL3_test.a (SDL test framework)
# SDL3::SDL3-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL3 PROPERTIES
    URL "https://www.libsdl.org/"
    DESCRIPTION "low level access to audio, keyboard, mouse, joystick, and graphics hardware"
)

cmake_minimum_required(VERSION 3.0...3.28)

# lib/cmake/SDL3 -> prefix (GG:usr/local)
get_filename_component(_sdl3_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL3_FOUND TRUE)
set(SDL3_INCLUDE_DIRS "${_sdl3_prefix}/include")
set(SDL3_LIBRARIES SDL3::SDL3)

if(NOT TARGET SDL3::Headers)
    add_library(SDL3::Headers INTERFACE IMPORTED)
    set_target_properties(SDL3::Headers PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${_sdl3_prefix}/include"
        INTERFACE_COMPILE_OPTIONS "-noixemul"
    )
endif()
set(SDL3_Headers_FOUND TRUE)

if(EXISTS "${_sdl3_prefix}/lib/libSDL3.a")
    if(NOT TARGET SDL3::SDL3-shared)
        add_library(SDL3::SDL3-shared STATIC IMPORTED)
        set_target_properties(SDL3::SDL3-shared PROPERTIES
            IMPORTED_LOCATION "${_sdl3_prefix}/lib/libSDL3.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_LINK_LIBRARIES "SDL3::Headers;GL;m"
            INTERFACE_LINK_OPTIONS "-noixemul"
            COMPATIBLE_INTERFACE_BOOL "SDL3_SHARED"
            INTERFACE_SDL3_SHARED "ON"
        )
    endif()
    set(SDL3_SDL3-shared_FOUND TRUE)
else()
    set(SDL3_SDL3-shared_FOUND FALSE)
endif()

set(SDL3_SDL3-static_FOUND FALSE)

if(EXISTS "${_sdl3_prefix}/lib/libSDL3_test.a")
    if(NOT TARGET SDL3::SDL3_test)
        add_library(SDL3::SDL3_test STATIC IMPORTED)
        set_target_properties(SDL3::SDL3_test PROPERTIES
            IMPORTED_LOCATION "${_sdl3_prefix}/lib/libSDL3_test.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_LINK_LIBRARIES "SDL3::SDL3-shared"
        )
    endif()
    set(SDL3_SDL3_test_FOUND TRUE)
else()
    set(SDL3_SDL3_test_FOUND FALSE)
endif()

# SDL3::SDL3 = the shared library, as upstream when both exist
if(SDL3_SDL3-shared_FOUND)
    if(NOT TARGET SDL3::SDL3)
        add_library(SDL3::SDL3 INTERFACE IMPORTED)
        set_target_properties(SDL3::SDL3 PROPERTIES
            INTERFACE_LINK_LIBRARIES "SDL3::SDL3-shared"
        )
    endif()
    set(SDL3_SDL3_FOUND TRUE)
else()
    set(SDL3_SDL3_FOUND FALSE)
endif()

# find_package(SDL3 REQUIRED COMPONENTS ...): components not listed are optional
if(NOT SDL3_FIND_COMPONENTS)
    set(SDL3_FIND_COMPONENTS SDL3)
    set(SDL3_FIND_REQUIRED_SDL3 TRUE)
endif()
foreach(_sdl3_comp IN LISTS SDL3_FIND_COMPONENTS)
    if(NOT SDL3_${_sdl3_comp}_FOUND AND SDL3_FIND_REQUIRED_${_sdl3_comp})
        set(SDL3_FOUND FALSE)
        set(SDL3_NOT_FOUND_MESSAGE "SDL3 component ${_sdl3_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_sdl3_comp)
unset(_sdl3_prefix)
