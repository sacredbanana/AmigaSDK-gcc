#ifndef NUMERICSTRING_MCC_H
#define NUMERICSTRING_MCC_H

/*
	NumericString.mcc include

	Copyright © 2004-2016 The MorphOS Development Team, All Rights Reserved.
*/

#define MUIC_NumericString "NumericString.mcc"
#define NumericStringObject MUI_NewObject(MUIC_NumericString

/*
** The supported Numeric attributes/methods are:
**   MUIA_Numeric_Max/Min
**   MUIA_Numeric_Value (values outside Max/Min will be clipped)
**   MUIM_Numeric_Decrease/Increase
**
** Default attribute values are the usual ones, except:
**   MUIA_String_Accept: "-0123456789"
**       (if MUIA_Numeric_Min >= 0, i.e. no negative numbers are accepted,
**        the minus character will be automatically rejected too)
**   MUIA_String_Format: MUIV_String_Format_Right
**   MUIA_String_MaxLen: 12
**
** Setting the following String attributes is discouraged:
**   MUIA_String_Accept/Reject (the default is adequate, see above)
**
** Setting the following String attributes is forbidden:
**   MUIA_String_Contents (set MUIA_Numeric_Value)
**   MUIA_String_Integer  (set MUIA_Numeric_Value)
**
** Getting them and notifying on them is ok.
*/

#endif
