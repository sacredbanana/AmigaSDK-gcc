__asm("\n"
".section \".ctors\",\"a\",@progbits\n"
".globl __ctrslist\n"
"__ctrslist:\n"
".long -1\n"
".section \".dtors\",\"a\",@progbits\n"
".globl __dtrslist\n"
"__dtrslist:\n"
".long -1\n"
".section \".text\"\n");