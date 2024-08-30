#ifndef LIBRARIES_HARFBUZZ_H
#define LIBRARIES_HARFBUZZ_H

/*

	MorphOS Shared HarfBuzz

	harfbuzz.library include

	Copyright © 2016-2022 The MorphOS Development Team, All Rights Reserved.

*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HB_VERSION_MAJOR 3
#define HB_VERSION_MINOR 3
#define HB_VERSION_MICRO 2

#define HB_VERSION_STRING "3.3.2"

#define HB_VERSION_ATLEAST(major,minor,micro) \
	((major)*10000+(minor)*100+(micro) <= \
	 HB_VERSION_MAJOR*10000+HB_VERSION_MINOR*100+HB_VERSION_MICRO)

#if defined(__GNUC__) && ((__GNUC__ > 3) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#define HB_DEPRECATED __attribute__((__deprecated__))
#else
#define HB_DEPRECATED
#endif

#if defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5))
#define HB_DEPRECATED_FOR(f) __attribute__((__deprecated__("Use '" #f "' instead")))
#else
#define HB_DEPRECATED_FOR(f) HB_DEPRECATED
#endif

typedef int hb_bool_t;

typedef uint32_t hb_codepoint_t;
typedef int32_t hb_position_t;
typedef uint32_t hb_mask_t;

typedef union _hb_var_int_t {
	uint32_t u32;
	int32_t i32;
	uint16_t u16[2];
	int16_t i16[2];
	uint8_t u8[4];
	int8_t i8[4];
} hb_var_int_t;

typedef uint32_t hb_tag_t;

#define HB_TAG(c1,c2,c3,c4) ((hb_tag_t)((((uint8_t)(c1))<<24)|(((uint8_t)(c2))<<16)|(((uint8_t)(c3))<<8)|((uint8_t)(c4))))
#define HB_UNTAG(tag) ((uint8_t)((tag)>>24)), ((uint8_t)((tag)>>16)), ((uint8_t)((tag)>>8)), ((uint8_t)(tag))

#define HB_TAG_NONE HB_TAG(0,0,0,0)
#define HB_TAG_MAX HB_TAG(0xff,0xff,0xff,0xff)
#define HB_TAG_MAX_SIGNED HB_TAG(0x7f,0xff,0xff,0xff)

typedef enum {
	HB_DIRECTION_INVALID = 0,
	HB_DIRECTION_LTR = 4,
	HB_DIRECTION_RTL,
	HB_DIRECTION_TTB,
	HB_DIRECTION_BTT
} hb_direction_t;

#define HB_DIRECTION_IS_VALID(dir)	((((unsigned int) (dir)) & ~3U) == 4)
#define HB_DIRECTION_IS_HORIZONTAL(dir)	((((unsigned int) (dir)) & ~1U) == 4)
#define HB_DIRECTION_IS_VERTICAL(dir)	((((unsigned int) (dir)) & ~1U) == 6)
#define HB_DIRECTION_IS_FORWARD(dir)	((((unsigned int) (dir)) & ~2U) == 4)
#define HB_DIRECTION_IS_BACKWARD(dir)	((((unsigned int) (dir)) & ~2U) == 5)
#define HB_DIRECTION_REVERSE(dir)	((hb_direction_t) (((unsigned int) (dir)) ^ 1))

typedef const struct hb_language_impl_t *hb_language_t;

#define HB_LANGUAGE_INVALID ((hb_language_t) 0)

typedef enum
{
	HB_SCRIPT_COMMON					= HB_TAG ('Z','y','y','y'),
	HB_SCRIPT_INHERITED					= HB_TAG ('Z','i','n','h'),
	HB_SCRIPT_UNKNOWN					= HB_TAG ('Z','z','z','z'),
	HB_SCRIPT_ARABIC					= HB_TAG ('A','r','a','b'),
	HB_SCRIPT_ARMENIAN					= HB_TAG ('A','r','m','n'),
	HB_SCRIPT_BENGALI					= HB_TAG ('B','e','n','g'),
	HB_SCRIPT_CYRILLIC					= HB_TAG ('C','y','r','l'),
	HB_SCRIPT_DEVANAGARI				= HB_TAG ('D','e','v','a'),
	HB_SCRIPT_GEORGIAN					= HB_TAG ('G','e','o','r'),
	HB_SCRIPT_GREEK						= HB_TAG ('G','r','e','k'),
	HB_SCRIPT_GUJARATI					= HB_TAG ('G','u','j','r'),
	HB_SCRIPT_GURMUKHI					= HB_TAG ('G','u','r','u'),
	HB_SCRIPT_HANGUL					= HB_TAG ('H','a','n','g'),
	HB_SCRIPT_HAN						= HB_TAG ('H','a','n','i'),
	HB_SCRIPT_HEBREW					= HB_TAG ('H','e','b','r'),
	HB_SCRIPT_HIRAGANA					= HB_TAG ('H','i','r','a'),
	HB_SCRIPT_KANNADA					= HB_TAG ('K','n','d','a'),
	HB_SCRIPT_KATAKANA					= HB_TAG ('K','a','n','a'),
	HB_SCRIPT_LAO						= HB_TAG ('L','a','o','o'),
	HB_SCRIPT_LATIN						= HB_TAG ('L','a','t','n'),
	HB_SCRIPT_MALAYALAM					= HB_TAG ('M','l','y','m'),
	HB_SCRIPT_ORIYA						= HB_TAG ('O','r','y','a'),
	HB_SCRIPT_TAMIL						= HB_TAG ('T','a','m','l'),
	HB_SCRIPT_TELUGU					= HB_TAG ('T','e','l','u'),
	HB_SCRIPT_THAI						= HB_TAG ('T','h','a','i'),
	HB_SCRIPT_TIBETAN					= HB_TAG ('T','i','b','t'),
	HB_SCRIPT_BOPOMOFO					= HB_TAG ('B','o','p','o'),
	HB_SCRIPT_BRAILLE					= HB_TAG ('B','r','a','i'),
	HB_SCRIPT_CANADIAN_SYLLABICS		= HB_TAG ('C','a','n','s'),
	HB_SCRIPT_CHEROKEE					= HB_TAG ('C','h','e','r'),
	HB_SCRIPT_ETHIOPIC					= HB_TAG ('E','t','h','i'),
	HB_SCRIPT_KHMER						= HB_TAG ('K','h','m','r'),
	HB_SCRIPT_MONGOLIAN					= HB_TAG ('M','o','n','g'),
	HB_SCRIPT_MYANMAR					= HB_TAG ('M','y','m','r'),
	HB_SCRIPT_OGHAM						= HB_TAG ('O','g','a','m'),
	HB_SCRIPT_RUNIC						= HB_TAG ('R','u','n','r'),
	HB_SCRIPT_SINHALA					= HB_TAG ('S','i','n','h'),
	HB_SCRIPT_SYRIAC					= HB_TAG ('S','y','r','c'),
	HB_SCRIPT_THAANA					= HB_TAG ('T','h','a','a'),
	HB_SCRIPT_YI						= HB_TAG ('Y','i','i','i'),
	HB_SCRIPT_DESERET					= HB_TAG ('D','s','r','t'),
	HB_SCRIPT_GOTHIC					= HB_TAG ('G','o','t','h'),
	HB_SCRIPT_OLD_ITALIC				= HB_TAG ('I','t','a','l'),
	HB_SCRIPT_BUHID						= HB_TAG ('B','u','h','d'),
	HB_SCRIPT_HANUNOO					= HB_TAG ('H','a','n','o'),
	HB_SCRIPT_TAGALOG					= HB_TAG ('T','g','l','g'),
	HB_SCRIPT_TAGBANWA					= HB_TAG ('T','a','g','b'),
	HB_SCRIPT_CYPRIOT					= HB_TAG ('C','p','r','t'),
	HB_SCRIPT_LIMBU						= HB_TAG ('L','i','m','b'),
	HB_SCRIPT_LINEAR_B					= HB_TAG ('L','i','n','b'),
	HB_SCRIPT_OSMANYA					= HB_TAG ('O','s','m','a'),
	HB_SCRIPT_SHAVIAN					= HB_TAG ('S','h','a','w'),
	HB_SCRIPT_TAI_LE					= HB_TAG ('T','a','l','e'),
	HB_SCRIPT_UGARITIC					= HB_TAG ('U','g','a','r'),
	HB_SCRIPT_BUGINESE					= HB_TAG ('B','u','g','i'),
	HB_SCRIPT_COPTIC					= HB_TAG ('C','o','p','t'),
	HB_SCRIPT_GLAGOLITIC				= HB_TAG ('G','l','a','g'),
	HB_SCRIPT_KHAROSHTHI				= HB_TAG ('K','h','a','r'),
	HB_SCRIPT_NEW_TAI_LUE				= HB_TAG ('T','a','l','u'),
	HB_SCRIPT_OLD_PERSIAN				= HB_TAG ('X','p','e','o'),
	HB_SCRIPT_SYLOTI_NAGRI				= HB_TAG ('S','y','l','o'),
	HB_SCRIPT_TIFINAGH					= HB_TAG ('T','f','n','g'),
	HB_SCRIPT_BALINESE					= HB_TAG ('B','a','l','i'),
	HB_SCRIPT_CUNEIFORM					= HB_TAG ('X','s','u','x'),
	HB_SCRIPT_NKO						= HB_TAG ('N','k','o','o'),
	HB_SCRIPT_PHAGS_PA					= HB_TAG ('P','h','a','g'),
	HB_SCRIPT_PHOENICIAN				= HB_TAG ('P','h','n','x'),
	HB_SCRIPT_CARIAN					= HB_TAG ('C','a','r','i'),
	HB_SCRIPT_CHAM						= HB_TAG ('C','h','a','m'),
	HB_SCRIPT_KAYAH_LI					= HB_TAG ('K','a','l','i'),
	HB_SCRIPT_LEPCHA					= HB_TAG ('L','e','p','c'),
	HB_SCRIPT_LYCIAN					= HB_TAG ('L','y','c','i'),
	HB_SCRIPT_LYDIAN					= HB_TAG ('L','y','d','i'),
	HB_SCRIPT_OL_CHIKI					= HB_TAG ('O','l','c','k'),
	HB_SCRIPT_REJANG					= HB_TAG ('R','j','n','g'),
	HB_SCRIPT_SAURASHTRA				= HB_TAG ('S','a','u','r'),
	HB_SCRIPT_SUNDANESE					= HB_TAG ('S','u','n','d'),
	HB_SCRIPT_VAI						= HB_TAG ('V','a','i','i'),
	HB_SCRIPT_AVESTAN					= HB_TAG ('A','v','s','t'),
	HB_SCRIPT_BAMUM						= HB_TAG ('B','a','m','u'),
	HB_SCRIPT_EGYPTIAN_HIEROGLYPHS		= HB_TAG ('E','g','y','p'),
	HB_SCRIPT_IMPERIAL_ARAMAIC			= HB_TAG ('A','r','m','i'),
	HB_SCRIPT_INSCRIPTIONAL_PAHLAVI		= HB_TAG ('P','h','l','i'),
	HB_SCRIPT_INSCRIPTIONAL_PARTHIAN	= HB_TAG ('P','r','t','i'),
	HB_SCRIPT_JAVANESE					= HB_TAG ('J','a','v','a'),
	HB_SCRIPT_KAITHI					= HB_TAG ('K','t','h','i'),
	HB_SCRIPT_LISU						= HB_TAG ('L','i','s','u'),
	HB_SCRIPT_MEETEI_MAYEK				= HB_TAG ('M','t','e','i'),
	HB_SCRIPT_OLD_SOUTH_ARABIAN			= HB_TAG ('S','a','r','b'),
	HB_SCRIPT_OLD_TURKIC				= HB_TAG ('O','r','k','h'),
	HB_SCRIPT_SAMARITAN					= HB_TAG ('S','a','m','r'),
	HB_SCRIPT_TAI_THAM					= HB_TAG ('L','a','n','a'),
	HB_SCRIPT_TAI_VIET					= HB_TAG ('T','a','v','t'),
	HB_SCRIPT_BATAK						= HB_TAG ('B','a','t','k'),
	HB_SCRIPT_BRAHMI					= HB_TAG ('B','r','a','h'),
	HB_SCRIPT_MANDAIC					= HB_TAG ('M','a','n','d'),
	HB_SCRIPT_CHAKMA					= HB_TAG ('C','a','k','m'),
	HB_SCRIPT_MEROITIC_CURSIVE			= HB_TAG ('M','e','r','c'),
	HB_SCRIPT_MEROITIC_HIEROGLYPHS		= HB_TAG ('M','e','r','o'),
	HB_SCRIPT_MIAO						= HB_TAG ('P','l','r','d'),
	HB_SCRIPT_SHARADA					= HB_TAG ('S','h','r','d'),
	HB_SCRIPT_SORA_SOMPENG				= HB_TAG ('S','o','r','a'),
	HB_SCRIPT_TAKRI						= HB_TAG ('T','a','k','r'),
	HB_SCRIPT_BASSA_VAH					= HB_TAG ('B','a','s','s'),
	HB_SCRIPT_CAUCASIAN_ALBANIAN		= HB_TAG ('A','g','h','b'),
	HB_SCRIPT_DUPLOYAN					= HB_TAG ('D','u','p','l'),
	HB_SCRIPT_ELBASAN					= HB_TAG ('E','l','b','a'),
	HB_SCRIPT_GRANTHA					= HB_TAG ('G','r','a','n'),
	HB_SCRIPT_KHOJKI					= HB_TAG ('K','h','o','j'),
	HB_SCRIPT_KHUDAWADI					= HB_TAG ('S','i','n','d'),
	HB_SCRIPT_LINEAR_A					= HB_TAG ('L','i','n','a'),
	HB_SCRIPT_MAHAJANI					= HB_TAG ('M','a','h','j'),
	HB_SCRIPT_MANICHAEAN				= HB_TAG ('M','a','n','i'),
	HB_SCRIPT_MENDE_KIKAKUI				= HB_TAG ('M','e','n','d'),
	HB_SCRIPT_MODI						= HB_TAG ('M','o','d','i'),
	HB_SCRIPT_MRO						= HB_TAG ('M','r','o','o'),
	HB_SCRIPT_NABATAEAN					= HB_TAG ('N','b','a','t'),
	HB_SCRIPT_OLD_NORTH_ARABIAN			= HB_TAG ('N','a','r','b'),
	HB_SCRIPT_OLD_PERMIC				= HB_TAG ('P','e','r','m'),
	HB_SCRIPT_PAHAWH_HMONG				= HB_TAG ('H','m','n','g'),
	HB_SCRIPT_PALMYRENE					= HB_TAG ('P','a','l','m'),
	HB_SCRIPT_PAU_CIN_HAU				= HB_TAG ('P','a','u','c'),
	HB_SCRIPT_PSALTER_PAHLAVI			= HB_TAG ('P','h','l','p'),
	HB_SCRIPT_SIDDHAM					= HB_TAG ('S','i','d','d'),
	HB_SCRIPT_TIRHUTA					= HB_TAG ('T','i','r','h'),
	HB_SCRIPT_WARANG_CITI				= HB_TAG ('W','a','r','a'),
	HB_SCRIPT_AHOM						= HB_TAG ('A','h','o','m'),
	HB_SCRIPT_ANATOLIAN_HIEROGLYPHS		= HB_TAG ('H','l','u','w'),
	HB_SCRIPT_HATRAN					= HB_TAG ('H','a','t','r'),
	HB_SCRIPT_MULTANI					= HB_TAG ('M','u','l','t'),
	HB_SCRIPT_OLD_HUNGARIAN				= HB_TAG ('H','u','n','g'),
	HB_SCRIPT_SIGNWRITING				= HB_TAG ('S','g','n','w'),
	HB_SCRIPT_ADLAM						= HB_TAG ('A','d','l','m'),
	HB_SCRIPT_BHAIKSUKI					= HB_TAG ('B','h','k','s'),
	HB_SCRIPT_MARCHEN					= HB_TAG ('M','a','r','c'),
	HB_SCRIPT_OSAGE						= HB_TAG ('O','s','g','e'),
	HB_SCRIPT_TANGUT					= HB_TAG ('T','a','n','g'),
	HB_SCRIPT_NEWA						= HB_TAG ('N','e','w','a'),
	HB_SCRIPT_MASARAM_GONDI				= HB_TAG ('G','o','n','m'),
	HB_SCRIPT_NUSHU						= HB_TAG ('N','s','h','u'),
	HB_SCRIPT_SOYOMBO					= HB_TAG ('S','o','y','o'),
	HB_SCRIPT_ZANABAZAR_SQUARE			= HB_TAG ('Z','a','n','b'),
	HB_SCRIPT_DOGRA			= HB_TAG ('D','o','g','r'),
	HB_SCRIPT_GUNJALA_GONDI		= HB_TAG ('G','o','n','g'),
	HB_SCRIPT_HANIFI_ROHINGYA		= HB_TAG ('R','o','h','g'),
	HB_SCRIPT_MAKASAR			= HB_TAG ('M','a','k','a'),
	HB_SCRIPT_MEDEFAIDRIN			= HB_TAG ('M','e','d','f'),
	HB_SCRIPT_OLD_SOGDIAN			= HB_TAG ('S','o','g','o'),
	HB_SCRIPT_SOGDIAN			= HB_TAG ('S','o','g','d'),
	HB_SCRIPT_ELYMAIC			= HB_TAG ('E','l','y','m'),
	HB_SCRIPT_NANDINAGARI			= HB_TAG ('N','a','n','d'),
	HB_SCRIPT_NYIAKENG_PUACHUE_HMONG	= HB_TAG ('H','m','n','p'),
	HB_SCRIPT_WANCHO			= HB_TAG ('W','c','h','o'),
	HB_SCRIPT_CHORASMIAN			= HB_TAG ('C','h','r','s'),
	HB_SCRIPT_DIVES_AKURU			= HB_TAG ('D','i','a','k'),
	HB_SCRIPT_KHITAN_SMALL_SCRIPT		= HB_TAG ('K','i','t','s'),
	HB_SCRIPT_YEZIDI			= HB_TAG ('Y','e','z','i'),
	HB_SCRIPT_CYPRO_MINOAN			= HB_TAG ('C','p','m','n'),
	HB_SCRIPT_OLD_UYGHUR			= HB_TAG ('O','u','g','r'),
	HB_SCRIPT_TANGSA			= HB_TAG ('T','n','s','a'),
	HB_SCRIPT_TOTO				= HB_TAG ('T','o','t','o'),
	HB_SCRIPT_VITHKUQI			= HB_TAG ('V','i','t','h'),
	HB_SCRIPT_INVALID					= HB_TAG_NONE,
	_HB_SCRIPT_MAX_VALUE				= HB_TAG_MAX,
	_HB_SCRIPT_MAX_VALUE_SIGNED			= HB_TAG_MAX_SIGNED
} hb_script_t;

#ifndef HB_DISABLE_DEPRECATED
#define HB_SCRIPT_CANADIAN_ABORIGINAL HB_SCRIPT_CANADIAN_SYLLABICS
#endif

typedef struct hb_user_data_key_t {
	char unused;
} hb_user_data_key_t;

typedef void (*hb_destroy_func_t) (void *user_data);

#define HB_FEATURE_GLOBAL_START	0
#define HB_FEATURE_GLOBAL_END	((unsigned int) -1)

typedef struct hb_feature_t {
	hb_tag_t tag;
	uint32_t value;
	unsigned int start;
	unsigned int end;
} hb_feature_t;

typedef struct hb_variation_t {
	hb_tag_t tag;
	float value;
} hb_variation_t;

typedef uint32_t hb_color_t;

#define HB_COLOR(b,g,r,a) ((hb_color_t) HB_TAG ((b),(g),(r),(a)))

typedef enum {
	HB_MEMORY_MODE_DUPLICATE,
	HB_MEMORY_MODE_READONLY,
	HB_MEMORY_MODE_WRITABLE,
	HB_MEMORY_MODE_READONLY_MAY_MAKE_WRITABLE
} hb_memory_mode_t;

typedef struct hb_blob_t hb_blob_t;

#define HB_UNICODE_MAX 0x10FFFFu

typedef enum
{
	HB_UNICODE_GENERAL_CATEGORY_CONTROL,
	HB_UNICODE_GENERAL_CATEGORY_FORMAT,
	HB_UNICODE_GENERAL_CATEGORY_UNASSIGNED,
	HB_UNICODE_GENERAL_CATEGORY_PRIVATE_USE,
	HB_UNICODE_GENERAL_CATEGORY_SURROGATE,
	HB_UNICODE_GENERAL_CATEGORY_LOWERCASE_LETTER,
	HB_UNICODE_GENERAL_CATEGORY_MODIFIER_LETTER,
	HB_UNICODE_GENERAL_CATEGORY_OTHER_LETTER,
	HB_UNICODE_GENERAL_CATEGORY_TITLECASE_LETTER,
	HB_UNICODE_GENERAL_CATEGORY_UPPERCASE_LETTER,
	HB_UNICODE_GENERAL_CATEGORY_SPACING_MARK,
	HB_UNICODE_GENERAL_CATEGORY_ENCLOSING_MARK,
	HB_UNICODE_GENERAL_CATEGORY_NON_SPACING_MARK,
	HB_UNICODE_GENERAL_CATEGORY_DECIMAL_NUMBER,
	HB_UNICODE_GENERAL_CATEGORY_LETTER_NUMBER,
	HB_UNICODE_GENERAL_CATEGORY_OTHER_NUMBER,
	HB_UNICODE_GENERAL_CATEGORY_CONNECT_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_DASH_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_CLOSE_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_FINAL_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_INITIAL_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_OTHER_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_OPEN_PUNCTUATION,
	HB_UNICODE_GENERAL_CATEGORY_CURRENCY_SYMBOL,
	HB_UNICODE_GENERAL_CATEGORY_MODIFIER_SYMBOL,
	HB_UNICODE_GENERAL_CATEGORY_MATH_SYMBOL,
	HB_UNICODE_GENERAL_CATEGORY_OTHER_SYMBOL,
	HB_UNICODE_GENERAL_CATEGORY_LINE_SEPARATOR,
	HB_UNICODE_GENERAL_CATEGORY_PARAGRAPH_SEPARATOR,
	HB_UNICODE_GENERAL_CATEGORY_SPACE_SEPARATOR
} hb_unicode_general_category_t;

typedef enum
{
	HB_UNICODE_COMBINING_CLASS_NOT_REORDERED		=   0,
	HB_UNICODE_COMBINING_CLASS_OVERLAY				=   1,
	HB_UNICODE_COMBINING_CLASS_NUKTA				=   7,
	HB_UNICODE_COMBINING_CLASS_KANA_VOICING			=   8,
	HB_UNICODE_COMBINING_CLASS_VIRAMA				=   9,
	HB_UNICODE_COMBINING_CLASS_CCC10				=  10,
	HB_UNICODE_COMBINING_CLASS_CCC11				=  11,
	HB_UNICODE_COMBINING_CLASS_CCC12				=  12,
	HB_UNICODE_COMBINING_CLASS_CCC13				=  13,
	HB_UNICODE_COMBINING_CLASS_CCC14				=  14,
	HB_UNICODE_COMBINING_CLASS_CCC15				=  15,
	HB_UNICODE_COMBINING_CLASS_CCC16				=  16,
	HB_UNICODE_COMBINING_CLASS_CCC17				=  17,
	HB_UNICODE_COMBINING_CLASS_CCC18				=  18,
	HB_UNICODE_COMBINING_CLASS_CCC19				=  19,
	HB_UNICODE_COMBINING_CLASS_CCC20				=  20,
	HB_UNICODE_COMBINING_CLASS_CCC21				=  21,
	HB_UNICODE_COMBINING_CLASS_CCC22				=  22,
	HB_UNICODE_COMBINING_CLASS_CCC23				=  23,
	HB_UNICODE_COMBINING_CLASS_CCC24				=  24,
	HB_UNICODE_COMBINING_CLASS_CCC25				=  25,
	HB_UNICODE_COMBINING_CLASS_CCC26				=  26,
	HB_UNICODE_COMBINING_CLASS_CCC27				=  27,
	HB_UNICODE_COMBINING_CLASS_CCC28				=  28,
	HB_UNICODE_COMBINING_CLASS_CCC29				=  29,
	HB_UNICODE_COMBINING_CLASS_CCC30				=  30,
	HB_UNICODE_COMBINING_CLASS_CCC31				=  31,
	HB_UNICODE_COMBINING_CLASS_CCC32				=  32,
	HB_UNICODE_COMBINING_CLASS_CCC33				=  33,
	HB_UNICODE_COMBINING_CLASS_CCC34				=  34,
	HB_UNICODE_COMBINING_CLASS_CCC35				=  35,
	HB_UNICODE_COMBINING_CLASS_CCC36				=  36,
	HB_UNICODE_COMBINING_CLASS_CCC84				=  84,
	HB_UNICODE_COMBINING_CLASS_CCC91				=  91,
	HB_UNICODE_COMBINING_CLASS_CCC103				= 103,
	HB_UNICODE_COMBINING_CLASS_CCC107				= 107,
	HB_UNICODE_COMBINING_CLASS_CCC118				= 118,
	HB_UNICODE_COMBINING_CLASS_CCC122				= 122,
	HB_UNICODE_COMBINING_CLASS_CCC129				= 129,
	HB_UNICODE_COMBINING_CLASS_CCC130				= 130,
	HB_UNICODE_COMBINING_CLASS_CCC133				= 132,
	HB_UNICODE_COMBINING_CLASS_ATTACHED_BELOW_LEFT	= 200,
	HB_UNICODE_COMBINING_CLASS_ATTACHED_BELOW		= 202,
	HB_UNICODE_COMBINING_CLASS_ATTACHED_ABOVE		= 214,
	HB_UNICODE_COMBINING_CLASS_ATTACHED_ABOVE_RIGHT	= 216,
	HB_UNICODE_COMBINING_CLASS_BELOW_LEFT			= 218,
	HB_UNICODE_COMBINING_CLASS_BELOW				= 220,
	HB_UNICODE_COMBINING_CLASS_BELOW_RIGHT			= 222,
	HB_UNICODE_COMBINING_CLASS_LEFT					= 224,
	HB_UNICODE_COMBINING_CLASS_RIGHT				= 226,
	HB_UNICODE_COMBINING_CLASS_ABOVE_LEFT			= 228,
	HB_UNICODE_COMBINING_CLASS_ABOVE				= 230,
	HB_UNICODE_COMBINING_CLASS_ABOVE_RIGHT			= 232,
	HB_UNICODE_COMBINING_CLASS_DOUBLE_BELOW			= 233,
	HB_UNICODE_COMBINING_CLASS_DOUBLE_ABOVE			= 234,
	HB_UNICODE_COMBINING_CLASS_IOTA_SUBSCRIPT		= 240,
	HB_UNICODE_COMBINING_CLASS_INVALID				= 255
} hb_unicode_combining_class_t;

typedef struct hb_unicode_funcs_t hb_unicode_funcs_t;
typedef hb_unicode_combining_class_t (*hb_unicode_combining_class_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode, void *user_data);
#ifndef HB_DISABLE_DEPRECATED
typedef unsigned int (*hb_unicode_eastasian_width_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode, void *user_data);
typedef unsigned int (*hb_unicode_decompose_compatibility_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t u, hb_codepoint_t *decomposed, void *user_data);
#endif
typedef hb_unicode_general_category_t (*hb_unicode_general_category_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode, void *user_data);
typedef hb_codepoint_t (*hb_unicode_mirroring_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode, void *user_data);
typedef hb_script_t (*hb_unicode_script_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t unicode, void *user_data);
typedef hb_bool_t (*hb_unicode_compose_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t a, hb_codepoint_t b, hb_codepoint_t *ab, void *user_data);
typedef hb_bool_t (*hb_unicode_decompose_func_t) (hb_unicode_funcs_t *ufuncs, hb_codepoint_t ab, hb_codepoint_t *a, hb_codepoint_t *b, void *user_data);

#ifndef HB_DISABLE_DEPRECATED
#define HB_UNICODE_MAX_DECOMPOSITION_LEN (18+1)
#endif

typedef struct hb_face_t hb_face_t;
typedef hb_blob_t * (*hb_reference_table_func_t) (hb_face_t *face, hb_tag_t tag, void *user_data);

typedef struct hb_font_t hb_font_t;
typedef struct hb_font_funcs_t hb_font_funcs_t;

typedef struct hb_font_extents_t
{
	hb_position_t ascender;
	hb_position_t descender;
	hb_position_t line_gap;
	hb_position_t reserved9;
	hb_position_t reserved8;
	hb_position_t reserved7;
	hb_position_t reserved6;
	hb_position_t reserved5;
	hb_position_t reserved4;
	hb_position_t reserved3;
	hb_position_t reserved2;
	hb_position_t reserved1;
} hb_font_extents_t;

typedef struct hb_glyph_extents_t
{
	hb_position_t x_bearing;
	hb_position_t y_bearing;
	hb_position_t width;
	hb_position_t height;
} hb_glyph_extents_t;

typedef hb_bool_t (*hb_font_get_font_extents_func_t) (hb_font_t *font, void *font_data, hb_font_extents_t *metrics, void *user_data);
typedef hb_font_get_font_extents_func_t hb_font_get_font_h_extents_func_t;
typedef hb_font_get_font_extents_func_t hb_font_get_font_v_extents_func_t;

#ifndef HB_DISABLE_DEPRECATED
typedef hb_bool_t (*hb_font_get_glyph_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t *glyph, void *user_data);
#endif
typedef hb_bool_t (*hb_font_get_nominal_glyph_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t unicode, hb_codepoint_t *glyph, void *user_data);
typedef hb_bool_t (*hb_font_get_variation_glyph_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t unicode, hb_codepoint_t variation_selector, hb_codepoint_t *glyph, void *user_data);
typedef unsigned int (*hb_font_get_nominal_glyphs_func_t) (hb_font_t *font, void *font_data, unsigned int count, const hb_codepoint_t *first_unicode, unsigned int unicode_stride, hb_codepoint_t *first_glyph, unsigned int glyph_stride, void *user_data);
typedef hb_position_t (*hb_font_get_glyph_advance_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t glyph, void *user_data);
typedef hb_font_get_glyph_advance_func_t hb_font_get_glyph_h_advance_func_t;
typedef hb_font_get_glyph_advance_func_t hb_font_get_glyph_v_advance_func_t;

typedef void (*hb_font_get_glyph_advances_func_t) (hb_font_t* font, void* font_data, unsigned int count, const hb_codepoint_t *first_glyph, unsigned glyph_stride, hb_position_t *first_advance, unsigned advance_stride, void *user_data);
typedef hb_font_get_glyph_advances_func_t hb_font_get_glyph_h_advances_func_t;
typedef hb_font_get_glyph_advances_func_t hb_font_get_glyph_v_advances_func_t;

typedef hb_bool_t (*hb_font_get_glyph_origin_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t glyph, hb_position_t *x, hb_position_t *y, void *user_data);
typedef hb_font_get_glyph_origin_func_t hb_font_get_glyph_h_origin_func_t;
typedef hb_font_get_glyph_origin_func_t hb_font_get_glyph_v_origin_func_t;

typedef hb_position_t (*hb_font_get_glyph_kerning_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t first_glyph, hb_codepoint_t second_glyph, void *user_data);
typedef hb_font_get_glyph_kerning_func_t hb_font_get_glyph_h_kerning_func_t;
#ifndef HB_DISABLE_DEPRECATED
typedef hb_font_get_glyph_kerning_func_t hb_font_get_glyph_v_kerning_func_t;
#endif

typedef hb_bool_t (*hb_font_get_glyph_extents_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t glyph, hb_glyph_extents_t *extents, void *user_data);
typedef hb_bool_t (*hb_font_get_glyph_contour_point_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t glyph, unsigned int point_index, hb_position_t *x, hb_position_t *y, void *user_data);

typedef hb_bool_t (*hb_font_get_glyph_name_func_t) (hb_font_t *font, void *font_data, hb_codepoint_t glyph, char *name, unsigned int size, void *user_data);
typedef hb_bool_t (*hb_font_get_glyph_from_name_func_t) (hb_font_t *font, void *font_data, const char *name, int len, hb_codepoint_t *glyph, void *user_data);

#define HB_MAP_VALUE_INVALID ((hb_codepoint_t) -1)

typedef struct hb_map_t hb_map_t;

#define HB_SET_VALUE_INVALID ((hb_codepoint_t) -1)

typedef struct hb_set_t hb_set_t;

typedef struct hb_glyph_info_t {
	hb_codepoint_t codepoint;
	hb_mask_t mask;
	uint32_t cluster;
	hb_var_int_t var1;
	hb_var_int_t var2;
} hb_glyph_info_t;

typedef enum {
	HB_GLYPH_FLAG_UNSAFE_TO_BREAK		= 0x00000001,
	HB_GLYPH_FLAG_UNSAFE_TO_CONCAT		= 0x00000002,
	HB_GLYPH_FLAG_DEFINED			= 0x00000001
} hb_glyph_flags_t;

#define hb_glyph_info_get_glyph_flags(info) \
	((hb_glyph_flags_t) ((unsigned int) (info)->mask & HB_GLYPH_FLAG_DEFINED))

typedef struct hb_glyph_position_t {
	hb_position_t x_advance;
	hb_position_t y_advance;
	hb_position_t x_offset;
	hb_position_t y_offset;
	hb_var_int_t var;
} hb_glyph_position_t;


typedef struct hb_segment_properties_t {
	hb_direction_t direction;
	hb_script_t script;
	hb_language_t language;
	void *reserved1;
	void *reserved2;
} hb_segment_properties_t;

#define HB_SEGMENT_PROPERTIES_DEFAULT {HB_DIRECTION_INVALID, HB_SCRIPT_INVALID, HB_LANGUAGE_INVALID, (void *) 0, (void *) 0}

typedef struct hb_buffer_t hb_buffer_t;

typedef enum {
	HB_BUFFER_CONTENT_TYPE_INVALID = 0,
	HB_BUFFER_CONTENT_TYPE_UNICODE,
	HB_BUFFER_CONTENT_TYPE_GLYPHS
} hb_buffer_content_type_t;

typedef enum {
  HB_BUFFER_FLAG_DEFAULT = 0x00000000u,
  HB_BUFFER_FLAG_BOT = 0x00000001u,
  HB_BUFFER_FLAG_EOT = 0x00000002u,
  HB_BUFFER_FLAG_PRESERVE_DEFAULT_IGNORABLES = 0x00000004u,
  HB_BUFFER_FLAG_REMOVE_DEFAULT_IGNORABLES = 0x00000008u,
  HB_BUFFER_FLAG_DO_NOT_INSERT_DOTTED_CIRCLE = 0x00000010u
} hb_buffer_flags_t;
#ifndef HB_DISABLE_DEPRECATED
#define HB_BUFFER_FLAGS_DEFAULT HB_BUFFER_FLAG_DEFAULT
#endif

typedef enum {
	HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES = 0,
	HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS = 1,
	HB_BUFFER_CLUSTER_LEVEL_CHARACTERS = 2,
	HB_BUFFER_CLUSTER_LEVEL_DEFAULT = HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES
} hb_buffer_cluster_level_t;

#define HB_BUFFER_REPLACEMENT_CODEPOINT_DEFAULT 0xFFFDu

typedef enum {
	HB_BUFFER_SERIALIZE_FLAG_DEFAULT = 0x00000000u,
	HB_BUFFER_SERIALIZE_FLAG_NO_CLUSTERS = 0x00000001u,
	HB_BUFFER_SERIALIZE_FLAG_NO_POSITIONS = 0x00000002u,
	HB_BUFFER_SERIALIZE_FLAG_NO_GLYPH_NAMES = 0x00000004u,
	HB_BUFFER_SERIALIZE_FLAG_GLYPH_EXTENTS = 0x00000008u,
	HB_BUFFER_SERIALIZE_FLAG_GLYPH_FLAGS = 0x00000010u,
	HB_BUFFER_SERIALIZE_FLAG_NO_ADVANCES = 0x00000020u
} hb_buffer_serialize_flags_t;
#ifndef HB_DISABLE_DEPRECATED
#define HB_BUFFER_SERIALIZE_FLAGS_DEFAULT HB_BUFFER_SERIALIZE_FLAG_DEFAULT
#endif

typedef enum {
	HB_BUFFER_SERIALIZE_FORMAT_TEXT = HB_TAG('T','E','X','T'),
	HB_BUFFER_SERIALIZE_FORMAT_JS = HB_TAG('J','S','O','N'),
	HB_BUFFER_SERIALIZE_FORMAT_INVALID = HB_TAG_NONE
} hb_buffer_serialize_format_t;

typedef enum {
	HB_BUFFER_DIFF_FLAG_EQUAL = 0x0000,
	HB_BUFFER_DIFF_FLAG_CONTENT_TYPE_MISMATCH = 0x0001,
	HB_BUFFER_DIFF_FLAG_LENGTH_MISMATCH = 0x0002,
	HB_BUFFER_DIFF_FLAG_NOTDEF_PRESENT = 0x0004,
	HB_BUFFER_DIFF_FLAG_DOTTED_CIRCLE_PRESENT = 0x0008,
	HB_BUFFER_DIFF_FLAG_CODEPOINT_MISMATCH = 0x0010,
	HB_BUFFER_DIFF_FLAG_CLUSTER_MISMATCH = 0x0020,
	HB_BUFFER_DIFF_FLAG_GLYPH_FLAGS_MISMATCH = 0x0040,
	HB_BUFFER_DIFF_FLAG_POSITION_MISMATCH = 0x0080
} hb_buffer_diff_flags_t;

typedef hb_bool_t (*hb_buffer_message_func_t) (hb_buffer_t *buffer, hb_font_t *font, const char *message, void *user_data);

#define HB_OT_TAG_MATH HB_TAG('M','A','T','H')

#define HB_OT_MATH_SCRIPT HB_TAG('m','a','t','h')

typedef enum {
	HB_OT_MATH_CONSTANT_SCRIPT_PERCENT_SCALE_DOWN = 0,
	HB_OT_MATH_CONSTANT_SCRIPT_SCRIPT_PERCENT_SCALE_DOWN = 1,
	HB_OT_MATH_CONSTANT_DELIMITED_SUB_FORMULA_MIN_HEIGHT = 2,
	HB_OT_MATH_CONSTANT_DISPLAY_OPERATOR_MIN_HEIGHT = 3,
	HB_OT_MATH_CONSTANT_MATH_LEADING = 4,
	HB_OT_MATH_CONSTANT_AXIS_HEIGHT = 5,
	HB_OT_MATH_CONSTANT_ACCENT_BASE_HEIGHT = 6,
	HB_OT_MATH_CONSTANT_FLATTENED_ACCENT_BASE_HEIGHT = 7,
	HB_OT_MATH_CONSTANT_SUBSCRIPT_SHIFT_DOWN = 8,
	HB_OT_MATH_CONSTANT_SUBSCRIPT_TOP_MAX = 9,
	HB_OT_MATH_CONSTANT_SUBSCRIPT_BASELINE_DROP_MIN = 10,
	HB_OT_MATH_CONSTANT_SUPERSCRIPT_SHIFT_UP = 11,
	HB_OT_MATH_CONSTANT_SUPERSCRIPT_SHIFT_UP_CRAMPED = 12,
	HB_OT_MATH_CONSTANT_SUPERSCRIPT_BOTTOM_MIN = 13,
	HB_OT_MATH_CONSTANT_SUPERSCRIPT_BASELINE_DROP_MAX = 14,
	HB_OT_MATH_CONSTANT_SUB_SUPERSCRIPT_GAP_MIN = 15,
	HB_OT_MATH_CONSTANT_SUPERSCRIPT_BOTTOM_MAX_WITH_SUBSCRIPT = 16,
	HB_OT_MATH_CONSTANT_SPACE_AFTER_SCRIPT = 17,
	HB_OT_MATH_CONSTANT_UPPER_LIMIT_GAP_MIN = 18,
	HB_OT_MATH_CONSTANT_UPPER_LIMIT_BASELINE_RISE_MIN = 19,
	HB_OT_MATH_CONSTANT_LOWER_LIMIT_GAP_MIN = 20,
	HB_OT_MATH_CONSTANT_LOWER_LIMIT_BASELINE_DROP_MIN = 21,
	HB_OT_MATH_CONSTANT_STACK_TOP_SHIFT_UP = 22,
	HB_OT_MATH_CONSTANT_STACK_TOP_DISPLAY_STYLE_SHIFT_UP = 23,
	HB_OT_MATH_CONSTANT_STACK_BOTTOM_SHIFT_DOWN = 24,
	HB_OT_MATH_CONSTANT_STACK_BOTTOM_DISPLAY_STYLE_SHIFT_DOWN = 25,
	HB_OT_MATH_CONSTANT_STACK_GAP_MIN = 26,
	HB_OT_MATH_CONSTANT_STACK_DISPLAY_STYLE_GAP_MIN = 27,
	HB_OT_MATH_CONSTANT_STRETCH_STACK_TOP_SHIFT_UP = 28,
	HB_OT_MATH_CONSTANT_STRETCH_STACK_BOTTOM_SHIFT_DOWN = 29,
	HB_OT_MATH_CONSTANT_STRETCH_STACK_GAP_ABOVE_MIN = 30,
	HB_OT_MATH_CONSTANT_STRETCH_STACK_GAP_BELOW_MIN = 31,
	HB_OT_MATH_CONSTANT_FRACTION_NUMERATOR_SHIFT_UP = 32,
	HB_OT_MATH_CONSTANT_FRACTION_NUMERATOR_DISPLAY_STYLE_SHIFT_UP = 33,
	HB_OT_MATH_CONSTANT_FRACTION_DENOMINATOR_SHIFT_DOWN = 34,
	HB_OT_MATH_CONSTANT_FRACTION_DENOMINATOR_DISPLAY_STYLE_SHIFT_DOWN = 35,
	HB_OT_MATH_CONSTANT_FRACTION_NUMERATOR_GAP_MIN = 36,
	HB_OT_MATH_CONSTANT_FRACTION_NUM_DISPLAY_STYLE_GAP_MIN = 37,
	HB_OT_MATH_CONSTANT_FRACTION_RULE_THICKNESS = 38,
	HB_OT_MATH_CONSTANT_FRACTION_DENOMINATOR_GAP_MIN = 39,
	HB_OT_MATH_CONSTANT_FRACTION_DENOM_DISPLAY_STYLE_GAP_MIN = 40,
	HB_OT_MATH_CONSTANT_SKEWED_FRACTION_HORIZONTAL_GAP = 41,
	HB_OT_MATH_CONSTANT_SKEWED_FRACTION_VERTICAL_GAP = 42,
	HB_OT_MATH_CONSTANT_OVERBAR_VERTICAL_GAP = 43,
	HB_OT_MATH_CONSTANT_OVERBAR_RULE_THICKNESS = 44,
	HB_OT_MATH_CONSTANT_OVERBAR_EXTRA_ASCENDER = 45,
	HB_OT_MATH_CONSTANT_UNDERBAR_VERTICAL_GAP = 46,
	HB_OT_MATH_CONSTANT_UNDERBAR_RULE_THICKNESS = 47,
	HB_OT_MATH_CONSTANT_UNDERBAR_EXTRA_DESCENDER = 48,
	HB_OT_MATH_CONSTANT_RADICAL_VERTICAL_GAP = 49,
	HB_OT_MATH_CONSTANT_RADICAL_DISPLAY_STYLE_VERTICAL_GAP = 50,
	HB_OT_MATH_CONSTANT_RADICAL_RULE_THICKNESS = 51,
	HB_OT_MATH_CONSTANT_RADICAL_EXTRA_ASCENDER = 52,
	HB_OT_MATH_CONSTANT_RADICAL_KERN_BEFORE_DEGREE = 53,
	HB_OT_MATH_CONSTANT_RADICAL_KERN_AFTER_DEGREE = 54,
	HB_OT_MATH_CONSTANT_RADICAL_DEGREE_BOTTOM_RAISE_PERCENT = 55
} hb_ot_math_constant_t;

typedef enum {
	HB_OT_MATH_KERN_TOP_RIGHT = 0,
	HB_OT_MATH_KERN_TOP_LEFT = 1,
	HB_OT_MATH_KERN_BOTTOM_RIGHT = 2,
	HB_OT_MATH_KERN_BOTTOM_LEFT = 3
} hb_ot_math_kern_t;

typedef struct hb_ot_math_glyph_variant_t {
	hb_codepoint_t glyph;
	hb_position_t advance;
} hb_ot_math_glyph_variant_t;

typedef enum {
	HB_OT_MATH_GLYPH_PART_FLAG_EXTENDER = 0x00000001u
} hb_ot_math_glyph_part_flags_t;
#ifndef HB_DISABLE_DEPRECATED
#define HB_MATH_GLYPH_PART_FLAG_EXTENDER HB_OT_MATH_GLYPH_PART_FLAG_EXTENDER
#endif

typedef struct hb_ot_math_glyph_part_t {
	hb_codepoint_t glyph;
	hb_position_t start_connector_length;
	hb_position_t end_connector_length;
	hb_position_t full_advance;
	hb_ot_math_glyph_part_flags_t flags;
} hb_ot_math_glyph_part_t;

typedef enum {
	HB_OT_META_TAG_DESIGN_LANGUAGES			= HB_TAG ('d','l','n','g'),
	HB_OT_META_TAG_SUPPORTED_LANGUAGES		= HB_TAG ('s','l','n','g'),
	_HB_OT_META_TAG_MAX_VALUE = HB_TAG_MAX_SIGNED
} hb_ot_meta_tag_t;

typedef enum {
	HB_OT_METRICS_TAG_HORIZONTAL_ASCENDER		= HB_TAG ('h','a','s','c'),
	HB_OT_METRICS_TAG_HORIZONTAL_DESCENDER		= HB_TAG ('h','d','s','c'),
	HB_OT_METRICS_TAG_HORIZONTAL_LINE_GAP		= HB_TAG ('h','l','g','p'),
	HB_OT_METRICS_TAG_HORIZONTAL_CLIPPING_ASCENT	= HB_TAG ('h','c','l','a'),
	HB_OT_METRICS_TAG_HORIZONTAL_CLIPPING_DESCENT	= HB_TAG ('h','c','l','d'),
	HB_OT_METRICS_TAG_VERTICAL_ASCENDER		= HB_TAG ('v','a','s','c'),
	HB_OT_METRICS_TAG_VERTICAL_DESCENDER		= HB_TAG ('v','d','s','c'),
	HB_OT_METRICS_TAG_VERTICAL_LINE_GAP		= HB_TAG ('v','l','g','p'),
	HB_OT_METRICS_TAG_HORIZONTAL_CARET_RISE		= HB_TAG ('h','c','r','s'),
	HB_OT_METRICS_TAG_HORIZONTAL_CARET_RUN		= HB_TAG ('h','c','r','n'),
	HB_OT_METRICS_TAG_HORIZONTAL_CARET_OFFSET	= HB_TAG ('h','c','o','f'),
	HB_OT_METRICS_TAG_VERTICAL_CARET_RISE		= HB_TAG ('v','c','r','s'),
	HB_OT_METRICS_TAG_VERTICAL_CARET_RUN		= HB_TAG ('v','c','r','n'),
	HB_OT_METRICS_TAG_VERTICAL_CARET_OFFSET		= HB_TAG ('v','c','o','f'),
	HB_OT_METRICS_TAG_X_HEIGHT			= HB_TAG ('x','h','g','t'),
	HB_OT_METRICS_TAG_CAP_HEIGHT			= HB_TAG ('c','p','h','t'),
	HB_OT_METRICS_TAG_SUBSCRIPT_EM_X_SIZE		= HB_TAG ('s','b','x','s'),
	HB_OT_METRICS_TAG_SUBSCRIPT_EM_Y_SIZE		= HB_TAG ('s','b','y','s'),
	HB_OT_METRICS_TAG_SUBSCRIPT_EM_X_OFFSET		= HB_TAG ('s','b','x','o'),
	HB_OT_METRICS_TAG_SUBSCRIPT_EM_Y_OFFSET		= HB_TAG ('s','b','y','o'),
	HB_OT_METRICS_TAG_SUPERSCRIPT_EM_X_SIZE		= HB_TAG ('s','p','x','s'),
	HB_OT_METRICS_TAG_SUPERSCRIPT_EM_Y_SIZE		= HB_TAG ('s','p','y','s'),
	HB_OT_METRICS_TAG_SUPERSCRIPT_EM_X_OFFSET	= HB_TAG ('s','p','x','o'),
	HB_OT_METRICS_TAG_SUPERSCRIPT_EM_Y_OFFSET	= HB_TAG ('s','p','y','o'),
	HB_OT_METRICS_TAG_STRIKEOUT_SIZE		= HB_TAG ('s','t','r','s'),
	HB_OT_METRICS_TAG_STRIKEOUT_OFFSET		= HB_TAG ('s','t','r','o'),
	HB_OT_METRICS_TAG_UNDERLINE_SIZE		= HB_TAG ('u','n','d','s'),
	HB_OT_METRICS_TAG_UNDERLINE_OFFSET		= HB_TAG ('u','n','d','o'),
	_HB_OT_METRICS_TAG_MAX_VALUE = HB_TAG_MAX_SIGNED
} hb_ot_metrics_tag_t;

typedef struct hb_shape_plan_t hb_shape_plan_t;

#define HB_OT_TAG_BASE HB_TAG('B','A','S','E')
#define HB_OT_TAG_GDEF HB_TAG('G','D','E','F')
#define HB_OT_TAG_GSUB HB_TAG('G','S','U','B')
#define HB_OT_TAG_GPOS HB_TAG('G','P','O','S')
#define HB_OT_TAG_JSTF HB_TAG('J','S','T','F')

#define HB_OT_TAG_DEFAULT_SCRIPT HB_TAG ('D', 'F', 'L', 'T')
#define HB_OT_TAG_DEFAULT_LANGUAGE HB_TAG ('d', 'f', 'l', 't')

#define HB_OT_MAX_TAGS_PER_SCRIPT	3u
#define HB_OT_MAX_TAGS_PER_LANGUAGE	3u

typedef enum {
	HB_OT_LAYOUT_GLYPH_CLASS_UNCLASSIFIED = 0,
	HB_OT_LAYOUT_GLYPH_CLASS_BASE_GLYPH = 1,
	HB_OT_LAYOUT_GLYPH_CLASS_LIGATURE = 2,
	HB_OT_LAYOUT_GLYPH_CLASS_MARK = 3,
	HB_OT_LAYOUT_GLYPH_CLASS_COMPONENT = 4
} hb_ot_layout_glyph_class_t;

#define HB_OT_LAYOUT_NO_SCRIPT_INDEX 0xFFFFu
#define HB_OT_LAYOUT_NO_FEATURE_INDEX 0xFFFFu
#define HB_OT_LAYOUT_DEFAULT_LANGUAGE_INDEX 0xFFFFu
#define HB_OT_LAYOUT_NO_VARIATIONS_INDEX 0xFFFFFFFFu

typedef enum {
	HB_OT_LAYOUT_BASELINE_TAG_ROMAN				= HB_TAG ('r','o','m','n'),
	HB_OT_LAYOUT_BASELINE_TAG_HANGING			= HB_TAG ('h','a','n','g'),
	HB_OT_LAYOUT_BASELINE_TAG_IDEO_FACE_BOTTOM_OR_LEFT	= HB_TAG ('i','c','f','b'),
	HB_OT_LAYOUT_BASELINE_TAG_IDEO_FACE_TOP_OR_RIGHT	= HB_TAG ('i','c','f','t'),
	HB_OT_LAYOUT_BASELINE_TAG_IDEO_EMBOX_BOTTOM_OR_LEFT	= HB_TAG ('i','d','e','o'),
	HB_OT_LAYOUT_BASELINE_TAG_IDEO_EMBOX_TOP_OR_RIGHT	= HB_TAG ('i','d','t','p'),
	HB_OT_LAYOUT_BASELINE_TAG_MATH				= HB_TAG ('m','a','t','h'),
	_HB_OT_LAYOUT_BASELINE_TAG_MAX_VALUE = HB_TAG_MAX_SIGNED
} hb_ot_layout_baseline_tag_t;

enum
{
	HB_OT_NAME_ID_COPYRIGHT			= 0,
	HB_OT_NAME_ID_FONT_FAMILY		= 1,
	HB_OT_NAME_ID_FONT_SUBFAMILY		= 2,
	HB_OT_NAME_ID_UNIQUE_ID			= 3,
	HB_OT_NAME_ID_FULL_NAME			= 4,
	HB_OT_NAME_ID_VERSION_STRING		= 5,
	HB_OT_NAME_ID_POSTSCRIPT_NAME		= 6,
	HB_OT_NAME_ID_TRADEMARK			= 7,
	HB_OT_NAME_ID_MANUFACTURER		= 8,
	HB_OT_NAME_ID_DESIGNER			= 9,
	HB_OT_NAME_ID_DESCRIPTION		= 10,
	HB_OT_NAME_ID_VENDOR_URL		= 11,
	HB_OT_NAME_ID_DESIGNER_URL		= 12,
	HB_OT_NAME_ID_LICENSE			= 13,
	HB_OT_NAME_ID_LICENSE_URL		= 14,
	/*HB_OT_NAME_ID_RESERVED		= 15,*/
	HB_OT_NAME_ID_TYPOGRAPHIC_FAMILY	= 16,
	HB_OT_NAME_ID_TYPOGRAPHIC_SUBFAMILY	= 17,
	HB_OT_NAME_ID_MAC_FULL_NAME		= 18,
	HB_OT_NAME_ID_SAMPLE_TEXT		= 19,
	HB_OT_NAME_ID_CID_FINDFONT_NAME		= 20,
	HB_OT_NAME_ID_WWS_FAMILY		= 21,
	HB_OT_NAME_ID_WWS_SUBFAMILY		= 22,
	HB_OT_NAME_ID_LIGHT_BACKGROUND		= 23,
	HB_OT_NAME_ID_DARK_BACKGROUND		= 24,
	HB_OT_NAME_ID_VARIATIONS_PS_PREFIX	= 25,
	HB_OT_NAME_ID_INVALID			= 0xFFFF
};

