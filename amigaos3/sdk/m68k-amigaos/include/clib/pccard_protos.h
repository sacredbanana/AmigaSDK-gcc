/* Automatically generated header! Do not edit! */

#ifndef CLIB_PCCARD_PROTOS_H
#define CLIB_PCCARD_PROTOS_H


/*
**	$VER: pccard_protos.h pccard_lib.sfd (02.04.2022)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2003-2022 Neil Cafferkey
**	All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

const struct TagItem * PCCard_GetTupleInfo(const UBYTE * tuple);
VOID PCCard_FreeTupleInfo(const struct TagItem * tagList);
const struct TagItem * PCCard_GetFuncETupleInfo(const UBYTE * tuple, const ULONG funcID);

#endif	/*  CLIB_PCCARD_PROTOS_H  */
