# SDL3_image CMake configuration file, sdl3 shared libraries for MorphOS
#
# libSDL3_image.a is the glue library opening sdl3_image.library (constructor). Targets
# with the upstream names:
#   SDL3_image::SDL3_image          the library (here SDL3_image::SDL3_image-shared)
#   SDL3_image::SDL3_image-shared   libSDL3_image.a glue + sdl3_image.library
# SDL3_image::SDL3_image-static is not available: the SDK only has the shared library.

include(FeatureSummary)
set_package_properties(SDL3_image PROPERTIES
    URL "https://github.com/libsdl-org/SDL_image/"
    DESCRIPTION "SDL_image is an image file loading library"
)

cmake_minimum_required(VERSION 3.0...3.28)

include(CMakeFindDependencyMacro)
if(NOT TARGET SDL3::SDL3-shared)
    find_dependency(SDL3 3.4.0 CONFIG COMPONENTS SDL3-shared)
endif()

# lib/cmake/SDL3_image -> prefix (GG:usr/local)
get_filename_component(_SDL3_image_prefix "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

set(SDL3_image_FOUND TRUE)

if(EXISTS "${_SDL3_image_prefix}/lib/libSDL3_image.a")
    if(NOT TARGET SDL3_image::SDL3_image-shared)
        add_library(SDL3_image::SDL3_image-shared STATIC IMPORTED)
        set_target_properties(SDL3_image::SDL3_image-shared PROPERTIES
            IMPORTED_LOCATION "${_SDL3_image_prefix}/lib/libSDL3_image.a"
            IMPORTED_LINK_INTERFACE_LANGUAGES "C"
            INTERFACE_INCLUDE_DIRECTORIES "${_SDL3_image_prefix}/include"
            INTERFACE_LINK_LIBRARIES "SDL3::SDL3-shared"
            COMPATIBLE_INTERFACE_BOOL "SDL3_SHARED"
            INTERFACE_SDL3_SHARED "ON"
        )
    endif()
    set(SDL3_image_SDL3_image-shared_FOUND TRUE)
else()
    set(SDL3_image_SDL3_image-shared_FOUND FALSE)
    set(SDL3_image_FOUND FALSE)
    set(SDL3_image_NOT_FOUND_MESSAGE "libSDL3_image.a not found in ${_SDL3_image_prefix}/lib")
endif()

set(SDL3_image_SDL3_image-static_FOUND FALSE)

if(SDL3_image_SDL3_image-shared_FOUND AND NOT TARGET SDL3_image::SDL3_image)
    add_library(SDL3_image::SDL3_image INTERFACE IMPORTED)
    set_target_properties(SDL3_image::SDL3_image PROPERTIES
        INTERFACE_LINK_LIBRARIES "SDL3_image::SDL3_image-shared"
    )
endif()

foreach(_SDL3_image_comp IN LISTS SDL3_image_FIND_COMPONENTS)
    if(NOT SDL3_image_${_SDL3_image_comp}_FOUND AND SDL3_image_FIND_REQUIRED_${_SDL3_image_comp})
        set(SDL3_image_FOUND FALSE)
        set(SDL3_image_NOT_FOUND_MESSAGE "SDL3_image component ${_SDL3_image_comp} is not available on MorphOS")
    endif()
endforeach()

unset(_SDL3_image_comp)
unset(_SDL3_image_prefix)
