#ifndef SCANNER_H
#define SCANNER_H

/*
	Copyright © 2017 The MorphOS Development Team, All Rights Reserved.
 */



#include <exec/types.h>
#include <exec/io.h>




// Non standard command for a scanner device driver
#define SCANCMD_CONTROL    CMD_NONSTD
#define SCANCMD_READOPTION CMD_NONSTD+1

// Status codes
#define SCAN_STATUS_OK           0
#define SCAN_STATUS_EOF          1
#define SCAN_STATUS_ABORTED      2

// Open error codes
#define SCAN_OPNERR_DEVICE       5
#define SCAN_OPNERR_NOT_SCANNER  6
#define SCAN_OPNERR_UNKNOWN      7
#define SCAN_OPNERR_MEMORY       8
#define SCAN_OPNERR_FATAL        9

#define SCAN_ERR_NOTSCANNING    10
#define SCAN_ERR_BUSY           11
#define SCAN_ERR_MEMORY         12
#define SCAN_ERR_READY          13
#define SCAN_ERR_PARAMETER      14
#define SCAN_ERR_HARDWARE       15
#define SCAN_ERR_COMMUNICATION  16
#define SCAN_ERR_MISC           17
#define SCAN_ERR_NOPAPER        18



// double <-> fixed point conversion
#define DOUBLE_FIX(v) ((int)   ((v)*(1 << 16)))
#define FIX_DOUBLE(v) (((double)(v)/(double)(1 << 16)))
#define FIX_INT(v) ((v)>>16)
#define INT_FIX(v) ((v)<<16)

typedef enum
{
  ID_NONE = 0,
  ID_SCANMODE,        // 1
  ID_TL_X,            // 2  /* upper left corner of scan area     */
  ID_TL_Y,            // 3  /* upper left corner of scan area     */
  ID_BR_X,            // 4  /* bottom right corner of scan area   */
  ID_BR_Y,            // 5  /* bottom right corner of scan area   */
  ID_RESOLUTION,      // 6  /* scan resolution (combined x and y) */
  ID_HALFTONEPATTERN, // 7
  ID_BRIGHTNESS,      // 8
  ID_CONTRAST,        // 9
  ID_ANALOGGAMMA,     // 10
  ID_BLACKLEVEL,      // 11  /* some times called shadow           */
  ID_WHITELEVEL,      // 12  /* some times called highlight        */
  ID_THRESHOLD,       // 13
  ID_EXPOSURETIME,    // 14
  ID_ADF,             // 15
  ID_SPEED,           // 16
  ID_NEGATIVE,        // 17
  ID_SCAN_SOURCE,     // 18
  ID_PREVIEW,         // 19
  ID_SHARPNESS,		  // 20
  ID_COLORCORRECTION, // 21
  ID_DUPLEXOFFSET,    // 22
  ID_PAGEWIDTH,       // 23
  ID_PAGEHEIGHT,      // 24
  ID_FIRMWARE,        // 25
  ID_NUMBER_OF_OPTIONS
} OptionId;

typedef enum
{
  TYPE_BOOL = 0,
  TYPE_INT,
  TYPE_FIXED,    /* Fixed point number - use DOUBLE_FIX and  */
                 /* FIX_DOUBLE macros to convert to double   */
  TYPE_STRING
} ValueType;

typedef enum
{
  UNIT_NONE = 0,         /* the value is unit-less (e.g., # of scans) */
  UNIT_PIXEL,            /* don't use!                                */
  UNIT_BIT,              /* value is number of bits                   */
  UNIT_MM,               /* value is millimeters                      */
  UNIT_DPI,              /* value is dots per inch                    */
  UNIT_PERCENT,          /* value is a percentage                     */
  UNIT_MICROSECOND       /* value is micro seconds                    */
} ValueUnit;

typedef enum
{
  CONSTRAINT_NONE = 0,
  CONSTRAINT_RANGE,
  CONSTRAINT_WORD_LIST,
  CONSTRAINT_STRING_LIST
} Constraint;


typedef struct
{
  int min;
  int max;
  int quant;
}
Range;


typedef enum
{
	FEATURE_NONE  = 0,
	FEATURE_TA    = 1,
	FEATURE_ADF   = 2
} Feature;
 
#pragma pack(2)
struct OptionDescriptor
{
  OptionId   od_optionID;
  ValueType  od_valueType;
  ValueUnit  od_valueUnit;
  Constraint od_constraintType;
  union
  {
    char** stringList;  /* Null terminated array of string values  */
    int*   numberList;  /* Legal values - numberList[0] = number   */
    Range* numberRange;
  }
  od_constraint;
  void* od_specialInfo; /* See below                               */
};
#pragma pack()

