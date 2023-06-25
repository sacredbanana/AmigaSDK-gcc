#ifndef CAIROAMIGAOS_H_
#define CAIROAMIGAOS_H_

#if CAIRO_HAS_AMIGAOS_SURFACE

#include <proto/graphics.h>
#include <proto/exec.h>
#include <proto/Picasso96API.h>

CAIRO_BEGIN_DECLS

cairo_public cairo_surface_t *
cairo_amigaos_surface_create(struct BitMap *bitmap);

cairo_public cairo_surface_t *
cairo_amigaos_surface_create_for_window(struct Window *window);

CAIRO_END_DECLS

#else
# error Cairo was not compiled with support for the amigaos backend
#endif

#endif /*CAIROAMIGAOS_H_*/
