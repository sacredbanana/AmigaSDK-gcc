#ifndef DISKFONT_DISKFONT_H
#define DISKFONT_DISKFONT_H
/*
**      $VER: diskfont.h 54.16 (22.08.2022)
**
**      diskfont library definitions
**
**      Copyright (C) 1990 Robert R. Burns
**          All Rights Reserved
**
**      Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**          All Rights Reserved
**
**      Copyright (c) 2010 Hyperion Entertainment CVBA.
**          All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif
#ifndef   DISKFONT_GLYPH_H
#include <diskfont/glyph.h>
#endif
#ifndef   BULLET_INTERFACE_DEF_H
#include <interfaces/bullet.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define MAXFONTPATH 256 /* including null terminator */

struct FontContents
{
    TEXT   fc_FileName[MAXFONTPATH];
    uint16 fc_YSize;
    uint8  fc_Style;
    uint8  fc_Flags;
};

struct TFontContents
{
    TEXT   tfc_FileName[MAXFONTPATH-2];
    uint16 tfc_TagCount;                /* including the TAG_DONE tag */
    /*
     * if tfc_TagCount is non-zero, tfc_FileName is overlayed with
     * Text Tags starting at:  (struct TagItem *)
     * &tfc_FileName[MAXFONTPATH - (tfc_TagCount * sizeof(struct TagItem))]
     */
    uint16 tfc_YSize;
    uint8  tfc_Style;
    uint8  tfc_Flags;
};


#define FCH_ID  0x0f00 /* FontContentsHeader, then FontContents */
#define TFCH_ID 0x0f02 /* FontContentsHeader, then TFontContents */
#define OFCH_ID 0x0f03 /* FontContentsHeader, then TFontContents,
                          associated with outline font */

struct FontContentsHeader
{
    uint16 fch_FileID;     /* FCH_ID */
    uint16 fch_NumEntries; /* the number of FontContents elements */

    /* struct FontContents fch_FC[], or struct TFontContents fch_TFC[]; */
};


#define DFH_ID      0x0f80
#define MAXFONTNAME 32     /* font name including ".font\0" */

struct DiskFontHeader
{
    /* the following 8 bytes are not actually considered a part of the */
    /* DiskFontHeader, but immediately preceed it. The NextSegment is  */
    /* supplied by the linker/loader, and the ReturnCode is the code   */
    /* at the beginning of the font in case someone runs it...         */
    /* Warning: you can find those bytes on disk but not in memory.    */
    /*   uint32 dfh_NextSegment; \* actually a BPTR                     */
    /*   uint32 dfh_ReturnCode;  \* MOVEQ #0,D0 : RTS                   */
    /* here then is the official start of the DiskFontHeader...        */
    struct Node     dfh_DF;                /* node to link disk fonts */
    uint16          dfh_FileID;            /* DFH_ID */
    uint16          dfh_Revision;          /* the font revision */
    int32           dfh_Segment;           /* the segment address
                                            * when loaded */
    TEXT            dfh_Name[MAXFONTNAME]; /* stripped font name (null
                                            * terminated) */
    struct TextFont dfh_TF;                /* loaded TextFont structure,
                                            * dfh_TF.tf_Message.mn_Node.ln_Name
                                            * points to the full font name */
};

/* unfortunately, this needs to be explicitly typed      */
/* used only if dfh_TF.tf_Style FSB_TAGGED bit is set    */
/* moved to dfh_TF.tf_Extension->tfe_Tags during loading */
#define dfh_TagList  dfh_Segment

#define AFB_MEMORY   0      /* dont filter out memory fonts */
#define AFF_MEMORY   0x0001
#define AFB_DISK     1      /* dont filter out disk fonts */
#define AFF_DISK     0x0002
#define AFB_SCALED   2      /* dont filter out scaled fonts */
#define AFF_SCALED   0x0004
#define AFB_BITMAP   3      /* filter out .otag files */
#define AFF_BITMAP   0x0008
#define AFB_OTAG     4      /* show .otag files only, */
#define AFF_OTAG     0x0010 /* implemented since V50 */
#define AFB_CHARSET  5      /* show fonts in all charsets, */
#define AFF_CHARSET  0x0020 /* implemented since V50 */
#define AFB_TYPE     6      /* return diskfont type in [t]af_Type: */
                            /* AFF_DISK|AFF_BITMAP for bitmap fonts, */
                            /* AFF_DISK|AFF_OTAG for .otag fonts, */
                            /* AFF_DISK|AFF_OTAG|AFF_SCALED for */
                            /* scalable .otag fonts. */
#define AFF_TYPE     0x0040 /* implemented since V50 */

#define AFB_TAGGED   16     /* return TAvailFonts with taglist */
#define AFF_TAGGED   0x10000L

struct AvailFonts
{
    uint16          af_Type; /* AFF_MEMORY, AFF_DISK or AFF_SCALED */
    struct TextAttr af_Attr; /* text attributes for font */
};

struct TAvailFonts
{
    uint16           taf_Type; /* AFF_MEMORY, AFF_DISK or AFF_SCALED */
    struct TTextAttr taf_Attr; /* text attributes for font */
};

struct AvailFontsHeader
{
    uint16 afh_NumEntries; /* number of AvailFonts elements */
    /* struct AvailFonts afh_AF[], or struct TAvailFonts afh_TAF[]; */
};

/* structure used by EOpenEngine() ESetInfo() etc (V50) */
struct EGlyphEngine
{
    struct BulletIFace *ege_IBullet;    /* NULL for 68K font engines */
    struct Library     *ege_BulletBase;
    struct GlyphEngine *ege_GlyphEngine;
};

/* flags for OpenOutlineFont() (V50) */
#define OFB_OPEN 0
#define OFF_OPEN 0x00000001L

/* structure returned by OpenOutlineFont() (V50) */
struct OutlineFont
{
    STRPTR               olf_OTagPath;    /* full path & name of the .otag file */
    struct TagItem      *olf_OTagList;    /* relocated .otag file in memory     */
    STRPTR               olf_EngineName;  /* OT_Engine name                     */
    STRPTR               olf_LibraryName; /* OT_Engine name + ".library"        */
    struct EGlyphEngine  olf_EEngine;     /* All NULL if OFF_OPEN not specified */
    APTR                 olf_Reserved;    /* for future expansion               */
    APTR                 olf_UserData;    /* for private use                    */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DISKFONT_DISKFONT_H */
