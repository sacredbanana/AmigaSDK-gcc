#ifndef HUNK_INTERFACE_DEF_H
#define HUNK_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_HUNK_H
#include <libraries/hunk.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef INTERFACES_HUNK_H
#include <interfaces/hunk.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct HunkIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct HunkIFace *Self);
	ULONG APICALL (*Release)(struct HunkIFace *Self);
	void APICALL (*Expunge)(struct HunkIFace *Self);
	struct Interface * APICALL (*Clone)(struct HunkIFace *Self);
	BPTR APICALL (*LoadHunk)(struct HunkIFace *Self, const struct TagItem * tags);
	BPTR APICALL (*LoadHunkTags)(struct HunkIFace *Self, ...);
	VOID APICALL (*UnLoadHunk)(struct HunkIFace *Self, const struct TagItem * tags);
	VOID APICALL (*UnLoadHunkTags)(struct HunkIFace *Self, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* HUNK_INTERFACE_DEF_H */
