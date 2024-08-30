#ifndef __PPDPROTOS_H__
#define __PPDPROTOS_H__


#ifndef LIBRARIES_PPD_H
#include <libraries/ppd.h>
#endif

# include <sys/types.h>

PPD *OpenPPDFromPPD(STRPTR filename, PPD_ERROR *error);
PPD *OpenPPDFromIFF(STRPTR filename, PPD_ERROR *error);
PPD_ERROR PPDWritePPDToIFF(STRPTR filename, PPD *ppd);
OPTION_NODE *FindPPD_Option(PPD *ppd, STRPTR option_name);
PAGE_SIZE_NODE *FindPPD_PageSize(PPD *ppd, STRPTR pagesize_name);
void ClosePPD(PPD *ppd);
OPTION_ITEM_NODE *FindPPD_OptionItem(OPTION_NODE *option_node, STRPTR option_item_name);
ATTRIBUTE_NODE *FindPPD_Attribute(PPD *ppd, STRPTR attribute_name, STRPTR attribute_option);
PPD *OpenPPD(STRPTR filename, PPD_ERROR *error);
CUSTOM_OPTION_NODE *FindPPD_CustomOption(PPD *ppd, STRPTR custom_option_name);
CUSTOM_ITEM_NODE *FindPPD_CustomOptionItem(CUSTOM_OPTION_NODE *custom_option_node, STRPTR custom_item_name);
CONST_STRPTR FaultPPD(PPD_ERROR errcode);

#endif