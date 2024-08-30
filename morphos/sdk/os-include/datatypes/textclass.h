#ifndef DATATYPES_TEXTCLASS_H
#define DATATYPES_TEXTCLASS_H

/*
	datatypes text-object definitions (V45)

	Copyright © 2002-2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DATATYPES_DATATYPESCLASS_H
# include <datatypes/datatypesclass.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define TEXTDTCLASS  "text.datatype"


/* Text attributes */

#define TDTA_Buffer      (DTA_Dummy + 300)
#define TDTA_BufferLen   (DTA_Dummy + 301)
#define TDTA_LineList    (DTA_Dummy + 302)
#define TDTA_WordSelect  (DTA_Dummy + 303)
#define TDTA_WordDelim   (DTA_Dummy + 304)
#define TDTA_WordWrap    (DTA_Dummy + 305)


struct Line
{
	struct MinNode ln_Link;
	STRPTR         ln_Text;
	ULONG          ln_TextLen;
	UWORD          ln_XOffset;
	UWORD          ln_YOffset;
	UWORD          ln_Width;
	UWORD          ln_Height;
	UWORD          ln_Flags;
	BYTE           ln_FgPen;
	BYTE           ln_BgPen;
	ULONG          ln_Style;
	APTR           ln_Data;
};


/* Line.ln_Flags defines */

#define LNF_LF        (1<<0)
#define LNF_LINK      (1<<1)
#define LNF_OBJECT    (1<<2)
#define LNF_SELECTED  (1<<3)


#define ID_FTXT  MAKE_ID('F','T','X','T')
#define ID_CHRS  MAKE_ID('C','H','R','S') /* Encoded with the 8-bit system codepage */
#define ID_UTF8  MAKE_ID('U','T','F','8') /* Encoded with UTF8                      */

/* ID_CHRS and ID_UTF8 chunks can be used at the same time. Preferably applications
 * dealing with UTF8 should still write a compatible ID_CHRS chunk for legacy
 * compatibility.
 */

#pragma pack()

#endif /* DATATYPES_TEXTCLASS_H */
