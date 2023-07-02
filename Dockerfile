# Docker Image for AmigaOS 3.2 & 4 cross compiler

FROM amigadev/crosstools:m68k-amigaos AS builder

RUN mv /opt/m68k-amigaos /opt/amiga

COPY ./m68k-amigaos /opt/amiga/m68k-amigaos

RUN rm -dr /opt/amiga/m68k-amigaos/Autodocs
RUN rm -dr /opt/amiga/m68k-amigaos/doc
RUN rm -dr /opt/amiga/m68k-amigaos/guide

FROM amigadev/crosstools:ppc-amigaos

RUN mv /opt/ppc-amigaos /opt/amiga

COPY --from=builder /opt/amiga /opt/amiga
COPY ./ppc-amigaos /opt/amiga/ppc-amigaos

RUN rm -dr /opt/amiga/ppc-amigaos/SDK/Documentation
RUN rm -dr /opt/amiga/ppc-amigaos/SDK/Examples
RUN rm -dr /opt/amiga/ppc-amigaos/SDK/Tools
RUN rm -dr /opt/amiga/ppc-amigaos/SDK/*.pdf*

RUN rm /tools
RUN ln -s /opt/amiga /tools

ENV PATH="/opt/amiga/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

WORKDIR /work

CMD exec /bin/bash -c "trap : TERM INT; sleep infinity & wait"