typedef unsigned int hb_ot_name_id_t;

typedef struct hb_ot_name_entry_t
{
	hb_ot_name_id_t name_id;
	hb_var_int_t var;
	hb_language_t language;
} hb_ot_name_entry_t;

#define HB_OT_TAG_VAR_AXIS_ITALIC HB_TAG('i','t','a','l')
#define HB_OT_TAG_VAR_AXIS_OPTICAL_SIZE HB_TAG('o','p','s','z')
#define HB_OT_TAG_VAR_AXIS_SLANT HB_TAG('s','l','n','t')
#define HB_OT_TAG_VAR_AXIS_WIDTH HB_TAG('w','d','t','h')
#define HB_OT_TAG_VAR_AXIS_WEIGHT HB_TAG('w','g','h','t')

typedef enum {
	HB_OT_VAR_AXIS_FLAG_HIDDEN    = 0x00000001u,
	_HB_OT_VAR_AXIS_FLAG_MAX_VALUE= 0x7FFFFFFFu
} hb_ot_var_axis_flags_t;

typedef struct hb_ot_var_axis_info_t
{
	unsigned int axis_index;
	hb_tag_t tag;
	hb_ot_name_id_t name_id;
	hb_ot_var_axis_flags_t flags;
	float min_value;
	float default_value;
	float max_value;
	unsigned int reserved;
} hb_ot_var_axis_info_t;

