#!/usr/bin/env bash

# This script is used to build the docker images.
# Image name can be specified with NAME environment variable.
# If PUSH is set to 1, the images will be pushed to the registry.

set -e

if [[ -z "${NAME}" ]]; then
    NAME="sacredbanana/amiga-compiler"
fi

docker build -t ${NAME}:ppc-amigaos --rm -f Dockerfile.ppc .

if [[ "${PUSH}" == "1" ]]; then
  docker push ${NAME}:ppc-amigaos
  docker buildx rm amigasdkbuilder || true
  docker buildx create --name amigasdkbuilder --use
  docker buildx build --platform linux/amd64,linux/arm64 -t ${NAME}:m68k-amigaos --rm -f Dockerfile.m68k --push .
  docker buildx rm amigasdkbuilder
else
  docker build -t ${NAME}:m68k-amigaos --rm -f Dockerfile.m68k .
fi