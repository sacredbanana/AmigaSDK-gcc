#ifndef INLINE4_VIRTUAL_H
#define INLINE4_VIRTUAL_H

/*
** This file was auto generated by idltool 51.8.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
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

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

/* Inline macros for Interface "main" */
#define VIRTUAL_GetClass() IVirtual->VIRTUAL_GetClass() 
#define RefreshVirtualGadget(gadget, obj, window, requester) IVirtual->RefreshVirtualGadget(gadget, obj, window, requester) 
#define RethinkVirtualSize(virt_obj, rootlayout, font, screen, layoutlimits) IVirtual->RethinkVirtualSize(virt_obj, rootlayout, font, screen, layoutlimits) 

#endif /* INLINE4_VIRTUAL_H */
