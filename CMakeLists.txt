# SPDX-License-Identifier: zlib-acknowledgement
cmake_minimum_required(VERSION 3.17)
project(EMT
        VERSION 0.0.1
        DESCRIPTION "Embedded testing structure"
        LANGUAGES C)
set_property(GLOBAL PROPERTY C_STANDARD 11)

add_subdirectory(src)
