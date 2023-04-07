#ifndef TEXTEDIT_PLUGIN_H
#define TEXTEDIT_PLUGIN_H

#include <exec/types.h>
#include <dos/dos.h>

/************************************************************************
*									*
*    plugin support stuff						*
*									*
************************************************************************/

/* This is the link structure, which allows us to detect a proper plugin */
struct PluginHead {
    ULONG 	      ph_Security;    /* should be PLUGINHEAD_SECURITY */
    ULONG 	      ph_ID;	      /* must be say FILETYPEPLUGINHEAD_ID or EXTENSIONPLUGINHEAD_ID */
    BPTR                ph_SegList;     /* set to zero in plugins */
    struct PluginHead * ph_Next;        /* set to zero in plugins */
    UWORD 	      ph_Version;     /* set to PLUGINHEAD_VERSION */
    UWORD 	      ph_Reserved;    /* only for alignment */
    STRPTR	      ph_VersString;  /* pointer to $VER: string */
    struct Plugin *     ph_FirstPlugin; /* pointer to first plugin */
};

#define PLUGINHEAD_SECURITY	0x70FF4E75 /* MOVEQ #-1,D0 and RTS */
#define PLUGINHEAD_VERSION	1
#define MASTER_VERSION 2 /* the version of this master */

/* There should be no need to modify the PluginHead structure! Only the
   ID field should be changed for each project, as this part must be
   individual.
*/

/* And this is the data structure we use */
struct Plugin {
    struct Plugin * p_Next;    /* pointer to next plugin */
    UWORD p_Version;        /* set to say FILETYPEPLUGIN_VERSION or EXTENSIONPLUGIN_VERSION*/
    UWORD p_MasterVersion;  /* set to MASTER_VERSION */
    UWORD p_PluginVersion;  /* the version of this plugin - not checked by textedit */
    UWORD p_PluginRevision; /* and the revision - not checked by textedit*/
    UWORD p_Identifier;     /* an ID to replace internal plugins */
    UWORD p_Flags;          /* some flags to define plugin type */

    /* Now the real data comes */
	void __ASM__ (*init)(__REG__(a0, APTR userData));
};

void InitPlugins(STRPTR plugindir, ULONG headerID, struct Plugin *dummyPlugin, struct PluginHead *dummyPluginHead);
void ReleasePlugins(struct Plugin *dummyPlugin, struct PluginHead *dummyPluginHead);

#endif /* TEXTEDIT_PLUGIN_H */
