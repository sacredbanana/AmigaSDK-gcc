        IFND MMU_MMUTAGS_I
MMU_MMUTAGS_I   SET     1
;*************************************************************************
;** mmu.library                                                         **
;**                                                                     **
;** a system library for arbitration and control of the MC68K MMUs      **
;**                                                                     **
;** © 1999 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** Definition of tags for the MMU library                              **
;**                                                                     **
;** $VER: 46.2 (06.08.2016)						**
;*************************************************************************

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC ; EXEC_TYPES_I

        IFND UTILITY_TAGITEM_I
        INCLUDE "utility/tagitem.i"
        ENDC ; UTILITY_TAGITEM_I


MAPTAG_DUMMY            equ     (TAG_USER+$03e00000)

;* SetProperties and SetPageProperties tags *

MAPTAG_DESTINATION      equ     (MAPTAG_DUMMY+1)
;* destination in case the memory gets remapped *

MAPTAG_BLOCKID          equ     (MAPTAG_DUMMY+2)
;* a unique block ID for swapped out pages. MUST be given. *

MAPTAG_USERDATA         equ     (MAPTAG_DUMMY+3)
;* user data for invalid, non-repairable pages. Optional. *

MAPTAG_DESCRIPTOR       equ     (MAPTAG_DUMMY+4)
;* the real descriptor for indirect pages. *

MAPTAG_SHAREMASK	equ	(MAPTAG_DUMMY+5)
;* defines which properties of the parent context are shared. *

MAPTAG_WINDOWCTXPTRPTR  equ	(MAPTAG_DUMMY+6)
;* defines the window for MAPP_WINDOW pages, i.e. which window to map in *


;* CreateMMUContext tags *

MCXTAG_DUMMY            equ     (TAG_USER+$03e00100)

MCXTAG_COPY             equ     (MCXTAG_DUMMY+$001)
;* copy the definition from another context, given as tag argument *

MCXTAG_SHARE            equ	(MCXTAG_DUMMY+$003)
;* share the properties of this parent (shareable) context *

MCXTAG_EXECBASE         equ     (MCXTAG_DUMMY+$010)
;* disable the special AbsExecBase and low-memory handling ? *

MCXTAG_BLANKFILL        equ     (MCXTAG_DUMMY+$011)
;* a LONG value to fill "blank" memory with *

MCXTAG_MEMORYATTRS      equ     (MCXTAG_DUMMY+$012)
;* the memory attributes to allocate the MMU tables from,
;* defaults to MEMF_PUBLIC *


MCXTAG_PRIVATESUPER     equ     (MCXTAG_DUMMY+$013)
;* Create a private supervisor MMU table as well?
;* This defaults to FALSE, but even if the argument is
;* set to FALSE explicitly, the library might ignore your
;* choice and build a supervisor table if your table layout
;* is incompatible to the default supervior table.

MCXTAG_ZEROBASE         equ     (MCXTAG_DUMMY+$014)
;* If the zeropage is invalidated, read the data from where?
;* This must be set explicitly if the zero page gets remapped,
;* unfortunately. Might be fixed in a future release. *

MCXTAG_DISCACHEDES      equ     (MCXTAG_DUMMY+$15)
;* Mark the memory allocated allocated for the descriptors of THIS
;* context as cacheinhibit.
;* Defaults to FALSE.
;* 

MCXTAG_LOWMEMORYLIMIT   equ     (MCXTAG_DUMMY+$016)
;* Define a boundary in the zero page such that accesses to
;* addresses higher than this boundary will be emulated in
;* software. This is mainly for 68060/68040 support under Os
;* V37 and V38 where chip memory started at 0x400 inside the
;* zero page. (NEW for V42)


MCXTAG_DEPTH            equ     (MCXTAG_DUMMY+$020)
;* define the depth of the MMU tree to build. Defaults to the
;* depth of the default tree, which is *usually* three.
;* Ranges from 1 to 4 *

MCXTAG_LEVELABITS       equ     (MCXTAG_DUMMY+$021)
;* number of bits to reserve for the top level of the tree *

MCXTAG_LEVELBBITS       equ     (MCXTAG_DUMMY+$022)
;* number of bits for the level B of the tree, if the depth is >1 *

