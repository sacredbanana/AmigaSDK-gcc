	IFND	DISKFONT_DISKFONTTAG_I
DISKFONT_DISKFONTTAG_I	SET	1

**
**	$VER: diskfonttag.i 47.1 (29.7.2019)
**
**      diskfonttag.h -- tag definitions for .otag files
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

	IFND	UTILITY_TAGITEM_I
	INCLUDE "utility/tagitem.i"
	ENDC

* Level 0 entries never appear in the .otag list, but appear in font
* specifications

OT_Level0	EQU	TAG_USER
* Level 1 entries are required to exist in the .otag tag list
OT_Level1	EQU	(TAG_USER!$1000)
* Level 2 entries are optional typeface metric tags
OT_Level2	EQU	(TAG_USER!$2000)
* Level 3 entries are required for some OT_Engines
OT_Level3	EQU	(TAG_USER!$3000)
* Indirect entries are at (tag address + data offset)
OT_Indirect	EQU	$8000

********************************************************************
* font specification and inquiry tags
*
*! tags flagged with an exclaimation mark are valid for
*    specification.
*  ? tags flagged with a question mark are valid for inquiry
*
* fixed binary numbers are encoded as 16 bits of integer and
* 16 bits of fraction.	Negative values are indicated by twos
* complement of all 32 bits.


*! OT_DeviceDPI specifies the target device dots per inch -- X DPI is
*    in the high word, Y DPI in the low word.  OT_DeviceDPI == TA_DeviceDPI.
OT_DeviceDPI	EQU	(OT_Level0!$01)

*! OT_DotSize specifies the target device dot size as a percent of
*    it's resolution-implied size -- X percent in high word, Y percent
*    in low word.
OT_DotSize	EQU	(OT_Level0!$02)

*! OT_PointHeight specifies the requested point height of a typeface,
*    specifically, the height and nominal width of the em-square.
*    The point referred to here is 1/72".  It is encoded as a fixed
*    binary number.
OT_PointHeight	EQU	(OT_Level0!$08)

*! OT_SetFactor specifies the requested set width of a typeface.
*    It distorts the width of the em-square from that specified by
*    OT_PointHeight.  To compensate for a device with different
*    horizontal and vertical resolutions, OT_DeviceDPI should be used
*    instead.  For a normal aspect ratio, set to 1.0 (encoded as
*    0x00010000).  This is the default value.
OT_SetFactor	EQU	(OT_Level0!$09)

*! OT_Shear... specifies the Sine and Cosine of the vertical stroke
*    angle, as two fixed point binary fractions.  Both must be specified:
*    first the Sine and then the Cosine.  Setting the sine component
*    changes the Shear to an undefined value, setting the cosine
*    component completes the Shear change to the new composite value.
*    For no shear, set to 0.0, 1.0 (encoded as 0x00000000, 0x00010000).
*    This is the default value.
OT_ShearSin	EQU	(OT_Level0!$0a)
OT_ShearCos	EQU	(OT_Level0!$0b)

*! OT_Rotate... specifies the Sine and Cosine of the baselin rotation
*    angle, as two fixed point binary fractions.  Both must be specified:
*    first the Sine and then the Cosine.  Setting the sine component
*    changes the Shear to an undefined value, setting the cosine
*    component completes the Shear change to the new composite value.
*    For no shear, set to 0.0, 1.0 (encoded as 0x00000000, 0x00010000).
*    This is the default value.
OT_RotateSin	EQU	(OT_Level0!$0c)
OT_RotateCos	EQU	(OT_Level0!$0d)

*! OT_Embolden... specifies values to algorithimically embolden -- or,
*    when negative, lighten -- the glyph.  It is encoded as a fixed point
*    binary fraction of the em-square.  The X and Y components can be
*    changed indendently.  For normal characters, set to 0.0, 0.0
*    (encoded as 0x00000000, 0x00000000).  This is the default value.
OT_EmboldenX	EQU	(OT_Level0!$0e)
OT_EmboldenY	EQU	(OT_Level0!$0f)

