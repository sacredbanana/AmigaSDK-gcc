#ifndef INLINE4_FILESYSBOX_H
#define INLINE4_FILESYSBOX_H

/*
** This file was auto generated by idltool 53.25.
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

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_FILESYSBOX_H
#include <libraries/filesysbox.h>
#endif
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#include <interfaces/filesysbox.h>

/* Inline macros for Interface "main" */
#define FbxQueryMountMsg(msg, attr) IFileSysBox->FbxQueryMountMsg((msg), (attr))
#define FbxSetupFS(msg, tags, ops, opssize, udata) IFileSysBox->FbxSetupFS((msg), (tags), (ops), (opssize), (udata))
#define FbxEventLoop(fs) IFileSysBox->FbxEventLoop((fs))
#define FbxCleanupFS(fs) IFileSysBox->FbxCleanupFS((fs))
#define FbxReturnMountMsg(msg, r1, r2) IFileSysBox->FbxReturnMountMsg((msg), (r1), (r2))
#define FbxFuseVersion() IFileSysBox->FbxFuseVersion()
#define FbxVersion() IFileSysBox->FbxVersion()
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define FbxSetupFSTags(msg, ops, opssize, ...) IFileSysBox->FbxSetupFSTags((msg), (ops), (opssize), __VA_ARGS__)
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define FbxSetupFSTags(msg, ops, opssize, vargs...) IFileSysBox->FbxSetupFSTags(msg, ops, opssize, ## vargs)
#endif
#define FbxSetSignalCallback(fs, func, signals) IFileSysBox->FbxSetSignalCallback((fs), (func), (signals))
#define FbxInstallTimerCallback(fs, func, period) IFileSysBox->FbxInstallTimerCallback((fs), (func), (period))
#define FbxUninstallTimerCallback(fs, cb) IFileSysBox->FbxUninstallTimerCallback((fs), (cb))
#define FbxSignalDiskChange(fs) IFileSysBox->FbxSignalDiskChange((fs))
#define FbxQueryFS(fs, tags) IFileSysBox->FbxQueryFS((fs), (tags))
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define FbxQueryFSTags(...) IFileSysBox->FbxQueryFSTags(__VA_ARGS__)
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define FbxQueryFSTags(vargs...) IFileSysBox->FbxQueryFSTags(## vargs)
#endif
#define FbxGetSysTime(fs, tv) IFileSysBox->FbxGetSysTime((fs), (tv))

#endif /* INLINE4_FILESYSBOX_H */
