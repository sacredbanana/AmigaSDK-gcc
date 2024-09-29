#ifndef INLINE4_BATTCLOCK_H
#define INLINE4_BATTCLOCK_H

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


/* Inline macros for Interface "main" */
#define ResetBattClock() IBattClock->ResetBattClock() 
#define ReadBattClock() IBattClock->ReadBattClock() 
#define WriteBattClock(time) IBattClock->WriteBattClock(time) 

#endif /* INLINE4_BATTCLOCK_H */