#ifndef RESOURCES_FSLDMA_H
#define RESOURCES_FSLDMA_H 1
/*
** fsldma.resource include file
**
** Copyright 2019,2021 Trevor Dickinson.
*/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#include <utility/tagitem.h>
#include <exec/types.h>

#define FSLDMA_NAME "fsldma.resource"

// Define maximum single data block size the DMA hardware
// can handle without chaining transactions
#define FSLDMA_MAXBLOCK_SIZE   ((64 * 1024 * 1024) - 1)

// Define the maximum optimal single data block size the DMA hardware
// can handle without chaining transactions.
#define FSLDMA_OPTIMAL_BLKSIZE ((64 * 1024 * 1024) - 64)

// Define Memory Attributes needed when working with
// Physical memory buffers
#define FSLDMA_PHYMEM_ATTRS (uint32)(MEMATTRF_CACHEINHIBIT | MEMATTRF_COHERENT | MEMATTRF_GUARDED)

//
// Tags for CopyMemDMATagList() / CopyMemDMATags()
//
#define FSLDMA_DUMMY (TAG_USER + 0xF51D0A)

//
// Tags for Notification, asynchronous "non-blocking" features
//
#define FSLDMA_CM_DoNotWait                 (FSLDMA_DUMMY + 1)
// (BOOL)
//   If set to TRUE, the DMA Copy will start and
//   return immediately. See the "Notify" tags
//   below if you wish to be notified that the
//   requested copy has been completed.
//
//   If you do not also set at least FSLDMA_CM_NotifyTask
//   and FSLDMA_CM_NotifySignalNumber, then the caller
//   will *not* be notify when the copy is complete.
//
//   This is effectively "spray-and-pray" mode,
//   where the caller only needs to queue up DMA
//   transfers, but does not care when (or if) they
//   have completed.

#define FSLDMA_CM_NotifyTask                (FSLDMA_DUMMY + 2)
// (struct Task *)
//   Provide the Task to be Signaled upon completion,
//   error, or status changes.

#define FSLDMA_CM_NotifySignalNumber        (FSLDMA_DUMMY + 3)
// (int8)
//   Provide the Signal Number to be sent
//   upon the successful completion of the
//   entire transfer.
//
//   Requires FSLDMA_CM_NotifyTask to be set
//   or silently does nothing.

#define FSLDMA_CM_NotifyProgessSignalNumber (FSLDMA_DUMMY + 4)
// (int8)
//   Provide the Signal Number to be sent
//   upon the successful completion of one
//   sub-block of the total transfer.
//
//   Requires FSLDMA_CM_NotifyTask to be set
//   or silently does nothing.

#define FSLDMA_CM_NotifyErrorSignalNumber   (FSLDMA_DUMMY + 5)
// (int8)
//   Provide the Signal Number to be sent
//   upon an error in the requested transfer.
//
//   Requires FSLDMA_CM_NotifyTask to be set
//   or silently does nothing.

// Specifying FSLDMA_CM_NotifyTask and at least
// one of the "Signal Number" tags, will automatically
// also set FSLDMA_CM_DoNotWait to TRUE.

//
// Tags for Passing Physical Addresses for buffer pointers
//

// When either the Source or Destination addresses
// being provided to the DMA needs to be supplied
// as a Physical Address instead of a Virtual one,
// use the one or both of the following Tags.

// This may be the case if the source or destination
// (or both) is either a hardware I/O location or
// points to an area of contiguous, cache-inhibited
// memory.

#define FSLDMA_CM_SourceIsPhysical          (FSLDMA_DUMMY + 6)
// (BOOL)
//     If this tag is provided and set to TRUE,
//     then the pointer to the source buffer
//     (pSourceBuffer) will be treated as a
//     Physical address and will not be handled
//     using StartDMA()/EndDMA().
//
//     Therefore, the Physical Memory address
//     provided must point to contiguous hardware
//     I/O space or a contiguous, cache-inhibited
//     memory buffer.

