#ifndef DATATYPES_TEXTCLASS_H
#define DATATYPES_TEXTCLASS_H
/*
**    $VER: textclass.h 54.16 (22.08.2022)
**
**    Interface definitions for DataType text objects.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

#define TEXTDTCLASS "text.datatype"

/*****************************************************************************/

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

/* Text attributes */
#define TDTA_Buffer     (DTA_Dummy + 300)
#define TDTA_BufferLen  (DTA_Dummy + 301)
#define TDTA_LineList   (DTA_Dummy + 302)
     /* (struct List *). List of lines. The elements of the list are of type
        struct Line (see below) */
#define TDTA_WordSelect (DTA_Dummy + 303)
#define TDTA_WordDelim  (DTA_Dummy + 304)

#define TDTA_WordWrap   (DTA_Dummy + 305)
     /* Boolean. Should the text be word wrapped. Defaults to false. */

#define TDTA_TabSize    (DTA_Dummy + 306)
     /* Size of a TAB character in spaces. Defaults to 8. */

/*****************************************************************************/

/* There is one Line structure for every line of text in our document.    */
struct Line
{
    struct MinNode ln_Link;    /* to link the lines together */
    STRPTR         ln_Text;    /* pointer to the text for this    line */
    ULONG          ln_TextLen; /* the character length of the text for this line */
    UWORD          ln_XOffset; /* where in the    line the text starts */
    UWORD          ln_YOffset; /* line the text is on */
    UWORD          ln_Width;   /* Width of line in pixels */
    UWORD          ln_Height;  /* Height of line in pixels */
    UWORD          ln_Flags;   /* info    on the line */
    BYTE           ln_FgPen;   /* foreground pen */
    BYTE           ln_BgPen;   /* background pen */
    ULONG          ln_Style;   /* Font style */
    APTR           ln_Data;    /* Link data... */
};

/*****************************************************************************/

/* Line.ln_Flags */

/* Line Feed */
#define LNF_LF       (1L << 0)

/* Segment is a link */
#define LNF_LINK     (1L << 1)

/* ln_Data is a pointer to an DataTypes object */
#define LNF_OBJECT   (1L << 2)

/* Object is selected */
#define LNF_SELECTED (1L << 3)

/*****************************************************************************/

/* IFF types that may be text */
#define ID_FTXT MAKE_ID('F','T','X','T')
#define ID_CSET MAKE_ID('C','S','E','T')
#define ID_CHRS MAKE_ID('C','H','R','S')
#define ID_UTF8 MAKE_ID('U','T','F','8')

/*****************************************************************************/

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

#endif /* DATATYPES_TEXTCLASS_H */
