        IFND    MMU_ALERTS_I
MMU_ALERTS_I    SET     1
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
;** MMU library specific alerts                                         **
;**									**
;** $VER: 42.1 (08.04.2001)						**
;*************************************************************************


;* MMU library alert identifier *

AN_MMULib       equ     $3e000000

AN_NoUtility    equ     $3e02800c
;* Library init failed to open the utility library *

AN_NoExpansion  equ     $3e02800a
;* Library init failed to open the expansion library *

AN_ContextOpen  equ     $3e090001
;* while flushing the library, a context was still in use *

AN_BadFreePool  equ     $3e018005
;* the internal memory pool is damaged *

AN_NoPoolMem    equ     $3e018001
;* no memory to build the pool on lib init *

AN_NoContext    equ     $3e018002
;* failure building the context *

AN_MMUInit      equ     $3e000002
;* MMU Init vector failed *

AN_IllegalTT    equ     $3e000003
;* transparent translation mode unsupported *

AN_IllegalMMU   equ     $3e000004
;* MMU table layout not supported *

AN_BadContext   equ     $3e000005
;* the context contains unaligned mappings *

AN_BadTable     equ     $3e000006
;* the MMU table build by the library has been damaged *

AN_FreeActive   equ     $3e000007
;* someone tried to release an active context *

AN_MapHole      equ     $3e000008
;* the mapping defined in the context contains undefined areas *

AN_Phase        equ     $3e000009
;* while building the MMU tree, another context change was required *

AN_BuildError   equ     $3e00000a
;* the MMU table builder failed to build a lower level of the tree *

AN_ConfigBroken equ     $be00000b
;* the MMU configuration could not be setup, the parameters are invalid *

AN_NoRoot       equ     $3e00000c
;* someone tried to install a context without a valid root pointer *

AN_NoCatcher    equ     $3e00000d
;* the message exception handler did not find the destination catcher port
;* to pass the exceptions to *

AN_ExcptBusy    equ     $3e00000e
;* someone tried to release an exception that is currently busy *

AN_NotCaller    equ     $3e00000f
;* someone different than the caller tried to release the message hook *

AN_QueueDaemon  equ     $3e000073
;* the returned message from the daemon was not the expected one, i.e. the
;* message exception daemon replied an invalid message *

AN_LineWB       equ     $be000010
;* an unhandled line writeback that is not a physical fault.
;* Broken hardware ? *

AN_LineRB       equ     $be000011
;* an unhandled line fetch of invalid data that is not a physical fault.
;* Broken hardware ? *

AN_GhostMovem   equ     $be000012
;* the exception handler detected a movem fault without a movem. *

AN_CheckMMU     equ     $3e000013
;* LibInit CheckMMU failed miserably and could not repair the modified
;* test page.

AN_BadDMA       equ     $3e000014
;* Bad DMA transfer initiated
;* (destination not available or writeprotected)

AN_PostSetup    equ     $3e000015
;* an Os function re-defining the memory layout was called
;* after table setup

AN_NoMapMem 	equ	$3e000016
;* while allocating memory for the page tables, the library
;* found free non-RemapSize() aligned memory.

AN_NoMemMemList	equ	$3e000017
;* an AddMemList() failed due to an out of memory condition
;* of the library while rebuilding the MMU tables.

AN_NoMemAddConf	equ	$3e000018
;* an AddConfigDev() failed due to an out of memory condition
;* while mapping in the new hardware.

AN_ChildFreeTwice equ	$3e090009   
;* a child context was detached twice, 
;* use counter underrun.

AN_BadShare	equ	$3e001005
;* A MAPP_SHARE of a non-shared context was found on the
;* MMU table rebuild.

AN_NoResExp	equ	$3e12800a
;* can't find the resident module of the 
;* expansion library.

        ENDC    ; MMU_ALERTS.I

