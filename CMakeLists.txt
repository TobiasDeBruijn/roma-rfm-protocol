cmake_minimum_required(VERSION 3.22)
project(roma-rfm-protocol LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_library(roma-rfm-protocol
        src/packet.c
        src/command.c

        include/packet.h
        include/command.h
)
