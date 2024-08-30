/* 

CgmRadio - Playlist file parser

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

#include "main.h"

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <libvstring.h>

#define PPS_LOOK_FOR_SECTION   0
#define PPS_LOOK_FOR_COUNT     1
#define PPS_LOOK_FOR_ENTRY     2
#define PPS_ERROR              3

void GetStreamsFromPlaylist(STRPTR filename, struct List *stream_list)
{
	BPTR playlist;
	char linebuf[256];
	BOOL in_playlist = FALSE;
	LONG counter = 0;
	LONG number_of_entries = 0;
	LONG entry = 1;
	BYTE state = PPS_LOOK_FOR_SECTION;

	if (playlist = Open(filename, MODE_OLDFILE))
	{
		while ((state != PPS_ERROR) && FGets(playlist, linebuf, 256))
		{
			counter++;
			if (linebuf[0] == 0x00) continue;     // empty line
			if (linebuf[0] == ';') continue;      // comment
			if (linebuf[0] == '#') continue;      // alternative comment
			StrTrim(linebuf, " \t\r\n");          // strip tabs, spaces, CR, LF

			switch (state)
			{
				case PPS_LOOK_FOR_SECTION:
					if (Stricmp(linebuf, "[playlist]") == 0) state = PPS_LOOK_FOR_COUNT;
					else
					{
						state = PPS_ERROR;
						Printf("Expected \"[playlist]\" in line %ld of \"%s\".\n", counter, filename);
					}
				break;

				case PPS_LOOK_FOR_COUNT:
					if (Strnicmp(linebuf, "numberofentries=", 16) == 0)
					{
						if (StrToLong(StrChr('=', linebuf) + 1, &number_of_entries) > 0) state = PPS_LOOK_FOR_ENTRY;
						else
						{
							state = PPS_ERROR;
							Printf("Malformed NumberOfEntries in line %ld of \"%s\".\n", counter, filename);
						}
					}
					else
					{
						state = PPS_ERROR;
						Printf("Expected \"NumberOfEntries\" in line %ld of \"%s\".\n", counter, filename);
					}
				break;

				case PPS_LOOK_FOR_ENTRY:
				{
					if (entry <= number_of_entries)
					{
						char opbuf[20];
						char *stream_name = NULL;
						struct Node *n;

						FmtPut(opbuf, "file%ld=", entry);

						if (Strnicmp(opbuf, linebuf, StrLen(opbuf)) == 0)
						{
							if (stream_name = StrNew(StrChr('=', linebuf) + 1))
							{
								if (StrNEqu(stream_name, "http://", 7)) stream_name += 7;

								if (n = AllocTaskPooled(sizeof(struct Node)))
								{
									n->ln_Name = (STRPTR)stream_name;
									AddTail((struct List*)stream_list, n);
								}
							}
						}

						entry++;
					}
					else state = PPS_ERROR;
				}
			}
		}

		Close(playlist);
	}
}
