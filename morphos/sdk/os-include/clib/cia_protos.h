#ifndef CLIB_CIA_PROTOS_H
#define CLIB_CIA_PROTOS_H

/*
	cia.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_INTERRUPTS_H
# include <exec/interrupts.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Interrupt *AddICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
VOID RemICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
WORD AbleICR( struct Library *resource, LONG mask );
WORD SetICR( struct Library *resource, LONG mask );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_CIA_PROTOS_H */
