#ifndef	CLIB_WHATIS_PROTOS_H
#define	CLIB_WHATIS_PROTOS_H	1

/*
**	$Filename: libraries/whatisbase.h $
**	$Release: 3
**	$Revision: 2 $
**	$Date: 92/12/13 $
**
**	(C) Copyright 1990,1992 S.R. & P.C.
**		All Rights Reserved
*/

/*
 *	Most function return a private FileType (ULONG), this FileType can change
 *	of format at any time. Don't assume anything about it except
 *	FileType == NULL means TYPE_UNSCANNED
 */

FileType WhatIs(char *Name, struct TagItem *TagArray);
char *GetIDString(FileType Type);								/* return a READONLY C string you can use for diplaying */
char *GetIconName(FileType Type);								/* Get default icon file name, READONLY String */
FileType GetIDType(char *IdString); 							/* used to search a particular Type, if not found return TYPE_UNKNOWNIDSTRING */
WORD CmpFileType(FileType Type1, FileType Type2);			/* used for sorting the type, if (Type1 == Type2) return 0; if ( Type1 > Type2) return >0;  if ( Type1 < Type2) return <0; */
ULONG GetIDStringMaxLen(void);									/* Max strlen() of all file types */
FileType FirstType(void);											/* Get the first Type: used to get the list of type */
FileType NextType(FileType Type);								/* When NextType() == NULL you reach the end of the list */
FileType ParentFileType(FileType Type);						/* Return the parent type of the type you passed, return NULL if no parent exist */
BOOL IsSubTypeOf(FileType Type, FileType ParentType);		/* Is the type 'Type' a subtype of the type 'ParentType', return TRUE if yes */
APTR MakeTypeInfos( ULONG SizeOfInfo);					/* return a Handle on private type info, you pass size of your info data for one FileType */
void *GetTypeInfo( APTR Handle, FileType Type);				/* return ptr on your data for this FileType */
void FreeTypeInfos( APTR Handle);
/*
 *	if AskReparse() returns 0, file was successfully parsed.
 *	if InstallTypes() failed, return <0
 *	if Now is not possible, return >0;
 */

long AskReparse(BOOL Now);	/* if Now = TRUE, you ask a reparse now, this can be done only if you are the only owner of the lib ( else reparse was deffered). After Reparse the Type you have are no longuer valid */

FileType WhatIsTags(char *Name, Tag FirstTag, ...);

#endif

