# SDL3_mixer CMake configuration file, sdl3 shared libraries for MorphOS
#
# libSDL3_mixer.a is the glue library opening sdl3_mixer.library (constructor). Targets
# with the upstream names:
#   SDL3_mixer::SDL3_mixer          the library (here SDL3_mixer::SDL3_mixer-shared)
#   SDL3_mixer::SDL3_mixer-shared   libSDL3_mixer.a glue + sdl3_mixer.library
# SDL3_mixer::SDL3_mixer-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL3_mixer PROPERTIES
    URL "https://github.com/libsdl-org/SDL_mixer/"
    DESCRIPTION "SDL_mixer is an audio mixer library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL3::SDL3-shared)
    find_dependency(SDL3 3.4.0 CONFIG COMPONENTS SDL3-shared)
endif()

# lib/cmake/SDL3_mixer -> prefix (GG:usr/local)
get_filename_component(_SDL3_mixer_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL3_mixer_FOUND TRUE)

if(EXISTS "${_SDL3_mixer_prefix}/lib/libSDL3_mixer.a")
    if(NOT TARGET SDL3_mixer::SDL3_mixer-shared)
        add_library(SDL3_mixer::SDL3_mixer-shared STATIC IMPORTED)
        set_target_properties(SDL3_mixer::SDL3_mixer-shared PROPERTIES
            IMPORTED_LOCATION "${_SDL3_mixer_prefix}/lib/libSDL3_mixer.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL3_mixer_prefix}/include"
            INTERFACE_LINK_LIBRARIES "SDL3::SDL3-shared"
            COMPATIBLE_INTERFACE_BOOL "SDL3_SHARED"
            INTERFACE_SDL3_SHARED "ON"
        )
    endif()
    set(SDL3_mixer_SDL3_mixer-shared_FOUND TRUE)
else()
    set(SDL3_mixer_SDL3_mixer-shared_FOUND FALSE)
    set(SDL3_mixer_FOUND FALSE)
    set(SDL3_mixer_NOT_FOUND_MESSAGE "libSDL3_mixer.a not found in ${_SDL3_mixer_prefix}/lib")
endif()

set(SDL3_mixer_SDL3_mixer-static_FOUND FALSE)

if(SDL3_mixer_SDL3_mixer-shared_FOUND AND NOT TARGET SDL3_mixer::SDL3_mixer)
    add_library(SDL3_mixer::SDL3_mixer INTERFACE IMPORTED)
    set_target_properties(SDL3_mixer::SDL3_mixer PROPERTIES
        INTERFACE_LINK_LIBRARIES "SDL3_mixer::SDL3_mixer-shared"
    )
endif()

foreach(_SDL3_mixer_comp IN LISTS SDL3_mixer_FIND_COMPONENTS)
    if(NOT SDL3_mixer_${_SDL3_mixer_comp}_FOUND AND SDL3_mixer_FIND_REQUIRED_${_SDL3_mixer_comp})
        set(SDL3_mixer_FOUND FALSE)
        set(SDL3_mixer_NOT_FOUND_MESSAGE "SDL3_mixer component ${_SDL3_mixer_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL3_mixer_comp)
unset(_SDL3_mixer_prefix)
