/*
 * $Id: glutcontext.h 254 2008-04-21 14:07:23Z HansR $
 *
 * $Date: 2008-04-21 09:07:23 -0359ÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐÐ $
 * $Revision: 254 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#include <exec/lists.h>

#include "mgl/context.h"

#ifndef __GLUTCONTEXT_H__
#define __GLUTCONTEXT_H__

#define MODIFIERS_INVALID ((int)~0)

typedef struct GameModeData_s GameModeData;
struct GameModeData_s
{
	GLboolean gameModeActive;
	GLint windowID;
};

typedef struct TimerHook_s TimerHook;
struct TimerHook_s
{
	struct MinNode node;
	struct TimeRequest *timerIO;
	void (*func)(int value);
	int value;
};

/* A helper structure holding two ints and a boolean */
typedef struct tagSFG_XYUse SFG_XYUse;
struct tagSFG_XYUse
{
    GLint           X, Y;               /* The two integers...               */
    GLboolean       Use;                /* ...and a single boolean.          */
};

typedef struct GLUTcontext_t * GLUTcontext;
struct GLUTcontext_t
{
	GLbitfield	GlutEvent;
	GLboolean	GlutSingle;

	GLuint		newX, newY;		/* Reposition event */
	GLuint		newW, newH;		/* Reshape event */
	GLuint		GlutW, GlutH;
	char *		IconName;

	void		(*glutDisplayFunc)(void);
	void		(*glutReshapeFunc)(int width, int height);
	void		(*glutKeyboardFunc)(unsigned char key, int x, int y);
	void		(*glutMouseFunc)(int button, int state, int x, int y);
	void		(*glutMotionFunc)(int x, int y);
	void		(*glutPassiveMotionFunc)(int x, int y);
	void		(*glutVisibilityFunc)(int state);
	void		(*glutEntryFunc)(int state);
	void		(*glutSpecialFunc)(int key, int x, int y);
	void		(*glutIdleFunc)(void);

	struct TimeVal __glutStartTime;
	GLuint __glutWindowX;
	GLuint __glutWindowY;
	GLuint __glutWindowWidth;
	GLuint __glutWindowHeight;
	GLuint __glutDisplayMode;
	struct GLContextIFace *__glutContext;
	GLcontext glctx; // Unused

	/* IMPORTANT: All new fields in this structure must be added after this line   */
	/* for compatibility with older software (glctx must remain at the same offset */
	void		(*glutKeyboardUpFunc)(unsigned char key, int x, int y);
	void		(*glutSpecialUpFunc)(int key, int x, int y);

	GLboolean ignoreKeyRepeat;
	GLenum keyRepeatMode;

	SFG_XYUse        gameModeSize;         /* Game mode screen's dimensions  */
	int              gameModeDepth;        /* The pixel depth for game mode  */
	int              gameModeRefresh;      /* The refresh rate for game mode */
	GameModeData 	 gameModeData;

	int modifiers; /* ALT, SHIFT, or CTRL indicator for key press callbacks */
	int actionOnWindowClose;
	GLboolean useCurrentContext; /* Allows a current context to be shared between multiple windows */
								 // NOTE: Not used yet
	GLboolean running;

	struct IOStdReq   *warpPointerIOReq;
	struct MsgPort    *warpPointerMP;
	struct InputEvent *warpPointerEvent;

	/** Additional hook function pointers
	 */
	void		(*glutCloseFunc)(void);

	/** // ##### FIXME! ##### need timer list for multiple timer funcs
	 */
	struct MinList freeTimerHookList;
	struct MinList activeTimerHookList;
	struct MsgPort *timerHookPort;
	double ticksPerMSec;
	
	#if defined(MGL_TABOR) && !defined(MGL_TABOR_NO_ABI_BRIDGE)
	GLfloat tabor_floats[4]; GLdouble tabor_doubles[4];
	#endif
};

#endif

