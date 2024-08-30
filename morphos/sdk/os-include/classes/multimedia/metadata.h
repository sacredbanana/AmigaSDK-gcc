/*
$VER: metadata.h 52.23 (27.09.2015)
*/

#ifndef CLASSES_MULTIMEDIA_METADATA_H
#define CLASSES_MULTIMEDIA_METADATA_H

#include <exec/types.h>

/* Definitions of metadata interface in Reggae. */

/* MetaItem structure is for a single metadata tag. A pointer to table of     */
/* such structures is returned on query of MMA_MetaData attribute.            */

struct MetaItem
{
	ULONG mi_Id;              /* one of MMETA_xxx, defines kind of metadata */
	ULONG mi_Type;            /* one of MTYYPE_xxx, defines data structure */
	ULONG mi_Length;          /* length of data in bytes (does include Unicode string termination) */
	LONG  mi_Importance;      /* 5 levels of importance (4 is the most important, 0 is least important */
	APTR  mi_Data;            /* points to data */
};


/* This structure is used for indirect pointing to [large] metadata */
/* available at some Reggae port. Used with MTYPE_PORTNUM.          */

struct MetaPort
{
	Object*  mtp_Object; 
	ULONG    mtp_Port;
};


/* Data types. */

#define MTYPE_NO_TYPE            0
#define MTYPE_INTEGER            1    /* 32-bit signed integer                                   */
#define MTYPE_STRING             2    /* NULL-terminated string, encoded in UTF-32BE             */
#define MTYPE_CLOCKDATA          3    /* ClockData structure as defined in <utility/date.h>      */
#define MTYPE_PORTNUM            4    /* Object and port number (struct MetaPort above).         */
#define MTYPE_DOUBLE             5    /* Double precision 64-bit IEEE 754 floating point number. */

/* Importance levels. */

#define MIMP_MAIN                4    /* main identification data (title, author, album etc.) */
#define MIMP_IMPORTANT           3    /* publication date, composers, actors, director etc.   */
#define MIMP_SECONDARY           2    /* type of original media, processing, equalization...  */
#define MIMP_DETAILED            1    /* URL-s to sites, comments                             */
#define MIMP_SPAM                0    /* spam, advertisements                                 */

/* Data identifiers. */

#define MMETA_BASE               (TAG_USER + 0x000045A2)

#define MMETA_Title              (MMETA_BASE + 0)  /* [STRING]    General. Title of the work.                  */
#define MMETA_Performer          (MMETA_BASE + 1)  /* [STRING]    Music. Performer of the work.                */
#define MMETA_Comment            (MMETA_BASE + 2)  /* [STRING]    General. Just comment.                       */
#define MMETA_TrackNum           (MMETA_BASE + 3)  /* [INTEGER]   Music. Number of track in album.             */
#define MMETA_Album              (MMETA_BASE + 4)  /* [STRING]    Music. Name of the album.                    */
#define MMETA_PubDate            (MMETA_BASE + 5)  /* [CLOCKDATA] General. Date of publication.                */
#define MMETA_Author             (MMETA_BASE + 6)  /* [STRING]    General. Author of the work.                 */
#define MMETA_Copyright          (MMETA_BASE + 7)  /* [STRING]    General. Copyright string of the work.       */
#define MMETA_Bitrate            (MMETA_BASE + 8)  /* [INTEGER]   General. Stream bitrate in bits per seconds. */
#define MMETA_VideoDpiX          (MMETA_BASE + 9)  /* [DOUBLE]    Video horizontal pixels per inch.            */
#define MMETA_VideoDpiY         (MMETA_BASE + 10)  /* [DOUBLE]    Video vertical pixels per inch.              */
#define MMETA_VideoAspectX      (MMETA_BASE + 11)  /* [DOUBLE]    Video horizontal aspect ratio.               */   
#define MMETA_VideoAspectY      (MMETA_BASE + 12)  /* [DOUBLE]    Video vertical aspect ratio.                 */
#define MMETA_FlashUsed         (MMETA_BASE + 13)  /* [INTEGER]   EXIF Flash options, bitset                   */
#define MMETA_CameraModel       (MMETA_BASE + 14)  /* [STRING]    EXIF Name of camera creator                  */
#define MMETA_CameraVendor      (MMETA_BASE + 15)  /* [STRING]    EXIF Name of camera model                    */
#define MMETA_ExposureTime      (MMETA_BASE + 16)  /* [DOUBLE]    EXIF Exposure time                           */
#define MMETA_Orientation       (MMETA_BASE + 17)  /* [INTEGER]   EXIF Rotation, values: 1 - 8                 */
#define MMETA_GPSLatitude       (MMETA_BASE + 18)  /* [DOUBLE]    Geographic coordinates, latitude (degrees)   */
#define MMETA_GPSAltitude       (MMETA_BASE + 19)  /* [DOUBLE]    Geographic coordinates, altitude (meters)    */
#define MMETA_GPSLongitude      (MMETA_BASE + 20)  /* [DOUBLE]    Geographic coordinates, longitude (degrees)  */
#define MMETA_ColorProfile      (MMETA_BASE + 21)  /* [PORTNUM]   ICC color profile data                       */
#define MMETA_PerformanceDate   (MMETA_BASE + 22)  /* [CLOCKDATA] General. Date of performance.                */

#define MMETA_COUNT             23


/* Metadata query control tags. */

#define MMDQ_Base               (TAG_USER + 0x0736221A)
#define MMDQ_Importance         (MMDQ_Base + 0)
#define MMDQ_Encoding           (MMDQ_Base + 1)


/* Metadata descriptor tags. */

#define MMDI_Base               (TAG_USER + 0x27A93E06)
#define MMDI_Data               (MMDI_Base + 0)
#define MMDI_Size               (MMDI_Base + 1)
#define MMDI_CharCount          (MMDI_Base + 2)
#define MMDI_Type               (MMDI_Base + 3)
#define MMDI_Importance         (MMDI_Base + 4)


#endif    /* CLASSES_MULTIMEDIA_METADATA_H */
