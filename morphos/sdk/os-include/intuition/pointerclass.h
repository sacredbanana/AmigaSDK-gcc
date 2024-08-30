#ifndef INTUITION_POINTERCLASS_H
#define INTUITION_POINTERCLASS_H

/*
	intuition pointer class definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define POINTERA_Dummy          (TAG_USER + 0x39000)
#define POINTERA_BitMap         (POINTERA_Dummy + 1)
#define POINTERA_XOffset        (POINTERA_Dummy + 2)
#define POINTERA_YOffset        (POINTERA_Dummy + 3)
#define POINTERA_WordWidth      (POINTERA_Dummy + 4)
#define POINTERA_XResolution    (POINTERA_Dummy + 5)
#define POINTERA_YResolution    (POINTERA_Dummy + 6)


#define POINTERXRESN_DEFAULT    0
#define POINTERXRESN_140NS      1
#define POINTERXRESN_70NS       2
#define POINTERXRESN_35NS       3

#define POINTERXRESN_SCREENRES  4
#define POINTERXRESN_LORES      5
#define POINTERXRESN_HIRES      6


#define POINTERYRESN_DEFAULT          0
#define POINTERYRESN_HIGH             2
#define POINTERYRESN_HIGHASPECT       3
#define POINTERYRESN_SCREENRES        4
#define POINTERYRESN_SCREENRESASPECT  5

/* pointer definitions for use with WA_PointerType (OpenWindow() and
** SetWindowPointer()) (V51)
*/

#define POINTERTYPE_NORMAL            0
#define POINTERTYPE_BUSY              1
#define POINTERTYPE_INVISIBLE         2 /* pointer still there, but completly transparent */
#define POINTERTYPE_DOT               3 /* single dot */
#define POINTERTYPE_WORKING           4 /* non blocking pointer signaling app is doing something */
#define POINTERTYPE_HELP              5 /* use when user will get help after clicking in window objects */
#define POINTERTYPE_AIMING            6 /* use for precise operations, such as painting */
#define POINTERTYPE_SELECTTEXT        7 /* use when selecting text */
#define POINTERTYPE_HANDWRITING       8
#define POINTERTYPE_NOTAVAILABLE      9
#define POINTERTYPE_VERTICALRESIZE    10  /* resize operations */
#define POINTERTYPE_HORIZONTALRESIZE  11
#define POINTERTYPE_DIAGONALRESIZE1   12
#define POINTERTYPE_DIAGONALRESIZE2   13
#define POINTERTYPE_MOVE              14 /* window move operations, etc */
#define POINTERTYPE_ALTERNATIVECHOICE 15
#define POINTERTYPE_SELECTLINK        16 /* for hyperlinks */
#define POINTERTYPE_NUMTYPES          17

#endif /* INTUITION_POINTERCLASS_H */
