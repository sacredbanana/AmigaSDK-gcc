;/* sift.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -j73 sift.c
Blink FROM LIB:c.o,sift.o TO sift LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

*
* sift.c:	Takes any IFF file and tells you what's in it.  Verifies
*		syntax and all that cool stuff.
*
* Usage: sift -c		; For clipboard scanning
*    or  sift <file>		; For DOS file scanning
*
* Reads the specified stream and prints an IFFCheck-like listing of the
* contents of the IFF file, if any.  Stream is a DOS file for <file>
* argument, or is the clipboard's primary clip for -c.
* This program must be run from a CLI.
*
* Based on original sift.c by by Stuart Ferguson and Leo Schwab
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <libraries/dos.h>
#include <libraries/iffparse.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/iffparse_protos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

#define MINARGS 2

/* 2.0 Version string for c:Version to find */
UBYTE vers[] = "\0$VER: sift 37.1";

UBYTE usage[] = "Usage: sift IFFfilename (or -c for clipboard)";

/* proto for our function */
void PrintTopChunk (struct IFFHandle *);

/*
 * Text error messages for possible IFFERR_#? returns from various
 * IFF routines.  To get the index into this array, take your IFFERR code,
 * negate it, and subtract one.
 *  idx = -error - 1;
 */
char	*errormsgs[] = {
	"End of file (not an error).",
	"End of context (not an error).",
	"No lexical scope.",
	"Insufficient memory.",
	"Stream read error.",
	"Stream write error.",
	"Stream seek error.",
	"File is corrupt.",
	"IFF syntax error.",
	"Not an IFF file.",
	"Required call-back hook missing.",
	"Return to client.  You should never see this."
};

struct Library *IFFParseBase;


void main(int argc, char **argv)
{
    struct IFFHandle	*iff = NULL;
    long		error;
    short		cbio;

    	/* if not enough args or '?', print usage */
    	if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
		{
	    	printf("%s\n",usage);
	    	goto bye;
	    	}

	/*
	 * Check to see if we are doing I/O to the Clipboard.
	 */
	cbio = (argv[1][0] == '-'  &&  argv[1][1] == 'c');

	if (!(IFFParseBase = OpenLibrary ("iffparse.library", 0L)))
		{
		puts("Can't open iff parsing library.");
		goto bye;
		}

	/*
	 * Allocate IFF_File structure.
	 */
	if (!(iff = AllocIFF ()))
		{
		puts ("AllocIFF() failed.");
		goto bye;
		}

	/*
	 * Internal support is provided for both AmigaDOS files, and the
	 * clipboard.device.  This bizarre 'if' statement performs the
	 * appropriate machinations for each case.
	 */
	if (cbio)
		{
		/*
		 * Set up IFF_File for Clipboard I/O.
		 */
		if (!(iff->iff_Stream =
				(ULONG) OpenClipboard (PRIMARY_CLIP)))
			{
			puts ("Clipboard open failed.");
			goto bye;
			}
		InitIFFasClip (iff);
		}
	else
		{
		/*
		 * Set up IFF_File for AmigaDOS I/O.
		 */
		if (!(iff->iff_Stream = Open (argv[1], MODE_OLDFILE)))
			{
			puts ("File open failed.");
			goto bye;
			}
		InitIFFasDOS (iff);
		}

	/*
	 * Start the IFF transaction.
	 */
	if (error = OpenIFF (iff, IFFF_READ))
		{
		puts ("OpenIFF failed.");
		goto bye;
		}

	while (1)
		{
		/*
		 * The interesting bit.  IFFPARSE_RAWSTEP permits us to
		 * have precision monitoring of the parsing process, which
		 * is necessary if we wish to print the structure of an
		 * IFF file.  ParseIFF() with _RAWSTEP will return the
		 * following things for the following reasons:
		 *
		 * Return code:			Reason:
		 * 0				Entered new context.
		 * IFFERR_EOC			About to leave a context.
		 * IFFERR_EOF			Encountered end-of-file.
		 * <anything else>		A parsing error.
		 */
		error = ParseIFF (iff, IFFPARSE_RAWSTEP);

		/*
		 * Since we're only interested in when we enter a context,
		 * we "discard" end-of-context (_EOC) events.
		 */
		if (error == IFFERR_EOC)
			continue;
		else if (error)
			/*
			 * Leave the loop if there is any other error.
			 */
			break;

		/*
		 * If we get here, error was zero.
		 * Print out the current state of affairs.
		 */
		PrintTopChunk (iff);
		}

	/*
	 * If error was IFFERR_EOF, then the parser encountered the end of
	 * the file without problems.  Otherwise, we print a diagnostic.
	 */
	if (error == IFFERR_EOF)
		puts ("File scan complete.");
	else
		printf ("File scan aborted, error %ld: %s\n",
			error, errormsgs[-error - 1]);

bye:
	if (iff) {
		/*
		 * Terminate the IFF transaction with the stream.  Free
		 * all associated structures.
		 */
		CloseIFF (iff);

		/*
		 * Close the stream itself.
		 */
		if (iff->iff_Stream)
			if (cbio)
				CloseClipboard ((struct ClipboardHandle *)
						iff->iff_Stream);
			else
				Close (iff->iff_Stream);

		/*
		 * Free the IFF_File structure itself.
		 */
		FreeIFF (iff);
		}
	if (IFFParseBase)	CloseLibrary (IFFParseBase);

	exit (RETURN_OK);
}


void
PrintTopChunk (iff)
struct IFFHandle *iff;
{
	struct ContextNode	*top;
	short			i;
	char			idbuf[5];

	/*
	 * Get a pointer to the context node describing the current context.
	 */
	if (!(top = CurrentChunk (iff)))
		return;

	/*
	 * Print a series of dots equivalent to the current nesting depth of
	 * chunks processed so far.  This will cause nested chunks to be
	 * printed out indented.
	 */
	for (i = iff->iff_Depth;  i--; )
		printf (". ");

	/*
	 * Print out the current chunk's ID and size.
	 */
	printf ("%s %ld ", IDtoStr (top->cn_ID, idbuf), top->cn_Size);

	/*
	 * Print the current chunk's type, with a newline.
	 */
	puts (IDtoStr (top->cn_Type, idbuf));
}

