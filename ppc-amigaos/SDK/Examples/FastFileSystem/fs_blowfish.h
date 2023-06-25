/*
 * $Id: fs_blowfish.h,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 * :ts=4
 *
 * 'C' implementation of the Blowfish algorithm,
 * by Paul Kocher <pck@netcom.com>
 */

#ifndef _FS_BLOWFISH_H
#define _FS_BLOWFISH_H

/****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/****************************************************************************/

struct blowfish_context
{
	ULONG P[16 + 2];
	ULONG S[4][256];
};

/****************************************************************************/

struct blowfish_data
{
	ULONG left;
	ULONG right;
};

/****************************************************************************/

VOID blowfish_encrypt(struct blowfish_context *context, struct blowfish_data *from, struct blowfish_data *to);
VOID blowfish_decrypt(struct blowfish_context *context, struct blowfish_data *from, struct blowfish_data *to);
VOID blowfish_init(struct blowfish_context *context, UBYTE * key, LONG keyLen);

/****************************************************************************/

#endif /* _FS_BLOWFISH_H */
