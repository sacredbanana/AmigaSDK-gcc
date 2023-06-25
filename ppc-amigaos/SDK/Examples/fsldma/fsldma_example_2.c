/*
 * fsldma_example_2.c
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
#include <exec/types.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <interfaces/exec.h>
#include <interfaces/fsldma.h>

BOOL verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize );

// fsldma.resource Example 2, "Non-blocking" DMA Copy
// test using user notifications and Physical memory areas
int main(int argc, char *argv[])
{
  struct ExecBase    *ExecBase          = (*(struct ExecBase **)4);
  struct ExecIFace   *IExec             = NULL;
  struct MMUIFace    *IMMU              = NULL;
  struct fslDMAIFace *IfslDMA           = NULL;
  uint32             lSize              = 0;
  CONST_APTR         pSrc               = NULL;
  APTR               pDest              = NULL;
  CONST_APTR         pPhySrcAddr        = NULL;
  APTR               pPhyDstAddr        = NULL;
  int8               nSuccessSigNum     = -1;
  int8               nInProgressSigNum  = -1;
  int8               nErrorSigNum       = -1;
  uint32             lSuccessSigMask    = 0;
  uint32             lInProgressSigMask = 0;
  uint32             lErrorSigMask      = 0;
  uint32             lAllSigsMask       = 0;
  BOOL               bGotResources      = FALSE;

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

  // Verify we are running the required kernel
  IExec = (struct ExecIFace *)ExecBase->MainInterface;
  struct Library *execLibNode = &ExecBase->LibNode;
  if ( !LIB_IS_AT_LEAST(execLibNode,54,41) )
  {
    // We are not running the minimum needed kernel version. Abort.
    printf("This program requires kernel version 54.41 or newer. Aborted test.\n");
    return( 1 );
  }

  // Obtain the MMU Interface
  IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,
                                                "MMU",1,NULL);
  // Obtain the fsldma.resource
  IfslDMA = IExec->OpenResource(FSLDMA_NAME);

  // Set our test buffer size large enough to generate some sub-block transfers
  lSize = FSLDMA_OPTIMAL_BLKSIZE * 8; // About 512 MB (twice this is needed for the test)

  // Display setup message
  printf("Setting up \"Non-Blocking\" DMA Transaction of %ld bytes.\n",lSize);

  // Allocate a test source buffer (fill with some data)
  pSrc  = IExec->AllocVecTags(lSize,
                              AVT_Type,              MEMF_SHARED,
                              AVT_Contiguous,        TRUE,
                              AVT_Lock,              TRUE,
                              AVT_Alignment,         64,
                              AVT_PhysicalAlignment, 64,
                              AVT_ClearWithValue,    0xB3,
                              TAG_DONE);

  // Allocate a test destination buffer (clear with zeroes)
  pDest = IExec->AllocVecTags(lSize,
                              AVT_Type,              MEMF_SHARED,
                              AVT_Contiguous,        TRUE,
                              AVT_Lock,              TRUE,
                              AVT_Alignment,         64,
                              AVT_PhysicalAlignment, 64,
                              AVT_ClearWithValue,    0,
                              TAG_DONE);

  // Allocate signals to wait on
  nSuccessSigNum    = IExec->AllocSignal((int8)-1);
  nInProgressSigNum = IExec->AllocSignal((int8)-1);
  nErrorSigNum      = IExec->AllocSignal((int8)-1);

  // Construct the signal masks we need to Wait() on later.
  // We are assuming these values are being built with
  // allocated signals here, but we will verify it before use.
  lSuccessSigMask    = (uint32)(1L << nSuccessSigNum);
  lInProgressSigMask = (uint32)(1L << nInProgressSigNum);
  lErrorSigMask      = (uint32)(1L << nErrorSigNum);
  lAllSigsMask = (lSuccessSigMask | lInProgressSigMask | lErrorSigMask);

  // Obtain the pointer to ourselves (this Task)
  struct Task *pThisTask = IExec->FindTask(NULL);

  // Verify we got all resources needed for the test
  if ( (NULL != IMMU) && (NULL != IfslDMA) &&
       (NULL != pSrc) && (NULL != pDest)   &&
       (NULL != pThisTask )                &&
       (-1 != nSuccessSigNum)              &&
       (-1 != nInProgressSigNum)           &&
       (-1 != nErrorSigNum)                 )
  {
    bGotResources = TRUE;
  }

  if ( TRUE == bGotResources )
  {
    // In this test we are using Physical memory areas
    // for both source and destination, so before we
    // hand the transaction to the DMA hardware, we first
    // need to set the flush the data cache, set the
    // buffers to cache-inhibited and obtain the Physical
    // addresses for both buffers

    // Enter Supervisor Mode
    APTR pUserStack = IExec->SuperState();

    // Now set the memory attributes to prevent further cache operations
    uint32 lSrcMemAttrs = IMMU->GetMemoryAttrs((APTR)pSrc,0);
    uint32 lDstMemAttrs = IMMU->GetMemoryAttrs(pDest,0);
    IMMU->SetMemoryAttrs((APTR)pSrc,lSize,(lSrcMemAttrs | FSLDMA_PHYMEM_ATTRS));
    IMMU->SetMemoryAttrs(pDest,lSize,(lDstMemAttrs | FSLDMA_PHYMEM_ATTRS));

    // Get the Physical addresses for our two buffers
    pPhySrcAddr = IMMU->GetPhysicalAddress((APTR)pSrc);
    pPhyDstAddr = IMMU->GetPhysicalAddress(pDest);

    // Return to User Mode
    if ( NULL != pUserStack ) IExec->UserState(pUserStack);

    // Call IfslDMA->CopyMemDMATags() to perform the memory copy using the
    // DMA hardware. Start off the transaction then wait on completion signals.

    printf("Starting \"Non-Blocking\" DMA Transaction"
           " of %ld bytes from 0x%08lx to 0x%08lx...\n",
           lSize,pPhySrcAddr,pPhyDstAddr);
    fflush(stdout);

    if ( TRUE == IfslDMA->CopyMemDMATags(pPhySrcAddr,pPhyDstAddr,lSize,
                            FSLDMA_CM_SourceIsPhysical,          TRUE,
                            FSLDMA_CM_DestinationIsPhysical,     TRUE,
                            FSLDMA_CM_DoNotWait,                 TRUE,
                            FSLDMA_CM_NotifyTask,                pThisTask,
                            FSLDMA_CM_NotifySignalNumber,        nSuccessSigNum,
                            FSLDMA_CM_NotifyProgessSignalNumber, nInProgressSigNum,
                            FSLDMA_CM_NotifyErrorSignalNumber,   nErrorSigNum,
                            TAG_DONE) )
    {
      // If the above call sets up correctly, it returns immeditately
      // So do something here *while* the data is being copied...
      printf("Doing other stuff before waiting...\n");
      fflush(stdout);

      // Now we will Wait() for the completion signals from the DMA
      BOOL   bStillRunning = TRUE;
      uint32 lSigReceived  = 0;
      do
      {
        // Wait for the DMA completion/status/error signals
        printf("Waiting for signals...\n");
        fflush(stdout);
        lSigReceived = IExec->Wait( lAllSigsMask | SIGBREAKF_CTRL_C );

        // Test for the "In Progress" signal
        if ( lInProgressSigMask == (lSigReceived & lInProgressSigMask) )
        {
          // Do something on the "In Process" signal and continue...
          printf("Received an \"In Progress\" signal...\n");
          fflush(stdout);
        }

        // Test for the "Success" signal
        if ( lSuccessSigMask == (lSigReceived & lSuccessSigMask) )
        {
          // Success - Do something with the copied data and quit
          printf("Received an \"Completed Successfully\" signal.\n");
          fflush(stdout);
          
          // If requested, verify the transfered data
          if ( TRUE == bVerifyTest )
          {
            printf("Verifing...");
            fflush(stdout);
            BOOL bVerified = verifyIdentical(pSrc,pDest,lSize);
            printf(" %s\n",(TRUE == bVerified) ? "OK" : "Failed!");
          }
          
          bStillRunning = FALSE;
        }

        // Test for the "Error" signal
        if ( lErrorSigMask == (lSigReceived & lErrorSigMask) )
        {
          // Report the error and quit
          printf("Received an \"Error\" signal!\n");
          fflush(stdout);
          bStillRunning = FALSE;
        }

        // Finally, check if we got a Break signal from the user
        // just in case we want to quit out early for some reason
        if ( SIGBREAKF_CTRL_C == (lSigReceived & SIGBREAKF_CTRL_C) )
        {
          printf("Received an \"User break\" signal, ending.\n");
          fflush(stdout);
          bStillRunning = FALSE;
        }
      } while( TRUE == bStillRunning );
    }
  }
  else
  {
    printf("Failed to obtain resources, aborting test.\n");
    fflush(stdout);
  }

  // Free our test buffers (as needed)
  if ( NULL != pSrc  ) IExec->FreeVec((APTR)pSrc);
  if ( NULL != pDest ) IExec->FreeVec(pDest);
  // Free any signals we (may have) obtained earlier
  if ( -1 != nSuccessSigNum    ) IExec->FreeSignal(nSuccessSigNum);
  if ( -1 != nInProgressSigNum ) IExec->FreeSignal(nInProgressSigNum);
  if ( -1 != nErrorSigNum      ) IExec->FreeSignal(nErrorSigNum);
  // Release the MMU Interface (as needed)
  if ( NULL != IMMU ) IExec->DropInterface((struct Interface *)IMMU);
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
          printf(" [%llx] != [%llx] ",pSrcBuf[i],pDstBuf[i]);
          //IExec->DebugPrintF(" [%llx] != [%llx] ",pSrcBuf[i],pDstBuf[i]);
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
          printf(" [%lx] != [%lx] ",pSrcBuf[i],pDstBuf[i]);
          //IExec->DebugPrintF(" [%lx] != [%lx] ",pSrcBuf[i],pDstBuf[i]);
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
          printf(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          //IExec->DebugPrintF(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
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
          printf(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          //IExec->DebugPrintF(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
  }
  return( bVerified );
}
