#ifndef REACTION_REACTION_PREFS_H
#define REACTION_REACTION_PREFS_H

/*
	reaction prefs definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#pragma pack(2)


#define RAPREFSSEMAPHORE "REACTION-PREFS"

#define ClassActPrefs UIPrefs

struct UIPrefs
{
	struct SignalSemaphore   cap_Semaphore;
	UWORD                    cap_PrefsVersion;
	UWORD                    cap_PrefsSize;
	UBYTE                    cap_BevelType;
	UWORD                    cap_LayoutSpacing;
	BOOL                     cap_3DLook;
	UWORD                    cap_LabelPen;
	UBYTE                    cap_LabelPlace;
	UBYTE                    cap_3DLabel;
	ULONG                   *cap_Reserved1;
	BOOL                     cap_SimpleRefresh;
	UBYTE                    cap_Pattern[256];
	ULONG                   *cap_Reserved2;

	BOOL                     cap_3DProp;
	BOOL                     cap_Reserved3;

	UBYTE                    cap_GlyphType;
	UBYTE                    cap_Reserved4;

	struct TextAttr         *cap_FallbackAttr;
	struct TextAttr         *cap_LabelAttr;
};


/* Bevel types */

#define BVT_GT       0
#define BVT_THIN     1
#define BVT_THICK    2
#define BVT_XEN      3
#define BVT_XENTHIN  4


/* Glyph types */
#define GLT_GT    0
#define GLT_FLAT  1
#define GLT_3D    2


#pragma pack()

#endif /* REACTION_REACTION_PREFS_H */
