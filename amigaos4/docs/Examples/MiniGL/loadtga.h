/*	load & save TGA file
 *
 *		written by Alexander Zaprjagaev
 *      modified for MiniGL by Hans-Joerg Frieden.
 */

#ifndef __LOADTGA_H__
#define __LOADTGA_H__

unsigned char *load_tga(char *name,int *width,int *height, int *bpp);
int save_tga(char *name,unsigned char *data,int width,int height);

int gen_texture(char *name, int internalformat);

#endif /* __LOADTGA_H__ */
