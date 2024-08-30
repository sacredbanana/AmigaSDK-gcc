        IFND MMU_EXCEPTIONS_I
MMU_EXCEPTIONS_I        SET     1
;*************************************************************************
;** mmu.library                                                         **
;**                                                                     **
;** a system library for arbitration and control of the MC68K MMUs      **
;**                                                                     **
;** © 1998 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** exception related definitions                                       **
;**									**
;** $VER: 42.1 (08.04.2001)						**
;*************************************************************************

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC ; EXEC_TYPES_I

        IFND EXEC_PORTS_I
        INCLUDE "exec/ports.i"
        ENDC ; EXEC_PORTS_I

        IFND EXEC_INTERRUPTS_I
        INCLUDE "exec/interrupts.i"
        ENDC ; EXEC_INTERRUPTS_I


;* The exception data structure. This structure is passed in register a0
;* for exception hooks and is the one and only information source about
;* the exception. This structure will be deleted as soon as the exception
;* terminates, hence make a copy for private use if you need to pass it
;* over to someone else.

    STRUCTURE ExceptionData,0
        APTR            exd_Task                ;struct Task *
;* The task that caused the exception. Meaningless if this is the exception
;* handler of the (a) supervisor context. *

        APTR            exd_Context             ;struct MMUContext *
;* The context this exception is part of. *

        APTR            exd_Descriptor          ;ULONG *
;* The true physical hardware descriptor as seen by the MMU. In case of
;* an indirect descriptor, this points to the pointer, not to (your) page
;* descriptor itself. *

        APTR            exd_NextDescriptor      ;ULONG *
;* In case of a misaligned access, i.e. an access that passes a page
;* boundary, the descriptor of the second page involved in the access.
;* Otherwise identical to exd_Descriptor *

        APTR            exd_FaultAddress
;* The address that failed. *

        APTR            exd_NextFaultAddress
;* This is the final end address, inclusively, of a failed access.
;* Note that this might well be less than "exd_FaultAddress", e.g. if the
;* faulty instruction is a movem.l regs,-(ax).
;*
;* ABS(exd_FaultAdress-exd_NextFaultAddress)+1 is the size of the access
;* that failed. Usually 1, 2 and 4 for byte, word and longword accesses, but
;* other sizes are possible as well. In case you're writing a swapper daemon,
;* make sure you make all addresses within this range valid.


        ULONG           exd_UserData
;* User data for the first page in the failed access if available. This is
;* the block Id for swapped out pages. *

        ULONG           exd_NextUserData
;* User data for the second page in a misaligned access. Identical to
;* exd_UserData otherwise. *

        ULONG           exd_Data
;* CPU output pipeline, right justified, if available, i.e. if the page(s)
;* is (are) marked as MAPP_REPAIRABLE.
;* Can be modified for your code, provided you set the EXDF_READBACK flag
;* and the page is repairable. In this case, this data will be loaded back
;* to the input pipeline of the CPU. *

        APTR            exd_ReturnPC
;* The approximate PC of the faulted instruction. Note that the real PC
;* might differ due to instruction prefetch. The program is guaranteed
;* to continue the "right" PC, however.
;* In case you set the EXDF_CALL flag, this is the pointer to a routine that
;* will be called by the library in user mode, e.g. for posting a message
;* to the swapper daemon. *

        ULONG           exd_Flags
;* A flags field, see below for the definitions. *

        ULONG           exd_Properties
;* Properties of the accessed memory *

        ULONG           exd_NextProperties
;*Properties of the next descriptor, if misaligned *

        UBYTE           exd_internal
;* Do not read or write this byte. *

        UBYTE           exd_FunctionCode
;* The function code mask of the access. *

        BYTE            exd_Level
;* The level of the *exd_Descriptor responsible for the fault. "0" is the
;* level A, "1" is level B and so on. Note that this is different from how
;* the 680x0 MMUs count. *

        BYTE            exd_NextLevel
;* The level of the *exd_NextDescriptor in case of a misalgined access.
;* Identical to exd_Level otherwise. *

        STRUCT          exd_DataRegs,8*4
;* A copy of the data registers of the faulty program. For higher magic,
;* you *might* be able to modify these. *

        STRUCT          exd_AddrRegs,7*4
;* A copy of the address registers, a0 to a6. a7 is below. *

        APTR            exd_SSP
;* The supervisor stack pointer, points to the exception stack frame.
;* DO NOT touch this stack frame, this is the buisiness of the library. *

        APTR            exd_USP
;* The user stack pointer. *

        APTR            exd_SysBase     ;struct SysBase *
;* A cached copy of the exec.library base address. DO NOT access AbsExecBase
;* within an exception handler, this will be fatal. Use either a private
;* copy or this field. *

        APTR            exd_MMUBase     ;struct MMUBase *
;* The base of the mmu.library. *

        LABEL           exd_SIZE

;*************************************************************************
;* The flags set in exd_Flags, above. Note that there are more flags than
;* documented here, but DO NOT touch or interpret these.

;* input flags    (set by the exception handler)        *


