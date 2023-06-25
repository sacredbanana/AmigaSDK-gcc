#ifndef EXEC_INTERFACES_H
#define EXEC_INTERFACES_H
/*
**    $VER: interfaces.h 53.29 (10.8.2015)
**
**    New-style library interface
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   AMIGA_COMPILER_H
#include <amiga_compiler.h>
#endif

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

/*
** The interface is the new way for exec libraries.
** Basically, the interface is embedded in a table of
** function pointers similar to the old library jump table.
**
** FIXME: Add some more documentation
*/

struct InterfaceData
{
    struct Node     Link;              /* Node for linking several interfaces */   
    struct Library *LibBase;           /* Library this interface belongs to */     

    uint32          RefCount;          /* Reference count */                       
    uint32          Version;           /* Version number of the interface */       
    uint32          Flags;             /* Various flags (see below) */             
    uint32          CheckSum;          /* Checksum of the interface */             
    uint32          PositiveSize;      /* Size of the function pointer part, (with this struct) */     
    uint32          NegativeSize;      /* Size of the data area */
    APTR            IExecPrivate;      /* Private copy of IExec */
    APTR            EnvironmentVector; /* Base address for base relative code */
    uint32          Reserved3;
    uint32          Reserved4;
};


/*
** Flags for the Flags field in interfaces and as flags parameter for GetInterface
*/
enum enInterfaceFlags
{
    IFLF_NONE          = 0x0000, // No flags
    IFLF_PROTECTED     = 0x0001, // This interface can't be SetMethod'd
    IFLF_NOT_NATIVE    = 0x0002, // Interface is 68k
    IFLF_PRIVATE       = 0x0004, // Interface is a private, non-shareable instance
    IFLF_CHANGED       = 0x0008, // Interface has been changed, ready for re-summing
    IFLF_UNMODIFIED    = 0x0010, // Interface is unmodified. This flag will be set
                                 // if the interface is created, and reset as soon
                                 // as someone uses SetMethod on it.
    IFLF_CLONED        = 0x0020, // Interface was created by Clone method and will
                                 // have to be freed via Expunge(). Interface
                                 // implementors must set this bit in Clone().
    IFLF_CLONE_EXPUNGE = 0x0040  // Call Expunge() on cloned interface when the
                                 // reference count reaches zero. (V53.31)
};


/*
** Generic interface
** This is a generic interface structure that can be used
** everywhere when no specific interface is required/available.
*/

struct Interface
{
    struct InterfaceData Data; /* Interface data area */

    uint32 APICALL             (*Obtain) (struct Interface *Self); /* Increment reference count */
    uint32 APICALL             (*Release)(struct Interface *Self); /* Decrement reference count */
	APTR APICALL               (*Expunge)(struct Interface *Self); /* Destroy interface. May be NULL */
    struct Interface * APICALL (*Clone)  (struct Interface *Self); /* Clone interface. May be NULL */
};


/*
** Init function used by MakeInterface
*/
typedef struct Interface * (*IFACEINITFUNC)(struct Library *ownerLib,
                                            struct Interface *newIFace,
                                            struct Interface *exec);


/*
** Tag items for MakeInterface taglists
*/

#define MIT_VectorTable  (TAG_USER + 1) // Pointer to function vectors
#define MIT_InitData     (TAG_USER + 2) // Pointer to an InitData() style table
#define MIT_InitFunc     (TAG_USER + 3) // Pointer to a function to be invoked
                                        // when initializing
#define MIT_DataSize     (TAG_USER + 4) // Size of data area
#define MIT_Flags        (TAG_USER + 5) // Interface flags 
                                        // (see enInterfaceFlags)
#define MIT_Version      (TAG_USER + 6) // Major version for the interface
#define MIT_Name         (TAG_USER + 9) // Interface name


/*
** Tags for GetInterface
*/
#define GIT_FLAGS (TAG_USER + 1)    /* Flags to match */


/*
** Library management and device management interface
** See the NDK for more information
*/

struct LibraryManagerInterface
{
    struct InterfaceData Data;

    uint32             APICALL (*Obtain) (struct LibraryManagerInterface *Self);
    uint32             APICALL (*Release)(struct LibraryManagerInterface *Self);
	APTR               APICALL (*Expunge)(struct LibraryManagerInterface *Self);
    struct Interface * APICALL (*Clone)  (struct LibraryManagerInterface *Self);

    struct Library *   APICALL (*Open)        (struct LibraryManagerInterface *Self,
                                               uint32 version);
    APTR               APICALL (*Close)       (struct LibraryManagerInterface *Self);
    APTR               APICALL (*LibExpunge)  (struct LibraryManagerInterface *Self);
    struct Interface * APICALL (*GetInterface)(struct LibraryManagerInterface *Self,
                                               STRPTR name, uint32 version,
                                               struct TagItem *taglist);
};

struct DeviceManagerInterface
{
    struct InterfaceData Data;
    
    uint32             APICALL (*Obtain) (struct DeviceManagerInterface *Self);
    uint32             APICALL (*Release)(struct DeviceManagerInterface *Self);
	APTR               APICALL (*Expunge)(struct DeviceManagerInterface *Self);
    struct Interface * APICALL (*Clone)  (struct DeviceManagerInterface *Self);

    /* the return value from Open() must be placed in ior->io_Error. In earlier
     * releases of this include the function was returning an int32 which was/is
     * wrong.
     */
    VOID               APICALL (*Open)        (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior, uint32 unit,
                                               uint32 flags);
    APTR               APICALL (*Close)       (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
    APTR               APICALL (*LibExpunge)  (struct DeviceManagerInterface *Self);
    struct Interface * APICALL (*GetInterface)(struct DeviceManagerInterface *Self,
                                               STRPTR name, uint32 version,
                                               struct TagItem *taglist);

    VOID               APICALL (*BeginIO)     (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
    VOID               APICALL (*AbortIO)     (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
};

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_INTERFACES_H */
