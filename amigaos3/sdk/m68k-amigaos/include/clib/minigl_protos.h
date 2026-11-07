#ifndef CLIB_MINIGL_PROTOS_H
#define CLIB_MINIGL_PROTOS_H

#include <exec/types.h>
#include <libraries/minigl.h>
#include <libraries/minigl_dispatch.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL MiniGLOpen(void);
void MiniGLClose(void);

#ifdef __cplusplus
}
#endif

#endif