*! OT_PointSize is an old method of specifying the point size,
*    encoded as (points * 16).
OT_PointSize	EQU	(OT_Level0!$10)

*! OT_GlyphCode specifies the glyph (character) code to use with
*    subsequent operations.  For example, this is the code for an
*    OT_Glyph inquiry
OT_GlyphCode	EQU	(OT_Level0!$11)

*! OT_GlyphCode2 specifies the second glyph code.  For example,
*    this is the right glyph of the two glyphs of an OT_KernPair
*    inquiry
OT_GlyphCode2	EQU	(OT_Level0!$12)

* For Unicode 3.1 compatibility:
* Since Unicode 3.1 glyph codes are no longer limited to 16 bit.
* To avoid problems with font engines that silently ignore the
* upper 16 bit of a glyph code, two new tags are introduced
* which can be used for specifying 32 bit ULONG glyph codes.
* Old font engines will return an error code, e.g. OTERR_UnknownTag.
* Font engines supporting the new tags will handle the old and
* new tags as equal (both as 32 bit ULONG).
* It only makes sense to use the new tags and glyph codes beyond
* 0xFFFF when OT_UnicodeRanges is present in the .otag file and
* has the UCR_SURROGATES bit set, which means the font has at least
* one glyph code beyond 0xFFFF.
OT_GlyphCode_32   EQU  (OT_Level0!$18)
OT_GlyphCode2_32  EQU  (OT_Level0!$19)

*! OT_GlyphWidth specifies a specific width for a glyph.
*    It sets a specific escapement (advance) width for subsequent
*    glyphs.  It is encoded as a fixed binary fraction of the em-square.
*    To revert to using the font-defined escapement for each glyph, set
*    to 0.0 (encoded as 0x00000000).  This is the default value.
OT_GlyphWidth	EQU	(OT_Level0!$13)

*! OT_OTagPath and
*! OT_OTagList specify the selected typeface.  Both must be specified:
*    first the Path and then the List.  Setting the path name changes
*    changes the typeface to an undefined value, providing the List
*    completes the typeface selection to the new typeface.  OTagPath
*    is the null terminated full file path of the .otag file associated
*    with the typeface.  OTagList is a memory copy of the processed
*    contents of that .otag file (i.e. with indirections resolved).
*    There are no default values for the typeface.
OT_OTagPath	EQU	(OT_Level0!OT_Indirect!$14)
OT_OTagList	EQU	(OT_Level0!OT_Indirect!$15)

* !  OT_MemPtr and
* !  OT_MemSize specify the address and size of a raw font in memory
*    (e.g. a font embedded in a PDF document) to be used instead of
*    a disk font with an .otag file. Not all font engines support this
*    tags.  Both must be specified: first the MemPtr and then the
*    MemSize.  Setting the MemPtr changes the typeface to an undefined
*    value, providing the MemSize completes the typeface selection to
*    the new typeface.  MemPtr is the address of an embedded font in
*    memory, MemSize is the size of the raw font in bytes.  Failure to
*    identify the font format results in an appropriate error code.
*    When no error is returned, you can get the information about the
*    font that would normally be present in an .otag file by calling
*    ObtainInfo(engineHandle, OT_OTagList, &tagListPtr, TAG_END);,
*    if successfull, tagListPtr points to a tagList similar to an
*    .otag file which has to be freed with
*    ReleaseInfo(engineHandle, OT_OTagList, tagListPtr, TAG_END);.
*    Do not release the memory containing the raw font until you have
*    selected another raw or disk font or closed the engineHandle.
OT_MemPtr   EQU   (OT_Level0!OT_Indirect!$16)
OT_MemSize  EQU   (OT_Level0!$17)

*  ? OT_GlyphMap supplies a read-only struct GlyphMap pointer that
*    describes a bitmap for a glyph with the current attributes.
OT_GlyphMap	EQU	(OT_Level0!OT_Indirect!$20)

