#!/usr/bin/env bash

# This script is used to build the docker images.
# Image name can be specified with NAME environment variable.
# If PUSH is set to 1, the images will be pushed to the registry.

set -e

if [[ -z "${NAME}" ]]; then
    NAME="sacredbanana/amiga-compiler"
fi

docker build -t ${NAME}:m68k-amigaos --rm -f Dockerfile.m68k .
docker build -t ${NAME}:ppc-amigaos --rm -f Dockerfile.ppc .

if [[ "${PUSH}" == "1" ]]; then
  docker push ${NAME}:m68k-amigaos
  docker push ${NAME}:ppc-amigaos
fi