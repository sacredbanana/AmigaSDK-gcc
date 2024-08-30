#ifndef CLASSES_AREXX_H
#define CLASSES_AREXX_H

/*
	arexx.class definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_MEMORY_H
# include <exec/memory.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef DOS_RDARGS_H
# include <dos/rdargs.h>
#endif

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif

#ifndef REXX_RXSLIB_H
# include <rexx/rxslib.h>
#endif

#ifndef REXX_ERRORS_H
# include <rexx/errors.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#pragma pack(2)


/* Tags supported by arexx.class */

#define AREXX_Dummy         (REACTION_Dummy + 0x30000)
#define AREXX_HostName      (AREXX_Dummy + 1)
#define AREXX_DefExtension  (AREXX_Dummy + 2)
#define AREXX_Commands      (AREXX_Dummy + 3)
#define AREXX_ErrorCode     (AREXX_Dummy + 4)
#define AREXX_SigMask       (AREXX_Dummy + 5)
#define AREXX_NoSlot        (AREXX_Dummy + 6)
#define AREXX_ReplyHook     (AREXX_Dummy + 7)
#define AREXX_MsgPort       (AREXX_Dummy + 8)


/* Possible error result codes */

#define RXERR_NO_COMMAND_LIST      (1L)
#define RXERR_NO_PORT_NAME         (2L)
#define RXERR_PORT_ALREADY_EXISTS  (3L)
#define RXERR_OUT_OF_MEMORY        (4L)


/* Typo-correction. Don't use! */

#define AREXX_DefExtention	AREXX_DefExtension


/* Methods supported by arexx.class */

#define AM_HANDLEEVENT  (0x590001)
#define AM_EXECUTE      (0x590002)
#define AM_FLUSH        (0x590003)


/* AM_EXECUTE message */

struct apExecute
{
	ULONG    MethodID;
	STRPTR   ape_CommandString;
	STRPTR   ape_PortName;
	LONG    *ape_RC;
	LONG    *ape_RC2;
	STRPTR  *ape_Result;
	BPTR     ape_IO;
};


/* An array of these structures must be passed at object-creation */

struct ARexxCmd
{
	STRPTR  ac_Name;
	UWORD   ac_ID;

	VOID  (*ac_Func)(VOID);	/* VOID ac_Func(struct ARexxCmd *A0, struct RexxMsg *A1) */

	STRPTR  ac_ArgTemplate;
	ULONG   ac_Flags;
	ULONG  *ac_ArgList;
	LONG    ac_RC;
	LONG    ac_RC2;
	STRPTR  ac_Result;
};


#pragma pack()

#endif /* CLASSES_AREXX_H */
