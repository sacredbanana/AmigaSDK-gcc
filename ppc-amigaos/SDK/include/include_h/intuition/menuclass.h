#ifndef INTUITION_MENUCLASS_H
#define INTUITION_MENUCLASS_H
/*
**    $VER: menuclass.h 54.16 (22.08.2022)
**
**    The 'boopsi' menu class interface
**
**    Copyright (c) 2011 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* Menu class attributes */

#define MA_Dummy        (TAG_USER + 0x440000)

#define MA_Type         (MA_Dummy +  1)
    /* (uint32) Type of a menuclass object. The possible types are T_ROOT
     * (a menu tree root, also known as a menu strip), T_MENU (a menu), or
     * T_ITEM (a menu item or sub-item).
     * Only applicable at OM_NEW time. Defaults to T_ROOT.
     */

#define MA_Label        (MA_Dummy +  2)
    /* (STRPTR) Label of the object, which can be either a menu title or a
     * menu (sub-)item text, depending on the object's type.
     * If instead of a string you pass an integer value lying in the range
     * defined by MA_MinStringID and MA_MaxStringID, that will go through
     * the hook specified by MA_StringHook (if any) for conversion into a
     * localized string.
     * You can embed a keyboard shortcut for a menu item directly in its
     * label, by prepending it to the actual label string and separating
     * it with a '|' (e.g. "S|Save").
     * The shortcut may also be a command string of more than one character
     * (such as "Ctrl z"). In this case, please note that Intuition will
     * display the string at the right side of the item label but won't
     * process the corresponding key combination; that has to be handled
     * separately by the application.
     * If the shortcut is a single character and MA_EmbeddedKey is TRUE,
     * you can also use a NUL ('\0') as a separator instead of '|'. This
     * may prove convenient when using an existing catalog where menu item
     * labels with shortcuts are defined this way (e.g. "S\0Save").
     * A special value for an item's label string is ML_SEPARATOR, which
     * tells menuclass the object is just a separator bar (equivalent to
     * passing MA_Separator, TRUE).
     */

#define MA_Level        (MA_Dummy +  3)
    /* (int32) How deep the object is in the menu tree. An object's level
     * also reflects its type, i.e. whether it is the menu root, a menu,
     * or a menu item. The root's level is -1, a menu has a level of zero,
     * while any level greater than zero identifies an item. The deeper
     * an item lies in the menu tree, the higher its level is: items of a
     * menu have a level of 1, sub-items of these have a level of 2, and
     * so on.
     * An appropriate initial level is implicitly set at OM_NEW time when
     * the object's type is specified via MA_Type; a type of T_ROOT sets
     * the level to -1, T_MENU sets it to zero, and T_ITEM sets it to 1.
     * (A menu item's initial level of 1 can then change when the item is
     * inserted into a menu tree, since menuclass assigns a level to each
     * object automatically according to its depth in the tree.)
     * You should never set this attribute programmatically. Applications
     * are expected to treat MA_Level as read-only.
     */

#define MA_Separator    (MA_Dummy +  4)
    /* (BOOL) If TRUE, declares the object as a separator bar between two
     * items. If this is the case, any other attribute except MA_Hidden is
     * ignored and has no meaning. Only menu item objects (T_ITEM) can be
     * separators. Defaults to FALSE.
     */

