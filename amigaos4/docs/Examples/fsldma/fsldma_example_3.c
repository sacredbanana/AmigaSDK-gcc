/*
 * fsldma_example_3.c
 *
 * Copyright 2021 Trevor Dickinson. All rights reserved.
 *
 * This file is part of ExecSG.
 * Licensed under the ExecSG license.
 * See the LICENSING file for details.
 *
 * :ts=4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <amiga_compiler.h>
#include <exec/exec.h>
#include <devices/timer.h>
#include <proto/exec.h>
#include <proto/timer.h>
#include <dos/dos.h>
#include <interfaces/exec.h>
#include <interfaces/fsldma.h>
#include <resources/fsldma.h>

// Timer Object structure
//  for use with openTimerDevice()
//  and closeTimerDevice()
struct TimerObject
{
    struct MsgPort     *pTimerMsgPort;
    struct TimeRequest *pTimerIOReq;
    struct Library     *pTimerBase;
    struct TimerIFace  *pITimer;
    struct TimeVal     oTimeValStart; // TimeVal structure for storing the start time of the transfer
    struct TimeVal     oTimeValEnd;   // TimeVal structure for storing the end time of the transfer
};

#define NUM_SUB_BLOCKS 5                       // Set the number of sub-blocks to 5
#define SUB_BLOCK_SIZE FSLDMA_OPTIMAL_BLKSIZE  // Set the sub-block size to ~64 Megabytes (largest optimal block size)
#define TOTAL_AREA_SIZE (NUM_SUB_BLOCKS * SUB_BLOCK_SIZE)

struct dma_link_descriptor * AllocateDMAChain( uint32 lBufferSize );
uint32                       InitializeDMAChain( struct dma_link_descriptor *pDMALinkDescriptor, CONST_APTR pPhysicalSourceBuffer, APTR pPhysicalDestBuffer, uint32 lBufferSize );
void                         FreeDMAChain( struct dma_link_descriptor *pDMALinkDescriptor );

struct TimerObject * openTimerDevice( enum enTimerUnits nTimerUnit );
void   closeTimerDevice( struct TimerObject *pTimerObj );
BOOL   verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize );

struct Task *gpSignalTask = NULL;

// fsldma.resource Example 3, "Non-blocking" DMA Copy
// test of Chain of DMA memory copies, using user
// notifications and Physical memory areas
int main(int argc, char *argv[])
{
  struct ExecBase    *ExecBase     = (*(struct ExecBase **)4);
  struct ExecIFace   *IExec        = NULL;
  struct fslDMAIFace *IfslDMA      = NULL;
  CONST_APTR         pSrcArea      = NULL;
  APTR               pDestArea     = NULL;
  BOOL               bGotResources = FALSE;

  // Set Verify Flag
  BOOL bVerifyTest = FALSE;
  if ( argc > 1 )
  {
    char *sVerifyArg = argv[1];
    if ( strlen(sVerifyArg) >= 2 )
    {
      if ( ('-' == sVerifyArg[0]) && ('v' == sVerifyArg[1]) )
      {
        bVerifyTest = TRUE;
      }
    }
  }

  struct dma_link_descriptor *pDMALinkArray = NULL;
  struct Hook                *pNotifyHook   = NULL;

  uint32 lNotifyHookFlags = FSLDMA_NF_ALL;    // Request "Complete", "In Progress" and "Error" notifications
  //uint32 lNotifyHookFlags = FSLDMA_NF_COMMON; // Request "Complete" and "Error" notifications only

  uint32 lNumberOfSegments = 0;
  uint32 lAreaSize         = TOTAL_AREA_SIZE;

  // Verify we are running the required kernel
  IExec = (struct ExecIFace *)ExecBase->MainInterface;
  struct Library *execLibNode = &ExecBase->LibNode;
  if ( !LIB_IS_AT_LEAST(execLibNode,54,41) )
  {
    // We are not running the minimum needed kernel version. Abort.
    printf("This program requires kernel version 54.41 or newer. Aborted test.\n");
    return( 1 );
  }

  // Display setup message
  printf("Setting up DMA Chaining Transaction with %ld blocks of %ld bytes, totaling %ld.\n",lNumberOfSegments,(uint32)SUB_BLOCK_SIZE,lAreaSize);

  // Obtain the pointer to ourself
  gpSignalTask = IExec->FindTask(NULL);

  // Obtain the fsldma.resource
  IfslDMA = IExec->OpenResource(FSLDMA_NAME);

  // Timer object structure populated by openTimerDevice()
  struct TimerObject *pTimerObj = NULL;
  pTimerObj = openTimerDevice(UNIT_MICROHZ);

  // Allocate a test source buffer (fill with some data)
  pSrcArea  = IExec->AllocVecTags(lAreaSize,
                                  AVT_Type,              MEMF_SHARED,
                                  AVT_Contiguous,        TRUE,
                                  AVT_Lock,              TRUE,
                                  AVT_Alignment,         64,
                                  AVT_PhysicalAlignment, 64,
                                  AVT_ClearWithValue,    0xB3,
                                  TAG_DONE);

  // Allocate a test destination buffer (clear with zeroes)
  pDestArea = IExec->AllocVecTags(lAreaSize,
                                  AVT_Type,              MEMF_SHARED,
                                  AVT_Contiguous,        TRUE,
                                  AVT_Lock,              TRUE,
                                  AVT_Alignment,         64,
                                  AVT_PhysicalAlignment, 64,
                                  AVT_ClearWithValue,    0,
                                  TAG_DONE);

  // Allocate a DMA Link descriptor array (clear with zeroes)
  // Large enough to contain a DMA Link Descriptor for each sub-block
  pDMALinkArray = (struct dma_link_descriptor *)AllocateDMAChain(lAreaSize);

  // Allocate our Notification Hook
  pNotifyHook = (struct Hook *)IExec->AllocSysObjectTags(ASOT_HOOK,
                                                         ASOHOOK_Entry, notifyHookFunction,
                                                         TAG_DONE);

  // Verify we got all resources needed for the test
  if ( (NULL != IfslDMA)       &&
       (NULL != pSrcArea)      && (NULL != pDestArea)   &&
       (NULL != pDMALinkArray) && (NULL != pNotifyHook) &&
       (NULL != pTimerObj)                              )
  {
    bGotResources = TRUE;
  }

  if ( TRUE == bGotResources )
  {
    // Initialize the DMA Link Array for use
    lNumberOfSegments = InitializeDMAChain(pDMALinkArray,pSrcArea,pDestArea,lAreaSize);

    // Call IfslDMA->CopyMemDMATags() to perform the memory copy using the
    // DMA hardware. Start off the transaction then wait on completion signals.

    printf("Starting \"Non-Blocking\" DMA Chain Transaction\n"
           " of %ld Bytes containing %ld blocks from\n"
           " 0x%08lx to 0x%08lx using DMA Link Array at 0x%08lx...\n",
           lAreaSize,lNumberOfSegments,pSrcArea,pDestArea,pDMALinkArray);
    fflush(stdout);

    // Reset and start the timer
    pTimerObj->oTimeValStart.Seconds      = 0;
    pTimerObj->oTimeValStart.Microseconds = 0;
    pTimerObj->oTimeValEnd.Seconds        = 0;
    pTimerObj->oTimeValEnd.Microseconds   = 0;
    pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart); // Get Start time before the copy

    uint32 lDMAResultCode   = FSLDMA_RC_UNKNOWN;
    BOOL   bStartDMAResults = FALSE;
    // Call the IfslDMA->StartDMAChain() function
    bStartDMAResults = IfslDMA->StartDMAChainTags(pDMALinkArray,
                                                  FSLDMA_CM_NotifyHook,      (uint32)pNotifyHook,
                                                  FSLDMA_CM_NotifyHookFlags, (uint32)lNotifyHookFlags,
                                                  FSLDMA_CM_ResultCode,      (uint32)&lDMAResultCode,
                                                  FSLDMA_CM_DoNotWait,       TRUE,
                                                  TAG_DONE);
    if ( TRUE == bStartDMAResults )
    {
      // The DMA Transaction started successfully
      printf("DMA Chain Transaction has started...\n");
      fflush(stdout);

      // If the above call sets up correctly, it returns immeditately
      // So do something here *while* the data is being copied...
      printf("Doing other stuff before waiting...\n");
      fflush(stdout);

      // Now we will Wait() for the completion signals from the DMA
      BOOL   bStillRunning    = TRUE;
      uint32 lSigReceived     = 0;
      uint32 lSubBlockCounter = 0;
      uint32 lWaitOnSignals   = (SIGBREAKF_CTRL_D | SIGBREAKF_CTRL_E |SIGBREAKF_CTRL_F | SIGBREAKF_CTRL_C);
      do
      {
        // Wait for the DMA completion/status/error signals
        printf("Waiting for signals...\n");
        fflush(stdout);
        lSigReceived = IExec->Wait( lWaitOnSignals );

        // Check if we got a "In Progress" signal
        if ( SIGBREAKF_CTRL_E == (lSigReceived & SIGBREAKF_CTRL_E) )
        {
          lSubBlockCounter++; // Increment the number of completed sub-blocks
          printf("DMA Chain Transaction has completed %ld out of %ld blocks...\n",
                 lSubBlockCounter,lNumberOfSegments);
        }

        // Check if we got a "Transaction Complete" signal
        if ( SIGBREAKF_CTRL_D == (lSigReceived & SIGBREAKF_CTRL_D) )
        {
          // Calculate and display the elapsed time
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
          pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);

          // If a completion signal was received before all
          // the subblock statuses were displayed, then output
          // the remaining updates first.
          if ( lSubBlockCounter < lNumberOfSegments )
          {
            for( ++lSubBlockCounter; lSubBlockCounter <= lNumberOfSegments; lSubBlockCounter++ )
            {
              printf("DMA Chain Transaction has completed {%ld} out of {%ld} blocks...\n",
                     lSubBlockCounter,lNumberOfSegments);
            }
          }

          // Now output the completion status
          printf("\nDMA Chain Transaction completed transfering %ld bytes successfully\n",lAreaSize);
          printf(" in %ld Seconds and %ld Microseconds.\n",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
          bStillRunning = FALSE;
        }

        // Check if we got a "Error" signal
        if ( SIGBREAKF_CTRL_F == (lSigReceived & SIGBREAKF_CTRL_F) )
        {
          printf("DMA Chain Transaction Failed!\n");
          bStillRunning = FALSE;
        }

        // Finally, check if we got a Break signal from the user
        // just in case we want to quit out early for some reason
        if ( SIGBREAKF_CTRL_C == (lSigReceived & SIGBREAKF_CTRL_C) )
        {
          printf("Received an \"User break\" signal, ending.\n");
          bStillRunning = FALSE;
        }

        // Do more stuff *while* the data is being copied...
        if ( TRUE == bStillRunning )
        {
          printf("Doing other stuff while waiting...\n");
        }

      } while( TRUE == bStillRunning );

      // Verify the destination matches the source
      if ( TRUE == bVerifyTest )
      {
        printf("Verifing Transfer of %ld bytes from %p to %p...",lAreaSize,pSrcArea,pDestArea);
        fflush(stdout);
        BOOL bVerified = verifyIdentical(pSrcArea,pDestArea,lAreaSize);
        printf("%s\n",(TRUE == bVerified) ? "OK" : "FAILED!");
      }
    }
    else
    {
      printf("The DMA Chain Transaction failed to start");
      fflush(stdout);
      switch( lDMAResultCode )
      {
        case FSLDMA_RC_BUSY:
        {
          printf(" because all DMA Channels are currently busy. Try again\n");
        }
        break;
        
        case FSLDMA_RC_PRGERROR:
        {
          printf(" because incorrect values were provided.\nCheck the initialization of the DMA Link Descriptor Array is correct.\n");
        }
        break;
        
        case FSLDMA_RC_HALTED:
        {
          printf(" because the selected DMA Channel was Halted.\nThis is normally the result of an Abort being sent.\n");
        }
        break;
        
        case FSLDMA_RC_TRANSERR:
        {
          printf(" because all selected DMA Channel encountered an error during the transaction.\nCheck the initialization of the DMA Link Descriptor Array is correct.\n");
        }
        break;
        
        case FSLDMA_RC_UNKNOWN:
        default:
        {
          printf(" because of an unknown error.\n"); // This should not happen
        }
      }
    }
  }
  else
  {
    printf("Failed to obtain resources, aborting test.\n");
  }

  // Clear our global Task pointer
  gpSignalTask = NULL;

  // Free our test buffers (as needed)
  if ( NULL != pTimerObj     ) closeTimerDevice(pTimerObj);
  if ( NULL != pSrcArea      ) IExec->FreeVec((APTR)pSrcArea);
  if ( NULL != pDestArea     ) IExec->FreeVec(pDestArea);
  if ( NULL != pDMALinkArray ) FreeDMAChain(pDMALinkArray);
  if ( NULL != pNotifyHook   ) IExec->FreeSysObject(ASOT_HOOK,pNotifyHook);
}

//
// Functions to aid in the allocation and setup of
// a suitable DMA Link Array for passing to the
// StartDMAChain() API call
//

//
// Allocate a DMA Link Array from the supplied size
//
struct dma_link_descriptor * AllocateDMAChain(uint32 lBufferSize)
{
  struct dma_link_descriptor *pDMALinkArray = NULL;
  uint32 lNumberOfSegments = 0;
  if ( lBufferSize > 0 )
  {
    // Determine the number of Links that with be needed
    if ( lBufferSize <= FSLDMA_OPTIMAL_BLKSIZE )
    {
      // The transfer size fits within a single segment,
      // so set the number of segments to 1.
      lNumberOfSegments = 1;
    }
    else
    {
      // The transfer size will take more than one segment,
      // so divide it by the FSLDMA_OPTIMAL_BLKSIZE value
      // to determine the number of segment links we will need.
      lNumberOfSegments = (lBufferSize / FSLDMA_OPTIMAL_BLKSIZE);
      if ( 0 != (lBufferSize - (lNumberOfSegments * FSLDMA_OPTIMAL_BLKSIZE)) )
      {
        // We have a partial block remaining, so add 1 to the count
        lNumberOfSegments++;
      }
    }
      
    // Now use the Number of required segments to
    // allocate a DMA Link descriptor array (clear with zeroes),
    // large enough to contain a DMA Link Descriptor for each sub-block
    uint32 lDMALinkArraySize = lNumberOfSegments * sizeof(struct dma_link_descriptor);
    pDMALinkArray = (struct dma_link_descriptor *)IExec->AllocVecTags(lDMALinkArraySize,
                                                                      AVT_Type,              MEMF_SHARED,
                                                                      AVT_Contiguous,        TRUE,
                                                                      AVT_Lock,              TRUE,
                                                                      AVT_Alignment,         32,
                                                                      AVT_PhysicalAlignment, 32,
                                                                      AVT_ClearWithValue,    0,
                                                                      TAG_DONE);
  }
  // Return the allocated array (or NULL)
  return( pDMALinkArray );
}

//
// Initialize the supplied DMA Link Array using the buffer size, source and destination pointers.
// On success returns the number of segments (blocks) that will be used for the transaction.
//
uint32 InitializeDMAChain(struct dma_link_descriptor *pDMALinkArray, CONST_APTR pSourceBuffer, APTR pDestBuffer, uint32 lBufferSize)
{
  uint32     lNumberOfSegments = 0;
  uint32     lUpperSourceAddr  = 0;
  uint32     lLowerSourceAddr  = 0;
  uint32     lUpperDestAddr    = 0;
  uint32     lLowerDestAddr    = 0;
  uint32     lDMASetSATR       = 0;
  uint32     lDMASetDATR       = 0;
  uint32     lBlockSize        = 0;
  uint32     lLastBlockSize    = 0;
  CONST_APTR pPhySrcArea       = NULL;
  APTR       pPhyDstArea       = NULL;
  APTR       pPhyDMALinkArray  = NULL;

  struct ExecBase *ExecBase    = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU        = NULL;
  
  if ( NULL != pDMALinkArray )
  {
    if ( (0 != pSourceBuffer) && (0 != pDestBuffer) && (lBufferSize > 0) )
    {
      // Obtain the MMU Interface
      IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,
                                                    "MMU",1,NULL);
      if ( NULL == IMMU ) return( 0 );
      
      // Determine the number of Links that with be needed
      if ( lBufferSize <= FSLDMA_OPTIMAL_BLKSIZE )
      {
        // The transfer size fits within a single segment,
        // so set the number of segments to 1.
        lNumberOfSegments = 1;
        lBlockSize     = (lBufferSize < FSLDMA_OPTIMAL_BLKSIZE) ? lBufferSize : FSLDMA_OPTIMAL_BLKSIZE;
        lLastBlockSize = lBlockSize;
      }
      else
      {
        // The transfer size will take more than one segment,
        // so divide it by the FSLDMA_OPTIMAL_BLKSIZE value
        // to determine the number of segment links we will need.
        lNumberOfSegments = (lBufferSize / FSLDMA_OPTIMAL_BLKSIZE);
        lBlockSize        = FSLDMA_OPTIMAL_BLKSIZE;
        lLastBlockSize    = lBlockSize; // Last block size starts out the same as block size
        uint32 lRemainder = (lBufferSize - (lNumberOfSegments * lBlockSize));
        if ( lRemainder != 0 )
        {
          // We have a partial block remaining, so add 1 to the count
          lNumberOfSegments++;
          // Also (re)set the size of the last block to the remainder
          lLastBlockSize = lRemainder;
        }
      }

      // Get the Virtual and Physical pointers to the start of the DMA Descriptor Links Array
      // Enter Supervisor Mode
      APTR pUserStack = IExec->SuperState();
  
      // Get the Physical addresses for our two buffers
      pPhySrcArea      = IMMU->GetPhysicalAddress((APTR)pSourceBuffer);
      pPhyDstArea      = IMMU->GetPhysicalAddress(pDestBuffer);
      pPhyDMALinkArray = IMMU->GetPhysicalAddress((APTR)pDMALinkArray);
  
      // Return to User Mode
      if ( NULL != pUserStack ) IExec->UserState(pUserStack);

      // Initialize the DMA Description Array with the
      // pointers and size of each sub-block we need to copy
      uint8 *pPhysicalSrcArea   = (uint8 *)pPhySrcArea;
      uint8 *pPhysicalDstArea   = (uint8 *)pPhyDstArea;
      uint8 *pNextDMADescriptor = (uint8 *)pPhyDMALinkArray + sizeof(struct dma_link_descriptor);
      for( uint32 i = 0; i < lNumberOfSegments; i++ )
      {
        // Setup both upper and lower 32-Bits of the active source and destination addresses
        lUpperSourceAddr = 0L; // (uint32)(pPhysicalSrcArea >> 32); // Since we are using 32-Bit pointers, this remains zero(0)
        lLowerSourceAddr = (uint32)pPhysicalSrcArea;
        lUpperDestAddr   = 0L; // (uint32)(pPhysicalDstArea >> 32); // Since we are using 32-Bit pointers, this remains zero(0)
        lLowerDestAddr   = (uint32)pPhysicalDstArea;

        // Add the upper 4-bits of the 36-Bit address for the working source and destination pointers
        lDMASetSATR = (uint32)(FSLDMA_SET_SATR | (lUpperSourceAddr & FSLDMA_SATR_MASK) );
        lDMASetDATR = (uint32)(FSLDMA_SET_DATR | (lUpperDestAddr & FSLDMA_DATR_MASK) );

        // Populate the next DMA Link Descriptor's fields with the current block data
        pDMALinkArray[i].dmalink_lSourceAttrs               = lDMASetSATR;        // Sets Read Type to (Read, Snoop), and the upper 4 bits of extended source address to 0x0000 (Bits 33-36), and disables Stride Mode
        pDMALinkArray[i].dmalink_pSourceAddr                = lLowerSourceAddr;   // Sets the lower (Bits 0-31) source address
        pDMALinkArray[i].dmalink_lDestinationAttrs          = lDMASetDATR;        // Sets Write Type to (Write, Snoop), and the upper 4 bits of extended destination address to 0x0000 (Bits 33-36), and disables Stride Mode
        pDMALinkArray[i].dmalink_pDestinationAddr           = lLowerDestAddr;     // Sets the lower (Bits 0-31) destination address
  
        // Start by assuming this is *not* the last link in the chain
        // (set next DMA Link Descriptor address without the EOL Flag)
        pDMALinkArray[i].dmalink_pNextLinkDescriptorExtAddr = (uint32)0;                  // Upper 4 Bits (33-36) of the Next Link Descriptor's address
        pDMALinkArray[i].dmalink_pNextLinkDescriptorAddr    = (uint32)pNextDMADescriptor; // Address (Lower 32 bits) of the pointer to the next DMA Link Descriptor (0 = None)
        pDMALinkArray[i].dmalink_lByteCount                 = (uint32)lBlockSize;         // Sets the number of bytes to copy
  
        // This is the last DMA Link Descriptor entry,
        // so set the EOL flag on this Next Link Addr field
        if ( i == (lNumberOfSegments - 1) )
        {
          // Setup the link to the next DMA Link Descriptor to indicate
          // that this is the Last entry in the array
          pDMALinkArray[i].dmalink_pNextLinkDescriptorAddr |= (uint32)FSLDMA_EOL_FLAG;
          pDMALinkArray[i].dmalink_lByteCount               = (uint32)lLastBlockSize;     // (re)set the number of bytes to copy for the Last Block
        }
        else
        {
          // Otherwise, advance the memory area pointers
          // and set the next DMA Link Descriptor in the array.
          // Also advance the physical pointer to the next
          // entry in the array
          pPhysicalSrcArea   += lBlockSize;
          pPhysicalDstArea   += lBlockSize;
          pNextDMADescriptor += sizeof(struct dma_link_descriptor);
        }
      }
      // Release the MMU Interface (as needed)
      if ( NULL != IMMU ) IExec->DropInterface((struct Interface *)IMMU);
    }
  }

  // Return the number of segments (blocks) that we used to build the array
  return( lNumberOfSegments );
}

//
// Free the allocated DMA Link Descriptor array
//
void FreeDMAChain(struct dma_link_descriptor *pDMALinkDescriptor)
{
  if ( NULL != pDMALinkDescriptor )
  {
    IExec->FreeVec(pDMALinkDescriptor);
  }
}

//
// Handle Notification Hook calls
//
uint32 notifyHookFunction(struct Hook *hook, uint32 lDMATransactionID, uint32 lNotifyFlag)
{
  if ( NULL != gpSignalTask )
  {
    if ( NULL != hook )
    {
      if ( FSLDMA_NF_INPROGRESS == (lNotifyFlag & FSLDMA_NF_INPROGRESS) )
      {
        // Send the "In Progress" signal
        IExec->Signal(gpSignalTask,SIGBREAKF_CTRL_E);
      }
  
      if ( FSLDMA_NF_ERROR == (lNotifyFlag & FSLDMA_NF_INPROGRESS) )
      {
        // Send the "Error" signal
        IExec->Signal(gpSignalTask,SIGBREAKF_CTRL_F);
      }
  
      if ( FSLDMA_NF_COMPLETE == (lNotifyFlag & FSLDMA_NF_COMPLETE) )
      {
        // Send the "Transaction Complete" signal
        IExec->Signal(gpSignalTask,SIGBREAKF_CTRL_D);
      }
    }
  }
  return( 0 );
}


//
// Our verify data routine
//
BOOL verifyIdentical(CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize)
{
  BOOL bVerified = TRUE;
  if ( (NULL != pBuffer1) && (NULL != pBuffer2) && (lTestSize > 0) )
  {
    // Determine the fastest verify method we can use
    if ( 0 == (lTestSize % 8) )
    {
      // We are divisible by 8 bytes,
      // so use a 64-Bit test loop
      uint64 *pSrcBuf = (uint64 *)pBuffer1;
      uint64 *pDstBuf = (uint64 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 8);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" 64-Bit Test at Position[%ld] found [%llx] != [%llx]\n",i,pSrcBuf[i],pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else if ( 0 == (lTestSize % 4) )
    {
      // We are divisible by 4 bytes,
      // so use a 32-Bit test loop
      uint32 *pSrcBuf = (uint32 *)pBuffer1;
      uint32 *pDstBuf = (uint32 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 4);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" 32-Bit Test at Position[%ld] found [%lx] != [%lx]\n",i,pSrcBuf[i],pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else if ( 0 == (lTestSize % 2) )
    {
      // We are divisible by 2 bytes,
      // so use a 16-Bit test loop
      uint16 *pSrcBuf = (uint16 *)pBuffer1;
      uint16 *pDstBuf = (uint16 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 2);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" 16-Bit Test at Position[%ld] found [%lx] != [%lx]\n",i,(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else
    {
      // Otherwise use a 8-Bit test loop
      uint8 *pSrcBuf = (uint8 *)pBuffer1;
      uint8 *pDstBuf = (uint8 *)pBuffer2;
      for( uint32 i = 0; i < lTestSize; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" 8-Bit Test at Position[%ld] found [%lx] != [%lx]\n",i,(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
  }
  return( bVerified );
}

struct TimerObject * openTimerDevice(enum enTimerUnits nTimerUnit)
{
  struct TimerObject *pNewTimerObj = NULL;
  pNewTimerObj = (struct TimerObject *)IExec->AllocVecTags(sizeof(struct TimerObject),AVT_Type,MEMF_SHARED,AVT_ClearWithValue,0,TAG_END);

  if ( NULL != pNewTimerObj )
  {
    // Allocate a MsgPort for our Timer
    pNewTimerObj->pTimerMsgPort = IExec->AllocSysObjectTags(ASOT_PORT,TAG_END);
    if ( NULL != pNewTimerObj->pTimerMsgPort )
    {
      // Allocare a IORequest object for our Timer
      pNewTimerObj->pTimerIOReq = (struct TimeRequest *)IExec->AllocSysObjectTags(ASOT_IOREQUEST,
                                                                                  ASOIOR_ReplyPort,pNewTimerObj->pTimerMsgPort,
                                                                                  ASOIOR_Size,sizeof(struct TimeRequest),
                                                                                  TAG_END);
      if ( NULL != pNewTimerObj->pTimerIOReq )
      {
        // Open the Timer Device (return of zero(0) == success)
        if ( 0 == IExec->OpenDevice(TIMERNAME,nTimerUnit,(struct IORequest *)pNewTimerObj->pTimerIOReq,0) )
        {
          // Obtain the TimerBase from our initialized TimerRequest structure
          pNewTimerObj->pTimerBase = (struct Library *)pNewTimerObj->pTimerIOReq->Request.io_Device;
          if ( NULL != pNewTimerObj->pTimerBase )
          {
            // Obtain the Interface to the Timer library
            pNewTimerObj->pITimer = (struct TimerIFace *)IExec->GetInterface(pNewTimerObj->pTimerBase,"main",1,NULL);
            if ( NULL != pNewTimerObj->pITimer )
            {
              // Success - Our timer device and timer library interface is open
            }
            else
            {
              // Failed to obtain the TimerIFace - Call closeTimerDevice() to cleanup
              closeTimerDevice(pNewTimerObj);
            }
          }
          else
          {
            // Failed to obtain the pTimerBase - Call closeTimerDevice() to cleanup
            closeTimerDevice(pNewTimerObj);
          }
        }
        else
        {
          // Failed to Open the Timer Device library - Call closeTimerDevice() to cleanup
          closeTimerDevice(pNewTimerObj);
        }
      }
      else
      {
        // Failed to Allocate the Timer IO Request - Call closeTimerDevice() to cleanup
        closeTimerDevice(pNewTimerObj);
      }
    }
    else
    {
      // Failed to Allocate the Timer Msg Port - Call closeTimerDevice() to cleanup
      closeTimerDevice(pNewTimerObj);
    }
  }

  return( pNewTimerObj );
}


void closeTimerDevice(struct TimerObject *pTimerObj)
{
  if ( NULL != pTimerObj )
  {
    // Free the Timer Interface
    if ( NULL != pTimerObj->pITimer )
    {
      IExec->DropInterface((struct Interface *)pTimerObj->pITimer);
      pTimerObj->pITimer = NULL;
    }

    // Free the TimerBase (Clear any pending Timer Event Messages before closing)
    if ( NULL != pTimerObj->pTimerBase )
    {
      if ( NULL != pTimerObj->pTimerIOReq )
      {
        // Now we can close the timer device
        IExec->CloseDevice((struct IORequest *)pTimerObj->pTimerIOReq);
      }
      pTimerObj->pTimerBase = NULL;
    }

    // Free the Timer IO Request object
    if ( NULL != pTimerObj->pTimerIOReq )
    {
      IExec->FreeSysObject(ASOT_IOREQUEST,(struct IORequest *)pTimerObj->pTimerIOReq);
      pTimerObj->pTimerIOReq = NULL;
    }

    // Free the Timer Msg Port
    if ( NULL != pTimerObj->pTimerMsgPort )
    {
      IExec->FreeSysObject(ASOT_PORT,pTimerObj->pTimerMsgPort);
      pTimerObj->pTimerMsgPort = NULL;
    }

    // Free the Timer Object itself
    IExec->FreeVec(pTimerObj);
    pTimerObj = NULL;
  }
}
