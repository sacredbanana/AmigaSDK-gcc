# Docker Image for AmigaOS 3.2 & 4 cross compiler

FROM amigadev/crosstools:m68k-amigaos AS builder

WORKDIR /home

RUN git clone https://github.com/sacredbanana/AmigaSDK-gcc.git

RUN rm -dr AmigaSDK-gcc/m68k-amigaos/Autodocs
RUN rm -dr AmigaSDK-gcc/m68k-amigaos/doc
RUN rm -dr AmigaSDK-gcc/m68k-amigaos/guide
RUN rm -dr AmigaSDK-gcc/ppc-amigaos/SDK/Documentation
RUN rm -dr AmigaSDK-gcc/ppc-amigaos/SDK/Examples
RUN rm -dr AmigaSDK-gcc/ppc-amigaos/SDK/Tools
RUN rm -dr AmigaSDK-gcc/ppc-amigaos/SDK/*.pdf*
RUN cp -R AmigaSDK-gcc/* /tools/
RUN rm -rf AmigaSDK-gcc

FROM amigadev/crosstools:ppc-amigaos

COPY --from=builder /opt /opt

COPY --from=builder /tools /tools

RUN ln -s /opt/m68k-amigaos /opt/amiga

WORKDIR /work

CMD exec /bin/bash -c "trap : TERM INT; sleep infinity & wait"