#define MA_ID           (MA_Dummy +  5)
    /* (uint32) Menu item ID assigned by the application. This is an unique
     * identifier allowing to find out which item was selected when a menu
     * event occurs. You can assign an ID also to menu titles, not just to
     * items; this is because the menu help feature offers the possibility
     * of selecting menu titles in addition to actual items.
     * For normal menu pick events, you can retrieve all selected item IDs
     * in sequence by invoking the MM_NEXTSELECT method in a loop on the
     * menu strip object until it returns NO_MENU_ID (an invalid ID value,
     * meaning "no more selections"). If the user did not perform multiple
     * selection, there will be only one ID to be retrieved. In case menu
     * operations were aborted, or terminated without selecting anything,
     * MM_NEXTSELECT will return NO_MENU_ID on the first invocation.
     * For menu help events, your application can find out which item or
     * menu title the user asked for help about by simply querying the menu
     * strip object's MA_MenuHelpID attribute (menu help doesn't support
     * multiple selection).
     * Note that by returning an absolute ID associated to the picked item
     * (arbitrarily defined by the application) rather than a "menu number"
     * encoding the position of the item within the menu tree, selections
     * of a menuclass item always yield the same result even if the item's
     * position is changed. This way you don't need to modify your event
     * handling code when you reorganize the order of menu items.
     * The ID number may be any value, except zero. This invalid value is
     * referred to as NO_MENU_ID and has about the same meaning MENUNULL
     * does for traditional menus. MA_ID defaults to NO_MENU_ID, and must
     * therefore be set to a valid value for any item or menu title that is
     * meant to be selectable by the user, or else it will never generate
     * any meaningful menu pick (or help) events.
     */

#define MA_Key          (MA_Dummy +  6)
    /* (STRPTR) Single-character keyboard shortcut or full command string
     * for the menu item object. This overrides any keyboard shortcut or
     * command string that may be embedded in the item label.
     * Note that when using a command string of more than one character,
     * Intuition will display it at the right side of the item label but
     * won't process the corresponding key combination; that has to be
     * handled by the application. Defaults to NULL (no keyboard shortcut).
     */

#define MA_Image        (MA_Dummy +  7)
    /* (struct Image *) An Intuition image, either traditional or BOOPSI, to
     * be displayed at the left side of (or in place of) the menu item label.
     * If BOOPSI, the image will be automatically disposed of when the menu
     * item object is; to avoid that, set MA_FreeImage to FALSE. Defaults to
     * NULL (no image).
     */

#define MA_Disabled     (MA_Dummy + 8)
    /* (BOOL) If TRUE, the menu title or item will appear in a disabled look
     * and won't be selectable. Disabling a menu title automatically makes
     * all of its menu items disabled as well, and disabling an item does
     * the same for all of its sub-items. Defaults to FALSE.
     */

#define MA_Toggle       (MA_Dummy + 9)
    /* (BOOL) If TRUE, the item represents an option which can be switched on
     * or off. The user will be able to toggle the state of the item between
     * checked (on) and unchecked (off), and the item will have a checkmark
     * symbol at its left side indicating its state. The actual state of the
     * item can be read at any time via the MA_Selected attribute or with the
     * MM_GETSTATE method. Defaults to FALSE.
     */

#define MA_MX           (MA_Dummy + 10)
    /* (uint32) If non-zero, the item represents an option which is mutually
     * exclusive with certain other options, that are therefore switched off
     * when this one gets switched on. The attribute's value is a bit mask
     * indicating what other items in the same menu or sub-menu panel must be
     * excluded (i.e. unselected) when the item is selected. Bit 0 represents
     * the first item, bit 1 the second one, and so on. A typical value for
     * MA_MX is ~(1 << N), with N being the bit number of the item itself:
     * that means "exclude all items except this one". A mutual exclude item
     * will have a special symbol (usually resembling a radio button) at its
     * left side indicating its state. The actual state of the item can be
     * read at any time via the MA_Selected attribute or with the MM_GETSTATE
     * method. Defaults to zero, i.e. no mutual exclusion at all.
     */

#define MA_Selected     (MA_Dummy + 11)
    /* (BOOL) The state of a toggle or mutual exclude item; if TRUE, the item
     * is checked (on), otherwise it is unchecked (off). If the object is not
     * a toggle or MX item, this attribute has no meaning. Defaults to FALSE.
     */

#define MA_UserData     (MA_Dummy + 12)
    /* (uint32) Application-specific user data which can be associated to a
     * menu or menu item object and read back at any time. Defaults to zero.
     */

