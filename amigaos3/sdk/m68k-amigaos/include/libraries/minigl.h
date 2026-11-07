#ifndef LIBRARIES_MINIGL_H
#define LIBRARIES_MINIGL_H
#include <exec/libraries.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define MINIGLNAME "minigl.library"

/*
 * The minimum library version a client will accept, passed to OpenLibrary.
 *
 * 28 (2026-10-01, on the user's instruction). This was 14 and deliberately a
 * FLOOR rather than the current version, so that a client demanded only what it
 * actually used and one needing newer entry points raised it on its own compile
 * line. That reasoning held while the only difference between library versions
 * was which entry points existed.
 *
 * It stopped holding when the GL tokens took OpenGL's own values: a pre-28
 * library and a client built after that change disagree about what 230 token
 * names MEAN, which no count of entry points describes. The dispatch table's
 * abiVersion already refuses that pairing, but only after the library is open
 * and the table fetched; this refuses it at OpenLibrary, before anything else
 * can go wrong.
 *
 * The cost is the one the old comment named: every client demands this number
 * even if it only ever calls what 14 had.
 *
 * 28 -> 29 (2026-10-05) IS A RELEASE BOUNDARY and not a routine bump. It moves
 * together with MINIGL_DISPATCH_ABI_VERSION 4 -> 5, which minigl_open.c tests
 * for EQUALITY, so a client built against this header requires a 29.0 library
 * and a client built against the old one is refused by it.
 *
 * FIVE CLIENTS, and WHICH BUILD of each matters, because every one of these
 * games also has a static build that compiles MiniGLV3D in and is unaffected:
 *   glquakelib  build_glquake_gcc_minigllib_wsl.sh
 *   Quake 2     D:\tmp\build_quake2_minigllib.sh -> ref_gl_shared_vNNN.dll
 *               (its own tree's two scripts are the STATIC ones)
 *   Heretic II  build_h2_wsl_showcase.sh lib -> ref_minigl.dll
 *               (its DEFAULT target builds the static ref_gl.dll)
 *   ioq3        build_ioq3_minigllib_wsl.sh
 *               (build_ioq3_gccfresh_wsl_showcase.sh is the STATIC one)
 *   glxsglut    build_glxsglut_wsl.sh
 * All five must be rebuilt and shipped alongside the new library; neither half
 * works with the other's old half.
 *
 * Heretic II and glxsglut also pin MINIGL_VERSION on their own compile lines,
 * overriding the default below, so those two numbers move with this one.
 *
 * Still OVERRIDABLE -- a client with a reason can define it on its compile line.
 */
#ifndef MINIGL_VERSION
#define MINIGL_VERSION 29
#endif

/*
 * Inside the extern "C" above because a C++ client resolves this against the
 * C-compiled minigl_base.o in the import lib; mangled, it would not link.
 * MiniGLOpen and MiniGLClose are NOT declared here -- <clib/minigl_protos.h>
 * already does, and <proto/minigl.h> is the umbrella that pulls in both.
 */
extern struct Library *MiniGLBase;

#ifdef __cplusplus
}
#endif

#endif
