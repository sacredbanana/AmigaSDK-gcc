#ifndef GL_H
#define GL_H

#include <clib/tinygl_protos.h>

#include <stddef.h>
#include <inttypes.h>

struct Library;

#ifdef __cplusplus
extern "C" {
#endif

/* Constants to pass to TGLSetContextVersion(). Note that passing a higher
 * version than the running tinygl.library supports will cause the value to
 * be ignored, so you have to check the version of tinygl.library before
 * deciding on which context version to use.
 *
 * libgl.a contains a function, TGLSetAutomaticContextVersion(), which will
 * choose the newest context version supported by both the SDK and the running
 * tinygl.library. Using this function is the preferred way to handle TinyGL
 * context versions.
 *
 * Calling TGLSetContextVersion() or TGLSetAutomaticContextVersion() is only
 * required if you open tinygl.library manually. When tinygl.library is being
 * automatically opened, then TGLSetAutomaticContextVersion() is also called
 * automatically. */
#define TGL_CONTEXT_VERSION_53_0                                          0
#define TGL_CONTEXT_VERSION_53_1                                          1
#define TGL_CONTEXT_VERSION_53_9                                          2
#define TGL_CONTEXT_VERSION_53_11                                         3

#define TGL_CORRECT_NORMALS_HINT                                          0x1105
#define TGL_LOWQUALITY_TEXTURES_HINT                                      0x1104


#include <tgl/types.h>

#define GL_RGB565                                                       0x8D62

/* Some defines that some software depends on */
#define GL_VERSION_1_0    1
#define GL_VERSION_1_1    1
#define GL_VERSION_1_2    1
#define GL_VERSION_1_2_1  1
#define GL_VERSION_1_3    1
#define GL_VERSION_1_4    1
#define GL_VERSION_1_5    1
#define GL_VERSION_2_0    1
#define GL_VERSION_2_1    1

/* functions */

unsigned int TGLGetMaximumContextVersion(struct Library *TinyGLBase);
void TGLSetAutomaticContextVersion(struct Library *TinyGLBase, void *__tglContext);


#ifndef _NO_PPCINLINE

/*
 Real interface functions.
*/

extern GLContext *__tglContext;


#define glAInitializeContextWindowed(w) GLAInitializeContextWindowed(__tglContext, w)
#define glADestroyContextWindowed() GLADestroyContextWindowed(__tglContext)
#define glAInitializeContextScreen(w) GLAInitializeContextScreen(__tglContext, w)
#define glADestroyContextScreen() GLADestroyContextScreen(__tglContext)
#define glAInitializeContextBitMap(w) GLAInitializeContextBitMap(__tglContext, w)
#define glADestroyContextBitMap() GLADestroyContextBitMap(__tglContext)
#define glASwapBuffers() GLASwapBuffers(__tglContext)
#define tglEnableNewExtensions(contextversion) TGLEnableNewExtensions(__tglContext, contextversion)
#define tglGetProcAddress(name) TGLGetProcAddress(&__tglContext, name)

#endif /* _NO_PPCINLINE */

#ifdef __cplusplus
}
#endif

#include <tgl/glstd.h>

#endif /* GL_H */

