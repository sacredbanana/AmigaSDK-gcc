#if !defined(USE_INLINE_STDARG)
void   TestSPrintf(char *Buffer, char *Fmt, ...);
#endif
double TestAdd(double Arg1, double Arg2);
double TestSub(double Arg1, double Arg2);
ULONG  TestTagList(struct TagItem *Tags);
#if !defined(USE_INLINE_STDARG)
ULONG  TestTags(...);
#endif
