/*
 * Phase K: compatibility header for original MiniGL/demos sources that
 * `#include <extra.h>` under `#ifdef __VBCC__` -- a header from the
 * original author's own environment, never bundled with the public
 * MiniGL distribution and not found anywhere in this project's tree.
 * Not MiniGL's own API.
 *
 * `warp.c` needs nothing real from it at all (builds clean against a
 * completely empty stub) -- its own `#include <extra.h>` is apparently
 * unused/defensive.
 *
 * `varray.c` is the one real case: it calls `glDrawElements` twice in an
 * if/else, toggled by its own `No_Pipeline` flag -- one branch uses
 * plain GL constants (`GL_TRIANGLES`/`GL_UNSIGNED_BYTE`), the OTHER uses
 * raw Warp3D primitive-type constants (`W3D_PRIMITIVE_TRIANGLES`/
 * `W3D_INDEX_UBYTE`) for the exact same logical draw call -- a
 * deliberate A/B test comparing the abstracted GL path against a
 * "closer to the metal" Warp3D path, not a typo (both branches draw the
 * same indexed cube).
 *
 * CHECKED against the real Warp3D SDK (`D:\v3d_driver\W3D Sourcecode\
 * trunk\Warp3D\include\warp3d\warp3d.h`, available on this system --
 * not guessed): `W3D_PRIMITIVE_TRIANGLES = 0`, `W3D_INDEX_UBYTE = 0`.
 * These do NOT equal this port's own `GL_TRIANGLES`/`GL_UNSIGNED_BYTE`
 * values (a large, differently-ordered enum, Phase G's own rewrite of
 * MiniGL's original header). The original's own `GLDrawElements`
 * (`MiniGL/src/vertexelements.c`) never actually forwards its `mode`
 * parameter to Warp3D at all -- internally it always hardcodes its OWN
 * `W3D_PRIMITIVE_TRIANGLES`/`_TRIFAN`/`_TRISTRIP` calls based on its own
 * dispatch logic, so the ORIGINAL was lenient about whatever `mode`
 * value it received from the caller. This port's own `GLDrawElements`
 * (`gl/src/vertexelements.c`) is NOT lenient -- it explicitly checks
 * `mode == GL_TRIANGLES` (or `_STRIP`/`_FAN`) and flags
 * `GL_INVALID_OPERATION` otherwise, so passing the real, unaliased
 * `W3D_PRIMITIVE_TRIANGLES` (0) would silently drop the draw here,
 * unlike in the original.
 *
 * Aliasing these to their GL equivalents (rather than defining the real
 * Warp3D values) is therefore the objectively correct fix for THIS
 * port specifically, verified against both the real SDK and this port's
 * own actual dispatch code -- not merely a safe-guess fallback.
 */

#ifndef W3D_PRIMITIVE_TRIANGLES
#define W3D_PRIMITIVE_TRIANGLES GL_TRIANGLES
#endif

#ifndef W3D_INDEX_UBYTE
#define W3D_INDEX_UBYTE GL_UNSIGNED_BYTE
#endif
