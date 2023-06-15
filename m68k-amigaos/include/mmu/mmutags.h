/*************************************************************************
 ** mmu.library                                                         **
 **                                                                     **
 ** a system library for arbitration and control of the MC68K MMUs      **
 **                                                                     **
 ** © 1999 THOR-Software, Thomas Richter                                **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** Definition of tags for the MMU library                              **
 **                                                                     **
 ** $VER: 46.2 (06.08.2016)						**
 *************************************************************************/

#ifndef MMU_MMUTAGS_H
#define MMU_MMUTAGS_H

#ifndef UTILITY_TAGITEM_H
#include "utility/tagitem.h"
#endif

#define MAPTAG_DUMMY            ( TAG_USER + 0x03e00000 )

/* SetProperties and SetPageProperties tags */

#define MAPTAG_DESTINATION      ( MAPTAG_DUMMY + 1 )
/* destination in case the memory gets remapped */

#define MAPTAG_BLOCKID          ( MAPTAG_DUMMY + 2 )
/* a unique block ID for swapped out pages. MUST be given. */

#define MAPTAG_USERDATA         ( MAPTAG_DUMMY + 3 )
/* user data for invalid, non-repairable pages. Optional. */

#define MAPTAG_DESCRIPTOR       ( MAPTAG_DUMMY + 4 )
/* the real descriptor for indirect pages. */

#define MAPTAG_SHAREMASK	( MAPTAG_DUMMY + 5 )
/* defines which properties of the parent context are shared. */

#define MAPTAG_WINDOWCTXPTRPTR  ( MAPTAG_DUMMY + 6)
/* defines the window for MAPP_WINDOW pages, i.e. which window to map in */


/* CreateMMUContext tags */

#define MCXTAG_DUMMY            ( TAG_USER + 0x03e00100 )

#define MCXTAG_COPY             ( MCXTAG_DUMMY + 0x001 )
/* copy the definition from another context, given as tag argument */

#define MCXTAG_SHARE            ( MCXTAG_DUMMY + 0x003 )
/* share the properties of this parent (shareable) context */

#define MCXTAG_EXECBASE         ( MCXTAG_DUMMY + 0x010 )
/* disable the special AbsExecBase and low-memory handling ? */

#define MCXTAG_BLANKFILL        ( MCXTAG_DUMMY + 0x011 )
/* a LONG value to fill "blank" memory with */

#define MCXTAG_MEMORYATTRS      ( MCXTAG_DUMMY + 0x012 )
/* the memory attributes to allocate the MMU tables from,
   defaults to MEMF_PUBLIC */

#define MCXTAG_PRIVATESUPER     ( MCXTAG_DUMMY + 0x013 )
/* Create a private supervisor MMU table as well?
   This defaults to FALSE, but even if the argument is
   set to FALSE explicitly, the library might ignore your
   choice and build a supervisor table if your table layout
   is incompatible to the default supervior table. */

#define MCXTAG_ZEROBASE         ( MCXTAG_DUMMY + 0x014 )
/* If the zeropage is invalidated, read the data from where?
   This must be set explicitly if the zero page gets remapped,
   unfortunately. Might be fixed in a future release. */

#define MCXTAG_DISCACHEDES      ( MCXTAG_DUMMY + 0x015)
/* Mark the memory allocated allocated for the descriptors of THIS
   context as cacheinhibit.
   Defaults to FALSE. */

#define MCXTAG_LOWMEMORYLIMIT   ( MCXTAG_DUMMY + 0x016 )
/* Define a boundary in the zero page such that accesses to
   addresses higher than this boundary will be emulated in
   software. This is mainly for 68060/68040 support under Os
   V37 and V38 where chip memory started at 0x400 inside the
   zero page. (NEW for V42) */


#define MCXTAG_DEPTH            ( MCXTAG_DUMMY + 0x020 )
/* define the depth of the MMU tree to build. Defaults to the
   depth of the default tree, which is *usually* three.
   Ranges from 1 to 4 */

#define MCXTAG_LEVELABITS       ( MCXTAG_DUMMY + 0x021 )
/* number of bits to reserve for the top level of the tree */

#define MCXTAG_LEVELBBITS       ( MCXTAG_DUMMY + 0x022 )
/* number of bits for the level B of the tree, if the depth is >1 */

