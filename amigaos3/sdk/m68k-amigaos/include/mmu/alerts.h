/*************************************************************************
 ** mmu.library                                                         **
 **                                                                     **
 ** a system library for arbitration and control of the MC68K MMUs      **
 **                                                                     **
 ** © 1999,2000 THOR-Software, Thomas Richter                           **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** MMU library specific alerts                                         **
 **									**
 ** $VER: 42.1 (08.04.2001)						**
 *************************************************************************/

#ifndef MMU_ALERTS_H
#define MMU_ALERTS_H

/* MMU library alert identifier */

#define AN_MMULib   0x3e000000

#define AN_NoUtility 0x3e02800c   
/* Library init failed to open the utility library */

#define AN_NoExpansion 0x3e02800a   
/* Library init failed to open the expansion library */

#define AN_ContextOpen 0x3e090001   
/* while flushing the library, a context was still in use */

#define AN_BadFreePool 0x3e018005   
/* the internal memory pool is damaged */

#define AN_NoPoolMem 0x3e018001   
/* no memory to build the pool on lib init */

#define AN_NoContext 0x3e018002   
/* failure building the context */

#define AN_MMUInit 0x3e000002   
/* MMU Init vector failed */

#define AN_IllegalTT 0x3e000003   
/* transparent translation mode unsupported */

#define AN_IllegalMMU 0x3e000004   
/* MMU table layout not supported */

#define AN_BadContext 0x3e000005
/* the context contains unaligned mappings */

#define AN_BadTable 0x3e000006
/* the MMU table build by the library has been damaged */

#define AN_FreeActive 0x3e000007
/* someone tried to release an active context */

#define AN_MapHole 0x3e000008
/* the mapping defined in the context contains undefined areas */

#define AN_Phase 0x3e000009
/* while building the MMU tree, another context change was required */

#define AN_BuildError 0x3e00000a
/* the MMU table builder failed to build a lower level of the tree */

#define AN_ConfigBroken 0xbe00000b
/* the MMU configuration could not be setup, the parameters are invalid */

#define AN_NoRoot 0x3e00000c
/* someone tried to install a context without a valid root pointer */

#define AN_NoCatcher 0x3e00000d
/* the message exception handler did not find the destination catcher port
   to pass the exceptions to */

#define AN_ExcptBusy 0x3e00000e
/* someone tried to release an exception that is currently busy */

#define AN_NotCaller 0x3e00000f
/* someone different than the caller tried to release the message hook */

#define AN_QueueDaemon 0x3e000073
/* the returned message from the daemon was not the expected one, i.e. the
   message exception daemon replied an invalid message */

#define AN_LineWB 0xbe000010   
/* an unhandled line writeback that is not a physical fault.
   Broken hardware ? */

#define AN_LineRB 0xbe000011   
/* an unhandled line fetch of invalid data that is not a physical fault.
   Broken hardware ? */

#define AN_GhostMovem 0xbe000012 
/* the exception handler detected a movem fault without a movem. */

#define AN_CheckMMU 0x3e000013
/* LibInit CheckMMU failed miserably and could not repair the modified
   test page. */

#define AN_BadDMA 0x3e000014
/* Bad DMA transfer initiated
   (destination not available or writeprotected) */

#define AN_PostSetup 0x3e000015
/* an Os function re-defining the memory layout was called
   after table setup */

#define AN_NoMapMem  0x3e000016
/* while allocating memory for the page tables, the library
   found free non-RemapSize() aligned memory. */

#define AN_NoMemMemList 0x3e000017
/* an AddMemList() failed due to an out of memory condition
   of the library while rebuilding the MMU tables. */

#define AN_NoMemAddConf 0x3e000018
/* an AddConfigDev() failed due to an out of memory condition
   while mapping in the new hardware. */

#define AN_ChildFreeTwice 0x3e090009   
/* a child context was detached twice, 
   use counter underrun. */

#define AN_BadShare 0x3e001005
/* A MAPP_SHARE of a non-shared context was found on the
   MMU table rebuild. */

#define AN_NoResExp 0x3e12800a
/* can't find the resident module of the 
   expansion library */


#endif
