#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

/*
	graphics text definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define FS_NORMAL       0
#define FSB_UNDERLINED  0
#define FSF_UNDERLINED  (1<<FSB_UNDERLINED)
#define FSB_BOLD        1
#define FSF_BOLD        (1<<FSB_BOLD)
#define FSB_ITALIC      2
#define FSF_ITALIC      (1<<FSB_ITALIC)
#define FSB_EXTENDED    3
#define FSF_EXTENDED    (1<<FSB_EXTENDED)
#define FSB_COLORFONT   6
#define FSF_COLORFONT   (1<<FSB_COLORFONT)
#define FSB_TAGGED      7
#define FSF_TAGGED      (1<<FSB_TAGGED)


#define FPB_ROMFONT       0
#define FPF_ROMFONT       (1<<FPB_ROMFONT)
#define FPB_DISKFONT      1
#define FPF_DISKFONT      (1<<FPB_DISKFONT)
#define FPB_REVPATH       2
#define FPF_REVPATH       (1<<FPB_REVPATH)
#define FPB_TALLDOT       3
#define FPF_TALLDOT       (1<<FPB_TALLDOT)
#define FPB_WIDEDOT       4
#define FPF_WIDEDOT       (1<<FPB_WIDEDOT)
#define FPB_PROPORTIONAL  5
#define FPF_PROPORTIONAL  (1<<FPB_PROPORTIONAL)
#define FPB_DESIGNED      6
#define FPF_DESIGNED      (1<<FPB_DESIGNED)
#define FPB_REMOVED       7
#define FPF_REMOVED       (1<<FPB_REMOVED)


struct TextAttr
{
	STRPTR ta_Name;
	UWORD  ta_YSize;
	UBYTE  ta_Style;
	UBYTE  ta_Flags;
};

struct TTextAttr
{
	STRPTR          tta_Name;
	UWORD           tta_YSize;
	UBYTE           tta_Style;
	UBYTE           tta_Flags;
	struct TagItem *tta_Tags;
};


#define TA_DeviceDPI     (TAG_USER+1)

/* these tags override struct TextAttr fields */
#define TA_Name          (TAG_USER+100)
#define TA_YSize         (TAG_USER+101)

#define TA_Underlined    (TAG_USER+102)
#define TA_Bold          (TAG_USER+103)
#define TA_Italic        (TAG_USER+104)
#define TA_Extended      (TAG_USER+105)
#define TA_ColorFont     (TAG_USER+106)

#define TA_ROMFont       (TAG_USER+107)
#define TA_DiskFont      (TAG_USER+108)
#define TA_RevPath       (TAG_USER+109)
#define TA_TallDot       (TAG_USER+110)
#define TA_WideDot       (TAG_USER+111)
#define TA_Proportional  (TAG_USER+112)
#define TA_Designed      (TAG_USER+113)


#define MAXFONTMATCHWEIGHT  32767


struct TextFont
{
	struct Message tf_Message;
	UWORD          tf_YSize;
	UBYTE          tf_Style;
	UBYTE          tf_Flags;
	UWORD          tf_XSize;
	UWORD          tf_Baseline;
	UWORD          tf_BoldSmear;

	UWORD          tf_Accessors;

	UBYTE          tf_LoChar;
	UBYTE          tf_HiChar;
	APTR           tf_CharData;

	UWORD          tf_Modulo;
	APTR           tf_CharLoc;
	APTR           tf_CharSpace;
	APTR           tf_CharKern;
};

#define tf_Extension  tf_Message.mn_ReplyPort


#define TE0B_NOREMFONT  0
#define TE0F_NOREMFONT  (1<<TE0B_NOREMFONT)


struct TextFontExtension
{
	UWORD            tfe_MatchWord;
	UBYTE            tfe_Flags0;
	UBYTE            tfe_Flags1;
	struct TextFont *tfe_BackPtr;
	struct MsgPort  *tfe_OrigReplyPort;
	struct TagItem  *tfe_Tags;
	UWORD           *tfe_OFontPatchS;
	UWORD           *tfe_OFontPatchK;
};


#define CT_COLORMASK  0x000F
#define CT_COLORFONT  0x0001
#define CT_GREYFONT   0x0002
#define CT_ANTIALIAS  0x0004

#define CTB_MAPCOLOR  0
#define CTF_MAPCOLOR  (1<<CTB_MAPCOLOR)


struct ColorFontColors
{
	UWORD  cfc_Reserved;
	UWORD  cfc_Count;
	UWORD *cfc_ColorTable;
};

struct ColorTextFont
{
	struct TextFont         ctf_TF;
	UWORD                   ctf_Flags;
	UBYTE                   ctf_Depth;
	UBYTE                   ctf_FgColor;
	UBYTE                   ctf_Low;
	UBYTE                   ctf_High;
	UBYTE                   ctf_PlanePick;
	UBYTE                   ctf_PlaneOnOff;
	struct ColorFontColors *ctf_ColorFontColors;
	APTR                    ctf_CharData[8];
};

struct TextExtent
{
	UWORD            te_Width;
	UWORD            te_Height;
	struct Rectangle te_Extent;
};


#pragma pack()

#endif /* GRAPHICS_TEXT_H */
