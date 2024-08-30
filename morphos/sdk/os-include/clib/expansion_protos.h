#ifndef CLIB_EXPANSION_PROTOS_H
#define CLIB_EXPANSION_PROTOS_H

/*
	expansion.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_MEMORY_H
# include <exec/memory.h>
#endif

#ifndef LIBRARIES_CONFIGVARS_H
# include <libraries/configvars.h>
#endif

#ifndef DOS_FILEHANDLER_H
# include <dos/filehandler.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID AddConfigDev( struct ConfigDev *configDev );
BOOL AddBootNode( LONG bootPri, ULONG flags, struct DeviceNode *deviceNode, struct ConfigDev *configDev );
VOID AllocBoardMem( ULONG slotSpec );
struct ConfigDev *AllocConfigDev( VOID );
APTR AllocExpansionMem( ULONG numSlots, ULONG slotAlign );
VOID ConfigBoard( APTR board, struct ConfigDev *configDev );
VOID ConfigChain( APTR baseAddr );
struct ConfigDev *FindConfigDev( CONST struct ConfigDev *oldConfigDev, LONG manufacturer, LONG product );
VOID FreeBoardMem( ULONG startSlot, ULONG slotSpec );
VOID FreeConfigDev( struct ConfigDev *configDev );
VOID FreeExpansionMem( ULONG startSlot, ULONG numSlots );
UBYTE ReadExpansionByte( CONST APTR board, ULONG offset );
VOID ReadExpansionRom( CONST APTR board, struct ConfigDev *configDev );
VOID RemConfigDev( struct ConfigDev *configDev );
VOID WriteExpansionByte( APTR board, ULONG offset, ULONG byte );
VOID ObtainConfigBinding( VOID );
VOID ReleaseConfigBinding( VOID );
VOID SetCurrentBinding( struct CurrentBinding *currentBinding, ULONG bindingSize );
ULONG GetCurrentBinding( CONST struct CurrentBinding *currentBinding, ULONG bindingSize );
struct DeviceNode *MakeDosNode( CONST APTR parmPacket );
BOOL AddDosNode( LONG bootPri, ULONG flags, struct DeviceNode *deviceNode );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_EXPANSION_PROTOS_H */
