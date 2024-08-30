#ifndef PREFS_REACTION_H
#define PREFS_REACTION_H

/*
	reaction prefs definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_TEXT_H
# include <graphics/text.h>
#endif

#pragma pack(2)


#define ID_RACT  MAKE_ID('R','A','C','T')

#define FONTNAMESIZE  (128)


struct ReactionPrefs
{
	UWORD           rp_BevelType;
	UWORD           rp_GlyphType;
	UWORD           rp_LayoutSpacing;
	BOOL            rp_3DProp;
	UWORD           rp_LabelPen;
	UWORD           rp_LabelPlace;
	BOOL            rp_3DLabel;
	BOOL            rp_SimpleRefresh;
	BOOL            rp_3DLook;
	struct TextAttr rp_FallbackAttr;
	struct TextAttr rp_LabelAttr;
	UBYTE           rp_FallbackName[FONTNAMESIZE];
	UBYTE           rp_LabelName[FONTNAMESIZE];
	UBYTE           rp_Pattern[256];
};


#pragma pack()

#endif /* PREFS_REACTION_H */
