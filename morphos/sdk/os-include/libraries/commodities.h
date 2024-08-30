#ifndef LIBRARIES_COMMODITIES_H
#define LIBRARIES_COMMODITIES_H

/*
	commodities.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


#define CxFilter(d)          CreateCxObj((LONG) CX_FILTER,     (LONG) d,      0)
#define CxSender(port,id)    CreateCxObj((LONG) CX_SEND,       (LONG) port,   (LONG) id)
#define CxSignal(task,sig)   CreateCxObj((LONG) CX_SIGNAL,     (LONG) task,   (LONG) sig)
#define CxTranslate(ie)      CreateCxObj((LONG) CX_TRANSLATE,  (LONG) ie,     0)
#define CxDebug(id)          CreateCxObj((LONG) CX_DEBUG,      (LONG) id,     0)
#define CxCustom(action,id)  CreateCxObj((LONG) CX_CUSTOM,     (LONG) action, (LONG) id)


struct NewBroker
{
	BYTE            nb_Version;
	STRPTR          nb_Name;
	STRPTR          nb_Title;
	STRPTR          nb_Descr;
	WORD            nb_Unique;
	WORD            nb_Flags;
	BYTE            nb_Pri;
	struct MsgPort *nb_Port;
	WORD            nb_ReservedChannel;
};

#define NB_VERSION  5

#define CBD_NAMELEN   24
#define CBD_TITLELEN  40
#define CBD_DESCRLEN  40

#define NBU_DUPLICATE  0
#define NBU_UNIQUE     1
#define NBU_NOTIFY     2

#define COF_SHOW_HIDE  4


#ifndef COMMODITIES_BASE_H
typedef LONG CxObj;
typedef LONG CxMsg;
#endif

typedef LONG (*PFL)(VOID);


#define CX_INVALID     0
#define CX_FILTER      1
#define CX_TYPEFILTER  2
#define CX_SEND        3
#define CX_SIGNAL      4
#define CX_TRANSLATE   5
#define CX_BROKER      6
#define CX_DEBUG       7
#define CX_CUSTOM      8
#define CX_ZERO        9


#define CXM_IEVENT  (1<<5)
#define CXM_COMMAND (1<<6)

#define CXCMD_DISABLE    (15)
#define CXCMD_ENABLE     (17)
#define CXCMD_APPEAR     (19)
#define CXCMD_DISAPPEAR  (21)
#define CXCMD_KILL       (23)
#define CXCMD_LIST_CHG   (27)
#define CXCMD_UNIQUE     (25)


struct InputXpression
{
	UBYTE ix_Version;
	UBYTE ix_Class;

	UWORD ix_Code;
	UWORD ix_CodeMask;

	UWORD ix_Qualifier;
	UWORD ix_QualMask;
	UWORD ix_QualSame;
};

typedef struct InputXpression IX;

#define IX_VERSION  2

#define IXSYM_SHIFT  1
#define IXSYM_CAPS   2
#define IXSYM_ALT    4

#define IXSYM_SHIFTMASK  (IEQUALIFIER_LSHIFT | IEQUALIFIER_RSHIFT)
#define IXSYM_CAPSMASK   (IXSYM_SHIFTMASK | IEQUALIFIER_CAPSLOCK)
#define IXSYM_ALTMASK    (IEQUALIFIER_LALT | IEQUALIFIER_RALT)

#define IX_NORMALQUALS  0x7FFF

#define NULL_IX(ix)  ((ix)->ix_Class == IECLASS_NULL)


#define CBERR_OK       0
#define CBERR_SYSERR   1
#define CBERR_DUP      2
#define CBERR_VERSION  3


#define COERR_ISNULL      1
#define COERR_NULLATTACH  2
#define COERR_BADFILTER   4
#define COERR_BADTYPE     8


#pragma pack()

#endif /* LIBRARIES_COMMODITIES_H */