MCXTAG_LEVELCBITS       equ     (MCXTAG_DUMMY+$023)
;* number of bits for the level C of the tree, if the depth is >2 *

MCXTAG_LEVELDBITS       equ     (MCXTAG_DUMMY+$024)
;* bits for the level D of the tree, if the depth is 4 *

MCXTAG_PAGEBITS         equ     (MCXTAG_DUMMY+$025)
;* the number of bits used for the page, 2^bits is the page size *

MCXTAG_ERRORCODE        equ     (MCXTAG_DUMMY+$030)
;* a pointer to a ULONG, to fill in an error code from CreateContext *

MCXTAG_SHAREABLE	equ	(MCXTAG_DUMMY+$040)
;* boolean: context is shareable and allows children to share
;* its properties partially or fully. *

MCXTAG_SHUTDOWNTASK	equ	(MCXTAG_DUMMY+$041)
;* send a signal to this task if all childs of this shareable
;* context are gone. *

MCXTAG_SHUTDOWNMASK	equ	(MCXTAG_DUMMY+$042)
;* send these signals when all children are gone. *




;* AddContextHook tags *

MADTAG_DUMMY            equ     (TAG_USER+$03e00200)

MADTAG_CONTEXT          equ     (MADTAG_DUMMY+0)
;* the context to which the context hook should be added. *

MADTAG_TASK             equ     (MADTAG_DUMMY+1)
;* if the exception is task specific, then this is the task pointer.
;* Note that many task specific handlers slow down exception handling. *

MADTAG_TYPE             equ     (MADTAG_DUMMY+2)
;* type of the exception, MMUEH_SEGFAULT, MMUEH_SWAPPED, MMUEH_SWITCH or
;* MMUEH_LAUNCH. See exceptions.h *

MADTAG_CODE             equ     (MADTAG_DUMMY+3)
;* the code to be called on exceptions. Should be assembly.
;* a0 is the struct ExceptionData *, a1 and a4 are pointers to the data
;* item, see below, a5 is the pointer to the code and a6 is the MMUBase.
;* d0-d1/a0-a1 and a4-a5 are scratch registers. The exception handler must
;* return with the Z flag set (i.e. an "equal" condition) and d0 cleared to
;* indicate that it handled the exception and no other handler should be
;* called. *

MADTAG_DATA             equ     (MADTAG_DUMMY+4)
;* data to be loaded for the exception handler, will be passed in a1
;* and a4 *

MADTAG_NAME             equ     (MADTAG_DUMMY+5)
;* a unique name for the handler. The library makes currently no use of
;* this name. *

MADTAG_PRI              equ     (MADTAG_DUMMY+6)
;* the priority of the handler. Higher priority handlers are called first.
;* Should be above 32 for "emergency stack swap in" handlers, between 32
;* and -32 for standard handlers and below -32 for debugging tools like the
;* Enforcer and similar. *



;* AddMessageHook tags *

MADTAG_CATCHERPORT      equ     (MADTAG_DUMMY+$100)
;* the port to send the exception message to for message hook types. *


;* GetContextData tags *


MGXTAG_DUMMY            equ     (TAG_USER+$03e00400)

MGXTAG_PAGESIZE         equ     (MGXTAG_DUMMY+0)
;* Identical to GetPageSize() (GET only) *

MGXTAG_REMAPSIZE        equ     (MGXTAG_DUMMY+1)
;* Identical to RemapSize() (GET only) *

MGXTAG_ROOT             equ     (MGXTAG_DUMMY+2)
;* Address of the MMU tree root. You usually do not need it (GET only). *

MGXTAG_CONFIG           equ     (MGXTAG_DUMMY+3)
;* Return a pointer to struct MMUConfig (GET only). *

MGXTAG_PARENT		equ	(MGXTAG_DUMMY+4)
;* context is a child that shares properties of this parent *

MGXTAG_USERDATA         equ     (MGXTAG_DUMMY+$100)
;* Return the user data (GET and SET). *

MGXTAG_ADDRESSSPACE     equ     (MGXTAG_DUMMY+$101)
;* Return the address space. Reserved for the memory lib (GET and SET). *


        ENDC    ; MMU_MMUTAGS_I
