#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H
/*
**    $VER: text.h 54.16 (22.08.2022)
**
**    graphics library text structures
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/*------ Font Styles ------------------------------------------------*/
#define FS_NORMAL       0    /* normal text (no style bits set) */
#define FSB_UNDERLINED  0    /* underlined (under baseline) */
#define FSF_UNDERLINED  0x01
#define FSB_BOLD        1    /* bold face text (ORed w/ shifted) */
#define FSF_BOLD        0x02
#define FSB_ITALIC      2    /* italic (slanted 1:2 right) */
#define FSF_ITALIC      0x04
#define FSB_EXTENDED    3    /* extended face (wider than normal) */
#define FSF_EXTENDED    0x08
#define FSB_ANTIALIASED 4    /* this uses AATextFont structure (V48) */
#define FSF_ANTIALIASED 0x10

#define FSB_COLORFONT   6    /* this uses ColorTextFont structure */
#define FSF_COLORFONT   0x40
#define FSB_TAGGED      7    /* the TextAttr is really a TTextAttr */
#define FSF_TAGGED      0x80

/*------ Font Flags -------------------------------------------------*/
#define FPB_ROMFONT      0    /* font is in rom */
#define FPF_ROMFONT      0x01
#define FPB_DISKFONT     1    /* font is from diskfont.library */
#define FPF_DISKFONT     0x02
#define FPB_REVPATH      2    /* designed path is reversed (e.g. left) */
#define FPF_REVPATH      0x04
#define FPB_TALLDOT      3    /* designed for hires non-interlaced */
#define FPF_TALLDOT      0x08
#define FPB_WIDEDOT      4    /* designed for lores interlaced */
#define FPF_WIDEDOT      0x10
#define FPB_PROPORTIONAL 5    /* character sizes can vary from nominal */
#define FPF_PROPORTIONAL 0x20
#define FPB_DESIGNED     6    /* size explicitly designed, not constructed */
                              /* note: if you do not set this bit in your */
                              /* textattr, then a font may be constructed */
                              /* for you by scaling an existing rom or disk */
                              /* font (under V36 and above). */
#define FPF_DESIGNED     0x40
    /* bit 7 is always clear for fonts on the graphics font list */
#define FPB_REMOVED      7    /* the font has been removed */
#define FPF_REMOVED      (1<<7)

/****** TextAttr node, matches text attributes in RastPort **********/
struct TextAttr
{
    CONST_STRPTR ta_Name;  /* name of the font */
    UWORD        ta_YSize; /* height of the font */
    UBYTE        ta_Style; /* intrinsic font style */
    UBYTE        ta_Flags; /* font preferences and flags */
};

struct TTextAttr
{
    CONST_STRPTR    tta_Name;  /* name of the font */
    UWORD           tta_YSize; /* height of the font */
    UBYTE           tta_Style; /* intrinsic font style */
    UBYTE           tta_Flags; /* font preferences and flags */
    struct TagItem *tta_Tags;  /* extended attributes */
};


/****** Text Tags ***************************************************/
#define TA_DeviceDPI (1|TAG_USER) /* Tag value is Point union: */
                                  /* Hi word XDPI, Lo word YDPI */

#define TA_CharSet   (3|TAG_USER) /* New in V46: IANA Charset number */

/* New in V50: boolean flag for OpenDiskFont() to force rebuilding
 * a font from a (modified) .otag file via bullet API.
 * Must be the first tag in the taglist.
 * To be used ONLY by bullet API font installer software!
 */
#define TA_Rebuild   (4|TAG_USER)

#define MAXFONTMATCHWEIGHT 32767  /* perfect match from WeighTAMatch */


/****** TextFonts node **********************************************/
struct TextFont
{
    struct Message tf_Message;   /* font name in LN       \    used in this  */
                                 /* charset in taglist    |    order to best */
    UWORD          tf_YSize;     /* font height           |    match a font  */
    UBYTE          tf_Style;     /* font style            |    request.      */
    UBYTE          tf_Flags;     /* preferences and flags /                  */
    UWORD          tf_XSize;     /* nominal font width */
    UWORD          tf_Baseline;  /* distance from the top of char to baseline*/
    UWORD          tf_BoldSmear; /* smear to affect a bold enhancement */

    UWORD          tf_Accessors; /* access count */

    UBYTE          tf_LoChar;    /* the first character described here */
    UBYTE          tf_HiChar;    /* the last character described here */
    APTR           tf_CharData;  /* the bit character data */

    UWORD          tf_Modulo;    /* the row modulo for the strike font data */
    APTR           tf_CharLoc;   /* ptr to location data for the strike font */
                                 /*   2 words: bit offset then size */
    APTR           tf_CharSpace; /* ptr to words of proportional spacing data */
    APTR           tf_CharKern;  /* ptr to words of kerning data */
};

/* unfortunately, this needs to be explicitly typed */
#define tf_Extension tf_Message.mn_ReplyPort

