#ifndef _SCRCNTL_H
#define _SCRCNTL_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#include <sys/cdefs.h>

#define CSI "\x9b"

extern void scr_beep __P((void));
#define scr_beep()      (void)(printf("\7"),fflush(stdout))

extern void scr_bs __P((void));
#define scr_bs()        (void)(printf(CSI"D"),fflush(stdout))

extern void scr_delete __P((void));
#define scr_cdelete()   (void)(printf(CSI"P"),fflush(stdout))

extern void scr_cinsert __P((void));
#define scr_cinsert()   (void)(printf(CSI"@"),fflush(stdout))

extern void scr_clear __P((void));
#define scr_clear()     (void)(printf("\f"),fflush(stdout))

extern void scr_cr __P((void));
#define scr_cr()        (void)(printf("\xA"),fflush(stdout))

extern void scr_cursrt __P((void));
#define scr_cursrt()    (void)(printf(CSI"C"),fflush(stdout))

extern void scr_cursup __P((void));
#define scr_cursup()    (void)(printf(CSI"A"),fflush(stdout))

extern void scr_eol __P((void));
#define scr_eol()       (void)(printf(CSI"K"),fflush(stdout))

extern void scr_home __P((void));
#define scr_home()      (void)(printf(CSI"H"),fflush(stdout))

extern void scr_ldelete __P((void));
#define scr_ldelete()   (void)(printf(CSI"M"),fflush(stdout))

extern void scr_lf __P((void));
#define scr_lf()        (void)(printf(CSI"B"),fflush(stdout))

extern void scr_linsert __P((void));
#define scr_linsert()   (void)(printf(CSI"L"),fflush(stdout))

extern void scr_tab __P((void));
#define scr_tab()       (void)(printf("\t"),fflush(stdout))

extern void scr_curs __P((int line, int column));
#define scr_curs(line,col)      (void)(printf(CSI #line ";" #col "H"),fflush(stdout))

#endif
