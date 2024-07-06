/*
** This little program can be used to convert an ILBM brush
** to something that MUI's Bodychunk class can understand.
**
** Perfect for about logos and stuff like that...
**
** Have fun,
** Stefan.
*/

/* SMAKE */

#include "exec/types.h"
#include "exec/memory.h"
#include "libraries/dos.h"
#include "libraries/iffparse.h"
#include "datatypes/pictureclass.h"
#include "graphics/gfx.h"
#include "proto/dos.h"
#include "proto/iffparse.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"


#define to32(c) (((c)<<24)|((c)<<16)|((c)<<8)|(c))


int main(int argc,char **argv)
{
	char name[100],uname[100],*c;
	struct IFFHandle *iff;
	struct ContextNode *cn;
	struct StoredProperty *sp;
	struct BitMapHeader *bmhd;
	UBYTE *body;
	int size,i;
	UBYTE *cols;

	if (argc<2 || argc>3 || argv[1][0]=='?')
	{
		printf("Syntax: %s ilbm-file\n",argv[0]);
		exit(20);
	}

	stccpy(name,argv[1],100);
	if (c=strchr(name,'.')) *c=0;
	strcpy(uname,name);
	for (c=uname;*c;c++)
		*c=toupper(*c);

	if (iff=AllocIFF())
	{
		if (iff->iff_Stream=Open(argv[1],MODE_OLDFILE))
		{
			InitIFFasDOS(iff);

			if (!OpenIFF(iff,IFFF_READ))
			{
				if (!ParseIFF(iff,IFFPARSE_STEP))
				{
					if ((cn=CurrentChunk(iff)) && (cn->cn_ID==ID_FORM))
					{
						if (cn->cn_Type==ID_ILBM)
						{
							if (!PropChunk(iff,ID_ILBM,ID_BMHD) &&
							    !PropChunk(iff,ID_ILBM,ID_CMAP) &&
							    !StopChunk(iff,ID_ILBM,ID_BODY) &&
							    !StopOnExit(iff,ID_ILBM,ID_FORM) &&
							    !ParseIFF(iff,IFFPARSE_SCAN))
							{
								if (sp=FindProp(iff,ID_ILBM,ID_CMAP))
								{
							    	cols = (UBYTE *)sp->sp_Data;

									printf("#ifdef USE_%s_COLORS\n",uname);
									printf("const ULONG %s_colors[%ld] =\n{\n",name,sp->sp_Size);
									for (i=0;i<sp->sp_Size;i+=3)
										printf("\t0x%08lx,0x%08lx,0x%08lx,\n",to32(cols[i]),to32(cols[i+1]),to32(cols[i+2]));
									printf("};\n");
									printf("#endif\n\n");
								}

								if (sp=FindProp(iff,ID_ILBM,ID_BMHD))
								{
									bmhd = (struct BitMapHeader *)sp->sp_Data;

									if ((bmhd->bmh_Compression==cmpNone) || (bmhd->bmh_Compression==cmpByteRun1))
									{
										size = CurrentChunk(iff)->cn_Size;

										if (body=malloc(size))
										{
											if (ReadChunkBytes(iff,body,size)==size)
											{
												fprintf(stderr,"Width %d Height %d Depth %d - converting...\n",bmhd->bmh_Width,bmhd->bmh_Height,bmhd->bmh_Depth);

												printf("#define %s_WIDTH       %3d\n",uname,bmhd->bmh_Width);
												printf("#define %s_HEIGHT      %3d\n",uname,bmhd->bmh_Height);
												printf("#define %s_DEPTH       %3d\n",uname,bmhd->bmh_Depth);
												printf("#define %s_COMPRESSION %3d\n",uname,bmhd->bmh_Compression);
												printf("#define %s_MASKING     %3d\n",uname,bmhd->bmh_Masking);
												printf("\n");

												printf("#ifdef USE_%s_HEADER\n",uname);
												printf("const struct BitMapHeader %s_header =\n{ %ld,%ld,%ld,%ld,%ld,%ld,%ld,0,%ld,%ld,%ld,%ld,%ld };\n",name,bmhd->bmh_Width,bmhd->bmh_Height,bmhd->bmh_Left,bmhd->bmh_Top,bmhd->bmh_Depth,bmhd->bmh_Masking,bmhd->bmh_Compression,bmhd->bmh_Transparent,bmhd->bmh_XAspect,bmhd->bmh_YAspect,bmhd->bmh_PageWidth,bmhd->bmh_PageHeight);
												printf("#endif\n\n");

												printf("#ifdef USE_%s_BODY\n",uname);
												printf("const UBYTE %s_body[%ld] = {\n",name,size);
												for (i=0;i<size;i++)
												{
													printf("0x%02lx,",body[i]);
													if (!((i+1)%15)) printf("\n");
												}
												printf(" };\n");
												printf("#endif\n");
											}
											free(body);
										}
									}
								}
							}
						}
					}
				}
				CloseIFF(iff);
			}
			Close(iff->iff_Stream);
		}
		FreeIFF(iff);
	}
	return(0);
}
