
/* This file was generated by idltool 50.7. Do not edit */

#ifndef EXEC_TYPES_H
#include <exec/types.h>

#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

extern uint32               VARARGS68K _docky_Obtain(struct DockyIFace *);
extern uint32               VARARGS68K _docky_Release(struct DockyIFace *);
extern void                 VARARGS68K _docky_Expunge(struct DockyIFace *);
extern struct DockyIFace *  VARARGS68K _docky_Clone(struct DockyIFace *);
extern BOOL                 VARARGS68K _docky_DockyGet(struct DockyIFace *, uint32 msgType, uint32 * msgData);
extern BOOL                 VARARGS68K _docky_DockySet(struct DockyIFace *, uint32 msgType, uint32 msgData);
extern BOOL                 VARARGS68K _docky_DockyProcess(struct DockyIFace *, uint32 turnCount, uint32 * msgType, uint32 * msgData, BOOL * anotherTurn);


static void *docky_vectors[] = {
	(void *)_docky_Obtain,
	(void *)_docky_Release,
	(void *)_docky_Expunge,
	(void *)_docky_Clone,
	(void *)_docky_DockyGet,
	(void *)_docky_DockySet,
	(void *)_docky_DockyProcess,
	(void *)-1
};
