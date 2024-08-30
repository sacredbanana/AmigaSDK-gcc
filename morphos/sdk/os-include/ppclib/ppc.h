#ifndef POWERUP_PPCLIB_PPC_H
#define POWERUP_PPCLIB_PPC_H

#include <utility/tagitem.h>

/* PPCGetInfo() Tags */

#define	PPCINFOTAG_Dummy		(TAG_USER + 0x1f000)

/* Version of the CPU
 * (Get)
 */
#define	PPCINFOTAG_CPU			(PPCINFOTAG_Dummy + 0x1)

/* CPU Count
 * (Get)
 */
#define	PPCINFOTAG_CPUCOUNT		(PPCINFOTAG_Dummy + 0x2)

/* Clock of the CPU
 * (Get)
 */
#define	PPCINFOTAG_CPUCLOCK		(PPCINFOTAG_Dummy + 0x3)

/* Revision of the CPU
 * (Get)
 */
#define	PPCINFOTAG_CPUREV		(PPCINFOTAG_Dummy + 0x4)

/* Default ExceptionHook
 * If you want to install an ExceptionHook
 * to catch all exceptions by a debugger for example
 * (Get/Set)
 */
#define	PPCINFOTAG_EXCEPTIONHOOK	(PPCINFOTAG_Dummy + 0x5)

/* Add PPCCreateTask Hook (V45)
 * If you want to be notified when a new PPC Task
 * is created. Usable for a debugger or a Task Viewer.
 *
 * BOOL CallHookPkt(YourHookHook, TaskObject, TaskHookMsg);
 *
 * If you want to install a new TrapHandler you can do it
 * now in your Hook function. Or tell the Task to stop at the
 * first instruction.
 * The PPC Task is initiated after all Hook functions complete.
 * The result defines if potential hooks should not be called.
 * If you return TRUE no other hooks are called.
 * (Set)
 */
#define	PPCINFOTAG_TASKHOOK	(PPCINFOTAG_Dummy + 0x6)

/* Remove a TaskHook (V45)
 * (Set)
 */
#define	PPCINFOTAG_REMTASKHOOK	(PPCINFOTAG_Dummy + 0x7)

/* PLL Devider of the CPU (V45)
 * (Get)
 */
#define	PPCINFOTAG_CPUPLL	(PPCINFOTAG_Dummy + 0x8)


/* BusClock of the CPU (V47)
 * (Get)
 */
#define	PPCINFOTAG_CPUBUSCLOCK	(PPCINFOTAG_Dummy + 0x9)


struct TaskHookMsg_Create
{
	ULONG		MethodID;
	ULONG		Version;
	void		*ElfObject;
	struct TagItem	*Tags;
};

struct TaskHookMsg_Delete
{
	ULONG		MethodID;
	ULONG		Version;
};

struct TaskHookMsg_Get
{
	ULONG		MethodID;
	ULONG		Version;
	struct TagItem	*Tags;
};

struct TaskHookMsg_Set
{
	ULONG		MethodID;
	ULONG		Version;
	struct TagItem	*Tags;
};

#define	PPCTASKHOOKMETHOD_CREATE	0
#define	PPCTASKHOOKMETHOD_DELETE	1
#define	PPCTASKHOOKMETHOD_GET		2
#define	PPCTASKHOOKMETHOD_SET		3


/* Current known PowerPC CPU versions */
#define	CPU_603		3
#define	CPU_604		4
#define	CPU_602		5
#define	CPU_603e	6
#define	CPU_603p	7
#define	CPU_604e	9

#endif
