#ifndef LIBRARIES_PPD_H
#define LIBRARIES_PPD_H

/*
**  ppd.h - PostScript Printer Description parser header    
**  (c) 2012-2018 Michal Zukowski and MorphOS Team
**  
*/

#ifndef EXEC_TYPES_H
#include <sys/types.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#define NAME_LEN_MAX	     81	

#  ifdef __cplusplus
extern "C" {
#  endif 

typedef enum
{
	PPD_ERR_OK,
	PPD_ERR_BADHEADER,
	PPD_ERR_SYNTAX,
	PPD_ERR_MEMORY,
	PPD_ERR_FILE,
	PPD_ERR_EOF,
	PPD_ERR_PREFS
} 
PPD_ERROR;	
		

typedef enum   				
{
	PPD_OPT_BOOL,
	PPD_OPT_SINGLESELECT,
	PPD_OPT_MULTISELECT
} OPTION_TYPE;

typedef enum 
{
	PPD_TR_NONE,		    // device doesn't have Type 42 rasterizer
	PPD_TR_ACCEPT68K,       // device has M68K rasterizer
	PPD_TR_TYPE24,          // device has Type 42 rasterizer
	PPD_TR_TRUEIMAGE        // device has TrueImage resterizer
} TTRASTERIZER;

typedef enum
{
	PPD_SECTION_ANY,        // any place in the postscript file
	PPD_SECTION_DOCUMENT,	// only in document setup
	PPD_SECTION_EXIT,       // to be sent before document
	PPD_SECTION_PAGESETUP,	// to be sent in page setup
	PPD_SECTION_PROLOG,		// to be sent in prolog		
	PPD_SECTION_JCL,		// sent as JCL command			
} OPTION_SECTION;


typedef enum 
{
	PPD_CM_GRAY,
	PPD_CM_COLOR
} COLOR_MODE;

typedef enum 
{
	PPD_CS_GRAY,             // gray colorspace
	PPD_CS_CMYK,             // cmyk colorspace
	PPD_CS_CMY,				 // cmy  colorspace
	PPD_CS_RGB,	             // rgb  colorspace
	PPD_CS_RGBK,			 // rgb+gray colorspace	
	PPD_CS_N				 // device colorspace
} COLOR_SPACE;

typedef enum 
{
	PPD_LO_PLUS90,
	PPD_LO_ANY,
	PPD_LO_MINUS90
} LANDSCAPE_ORIENTATION;



typedef struct
{
	struct MinNode   Node;    
	STRPTR	Name;	
	STRPTR	Full_Name;		
	STRPTR	PS_Code;
	LONG	Left_Margin;
	LONG	Right_Margin;	   
	LONG	Top_Margin;
	LONG	Bottom_Margin;
	LONG	Width;
	LONG	Height;
} PAGE_SIZE_NODE;


typedef struct  
{
	struct MinNode   Node;    
	STRPTR		Name;		
	STRPTR		Full_Name;	
	STRPTR		PS_Code; 
} OPTION_ITEM_NODE;


typedef struct		
{		
	struct MinNode		Node;   
	STRPTR				Name;	
	STRPTR				Full_Name;	
	struct MinList		Items;  
} GROUP_NODE;


typedef struct		
{		
	struct MinNode		Node;    
	STRPTR				Name;	
	STRPTR				Full_Name;	
	OPTION_ITEM_NODE	*Default;
	OPTION_ITEM_NODE 	*Selected;
	OPTION_TYPE			Type;
	OPTION_SECTION		Section; 
	LONG				Order;
	struct MinList		Items;
} OPTION_NODE;


typedef struct
{
	struct MinNode	Node;  
	STRPTR 			Name;  
	OPTION_NODE		*Option;	
	struct MinList  Items;

} CUSTOM_OPTION_NODE;

typedef enum 		
{
  PPD_CUSTOM_CURVE,			
  PPD_CUSTOM_INTEGER,			
  PPD_CUSTOM_INVCURVE,			
  PPD_CUSTOM_PASSCODE,			
  PPD_CUSTOM_PASSWORD,			
  PPD_CUSTOM_POINTS,		
  PPD_CUSTOM_FLOAT,		
  PPD_CUSTOM_STRING			
} CUSTOM_TYPE;


typedef union
{
  FLOAT		Curve;		
  LONG		Integer;		
  FLOAT		Invcurve;
  STRPTR	Passcode;	
  STRPTR	Password;	
  FLOAT		Points;		
  FLOAT		Float;		
  STRPTR	String;		
  LONG      TextLen;
} CUSTOM_VALUE;


typedef struct
{
	struct MinNode	Node;  
	STRPTR			Name;
	STRPTR			Full_Name;	
	LONG			Order;			
	CUSTOM_TYPE		Type;	
	CUSTOM_VALUE	Minimum;
	CUSTOM_VALUE  	Maximum;		
	CUSTOM_VALUE	Current;
} CUSTOM_ITEM_NODE;


typedef struct 
{
	struct MinNode   Node;    
	STRPTR	Option1;
	STRPTR	Value1;
	STRPTR	Option2;
	STRPTR	Value2;
} CONSTRAINT_NODE;



typedef struct 
{
	struct MinNode   Node;    
	STRPTR Font_Name;
} FONT_NODE;


typedef struct 
{
	struct MinNode   Node;    
	STRPTR		Resolution;
	STRPTR		Media_Type;
	float		Density;	
	float		Gamma;		
	float		Matrix[3][3];		
} PROFILE_NODE;



typedef struct
{
 	LONG			PS_Level;			// 1, 2 or 3
    LONG        	Throughput;         // pages per minute
	COLOR_MODE		Color_Mode;
	COLOR_SPACE     Color_Space;
    TTRASTERIZER	TTRasterizer;
	LANDSCAPE_ORIENTATION Landscape_Orientation;  // -90, Any, +90
	BOOL 			Print_PSErrors;
	LONG			HW_Left_Margin;
	LONG			HW_Right_Margin;	   
	LONG			HW_Top_Margin;
	LONG			HW_Bottom_Margin;
	BOOL            Variable_PageSize;
	BYTE			Filters;
	BYTE			Model_Number;
	BYTE			Manual_Copies;
	BYTE			Flip_Duplex;
	BYTE			Unused[60];
} PRINTER_PARAMS;


typedef struct 
{
    struct MinNode   Node;    
	STRPTR Name;
	STRPTR Value;
	STRPTR Option;

} ATTRIBUTE_NODE;

typedef struct
{
	char Nick_Name[NAME_LEN_MAX];			// name of device
	char PCFile_Name[NAME_LEN_MAX];
	char Model_Name[NAME_LEN_MAX];
	char Manufacturer[NAME_LEN_MAX];
	char Language_Version[NAME_LEN_MAX];
	char Language_Encoding[NAME_LEN_MAX];
} PRINTER_DESC;

typedef struct 
{
	PRINTER_DESC	Description;		
    PRINTER_PARAMS 	Parameters;
	STRPTR			JCL_Begin;		// start JCL cmds
	STRPTR			JCL_ToPS;
	STRPTR			JCL_End;		// end JCL cmds 
    STRPTR 			DefaultFont;
	PAGE_SIZE_NODE* DefaultPageSize;
	PAGE_SIZE_NODE* SelectedPageSize;
	struct MinList	Fonts;
	struct MinList	PageSizes;
	struct MinList	Constraints;
	struct MinList  Attributes;
	struct MinList  CustomOptions;
	struct MinList  ColorProfiles;
	struct MinList  Groups;
} PPD;


# ifdef __cplusplus
}
# endif 

#endif

