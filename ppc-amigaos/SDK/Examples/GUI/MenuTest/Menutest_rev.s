VERSION = 53
REVISION = 6

.macro DATE
.ascii "23.4.2022"
.endm

.macro VERS
.ascii "Menutest 53.6"
.endm

.macro VSTRING
.ascii "Menutest 53.6 (23.4.2022)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: Menutest 53.6 (23.4.2022)"
.byte 0
.endm
