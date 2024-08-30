#ifndef	TINYGL_GLA_H
#define	TINYGL_GLA_H

#include <cybergraphx/cybergraphics.h>
#include <utility/tagitem.h>

typedef struct GLAContext_s GLAContext;

void	GLASwapBuffers( GLContext   *c);
void	GLASetSync( GLContext   *c , int enable );
int		GLAInitializeContext(GLContext *context, struct TagItem	   *tags );
void	GLADestroyContext( GLContext    *context );

/* Context creation tags (for glACreateContext) */

enum
{
	/* with these you can specify type of context (using window, screen or bitmap.
	   You have to only specify one of them. It more is used then here is the order
	   they are checked: SCREEN, WINDOW, BITMAP
	*/

	TGL_CONTEXT_SCREEN = TAG_USER + 1,	   /* pass here screen pointer the context will use */
	TGL_CONTEXT_WINDOW,	/* same for window */
	TGL_CONTEXT_BITMAP,	/* same for bitmap */
	TGL_CONTEXT_STENCIL	/* requests stencil. It may fail to create one though. check if it's present later */
};

#endif /* TINYGL_GLA_H */