#ifndef HB_DISABLE_DEPRECATED
typedef struct hb_ot_var_axis_t {
	hb_tag_t tag;
	unsigned int name_id;
	float min_value;
	float default_value;
	float max_value;
} hb_ot_var_axis_t;

#define HB_OT_VAR_NO_AXIS_INDEX 0xFFFFFFFFu
#endif

typedef enum {
	HB_OT_COLOR_PALETTE_FLAG_DEFAULT                      = 0x00000000u,
	HB_OT_COLOR_PALETTE_FLAG_USABLE_WITH_LIGHT_BACKGROUND = 0x00000001u,
	HB_OT_COLOR_PALETTE_FLAG_USABLE_WITH_DARK_BACKGROUND  = 0x00000002u
} hb_ot_color_palette_flags_t;

typedef struct hb_ot_color_layer_t
{
	hb_codepoint_t glyph;
	unsigned int color_index;
} hb_ot_color_layer_t;

typedef enum
{
	HB_AAT_LAYOUT_FEATURE_TYPE_INVALID			= 0xFFFF,
	HB_AAT_LAYOUT_FEATURE_TYPE_ALL_TYPOGRAPHIC		= 0,
	HB_AAT_LAYOUT_FEATURE_TYPE_LIGATURES				= 1,
	HB_AAT_LAYOUT_FEATURE_TYPE_CURISVE_CONNECTION			= 2,
	HB_AAT_LAYOUT_FEATURE_TYPE_LETTER_CASE			= 3,
	HB_AAT_LAYOUT_FEATURE_TYPE_VERTICAL_SUBSTITUTION		= 4,
	HB_AAT_LAYOUT_FEATURE_TYPE_LINGUISTIC_REARRANGEMENT		= 5,
	HB_AAT_LAYOUT_FEATURE_TYPE_NUMBER_SPACING			= 6,
	HB_AAT_LAYOUT_FEATURE_TYPE_SMART_SWASH_TYPE			= 8,
	HB_AAT_LAYOUT_FEATURE_TYPE_DIACRITICS_TYPE			= 9,
	HB_AAT_LAYOUT_FEATURE_TYPE_VERTICAL_POSITION			= 10,
	HB_AAT_LAYOUT_FEATURE_TYPE_FRACTIONS				= 11,
	HB_AAT_LAYOUT_FEATURE_TYPE_OVERLAPPING_CHARACTERS_TYPE	= 13,
	HB_AAT_LAYOUT_FEATURE_TYPE_TYPOGRAPHIC_EXTRAS			= 14,
	HB_AAT_LAYOUT_FEATURE_TYPE_MATHEMATICAL_EXTRAS		= 15,
	HB_AAT_LAYOUT_FEATURE_TYPE_ORNAMENT_SETS_TYPE			= 16,
	HB_AAT_LAYOUT_FEATURE_TYPE_CHARACTER_ALTERNATIVES		= 17,
	HB_AAT_LAYOUT_FEATURE_TYPE_DESIGN_COMPLEXITY_TYPE		= 18,
	HB_AAT_LAYOUT_FEATURE_TYPE_STYLE_OPTIONS			= 19,
	HB_AAT_LAYOUT_FEATURE_TYPE_CHARACTER_SHAPE			= 20,
	HB_AAT_LAYOUT_FEATURE_TYPE_NUMBER_CASE			= 21,
	HB_AAT_LAYOUT_FEATURE_TYPE_TEXT_SPACING			= 22,
	HB_AAT_LAYOUT_FEATURE_TYPE_TRANSLITERATION			= 23,
	HB_AAT_LAYOUT_FEATURE_TYPE_ANNOTATION_TYPE			= 24,
	HB_AAT_LAYOUT_FEATURE_TYPE_KANA_SPACING_TYPE			= 25,
	HB_AAT_LAYOUT_FEATURE_TYPE_IDEOGRAPHIC_SPACING_TYPE		= 26,
	HB_AAT_LAYOUT_FEATURE_TYPE_UNICODE_DECOMPOSITION_TYPE		= 27,
	HB_AAT_LAYOUT_FEATURE_TYPE_RUBY_KANA				= 28,
	HB_AAT_LAYOUT_FEATURE_TYPE_CJK_SYMBOL_ALTERNATIVES_TYPE	= 29,
	HB_AAT_LAYOUT_FEATURE_TYPE_IDEOGRAPHIC_ALTERNATIVES_TYPE	= 30,
	HB_AAT_LAYOUT_FEATURE_TYPE_CJK_VERTICAL_ROMAN_PLACEMENT_TYPE	= 31,
	HB_AAT_LAYOUT_FEATURE_TYPE_ITALIC_CJK_ROMAN			= 32,
	HB_AAT_LAYOUT_FEATURE_TYPE_CASE_SENSITIVE_LAYOUT		= 33,
	HB_AAT_LAYOUT_FEATURE_TYPE_ALTERNATE_KANA			= 34,
	HB_AAT_LAYOUT_FEATURE_TYPE_STYLISTIC_ALTERNATIVES		= 35,
	HB_AAT_LAYOUT_FEATURE_TYPE_CONTEXTUAL_ALTERNATIVES		= 36,
	HB_AAT_LAYOUT_FEATURE_TYPE_LOWER_CASE				= 37,
	HB_AAT_LAYOUT_FEATURE_TYPE_UPPER_CASE				= 38,
	HB_AAT_LAYOUT_FEATURE_TYPE_LANGUAGE_TAG_TYPE			= 39,
	HB_AAT_LAYOUT_FEATURE_TYPE_CJK_ROMAN_SPACING_TYPE		= 103,

	_HB_AAT_LAYOUT_FEATURE_TYPE_MAX_VALUE= 0x7FFFFFFFu,
} hb_aat_layout_feature_type_t;