#define MA_Parent       (MA_Dummy + 13)
    /* (Object *) The parent of an object in the menu tree; this will be the
     * menu root for a menu title, a menu title for a menu item, or an item
     * for a sub-item. The attribute is automatically set when a child object
     * is added to its parent, and reset to NULL upon the child's removal.
     * Defaults to NULL.
     */

#define MA_EvenSize     (MA_Dummy + 14)
    /* (BOOL) If TRUE, all children (items or sub-items) of the object will
     * have the same height, that is, the height of the tallest item.
     * Defaults to FALSE.
     */

#define MA_Hidden       (MA_Dummy + 15)
    /* (BOOL) If TRUE, this object will not appear at menu display time. If
     * this is a menu object, its title will not be shown in the menu strip;
     * if this is a (sub-)item object, its label will not be shown in the
     * (sub-)menu panel of its parent object.
     * Defaults to FALSE.
     */

#define MA_MenuHelpID   (MA_Dummy + 16)
    /* (uint32) ID number of the menu item or menu title for which the user
     * requested help during the last menu session. To obtain this you must
     * invoke OM_GET on the menu root object; do not attempt to read it from
     * any other member of the menu tree. Only query this attribute upon an
     * actual menu help event. Be prepared to handle a NO_MENU_ID value; it
     * means the user pressed the Help key while the mouse pointer was not
     * positioned over any menu title or item.
     */

#define MA_LastSelected (MA_Dummy + 17)
    /* (uint32) Index of the most recently selected child (item or sub-item)
     * of the object. Reserved for use by Intuition; do not attempt to change
     * it or rely on its value.
     */

#define MA_MenuPosX     (MA_Dummy + 18)
    /* (int32) Left edge of the main panel of a context menu. Ignored if the
     * menu tree is not used as a context menu. The value of this attribute
     * is expressed in screen pixel coordinates. If you pass the special
     * constant CMENU_CENTER_MOUSE (defined below), the menu panel will be
     * horizontally centered relative to the mouse pointer. By ORing either
     * CMENU_RIGHT or CMENU_CENTER to the desired coordinate, it will be
     * interpreted as the right edge or the center of the menu panel, rather
     * than the left edge.
     * If you pass any negative value, the default from user preferences will
     * be used.
     * It's recommended not to use this attribute without a good reason; user
     * preferences should be honored whenever possible.
     * Defaults to -1.
     */

#define MA_MenuPosY     (MA_Dummy + 19)
    /* (int32) Top edge of the main panel of a context menu. Ignored if the
     * menu tree is not used as a context menu. The value of this attribute
     * is expressed in screen pixel coordinates. If you pass the special
     * constant CMENU_CENTER_MOUSE (defined below), the menu panel will be
     * vertically centered relative to the mouse pointer. By ORing either
     * CMENU_BOTTOM or CMENU_CENTER to the desired coordinate, it will be
     * interpreted as the bottom edge or the center of the menu panel, rather
     * than the top edge.
     * If you pass any negative value, the default from user preferences will
     * be used.
     * It's recommended not to use this attribute without a good reason; user
     * preferences should be honored whenever possible.
     * Defaults to -1.
     */

#define MA_AddChild     (MA_Dummy + 50)
    /* (Object *) An object which is to become a child of the current object.
     * The child object will inherit a number of attributes from its parent,
     * except those that are explicitly set for the child.
     * Adding a child via this attribute is equivalent to doing so with the
     * OM_ADDMEMBER method, but more convenient when building a whole tree of
     * menuclass objects through a series of nested NewObject() calls.
     */

#define MA_RemoveChild  (MA_Dummy + 51)
    /* (Object *) An object which is to be removed from the list of children
     * of the current object. Removing a child object from its parent resets
     * to default values any attributes inherited from it, except those of
     * them that were explicitly set in the meantime.
     * Removing a child via this attribute is equivalent to doing so with the
     * OM_REMMEMBER method.
     */