#define FSLDMA_CM_DestinationIsPhysical     (FSLDMA_DUMMY + 7)
// (BOOL)
//     If this tag is provided and set to TRUE,
//     then the pointer to the destination buffer
//     (pDestBuffer) will be treated as a
//     Physical address and will not be handled
//     using StartDMA()/EndDMA().
//
//     Therefore, the Physical Memory address
//     provided must point to contiguous hardware
//     I/O space or a contiguous, cache-inhibited
//     memory buffer.

#define FSLDMA_CM_NotifyHook                (FSLDMA_DUMMY + 9)
// (struct Hook *)
//     If this tag is provided then the Hook structure
//     is called based on the provided NotifyHookFlags.
//
//     The Notify Hook is separate from the Notify signals
//     and as such does not require FSLDMA_CM_NotifyTask
//     to be provided.

#define FSLDMA_CM_NotifyHookFlags           (FSLDMA_DUMMY + 10)
// (uint32)
//     This tag is used to request which notification
//     events should call the Notify Hook.
//
//     FSLDMA_CM_NotifyHook must be provided with
//     a pointer to a proper Hook structure.
//
//     This tags defaults to call the Hook on completion
//     or error events.
//
//     The possible values for this tag are listed below.

// Define the Notify Flags for use with Notify Hook calls.
// Provide one or more of the Flags below to request
// the provided Hook function be called on the corresponding event.
//
// Upon the call to the provided Hook Function,
// one of the above values will be pass into the message variable
#define FSLDMA_NF_COMPLETE   0x00000001 // Call Hook function on "DMA Chain completed successfully"
#define FSLDMA_NF_INPROGRESS 0x00000002 // Call Hook function on "Sub-block completed successfully"
#define FSLDMA_NF_ERROR      0x00000004 // Call Hook function on "Error occurred"
#define FSLDMA_NF_COMMON     (FSLDMA_NF_COMPLETE | FSLDMA_NF_ERROR)
#define FSLDMA_NF_ALL        (FSLDMA_NF_COMMON | FSLDMA_NF_INPROGRESS)

//
// Tag for obtaining more details about the
// success or failure to start a DMA transaction
//

#define FSLDMA_CM_ResultCode                (FSLDMA_DUMMY + 11)
// (uint32 *)
//     If a pointer to a uint32 variable is provided using
//     this tag, then the specific DMA Transaction Result Code
//     will be filled into that memory location.
//
//     This tag is optional but provides a good way to
//     determine why the requested DMA transaction may
//     have returned before it was started.
//
//     The most common use of this tag is to determine
//     why the API call (eg. CopyMemDMATags()) returned
//     during setup.
//
//     The possible DMA Result Code values are listed below.

#define FSLDMA_RC_STARTED  0x00000000 // The DMA transaction was started successfully*
#define FSLDMA_RC_BUSY     0x00000001 // The transaction was not started because all DMA Channels are currently busy. Try the call again.
#define FSLDMA_RC_PRGERROR 0x00000002 // The transaction could not start because missing or incorrect arguments were provided
#define FSLDMA_RC_HALTED   0x00000004 // The DMA transaction was halted (most likely in response to an Abort request)
#define FSLDMA_RC_TRANSERR 0x00000005 // The DMA transaction failed to complete, a transfer error occurred
#define FSLDMA_RC_UNKNOWN  0xFFFFFFFF // Since 0 == success, use this to initialize the result code to start

// *The FSLDMA_CM_ResultCode will be set to FSLDMA_RC_STARTED when
//  either a "blocking" request was completed without error, or
//  when a "non-blocking" request was successfully started and is
//  currently running. See the FSLDMA_CM_Notify tags for details
//  about capturing the results from "non-blocking" transactions. 

//
// Tags for setting the Upper (high order) 32-Bits
// of the source and/or destination buffer pointers.
//
// If present, the values of these tags will be combined
// with the virtual or physical source and/or destination
// pointers that are provided as arguments to the main
// API call (eg. CopyMemDMATags())
//

