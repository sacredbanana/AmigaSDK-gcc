#include <exec/types.h>
#include <clib/alib_protos.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/wb.h>
#include <libraries/application.h>
#include <proto/application.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

extern struct ExecIFace *IExec;
struct Library *ApplicationBase=NULL;
struct PrefsObjectsIFace *IPrefsObjects=NULL;
extern struct DOSIFace *IDOS;

void retaintest(void)
{
	PrefsObject *array, *string;
	STRPTR str;
	LONG count;

	printf("RETAINTEST ****************************\n");

	array=IPrefsObjects->PrefsArray(NULL, NULL,
									ALPO_Alloc, 0,
									TAG_DONE);

	string=IPrefsObjects->PrefsString(NULL, NULL,
										 ALPOSTR_AllocSetString, (ULONG)"Some text...",
										 TAG_DONE);


	IPrefsObjects->PrefsArray(array, NULL,
						 ALPOARR_GetCount, (ULONG)&count,
						 TAG_DONE);
	printf("Array contains currently %ld items.\n", count);


	printf("Adding string object to array...\n");
	IPrefsObjects->PrefsArray(array, NULL,
						 ALPOARR_AddObj, (ULONG)string,
						 TAG_DONE);


	IPrefsObjects->PrefsArray(array, NULL,
						 ALPOARR_GetCount, (ULONG)&count,
						 TAG_DONE);
	printf("Array contains now %ld items.\n", count);


	printf("Retain'ing string object to prevent it from being released by the array object...\n");
	printf("Normally, adding and object transfers the ownership to an array or dictionary.\n");
	IPrefsObjects->PrefsString(string, NULL,
							ALPO_Retain, 0,
							TAG_DONE);

	printf("Releasing array [does implicitely a release of all stored objects, too!]\n");
	IPrefsObjects->PrefsArray(array, NULL,
						 ALPO_Release, 0,
						 TAG_DONE);


	IPrefsObjects->PrefsString(string, NULL,
							ALPOSTR_GetString, (ULONG)&str,
							TAG_DONE);
	printf("The string is still valid. its content is \"%s\".\n", str);


	printf("Now, a release is necessary as we transferred the ownership to the user code previously.\n");
	IPrefsObjects->PrefsString(string, NULL,
							ALPO_Release, 0,
							TAG_DONE);

	printf("***************************************\n\n");
}


void writetest(void)
{
	PrefsObject *dict;
	ULONG err=0;
	BPTR file;

	printf("WRITETEST *****************************\n");

	dict=IPrefsObjects->PrefsDictionary(NULL, NULL, ALPO_Alloc, 0, TAG_DONE);

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsString(NULL, &err, ALPOSTR_AllocSetString, (ULONG)"ÄÖÜäöü This\nis\\a<String>!", TAG_DONE), // string with some special characters
										"a string");

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsString(NULL, &err, ALPOSTR_AllocSetString, (ULONG)"ÄÖÜäöüßæå<>&", TAG_DONE), // string with foreign characters
										"schlüssel<>&");

	{
		struct ALPOUniString uni;
		ULONG chars[10];
		uni.string=chars;

		chars[0]='H';
		chars[1]='e';
		chars[2]='l';
		chars[3]='l';
		chars[4]='o';
		uni.length=5;

		IPrefsObjects->DictSetObjectForKey(dict,
											IPrefsObjects->PrefsString(NULL, &err, ALPOSTR_AllocSetUniString, (ULONG)&uni, TAG_DONE), // unicode string
											"unicode");
	}

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 42, TAG_DONE),
										"answer of THE question");

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 23, TAG_DONE),
										"a mystery");

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsArray(NULL, NULL,
															 ALPO_Alloc, 0,
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 1, TAG_DONE),
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 2, TAG_DONE),
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 3, TAG_DONE),
															 TAG_DONE),
										"this is an array");


	file = IDOS->Open("sys:Prefs.info", MODE_OLDFILE);
	if (file)
	{
		UBYTE *buffer;
		ULONG l;

		l=IDOS->GetFileSize(file);

		if (l>0)
		{
			buffer = IExec->AllocVecTags( l,
						AVT_Type, MEMF_SHARED,
						AVT_ClearWithValue, 0,
						TAG_DONE);
			if (buffer)
			{
				if (IDOS->Read(file, buffer, l)==l)
				{
					struct ALPOBinData bd;

					printf("%ld bytes read as binary data!\n", l);

					bd.data=buffer;
					bd.size=l;

					err=0;

					IPrefsObjects->DictSetObjectForKey(dict,
														IPrefsObjects->PrefsBinary(NULL, &err, ALPOBIN_AllocWithData, (ULONG)&bd, TAG_DONE),
														"binary data");
				}
				IExec->FreeVec(buffer);
			}
		}
		IDOS->Close(file);
	}


	if (!IPrefsObjects->WritePrefs( dict, WRITEPREFS_FileName, (ULONG)"ram:test.xml", TAG_DONE))
		printf("writing successful.\n");
	else
		printf("writing not successful.\n");

	IPrefsObjects->PrefsDictionary(dict, NULL, ALPO_Release, 0, TAG_DONE);

	printf("***************************************\n\n");
}


