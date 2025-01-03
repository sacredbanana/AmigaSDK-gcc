#ifndef EXEC_INITIALIZERS_H
#define EXEC_INITIALIZERS_H

/*
	exec initializer definitions (V50)

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#define OFFSET(structName,structEntry)  (&(((struct structName*)0)->structEntry))

#define INITBYTE(offset,value)  0xe000, (UWORD) (offset),(UWORD) ((value) << 8)

#define INITWORD(offset,value)  0xd000, (UWORD) (offset),(UWORD) (value)

#define INITLONG(offset,value)  0xc000, (UWORD) (offset), \
                                        (UWORD) ((value) >> 16), \
                                        (UWORD) ((value) & 0xffff)

#define INITSTRUCT(size,offset,value,count) \
                  (UWORD) (0xc000 | (size << 12) | (count << 8) | \
                  ((UWORD) ((offset) >> 16)), \
                  ((UWORD) (offset)) & 0xffff)

#endif
