#include <exec/types.h>
#include <exec/nodes.h>
#include <exec/lists.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <exec/alerts.h>
#include <exec/execbase.h>
#include <exec/devices.h>
#include <exec/io.h>
#include <exec/errors.h>

#include <emul/emulinterface.h>
#include <emul/emulregs.h>
#include <proto/exec.h>

#include <clib/debug_protos.h>


ULONG	test(ULONG	Arg1,
             ULONG	Arg2,
             ULONG	Arg3,
             ULONG	Arg4,
             ULONG	Arg5,
             ULONG	Arg6,
             ULONG	Arg7,
             ULONG	Arg8);

#define	STACKSIZE	16384

int	main(void)
{
	struct ExecBase         *SysBase = *((struct ExecBase**) 4);
	struct PPCStackSwapArgs Args;
	struct StackSwapStruct  Swap;
	UBYTE                   *MyStack;
	ULONG                   Result;
	int                     i;

	kprintf("main: StackSwap\n");

	for (i = 0; i < 8; i++)
	{
		Args.Args[i] = i;
	}

	if ((MyStack = AllocVec(STACKSIZE, MEMF_PUBLIC)))
	{
		kprintf("main: Stack 0x%lx\n", (ULONG) MyStack);

		Swap.stk_Lower = (void *) MyStack;
		Swap.stk_Upper = (ULONG)  &MyStack[STACKSIZE];

		/*
		 * Internally the function subtract 16 for the current r1
		 * because we need the savety header
		 */
		Swap.stk_Pointer = (void *) &MyStack[STACKSIZE];

		Result = NewPPCStackSwap(&Swap,
		                         &test,
		                         &Args);

		kprintf("Result: 0x%lx\n", Result);

		FreeVec(MyStack);
	}
	else
	{
		kprintf("main: Stack allocation failed\n");
	}

	kprintf("main: done\n");

	return 0;
}


ULONG test(ULONG  Arg1,
           ULONG  Arg2,
           ULONG  Arg3,
           ULONG  Arg4,
           ULONG  Arg5,
           ULONG  Arg6,
           ULONG  Arg7,
           ULONG  Arg8)
{
	kprintf("test: %ld %ld %ld %ld %ld %ld %ld %ld\n",
	        Arg1,
	        Arg2,
	        Arg3,
	        Arg4,
	        Arg5,
	        Arg6,
	        Arg7,
	        Arg8);

	return 0x12345678;
}