*  ? OT_GlyphMap8Bit supplies a read-only struct GlyphMap pointer that
*    describes a bitmap for a glyph with the current attributes.
*    The chunky bitmap contains bytes, not bits, each byte describes
*    the intensity of the pixel, 0 is background color, 0xff is text
*    color (called "font smoothing" or "anti-aliased glyph").
*    Not all font engines support this tag, it depends on the font
*    format whether there only exist 0x00 and 0xff bytes ("b/w") or
*    if also intermediate values exist ("gray"). Has to be freed
*    with ReleaseInfo(engineHandle, OT_GlyphMap8Bit, glyph, TAG_END);
OT_GlyphMap8Bit EQU (OT_Level0!OT_Indirect!$1a)

*  ? OT_WidthList supplies a read-only struct MinList of struct
*    GlyphWidthEntry nodes for glyphs that are defined from GlyphCode
*    to GlyphCode2, inclusive.  The widths are represented as fixed
*    binary fractions of the em-square, ignoring any effect of
*    SetFactor or GlyphWidth.  A width would need to be converted to
*    a distance along the baseline in device units by the
*    application.
OT_WidthList	EQU	(OT_Level0!OT_Indirect!$21)

*  ? OT_WidthList32 supplies a read-only struct MinList of struct
*    GlyphWidthEntry32 nodes for glyphs that are defined from GlyphCode_32
*    to GlyphCode2_32, inclusive.  The list is guaranteed to be sorted by
*    glyph code, in ascending order. The widths are represented as fixed
*    binary fractions of the em-square, ignoring any effect of
*    SetFactor or GlyphWidth.  A width would need to be converted to
*    a distance along the baseline in device units by the
*    application. Only font engines that support Unicode3.1 and up
*    with glyph codes beyond 0xFFFF support this tag
OT_WidthList32 EQU (OT_Level0!OT_Indirect!$1b)

*  ? OT_...KernPair supplies the kern adjustment to be added to the
*    current position after placement of the GlyphCode glyph and
*    before placement of the GlyphCode2 glyph.  Text kern pairs are
*    for rendering body text.  Display kern pairs are generally
*    tighter values for display (e.g. headline) purposes.  The
*    adjustment is represented as a fixed binary fraction of the
*    em-square, ignoring any effect of SetFactor.  This number would
*    need to be converted to a distance along the baseline in device
*    units by the application.
OT_TextKernPair		EQU	(OT_Level0!OT_Indirect!$22)
OT_DesignKernPair	EQU	(OT_Level0!OT_Indirect!$23)

*  ? OT_Underlined is an unsigned word which is used to request
*    algorithimic underlining for the engine when rendering the glyph.
*    Bullet.library currently does not support this tag, though it
*    may be used by other engines in the future.  The default for
*    any engine which supports this tag must be OTUL_None.  Engines which
*    do not support this tag should return an appropriate OTERR value.
*
*    As of V39, diskfont.library will request underlining if specified
*    in the TextAttr, or TTextAttr passed to OpenDiskFont().  Diskfont
*    will first request Broken underlining (like the Text() function
*    does when SetSoftStyle() is used), and then Solid underlining if
*    the engine returns an error.  If the engine returns an error for
*    both, then diskfont.library attempts to find, or create the best
*    non-underlined font that it can.
OT_UnderLined		EQU	(OT_Level0!$24)

OTUL_None		EQU	0
OTUL_Solid		EQU	1
OTUL_Broken		EQU	2
OTUL_DoubleSolid	EQU	3
OTUL_DoubleBroken	EQU	4
* old versions had a typo here
OUTL_DoubleBroken	EQU     OTUL_DoubleBroken

*  ? OT_StrikeThrough is a boolean which is used to request
*    algorithimic strike through when rendering the glyph.
*    Bullet.library currently does not support this tag, though it
*    may be used by other engines in the future.  The default for
*    any engined which supports this tag must be FALSE.  Engines which
*    do not support this tag should return an appropriate OTERR value.
OT_StrikeThrough	EQU	(OT_Level0!$25)

