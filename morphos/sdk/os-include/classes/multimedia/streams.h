/*
$VER: streams.h 51.13 (27.12.2010)
*/

#ifndef CLASSES_MULTIMEDIA_STREAMS_H
#define CLASSES_MULTIMEDIA_STREAMS_H

#include <classes/multimedia/multimedia.h>


/******************************************************************************/
/**** http.stream *************************************************************/
/******************************************************************************/

#define MMA_Http_Response              (MMA_Dummy + 1100)
#define MMA_Http_Header                (MMA_Dummy + 1101)
#define MMA_Http_HeaderEntries         (MMA_Dummy + 1102)
#define MMA_Http_NetProcess            (MMA_Dummy + 1103)
#define MMA_Http_NoFailOnHttpError     (MMA_Dummy + 1104)
#define MMA_Http_ProxyServer           (MMA_Dummy + 1105)
#define MMA_Http_ProxyPort             (MMA_Dummy + 1106)
#define MMA_Http_AutoRedirect          (MMA_Dummy + 1107)
#define MMA_Http_UserAgent             (MMA_Dummy + 1108)
#define MMA_Http_ExtraHeaderFields     (MMA_Dummy + 1109)
#define MMA_Http_UserAgentOverride     (MMA_Dummy + 1110)
#define MMA_Http_ExtendedLog           (MMA_Dummy + 1111)
#define MMA_Http_ResponseCode          (MMA_Dummy + 1112)
#define MMA_Http_RequestType           (MMA_Dummy + 1113)
#define MMA_Http_PostData              (MMA_Dummy + 1114)
#define MMA_Http_Ready                 (MMA_Dummy + 1115)

#define MMM_Http_GetHeaderEntry        (MMA_Dummy + 1199)

struct mmopHttp_GetHeaderEntry
{
	ULONG MethodID;
	STRPTR EntryName;
};

/* Tag values for MMA_Http_RequestType */

#define MMV_Http_RequestType_Get          0
#define MMV_Http_RequestType_PostUrl      1  /* application/x-www-form-url-encoded */
#define MMV_Http_RequestType_PostMulti    2  /* multipart/form-data */
#define MMV_Http_RequestType_PostDirect   3  /* direct non-form data with specified MIME type */ 

/* Tags for MMA_Http_PostData tag stream */

#define MMA_Http_PostData_Name            6
#define MMA_Http_PostData_Value           7
#define MMA_Http_PostData_Charset         8
#define MMA_Http_PostData_Binary          9
#define MMA_Http_PostData_Length         10
#define MMA_Http_PostData_MimeType       11
#define MMA_Http_PostData_FileName       12
#define MMA_Http_PostData_FieldCharset   13


/******************************************************************************/
/**** datapush.stream *********************************************************/
/******************************************************************************/

#define MMA_DataPush_BufferedBytes     (MMA_Dummy + 1200)  // [..G.Q], LONG, bytes buffered in internal FIFO

#define MMM_DataPush_Push              (MMA_Dummy + 1299)

struct mmopDataPushPush
{
	ULONG MethodID;
	APTR Buffer;
	IPTR Length;
};


/******************************************************************************/
/******************************************************************************/

#endif /* CLASSES_MULTIMEDIA_STREAMS_H */
