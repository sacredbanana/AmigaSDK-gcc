/*
 * chainingdma_test.c
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

// Structure to hold the buffer pointers
// for the IExec->CopyMem() test
struct BufferPtrs
{
  APTR pSrcAddr;
  APTR pDestAddr;
};

#define NUM_SUB_BLOCKS 256  // Set the number of sub-blocks to 256
#define SUB_BLOCK_SIZE 1024 // Set the sub-block size to 1024 Bytes
#define TOTAL_AREA_SIZE (NUM_SUB_BLOCKS * SUB_BLOCK_SIZE)

#define MAX_ALLOWED_BUFFER (512 * 1024 * 1024)

struct dma_link_descriptor * AllocateDMAChain( uint32 lNumberOfSegments );
uint32                       InitializeDMAChain( struct dma_link_descriptor *pDMALinkDescriptor, CONST_APTR pPhysicalSourceBuffer, APTR pPhysicalDestBuffer, uint32 lNumberOfSegments, uint32 lSegmentSize, uint32 lTotalBufferSize );
void                         FreeDMAChain( struct dma_link_descriptor *pDMALinkDescriptor );

struct TimerObject * openTimerDevice( enum enTimerUnits nTimerUnit );
void   closeTimerDevice( struct TimerObject *pTimerObj );
BOOL   verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize );

// fsldma.resource DMA Chaining test.
// This test compares the execution time of
// a set of IExec->CopyMem() calls vs a
// single fsldma.resource call that performs
// the same set of data moves using a chain
// of DMA transactions.

int main(int argc, char *argv[])
{
  struct ExecBase            *ExecBase           = (*(struct ExecBase **)4);
  struct ExecIFace           *IExec              = NULL;
  struct fslDMAIFace         *IfslDMA            = NULL;
  struct dma_link_descriptor *pDMALinkArray      = NULL;
  struct BufferPtrs          *pCopyMemBufferPtrs = NULL;
  CONST_APTR                  pSrcArea           = NULL;
  APTR                        pDestArea          = NULL;
  BOOL                        bGotResources      = FALSE;

  // Set the defaults for the test
  uint32 lNumberOfSegments = NUM_SUB_BLOCKS;
  uint32 lSegmentSize      = SUB_BLOCK_SIZE;
  BOOL   bVerifyTest       = FALSE;
  BOOL   bVerboseFlag      = FALSE;

  // Handle any supplied arguments
  for( int c = 0; c < argc; c++ )
  {
    char *sNextArg = argv[c];
    // If the argument does not start with a '-'
    // then handle it as a positional argument
    if ( '-' != sNextArg[0] )
    {
      switch( c )
      {
        // Read the first position argument
        case 1:
        {
          // Convert the first argument to a number value
          // (for Number of Segments)
          lNumberOfSegments = (uint32)atol(sNextArg);
        }
        break;
  
        // Read the second position argument
        case 2:
        {
          // Convert the second argument to a number value
          // (for Segment Size)
          lSegmentSize = (uint32)atol(sNextArg);
        }
        break;
      }
    }
    else
    {
      // Handle the '-' arguments
      if ( (c > 0) && (strlen(sNextArg) >= 2) )
      {
        if ( 'v' == sNextArg[1] )
        {
          bVerifyTest = TRUE; // Set the Verify Test flag
        }
        else if ( 'b' == sNextArg[1] )
        {
          bVerboseFlag = TRUE; // Set the Verbose output flag
        }       
      }
    }
  } 

  // Sanity check the Number of Segments
  if ( lNumberOfSegments <= 0 ) lNumberOfSegments = NUM_SUB_BLOCKS;

  // Sanity check the Segment Size
  // Adjust the Segment size (as needed)
  if ( lSegmentSize <= 0 )
  {
    lSegmentSize = SUB_BLOCK_SIZE;
  }
  else if ( lSegmentSize > FSLDMA_MAXBLOCK_SIZE )
  {
    lSegmentSize = FSLDMA_MAXBLOCK_SIZE;
  }

  // Calculate the size for the source and destination buffers
  uint32 lTotalBufferSize = (lNumberOfSegments * lSegmentSize);
  
  // Make sure the Total memory requirements are not to large
  if ( lTotalBufferSize > MAX_ALLOWED_BUFFER )
  {
    printf("Test aborted, the total memory needed if above %ld\n",(MAX_ALLOWED_BUFFER * 2));
    return( 1 );
  }

  if ( TRUE == bVerboseFlag )
  {
    printf("Command line args passed in:\nNumber of Segments = %lu\nSegment Size  = %lu\nVerify Mode is %s\n",
           lNumberOfSegments,lSegmentSize,(TRUE == bVerifyTest) ? "Enabled" : "Disabled");
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

  // Display setup message
  printf("Setting up DMA Chaining Transaction with %ld blocks of %ld bytes, totaling %ld.\n",lNumberOfSegments,lSegmentSize,lTotalBufferSize);

  // Obtain the fsldma.resource
  IfslDMA = IExec->OpenResource(FSLDMA_NAME);

  // Timer object structure populated by openTimerDevice()
  struct TimerObject *pTimerObj = NULL;
  pTimerObj = openTimerDevice(UNIT_MICROHZ);

  //
  // For this test we allocate two larger memory areas
  // and then copy smaller blocks from those areas
  //
  
  // Allocate a test source buffer (fill with some data)
  pSrcArea  = IExec->AllocVecTags(lTotalBufferSize,
                                  AVT_Type,              MEMF_SHARED,
                                  AVT_Contiguous,        TRUE,
                                  AVT_Lock,              TRUE,
                                  AVT_Alignment,         64,
                                  AVT_PhysicalAlignment, 64,
                                  AVT_ClearWithValue,    0xB3,
                                  TAG_DONE);

  // Allocate a test destination buffer (clear with zeroes)
  pDestArea = IExec->AllocVecTags(lTotalBufferSize,
                                  AVT_Type,              MEMF_SHARED,
                                  AVT_Contiguous,        TRUE,
                                  AVT_Lock,              TRUE,
                                  AVT_Alignment,         64,
                                  AVT_PhysicalAlignment, 64,
                                  AVT_ClearWithValue,    0,
                                  TAG_DONE);

  // Allocate a DMA Link descriptor array (clear with zeroes)
  // Large enough to contain a DMA Link Descriptor for each sub-block
  pDMALinkArray = (struct dma_link_descriptor *)AllocateDMAChain(lNumberOfSegments);

  // Verify we got all resources needed for the test
  if ( (NULL != IfslDMA)       &&
       (NULL != pSrcArea)      && (NULL != pDestArea) &&
       (NULL != pDMALinkArray) && (NULL != pTimerObj)  )
  {
    bGotResources = TRUE;
  }

  if ( TRUE == bGotResources )
  {
    //
    // Setup and perform the DMA Chaining test
    //

    // Initialize the DMA Link Array for use
    lNumberOfSegments = InitializeDMAChain(pDMALinkArray,pSrcArea,pDestArea,lNumberOfSegments,lSegmentSize,lTotalBufferSize);

    // Call IfslDMA->StartDMAChain() to perform the memory copy using the
    // DMA hardware. Wait for transaction to return after all copies are complete.

    if ( TRUE == bVerboseFlag )
    {
      printf("\nStarting \"Blocking\" DMA Chain Transaction\n"
             " of %ld Bytes containing %ld blocks from\n"
             " 0x%08lx to 0x%08lx using DMA Link Array at 0x%08lx...\n",
             lTotalBufferSize,lNumberOfSegments,pSrcArea,pDestArea,pDMALinkArray);
    }

    BOOL bStartDMAResults = FALSE;

    // Reset and start the timer
    pTimerObj->oTimeValStart.Seconds      = 0;
    pTimerObj->oTimeValStart.Microseconds = 0;
    pTimerObj->oTimeValEnd.Seconds        = 0;
    pTimerObj->oTimeValEnd.Microseconds   = 0;
    
    // Get Start time before the copy
    pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);

    // Call the IfslDMA->StartDMAChain() function
    bStartDMAResults = IfslDMA->StartDMAChain(pDMALinkArray);

    // Calculate and display the elapsed time
    pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
    pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);

    if ( TRUE == bStartDMAResults )
    {
      // The DMA Transaction successfully completed
      printf("\nDMA Chain Transaction completed transfering %ld bytes successfully\n",lTotalBufferSize);
      printf(" in %ld Seconds and %ld Microseconds.\n",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
    }
    else
    {
      // The DMA call returned false (all DMA Channels could be busy)
      printf("DMA Chain Transaction returned FALSE.\n");
      printf("Since we are not checking for DMA result codes\n");
      printf("it is possible that all DMA channels are just busy,\n");
      printf("so just try re-running the test.\n");
    }

    // Verify the destination matches the source
    // after the DMA copy
    if ( TRUE == bVerifyTest )
    {
      printf("\nVerifing Transfer of %ld bytes from %p to %p...",lTotalBufferSize,pSrcArea,pDestArea);
      fflush(stdout);
      BOOL bVerified = verifyIdentical(pSrcArea,pDestArea,lTotalBufferSize);
      printf("%s\n",(TRUE == bVerified) ? "OK" : "FAILED!");
    }


    //
    // Setup the run the same test using IExec->CopyMem()
    //
    uint32 lBufferPtrsSize = lNumberOfSegments * sizeof(struct BufferPtrs);
    pCopyMemBufferPtrs = (struct BufferPtrs *)IExec->AllocVecTags(lBufferPtrsSize,
                                                                  AVT_Type,           MEMF_SHARED,
                                                                  AVT_Contiguous,     TRUE,
                                                                  AVT_Lock,           TRUE,
                                                                  AVT_ClearWithValue, 0,
                                                                  TAG_DONE);

    if ( NULL != pCopyMemBufferPtrs )
    {
      // Populate the source and destination pointer
      uint8 *pNextSrcArea  = (uint8 *)pSrcArea;
      uint8 *pNextDestArea = (uint8 *)pDestArea;
      for( uint32 i = 0; i < lNumberOfSegments; i++ )
      {
        pCopyMemBufferPtrs[i].pSrcAddr  = (APTR)pNextSrcArea;
        pCopyMemBufferPtrs[i].pDestAddr = (APTR)pNextDestArea;
        pNextSrcArea  += lSegmentSize;
        pNextDestArea += lSegmentSize;
      }

      //
      // Test using individual IfslDMA->CopyMemDMA() calls
      //      
      if ( TRUE == bVerboseFlag )
      {
        printf("\nStarting %ld calls of IfslDMA->CopyMemDMA()...\n",lNumberOfSegments);
      }
      
      // Get Start time before the copy
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
      for( uint32 i = 0; i < lNumberOfSegments; i++ )
      {
        IfslDMA->CopyMemDMA((CONST APTR)pCopyMemBufferPtrs[i].pSrcAddr,pCopyMemBufferPtrs[i].pDestAddr,lSegmentSize);
      }
      // Calculate and display the elapsed time
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
      pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);
      printf("\n%ld IfslDMA->CopyMemDMA() calls completed transfering %ld bytes\n",lNumberOfSegments,lTotalBufferSize);
      printf(" in %ld Seconds and %ld Microseconds.\n",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
  
      // Verify the destination matches the source
      // after the IExec->CopyMem() calls
      if ( TRUE == bVerifyTest )
      {
        printf("\nVerifing Transfer of %ld bytes from %p to %p...",lTotalBufferSize,pSrcArea,pDestArea);
        fflush(stdout);
        BOOL bVerified = verifyIdentical(pSrcArea,pDestArea,lTotalBufferSize);
        printf("%s\n",(TRUE == bVerified) ? "OK" : "FAILED!");
      }


      //
      // Test using individual IExec->CopyMem() calls
      //      
      if ( TRUE == bVerboseFlag )
      {
        printf("\nStarting %ld calls of IExec->CopyMem()...\n",lNumberOfSegments);
      }
      
      // Get Start time before the copy
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
      for( uint32 i = 0; i < lNumberOfSegments; i++ )
      {
        IExec->CopyMem((CONST APTR)pCopyMemBufferPtrs[i].pSrcAddr,pCopyMemBufferPtrs[i].pDestAddr,lSegmentSize);
      }
      // Calculate and display the elapsed time
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
      pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);
      printf("\n%ld IExec->CopyMem() calls completed transfering %ld bytes\n",lNumberOfSegments,lTotalBufferSize);
      printf(" in %ld Seconds and %ld Microseconds.\n",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
  
      // Verify the destination matches the source
      // after the IExec->CopyMem() calls
      if ( TRUE == bVerifyTest )
      {
        printf("\nVerifing Transfer of %ld bytes from %p to %p...",lTotalBufferSize,pSrcArea,pDestArea);
        fflush(stdout);
        BOOL bVerified = verifyIdentical(pSrcArea,pDestArea,lTotalBufferSize);
        printf("%s\n",(TRUE == bVerified) ? "OK" : "FAILED!");
      }
    }
    else
    {
      // Unable to allocate the memory for the segment pointers
      printf("Failed to obtain resources, aborting IExec->CopyMem() section of the test.\n");
    }
  }
  else
  {
    printf("Failed to obtain resources, aborting test.\n");
  }

  // Free our test buffers (as needed)
  if ( NULL != pTimerObj          ) closeTimerDevice(pTimerObj);
  if ( NULL != pSrcArea           ) IExec->FreeVec((APTR)pSrcArea);
  if ( NULL != pDestArea          ) IExec->FreeVec(pDestArea);
  if ( NULL != pDMALinkArray      ) FreeDMAChain(pDMALinkArray);
  if ( NULL != pCopyMemBufferPtrs ) IExec->FreeVec(pCopyMemBufferPtrs);
}

//
// Functions to aid in the allocation and setup of
// a suitable DMA Link Array for passing to the
// StartDMAChain() API call
//

//
// Allocate a DMA Link Array large enough to
// handle the number of specified segments
//
struct dma_link_descriptor * AllocateDMAChain(uint32 lNumberOfSegments)
{
  struct dma_link_descriptor *pDMALinkArray = NULL;
  if ( lNumberOfSegments > 0 )
  {
    // Allocate a DMA Link descriptor array (clear with zeroes),
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
// Initialize the supplied DMA Link Array using the segment size, source and destination pointers.
// On success returns the number of segments (blocks) that will be used for the transaction.
//
uint32 InitializeDMAChain(struct dma_link_descriptor *pDMALinkArray, CONST_APTR pSourceBuffer, APTR pDestBuffer, uint32 lNumberOfSegments, uint32 lSegmentSize, uint32 lTotalBufferSize)
{
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
    if ( (0 != pSourceBuffer) && (0 != pDestBuffer) )
    { 
      if ( (lNumberOfSegments > 0) && (lSegmentSize > 0) )
      {
        if ( lTotalBufferSize > 0 )
        {
          // Obtain the MMU Interface
          IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,
                                                    "MMU",1,NULL);
          if ( NULL == IMMU ) return( 0 );
      
          // Verify the Number of segments of segment size
          // will fit the provided total buffer size
          if ( lTotalBufferSize < (lNumberOfSegments * lSegmentSize) )
          {
            return( 0 );
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
            pDMALinkArray[i].dmalink_lByteCount                 = (uint32)lSegmentSize;       // Sets the number of bytes to copy
      
            // This is the last DMA Link Descriptor entry,
            // so set the EOL flag on this Next Link Addr field
            if ( i == (lNumberOfSegments - 1) )
            {
              // Setup the link to the next DMA Link Descriptor to indicate
              // that this is the Last entry in the array
              pDMALinkArray[i].dmalink_pNextLinkDescriptorAddr |= (uint32)FSLDMA_EOL_FLAG;
            }
            else
            {
              // Otherwise, advance the memory area pointers
              // and set the next DMA Link Descriptor in the array.
              // Also advance the physical pointer to the next
              // entry in the array
              pPhysicalSrcArea   += lSegmentSize;
              pPhysicalDstArea   += lSegmentSize;
              pNextDMADescriptor += sizeof(struct dma_link_descriptor);
            }
          }
          // Release the MMU Interface (as needed)
          if ( NULL != IMMU ) IExec->DropInterface((struct Interface *)IMMU);
        }
      }
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

//
// Open and configure the Timer Device
//
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

//
// Close and free the Timer Device
//
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
