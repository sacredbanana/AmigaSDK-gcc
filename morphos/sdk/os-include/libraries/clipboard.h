/*
    clipboard.library definitions

    Copyright ? 2014 Grzegorz Kraszewski. All rights reserved.
*/

#ifndef LIBRARIES_CLIPBOARD_H
#define LIBRARIES_CLIPBOARD_H


/* tags */

#define CLP_Base                       0x92000000
#define CLP_ClipUnit                   (CLP_Base + 1)
#define CLP_Charset                    (CLP_Base + 2)
#define CLP_Rectangular                (CLP_Base + 3)
#define CLP_ReadError                  (CLP_Base + 4)
#define CLP_CharCount                  (CLP_Base + 5)
#define CLP_Size					   (CLP_Base + 6)
#define CLP_SizeTerminated             (CLP_Base + 6)
#define CLP_SizeUnterminated           (CLP_Base + 7)
#define CLP_Width					   (CLP_Base + 8)
#define CLP_Height                     (CLP_Base + 9)
#define CLP_Data                       (CLP_Base + 10)
#define CLP_Format				       (CLP_Base + 11)
#define CLP_ColorMap				   (CLP_Base + 12)
#define CLP_BytesPerRow		 		   (CLP_Base + 13)
#define CLP_SecondaryData	 		   (CLP_Base + 14)

/* clip types */

#define CLIPTYPE_NONE                  0
#define CLIPTYPE_TEXT                  1
#define CLIPTYPE_AUDIO                 2
#define CLIPTYPE_IMAGE                 3

/* pixel formats */

#define CLIPPIXFMT_GRAY8			   0
#define CLIPPIXFMT_RGB24			   1
#define CLIPPIXFMT_ARGB32			   2
#define CLIPPIXFMT_LUT8			       3

/* text formats */
#define CLIPTXTFMT_PLAIN               0
#define CLIPTXTFMT_HTML                1

#endif      /* LIBRARIES_CLIPBOARD_H */
