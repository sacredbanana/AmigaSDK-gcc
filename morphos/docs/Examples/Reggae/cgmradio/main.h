/*

CgmRadio (c) 2013-2014 Grzegorz Kraszewski

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
  
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
   
3. The name of the author may not be used to endorse or promote products derived
   from this software without specific prior written permission.
   
This software is provided by the author "as is" and any express or implied
warranties, including, but not limited to, the implied warranties of merchant-
ability and fitness for a particular purpose are disclaimed. In no event shall
the author be liable for any direct, indirect, incidental, special, exemplary,
or consequential damages (including, but not limited to, procurement of substi-
tute goods or services; loss of use, data, or profits; or business interruption)
however caused and on any theory of liability, whether in contract, strict
liability, or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.

*/

#define APP_NAME "CgmRadio"
#define APP_VER "2.1"
#define APP_DATE "04.01.2019"
#define APP_CYEARS "2013-2014, 2019"
#define APP_AUTHOR "Grzegorz Kraszewski, Michal Zukowski"

typedef char* STRPTR;
typedef const char* CONST_STRPTR;
#define STRPTR_TYPEDEF

#define UNUSED __attribute__((unused))
#define __NOLIBBASE__

#include <exec/libraries.h>

extern struct Library
	*UtilityBase,
	*DOSBase;

