# SDL3_ttf CMake configuration file, sdl3 shared libraries for MorphOS
#
# libSDL3_ttf.a is the glue library opening sdl3_ttf.library (constructor). Targets
# with the upstream names:
#   SDL3_ttf::SDL3_ttf          the library (here SDL3_ttf::SDL3_ttf-shared)
#   SDL3_ttf::SDL3_ttf-shared   libSDL3_ttf.a glue + sdl3_ttf.library
# SDL3_ttf::SDL3_ttf-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL3_ttf PROPERTIES
    URL "https://github.com/libsdl-org/SDL_ttf/"
    DESCRIPTION "SDL_ttf is a TrueType font rendering library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL3::SDL3-shared)
    find_dependency(SDL3 3.4.0 CONFIG COMPONENTS SDL3-shared)
endif()

# lib/cmake/SDL3_ttf -> prefix (GG:usr/local)
get_filename_component(_SDL3_ttf_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL3_ttf_FOUND TRUE)

if(EXISTS "${_SDL3_ttf_prefix}/lib/libSDL3_ttf.a")
    if(NOT TARGET SDL3_ttf::SDL3_ttf-shared)
        add_library(SDL3_ttf::SDL3_ttf-shared STATIC IMPORTED)
        set_target_properties(SDL3_ttf::SDL3_ttf-shared PROPERTIES
            IMPORTED_LOCATION "${_SDL3_ttf_prefix}/lib/libSDL3_ttf.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL3_ttf_prefix}/include"
            INTERFACE_LINK_LIBRARIES "SDL3::SDL3-shared"
            COMPATIBLE_INTERFACE_BOOL "SDL3_SHARED"
            INTERFACE_SDL3_SHARED "ON"
        )
    endif()
    set(SDL3_ttf_SDL3_ttf-shared_FOUND TRUE)
else()
    set(SDL3_ttf_SDL3_ttf-shared_FOUND FALSE)
    set(SDL3_ttf_FOUND FALSE)
    set(SDL3_ttf_NOT_FOUND_MESSAGE "libSDL3_ttf.a not found in ${_SDL3_ttf_prefix}/lib")
endif()

set(SDL3_ttf_SDL3_ttf-static_FOUND FALSE)

if(SDL3_ttf_SDL3_ttf-shared_FOUND AND NOT TARGET SDL3_ttf::SDL3_ttf)
    add_library(SDL3_ttf::SDL3_ttf INTERFACE IMPORTED)
    set_target_properties(SDL3_ttf::SDL3_ttf PROPERTIES
        INTERFACE_LINK_LIBRARIES "SDL3_ttf::SDL3_ttf-shared"
    )
endif()

foreach(_SDL3_ttf_comp IN LISTS SDL3_ttf_FIND_COMPONENTS)
    if(NOT SDL3_ttf_${_SDL3_ttf_comp}_FOUND AND SDL3_ttf_FIND_REQUIRED_${_SDL3_ttf_comp})
        set(SDL3_ttf_FOUND FALSE)
        set(SDL3_ttf_NOT_FOUND_MESSAGE "SDL3_ttf component ${_SDL3_ttf_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL3_ttf_comp)
unset(_SDL3_ttf_prefix)
