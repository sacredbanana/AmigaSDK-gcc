#ifndef REACTION_REACTION_CLASS_H
#define REACTION_REACTION_CLASS_H

/*
	reaction.class author definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_CGHOOKS_H
# include <intuition/cghooks.h>
#endif

#pragma pack(2)


struct SpecialPens
{
	WORD sp_Version;
	LONG sp_DarkPen;
	LONG sp_LightPen;
};


#define GM_CLIPRECT  (0x550001L)

struct gpClipRect
{
	ULONG                MethodID;
	struct GadgetInfo   *gpc_GInfo;
	struct Rectangle    *gpc_ClipRect;
	ULONG                gpc_Flags;
};


/* GM_CLIPRECT return values */

#define GMC_VISIBLE    2
#define GMC_PARTIAL    1
#define GMC_INVISIBLE  0


#pragma pack()

#endif /* REACTION_REACTION_CLASS_H */
