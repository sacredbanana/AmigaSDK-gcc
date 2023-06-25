#ifndef EXEC_DEBUG_H
#define EXEC_DEBUG_H
/*
**    $VER: debug.h 53.29 (10.8.2015)
**
**    Debugging data structure definitions
**
**    Copyright (c) 2013 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/


// Minimum size of the buffers to receive disassembled opcodes
// and operands including the NIL string terminator.
#define LEN_DISASSEMBLE_OPCODE_STRING    15
#define LEN_DISASSEMBLE_OPERANDS_STRING  40


/*
 * The StackFrameMsg is used when traversing a Task's stack.
 */
struct StackFrameMsg
{
    uint32 StructSize;           // Size of the data structure
    uint32 State;                // State of the stack frame
    CONST_APTR MemoryAddress;    // Memory address being pointed to
    const uint32 *StackPointer;  // The stack pointer itself
};


enum enStackFrameMsgState
{
    STACK_FRAME_DECODED               = 1,  // Decoded stack frame
    STACK_FRAME_INVALID_BACKCHAIN_PTR = 2,  // Invalid backchain pointer
    STACK_FRAME_TRASHED_MEMORY_LOOP   = 3,  // Memory loop caused by
                                            // trashed memory
    STACK_FRAME_BACKCHAIN_PTR_LOOP    = 4   // Backchain pointer loops
};


/*
 * Each DebugSymbol corresponds to some memory address.
 */
struct DebugSymbol
{
    uint32 StructSize;               // Size of the data structure
    uint32 Type;                     // Type of debug symbol

    CONST_STRPTR Name;               // Module name (may be NULL)
    uint32 Offset;                   // Offset into the module
    uint32 SegmentNumber;            // DOS segment number
    uint32 SegmentOffset;            // DOS segment offset

    CONST_STRPTR SourceFileName;     // Source code file name (may be NULL)
    uint32 SourceLineNumber;         // Source code line number (may be zero)
    CONST_STRPTR SourceFunctionName; // Source code function name (may be NULL)
    CONST_STRPTR SourceBaseName;     // Source code base name (may be NULL)
};


enum enDebugSymbolType
{
    DEBUG_SYMBOL_68K_MODULE    = 1,  // 68K kernel module
    DEBUG_SYMBOL_NATIVE_MODULE = 2,  // Kernel data module
    DEBUG_SYMBOL_KERNEL_MODULE = 3,  // Kernel module
    DEBUG_SYMBOL_MODULE        = 4,  // Module
    DEBUG_SYMBOL_MODULE_STABS  = 5   // Module with stabs debug
};

/*
 * Opaque datatype for the result of StartDebugOutputNotify.
 */
struct DebugOutputNotify;

/* The task that should be signaled with the given
 * signal mask when the debug output buffer was updated.
 */
#define SDONA_Task (TAG_USER + 0x1021000) /* struct Task * */

/* The signal mask that shall be used */
#define SDONA_SignalMask (TAG_USER + 0x1021001) /* uint32 */

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_DEBUG_H */
