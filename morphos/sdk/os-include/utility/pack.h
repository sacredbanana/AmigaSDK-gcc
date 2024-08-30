#ifndef UTILITY_PACK_H
#define UTILITY_PACK_H

/*
	utility.library pack attributes and macros

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define PSTB_SIGNED  31
#define PSTB_UNPACK  30
#define PSTB_PACK    29
#define PSTB_EXISTS  26

#define PSTF_SIGNED  (1<<PSTB_SIGNED)
#define PSTF_UNPACK  (1<<PSTB_UNPACK)
#define PSTF_PACK    (1<<PSTB_PACK)
#define PSTF_EXISTS  (1<<PSTB_EXISTS)


#define PKCTRL_PACKUNPACK  0x00000000
#define PKCTRL_PACKONLY    0x40000000
#define PKCTRL_UNPACKONLY  0x20000000

#define PKCTRL_BYTE        0x80000000
#define PKCTRL_WORD        0x88000000
#define PKCTRL_LONG        0x90000000

#define PKCTRL_UBYTE       0x00000000
#define PKCTRL_UWORD       0x08000000
#define PKCTRL_ULONG       0x10000000

#define PKCTRL_BIT         0x18000000
#define PKCTRL_FLIPBIT     0x98000000


#define PK_BITNUM1(flg)            ((flg) == 0x01 ? 0 : (flg) == 0x02 ? 1 : (flg) == 0x04 ? 2 : (flg) == 0x08 ? 3 : (flg) == 0x10 ? 4 : (flg) == 0x20 ? 5 : (flg) == 0x40 ? 6 : 7)
#define PK_BITNUM2(flg)            ((flg < 0x100 ? PK_BITNUM1(flg) : 8 + PK_BITNUM1(flg >> 8)))
#define PK_BITNUM(flg)             ((flg < 0x10000 ? PK_BITNUM2(flg) : 16 + PK_BITNUM2(flg >> 16)))
#define PK_WORDOFFSET(flg)         ((flg) < 0x100 ? 1 : 0)
#define PK_LONGOFFSET(flg)         ((flg) < 0x100  ? 3 : (flg) < 0x10000 ? 2 : (flg) < 0x1000000 ? 1 : 0)
#define PK_CALCOFFSET(type,field)  ((ULONG)(&((struct type *)0)->field))


#define PACK_STARTTABLE(tagbase)                           (tagbase)
#define PACK_NEWOFFSET(tagbase)                            (-1L),(tagbase)
#define PACK_ENDTABLE                                      0
#define PACK_ENTRY(tagbase,tag,type,field,control)         (control | ((tag-tagbase) << 16L) | PK_CALCOFFSET(type,field))
#define PACK_BYTEBIT(tagbase,tag,type,field,control,flags) (control | ((tag-tagbase) << 16L) | PK_CALCOFFSET(type,field) | (PK_BITNUM(flags) << 13L))
#define PACK_WORDBIT(tagbase,tag,type,field,control,flags) (control | ((tag-tagbase) << 16L) | (PK_CALCOFFSET(type,field) + PK_WORDOFFSET(flags)) | ((PK_BITNUM(flags) & 7) << 13L))
#define PACK_LONGBIT(tagbase,tag,type,field,control,flags) (control | ((tag-tagbase) << 16L) | (PK_CALCOFFSET(type,field) + PK_LONGOFFSET(flags)) | ((PK_BITNUM(flags) & 7) << 13L))


#endif /* UTILITY_PACK_H */
