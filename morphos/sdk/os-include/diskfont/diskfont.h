#ifndef DISKFONT_DISKFONT_H
#define DISKFONT_DISKFONT_H

/*
	diskfont.library defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef GRAPHICS_TEXT_H
# include <graphics/text.h>
#endif

#pragma pack(2)


#define MAXFONTPATH  256


struct FontContents
{
	char  fc_FileName[MAXFONTPATH];
	UWORD fc_YSize;
	UBYTE fc_Style;
	UBYTE fc_Flags;
};

struct TFontContents
{
	char  tfc_FileName[MAXFONTPATH-2];
	UWORD tfc_TagCount;
	UWORD tfc_YSize;
	UBYTE tfc_Style;
	UBYTE tfc_Flags;
};


#define FCH_ID   0x0f00
#define TFCH_ID  0x0f02
#define OFCH_ID  0x0f03


struct FontContentsHeader
{
	UWORD fch_FileID;
	UWORD fch_NumEntries;
};


#define DFH_ID  0x0f80

#define MAXFONTNAME  32


struct DiskFontHeader
{
	struct Node     dfh_DF;
	UWORD           dfh_FileID;
	UWORD           dfh_Revision;
	LONG            dfh_Segment;
	char            dfh_Name[MAXFONTNAME];
	struct TextFont dfh_TF;
};

#define dfh_TagList  dfh_Segment


#define AFB_MEMORY  0
#define AFF_MEMORY  (1<<AFB_MEMORY)
#define AFB_DISK    1
#define AFF_DISK    (1<<AFB_DISK)
#define AFB_SCALED  2
#define AFF_SCALED  (1<<AFB_SCALED)
#define AFB_BITMAP  3
#define AFF_BITMAP  (1<<AFB_BITMAP)

#define AFB_TAGGED  16
#define AFF_TAGGED  (1<<AFB_TAGGED)


struct AvailFonts
{
	UWORD           af_Type;
	struct TextAttr af_Attr;
};

struct TAvailFonts
{
	UWORD            taf_Type;
	struct TTextAttr taf_Attr;
};

struct AvailFontsHeader
{
	UWORD afh_NumEntries;
};


#pragma pack()

#endif /* DISKFONT_DISKFONT_H */