#define MCXTAG_LEVELCBITS       ( MCXTAG_DUMMY + 0x023 )
/* number of bits for the level C of the tree, if the depth is >2 */

#define MCXTAG_LEVELDBITS       ( MCXTAG_DUMMY + 0x024 )
/* bits for the level D of the tree, if the depth is 4 */

#define MCXTAG_PAGEBITS         ( MCXTAG_DUMMY + 0x025 )
/* the number of bits used for the page, 2^bits is the page size */

#define MCXTAG_ERRORCODE        ( MCXTAG_DUMMY + 0x030 )
/* a pointer to a ULONG, to fill in an error code from CreateContext */

#define MCXTAG_SHAREABLE	( MCXTAG_DUMMY + 0x040 )
/* boolean: context is shareable and allows children to share
   its properties partially or fully. */

#define MCXTAG_SHUTDOWNTASK	( MCXTAG_DUMMY + 0x041 )
/* send a signal to this task if all childs of this shareable
   context are gone. */

#define MCXTAG_SHUTDOWNMASK	( MCXTAG_DUMMY + 0x042 )
/* send these signals when all children are gone. */



/* AddContextHook tags */

#define MADTAG_DUMMY            ( TAG_USER + 0x03e00200 )

#define MADTAG_CONTEXT          ( MADTAG_DUMMY + 0 )
/* the context to which the context hook should be added. */

#define MADTAG_TASK             ( MADTAG_DUMMY + 1 )
/* if the exception is task specific, then this is the task pointer.
   Note that many task specific handlers slow down exception handling. */

#define MADTAG_TYPE             ( MADTAG_DUMMY + 2 )
/* type of the exception, MMUEH_SEGFAULT, MMUEH_SWAPPED, MMUEH_SWITCH or
   MMUEH_LAUNCH. See exceptions.h */

#define MADTAG_CODE             ( MADTAG_DUMMY + 3 )
/* the code to be called on exceptions. Should be assembly. 
   a0 is the struct ExceptionData *, a1 and a4 are pointers to the data
   item, see below, a5 is the pointer to the code and a6 is the MMUBase.
   d0-d1/a0-a1 and a4-a5 are scratch registers. The exception handler must
   return with the Z flag set (i.e. an "equal" condition) and d0 cleared to
   indicate that it handled the exception and no other handler should be
   called. */

#define MADTAG_DATA             ( MADTAG_DUMMY + 4 )
/* data to be loaded for the exception handler, will be passed in a1 
   and a4 */

#define MADTAG_NAME             ( MADTAG_DUMMY + 5 )
/* a unique name for the handler. The library makes currently no use of
   this name. */

#define MADTAG_PRI              ( MADTAG_DUMMY + 6 )
/* the priority of the handler. Higher priority handlers are called first.
   Should be above 32 for "emergency stack swap in" handlers, between 32
   and -32 for standard handlers and below -32 for debugging tools like the
   Enforcer and similar. */



/* AddMessageHook tags */

#define MADTAG_CATCHERPORT      ( MADTAG_DUMMY + 0x100 )
/* the port to send the exception message to for message hook types. */



/* GetContextData tags */

#define MGXTAG_DUMMY            ( TAG_USER + 0x03e00400 )

#define MGXTAG_PAGESIZE         ( MGXTAG_DUMMY + 0 )
/* Identical to GetPageSize() (GET only) */

#define MGXTAG_REMAPSIZE        ( MGXTAG_DUMMY + 1 )
/* Identical to RemapSize() (GET only) */

#define MGXTAG_ROOT             ( MGXTAG_DUMMY + 2 )
/* Address of the MMU tree root. You usually do not need it (GET only). */

#define MGXTAG_CONFIG           ( MGXTAG_DUMMY + 3 )
/* Return a pointer to struct MMUConfig (GET only). */

#define MGXTAG_PARENT		( MGXTAG_DUMMY + 4 )
/* context is a child that shares properties of this parent */

#define MGXTAG_USERDATA         ( MGXTAG_DUMMY + 0x100 )
/* Return the user data (GET and SET). */

#define MGXTAG_ADDRESSSPACE     ( MGXTAG_DUMMY + 0x101 )
/* Return the address space. Reserved for the memory lib (GET and SET). */

#endif