EXDF_WRITE              equ     (1<<0)
EXDB_WRITE              equ     0
;* A faulty write if set. A read exception if reset.
;* A 060 read/modify/write access will invoke the exception handler twice.
;* Note that locked transfers (what is called a RMW-access on a 020 or 030)
;* are neither handled by the Amiga hardware nor the mmu.library software. *

EXDF_INSTRUCTION        equ     (1<<1)
EXDB_INSTRUCTION        equ     1
;* A faulty instruction access. This means specifically that you MAY NOT
;* provide read-back data. You've either to stop the task, or swap in a page.
;* Note that EXDF_WRITE and EXDF_INSTRUCTION are possible in case a faulty
;* program uses a "moves" instruction with the dfc register loaded with an
;* instruction function code. Note, too, that the os never tries to do that
;* and that this method is not supported by the mmu.library. *

EXDF_WRITEPROTECTED     equ     (1<<2)
EXDB_WRITEPROTECTED     equ     2
;* The fault was due to a write to a write protected page. *

EXDF_WRITEDATAUNKNOWN   equ     (1<<3)
EXDB_WRITEDATAUNKNOWN   equ     3
;* The mmu library could not get hold of the data actually written out,
;* exd_Data is invalid. Set pages to MAPP_REPAIRABLE to get write data. *

EXDF_SUPERVISOR         equ     (1<<6)
EXDB_SUPERVISOR         equ     6
;* The fault was due to access of a supervisor only page. *

EXDF_MISALIGNED         equ     (1<<8)
EXDB_MISALIGNED         equ     8
;* The access spawned more than one page in memory. *


;* The following flags are output flags. You may set them in your code and
;* they are respected by the library. *

EXDF_READBACK           equ     (1<<16)
EXDB_READBACK           equ     16
;* Fill the input pipeline of the CPU with the data in exd_Data, right
;* justified. *

EXDF_WRITECOMPLETE      equ     (1<<16)         ;* yes, the same number *
EXDB_WRITECOMPLETE      equ     16
;* The exception handler was able to perform the writeback of exd_Data,
;* the CPU should ignore the faulty write and continue execution.
;* If this bit is not set, the access is retried. *

EXDF_CALL               equ     (1<<17)
EXDB_CALL               equ     17
;* Call a routine in user mode, the address is given in exd_ReturnPC.
;* The access is retried as soon as this routine returns.
;* The user routine executes in user mode in the context of the task that
;* faulted and has full access to the multitasking machine of exec.
;* (This requires really a lot of meta-magic....).
;* Do NOT set EXDF_WRITECOMPLETED/EXDF_READBACK and EXDF_CALL at once, only
;* one of the two bits should be set. *


;* The next lines define the exception types, passed in for example to
;* AddContextHook(). This type determinates to which exception hook list
;* your hook will be added. *

MMUEH_SEGFAULT          equ     0
;* a segmentation fault, i.e. access of invalid or supervisor protected
;* memory, or writes to write-protected memory. *

MMUEH_SWAPPED           equ     1
;* access of memory that is marked as "swapped out". *

MMUEH_SWITCH            equ     $10
;* called whenever a task looses the CPU. This is task specific and requires
;* that the specific task has been entered a context explicitly. This holds
;* even for the public default context. *

MMUEH_LAUNCH            equ     $11
;* called whenever a task gains control over the CPU. *

MMUEH_PAGEACCESS        equ     $20
;* called on installation of a MAPP_SINGLE page. *


;* The next structure is the exception handler itself. Note that this is
;* *NOT* the full definition. This structure is really "internal use only"
;* you should not read or write it. It's only documented here for complete-
;* ness. *

        STRUCTURE ExceptionHook,IS_SIZE
        LABEL exh_SIZE

;* The next structure is sent to the "Catcher" port for the high-level
;* message hook mechanism. *

        STRUCTURE ExceptionMessage,MN_SIZE
        STRUCT exm_Exception,exd_SIZE
        LABEL exm_SIZE

;* If this is replied, then the access is retried and the faulty task is
;* continued. *


;* The PageAccessData structure
;* this is passed to a page access handler
;* in register a0, with your data in a1 and a4.
;* This is only called for MAPP_SINGLE pages, at the
;* page level.
;* The code is called in supervisor level, with all
;* interrupts disabled. *

        STRUCTURE PageAccessData,0
        ULONG                    pgad_Level
;* level of the tree that is getting build *

        APTR                     pgad_Address
;* the logical address this is build for *

        APTR                     pgad_Destination
;* where the descriptor will go to *

        APTR                     pgad_Context
;* the context this is build for *

        APTR                     pgad_MMUBase
;* The base of the mmu.library. *

        ULONG                    pgad_Properties
;* The properties for this descriptor *

        ULONG                    pgad_UserData
;* User data for the descriptor.
;* This is the user data for invalid/swapped pages,
;* the destination address for remapped pages and
;* the descriptor address for indirect pages. *
        LABEL                   pgad_SIZE


        ENDC    ;       MMU_EXCEPTIONS_I