//
// If not NULL, special info has a null terminated int list 
// depending of option id:
//
//  ID_SCANMODE:        If constraint type is a list specialInfo is
//                      a pointer to an int list of scan depth values
//
//  ID_HALFTONEPATTERN: A pointer to an int list of boolean values
//                      telling if the pattern works for the
//                      corresponding scan mode
//
//  ID_BRIGHTNESS:      If ValueType is not UNIT_PERCENT and 
//  ID_CONTRAST:        constraint type is a list specialInfo is
//                      a pointer to an int list of percentage
//                      values corresponding to each value in the
//                      constraint list.
//
//  ID_THRESHOLD:       To be able to make real time threshold
//                      corrections (B/W), BetaScan scans in gray
//                      scale.
//                      Special Info is a pointer to a list of int
//                      telling BetaScan where Gray mode is. For
//                      example:
//                        if modes are:
//                          {"LineArt","Halftone","Gray","Color"}
//                        then set special info to:
//                          {2,1,2,3}
//
//                        This tells BetaScan:
//                          if mode is 0 (LineArt) scan in mode 2 (Gray)
//                          if mode is 1 (Halftone) scan in mode 1
//                          if mode is 2 (Gray) scan in mode 2
//                          if mode is 3 (Color) scan in mode 3
//  ID_SCAN_SOURCE:     If constraint type is a list specialInfo is
//                      a pointer to an int list of Feature (bitset)
// 

#pragma pack(2)
struct ScannerOptions
{
  char   so_scannerVendor[40];
  char   so_scannerModel[40];
  UBYTE  so_driverVersion;
  UBYTE  so_driverRevision;

  double so_docWidth;                      /* Paper size in mm             */
  double so_docHeight;

  UWORD  so_flags;                         /* Not used                     */
  UWORD  so_optionNum;                     /* Number of option descriptors */
  struct OptionDescriptor* so_descriptor;
};
#pragma pack()
//
// Structure to be used by controlOption routine
//
#pragma pack(2)
struct OptionValue
{
  OptionId sp_optionID;
  int      sp_value;
  ULONG    sp_flags;
};
#pragma pack()

// optionValue flags
//
#define CONTROL_SET        (1<<0)      /* Set new value              */ 
#define CONTROL_GET        (1<<1)      /* Return current value       */
                                       /* If both bits are set then  */
                                       /* SET is exec. before GET    */

#define CONTROL_ROUNDED    (1<<16)     /* Value set is not exact     */
#define CONTROL_RANGE      (1<<17)     /* Out of range - not set     */
#define CONTROL_DISABLED   (1<<18)     /* Option disabled - not set  */
#define CONTROL_INVALID    (1<<19)     /* Option not supported       */
#define CONTROL_RELOAD     (1<<20)     /* Other options are affected */

#define CONTROL_CALLMASK   0x0000FFFF
#define CONTROL_RETURNMASK 0xFFFF0000


typedef enum
{
  FORMAT_BW = 0,
  FORMAT_GRAY,                /* 8 bit gray scale                    */
  FORMAT_RED,
  FORMAT_GREEN,
  FORMAT_BLUE,
  FORMAT_RGB,                 /* Each pixel as 3 (24bit) byte RGB    */
  FORMAT_RGB_RANDOM           /* Colors separated in 8 bit red,      */
} LineFormat;                 /* green and blue components ariving   */
                              /* (posibly) in random order. Used by  */
                              /* 3 pass scanners.                    */

struct ScanInformation
{
  double     sv_xResolution;  /* actual horizontal resolution        */
  double     sv_yResolution;  /* actual vertical resolution          */
  LineFormat sv_lineFormat;   /* format of scan lines                */
  UWORD      sv_imageWidth;   /* image width in pixels               */
  UWORD      sv_imageHeight;  /* image height in pixels              */
  UWORD      sv_imageDepth;   /* image depth in bits                 */
  UWORD      sv_bytesPerLine; /* bytes per line read                 */
  ULONG      sv_Flags;        /* data information flags              */
};

struct ScanLine
{
  UBYTE*     sl_data;
  LineFormat sl_color;   /* If sv_lineFormat is FORMAT_RGB_RANDOM    */
};                       /* this is either FORMAT_RED, FORMAT_GREEN  */
                         /* or FORMAT_BLUE. Otherwise it must be the */
                         /* same as sv_lineFormat.                   */


struct ScannerIO
{
    struct IOStdReq       IOScan;
    struct ScannerOptions option;
};

#endif /* SCANNER_H */

