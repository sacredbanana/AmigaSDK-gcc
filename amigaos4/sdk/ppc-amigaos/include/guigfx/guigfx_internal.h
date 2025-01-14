#ifndef  EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

/****************************************************************************

	Structure definitions

****************************************************************************/

struct Picture
{
	struct	SignalSemaphore semaphore;
	UBYTE	*array;					/* Daten */
	UWORD	width, height;			/* Breite/H�he in Pixeln */
	UWORD	aspectx, aspecty;		/* x:y Pixelaspekt */
	APTR   	palette;				/* Palette im render.library Format */
	ULONG	pixelformat;			/* Pixelformat */


	BOOL	alphapresent;			/* alpha-channel vorhanden */
	UBYTE	*alphaarray;			/* separater (ausgelagerter) alpha-channel */

	APTR    histogram;

	UWORD	hstype;					/* palette und histogramm */

	BOOL	owner;					/* zeigt an, da� das Array auch gel�scht werden mu� */
	ULONG	maxbytes;				/* nur bei owner==FALSE - Gr��e des Speicherbereichs */

	APTR    directdraw; /* auf dieses Drawhandle kann direkt gezeichnet werden */


	APTR	scaleengine;
	WORD	scalesourcewidth, scalesourceheight;
	WORD	scaledestwidth, scaledestheight;
	ULONG	scalepixelformat;
	BOOL	scalecoords;

};