*  ? OT_BaseLine returns the ascender in the upper 16 bit
*    and the descender in the lower 16 bit so you can compute
*    the baseline faster if the font engine supports this tag.
*    Even if the tag is supported you must check whether the
*    result contains a zero ascender.
*    Example:
*
*    int Ascend, Descend;
*    ULONG BaseLine;
*
*    if (!ObtainInfo(engineHandle, OT_BaseLine, &BaseLine, TAG_END) &&
*        ((BaseLine & 0xffff0000) != 0)) {
*            Ascend = BaseLine >> 16;
*            Descend = BaseLine & 0xffff;
*            BaseLinePosInPixels =
*                (LineHeightInPixels * Ascend) / (Ascend + Descend);
*    } else {
*            // assume the baseline from ascender and
*            // descender values of a series of rendered glyphs as before
*    }
OT_BaseLine EQU (OT_Level0!OT_Indirect!$1c)

*  ? OT_NumGlyphs tells you how many glyphs the font contains.
*    It depends on OT_SymbolSet if this number is really available.
*    Example:
*
*    ULONG NumGlyphs;
*
*    if (!ObtainInfo(engineHandle, OT_NumGlyphs, &NumGlyphs, TAG_END))
*        printf("The font contains %ld glyphs\n", NumGlyphs);
*    else
*        printf("The font engine does not support OT_NumGlyphs\n");
*
OT_NumGlyphs EQU (OT_Level0!OT_Indirect!$1d)

*  ? OT_NumKernPairs tells you how many kerning pairs the font contains.
*    Example:
*
*    ULONG NumPairs;
*
*    if (!ObtainInfo(engineHandle, OT_NumKernPairs, &NumPairs, TAG_END))
*        printf("The font contains %ld kerning pairs\n", NumPairs);
*    else
*        printf("The font engine does not support OT_NumKernPairs\n");
*
OT_NumKernPairs EQU (OT_Level0!OT_Indirect!$1e)

*  ? OT_HasGlyphs provides a faster searching method for the glyph codes
*    that are definded in a font than OT_WidthList (depending on font
*    format it may be necessary to render the glyphs for WidthList
*    creation). You pass a pointer to an ULONG containing the number of
*    glyphs to be checked for, after the call it contains 1 if so many
*    glyphs are available or 0 otherwise.
*    Example: If you want to know whether the font has at least 230
*    cyrillic glyphs between 0x400 and 0x4ff then call something like
*
*    ULONG wanted = 230;
*    if ((SetInfo(engineHandle, OT_GlyphCode, 0x400,
*                 OT_GlyphCode2, 0x4ff, TAG_END) == OTERR_Success) &&
*        (ObtainInfo(engineHandle, OT_HasGlyphs, &wanted,
*                    TAG_END) == OTERR_Success)) {
*            if (wanted)
*                printf("at least 230 cyrillic glyphs available\n");
*            else
*                printf("less than 230 cyrillic glyphs available\n");
*    } else {
*        // Use OT_WidthList since OT_HasGlyphs seems to be not supported
*    }
*
OT_HasGlyphs EQU (OT_Level0!OT_Indirect!$1f)

*  ? OT_GlyphName asks the font engine for the name of the glyph specified
*    with OT_GlyphCode. You pass a pointer to a buffer of at least 128
*    bytes in size. If the font engine supports this tag but the font does
*    not contain glyph names, the return code will be OTERR_BadFace. If
*    no error is returned, the buffer will be filled with the name of the
*    glyph, at least with an empty string. It depends on the font format
*    what type of name is returned (normally the postscript name).
*    Example:
*
*    char namebuf[128];
*
*    if (!SetInfo(engineHandle, OT_GlyphCode, '>', TAG_END) &&
*        !ObtainInfo(engineHandle, OT_GlyphName, &namebuf, TAG_END))
*            printf("name of glyph '>': %s\n", namebuf); // greater
*
OT_GlyphName EQU (OT_Level0!OT_Indirect!$26)


********************************************************************
* .otag tags

* suffix for files in FONTS: that contain these tags
OTSUFFIX	MACRO	; ".otag" text
		dc.b	'.otag',0
		ds.w	0
		ENDM

* OT_FileIdent both identifies this file and verifies its size.
* It is required to be the first tag in the file.
OT_FileIdent	EQU	(OT_Level1!$01)

* OT_Engine specifies the font engine this file is designed to use
OT_Engine	EQU	(OT_Level1!OT_Indirect!$02)

OTE_Bullet	MACRO	; "bullet" text
		dc.b	'bullet',0
		ds.w	0
		ENDM

* OT_Family is the family name of this typeface
OT_Family	EQU	(OT_Level1!OT_Indirect!$03)

* The name of this typeface is implicit in the name of the .otag file
* OT_BName is used to find the bold variant of this typeface
OT_BName	EQU	(OT_Level2!OT_Indirect!$05)
* OT_IName is used to find the italic variant of this typeface
OT_IName	EQU	(OT_Level2!OT_Indirect!$06)
* OT_BIName is used to find the bold italic variant of this typeface
OT_BIName	EQU	(OT_Level2!OT_Indirect!$07)
* OT_RName is used to find the Roman variant of this typeface
OT_RName        EQU     (OT_Level2!OT_Indirect!$09)

* OT_SymSet is used to select the symbol set that has the OT_YSizeFactor
* described here.  Other symbol sets might have different extremes
OT_SymbolSet	EQU	(OT_Level1!$10)

* OT_YSizeFactor is a ratio to assist in calculating the Point height
* to BlackHeight relationship -- high word: Point height term, low
* word: Black height term -- pointSize = ysize*<high>/<low>
OT_YSizeFactor	EQU	(OT_Level1!$11)

* OT_SpaceWidth specifies the width of the space character relative
* to the character height
OT_SpaceWidth	EQU	(OT_Level2!$12)

* OT_IsFixed is a boolean indicating that all the characters in the
* typeface are intended to have the same character advance
OT_IsFixed	EQU	(OT_Level2!$13)

* OT_IsUnderlined is a boolean indicating that the characters in the
* typeface are underlined.
* Defaults to FALSE if absent.
OT_IsUnderlined EQU     (OT_Level2!$23)

* OT_SerifFlag is a boolean indicating if the character has serifs
OT_SerifFlag	EQU	(OT_Level1!$14)

* OT_StemWeight is an unsigned byte indicating the weight of the character
OT_StemWeight	EQU	(OT_Level1!$15)

OTS_UltraThin	EQU	 8	;   0- 15
OTS_ExtraThin	EQU	 24	;  16- 31
OTS_Thin	EQU	 40	;  32- 47
OTS_ExtraLight	EQU	 56	;  48- 63
OTS_Light	EQU	 72	;  64- 79
OTS_DemiLight	EQU	 88	;  80- 95
OTS_SemiLight	EQU	104	;  96-111
OTS_Book	EQU	120	; 112-127
OTS_Medium	EQU	136	; 128-143
OTS_SemiBold	EQU	152	; 144-159
OTS_DemiBold	EQU	168	; 160-175
OTS_Bold	EQU	184	; 176-191
OTS_ExtraBold	EQU	200	; 192-207
OTS_Black	EQU	216	; 208-223
OTS_ExtraBlack	EQU	232	; 224-239
OTS_UltraBlack	EQU	248	; 240-255

* OT_SlantStyle is an unsigned byte indicating the font posture
OT_SlantStyle	EQU	(OT_Level1!$16)
OTS_Upright	EQU	0
OTS_Italic	EQU	1	; Oblique, Slanted, etc.
OTS_LeftItalic	EQU	2	; Reverse Slant

* OT_HorizStyle is an unsigned byte indicating the appearance width
OT_HorizStyle		EQU	(OT_Level1!$17)
OTH_UltraCompressed	EQU	 16	;   0- 31
OTH_ExtraCompressed	EQU	 48	;  32- 63
OTH_Compressed		EQU	 80	;  64- 95
OTH_Condensed		EQU	112	;  96-127
OTH_Normal		EQU	144	; 128-159
OTH_SemiExpanded	EQU	176	; 160-191
OTH_Expanded		EQU	208	; 192-223
OTH_ExtraExpanded	EQU	240	; 224-255

* OT_SpaceFactor specifies the width of the space character relative
* to the character height
OT_SpaceFactor		EQU	(OT_Level2!$18)

* OT_InhibitAlgoStyle indicates which ta_Style bits, if any, should
* be ignored even if the font does not already have that quality.
* For example, if FSF_BOLD is set and the typeface is not bold but
* the user specifies bold, the application or diskfont library is
* not to use OT_Embolden to achieve a bold result.
OT_InhibitAlgoStyle 	EQU	(OT_Level2!$19)

* OT_AvailSizes is an indirect pointer to sorted UWORDs, 0th is count
OT_AvailSizes		EQU	(OT_Level1!OT_Indirect!$20)

OT_MAXAVAILSIZES	EQU	20	; no more than 20 sizes allowed

* OT_BMSize specifies whether the font is scalable or not.  Some font
* engines can use non-scalable bitmap font formats, e.g.
* .(bdf|fnt|fon|pcf) files.  This is an unsigned long that contains
* the maximum glyph bounding box width in pixels in the high word and
* the maximum glyph bounding box height in pixels in the low word.
* If absent or 0 the font is scalable. Setting OT_DeviceDPI,
* OT_PointHeight etc for non-scalable fonts has no effect on the glyphs,
* especially they can be much higher as expected.  If you e.g. specified
* 12 pts but (OT_BMSize & 0xffff) is 48, they may be 48 pixels high
* and your template for BltTemplate() may be too small. Using non-
* scalable fonts via bullet API instead of converting them to Amiga
* bitmap fonts makes sense for font formats that can handle glyph
* codes beyond 0xFF, e.g. BDF or PCF.
OT_BMSize    EQU  (OT_Level2!$21)

* OT_SpecCount is the count number of parameters specified here
OT_SpecCount           EQU     (OT_Level1!$100)

* Specs can be created as appropriate for the engine by ORing in the
* parameter number (1 is first, 2 is second, ... up to 15th)
OT_Spec                        EQU     (OT_Level1!$100)
* OT_Spec1 is the (first) parameter to the font engine to select
* this particular typeface
OT_Spec1               EQU     (OT_Level1!$101)

********************************************************************
* GetDiskFontCtrl and SetDiskFontCtrl tags *

DFCTRL_BASE EQU (TAG_USER!$0B000000)

*
* X and Y DPI device default settings for the bullet library font generator.
* Default is 72 dpi.
*

DFCTRL_XDPI EQU    (DFCTRL_BASE!$1)
DFCTRL_YDPI EQU    (DFCTRL_BASE!$2)

*
* X and Y DPI dot size settings for the font generator.
* Default is 100dpi.
*

DFCTRL_XDOTP EQU   (DFCTRL_BASE!$3)
DFCTRL_YDOTP EQU   (DFCTRL_BASE!$4)

*
* Default symbol set identifier. This is currently unused.
*

DFCTRL_SYMSET EQU  (DFCTRL_BASE!$4)

*
* AvailFonts cache enable flag. Either TRUE or FALSE.
*

DFCTRL_CACHE EQU   (DFCTRL_BASE!$5)

*
* Availfonts font sorting flag. See below for available values.
*
DFCTRL_SORTMODE EQU (DFCTRL_BASE!$6)

* No sorting: Default.
DFCTRL_SORT_OFF EQU 0

* Asceding sort order, localized with default locale.
DFCTRL_SORT_ASC EQU 1

* Descending sort order, localized with default locale.
DFCTRL_SORT_DES EQU -1

* Flush the cache? (BOOL) If TRUE, a cache flush is initiated.
DFCTRL_CACHEFLUSH EQU (DFCTRL_BASE!$7)

	ENDC	; DISKFONT_DISKFONTTAG_I
