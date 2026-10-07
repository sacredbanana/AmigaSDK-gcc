#ifndef EXEC_ERRORS_H
#define EXEC_ERRORS_H
/*
** Standard Device IO Errors (returned in io_Error)
**
** Copyright 1985-2001 Amiga, Inc.
**
** Copyright 2002-2019 Trevor Dickinson.
*/

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

enum enDeviceIOErrors
{
    IOERR_SUCCESS    = ( 0), /* no error */
    IOERR_OPENFAIL   = (-1), /* device/unit failed to open */
    IOERR_ABORTED    = (-2), /* request terminated early [after AbortIO()] */
    IOERR_NOCMD      = (-3), /* command not supported by device */
    IOERR_BADLENGTH  = (-4), /* not a valid length (usually IO_LENGTH) */
    IOERR_BADADDRESS = (-5), /* invalid address (misaligned or bad range) */
    IOERR_UNITBUSY   = (-6), /* device opens ok, but requested unit is busy */
    IOERR_SELFTEST   = (-7)  /* hardware failed self-test */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_ERRORS_H */
