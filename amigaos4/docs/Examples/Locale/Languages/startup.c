/*
 * This has to be linked as first file before other object code
 * and the linker libs to make sure that it is the first executable
 * location, which must return an error to the caller.
 */

#include <exec/types.h>

LONG ASM _start(VOID)
{
    return 100;
}
