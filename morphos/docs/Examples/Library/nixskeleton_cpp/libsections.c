__asm("\n"
".section \".ctdt\",\"a\",@progbits\n"
".globl __ctdtlist\n"
"__ctdtlist:\n"
".long -1,-1\n"
".section \".ctors\",\"a\",@progbits\n"
".globl __ctrslist\n"
"__ctrslist:\n"
".long -1\n"
".section \".dtors\",\"a\",@progbits\n"
".globl __dtrslist\n"
"__dtrslist:\n"
".long -1\n"
".section \".text\"\n");