#define MA_StringHook   (MA_Dummy + 80)
    /* (struct Hook *) A hook used for dynamic localization of menu strings.
     * Whenever the value of MA_Label or MA_Key lies in the range defined
     * by MA_MinStringID and MA_MaxStringID, it is considered a numeric
     * string ID, and menuclass invokes your hook to convert that ID to an
     * actual string.
     * The object the hook receives is the menu or item the string ID to be
     * converted belongs to.
     * The message the hook receives is a MenuStringMessage structure (see
     * below for definition) which carries the string ID. If you specify
     * a value for MA_Catalog and/or MA_CharSet, that information is also
     * passed back in the message.
     * Note: if you don't use a string hook, MA_Label and MA_Key need to be
     * real strings and not numeric IDs, otherwise they'll get converted
     * to "????", which isn't very meaningful.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to NULL.
     */

#define MA_Catalog      (MA_Dummy + 81)
    /* (struct Catalog *) A catalog used for dynamic localization of menu
     * strings. This is ignored if you don't also set MA_StringHook.
     * If you do, the catalog is passed to the string hook along with the
     * string ID and (possibly) a charset specifier.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to NULL.
     */

#define MA_MinStringID  (MA_Dummy + 82)
    /* (uint32) The lower bound of the range within which a value passed
     * via MA_Label or MA_Key must lie to be considered a string ID (used
     * for dynamic localization) rather than an actual string.
     * If this attribute is set to a number greater than the upper bound
     * of the string ID range (MA_MaxStringID), no menu string will ever
     * be interpreted as a string ID; this is the default behavior.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to ~0UL.
     */

#define MA_MaxStringID  (MA_Dummy + 83)
    /* (uint32) The upper bound of the range within which a value passed
     * via MA_Label or MA_Key must lie to be considered a string ID (used
     * for dynamic localization) rather than an actual string.
     * If this attribute is set to a number smaller than the lower bound
     * of the string ID range (MA_MinStringID), no menu string will ever
     * be interpreted as a string ID; this is the default behavior.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to 1.
     */

#define MA_CharSet      (MA_Dummy + 84)
    /* (uint32) The charset (character set) for the label and the keyboard
     * shortcut, if any, of the current menu or menu item object. The font
     * used for such strings will be adjusted, if possible, to display them
     * correctly in the specified charset.
     * The charset value is also passed back to the string hook in use, if
     * one was set via MA_StringHook.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to zero (system default charset).
     */

#define MA_TextAttr     (MA_Dummy + 85)
    /* (struct TextAttr *) The font for the item's label (and shortcut).
     * If NULL, the default screen font will be used. To also request a
     * particular charset, use MA_CharSet.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to NULL.
     */

#define MA_EmbeddedKey  (MA_Dummy + 86)
    /* (BOOL) If TRUE, menu item labels can have a single letter prepended
     * to them, separated with a NUL ('\0') character, which will be used
     * as the item's keyboard shortcut. If you need to have an item label
     * of just one letter (with no shortcut embedded in the string), set
     * this attribute to FALSE, otherwise the label will be interpreted as
     * a shortcut followed by random bytes!
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to TRUE.
     */

#define MA_FreeImage    (MA_Dummy + 87)
    /* (BOOL) If TRUE, a BOOPSI image passed via MA_Image is automatically
     * disposed of when the object itself is. Set it to FALSE if you want
     * to handle the image disposal yourself.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to TRUE.
     */

#define MA_PickHook     (MA_Dummy + 88)
    /* (struct Hook *) A custom hook which is invoked during the processing
     * of menu pick events to handle the selection of this menu item object.
     * This is achieved by using the MM_HANDLEPICK method in your event
     * handling loop in place of MM_NEXTSELECT.
     * See the MM_HANDLEPICK method autodoc for more information.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to NULL (no pick hook).
     */

#define MA_HelpHook     (MA_Dummy + 89)
    /* (struct Hook *) A custom hook which is invoked during the processing
     * of menu help events to handle a help request on this menu object.
     * This is achieved by using the MM_HANDLEHELP method in your event
     * handling loop instead of reading MA_MenuHelpID with GetAttr().
     * See the MM_HANDLEHELP method autodoc for more information.
     * This attribute is inherited by all the object's children, and all
     * their descendants as well, except those for which it is explicitly
     * set to a different value. Defaults to NULL (no help hook).
     */