typedef enum
{
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INVALID			= 0xFFFF,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALL_TYPE_FEATURES_ON		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALL_TYPE_FEATURES_OFF		= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_REQUIRED_LIGATURES_ON		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_REQUIRED_LIGATURES_OFF		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_COMMON_LIGATURES_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_COMMON_LIGATURES_OFF		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_RARE_LIGATURES_ON		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_RARE_LIGATURES_OFF		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LOGOS_ON			= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LOGOS_OFF			= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_REBUS_PICTURES_ON		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_REBUS_PICTURES_OFF		= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DIPHTHONG_LIGATURES_ON		= 10,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DIPHTHONG_LIGATURES_OFF	= 11,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SQUARED_LIGATURES_ON		= 12,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SQUARED_LIGATURES_OFF		= 13,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ABBREV_SQUARED_LIGATURES_ON	= 14,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ABBREV_SQUARED_LIGATURES_OFF	= 15,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SYMBOL_LIGATURES_ON		= 16,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SYMBOL_LIGATURES_OFF		= 17,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_LIGATURES_ON	= 18,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_LIGATURES_OFF	= 19,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HISTORICAL_LIGATURES_ON	= 20,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HISTORICAL_LIGATURES_OFF	= 21,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_UNCONNECTED			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PARTIALLY_CONNECTED		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CURSIVE			= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_UPPER_AND_LOWER_CASE		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALL_CAPS			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALL_LOWER_CASE			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SMALL_CAPS			= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INITIAL_CAPS			= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INITIAL_CAPS_AND_SMALL_CAPS	= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_SUBSTITUTE_VERTICAL_FORMS_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SUBSTITUTE_VERTICAL_FORMS_OFF	= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINGUISTIC_REARRANGEMENT_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINGUISTIC_REARRANGEMENT_OFF	= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_MONOSPACED_NUMBERS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PROPORTIONAL_NUMBERS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_THIRD_WIDTH_NUMBERS		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_QUARTER_WIDTH_NUMBERS		= 3,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_WORD_INITIAL_SWASHES_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_WORD_INITIAL_SWASHES_OFF	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_WORD_FINAL_SWASHES_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_WORD_FINAL_SWASHES_OFF		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINE_INITIAL_SWASHES_ON	= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINE_INITIAL_SWASHES_OFF	= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINE_FINAL_SWASHES_ON		= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LINE_FINAL_SWASHES_OFF		= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_NON_FINAL_SWASHES_ON		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_NON_FINAL_SWASHES_OFF		= 9,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_SHOW_DIACRITICS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HIDE_DIACRITICS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DECOMPOSE_DIACRITICS		= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NORMAL_POSITION		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SUPERIORS			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INFERIORS			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ORDINALS			= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SCIENTIFIC_INFERIORS		= 4,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_FRACTIONS			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_VERTICAL_FRACTIONS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DIAGONAL_FRACTIONS		= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_PREVENT_OVERLAP_ON		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PREVENT_OVERLAP_OFF		= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHENS_TO_EM_DASH_ON		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHENS_TO_EM_DASH_OFF		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHEN_TO_EN_DASH_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHEN_TO_EN_DASH_OFF		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SLASHED_ZERO_ON		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SLASHED_ZERO_OFF		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_FORM_INTERROBANG_ON		= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_FORM_INTERROBANG_OFF		= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SMART_QUOTES_ON		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SMART_QUOTES_OFF		= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PERIODS_TO_ELLIPSIS_ON		= 10,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PERIODS_TO_ELLIPSIS_OFF	= 11,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHEN_TO_MINUS_ON		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HYPHEN_TO_MINUS_OFF		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ASTERISK_TO_MULTIPLY_ON	= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ASTERISK_TO_MULTIPLY_OFF	= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SLASH_TO_DIVIDE_ON		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SLASH_TO_DIVIDE_OFF		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INEQUALITY_LIGATURES_ON	= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INEQUALITY_LIGATURES_OFF	= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_EXPONENTS_ON			= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_EXPONENTS_OFF			= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_MATHEMATICAL_GREEK_ON		= 10,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_MATHEMATICAL_GREEK_OFF		= 11,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_ORNAMENTS			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DINGBATS			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PI_CHARACTERS			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_FLEURONS			= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DECORATIVE_BORDERS		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INTERNATIONAL_SYMBOLS		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_MATH_SYMBOLS			= 6,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_ALTERNATES			= 0,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_DESIGN_LEVEL1			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DESIGN_LEVEL2			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DESIGN_LEVEL3			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DESIGN_LEVEL4			= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DESIGN_LEVEL5			= 4,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_STYLE_OPTIONS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DISPLAY_TEXT			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ENGRAVED_TEXT			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ILLUMINATED_CAPS		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TITLING_CAPS			= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TALL_CAPS			= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_CHARACTERS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SIMPLIFIED_CHARACTERS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_JIS1978_CHARACTERS		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_JIS1983_CHARACTERS		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_JIS1990_CHARACTERS		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_ALT_ONE		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_ALT_TWO		= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_ALT_THREE		= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_ALT_FOUR		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_ALT_FIVE		= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_EXPERT_CHARACTERS		= 10,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_JIS2004_CHARACTERS		= 11,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HOJO_CHARACTERS		= 12,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_NLCCHARACTERS			= 13,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRADITIONAL_NAMES_CHARACTERS	= 14,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_LOWER_CASE_NUMBERS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_UPPER_CASE_NUMBERS		= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_PROPORTIONAL_TEXT		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_MONOSPACED_TEXT		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HALF_WIDTH_TEXT		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_THIRD_WIDTH_TEXT		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_QUARTER_WIDTH_TEXT		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALT_PROPORTIONAL_TEXT		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALT_HALF_WIDTH_TEXT		= 6,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_TRANSLITERATION		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HANJA_TO_HANGUL		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HIRAGANA_TO_KATAKANA		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_KATAKANA_TO_HIRAGANA		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_KANA_TO_ROMANIZATION		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ROMANIZATION_TO_HIRAGANA	= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ROMANIZATION_TO_KATAKANA	= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HANJA_TO_HANGUL_ALT_ONE	= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HANJA_TO_HANGUL_ALT_TWO	= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HANJA_TO_HANGUL_ALT_THREE	= 9,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_ANNOTATION			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_BOX_ANNOTATION			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ROUNDED_BOX_ANNOTATION		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CIRCLE_ANNOTATION		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INVERTED_CIRCLE_ANNOTATION	= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PARENTHESIS_ANNOTATION		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PERIOD_ANNOTATION		= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ROMAN_NUMERAL_ANNOTATION	= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DIAMOND_ANNOTATION		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INVERTED_BOX_ANNOTATION	= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_INVERTED_ROUNDED_BOX_ANNOTATION= 10,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_FULL_WIDTH_KANA		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PROPORTIONAL_KANA		= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_FULL_WIDTH_IDEOGRAPHS		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PROPORTIONAL_IDEOGRAPHS	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_HALF_WIDTH_IDEOGRAPHS		= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_CANONICAL_COMPOSITION_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CANONICAL_COMPOSITION_OFF	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_COMPATIBILITY_COMPOSITION_ON	= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_COMPATIBILITY_COMPOSITION_OFF	= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRANSCODING_COMPOSITION_ON	= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_TRANSCODING_COMPOSITION_OFF	= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_RUBY_KANA			= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_RUBY_KANA			= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_RUBY_KANA_ON			= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_RUBY_KANA_OFF			= 3,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_CJK_SYMBOL_ALTERNATIVES	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_SYMBOL_ALT_ONE		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_SYMBOL_ALT_TWO		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_SYMBOL_ALT_THREE		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_SYMBOL_ALT_FOUR		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_SYMBOL_ALT_FIVE		= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_IDEOGRAPHIC_ALTERNATIVES	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_IDEOGRAPHIC_ALT_ONE		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_IDEOGRAPHIC_ALT_TWO		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_IDEOGRAPHIC_ALT_THREE		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_IDEOGRAPHIC_ALT_FOUR		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_IDEOGRAPHIC_ALT_FIVE		= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_VERTICAL_ROMAN_CENTERED	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_VERTICAL_ROMAN_HBASELINE	= 1,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_CJK_ITALIC_ROMAN		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_ITALIC_ROMAN		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_ITALIC_ROMAN_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CJK_ITALIC_ROMAN_OFF		= 3,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_CASE_SENSITIVE_LAYOUT_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CASE_SENSITIVE_LAYOUT_OFF	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CASE_SENSITIVE_SPACING_ON	= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CASE_SENSITIVE_SPACING_OFF	= 3,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALTERNATE_HORIZ_KANA_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALTERNATE_HORIZ_KANA_OFF	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALTERNATE_VERT_KANA_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_ALTERNATE_VERT_KANA_OFF	= 3,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_NO_STYLISTIC_ALTERNATES	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_ONE_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_ONE_OFF		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWO_ON		= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWO_OFF		= 5,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_THREE_ON		= 6,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_THREE_OFF	= 7,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FOUR_ON		= 8,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FOUR_OFF		= 9,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FIVE_ON		= 10,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FIVE_OFF		= 11,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SIX_ON		= 12,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SIX_OFF		= 13,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SEVEN_ON		= 14,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SEVEN_OFF	= 15,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_EIGHT_ON		= 16,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_EIGHT_OFF	= 17,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_NINE_ON		= 18,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_NINE_OFF		= 19,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TEN_ON		= 20,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TEN_OFF		= 21,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_ELEVEN_ON	= 22,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_ELEVEN_OFF	= 23,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWELVE_ON	= 24,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWELVE_OFF	= 25,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_THIRTEEN_ON	= 26,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_THIRTEEN_OFF	= 27,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FOURTEEN_ON	= 28,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FOURTEEN_OFF	= 29,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FIFTEEN_ON	= 30,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_FIFTEEN_OFF	= 31,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SIXTEEN_ON	= 32,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SIXTEEN_OFF	= 33,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SEVENTEEN_ON	= 34,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_SEVENTEEN_OFF	= 35,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_EIGHTEEN_ON	= 36,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_EIGHTEEN_OFF	= 37,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_NINETEEN_ON	= 38,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_NINETEEN_OFF	= 39,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWENTY_ON	= 40,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_STYLISTIC_ALT_TWENTY_OFF	= 41,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_ALTERNATES_ON	= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_ALTERNATES_OFF	= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SWASH_ALTERNATES_ON		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_SWASH_ALTERNATES_OFF		= 3,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_SWASH_ALTERNATES_ON	= 4,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_CONTEXTUAL_SWASH_ALTERNATES_OFF= 5,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_DEFAULT_LOWER_CASE		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LOWER_CASE_SMALL_CAPS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_LOWER_CASE_PETITE_CAPS		= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_DEFAULT_UPPER_CASE		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_UPPER_CASE_SMALL_CAPS		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_UPPER_CASE_PETITE_CAPS		= 2,

	HB_AAT_LAYOUT_FEATURE_SELECTOR_HALF_WIDTH_CJK_ROMAN		= 0,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_PROPORTIONAL_CJK_ROMAN		= 1,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_DEFAULT_CJK_ROMAN		= 2,
	HB_AAT_LAYOUT_FEATURE_SELECTOR_FULL_WIDTH_CJK_ROMAN		= 3,

	_HB_AAT_LAYOUT_FEATURE_SELECTOR_MAX_VALUE= 0x7FFFFFFFu,
} hb_aat_layout_feature_selector_t;

typedef struct hb_aat_layout_feature_selector_info_t
{
	hb_ot_name_id_t name_id;
	hb_aat_layout_feature_selector_t enable;
	hb_aat_layout_feature_selector_t disable;
	unsigned int reserved;
} hb_aat_layout_feature_selector_info_t;

#define HB_AAT_LAYOUT_NO_SELECTOR_INDEX		0xFFFFu

typedef enum
{
	HB_STYLE_TAG_ITALIC		= HB_TAG ('i','t','a','l'),
	HB_STYLE_TAG_OPTICAL_SIZE	= HB_TAG ('o','p','s','z'),
	HB_STYLE_TAG_SLANT_ANGLE	= HB_TAG ('s','l','n','t'),
	HB_STYLE_TAG_SLANT_RATIO	= HB_TAG ('S','l','n','t'),
	HB_STYLE_TAG_WIDTH		= HB_TAG ('w','d','t','h'),
	HB_STYLE_TAG_WEIGHT		= HB_TAG ('w','g','h','t'),

	_HB_STYLE_TAG_MAX_VALUE		= HB_TAG_MAX_SIGNED
} hb_style_tag_t;

typedef struct hb_subset_input_t hb_subset_input_t;

typedef enum {
	HB_SUBSET_FLAGS_DEFAULT =			0x00000000u,
	HB_SUBSET_FLAGS_NO_HINTING =			0x00000001u,
	HB_SUBSET_FLAGS_RETAIN_GIDS =			0x00000002u,
	HB_SUBSET_FLAGS_DESUBROUTINIZE =		0x00000004u,
	HB_SUBSET_FLAGS_NAME_LEGACY =			0x00000008u,
	HB_SUBSET_FLAGS_SET_OVERLAPS_FLAG =		0x00000010u,
	HB_SUBSET_FLAGS_PASSTHROUGH_UNRECOGNIZED =	0x00000020u,
	HB_SUBSET_FLAGS_NOTDEF_OUTLINE =		0x00000040u,
	HB_SUBSET_FLAGS_GLYPH_NAMES =			0x00000080u,
	HB_SUBSET_FLAGS_NO_PRUNE_UNICODE_RANGES =	0x00000100u,
} hb_subset_flags_t;

typedef enum {
	HB_SUBSET_SETS_GLYPH_INDEX = 0,
	HB_SUBSET_SETS_UNICODE,
	HB_SUBSET_SETS_NO_SUBSET_TABLE_TAG,
	HB_SUBSET_SETS_DROP_TABLE_TAG,
	HB_SUBSET_SETS_NAME_ID,
	HB_SUBSET_SETS_NAME_LANG_ID,
	HB_SUBSET_SETS_LAYOUT_FEATURE_TAG,
} hb_subset_sets_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBRARIES_HARFBUZZ_H */
