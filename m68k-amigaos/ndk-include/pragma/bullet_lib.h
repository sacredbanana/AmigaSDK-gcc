#ifndef PRAGMA_BULLET_LIB_H
#define PRAGMA_BULLET_LIB_H

/*
**	$VER: bullet_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BULLET_PROTOS_H
#include <clib/bullet_protos.h>
#endif /* CLIB_BULLET_PROTOS_H */

/* "bullet.library" */
#pragma amicall(BulletBase, 0x1e, OpenEngine())
#pragma amicall(BulletBase, 0x24, CloseEngine(a0))
#pragma amicall(BulletBase, 0x2a, SetInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(BulletBase, 0x2a, SetInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(BulletBase, 0x30, ObtainInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(BulletBase, 0x30, ObtainInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(BulletBase, 0x36, ReleaseInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(BulletBase, 0x36, ReleaseInfo(a0,a1))
#endif /* __STORM__ */

#endif /* PRAGMA_BULLET_LIB_H */