#define MA_ErrorCode    (MA_Dummy + 98)
    /* (int32 *) Pointer to a longword variable to store error codes in. Note
     * that this variable will be initialized regardless of whether an error
     * occurred or not. Thus, you can check for an error condition by comparing
     * the variable contents against 0; 0 indicates success, all other values
     * are either error codes as defined by dos.library or menuclass-specific
     * error codes (see below for definitions).
     */

#define MA_ErrorTagItem (MA_Dummy + 99)
    /* (struct TagItem **) When an error occurs whilst processing the tag list
     * passed to OM_NEW, OM_SET or MM_NEWMENU, you can have a pointer to the
     * item that caused the error passed back via the MA_ErrorTagItem tag.
     * Note that for tag lists allocated from the stack the address passed back
     * to you may no longer be valid when control returns to your code.
     */

/* Possible values for MA_Type.
 */
#define T_ROOT -1  /* The menu tree root */
#define T_MENU  0  /* A menu */
#define T_ITEM  1  /* A menu item (or sub-item) */

/* MA_Label should be a text string, or the special
 * constant ML_SEPARATOR, to get a separator bar.
 * The latter is equivalent to omitting MA_Label and
 * passing MA_Separator, TRUE instead.
 */
#define ML_SEPARATOR ((STRPTR)~0UL)

/* This means "no menu selection" and must never be
 * passed as a value for the MA_ID attribute.
 */
#define NO_MENU_ID 0

/* You can OR these to the value of MA_MenuPosX or
 * MA_MenuPosY (if it is non-negative) to alter the
 * way it gets interpreted by Intuition.
 */
#define CMENU_RIGHT  (0x10000000UL)  /* Value is right edge, not left edge */
#define CMENU_BOTTOM (0x10000000UL)  /* Value is bottom edge, not top edge */
#define CMENU_CENTER (0x20000000UL)  /* Value is center, not left/top edge */

/* Special value for the MA_MenuPosX and MA_MenuPosY
 * attributes, meaning "centered relative to mouse
 * pointer".
 */
#define CMENU_CENTER_MOUSE (0x2FFFFFFFL)

/*****************************************************************************/

/* Menu method identifiers */

#define MM_FINDID     4001
    /* Return address of menu object in tree with given ID */

#define MM_SCAN       4002
    /* Do a recursive scan of menu tree with custom hook */

#define MM_NEWMENU    4003
    /* Build a whole menu (sub-)tree from a tag list */

#define MM_DELETEMENU 4004
    /* Free menu (sub-)tree built by MM_NEWMENU */

#define MM_NEXTCHILD  4005
    /* Get address of next child of a menu object */

#define MM_SETSTATE   4006
    /* Change checked/disabled attributes of item with given ID */

#define MM_GETSTATE   4007
    /* Read checked/disabled attributes of item with given ID */

#define MM_NEXTSELECT 4009
    /* Get next ID in menu item selection chain */

#define MM_HANDLEPICK 4011
    /* Browse through menu selections, invoking pick hooks */

#define MM_HANDLEHELP 4012
    /* Return menu help ID or invoke help hook if non-NULL */

#define MM_SETUP      4013
    /* Prepare a menu (sub-)tree for display; normally not needed */

#define MM_CLEANUP    4014
    /* Release all resources allocated during menu setup */

/*****************************************************************************/

/* Parameter "messages" passed to menu class methods */

/* MM_FINDID - Return the address of the menuclass
 * object having the specified ID, if it exists in
 * the menu tree, otherwise NULL.
 */
struct mpFindID
{
    uint32 MethodID;
    uint32 mpfi_Reserved;
    uint32 mpfi_ID;
};

/* MM_SCAN - Do a recursive scan of the menu tree.
 * For each object in the tree, the specified hook
 * is invoked on it and is passed a MenuScanMessage
 * structure (see below) as message.
 * If the hook returns a non-zero value, the scan
 * stops and the method returns the address of the
 * object on which it stopped. If the hook always
 * returns zero, all objects are scanned and the
 * method returns NULL.
 * The four mps_Args variables are for program use;
 * they allow to pass custom arguments to the hook.
 */
struct mpScan
{
    uint32 MethodID;
    uint32 mps_Reserved;
    struct Hook *mps_Hook;
    uint32 mps_Args[4];
};

/* MM_NEWMENU - Build a whole menu (sub-)tree from
 * a compact tag-based description, with less typing,
 * more readability, greater efficiency and better
 * error checking than doing so through a series of
 * nested NewObject() calls.
 */
struct mpNewMenu
{
    uint32 MethodID;
    uint32 mpnm_Reserved;
    struct TagItem *mpnm_AttrList;
};

/* MM_DELETEMENU - Free a whole menu (sub-)tree that
 * was built via MM_NEWMENU.
 */
struct mpDeleteMenu
{
    uint32 MethodID;
    uint32 mpdm_Reserved;
};

/* MM_NEXTCHILD - Return the object which comes
 * next after the passed one in the children list
 * of the menuclass object it's invoked on.
 * If NULL is passed for mpnc_Current, the first
 * child in the list is returned; if mpnc_Current
 * is the last child in the list, NULL is returned.
 * This method can be used in a loop to browse
 * through all children of a given object.
 */
struct mpNextChild
{
    uint32 MethodID;
    uint32 mpnc_Reserved;
    Object *mpnc_Current;
};

/* MM_SETSTATE - Change the state of the "checked"
 * and/or "disabled" attribute of the menuclass
 * object having the specified ID. The apply mask
 * defines which attributes are to be changed, and
 * the state mask what they should be changed to;
 * they can be a combination of the MS_CHECKED and
 * MS_DISABLED bits.
 */
struct mpSetState
{
    uint32 MethodID;
    uint32 mpss_Reserved;
    uint32 mpss_ID;
    uint32 mpss_ApplyMask;
    uint32 mpss_StateMask;
};

/* MM_GETSTATE - Examine the state of the "checked"
 * and "disabled" attributes of the menuclass object
 * having the specified ID. The result is a bit mask
 * with a combination of MS_CHECKED and MS_DISABLED.
 */
struct mpGetState
{
    uint32 MethodID;
    uint32 mpgs_Reserved;
    uint32 mpgs_ID;
};

/* MM_NEXTSELECT - Get the ID of the next menu item
 * picked by the user during the most recent menu
 * selection operation. To retrieve the first menu
 * item selected, pass NO_MENU_ID in mpns_CurrentID,
 * else pass the result of the previous invocation
 * of MM_NEXTSELECT which will yield the subsequent
 * ID in the selection list. As soon as NO_MENU_ID
 * is returned, there are no more IDs in the list.
 * NOTE WELL: this method should be invoked on the
 * root object of the menu tree, not on any actual
 * menu title or (sub-)item object.
 */
struct mpNextSelect
{
    uint32 MethodID;
    uint32 mpns_Reserved;
    uint32 mpns_CurrentID;
};

/* MM_HANDLEPICK - Browse through the menu selection
 * list and invoke the pick hook of each selected
 * item that has one. Every time an item with a NULL
 * pick hook is encountered in the list, stop and
 * return its ID.
 * To start the browsing and retrieve the ID of the
 * first selected menu item without a pick hook (if
 * any exists), pass NO_MENU_ID in mphe_CurrentID;
 * to resume the browsing and possibly obtain the ID
 * of the subsequent item without a pick hook found
 * in the selection list, pass instead the result of
 * the previous invocation. As soon as NO_MENU_ID is
 * returned, there are no more items in the list.
 * This method uses the same message structure as...
 *
 * MM_HANDLEHELP - Invoke the help hook of the menu
 * object the user asked for help about and then
 * return NO_MENU_ID; if the object has no help hook
 * return its ID instead. This method uses the same
 * message structure as MM_HANDLEPICK, however it
 * ignores the mphe_CurrentID field since for menu
 * help events there is no selection list to follow.
 *
 * NOTE WELL: these methods should be invoked on the
 * root object of the menu tree, not on any actual
 * menu title or (sub-)item object.
 *
 * Also note that if none of your menuclass objects
 * has a pick hook or a help hook you never need to
 * invoke these methods at all.
 */
struct mpHandleEvent
{
    uint32 MethodID;
    uint32 mphe_Reserved;
    uint32 mphe_CurrentID;
    struct Window *mphe_Window;
    APTR mphe_UserData;
};

/* MM_SETUP - Prepare a menu (sub-)tree for display
 * by allocating any needed resources and computing
 * geometric properties. Applications don't normally
 * need to invoke this method themselves; it is done
 * automatically upon the first SetMenuStrip() call
 * and whenever it is required to update the layout
 * of the menu (e.g. when changing certain menu or
 * menu item attributes).
 */
struct mpSetup
{
    uint32 MethodID;
    uint32 mps_Reserved;
    uint32 mps_Initial;
};

/****************************************************************************/

/* Special control tags for MM_NEWMENU */

#define NM_Dummy    (TAG_USER + 0x450000)

#define NM_Menu     (NM_Dummy + 1)
    /* (STRPTR) Used to add a new menu object to the menu root. The data
     * you pass for this tag is the title string of the new menu.
     * Any menuclass attributes (MA_#?) following NM_Menu, until another
     * NM_Menu or NM_Item tag is encountered in the tag list, will apply
     * to this new menu.
     * Also, until another NM_Menu tag is encountered, this new menu is
     * considered the current menu to which any subsequent NM_Item entry
     * gets added as a menu item.
     */

#define NM_Item     (NM_Dummy + 2)
    /* (STRPTR) Used to add a new menu item object to the current menu
     * (see NM_Menu). The data you pass for this tag is the label string
     * of the new menu item.
     * Any menuclass attributes (MA_#?) following NM_Item, until another
     * NM_Item or NM_Menu tag is encountered in the tag list, will apply
     * to this new menu item.
     * Also, until another NM_Item tag is encountered at the same level,
     * this new item is considered the current item to which a subsequent
     * NM_SubItems list (if any is specified; see below) gets added as a
     * chain of sub-items.
     */

#define NM_SubItems (NM_Dummy + 3)
    /* (uint32) Used to begin and end a list of sub-items of the current
     * menu item (see NM_Item). Pass this tag with a value of SI_BEGIN to
     * begin the list, and then this tag again with a value of SI_END to
     * end the same list.
     * The sub-items themselves shall be defined as one or more NM_Item
     * entries between the two enclosing NM_SubItems tags. Any one of
     * these sub-items can, in turn, have its own sub-item list by way
     * of a nested NM_SubItems block. NM_SubItems blocks can be nested
     * indefinitely, allowing for any number of sub-item levels.
     * Note that this tag is only used to begin/end a list of sub-items
     * for a NM_Item entry; it is not needed (nor allowed) when adding
     * a list of items for a NM_Menu entry.
     */

/* Values for NM_SubItems */

#define SI_BEGIN 1  /* This begins a sub-item list */
#define SI_END   0  /* This ends a sub-item list */

/* Shortcuts for faster typing */

#define NM_SUB_BEGIN NM_SubItems, SI_BEGIN
#define NM_SUB_END   NM_SubItems, SI_END
#define NM_SEPARATOR NM_Item, ML_SEPARATOR

/****************************************************************************/

/* Possible state flags for MM_SETSTATE/MM_GETSTATE */

#define MS_CHECKED  1
#define MS_DISABLED 2

/****************************************************************************/

/* The string hook specified via MA_StringHook
 * receives this message.
 */
struct MenuStringMessage
{
    uint32 StructSize;        /* For future expansion */
    uint32 StringID;          /* The string ID number */
    struct Catalog *Catalog;  /* Catalog pointer, may be NULL */
    uint32 CharSet;           /* Charset number, may be zero */
};

/* The menu scan hook passed to MM_SCAN
 * receives this message. The four Args
 * variables hold the same values which
 * were passed upon method invocation;
 * they can be used to feed your custom
 * arguments to the hook.
 */
struct MenuScanMessage
{
    uint32 StructSize;  /* For future expansion */
    int32 Level;        /* How deep we are in the menu tree */
    uint32 Args[4];     /* Custom arguments */
};

/* Pick hooks and help hooks specified via
 * MA_PickHook and MA_HelpHook receive this
 * message. The UserData field contains any
 * context information that was passed by
 * the application upon MM_HANDLEPICK or
 * MM_HANDLEHELP method invocation.
 */
struct MenuEventMessage
{
    uint32 StructSize;      /* For future expansion */
    uint32 EventType;       /* ET_MENUPICK or ET_MENUHELP */
    struct Window *Window;  /* Event window pointer */
    APTR UserData;          /* Custom data pointer */
};

/* Values for MenuEventMessage.EventType */

#define ET_MENUPICK 0
#define ET_MENUHELP 1

/****************************************************************************/

/* Menu-specific error codes MM_NEWMENU can
 * return (via MA_ErrorCode) in addition to
 * standard DOS error codes.
 */
#define ERROR_TITLE_OUT_OF_PLACE       4001
    /* A menu title was found at the wrong position in the tree. */

#define ERROR_SUBITEMS_WITHOUT_PARENT  4002
    /* A sub-item list was started without having a parent item first. */

#define ERROR_ITEM_WITHOUT_ID          4003
    /* No ID was set for a menu item or sub-item which needs one. */

#define ERROR_SEPARATOR_AT_TITLE_LEVEL 4004
    /* A separator was inserted before the first menu title. */

#define ERROR_BAD_ACTION_ON_ROOT       4005
    /* An unsupported attribute was specified for a menu root object. */

#define ERROR_BAD_ACTION_ON_MENU       4006
    /* An unsupported attribute was specified for a menu object. */

#define ERROR_BAD_ACTION_ON_ITEM       4007
    /* An unsupported attribute was specified for a menu item object. */

#define ERROR_BAD_ACTION_ON_SEPARATOR  4008
    /* An unsupported attribute was specified for a separator. */

#define ERROR_ITEM_ID_IS_ZERO          4009
    /* An ID of zero was specified for a menu item or sub-item. */

#define ERROR_COMM_KEY_AT_TITLE_LEVEL  4010
    /* A command key was specified for a menu title. */

/****************************************************************************/

/* Handy macros to make it easier to build a menu tree by hand */

#ifndef __USE_INLINE__
#define MStrip     IIntuition->NewObject(NULL, "menuclass"
#define MTitle(l)  IIntuition->NewObject(NULL, "menuclass", MA_Type, T_MENU, \
                                                            MA_Label, (l)
#define MItem(l)   IIntuition->NewObject(NULL, "menuclass", MA_Type, T_ITEM, \
                                                            MA_Label, (l)
#define MSeparator IIntuition->NewObject(NULL, "menuclass", MA_Type, T_ITEM, \
                                                            MA_Separator, TRUE
#else
#define MStrip     NewObject(NULL, "menuclass"
#define MTitle(l)  NewObject(NULL, "menuclass", MA_Type, T_MENU, \
                                                MA_Label, (l)
#define MItem(l)   NewObject(NULL, "menuclass", MA_Type, T_ITEM, \
                                                MA_Label, (l)
#define MSeparator NewObject(NULL, "menuclass", MA_Type, T_ITEM, \
                                                MA_Separator, TRUE
#endif

#ifndef End
#define End TAG_END)
#endif

#define MEnd TAG_END)

#define MStripEnd     MEnd
#define MTitleEnd     MEnd
#define MItemEnd      MEnd
#define MSeparatorEnd MEnd

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif

