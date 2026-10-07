/*
 * fsldma_copymemdma64.c
 *
 * Copyright 2023 Trevor Dickinson. All rights reserved.
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
#include <resources/fsldma.h>

BOOL verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize );

// fsldma.resource Example 1, "Blocking" DMA Copy
// test using Virtual memory areas
int main(int argc, char *argv[])
{
  struct ExecBase    *ExecBase     = (*(struct ExecBase **)4);
  struct ExecIFace   *IExec        = NULL;
  struct MMUIFace    *IMMU         = NULL;
  struct fslDMAIFace *IfslDMA      = NULL;
  uint32             lSize         = 0;
  CONST_APTR         pSrc          = NULL;
  APTR               pDest         = NULL;
  CONST_APTR         pPhySrcAddr   = NULL;
  APTR               pPhyDstAddr   = NULL;
  BOOL               bGotResources = FALSE;

  // Verify we are running the required kernel
  IExec = (struct ExecIFace *)ExecBase->MainInterface;
  struct Library *execLibNode = &ExecBase->LibNode;
  if ( !LIB_IS_AT_LEAST(execLibNode,54,62) )
  {
    // We are not running the minimum needed kernel version. Abort.
    printf("This program requires kernel version 54.62 or newer. Aborted test.\n");
    return( 1 );
  }

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

  // Obtain the MMU Interface
  IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,
                                                "MMU",1,NULL);

  // Obtain the fsldma.resource
  IfslDMA = IExec->OpenResource(FSLDMA_NAME);
  
  // Set the size of our test buffers
  lSize = FSLDMA_OPTIMAL_BLKSIZE * 2; // About 128 MB

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

  // Verify we got all resources needed for the test
  if ( (NULL != IMMU) && (NULL != IfslDMA) && (NULL != pSrc) && (NULL != pDest) )
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

    // Setup 64-Bit Physical addresses
    // As the destinations here are 64-Bit integers and
    // the sources are 32-Bit pointers, we need the
    // "double cast" first to a 32-Bit integer from
    // a 32-Bit pointer and then to a 64-Bit integer
    // in order to make the compiler shut-up.
    // This nonsense will be removed only we are building
    // with a 64-Bit compiler.
    CONST_DMAPTR SrcAddr64 = (CONST_DMAPTR)(uint32)pPhySrcAddr;
    DMAPTR       DstAddr64 = (DMAPTR)(uint32)pPhyDstAddr;

    // Sanity check of 64-Bit address values before use
    if ( (0 == SrcAddr64) || (0 == DstAddr64) )
    {
      printf("Test aborted, SrcAddr64 and/or DstAddr64 is zero(0)!\n");

      // Free our test buffers (as needed)
      if ( NULL != pSrc  ) IExec->FreeVec((APTR)pSrc);
      if ( NULL != pDest ) IExec->FreeVec(pDest);
      // Release the MMU Interface (as needed)
      if ( NULL != IMMU ) IExec->DropInterface((struct Interface *)IMMU);

      return( 0 );
    }     

    // Call IfslDMA->CopyMemDMA64() to perform the memory copy using the
    // DMA hardware. Wait for the transaction to complete before continuing.

    printf("Starting \"Blocking\" DMA Transaction"
           " of %ld bytes from 0x%016llx to 0x%016llx...\n",lSize,SrcAddr64,DstAddr64);
    if ( TRUE == IfslDMA->CopyMemDMA64(SrcAddr64,DstAddr64,lSize) )
    {
      // Success - Do something with the copied data and quit
      if ( TRUE == bVerifyTest )
      {
        printf("Returned with Success. Verifing...");
        fflush(stdout);
        BOOL bVerified = verifyIdentical(pSrc,pDest,lSize);
        printf(" %s\n",(TRUE == bVerified) ? "OK" : "Failed!");
      }
      else
      {
        printf("Returned with Success.\n");
      }
    }
    else
    {
      // Report the error
      printf("Received an Error!\n");
    }
  }
  else
  {
    printf("Failed to obtain resources, aborting test.\n");
  }

  // Free our test buffers (as needed)
  if ( NULL != pSrc  ) IExec->FreeVec((APTR)pSrc);
  if ( NULL != pDest ) IExec->FreeVec(pDest);
  // Release the MMU Interface (as needed)
  if ( NULL != IMMU ) IExec->DropInterface((struct Interface *)IMMU);

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
          printf(" [%llx] != [%llx] ",pSrcBuf[i],pDstBuf[i]);
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
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
  }
  return( bVerified );
}
