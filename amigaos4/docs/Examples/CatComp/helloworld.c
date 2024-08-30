;/*
;Sample use of CatComp
;
CatComp helloworld.cd CFILE helloworld_strings.h
CatComp helloworld.cd helloworld.ct CATALOG Catalogs/french/helloworld.catalog
gcc -o HelloWorld helloworld.c -lauto
Quit
*/

/*
Copyright (c) 2010 Hyperion Entertainment CVBA. All rights reserved.

Copyright (c) 1992-1993 Commodore-Amiga, Inc. All rights reserved.

DISCLAIMER: This software is provided "as is".  No representations or
warranties are made with respect to the accuracy, reliability, performance,
currentness, or operation of this software, and all use is at your own risk.
Neither commodore nor the authors assume any responsibility or liability
whatsoever with respect to your use of this software.
*/

#include <proto/exec.h>
#include <proto/locale.h>
#include <proto/dos.h>

#define CATCOMP_CODE
#define CATCOMP_BLOCK
#define CATCOMP_NUMBERS
#include "helloworld_strings.h"


int main()
{
struct LocaleInfo li;

    li.li_ILocale = ILocale;
    li.li_Catalog = ILocale->OpenCatalogA(NULL,"helloworld.catalog",NULL);

    IDOS->Printf("%s\n",GetString(&li,MSG_HELLO));
    IDOS->Printf("%s\n",GetString(&li,MSG_BYE));

    if (LocaleBase)
    {
        ILocale->CloseCatalog(li.li_Catalog);
        IExec->CloseLibrary(LocaleBase);
    }

	return 0;
}
