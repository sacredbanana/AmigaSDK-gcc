#ifndef DOS_VAR_H
#define DOS_VAR_H
/*
**    $VER: var.h  54.100 (07.09.2020)
**
**    include file for dos local and environment variables
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

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
/* The structure in the pr_LocalVars list;
   Do NOT allocate yourself, use SetVar()!!! This structure may grow in
   future releases!  The list should be left in alphabetical order, and
   can have multiple entries with the same name but different types. */

struct LocalVar
{
    struct Node    lv_Node;
    uint16         lv_Flags;
    STRPTR         lv_Value;
    int32          lv_Len;
};

/*
 * The LocalVar->lv_Node.ln_Name points to the name buffer.
 *
 * The LocalVar->lv_Node.ln_Type is used by the system to identify var type,
 * its value is derrived from (lv_Flags & LV_TYPE_MASK).
 *
 * The LocalVar->lv_Node.ln_Pri is reserved for system use.
 */


/****************************************************************************/
/* Definitions for LocalVar types: */

#define LV_VAR        0     /* a variable */
#define LV_ALIAS      1     /* an alias   */

#define LV_TYPE_MASK  0xFF  /* mask the low 8 bits for the local var type */

/****************************************************************************/
/* Bit definitions of lv_Flags passed to GetVar(), SetVar(), DeleteVar(), ScanVars()
   these bit defs are OR'ed with the LV_xxx type.
   Item will be treated as a single line of text unless BINARY_VAR is specified */

/* ignore this entry on GetVar, FindVar() etc */
#define LVB_IGNORE              7 

/* only use global vars, no local vars will be accessed. */
#define GVB_GLOBAL_ONLY         8

/* only use local vars, no global vars will be accessed. */
#define GVB_LOCAL_ONLY          9

/* treat as binary var, don't truncate at a newline or carriage return char. */
#define GVB_BINARY_VAR         10

/* do not add a nul-terminator 0 byte at the end of data. */ 
#define GVB_DONT_NULL_TERM     11    /* can only be used with GVF_BINARY_VAR */

/* this is only supported in >= V39 dos.  V37 dos ignores this.
   this causes SetVar to affect ENVARC: as well as ENV: */
#define GVB_SAVE_VAR           12    /* only works with GVF_GLOBAL_VAR */

/* scan envarc: instead of env: for use in ScanVars() - v50 */
#define GVB_SCAN_ENVARC        13    /* only usefull with GLOBAL vars */

/* scan single directory level do not go into further sub directories. - v53 */
#define GVB_SCAN_LEVEL         14    /* for ScanVars() - v53 */
#define GVB_SCAN_TOPLEVEL      GVB_SCAN_LEVEL  /* old synonym */

/* causes only the ROOT DIR RELATIVE directory name which is specified with
   a c-string in 'extradata', to be the beginning of the directory scan. 
   All characters before a ":" will be skipped.  */
#define GVB_SCAN_STARTDIR      15


/****************************************************************************/
/* Field definitions for above */

#define LVF_IGNORE              (1<<LVB_IGNORE)
#define GVF_GLOBAL_ONLY         (1<<GVB_GLOBAL_ONLY)
#define GVF_LOCAL_ONLY          (1<<GVB_LOCAL_ONLY)
#define GVF_BINARY_VAR          (1<<GVB_BINARY_VAR)
#define GVF_DONT_NULL_TERM      (1<<GVB_DONT_NULL_TERM)
#define GVF_SAVE_VAR            (1<<GVB_SAVE_VAR)
#define GVF_SCAN_ENVARC         (1<<GVB_SCAN_ENVARC)
#define GVF_SCAN_LEVEL          (1<<GVB_SCAN_LEVEL)
#define GVF_SCAN_STARTDIR       (1<<GVB_SCAN_STARTDIR)
 
/* old name change */
#define GVF_SCAN_TOPLEVEL       GVF_SCAN_LEVEL

/****************************************************************************/
/* Mode value for NotifyVar() (V50) */

#define NV_REMOVE_NOTIFY_HOOK     (1<<1)  /* V50 */
#define NV_REMOVE_NOTIFY_NAME     (1<<2)  /* added 54.82  */ 
#define NV_REMOVE_NOTIFY_THISPROC (1<<3)  /* added 54.83  */   
#define NV_SCAN_NOTIFY            (1<<4)  /* added 53.122 */
#define NV_CAUSE_NOTIFY           (1<<5)  /* added 54.28  */
#define NV_ADD_NOTIFY             (1<<8)  /* V50 */


/* some old source name change compatibility */
#define NV_GLOBAL_NOTIFY          NV_ADD_NOTIFY
#define NV_REMOVE_NOTIFY          NV_REMOVE_NOTIFY_HOOK

/****************************************************************************/
/* Structure used by V50 ScanVars(). This structure may grow in future.     */
/* Check sv_SVMSize before accessing members past sv_VarLen.                */

struct ScanVarsMsg
{
    uint32   sv_SVMSize; 
    uint32   sv_Flags;
    STRPTR   sv_GDir;
    STRPTR   sv_Name;      
    STRPTR   sv_Var;
    uint32   sv_VarLen;
    APTR     sv_DosPrivate;
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

#endif /* DOS_VAR_H */
