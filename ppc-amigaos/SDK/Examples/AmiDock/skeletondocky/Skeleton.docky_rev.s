VERSION = 53
REVISION = 1

.macro DATE
.ascii "23.9.2008"
.endm

.macro VERS
.ascii "Skeleton.docky 53.1"
.endm

.macro VSTRING
.ascii "Skeleton.docky 53.1 (23.9.2008)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: Skeleton.docky 53.1 (23.9.2008)"
.byte 0
.endm