#define FSLDMA_CM_SourceUpper               (FSLDMA_DUMMY + 12)
// (uint32)
// If the location of the Source Buffer is found at a memory
// address greater than 4GB (lower 32-Bits) then the upper
// 32-bits of the address may be set with this tag.
//
// For example if:
//   pSourceBuffer         = 0x0001FEE0
//   FSLDMA_CM_SourceUpper = 0x00CE0000
// then the address of the source buffer passed to the DMA would be:
//   0x00CE00000001FEE0

#define FSLDMA_CM_DestUpper                 (FSLDMA_DUMMY + 13)
// (uint32)
// If the location of the Destination Buffer is found at a memory
// address greater than 4GB (lower 32-Bits) then the upper
// 32-bits of the address may be set with this tag.
//
// For example if:
//   pDestBuffer         = 0x0021FEA0
//   FSLDMA_CM_DestUpper = 0x000000FE
// then the address of the source buffer passed to the DMA would be:
//   0x000000FE0021FEA0

// This structure describes the format of the link descriptors.
// Figure 20-10. Link descriptor format
// for use with StartDMAChain()
struct dma_link_descriptor
{
  uint32 dmalink_lSourceAttrs;               // [0x00] Source Attributes
  uint32 dmalink_pSourceAddr;                // [0x04] Source Address
  uint32 dmalink_lDestinationAttrs;          // [0x08] Destination Attributes
  uint32 dmalink_pDestinationAddr;           // [0x0C] Destination Address
  uint32 dmalink_pNextLinkDescriptorExtAddr; // [0x10] Next Link Descriptor Extended Address
  uint32 dmalink_pNextLinkDescriptorAddr;    // [0x14] Next Link Descriptor Address
  uint32 dmalink_lByteCount;                 // [0x18] Byte Count
  uint32 dmalink_r1c;                        // [0x1C] Reserved
} __attribute__ ((packed));

// These values are used in setting up the above structure
#define FSLDMA_SET_SATR  0x00050000 // Sets Read Type to (Read, Snoop), and the upper 4 bits of extended source address to 0x0 (Bits 33-36), and disables Stride Mode
#define FSLDMA_SET_DATR  0x00050000 // Sets Write Type to (Write, Snoop), and the upper 4 bits of extended destination address to 0x0 (Bits 33-36), and disables Stride Mode
#define FSLDMA_SATR_MASK 0x0000000F // Extended source address. ESAD represents the four high-order bits of the 36-bit source address.
#define FSLDMA_DATR_MASK 0x0000000F // Extended destination address. EDAD represents the four high-order bits of the 36-bit destination address.
#define FSLDMA_EOL_FLAG  0x00000001 // Sets End-of-Links in the dmalink_pNextLinkDescriptorAddr field of the last entry in the array

//
// fsldma resource will call this function using IUtility->CallHookPkt()
// when both FSLDMA_CM_NotifyHook and FSLDMA_CM_NotifyHookFlags flags are set.
// (See the AutoDoc on IUtility->CallHookPkt() for more details)
//
// struct Hook *hook        = Pointer the Hook object specified with FSLDMA_CM_NotifyHook
// uint32 lDMATransactionID = The transction ID this callback is about
// uint32 lNotifyFlag       = The event; FSLDMA_NF_COMPLETE, FSLDMA_NF_INPROGRESS or FSLDMA_NF_ERROR
//                            that occurred for this transaction
//
uint32 notifyHookFunction( struct Hook *hook, uint32 lDMATransactionID, uint32 lNotifyFlag );

// Types needed for 64-Bit DMA functions
//
// We use the "uint64" type, instead of "uint64 *"
// in order to force the 32-Bit complier to build
// full 8 byte (64-Bit) parameters for the API calls.
//
// Once the SDK's complier is built for 64-Bit PPC
// targets, then these types can become the more
// proper "uint64 *"
//
typedef uint64 DMAPTR;
typedef const uint64 CONST_DMAPTR;

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif
