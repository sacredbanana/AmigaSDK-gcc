#ifndef INLINE4_DOCKY_H
#define INLINE4_DOCKY_H

/*
** This file was machine generated by idltool 50.7.
** Do not edit
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

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/* Inline functions for Interface "docky" */
#define DockyGet(msgType, msgData) IDocky->DockyGet(msgType, msgData) 
#define DockySet(msgType, msgData) IDocky->DockySet(msgType, msgData) 
#define DockyProcess(turnCount, msgType, msgData, anotherTurn) IDocky->DockyProcess(turnCount, msgType, msgData, anotherTurn) 

#endif /* INLINE4_DOCKY_H */
