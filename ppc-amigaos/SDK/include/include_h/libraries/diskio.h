#ifndef LIBRARIES_DISKIO_H
#define LIBRARIES_DISKIO_H

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct DiskIO; /* This is a library private structure, do not touch! */

/* Tags for IDiskIO->Setup() */
#define DIOS_Dummy          (TAG_USER)
#define DIOS_Cache          (DIOS_Dummy + 1) /* (BOOL) Enable/disable I/O cache */
#define DIOS_WriteCache     (DIOS_Dummy + 2) /* (BOOL) Enable/disable caching of write operations */
#define DIOS_Inhibit        (DIOS_Dummy + 3) /* (BOOL) Inhibit filesystem */
#define DIOS_DOSType        (DIOS_Dummy + 4) /* (uint32) Check that filesystem reports the correct dostype */
#define DIOS_DOSTypeMask    (DIOS_Dummy + 5) /* (uint32) Which bits of dostype to check and which to ignore */
#define DIOS_Error          (DIOS_Dummy + 6) /* (int32 *) Error code if Setup() failed */
#define DIOS_ReadOnly       (DIOS_Dummy + 7) /* (BOOL) Enable/disable read-only mode */

/* Tags for IDiskIO->Query() */
#define DIOQ_Dummy          (TAG_USER)
#define DIOQ_DiskPresent    (DIOQ_Dummy + 1) /* (uint32) Is a disk present? */
#define DIOQ_WriteProtected (DIOQ_Dummy + 2) /* (uint32) Is it write protected? */
#define DIOQ_DiskValid      (DIOQ_Dummy + 3) /* (uint32) Is it usable? */
#define DIOQ_TotalSectors   (DIOQ_Dummy + 4) /* (uint64) Total sectors of disk/partition */
#define DIOQ_BytesPerSector (DIOQ_Dummy + 5) /* (uint32) Sector size of disk/partition */
#define DIOQ_SectorShift    (DIOQ_Dummy + 6) /* (uint32) */
#define DIOQ_SectorMask     (DIOQ_Dummy + 7) /* (uint32) */
#define DIOQ_TotalBytes     (DIOQ_Dummy + 8) /* (uint64) Total size of disk/partition */
#define DIOQ_DOSDevName     (DIOQ_Dummy + 9) /* (CONST_STRPTR) Name of DOS device ("USB0:", "DH1:") */

enum {
	DIO_SUCCESS = 0,       /* Success */
	DIO_ERROR_UNSPECIFIED, /* General catch-all error code */
	DIO_ERROR_NOMEM,       /* Not enough memory */
	DIO_ERROR_GETFSD,      /* GetDiskFileSystemData() failed */
	DIO_ERROR_DOSTYPE,     /* Didn't pass dostype check */
	DIO_ERROR_INHIBIT,     /* Inhibit() failed */
	DIO_ERROR_OPENDEVICE,  /* OpenDevice() failed */
	DIO_ERROR_NSDQUERY,    /* NSCMD_DEVICEQUERY failed or not of type NSDEVTYPE_TRACKDISK */
	DIO_ERROR_OUTOFBOUNDS, /* Out of bounds read or write access */
	DIO_ERROR_READONLY,    /* Tried to write to a read-only handle */
	DIO_ERROR_NODISK       /* No valid disk in drive */
};

typedef void (*DiskChangeHandlerFunc)(APTR udata);

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif

