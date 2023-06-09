#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef __INLINE_STUB_H
#define __INLINE_STUB_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_NODES_H
#include <exec/lists.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
#endif
#ifndef LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif

struct AnchorPath;
struct AnimOb;
struct AreaInfo;
struct BitMap;
struct BitScaleArgs;
struct Bob;
struct Border;
struct Catalog;
struct CardHandle;
struct ClipboardHandle;
struct ClipRect;
struct ClockData;
struct ColorMap;
struct ColorWheelRGB;
struct ColorWheelHSB;
struct ConfigDev;
struct CSource;
struct CopList;
struct CurrentBinding;
struct DataBase;
struct DateStamp;
struct DateTime;
struct Device;
struct DeviceNode;
struct DeviceTData;
struct DiskObject;
struct DosLibrary;
struct DosList;
struct DevProc;
struct DosPacket;
struct DrawInfo;
struct EasyStruct;
struct EClockVal;
struct ExAllControl;
struct ExAllData;
struct ExecBase;
struct ExpansionBase;
struct FileInfoBlock;
struct FileLock;
struct FileRequester;
struct FontContentsHeader;
struct FreeList;
struct Gadget;
struct GadgetInfo;
struct GelsInfo;
struct GlyphEngine;
struct GlyphMap;
struct GfxBase;
struct HelpNode;
struct Hook;
struct IClass;
struct Image;
struct InfoData;
struct InputEvent;
struct Interrupt;
struct IntuiText;
struct IntuitionBase;
struct IORequest;
struct KeyMap;
struct KeyQuery;
struct Layer;
struct Layer_Info;
struct Library;
struct List;
struct Locale;
struct LocaleBase;
struct MathIEEEBase;
struct MemHeader;
struct MemList;
struct Menu;
struct MenuItem;
struct Message;
struct MiscResource;
struct MsgPort;
struct NamedObject;
struct Node;
struct NewAmigaGuide;
struct NewGadget;
struct NewMenu;
struct NewScreen;
struct NewWindow;
struct NotifyRequest;
struct Preferences;
struct RDArgs;
struct RastPort;
struct RealTimeBase;
struct RecordLock;
struct Rectangle;
struct Region;
struct Remember;
struct Requester;
struct ReqToolsBase;
struct Resident;
struct RexxMsg;
struct RomBootBase;
struct RxsLib;
struct Screen;
struct Semaphore;
struct SignalSemaphore;
struct SimpleSprite;
struct TagItem;
struct Task;
struct TextAttr;
struct TextExtent;
struct TextFont;
struct TimeVal;
struct UCopList;
struct View;
struct ViewPort;
struct VSprite;
struct WBObject;
struct Window;

struct bltnode;
struct cprlist;
struct gpLayout;
struct dtPrint;

#endif /* __INLINE_STUB_H */
