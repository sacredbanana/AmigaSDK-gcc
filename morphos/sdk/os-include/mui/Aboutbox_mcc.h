#ifndef ABOUTBOX_MCC_H
#define ABOUTBOX_MCC_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#define MUIC_Aboutbox	"Aboutbox.mcc"
#define AboutboxObject	MUI_NewObject(MUIC_Aboutbox

#define ABOXBASE(_x_) (0xFED10000 + _x_)

// STRPTR, I**
#define MUIA_Aboutbox_Credits          ABOXBASE(1)
// APTR, I**
#define MUIA_Aboutbox_LogoData         ABOXBASE(2)
// ULONG, I**
#define MUIA_Aboutbox_LogoFallbackMode ABOXBASE(3)
// STRPTR, I**
#define MUIA_Aboutbox_LogoFile         ABOXBASE(4)
// STRPTR, I**
#define MUIA_Aboutbox_Build            ABOXBASE(0x1E)


// Order in which the class will try to load the logo:
// D = from PROGDIR:(executable).info
// E = from MUIA_Aboutbox_LogoFile
// I = data in MUIA_Aboutbox_LogoData
#define MUIV_Aboutbox_LogoFallbackMode_NoLogo 0
#define MUIV_Aboutbox_LogoFallbackMode_Auto   MAKE_ID('D','E','I','\0')

#endif /* ABOUTBOX_MCC_H */
