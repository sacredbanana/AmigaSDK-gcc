/*
 * fsldma_example_1.c
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

// fsldma.resource Example 1, "Blocking" DMA Copy
// test using Virtual memory areas
int main(int argc, char *argv[])
{
  struct ExecBase    *ExecBase     = (*(struct ExecBase **)4);
  struct ExecIFace   *IExec        = NULL;
  struct fslDMAIFace *IfslDMA      = NULL;
  uint32             lSize         = 0;
  CONST_APTR         pSrc          = NULL;
  APTR               pDest         = NULL;
  BOOL               bGotResources = FALSE;

  // Verify we are running the required kernel
  IExec = (struct ExecIFace *)ExecBase->MainInterface;
  struct Library *execLibNode = &ExecBase->LibNode;
  if ( !LIB_IS_AT_LEAST(execLibNode,54,41) )
  {
    // We are not running the minimum needed kernel version. Abort.
    printf("This program requires kernel version 54.41 or newer. Aborted test.\n");
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

  // Obtain the fsldma.resource
  IfslDMA = IExec->OpenResource(FSLDMA_NAME);
  
  // Set the size of our test buffers
  lSize = FSLDMA_OPTIMAL_BLKSIZE * 2; // About 128 MB

  // Allocate a test source buffer (fill with some data)
  pSrc  = IExec->AllocVecTags(lSize,
                              AVT_Type,              MEMF_SHARED,
                              AVT_ClearWithValue,    0xB3,
                              TAG_DONE);

  // Allocate a test destination buffer (clear with zeroes)
  pDest = IExec->AllocVecTags(lSize,
                              AVT_Type,              MEMF_SHARED,
                              AVT_ClearWithValue,    0,
                              TAG_DONE);

  // Verify we got all resources needed for the test
  if ( (NULL != IfslDMA) && (NULL != pSrc) && (NULL != pDest) )
  {
    bGotResources = TRUE;
  }

  if ( TRUE == bGotResources )
  {
    // Call IfslDMA->CopyMemDMA() to perform the memory copy using the
    // DMA hardware. Wait for the transaction to complete before continuing.

    printf("Starting \"Blocking\" DMA Transaction"
           " of %ld bytes from 0x%08lx to 0x%08lx...\n",lSize,pSrc,pDest);
    fflush(stdout);
    if ( TRUE == IfslDMA->CopyMemDMA(pSrc,pDest,lSize) )
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
