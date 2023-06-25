#ifndef CLIB_ELF_PROTOS_H
#define CLIB_ELF_PROTOS_H

/*
**    $Id: elf_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEMS_H
#include <utility/tagitems.h>
#endif
#ifndef   LIBRARIES_ELF_H
#include <libraries/elf.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

Elf32_Handle OpenElf( struct TagItem *taglist );
Elf32_Handle OpenElfTags( Tag tag1, ... );
VOID CloseElf( Elf32_Handle elfHandle );
ULONG GetElfAttrs( Elf32_Handle elfHandle, struct TagItem *taglist );
ULONG GetElfAttrsTags( Elf32_Handle elfHandle, Tag tag1, ... );
ULONG SetElfAttrs( Elf32_Handle elfHandle, struct TagItem *taglist );
ULONG SetElfAttrsTags( Elf32_Handle elfHandle, Tag tag1, ... );
Elf32_Shdr *GetSectionHeader( Elf32_Handle elfHandle, struct TagItem *tagList );
Elf32_Shdr *GetSectionHeaderTags( Elf32_Handle elfHandle, Tag tag1, ... );
APTR GetSection( Elf32_Handle elfHandle, struct TagItem *tagList );
APTR GetSectionTags( Elf32_Handle elfHandle, Tag tag1, ... );
Elf32_Error ElfLoadSeg( Elf32_Handle elfHandle, struct TagItem *taglist );
Elf32_Error ElfLoadSegTags( Elf32_Handle elfHandle, Tag tag1, ... );
STRPTR GetElfString( Elf32_Handle elfHandle, ULONG sectionIndex, ULONG stringIndex );
ULONG SymbolQuery( Elf32_Handle elfHandle, ULONG numQueries, struct Elf32_SymbolQuery *queries );
VOID UnloadSection( Elf32_Handle elfHandle, struct TagItem *taglist );
VOID UnloadSectionTags( Elf32_Handle elfHandle, Tag tag1, ... );
VOID FixupHandle( Elf32_Handle elfHandle );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_ELF_PROTOS_H */
