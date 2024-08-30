#ifndef CLIB_EXPAT_PROTOS_H
#define CLIB_EXPAT_PROTOS_H

/*
**  $VER: expat_protos.h 5.0 (30.9.2009)
**  Includes Release 5.0
**
**  C prototypes. For use with 32 bit integers only.
**
**  Written by Alfonso [alfie] Ranieri <alforan@tin.it>.
**
**  Released under the terms of the
**  GNU Public Licence version 2
*/

#ifndef LIBRARIES_EXPAT_H
#include <libraries/expat.h>
#endif

XML_Parser XML_ParserCreate ( const XML_Char *encodingName );
XML_Parser XML_ParserCreateNS ( const XML_Char *encodingName , XML_Char nsSep );
XML_Parser XML_ParserCreate_MM ( const XML_Char *encodingName , const XML_Memory_Handling_Suite *memsuite , const XML_Char *nameSep );
XML_Bool XML_ParserReset ( XML_Parser parser , const XML_Char *encodingName );
int XML_SetEncoding ( XML_Parser parser , const XML_Char *encodingName );
XML_Parser XML_ExternalEntityParserCreate ( XML_Parser oldParser , const XML_Char *context , const XML_Char *encodingName );
void XML_ParserFree ( XML_Parser parser );
void XML_UseParserAsHandlerArg ( XML_Parser parser );
int XML_UseForeignDTD ( XML_Parser parser , XML_Bool useDTD );
void XML_SetReturnNSTriplet ( XML_Parser parser , int do_nst );
void XML_SetUserData ( XML_Parser parser , void *p );
int XML_SetBase ( XML_Parser parser , const XML_Char *p );
const XML_Char *XML_GetBase ( XML_Parser parser );
int XML_GetSpecifiedAttributeCount ( XML_Parser parser );
int XML_GetIdAttributeIndex ( XML_Parser parser );
int XML_SetParamEntityParsing ( XML_Parser parser , int peParsing );
int XML_Parse ( XML_Parser parser , const char *s , int len , int isFinal );
int XML_ParseBuffer ( XML_Parser parser , int len , int isFinal );
void *XML_GetBuffer ( XML_Parser parser , int len );
int XML_StopParser ( XML_Parser parser , XML_Bool resumable );
int XML_ResumeParser ( XML_Parser parser );
void XML_GetParsingStatus ( XML_Parser parser , XML_ParsingStatus *status );

int XML_GetErrorCode ( XML_Parser parser );
long XML_GetCurrentByteIndex ( XML_Parser parser );
int XML_GetCurrentByteCount ( XML_Parser parser );
const char *XML_GetInputContext ( XML_Parser parser , int *offset , int *size );
XML_Size XML_GetCurrentLineNumber ( XML_Parser parser );
XML_Size XML_GetCurrentColumnNumber ( XML_Parser parser );
void XML_FreeContentModel ( XML_Parser parser , XML_Content *model );
void *XML_MemMalloc ( XML_Parser parser , size_t size );
void *XML_MemRealloc ( XML_Parser parser , void *ptr , size_t size );
void XML_MemFree ( XML_Parser parser , void *ptr );
void XML_DefaultCurrent ( XML_Parser parser );
const XML_LChar *XML_ErrorString ( int code );
const XML_LChar *XML_ExpatVersion ( void );
XML_Expat_Version XML_ExpatVersionInfo ( void );
const XML_Feature *XML_GetFeatureList ( void );

void XML_SetElementHandler ( XML_Parser parser , XML_StartElementHandler start , XML_EndElementHandler end );
void XML_SetStartElementHandler ( XML_Parser parser , XML_StartElementHandler start );
void XML_SetEndElementHandler ( XML_Parser parser , XML_EndElementHandler end );
void XML_SetCharacterDataHandler ( XML_Parser parser , XML_CharacterDataHandler handler );
void XML_SetProcessingInstructionHandler ( XML_Parser parser , XML_ProcessingInstructionHandler handler );
void XML_SetCommentHandler ( XML_Parser parser , XML_CommentHandler handler );
void XML_SetCdataSectionHandler ( XML_Parser parser , XML_StartCdataSectionHandler start , XML_EndCdataSectionHandler end );
void XML_SetStartCdataSectionHandler ( XML_Parser parser , XML_StartCdataSectionHandler start );
void XML_SetEndCdataSectionHandler ( XML_Parser parser , XML_EndCdataSectionHandler end );
void XML_SetDefaultHandler ( XML_Parser parser , XML_DefaultHandler handler );
void XML_SetDefaultHandlerExpand ( XML_Parser parser , XML_DefaultHandler handler );
void XML_SetDoctypeDeclHandler ( XML_Parser parser , XML_StartDoctypeDeclHandler start , XML_EndDoctypeDeclHandler end );
void XML_SetStartDoctypeDeclHandler ( XML_Parser parser , XML_StartDoctypeDeclHandler start );
void XML_SetEndDoctypeDeclHandler ( XML_Parser parser , XML_EndDoctypeDeclHandler end );
void XML_SetUnparsedEntityDeclHandler ( XML_Parser parser , XML_UnparsedEntityDeclHandler handler );
void XML_SetNotationDeclHandler ( XML_Parser parser , XML_NotationDeclHandler handler );
void XML_SetNamespaceDeclHandler ( XML_Parser parser , XML_StartNamespaceDeclHandler start , XML_EndNamespaceDeclHandler end );
void XML_SetStartNamespaceDeclHandler ( XML_Parser parser , XML_StartNamespaceDeclHandler start );
void XML_SetEndNamespaceDeclHandler ( XML_Parser parser , XML_EndNamespaceDeclHandler end );
void XML_SetNotStandaloneHandler ( XML_Parser parser , XML_NotStandaloneHandler handler );
void XML_SetExternalEntityRefHandler ( XML_Parser parser , XML_ExternalEntityRefHandler handler );
void XML_SetExternalEntityRefHandlerArg ( XML_Parser parser , void *arg );
void XML_SetSkippedEntityHandler ( XML_Parser parser , XML_SkippedEntityHandler handler );
void XML_SetUnknownEncodingHandler ( XML_Parser parser , XML_UnknownEncodingHandler handler , void *data );
void XML_SetElementDeclHandler ( XML_Parser parser , XML_ElementDeclHandler eldecl );
void XML_SetAttlistDeclHandler ( XML_Parser parser , XML_AttlistDeclHandler attdecl );
void XML_SetEntityDeclHandler ( XML_Parser parser , XML_EntityDeclHandler handler );
void XML_SetXmlDeclHandler ( XML_Parser parser , XML_XmlDeclHandler handler );

XML_Parser XML_ParserCreate_M68K ( const XML_Char *encodingName );
XML_Parser XML_ParserCreateNS_M68K ( const XML_Char *encodingName , XML_Char nsSep );
XML_Parser XML_ParserCreate_MM_M68K ( const XML_Char *encodingName , const XML_Memory_Handling_Suite *memsuite , const XML_Char *nameSep );
int XML_SetHashSalt (XML_Parser parser, unsigned long hash_salt );

XML_Bool XML_SetBillionLaughsAttackProtectionMaximumAmplification ( XML_Parser parser, float maximumAmplificationFactor );
XML_Bool XML_SetBillionLaughsAttackProtectionActivationThreshold ( XML_Parser parser, unsigned long long activationThresholdBytes );
#endif /* CLIB_EXPAT_PROTOS_H */
