# SDL2_mixer CMake configuration file, sdl2 shared libraries for MorphOS
#
# libSDL2_mixer.a is the glue library opening sdl2_mixer.library (constructor). Targets
# with the upstream names:
#   SDL2_mixer::SDL2_mixer   libSDL2_mixer.a glue + sdl2_mixer.library
# SDL2_mixer::SDL2_mixer-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL2_mixer PROPERTIES
    URL "https://github.com/libsdl-org/SDL_mixer/"
    DESCRIPTION "SDL_mixer is an audio mixer library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL2::SDL2)
    find_dependency(SDL2 2.0.0 CONFIG)
endif()

# lib/cmake/SDL2_mixer -> prefix (GG:usr/local)
get_filename_component(_SDL2_mixer_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL2_mixer_FOUND TRUE)

if(EXISTS "${_SDL2_mixer_prefix}/lib/libSDL2_mixer.a")
    if(NOT TARGET SDL2_mixer::SDL2_mixer)
        add_library(SDL2_mixer::SDL2_mixer STATIC IMPORTED)
        set_target_properties(SDL2_mixer::SDL2_mixer PROPERTIES
            IMPORTED_LOCATION "${_SDL2_mixer_prefix}/lib/libSDL2_mixer.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL2_mixer_prefix}/include/SDL2"
            INTERFACE_LINK_LIBRARIES "SDL2::SDL2"
            COMPATIBLE_INTERFACE_BOOL "SDL2_SHARED"
            INTERFACE_SDL2_SHARED "ON"
        )
    endif()
    set(SDL2_mixer_SDL2_mixer_FOUND TRUE)
else()
    set(SDL2_mixer_SDL2_mixer_FOUND FALSE)
    set(SDL2_mixer_FOUND FALSE)
    set(SDL2_mixer_NOT_FOUND_MESSAGE "libSDL2_mixer.a not found in ${_SDL2_mixer_prefix}/lib")
endif()

set(SDL2_mixer_SDL2_mixer-static_FOUND FALSE)

foreach(_SDL2_mixer_comp IN LISTS SDL2_mixer_FIND_COMPONENTS)
    if(NOT SDL2_mixer_${_SDL2_mixer_comp}_FOUND AND SDL2_mixer_FIND_REQUIRED_${_SDL2_mixer_comp})
        set(SDL2_mixer_FOUND FALSE)
        set(SDL2_mixer_NOT_FOUND_MESSAGE "SDL2_mixer component ${_SDL2_mixer_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL2_mixer_comp)
unset(_SDL2_mixer_prefix)