/*----- tfe_Flags0 (partial definition) ----------------------------*/
#define TE0B_NOREMFONT 0    /* disallow RemFont for this font */
#define TE0F_NOREMFONT 0x01

/*----- tfe_Flags1 (private) ---------------------------------------*/
#define TE1F_NOUNDERLINING    0x01 /* Cant make this font underlined         */
#define TE1F_NOEMBOLDENING    0x02 /* Cant make this font bold               */
#define TE1F_NOSHEARING       0x04 /* Cant make this font italic             */
#define TE1F_NODEUNDERLINING  0x08 /* Cant make this font non-underlined     */
#define TE1F_NODEEMBOLDENING  0x10 /* Cant make this font non-bold           */
#define TE1F_NODESHEARING     0x20 /* Cant make this font non-italic         */
#define TE1F_NOANTIALIASING   0x40 /* Cant make this font antialiased        */
#define TE1F_GENFONT          0x80 /* This font was generated via bullet API */

struct TextFontExtension                     /* this structure is read-only */
{
    UWORD                 tfe_MatchWord;     /* a magic cookie */
    UBYTE                 tfe_Flags0;        /* (system private flags) */
    UBYTE                 tfe_Flags1;        /* (system private flags) */
    struct TextFont      *tfe_BackPtr;       /* validation of compilation */
    struct MsgPort       *tfe_OrigReplyPort; /* original value in
                                              * tf_Extension */
    CONST struct TagItem *tfe_Tags;          /* Text Tags for the font */
    APTR                  tfe_OFontPatchS;   /* (system private use) */
    APTR                  tfe_OFontPatchK;   /* (system private use) */

    APTR                  tfe_Private0;      /* (guess what) */
    /* this space is reserved for future expansion */
};

/****** ColorTextFont node ******************************************/
/*----- ctf_Flags --------------------------------------------------*/
#define CT_COLORMASK 0x000F /* mask to get to following color styles */
#define CT_COLORFONT 0x0001 /* color map contains designer's colors */
#define CT_GREYFONT  0x0002 /* color map describes even-stepped */
                            /* brightnesses from low to high */
#define CT_ANTIALIAS 0x0004 /* zero background thru fully saturated char */

#ifdef KNOW_YOU_MEAN_SECOND_BYTE
/* The MAPCOLOR bit was defined wrong in earlier releases! */
#define CTB_MAPCOLOR 0      /* map ctf_FgColor to the rp_FgPen if it's */
#define CTF_MAPCOLOR 0x0001 /* is a valid color within ctf_Low..ctf_High */
#else
/* New correct MAPCOLOR bit definition */
#define CTB_MAPCOLOR 8      /* map ctf_FgColor to the rp_FgPen if it's */
#define CTF_MAPCOLOR 0x0100 /* is a valid color within ctf_Low..ctf_High */
#endif

/*----- ColorFontColors --------------------------------------------*/
struct ColorFontColors
{
    UWORD  cfc_Reserved;   /* *must* be zero */
    UWORD  cfc_Count;      /* number of entries in cfc_ColorTable */
    UWORD *cfc_ColorTable; /* 4 bit per component color map packed xRGB */
};

/*----- ColorTextFont ----------------------------------------------*/
struct ColorTextFont
{
    struct TextFont         ctf_TF;
    UWORD                   ctf_Flags;           /* extended flags */
    UBYTE                   ctf_Depth;           /* number of bit planes */
    UBYTE                   ctf_FgColor;         /* color that is remapped to
                                                  * FgPen */
    UBYTE                   ctf_Low;             /* lowest color represented
                                                  * here */
    UBYTE                   ctf_High;            /* highest color represented
                                                  * here */
    UBYTE                   ctf_PlanePick;       /* PlanePick ala Images */
    UBYTE                   ctf_PlaneOnOff;      /* PlaneOnOff ala Images */
    struct ColorFontColors *ctf_ColorFontColors; /* colors for font */
    APTR                    ctf_CharData[8];     /* pointers to bit planes
                                                  * ala tf_CharData */
};

/*----- AATextFont -------------------------------------------------*/
struct AATextFont
{
    struct ColorTextFont aatf_CTF;
    UWORD                aatf_Modulo;      /* Row modulo for the
                                              strike font data */
    UWORD                aatf_FreeMe;      /* Private, defaults to 0 */
    APTR                 aatf_CharData;    /* Chunky alpha maps
                                              for characters */
    APTR                 aatf_CharLoc;     /* Pointer to location data for the
                                              strike font. Two words:
                                              pixel offset then size */
    struct AATextFont   *aatf_SelfPtr;     /* Pointer to the structure itself
                                              to be able to detect modified
                                              TextFont copies that are no real
                                              AATextFonts */
    ULONG                aatf_Reserved[2]; /* For future expansion,
                                              default to 0 */
};

/****** TextExtent node *********************************************/
struct TextExtent
{
     WORD            te_Width;  /* same as TextLength */
    UWORD            te_Height; /* same as tf_YSize   */
    struct Rectangle te_Extent; /* relative to CP     */
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

#endif /* GRAPHICS_TEXT_H */
