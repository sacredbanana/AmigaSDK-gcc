APTR OpenDictionary(CONST_STRPTR, struct TagItem *ti);
void CloseDictionary(APTR);
STRPTR* Suggest(APTR, CONST_STRPTR, struct TagItem *ti);
BOOL Learn(APTR, CONST_STRPTR);
BOOL SpellCheck(APTR, CONST_STRPTR, struct TagItem *ti);
APTR ListDictionaries(VOID *, ULONG, struct TagItem *ti);
