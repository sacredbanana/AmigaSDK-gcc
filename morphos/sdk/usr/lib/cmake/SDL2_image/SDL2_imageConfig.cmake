# SDL2_image CMake configuration file, sdl2 shared libraries for MorphOS
#
# libSDL2_image.a is the glue library opening sdl2_image.library (constructor). Targets
# with the upstream names:
#   SDL2_image::SDL2_image   libSDL2_image.a glue + sdl2_image.library
# SDL2_image::SDL2_image-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL2_image PROPERTIES
    URL "https://github.com/libsdl-org/SDL_image/"
    DESCRIPTION "SDL_image is an image file loading library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL2::SDL2)
    find_dependency(SDL2 2.0.0 CONFIG)
endif()

# lib/cmake/SDL2_image -> prefix (GG:usr/local)
get_filename_component(_SDL2_image_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL2_image_FOUND TRUE)

if(EXISTS "${_SDL2_image_prefix}/lib/libSDL2_image.a")
    if(NOT TARGET SDL2_image::SDL2_image)
        add_library(SDL2_image::SDL2_image STATIC IMPORTED)
        set_target_properties(SDL2_image::SDL2_image PROPERTIES
            IMPORTED_LOCATION "${_SDL2_image_prefix}/lib/libSDL2_image.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL2_image_prefix}/include/SDL2"
            INTERFACE_LINK_LIBRARIES "SDL2::SDL2"
            COMPATIBLE_INTERFACE_BOOL "SDL2_SHARED"
            INTERFACE_SDL2_SHARED "ON"
        )
    endif()
    set(SDL2_image_SDL2_image_FOUND TRUE)
else()
    set(SDL2_image_SDL2_image_FOUND FALSE)
    set(SDL2_image_FOUND FALSE)
    set(SDL2_image_NOT_FOUND_MESSAGE "libSDL2_image.a not found in ${_SDL2_image_prefix}/lib")
endif()

set(SDL2_image_SDL2_image-static_FOUND FALSE)

foreach(_SDL2_image_comp IN LISTS SDL2_image_FIND_COMPONENTS)
    if(NOT SDL2_image_${_SDL2_image_comp}_FOUND AND SDL2_image_FIND_REQUIRED_${_SDL2_image_comp})
        set(SDL2_image_FOUND FALSE)
        set(SDL2_image_NOT_FOUND_MESSAGE "SDL2_image component ${_SDL2_image_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL2_image_comp)
unset(_SDL2_image_prefix)
