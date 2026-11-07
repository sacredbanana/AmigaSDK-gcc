# SDL2_net CMake configuration file, sdl2 shared libraries for MorphOS
#
# libSDL2_net.a is the glue library opening sdl2_net.library (constructor). Targets
# with the upstream names:
#   SDL2_net::SDL2_net   libSDL2_net.a glue + sdl2_net.library
# SDL2_net::SDL2_net-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL2_net PROPERTIES
    URL "https://github.com/libsdl-org/SDL_net/"
    DESCRIPTION "SDL_net is a cross-platform networking library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL2::SDL2)
    find_dependency(SDL2 2.0.0 CONFIG)
endif()

# lib/cmake/SDL2_net -> prefix (GG:usr/local)
get_filename_component(_SDL2_net_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL2_net_FOUND TRUE)

if(EXISTS "${_SDL2_net_prefix}/lib/libSDL2_net.a")
    if(NOT TARGET SDL2_net::SDL2_net)
        add_library(SDL2_net::SDL2_net STATIC IMPORTED)
        set_target_properties(SDL2_net::SDL2_net PROPERTIES
            IMPORTED_LOCATION "${_SDL2_net_prefix}/lib/libSDL2_net.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL2_net_prefix}/include/SDL2"
            INTERFACE_LINK_LIBRARIES "SDL2::SDL2"
            COMPATIBLE_INTERFACE_BOOL "SDL2_SHARED"
            INTERFACE_SDL2_SHARED "ON"
        )
    endif()
    set(SDL2_net_SDL2_net_FOUND TRUE)
else()
    set(SDL2_net_SDL2_net_FOUND FALSE)
    set(SDL2_net_FOUND FALSE)
    set(SDL2_net_NOT_FOUND_MESSAGE "libSDL2_net.a not found in ${_SDL2_net_prefix}/lib")
endif()

set(SDL2_net_SDL2_net-static_FOUND FALSE)

foreach(_SDL2_net_comp IN LISTS SDL2_net_FIND_COMPONENTS)
    if(NOT SDL2_net_${_SDL2_net_comp}_FOUND AND SDL2_net_FIND_REQUIRED_${_SDL2_net_comp})
        set(SDL2_net_FOUND FALSE)
        set(SDL2_net_NOT_FOUND_MESSAGE "SDL2_net component ${_SDL2_net_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL2_net_comp)
unset(_SDL2_net_prefix)
