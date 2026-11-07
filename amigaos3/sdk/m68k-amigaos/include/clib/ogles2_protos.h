#ifndef CLIB_OGLES2_PROTOS_H
#define CLIB_OGLES2_PROTOS_H
/*
 * Import-library functions that are not generated from the dispatch table.
 * <proto/ogles2.h> (generated) includes this and adds the agl* functions
 * and the GL wrappers.
 */
#include <exec/types.h>
#include <utility/tagitem.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Open ogles2.library and fetch its dispatch table: the installed one (in
 * memory, or LIBS:), else PROGDIR:libs/ogles2.library, else
 * PROGDIR:ogles2.library, the first that is new enough and of this dispatch
 * ABI. One in memory that is not is expunged first if no program has it open
 * (exec keeps one library of a name); one in use cannot be replaced. FALSE
 * if there is none. */
BOOL OGLES2Open(void);
void OGLES2Close(void);

/* GL entry points by name, callable without a context argument (SDL, gl4es).
 * NULL for unknown names. Never calls the library. */
void *aglGetProcAddress(const char *name);

/* Varargs forms, as on AmigaOS 4: a tag list ending with TAG_DONE. */
void *aglCreateContextTags2(ULONG *errcode, ...);
void aglSetParamsTags2(ULONG tag1, ...);

/* AmigaOS 4 deprecated these ("_AVOID" in its interface); old source keeps
 * compiling. */
#define aglCreateContext(errcode, tags) aglCreateContext2((errcode), (tags))
#define aglCreateContextTags            aglCreateContextTags2
#define aglSetParams(tags)              aglSetParams2(tags)
#define aglSetParamsTags                aglSetParamsTags2

#ifdef __cplusplus
}
#endif

#endif
