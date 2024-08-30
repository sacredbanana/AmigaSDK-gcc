#ifndef	TINYGL_GLA_H
#define	TINYGL_GLA_H


#include <cybergraphx/cybergraphics.h>
#include <utility/tagitem.h>



/* -------------------------------------------------------------------
 * Functions which are available through shared library interface
 * and only these ones should be used
 */

int  GLAInitializeContextWindowed(GLContext *context, void *w);
void GLADestroyContextWindowed(GLContext *context);
void GLASwapBuffers(GLContext *c);

int  GLAInitializeContextScreen(GLContext *context, void *s);
void GLADestroyContextScreen(GLContext *context);

int  GLAInitializeContextBitMap(GLContext *context, void *b);
void GLADestroyContextBitMap(GLContext *context);

void GLASetSync(GLContext *c, int enable);

int  GLAInitializeContext(GLContext *context, struct TagItem *tags);
void GLADestroyContext(GLContext *context);

int GLAReinitializeContextWindowed(GLContext *context, void *w);

void GLASetAttr(GLContext *c, unsigned int attr, unsigned int val);

/* Context creation tags (for glACreateContext) */

enum
{
	/* with these you can specify type of context (using window, screen or bitmap.
	   You have to only specify one of them. It more is used then here is the order
	   they are checked: SCREEN, WINDOW, BITMAP
	*/

	TGL_CONTEXT_SCREEN = TAG_USER + 1, /* pass here screen pointer the context will use */
	TGL_CONTEXT_WINDOW,                /* same for window */
	TGL_CONTEXT_BITMAP,                /* same for bitmap */
	TGL_CONTEXT_STENCIL,               /* requests stencil. It may fail to create one though. check if it's present later */
	TGL_CONTEXT_NODEPTH                /* don't allocate depth buffer. */
};

/* Context types */

enum
{
	GLA_CTYPE_UNKNOWN = 0,
	GLA_CTYPE_WINDOW,
	GLA_CTYPE_SCREEN,
	GLA_CTYPE_BITMAP
};

/* GLA Extensions */

#define GLA_EXTERNAL_READBUFFER_BITMAP 1UL

#endif /* TINYGL_GLA_H */

