#!/usr/bin/env bash

# This script is used to build the docker image.
# Image name and tag can be specified with NAME and TAG environment variables.
# If PUSH is set to 1, the image will be pushed to the registry.

set -e

if [[ -z "${NAME}" ]]; then
    NAME="sacredbanana/amiga-compiler"
fi

if [[ -z "${TAG}" ]]; then
    TAG="latest"
fi

docker build -t ${NAME}:${TAG} --rm .

if [[ "${PUSH}" == "1" ]]; then
  docker push ${NAME}:${TAG}
fi