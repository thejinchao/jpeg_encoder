# Build Stage
FROM --platform=linux/amd64 ubuntu:20.04 as builder

## Install build dependencies.
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y cmake clang

## Add source code to the build stage.
ADD . /jpeg-encoder
WORKDIR /jpeg-encoder

## TODO: ADD YOUR BUILD INSTRUCTIONS HERE.
RUN mkdir build && cd build && clang++ ../fuzz-jpeg.cpp ../jpeg_encoder.cpp -o fuzzjpeg -lstdc++

# Package Stage
FROM --platform=linux/amd64 ubuntu:20.04

## TODO: Change <Path in Builder Stage>
COPY --from=builder /jpeg-encoder/build/fuzzjpeg /

