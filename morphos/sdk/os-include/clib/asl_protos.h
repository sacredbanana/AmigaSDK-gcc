#ifndef CLIB_ASL_PROTOS_H
#define CLIB_ASL_PROTOS_H

/*
	asl.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_ASL_H
# include <libraries/asl.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct FileRequester *AllocFileRequest( VOID );
VOID FreeFileRequest( struct FileRequester *fileReq );
BOOL RequestFile( struct FileRequester *fileReq );
APTR AllocAslRequest( ULONG reqType, struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
APTR AllocAslRequestTags( ULONG reqType, Tag tag1, ... );
#endif
VOID FreeAslRequest( APTR requester );
BOOL AslRequest( APTR requester, struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
BOOL AslRequestTags( APTR requester, Tag tag1, ... );
#endif
VOID AbortAslRequest( APTR requester );
VOID ActivateAslRequest( APTR requester );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_ASL_PROTOS_H */
