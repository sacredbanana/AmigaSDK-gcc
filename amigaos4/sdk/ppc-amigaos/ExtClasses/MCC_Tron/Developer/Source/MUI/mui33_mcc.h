/*

	MCC fix for MUI 3.3

	mui33_mcc.h

*/

#ifndef MUI_MUI33_MCC_H
#define MUI_MUI33_MCC_H

#define MUIM_GetConfigItem                  0x80423edb /* V11 */

#define MUIM_Settingsgroup_ConfigToGadgets  0x80427043 /* V11 */
#define MUIM_Settingsgroup_GadgetsToConfig  0x80425242 /* V11 */

struct  MUIP_Settingsgroup_ConfigToGadgets  { ULONG MethodID; Object *configdata; };
struct  MUIP_Settingsgroup_GadgetsToConfig  { ULONG MethodID; Object *configdata; };

#define MUIM_Dataspace_Find                 0x8042832c /* V11 */

#endif /* MUI_MUI33_MCC_H */

