# SDL2 CMake configuration file, sdl2 shared libraries for MorphOS
#
# libSDL2.a is the glue library opening sdl2.library (constructor). The
# targets have the upstream names:
#   SDL2::SDL2       libSDL2.a glue + sdl2.library
#   SDL2::SDL2main   empty (no SDL_main on MorphOS), for the projects linking it
#   SDL2::SDL2test   libSDL2test.a (SDL test framework)
# SDL2::SDL2-static is not available: the SDK only has the shared library.
# The SDL2_* variables of the upstream sdl2-config.cmake are set too.

include(FeatureSummary)
set_package_properties(SDL2 PROPERTIES
    URL "https://www.libsdl.org/"
    DESCRIPTION "low level access to audio, keyboard, mouse, joystick, and graphics hardware"
)

cmake_minimum_required(VERSION 3.0...3.28)

# lib/cmake/SDL2 -> prefix (GG:usr/local)
get_filename_component(_sdl2_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL2_FOUND TRUE)
set(SDL2_PREFIX "${_sdl2_prefix}")
set(SDL2_EXEC_PREFIX "${_sdl2_prefix}")
set(SDL2_INCLUDE_DIR "${_sdl2_prefix}/include/SDL2")
set(SDL2_INCLUDE_DIRS "${_sdl2_prefix}/include;${_sdl2_prefix}/include/SDL2")
set(SDL2_BINDIR "${_sdl2_prefix}/bin")
set(SDL2_LIBDIR "${_sdl2_prefix}/lib")

if(EXISTS "${_sdl2_prefix}/lib/libSDL2.a")
    if(NOT TARGET SDL2::SDL2)
        add_library(SDL2::SDL2 STATIC IMPORTED)
        set_target_properties(SDL2::SDL2 PROPERTIES
            IMPORTED_LOCATION "${_sdl2_prefix}/lib/libSDL2.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_sdl2_prefix}/include;${_sdl2_prefix}/include/SDL2"
            INTERFACE_COMPILE_OPTIONS "-noixemul"
            INTERFACE_LINK_LIBRARIES "GL;m"
            INTERFACE_LINK_OPTIONS "-noixemul"
            COMPATIBLE_INTERFACE_BOOL "SDL2_SHARED"
            INTERFACE_SDL2_SHARED "ON"
        )
    endif()
    set(SDL2_SDL2_FOUND TRUE)
else()
    set(SDL2_SDL2_FOUND FALSE)
    set(SDL2_FOUND FALSE)
    set(SDL2_NOT_FOUND_MESSAGE "libSDL2.a not found in ${_sdl2_prefix}/lib")
endif()

set(SDL2_SDL2-static_FOUND FALSE)

if(NOT TARGET SDL2::SDL2main)
    add_library(SDL2::SDL2main INTERFACE IMPORTED)
endif()
set(SDL2_SDL2main_FOUND TRUE)

if(EXISTS "${_sdl2_prefix}/lib/libSDL2test.a")
    if(NOT TARGET SDL2::SDL2test)
        add_library(SDL2::SDL2test STATIC IMPORTED)
        set_target_properties(SDL2::SDL2test PROPERTIES
            IMPORTED_LOCATION "${_sdl2_prefix}/lib/libSDL2test.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_LINK_LIBRARIES "SDL2::SDL2"
        )
    endif()
    set(SDL2_SDL2test_FOUND TRUE)
else()
    set(SDL2_SDL2test_FOUND FALSE)
endif()

# upstream sdl2-config.cmake variables
set(SDL2_LIBRARY SDL2::SDL2)
set(SDL2MAIN_LIBRARY SDL2::SDL2main)
set(SDL2TEST_LIBRARY SDL2::SDL2test)
set(SDL2_LIBRARIES SDL2::SDL2main SDL2::SDL2)
set(SDL2_STATIC_LIBRARIES SDL2::SDL2main SDL2::SDL2)
set(SDL2_STATIC_LINK_LIBRARIES "")

foreach(_sdl2_comp IN LISTS SDL2_FIND_COMPONENTS)
    if(NOT SDL2_${_sdl2_comp}_FOUND AND SDL2_FIND_REQUIRED_${_sdl2_comp})
        set(SDL2_FOUND FALSE)
        set(SDL2_NOT_FOUND_MESSAGE "SDL2 component ${_sdl2_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_sdl2_comp)
unset(_sdl2_prefix)
