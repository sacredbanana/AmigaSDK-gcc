#ifndef CLIB_PCIX_PROTOS_H
#define CLIB_PCIX_PROTOS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR    PCIXCreateIntObjectTagList(APTR                 MyBoardObject,
                                   ULONG                (*Code)(void),
                                   APTR                 Data,
                                   struct TagItem       *MyTags);

APTR    PCIXCreateIntObjectTags(APTR                    MyBoardObject,
                                ULONG                   (*Code)(void),
                                APTR                    Data,
                                ...);

void    PCIXDeleteIntObject(APTR                        MyIntObject);


APTR    PCIXFindBridgeTagList(APTR                      MyBridgeObject,
                              struct TagItem            *MyTags);

APTR    PCIXFindBridgeTags(APTR                         MyBridgeObject,
                           ...);

ULONG   PCIXGetBridgeAttr(APTR                          MyBridgeObject,
                          ULONG                         Attr);

ULONG   PCIXSetBridgeAttr(APTR                          MyBridgeObject,
                          ULONG                         Attr,
                          ULONG                         Data);

APTR    PCIXFindBoardTagList(APTR                       MyBoardObject,
                             struct TagItem             *MyTags);

APTR    PCIXFindBoardTags(APTR                          MyBoardObject,
                          ...);

ULONG   PCIXGetBoardAttr(APTR                           MyBoardObject,
                         ULONG                          Attr);

ULONG   PCIXSetBoardAttr(APTR                           MyBoardObject,
                         ULONG                          Attr,
                         ULONG                          Data);

ULONG   PCIXReadConfigByte(APTR                         MyBoardNode,
                           ULONG                        Offset);
ULONG   PCIXReadConfigWord(APTR                         MyBoardNode,
                           ULONG                        Offset);
ULONG   PCIXReadConfigLong(APTR                         MyBoardNode,
                           ULONG                        Offset);
ULONG   PCIXWriteConfigByte(APTR                        MyBoardNode,
                            ULONG                       Offset,
                            ULONG                       Data);
ULONG   PCIXWriteConfigWord(APTR                        MyBoardNode,
                            ULONG                       Offset,
                            ULONG                       Data);
ULONG   PCIXWriteConfigLong(APTR                        MyBoardNode,
                            ULONG                       Offset,
                            ULONG                       Data);

ULONG   PCIXModifyConfigByte(APTR                       MyBoardNode,
                             ULONG                      Offset,
                             ULONG                      Data,
                             ULONG                      Mask);
ULONG   PCIXModifyConfigWord(APTR                       MyBoardNode,
                             ULONG                      Offset,
                             ULONG                      Data,
                             ULONG                      Mask);
ULONG   PCIXModifyConfigLong(APTR                       MyBoardNode,
                             ULONG                      Offset,
                             ULONG                      Data,
                             ULONG                      Mask);


APTR    PCIXDMAGetPhysical(APTR                         MyBoardNode,
                           APTR                         MyAddress);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
