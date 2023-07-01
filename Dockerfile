# Docker Image for AmigaOS 3.2 & 4 cross compiler

FROM amigadev/crosstools:m68k-amigaos AS builder

COPY ./m68k-amigaos /opt/m68k-amigaos/m68k-amigaos

RUN rm -dr /opt/m68k-amigaos/m68k-amigaos/Autodocs
RUN rm -dr /opt/m68k-amigaos/m68k-amigaos/doc
RUN rm -dr /opt/m68k-amigaos/m68k-amigaos/guide

FROM amigadev/crosstools:ppc-amigaos

COPY --from=builder /opt /opt
COPY ./ppc-amigaos /opt/ppc-amigaos/ppc-amigaos

RUN rm -dr /opt/ppc-amigaos/ppc-amigaos/SDK/Documentation
RUN rm -dr /opt/ppc-amigaos/ppc-amigaos/SDK/Examples
RUN rm -dr /opt/ppc-amigaos/ppc-amigaos/SDK/Tools
RUN rm -dr /opt/ppc-amigaos/ppc-amigaos/SDK/*.pdf*

RUN ln -s /opt/m68k-amigaos /opt/amiga
RUN ln -s /opt /tools

WORKDIR /work

CMD exec /bin/bash -c "trap : TERM INT; sleep infinity & wait"