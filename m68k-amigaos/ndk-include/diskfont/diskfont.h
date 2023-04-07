#ifndef	DISKFONT_DISKFONT_H
#define	DISKFONT_DISKFONT_H

/*
**	$VER: diskfont.h 47.2 (16.11.2021)
**
**	diskfont library definitions
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif

#define MAXFONTPATH 256   /* including null terminator */

/* this really belongs to <graphics/text.h> */
#define TA_CharSet (3|TAG_USER)

struct FontContents {
    TEXT    fc_FileName[MAXFONTPATH];
    UWORD   fc_YSize;
    UBYTE   fc_Style;
    UBYTE   fc_Flags;
};

struct TFontContents {
    TEXT    tfc_FileName[MAXFONTPATH-2];
    UWORD   tfc_TagCount;	/* including the TAG_DONE tag */
    /*
     *	if tfc_TagCount is non-zero, tfc_FileName is overlayed with
     *	Text Tags starting at:	(struct TagItem *)
     *	    &tfc_FileName[MAXFONTPATH-(tfc_TagCount*sizeof(struct TagItem))]
     */
    UWORD   tfc_YSize;
    UBYTE   tfc_Style;
    UBYTE   tfc_Flags;
};


#define FCH_ID	0x0f00	/* FontContentsHeader, then FontContents */
#define TFCH_ID	0x0f02	/* FontContentsHeader, then TFontContents */
#define OFCH_ID	0x0f03	/* FontContentsHeader, then TFontContents,
			 * associated with outline font */

struct FontContentsHeader {
    UWORD   fch_FileID;		/* FCH_ID */
    UWORD   fch_NumEntries;	/* the number of FontContents elements */
    /* struct FontContents fch_FC[], or struct TFontContents fch_TFC[]; */
};


#define  DFH_ID		0x0f80
#define  MAXFONTNAME	32	/* font name including ".font\0" */

struct DiskFontHeader {
    /* the following 8 bytes are not actually considered a part of the	*/
    /* DiskFontHeader, but immediately preceed it. The NextSegment is	*/
    /* supplied by the linker/loader, and the ReturnCode is the code	*/
    /* at the beginning of the font in case someone runs it...		*/
    /*	 ULONG dfh_NextSegment;			\* actually a BPTR	*/
    /*	 ULONG dfh_ReturnCode;			\* MOVEQ #0,D0 : RTS	*/
    /* here then is the official start of the DiskFontHeader...		*/
    struct Node dfh_DF;		/* node to link disk fonts */
    UWORD   dfh_FileID;		/* DFH_ID */
    UWORD   dfh_Revision;	/* the font revision */
    LONG    dfh_Segment;	/* the segment address when loaded */
    TEXT    dfh_Name[MAXFONTNAME]; /* stripped font name (null terminated) */
    struct TextFont dfh_TF;	/* loaded TextFont structure */
				/* dfh_TF.tf_Message.mn_Node.ln_Name */
				/* points to the full font name */
};

/* unfortunately, this needs to be explicitly typed */
/* used only if dfh_TF.tf_Style FSB_TAGGED bit is set */
/* moved to dfh_TF.tf_Extension->tfe_Tags during loading */
#define	dfh_TagList	dfh_Segment


#define     AFB_MEMORY	0	/* dont filter out memory fonts */
#define     AFF_MEMORY	0x0001
#define     AFB_DISK	1	/* dont filter out disk fonts */
#define     AFF_DISK	0x0002
#define     AFB_SCALED	2	/* dont filter out scaled fonts */
#define     AFF_SCALED	0x0004
#define     AFB_BITMAP	3	/* filter out .otag files */
#define     AFF_BITMAP	0x0008
#define     AFB_OTAG    4	/* show .otag files only, */
#define     AFF_OTAG	0x0010	/* implemented since V46 */
#define     AFB_TYPE    6	/* return diskfont type in [t]af_Type: */
				/* AFF_DISK|AFF_BITMAP for bitmap fonts, */
				/* AFF_DISK|AFF_OTAG for .otag fonts, */
				/* AFF_DISK|AFF_OTAG|AFF_SCALED for */
				/* scalable .otag fonts. */
#define     AFF_CHARSET	0x0020	/* reserved */
#define     AFF_TYPE	0x0040	/* implemented since V46 */

#define     AFB_TAGGED	16	/* return TAvailFonts with taglist */
#define     AFF_TAGGED	0x10000L

struct AvailFonts {
    UWORD   af_Type;		/* MEMORY, DISK, or SCALED */
    struct TextAttr af_Attr;	/* text attributes for font */
};

struct TAvailFonts {
    UWORD   taf_Type;		/* MEMORY, DISK, or SCALED */
    struct TTextAttr taf_Attr;	/* text attributes for font */
};

struct AvailFontsHeader {
    UWORD   afh_NumEntries;	 /* number of AvailFonts elements */
    /* struct AvailFonts afh_AF[], or struct TAvailFonts afh_TAF[]; */
};

/* structure used by EOpenEngine() ESetInfo() etc (V47) */
struct EGlyphEngine {
    APTR                ege_Reserved;     /* System reserved, don't touch */
    struct Library     *ege_BulletBase;
    struct GlyphEngine *ege_GlyphEngine;
};

/* flags for OpenOutlineFont() (V47) */
#define OFB_OPEN 0
#define OFF_OPEN 0x00000001L

/* structure returned by OpenOutlineFont() (V47) */
struct OutlineFont {
    STRPTR               olf_OTagPath;    /* full path & name of the .otag file */
    struct TagItem      *olf_OTagList;    /* relocated .otag file in memory     */
    STRPTR               olf_EngineName;  /* OT_Engine name                     */
    STRPTR               olf_LibraryName; /* OT_Engine name + ".library"        */
    struct EGlyphEngine  olf_EEngine;     /* All NULL if OFF_OPEN not specified */
    APTR                 olf_Reserved;    /* for future expansion               */
    APTR                 olf_UserData;    /* for private use                    */
};

#endif	/* DISKFONT_DISKFONT_H */