void readtest(void)
{
	PrefsObject *dict;
	ULONG err=0;
	BPTR file;

	printf("READTEST ******************************\n");

	dict = IPrefsObjects->PrefsDictionary(NULL, NULL, ALPO_Alloc, 0, TAG_DONE);

	err = IPrefsObjects->ReadPrefs(dict, READPREFS_FileName, (ULONG)"ram:test.xml", TAG_DONE);

	if (err)
	{
		printf("prefs read error: %08lx\n", err);
	}
	else
	{
		PrefsObject *bin, *array;

		// --- get the encoded binary data
		bin = IPrefsObjects->DictGetObjectForKey(dict, "binary data");
		if (bin)
		{
			file=IDOS->Open("ram:test.info", MODE_NEWFILE);
			if (file)
			{
				UBYTE *buffer=NULL;
				ULONG l;

				IPrefsObjects->PrefsBinary(bin, NULL, ALPOBIN_GetSize, (ULONG)&l, TAG_DONE);
				IPrefsObjects->PrefsBinary(bin, NULL, ALPOBIN_GetData, (ULONG)&buffer, TAG_DONE);

				if (buffer)
					IDOS->Write(file, buffer, l);

				IDOS->Close(file);
			}
		}

		// --- show the contents of the array
		array = IPrefsObjects->DictGetObjectForKey(dict, "this is an array");
		if (array)
		{
			LONG count;
			struct ALPOObjIndex oi;

			IPrefsObjects->PrefsArray(array, NULL, ALPOARR_GetCount, &count, TAG_DONE);

			for(oi.index=0; oi.index<count; oi.index++)
			{
				IPrefsObjects->PrefsArray(array, NULL, ALPOARR_GetObjAtIndex, &oi, TAG_DONE);
				if (oi.obj)
				{
					ULONG err;
					LONG l;

					printf("object %ld: ", oi.index);

					IPrefsObjects->PrefsNumber(oi.obj, &err, ALPONUM_GetLong, &l, TAG_DONE);
					if (!err)
						printf("number=%ld\n", l);
					else
						printf("error [not a number?]\n");
				}
			}
		}

		printf("string :%s:\n", IPrefsObjects->DictGetStringForKey(dict, "a string", "string not found. this is the default."));

		printf("string :%s:\n", IPrefsObjects->DictGetStringForKey(dict, "schlüssel<>&", "some default string"));
	}

	IPrefsObjects->PrefsDictionary(dict, NULL, ALPO_Release, 0, TAG_DONE);

	printf("***************************************\n\n");
}


void filePutProc(int32 c, struct ALPOPutProcInfo *pi)
{
	if (c)
		((struct DOSIFace *)pi->basePtr)->FPutC((BPTR)pi->handlePtr, (LONG) c);
}

void serializetest(void)
{
	struct ALPOPutProcInfo pi;
	PrefsObject *dict, *obj;

	printf("SERIALIZETEST *************************\n");

	dict=IPrefsObjects->PrefsDictionary(NULL, NULL, ALPO_Alloc, 0, TAG_DONE);

	// --- add some objectd
	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 42, TAG_DONE),
										"answer of THE question");

	IPrefsObjects->DictSetObjectForKey(dict,
										IPrefsObjects->PrefsString(NULL, NULL, ALPOSTR_AllocSetString, (ULONG)"ÄÖÜäöü<my&string>!", TAG_DONE),
										"some unicode test");

	IPrefsObjects->DictSetObjectForKey(dict,
										obj=IPrefsObjects->PrefsArray(NULL, NULL,
															 ALPO_Alloc, 0,
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 1, TAG_DONE),
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 2, TAG_DONE),
															 ALPOARR_AddObj, (ULONG)IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, 3, TAG_DONE),
															 TAG_DONE),
										"this is an array");

	printf("--- serialize the whole XML structure\n");
	pi.putChProc = filePutProc;
	pi.basePtr   = (APTR)IDOS;
	pi.handlePtr = (APTR)IDOS->Output();
	pi.tabDepth  = 0;
	pi.encoding  = ALPOENC_ISO8859;//ALPOENC_UTF8;

	IPrefsObjects->WritePrefs(dict, WRITEPREFS_PutProcInfo, (ULONG)&pi, TAG_DONE);

	printf("--- serialize only one object -------\n");

	IPrefsObjects->PrefsArray(obj, NULL, ALPO_Serialize, (ULONG)&pi, TAG_DONE);

	IPrefsObjects->PrefsDictionary(dict, NULL, ALPO_Release, 0, TAG_DONE);

	printf("***************************************\n\n");
}


int main(void)
{
	signal(SIGINT, SIG_IGN);

	ApplicationBase = IExec->OpenLibrary("application.library", 50);
	if (ApplicationBase)
	{
		if (!(IPrefsObjects = (struct PrefsObjectsIFace *)IExec->GetInterface(ApplicationBase, "prefsobjects", 2, NULL)))
			IDOS->Printf("*** Error: Unable to open application.library/prefsobjects interface!\n");
	}
	else IDOS->Printf("*** Error: Unable to open application.library!\n");

	if (IPrefsObjects)
	{
		IDOS->Printf("Interfaces opened.\n");

		retaintest();

		writetest();

		readtest();

		serializetest();
	}

	if (IPrefsObjects)
		IExec->DropInterface((struct Interface *)IPrefsObjects);
	if (ApplicationBase)
		IExec->CloseLibrary(ApplicationBase);

	return 0;
}

