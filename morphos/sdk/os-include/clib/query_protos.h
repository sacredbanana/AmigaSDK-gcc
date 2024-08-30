#ifndef	CLIB_QUERY_PROTOS_H
#define	CLIB_QUERY_PROTOS_H

#ifndef	EXEC_TYPES_H
#  include <exec/types.h>
#endif

#ifndef LIBRARIES_QUERY_H
# include <libraries/query.h>
#endif

struct TagItem;
struct Library;
struct Device;
struct Resident;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void *QueryCreatePathNode(char *MyPath,char *MyPattern, ULONG Flags);
void *QueryDeletePathNode(void *MyPathNode);
void *QueryObtainTagList(void *MyQueryInfo, struct TagItem *Tags);
void QueryRelease(void *MyQueryInfo);
ULONG QueryGetAttr(void *MyQueryInfo,APTR Data, ULONG Attr);
ULONG QueryGetLibraryAttr(struct Library *,APTR Data,ULONG Attr);
ULONG QueryGetDeviceAttr(struct Device *,APTR	Data,ULONG Attr);
ULONG QueryGetResidentAttr(struct Resident *,APTR Data,ULONG Attr);

#if !defined(USE_INLINE_STDARG)
void *QueryObtainTags(void *MyQueryInfo,...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_QUERY_PROTOS_H */
